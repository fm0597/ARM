#include "capture.h"
#include "ui_capture.h"

#include <QFile>
#include <QPixmap>
#include <QHBoxLayout>
#include <sys/ioctl.h>
#include <stdio.h>
#include <fcntl.h>
//#include "logindlg.h"

#include "video.h"
#include <QFile>
#include <QDir>
#include <QSettings>
#include <QTimer>
#include <QDateTime>
#include <QDebug>


//static int fb;//?????
unsigned char Txbuf[2];

//??????
static int cam_fd;
unsigned long file_length;
void *img[4];
int isstreaming=0;

struct v4l2_capability cap;
struct v4l2_format fmt;
struct v4l2_requestbuffers req;
struct v4l2_buffer buffer;
const int W=321,H=241;

Capture::Capture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Capture)
{
    ui->setupUi(this);

    //initialize
    ///111
    take_photo_flag = 0;
    ///111
    num = 0;
    send_frame_flag = 0;
    //capture = NULL;
    //timer = new QTimer(this);
    photos = new Photos();

    this->first_open_cam_flag = 0;
    this->open_cam_flag=0;
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    //initialize socketbind port 63636
    send_socket = new QUdpSocket(this);
    send_socket->bind(63636, QUdpSocket::ShareAddress);

    //enable button
    ui->close_pushButton->setDisabled(true);
    //ui->image_close_pushButton->setDisabled(false);
    ui->take_photo_pushButton->setDisabled(true);

    //this->setWindowFlags(Qt::Tool | Qt::X11BypassWindowManagerHint);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->video_label->setStyleSheet ("background-color: #000000;color: #ffffff;");

    //C_translateLanguage();//set the content of button

    this->picNum = 0;

    //serial_port
    this->serial_open_flag = 0;
    struct PortSettings myComSetting = {BAUD4800,DATA_8,PAR_NONE,STOP_1,FLOW_OFF,10};
    myCom = new Posix_QextSerialPort("/dev/ttyUSB0",myComSetting,QextSerialBase::Polling);
    //myCom->open(QIODevice::ReadWrite);

    readTimer = new QTimer(this);
    readTimer->start(10);

    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));

    connect(send_socket, SIGNAL(readyRead()), this, SLOT(readData()));
    connect(ui->open_pushButton,SIGNAL(clicked()),this,SLOT(openCapture()));
    connect(ui->close_pushButton,SIGNAL(clicked()),this,SLOT(closeCapture()));
    connect(timer,SIGNAL(timeout()),this,SLOT(readFrame()));
    connect(ui->image_open_pushButton, SIGNAL(clicked()), this, SLOT(openPhotos()));
    connect(ui->image_close_pushButton, SIGNAL(clicked()), this, SLOT(closePhotos()));
    connect(photos, SIGNAL(closeImage()), this, SLOT(closePhotos()));
    connect(ui->take_photo_pushButton, SIGNAL(clicked()), this, SLOT(takePhotos()));
}

void Capture::readMyCom()
{
    QByteArray temp = myCom->readAll();
    QString *com = new QString(temp);
    if(com->contains("a"))
   {
        takePhotos();
        qDebug()<<"take photos Now!";
   }
}

//set the content of button
void Capture::C_translateLanguage()
{
    ui->open_pushButton->setText("open_capture");
    ui->close_pushButton->setText("close_capture");
    ui->take_photo_pushButton->setText("take_photos");
    ui->image_open_pushButton->setText("skim_photos");
    ui->image_close_pushButton->setText("close_skim");
}

void Capture::paintEvent(QPaintEvent *)
{
    if(open_cam_flag==1)
    video_play();
    else
    {
        ui->video_label->setPixmap(QPixmap(":/Image/black.jpg"));
    }
}
//?
void Capture::openCapture()
{
    //??
    //capture = cvCaptureFromCAM(0);
    //capture = cvCreateCameraCapture();
    /*if( ! capture )
    {
        qDebug("Could not initialize capture!");
        return ;
    }*/
    open_cam_flag=1;
    if(this->first_open_cam_flag == 0)
    {
    if(cam_init())
        {
        qDebug("camera init!");
        start_capture();
        timer->start(100);
        this->first_open_cam_flag = 1;
        ui->take_photo_pushButton->setDisabled(false);
        ui->open_pushButton->setDisabled(true);
        ui->close_pushButton->setDisabled(false);
    }
    else
    {
        qDebug("camera init error!");
        QMessageBox::information(this,tr("Waring!"),tr("Can't Open Camera!"),QMessageBox::Yes);
        ui->open_pushButton->setDisabled(false);
        ui->close_pushButton->setDisabled(true);
    }
   // start_capture();
    //timer->start(100);
    //this->first_open_cam_flag = 1;
    }
    else
    {
        timer->start(100);
        ui->open_pushButton->setDisabled(true);
        ui->close_pushButton->setDisabled(false);
    }



    //timer->start(32);  //ü?????
    //ui->close_pushButton->setDisabled(false);
    //ui->open_pushButton->setDisabled(true);

}

//??


void Capture::closeCapture()
{
    open_cam_flag=0;
    timer->stop();    //???
    //cvReleaseCapture( &capture );  //??
    ui->open_pushButton->setDisabled(false);
    ui->close_pushButton->setDisabled(true);
    //ui->take_photo_pushButton->setDisabled(true);
    ui->video_label->setPixmap(QPixmap(":/Image/black.jpg"));

    //this->close();

    //delete timer;
    //close_cam();
    //::close(cam_fd);

}

//???
void Capture::readFrame()
{

    //frame = cvQueryFrame( capture );   //???
    // ?????QImage?QImage::Format_RGB888??ò???

    //img = QImage((const uchar*)frame->imageData,frame->width,frame->height,QImage::Format_RGB888);
    //ui->video_label->setPixmap(QPixmap::fromImage(img));  //video_label???

    //send_frame_flag?1?PC???
    if(1 == send_frame_flag)
    {
        QByteArray buf;
        QBuffer buffer(&buf);
        buffer.open(QIODevice::ReadWrite);
        this->image.save(&buffer, "JPG");

        qint64 res;
        ///111
        if(take_photo_flag)
            {
                buf.insert(0,'y');
                take_photo_flag=0;
            }
            else buf.insert(0,'n');
        ///111
        if((res = send_socket->writeDatagram(buf.data(),buf.size(),QHostAddress("10.13.23.89"),port)) != buf.length())
        {
            qDebug()<<"error";
            return;
        }
    }
    //videoWrite(frame);


}
void Capture::takePhotos()
{

    //11
    take_photo_flag = 1;
    //11

    QDateTime time = QDateTime::currentDateTime();
    QString pname = "E:\\Program_Files\\Qt\\";
    pname += time.toString("yyyy-MM-dd-hh-mm-ss");
    pname.append(".jpg");


    //const char *name = pname.toStdString().data();

    this->image.save(pname);
    this->picNum++;
    ui->label->setText("picNum:"+QString::number(this->picNum));



}

//?PC???
void Capture::readData()
{
    while (send_socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(send_socket->pendingDatagramSize());
        send_socket->readDatagram(datagram.data(), datagram.size());
        if("send" == datagram)
        {
            send_frame_flag = 1;

        }
        else if("stop" == datagram)
        {
            send_frame_flag = 0;
        }
    }
}

/*void Capture::videoWrite(IplImage *frame)
{
    qDebug()<<frame->width;
    qDebug()<<frame->height;
    video = cvCreateVideoWriter("capture.avi",CV_FOURCC('D', 'I', 'V', 'X'), 16, cvSize(640,480));

    if( ! video )
    {
        qDebug("Could not initialize video!");
        return;

    }
    int flag = cvWriteFrame( video, frame );
    if( ! flag )
    {
        qDebug("Fail to write video!");
        return ;
    }
}*/
//??
void Capture::openPhotos()
{

    ui->image_open_pushButton->setDisabled(true);
    //ui->image_close_pushButton->setDisabled(false);
    photos->show();
}

//???
void Capture::closePhotos()
{
    ui->image_open_pushButton->setDisabled(false);
    //ui->image_close_pushButton->setDisabled(true);
    photos->close();
}



Capture::~Capture()
{
    delete ui;
    delete timer;
    close_cam();
    ::close(cam_fd);
    //cvReleaseCapture( &capture );  //??
}

bool Capture::cam_init()  //??????
{
    QFile f(CAM_DEV);
    //open device
    if(f.exists())
    {
        cam_fd=::open(CAM_DEV,O_RDWR);
        if(cam_fd<0)
        {
            qDebug("open camera error");
            return false;
        }
    }
    //query capability
    CLEAR(cap);
    if(ioctl (cam_fd, VIDIOC_QUERYCAP, &cap)<0)
    {
        qDebug("VIDIOC_QUERYCAP:");
        return false;
    }
    qDebug("capabilities:0x%x",cap.capabilities);
    //set fomat
    CLEAR(fmt);
    fmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    fmt.fmt.pix.width=W;
    fmt.fmt.pix.height=H;

    if(ioctl(cam_fd,VIDIOC_S_FMT,&fmt)<0)
    {
        qDebug("VIDIOC_S_FMT");
        return false;
    }
    fmt.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    ioctl(cam_fd,VIDIOC_G_FMT,&fmt);
    if(fmt.fmt.pix.pixelformat&V4L2_PIX_FMT_JPEG)
        qDebug("set format V4L2_PIX_FMT_JPEG");
    //file length
    file_length=fmt.fmt.pix.bytesperline*fmt.fmt.pix.height;
    //request memory
    CLEAR(req);
    req.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
    req.memory=V4L2_MEMORY_MMAP;
    req.count=4;
    if(ioctl(cam_fd,VIDIOC_REQBUFS,&req)<0)
    {
        qDebug("VIDIOC_REQBUFS:");
        return false;
    }
    qDebug("request memory!");
    //query buffer
    int i;
    for(i=0;i<4;i++)
    {
        CLEAR(buffer);
        buffer.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buffer.memory=V4L2_MEMORY_MMAP;
        buffer.index=i;
        if(ioctl(cam_fd,VIDIOC_QUERYBUF,&buffer)<0)
        {
            qDebug("VIDIOC_QUERYBUF:");
            return false;
        }
        //memory map
        img[i]=mmap(0,buffer.length,PROT_READ|PROT_WRITE,MAP_SHARED,cam_fd,buffer.m.offset);
        if(img==MAP_FAILED)
        {
            qDebug("mmap failed:");
            return false;
        }
    }
    qDebug("memory mapped!");
    //queue the buffer
    for(i=0;i<4;i++)
    {
        CLEAR(buffer);
        buffer.index=i;
        buffer.type=V4L2_BUF_TYPE_VIDEO_CAPTURE;
        buffer.memory=V4L2_MEMORY_MMAP;
        if(ioctl(cam_fd,VIDIOC_QBUF,&buffer)<0)
            {
                qDebug("VIDIOC_QBUF:");
                return false;
            }
    }
    qDebug("queen buffer!");

    return true;
}

bool Capture::start_capture()
{
    if(!isstreaming)
    {
        //stream on
        if(ioctl(cam_fd,VIDIOC_STREAMON,&buffer.type)<0)
        {
            qDebug("VIDIOC_STREAMON:");
            return false;
        }
        isstreaming=1;
        //qDebug("stream on");
    }
    return true;
}

void Capture::video_play()
{

    //queue out
    if(ioctl (cam_fd, VIDIOC_DQBUF, &buffer)<0)
        {
            qDebug("VIDIOC_DQBUF:");
            //return false;
        }
    this->pixmap.loadFromData((uchar*)img[buffer.index],buffer.bytesused,"JPEG");
    this->image.loadFromData((uchar*)img[buffer.index],buffer.bytesused,"JPEG");
    //pixmap.fromImage(this->image);

   // qp = this->image;
    ui->video_label->setPixmap(pixmap);;
    //queue buffer
    ioctl(cam_fd, VIDIOC_QBUF, &buffer);
    //return true;
}

bool Capture::close_cam()
{
    if(isstreaming)
    {
        if(ioctl(cam_fd, VIDIOC_STREAMOFF, &buffer.type)<0)
            {
                qDebug("VIDIOC_STREAMOFF:");
                return false;
            }
            qDebug("stop capture!");
            //memory unmap
            int i;
            for(i=0;i<4;i++)
            {
                if(munmap(img[i],buffer.length)<0)
                {
                    qDebug("munmap:");
                    return false;
                }
            }
            qDebug("memory unmapped");
        isstreaming=0;
    }
    return true;
}
//?

void Capture::on_image_close_pushButton_clicked()
{
    if(this->myCom->isOpen())
    {
        this->myCom->close();
        ui->serial_btn->setText("Open Serial");
        this->serial_open_flag = 0;
    }

    this->close();

}


void Capture::on_serial_btn_clicked()
{
    if(this->serial_open_flag == 0)
    {
        //only open the serial if camera is working
        if(first_open_cam_flag == 1)
        {
            myCom->open(QIODevice::ReadWrite);
            ui->serial_btn->setText("Close serial");
            this->serial_open_flag = 1;
        }
    }
    else
    {
        myCom->close();
        ui->serial_btn->setText("Open serial");
        this->serial_open_flag = 0;
    }

}

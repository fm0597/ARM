#include "capture.h"
#include "ui_capture.h"
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QBuffer>
#include <QtGui>



Capture::Capture(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Capture)
{
    ui->setupUi(this);

    //初始化
    //num = 0;
    timer = new QTimer(this);

    ///111
    take_photo_flag='y';
    ///111
    photos = new Photos();
    send_socket = new QUdpSocket(this);
    send_socket->bind(45454,QUdpSocket::ShareAddress);
    ui->close_pushButton->setDisabled(true);
    ui->image_close_pushButton->setDisabled(true);

    C_translateLanguage();

    connect(ui->open_pushButton, SIGNAL(clicked()), this, SLOT(sendMssg()));
    connect(send_socket, SIGNAL(readyRead()), this, SLOT(receiverData()));
    connect(ui->close_pushButton, SIGNAL(clicked()),this,SLOT(closeCapture()));
    connect(ui->image_open_pushButton, SIGNAL(clicked()), this, SLOT(openPhotos()));
    connect(ui->image_close_pushButton, SIGNAL(clicked()), this, SLOT(closePhotos()));
    connect(photos, SIGNAL(closeImage()), this, SLOT(closePhotos()));
    connect(timer, SIGNAL(timeout()), this, SLOT(clearVideo()));
    ui->video_label->setScaledContents(true);

}

//设置按钮显示的内容
void Capture::C_translateLanguage()

{
    ui->open_pushButton->setText(tr("开启监控"));
    ui->close_pushButton->setText(tr("关闭监控"));
    ui->image_open_pushButton->setText(tr("浏览图片"));
    ui->image_close_pushButton->setText(tr("关闭浏览"));
}

void Capture::sendMssg()
{
    QByteArray command = "send";
    send_socket->writeDatagram(command.data(), command.size(),QHostAddress("10.13.23.89"), port);
    ui->open_pushButton->setDisabled(true);
    ui->close_pushButton->setDisabled(false);
    timer->start(200);
    //qDebug()<<command;

}

void Capture::receiverData()
{


    while (send_socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(send_socket->pendingDatagramSize());
        send_socket->readDatagram(datagram.data(), datagram.size());
     ////////////111
        take_photo_flag=datagram[0];
        datagram = datagram.right(datagram.size()-1);
      /////////////1111
        QImage image;
        image.loadFromData(datagram);
///////////////////2222

        if(take_photo_flag=='y')
        {
            QDateTime time = QDateTime::currentDateTime();
            QString pname = "E:\\Program_Files\\Qt\\";
            pname += time.toString("yy-MM-dd-hh-mm-ss");
            pname.append(".jpg");
            const char *name = pname.toStdString().data();
            image.save(name);
        }
   //////////////////2222

        QPixmap pix;
        pix = pix.fromImage(image);
        ui->video_label->clear();
        ui->video_label->setPixmap(pix);
        this->update();
        timer->start(200);
    }


}


void Capture::closeCapture()
{
    QByteArray command = "stop";
    send_socket->writeDatagram(command.data(), command.size(),QHostAddress("10.13.23.89"), port);

    ui->open_pushButton->setDisabled(false);
    ui->close_pushButton->setDisabled(true);

}


//打开图片浏览器
void Capture::openPhotos()
{

    ui->image_open_pushButton->setDisabled(true);
    ui->image_close_pushButton->setDisabled(false);
    photos->show();
}

//关闭图片浏览器
void Capture::closePhotos()
{
    ui->image_open_pushButton->setDisabled(false);
    ui->image_close_pushButton->setDisabled(true);
    photos->close();
}

void Capture::clearVideo()
{
    ui->video_label->clear();
    timer->stop();
    if(ui->close_pushButton->isEnabled())
    {
        QMessageBox::critical(this, tr("错误"), tr("数据传送出错或前端系统已关闭！"), QMessageBox::Ok);
    }
}



Capture::~Capture()
{
    delete ui;
}

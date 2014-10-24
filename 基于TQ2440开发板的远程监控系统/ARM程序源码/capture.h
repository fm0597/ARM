#ifndef CAPTURE_H
#define CAPTURE_H

#include <QWidget>
#include <QImage>
#include <QTimer>
//#include <opencv2/opencv.hpp>
#include <qprocess.h>     // ??linux?????
#include <photos.h>
#include <QUdpSocket>
#include <QString>
#include <QDebug>
#include <QByteArray>
#include <QBuffer>
#include <QDateTime>
#include "TQInputMethod.h"
#include <QWSInputMethod>

#include "posix_qextserialport.h"
#include <QTimer>
namespace Ui {
    class Capture;
}

class Capture : public QWidget
{
    Q_OBJECT

public:
    explicit Capture(QWidget *parent = 0);
    void C_translateLanguage();
    bool cam_init();
    bool start_capture();
    void video_play();
    bool close_cam();
    ~Capture();
    Posix_QextSerialPort *myCom;
    //void C_translateLanguage();   //设置按钮显示的内容
   // void videoWrite(IplImage *frame);


public slots:
    void openCapture();    //打开摄像头
    void closeCapture();   //关闭摄像头
    void readFrame();      //读取摄像机的帧
    void openPhotos();     //打开图片浏览器
    void closePhotos();    //关闭图片浏览器
    void takePhotos();     //拍照
    void readData();       //读取PC端发来的数据

private:
    Ui::Capture *ui;
    int first_open_cam_flag;
    int open_cam_flag;
    QProcess process;//????QProcess
    QImage image;
    QPixmap pixmap;
    //QImage img;           //摄像机的帧转换后的图片
    QTimer *timer;        //计时器
    //CvCapture *capture;   //摄像头
    //IplImage *frame;      //帧
    Photos *photos;       //Photos类的对象
    //CvVideoWriter *video;
    QUdpSocket* send_socket;
    const static quint16 port = 45454;  //端口
    int num ;            //拍照数量
    int send_frame_flag; //是否向PC端发送视频帧
    ///111
    int take_photo_flag;

    QTimer *readTimer;
    int serial_open_flag;

    int picNum;
    ///111

private slots:
    void on_serial_btn_clicked();
    //void on_pushButton_clicked();
    void on_image_close_pushButton_clicked();
    void paintEvent(QPaintEvent *);
    void readMyCom();

};

#endif // CAPTURE_H

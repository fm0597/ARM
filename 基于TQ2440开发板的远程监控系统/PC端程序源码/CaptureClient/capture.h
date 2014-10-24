#ifndef CAPTURE_H
#define CAPTURE_H

#include <QWidget>
#include <QImage>
#include <photos.h>
#include <QUdpSocket>
#include <QDateTime>
#include <QTimer>

namespace Ui {
    class Capture;
}

class Capture : public QWidget
{
    Q_OBJECT

public:
    explicit Capture(QWidget *parent = 0);
    ~Capture();
    void C_translateLanguage();



public slots:

    void sendMssg();
    void receiverData();
    void closeCapture();   //关闭摄像头

    void openPhotos();
    void closePhotos();
    void clearVideo();

private:
    ///111
    char take_photo_flag;
    ///111
    Ui::Capture *ui;
    QImage img;           //摄像机的帧转换后的图片
    Photos *photos;
    int flag;
    QUdpSocket* send_socket;
    const static quint16 port = 63636;
    QTimer *timer;




};

#endif // CAPTURE_H

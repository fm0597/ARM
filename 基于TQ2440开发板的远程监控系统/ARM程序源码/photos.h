#ifndef PHOTOS_H
#define PHOTOS_H

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QStringList>
#include <QCloseEvent>
#include <QFileDialog>
#include <QDirIterator>
#include <QListIterator>
#include <QMessageBox>
#include <QPainter>
#include <QFileInfoList>
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QMouseEvent>
#include <QPushButton>



namespace Ui {
    class Photos;
}

class Photos : public QWidget
{
    Q_OBJECT

signals:
    void closeImage();

protected:
    void paintEvent(QPaintEvent *);      //ڴϻͼ
    void resizeEvent(QResizeEvent * );   //ͼƬ洰仯仯
    void closeEvent(QCloseEvent *);      //رմں
    //void mouseMoveEvent(QMouseEvent*event);
    //void mousePressEvent(QMouseEvent*event);

public:
    explicit Photos(QWidget *parent = 0);
    ~Photos();
    void translateLanguage();     //ðťʾ
    void setPixmap(QString imageName);  //ͼƬ
    void scanFile(QString path);        //ɨͼƬڵļ
    void getPosition();                 //ôͼƬλ
    void designUI();                    //Ľ
    void disableButton();               //ʹťЧ
    void enableButton();                //ʹťЧ



public slots:
    void openFiles();              //ͼƬļ
    void previousPhoto();          //һͼƬ
    void nextPhoto();              //һͼƬ
    void expandImage();            //ŴͼƬ
    void narrowImage();            //СͼƬ
    void deleteImage();            //ɾͼƬ
    void adjustPhoto();            //ͼƬСӦ

private:
    Ui::Photos *ui;
    QPixmap pixmap;
    QString imagePath;     //ͼƬ·
    QString dirPath;       //ͼƬڵļе·
    QStringList imageList; //ͼƬ
    int position;          //ͼƬλ
    int original_x, original_y;       //ͼĳʼ
    int image_width, image_height;    //ͼƬĳͿ
    int widget_width, widget_height;  //ͼƬĳӿ
    int mouse_flag;
    int transform_flag;
    int static_width, static_height;  //ͼƬ߿ľ

};

#endif // PHOTOS_H

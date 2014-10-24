#ifndef PHOTOS_H
#define PHOTOS_H

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QStringList>
#include <QCloseEvent>



namespace Ui {
    class Photos;
}

class Photos : public QWidget
{
    Q_OBJECT

signals:
    void closeImage();

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent * );
    void closeEvent(QCloseEvent *);
    //void mouseMoveEvent(QMouseEvent*event);
    //void mousePressEvent(QMouseEvent*event);

public:
    explicit Photos(QWidget *parent = 0);
    ~Photos();
    void translateLanguage();
    void setPixmap(QString imageName);
    void scanFile(QString path);
    void getPosition();
    void designUI();
    void disableButton();
    void enableButton();



public slots:
    void openFiles();
    void previousPhoto();
    void nextPhoto();
    void expandImage();
    void narrowImage();
    void deleteImage();
    void adjustPhoto();

private:
    Ui::Photos *ui;
    QPixmap pixmap;
    QString imagePath;
    QString dirPath;
    QStringList imageList;
    int position;
    int original_x, original_y;
    int image_width, image_height;
    int widget_width, widget_height;
    int mouse_flag;
    int transform_flag;
    int size_height, size_width;
    int static_width, static_height;

};

#endif // PHOTOS_H

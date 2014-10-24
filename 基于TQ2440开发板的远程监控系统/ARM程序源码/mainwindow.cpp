#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "capture.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    capture = new Capture();
   // translateLanguage();
    this->setWindowFlags(Qt::FramelessWindowHint);
    bKeyShow=false;
    im = new TQInputMethod;
    ui->lineEdit_psd->setEchoMode(QLineEdit::Password);

    //QWSServer::setCurrentInputMethod(im);
    ((TQInputMethod *) im)->setVisible(false);

    QPixmap pixmap("/X/b.png");//????????
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));//??????????
    setPalette(palette);//??????
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_login_clicked()
{
    if(ui->lineEdit_user->text()==tr("root")&&ui->lineEdit_psd->text()==tr("012345"))
    {
        capture->show();
        ((TQInputMethod *) im)->setVisible(false);
    }
    else
    {
         QMessageBox::warning(this,tr("Warnning"),tr("The UsrName or pwd is worry!"),QMessageBox::Yes);
         ui->lineEdit_user->clear();
         ui->lineEdit_psd->clear();
         ui->lineEdit_user->setFocus();
    }
   // capture->show();
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

void MainWindow::on_pushButton_help_clicked()
{
    QMessageBox::information(this,tr("Title"),tr("UsrName:root PWD:012345"),QMessageBox::Yes);
}

void MainWindow::translateLanguage()
{
    ui->title_label->setText("      ¿¿¿¿¿¿¿¿¿¿");
    ui->user_label->setText("¿¿¿¿");
    ui->password_label->setText("¿¿¿");
    ui->pushButton_info->setText("¿¿");
    ui->pushButton_login->setText("¿¿");
    ui->pushButton_exit->setText("¿¿");
    ui->pushButton_help->setText("¿¿");
}

void MainWindow::on_pushButton_info_clicked()
{

    ((TQInputMethod *) im)->setVisible(bKeyShow);
    bKeyShow = !bKeyShow;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <capture.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void translateLanguage();

public slots:
    void on_pushButton_login_clicked();
    void on_pushButton_exit_clicked();
    void on_pushButton_help_clicked();

private:
    Ui::MainWindow *ui;
   Capture *capture;
    QWSInputMethod* im;
    bool bKeyShow;

private slots:
    void on_pushButton_info_clicked();
};

#endif // MAINWINDOW_H

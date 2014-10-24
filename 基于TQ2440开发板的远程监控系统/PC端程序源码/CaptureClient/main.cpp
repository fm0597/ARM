#include <QtGui/QApplication>
#include "capture.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    Capture w;
    w.show();

    return a.exec();
}

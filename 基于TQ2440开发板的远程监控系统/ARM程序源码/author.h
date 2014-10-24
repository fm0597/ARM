#ifndef AUTHOR_H
#define AUTHOR_H
#include <QWidget>

namespace Ui {
    class author;
}

class author : public QWidget
{
    Q_OBJECT

public:
    explicit author(QWidget *parent = 0);

    ~author();



public slots:


private:
    Ui::author *ui;




};
#endif // AUTHOR_H

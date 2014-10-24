#include "photos.h"
#include "ui_photos.h"


#define RATIO 2


Photos::Photos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Photos)
{
    ui->setupUi(this);

    position = 0;
    original_x = 40;
    original_y = 18;
    image_width = 380;
    image_height = 200;
    transform_flag = 0;
    widget_width = QWidget::width();
    widget_height = QWidget::height();

    mouse_flag = 0;
    static_height = 50;
    static_width =  80;

   // translateLanguage();
    designUI();

    this->setMouseTracking(true);
    this->setWindowFlags(Qt::FramelessWindowHint);

    connect(ui->open_pushButton, SIGNAL(clicked()), this, SLOT(openFiles()));
    connect(ui->previous_pushButton, SIGNAL(clicked()), this, SLOT(previousPhoto()));
    connect(ui->next_pushButton, SIGNAL(clicked()), this, SLOT(nextPhoto()));
  //  connect(ui->previous_Button, SIGNAL(clicked()), this, SLOT(previousPhoto()));
    //connect(ui->next_Button, SIGNAL(clicked()), this, SLOT(nextPhoto()));
    connect(ui->expand_pushButton, SIGNAL(clicked()), this, SLOT(expandImage()));
    connect(ui->narrow_pushButton, SIGNAL(clicked()), this, SLOT(narrowImage()));
    connect(ui->delete_pushButton, SIGNAL(clicked()), this, SLOT(deleteImage()));
    connect(ui->adjust_pushButton, SIGNAL(clicked()), this, SLOT(adjustPhoto()));


   // QPainter *painter1 = new QPainter;
   // painter1->setBrush(Qt::black);
    //painter1->drawPixmap(original_x, original_y, image_width, image_height, pixmap);


}

//ð??
void Photos::translateLanguage()
{
  ui->adjust_pushButton->setToolTip("adapt");
    ui->open_pushButton->setToolTip("open");
    ui->previous_pushButton->setToolTip("previous");
    ui->next_pushButton->setToolTip("next");
    ui->expand_pushButton->setToolTip("expand");
    ui->narrow_pushButton->setToolTip("narrow");
    //ui->previous_Button->setToolTip("previous");
    //ui->next_Button->setToolTip("next");
    ui->delete_pushButton->setToolTip("delete");
}

void Photos::designUI()
{

    //?????
    QPalette palette;
    this->setAutoFillBackground(true);
    palette.setColor(QPalette::Background, QColor(255,255,255));
    this->setPalette(palette);

    disableButton();
    /*ui->previous_Button->setStyleSheet("border-style: flat;");
    ui->next_Button->setStyleSheet("border-style: flat;");


    ui->adjust_pushButton->setStyleSheet("border-style: flat;");
    ui->adjust_pushButton->setStyleSheet("QPushButton{border-image:url(:/Image/adjust1.png)}QPushButton:hover:!pressed{border-image:url(:/Image/adjust2.jpg);font-size:20px;}QPushButton:hover:pressed {border-image:url(:/Image/adjust2.jpg);font-size:20px;}");
    ui->expand_pushButton->setStyleSheet("border-style: flat;");
    ui->expand_pushButton->setStyleSheet("QPushButton{border-image:url(:/Image/expand1.png)}QPushButton:hover:!pressed{border-image:url(:/Image/expand2.jpg);font-size:20px;}QPushButton:hover:pressed {border-image:url(:/Image/expand2.jpg);font-size:20px;}");
    ui->narrow_pushButton->setStyleSheet("border-style: flat;");
    ui->narrow_pushButton->setStyleSheet("QPushButton{border-image:url(:/Image/narrow1.png)}QPushButton:hover:!pressed{border-image:url(:/Image/narrow2.jpg);font-size:20px;}QPushButton:hover:pressed {border-image:url(:/Image/narrow2.jpg);font-size:20px;}");
    ui->previous_pushButton->setStyleSheet("border-style: flat;");
    ui->previous_pushButton->setStyleSheet("QPushButton{border-image:url(:/Image/previous1.png)}QPushButton:hover:!pressed{border-image:url(:/Image/previous2.jpg);font-size:20px;}QPushButton:hover:pressed {border-image:url(:/Image/previous2.jpg);font-size:20px;}");
    ui->next_pushButton->setStyleSheet("border-style: flat;");
    ui->next_pushButton->setStyleSheet("QPushButton{border-image:url(:/Image/next1.png)}QPushButton:hover:!pressed{border-image:url(:/Image/next2.jpg);font-size:20px;}QPushButton:hover:pressed {border-image:url(:/Image/next2.jpg);font-size:20px;}");
    ui->open_pushButton->setStyleSheet("border-style: flat;");
    ui->open_pushButton->setStyleSheet("QPushButton{border-image:url(:/Image/open1.png)}QPushButton:hover:!pressed{border-image:url(:/Image/open2.jpg);font-size:20px;}QPushButton:hover:pressed {border-image:url(:/Image/open2.jpg);font-size:20px;}");
    ui->delete_pushButton->setStyleSheet("border-style: flat;");
    ui->delete_pushButton->setStyleSheet("QPushButton{border-image:url(:/Image/delete1.png)}QPushButton:hover:!pressed{border-image:url(:/Image/delete2.jpg);font-size:20px;}QPushButton:hover:pressed {border-image:url(:/Image/delete2.jpg);font-size:20px;}");
*/
}
void Photos::disableButton()
{
    ui->adjust_pushButton->setDisabled(false);
    ui->expand_pushButton->setDisabled(true);
    ui->narrow_pushButton->setDisabled(true);
    ui->previous_pushButton->setDisabled(true);
   // ui->previous_Button->setDisabled(true);
   // ui->next_Button->setDisabled(true);
    ui->next_pushButton->setDisabled(true);
    ui->delete_pushButton->setDisabled(true);
}
void Photos::enableButton()
{
    ui->expand_pushButton->setDisabled(false);
    ui->narrow_pushButton->setDisabled(false);
    ui->previous_pushButton->setDisabled(false);
  //  ui->previous_Button->setDisabled(false);
   // ui->next_Button->setDisabled(false);
    ui->next_pushButton->setDisabled(false);
    ui->delete_pushButton->setDisabled(false);
    ui->adjust_pushButton->setDisabled(false);
}
//??
void Photos::setPixmap(QString imageName)
{
    pixmap.load(imageName);
    update();

}

//???
void Photos::paintEvent(QPaintEvent *)
{
   QPainter painter(this);

   painter.drawPixmap(original_x, original_y, image_width, image_height, pixmap);

}


//???
void Photos::openFiles()
{


    QString path = QFileDialog::getOpenFileName(this,"","/","*.*");
    if( "" != path)
    {
        position = 0;
        imageList.clear();
        imagePath = path;
        //"/"??????stringList
        QStringList stringList = imagePath.split("/");
        //?????·
        stringList.removeLast();
        dirPath = stringList.join("/");
        setPixmap(imagePath);    //??
        enableButton();          //ð?
        scanFile(dirPath);       //?

        ui->label->setVisible(false);
    }



}

//?µ??
void Photos::scanFile(QString path)
{
    QDirIterator dirIterator(path,QDir::Files|QDir::NoSymLinks);
    while (dirIterator.hasNext())
    {
        QString tmpFile = dirIterator.next();
        QStringList list = tmpFile.split(".");
        QString expandedName = list.takeLast();
        if("jpg" == expandedName || "JPG" == expandedName)
        imageList << tmpFile;

    }
    getPosition();

}

//????
void Photos::getPosition()
{
    QListIterator<QString> it(imageList);
    while(it.hasNext())
    {
        if(imagePath == it.next())
        {
            break;
        }
        else
        {
            position++;
        }

    }
}

//???
void Photos::previousPhoto()
{
    if( 0 == imageList.size())
    {
        QMessageBox::critical(this,tr("Warin"),
                              tr("No more!"),QMessageBox::Ok);
        return;
    }
    position = (position - 1 + imageList.size()) % (imageList.size());
    imagePath = imageList.at(position);
    setPixmap(imagePath);
}

//???
void Photos::nextPhoto()
{
    if( 0 == imageList.size())
    {
        QMessageBox::critical(this,tr("Warn"),
                              tr("No more!"),QMessageBox::Ok);
        return;
    }
    position = (position + 1 + imageList.size()) % (imageList.size());
    imagePath = imageList.at(position);
    setPixmap(imagePath);
}

//???
void Photos::expandImage()
{
    if( 0 == imageList.size())
    {
        QMessageBox::critical(this,tr("Warn"),
                              tr("No picture"),QMessageBox::Ok);
        return;
    }
    transform_flag = 1;
    int i,j,k;

    for(int times = 0; times < 10; times++)
    {
        image_width += RATIO;
        image_height += RATIO;
        original_x -= (RATIO/2);
        original_y -= (RATIO/2);
        //size_width -= RATIO;
        //size_height -= RATIO;
        update();
        this->repaint(original_x, original_y, image_width, image_height);
        for(i = 0; i < 900; i++)
            
            for(j = 0; j < 100; j++)
                for(k = 0; k < 45; k++);
    }
    //????????
    if(!ui->narrow_pushButton->isEnabled())
    {
        ui->narrow_pushButton->setDisabled(false);
    }
}

//???
void Photos::narrowImage()
{
    if( 0 == imageList.size())
    {
        QMessageBox::critical(this,tr("Warn"),
                              tr("No picture"),QMessageBox::Ok);
        return;
    }
    transform_flag = 1;
    int i,j,k;

    if((image_height - (RATIO*25)) >= 150)
    {
        for(int times = 0; times < 10; times++)
        {

            image_width -=  RATIO;
            image_height -= RATIO;
            original_x += (RATIO/2);
            original_y += (RATIO/2);
            //size_width += RATIO;
            //size_height += RATIO;
            update();
            this->repaint(original_x, original_y, image_width, image_height);
            for(i = 0; i < 800; i++)

            {
                for(j = 0; j < 100; j++)
                {
                    for(k = 0; k < 45; k++);
                }
            }
        }
    }
    //??????????
    if(image_height <= 150)
    {
        ui->narrow_pushButton->setDisabled(true);
    }
}

//???
void Photos::deleteImage()
{
    if( 0 == imageList.size())
    {
        QMessageBox::critical(this,tr("Warn"),
                              tr("No picture"),QMessageBox::Ok);
        return;
    }
    QMessageBox::StandardButton select = QMessageBox::question(NULL,"Warning",
                 tr("Delete is?"),QMessageBox::Yes | QMessageBox::No, QMessageBox::No);

    if(QMessageBox::Yes == select)
    {

        imageList.takeAt(position);
        QDir dir(dirPath);
        QFileInfoList fileList;
        QFileInfo curFile;
        QStringList filters;

        filters << "*.jpg" << "*.JPG";

        //??·µ?
        fileList = dir.entryInfoList(filters, QDir::Dirs|QDir::Files
                                   | QDir::Readable | QDir::Writable
                                   | QDir::Hidden | QDir::NoDotAndDotDot
                                   , QDir::Name);

        if(fileList.size()>0)
        {

            curFile = fileList[position];
            QFile tmpFile(curFile.filePath());
            tmpFile.remove();
            fileList.removeAt(position);

        }

        if(0 == imageList.size())
        {

            QMessageBox::critical(this,tr("Warn"),
                                  tr("No more"),QMessageBox::Ok);
            return;
        }

        //????ÿ???þ?????õ????????
        imagePath = imageList.at(position);
        setPixmap(imagePath);

    }
}

//?????
void Photos::resizeEvent(QResizeEvent *)
{

    int tmp_width, tmp_height;
    //???
    tmp_width = QWidget::width();
    tmp_height = QWidget::height();


    //transform_flag?1??????
    if(0 == transform_flag)
    {
        if(tmp_width != widget_width )
        {

            image_width = tmp_width - static_width;
            update();
        }
        if(tmp_height != widget_height)
        {
            image_height = tmp_height - static_height;
            update();
        }
    }
    else
    {
        if(tmp_width > widget_width)
        {
            original_x += (tmp_width - widget_width+1)/2;
        }
        else{
            original_x += (tmp_width - widget_width-1)/2;
        }
        if(tmp_height > widget_height)
        {
            original_y += (tmp_height - widget_height+1)/2;
        }
        else{
            original_y += (tmp_height - widget_height-1)/2;
        }
        update();
    }
    widget_width = tmp_width;
    widget_height = tmp_height;


}

void Photos::adjustPhoto()
{
    /*int tmp_width, tmp_height;
    tmp_width = QWidget::width();
    tmp_height = QWidget::height();
    image_width = tmp_width - static_width;
    image_height = tmp_height - static_height;
    original_x = 40;
    original_y = 18;
    transform_flag = 0;
    update();*/
    ui->label->setVisible(true);
    this->close();
}

void Photos::closeEvent(QCloseEvent *)
{


    position = 0;
    original_x = 40;
    original_y = 18;
    image_width = 400;
    image_height = 250;
    transform_flag = 0;
    imageList.clear();
    imagePath.clear();
    disableButton();

    pixmap.fill(Qt::white);
    this->repaint(0, 0, QWidget::width(), QWidget::height());
    //update();

    emit(closeImage());
    this->close();
}

/*void Photos::mousePressEvent(QMouseEvent *event)
{
    if(image_width > widget_width || image_height > widget_height)
    {
        if(event->button()== Qt::LeftButton)
        {
            mouse_flag = 1;
        }
    }
    qDebug()<<widget_width;
    qDebug()<<image_width;
}

void Photos::mouseMoveEvent(QMouseEvent *event)
{
    if(image_width > widget_width || image_height > widget_height)
    {

        int final_x, final_y;
        final_x = final_y = 0;
        if((event->button() & Qt::LeftButton) && mouse_flag == 1)
        {
            original_x += (event->x() - final_x);
            original_y += (event->y() - final_y);
            qDebug()<< event->x();
            qDebug()<< event->y();
            //abs_x = qAbs(abs_x);
            //abs_y = qAbs(abs_y);
            this->repaint(original_x, original_y, image_width, image_height);
            update();
        }

        if(event->button() == Qt::LeftButton)
        {
            final_x = event->x();
            final_y = event->y();
            mouse_flag = 1;

        }
        else
        {
            mouse_flag = 0;
        }
        //if()
    }
}
*/

Photos::~Photos()
{
    delete ui;

}

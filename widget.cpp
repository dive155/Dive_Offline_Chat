#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QString defName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->nameField->setText(defName);
    ui->msgField->setPlaceholderText("Enter your message here");
    /*ui->spinBox->setMaximum(5);
    ui->spinBox->setMinimum(1);
    ui->spinBox->setMinimum(0);
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(loadImage()));
    connect(ui->pushButton_6, SIGNAL(clicked()),
            this, SLOT(saveImage()));
   // connect(ui->pushButton_2, SIGNAL(clicked()),
   //         this, SLOT(makeRed()));
    connect(ui->pushButton_3, SIGNAL(clicked()),
            this, SLOT(justGist()));
    connect(ui->pushButton_4, SIGNAL(clicked()),
            this, SLOT(medFilter()));
    connect(ui->pushButton_5, SIGNAL(clicked()),
            this, SLOT(rangFilter()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            this, SLOT(checkSpin(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
            this, SLOT(checkDisplacement(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)),
            this, SLOT(checkK()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)),
            this, SLOT(checkK()));

    checkK();
    checkSpin(ui->spinBox->value());
*/
    connect(ui->sendBtn  , SIGNAL(clicked()),
            this, SLOT(sendMsg()));
    connect(ui->msgField  , SIGNAL(returnPressed()),
            this, SLOT(sendMsg()));
    connect(ui->msgField  , SIGNAL(returnPressed()),
            this, SLOT(sendToPartner()));
    connect(ui->sendBtn  , SIGNAL(clicked()),
            this, SLOT(sendToPartner()));
}


void Widget::sendMsg()
{
    ui->chatText->append(QString("%1: ").arg(ui->nameField->text()) + ui->msgField->text());

}

Widget::~Widget()
{
    delete ui;
}


void Widget::setPartner(Widget* aPartner)
{
    partner = aPartner;
}

void Widget::getMessage(QString msg)
{
    ui->chatText->append(msg);
    QApplication::alert(this);

}

void Widget::sendToPartner()
{
    QString msg = (QString("%1: ").arg(ui->nameField->text()) + ui->msgField->text());
    qDebug() << msg;
    partner->getMessage(msg);
    ui->msgField->setText("");
}




/*
void Widget::loadImage()
{
    QString fileName = QFileDialog::getOpenFileName(0, tr("Open"), "",
                                                    tr("Images") +
                                                       "(*.jpg *.jpeg *.png *.bmp "
                                                       "*.gif *.pbm *.pgm *.ppm "
                                                       "*.tiff *.xbm *.xpm);;" +
                                                    tr("All Files") +
                                                       "(*.*)");
    if (fileName.isEmpty())
        return;

    image = QImage(fileName);

    if (image.format() == QImage::Format_Invalid)
        return;
/*
    if (image.width() > 500)
        image = image.scaled(image.width(), image.height() / image.width());
    if (image.height() > 300)
        image = image.scaled(300 / image.height());*//*
    result = QImage(image);
    showImage();
    showResult();
}

void Widget::saveImage()
{
    QString fileName = QFileDialog::getSaveFileName(0, tr("Save"), "",
                                                                    tr("PNG") +
                                                                    "(*.png);;" +
                                                                    tr("All Files") +
                                                                    "(*.*)");
    if (fileName.isEmpty())
        return;
    result.save(fileName);
}
*/
/*
void Widget::showImage()
{ //this shows a picture
    QPixmap pixmap;
    pixmap.convertFromImage(image);
    ui->label->setPixmap(pixmap/*pixmap.scaled(ui->label->width(), ui->label->height(), Qt::KeepAspectRatio)*///);
//} /*
/*

void Widget::mousePressEvent(QMouseEvent * event)
{ //output pixel info
    if (ui->label->geometry().contains(event->pos()))
    {
        QPoint p = ui->label->mapFromParent(event->pos());
        QColor pixel = image.pixel(p.x(), p.y());
        int r = pixel.red();
        int g = pixel.green();
        int b = pixel.blue();
        int l = pixel.red()*0.3 + pixel.green()*0.59 + pixel.blue()*0.11;

        ui->label_6->setText(QString("X=%1, Y=%2, Lightness=%3, R=%4, G=%5, B=%6")
                             .arg(p.x()).arg(p.y()).arg(l).arg(r).arg(g).arg(b));
    }

    if (ui->label_3->geometry().contains(event->pos()))
    {
        QPoint p = ui->label_3->mapFromParent(event->pos());
        QColor pixel = image.pixel(p.x(), p.y());
        int r = pixel.red();
        int g = pixel.green();
        int b = pixel.blue();
        int l = pixel.red()*0.3 + pixel.green()*0.59 + pixel.blue()*0.11;

        ui->label_6->setText(QString("X=%1, Y=%2, Lightness=%3, R=%4, G=%5, B=%6")
                             .arg(p.x()).arg(p.y()).arg(l).arg(r).arg(g).arg(b));
    }
    */
//}

#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QString defName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    socket = new QTcpSocket;
    ui->setupUi(this);
    ui->nameField->setText(defName);
    ui->msgField->setPlaceholderText("Enter your message here");

    connect(ui->sendBtn  , SIGNAL(clicked()),
            this, SLOT(sendMsg()));
    connect(ui->msgField  , SIGNAL(returnPressed()),
            this, SLOT(sendMsg()));
    connect(ui->msgField  , SIGNAL(returnPressed()),
            this, SLOT(sendToPartner()));
    connect(ui->sendBtn  , SIGNAL(clicked()),
            this, SLOT(sendToPartner()));

    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this,
            SLOT (error(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(ui->connectButton,SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
}


void Widget::sendMsg()
{
    ui->chatText->append(QString("%1: ").arg(ui->nameField->text()) + ui->msgField->text());

}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectToServer()
{
    socket->connectToHost(ui->hostEdit->text(), 12000); //192.168.200.71
}

void Widget::error(QAbstractSocket::SocketError)
{
    ui->statusLabel->setText(socket->errorString());
}

void Widget::connected()
{
    ui->statusLabel->setText("online");
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

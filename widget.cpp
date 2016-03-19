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
    ui->hostEdit->setText("192.168.200.71");

    connect(ui->sendBtn  , SIGNAL(clicked()),
            this, SLOT(sendMsg()));
    connect(ui->msgField  , SIGNAL(returnPressed()),
            this, SLOT(sendMsg()));
    connect(ui->msgField  , SIGNAL(returnPressed()),
            this, SLOT(sendMessage()));
    connect(ui->sendBtn  , SIGNAL(clicked()),
            this, SLOT(sendMessage()));

    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this,
            SLOT (error(QAbstractSocket::SocketError)));
    connect(socket, SIGNAL(connected()), this, SLOT(connected()));
    connect(ui->connectButton,SIGNAL(clicked(bool)), this, SLOT(connectToServer()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(receiveMessage()));
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

void Widget::sendMessage()
{
    QString msg = (QString("%1: ").arg(ui->nameField->text()) + ui->msgField->text());
    if (!socket->isOpen()) {
        return;
    }
    QByteArray data(msg.toUtf8());
    socket->write(data);
    ui->msgField->setText("");
}

void Widget::receiveMessage()
{
    QByteArray data = socket->readAll();
    ui->chatText->append(data);
    QApplication::alert(this);
}

void Widget::setPartner(Widget* aPartner)
{
    partner = aPartner;
}


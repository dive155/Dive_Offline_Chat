#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QFileDialog>
#include <QtGui/QMouseEvent>
#include <QTcpSocket>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QString defName, QWidget *parent = 0);
    ~Widget();
      Ui::Widget *ui;
      void setPartner(Widget* aPartner);
      void getMessage(QString msg);


private:/*
    void mousePressEvent(QMouseEvent * event); */
    QString name1;
    Widget* partner;
    QTcpSocket* socket;

private slots:
    void sendMsg();
    void sendToPartner();

    void connectToServer();
    void error(QAbstractSocket::SocketError);
    void connected();

};

#endif // WIDGET_H

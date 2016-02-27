#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QFileDialog>
#include <QtGui/QMouseEvent>

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

private slots:
    void sendMsg();
    void sendToPartner();

};

#endif // WIDGET_H

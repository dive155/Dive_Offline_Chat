#include "widget.h"
#include <QtWidgets/QApplication>
#include <QtCore/QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);
    Widget w("Dummy");
    Widget v("Derp");
    w.setWindowTitle("Chat 1");
    v.setWindowTitle("Chat 2");
    w.setPartner(&v);
    v.setPartner(&w);
    w.show();
    v.show();

    return a.exec();
}

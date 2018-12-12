#include "QAxBrowser.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QAxBrowser w;
    w.setWindowOpacity(1);
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.setAttribute(Qt::WA_TranslucentBackground);

    w.navigate("www.bing.com");
    w.setSlient(true);
    w.showMaximized();
    return a.exec();
}

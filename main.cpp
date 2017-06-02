/************************************************************************************
 *  author : Dave
 *  Email : nova_wangwenbo@126.com
 *  Address : Xi'an Aeronautical University
 *  Date : 20170527
 * **********************************************************************************/
#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    w.setWindowTitle("西航=>图像处理软件");
    return a.exec();
}

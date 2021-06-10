#include "farfaraway.h"
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QStyleFactory>
#include <QtDebug>






auto main(int argc, char* argv[]) -> int
{
    QApplication duloc(argc,argv);
//    duloc.setStyle()
    qApp->setStyle(QStyleFactory::create("macOS"));
    qDebug()<<QStyleFactory().keys();
//    duloc.setStyle(QStyleFactory::create("macOS"));


    farfaraway fiona;


    return duloc.exec();
}


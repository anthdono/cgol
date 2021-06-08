#include <farfaraway.h>

#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>





auto main(int argc, char* argv[]) -> int
{
    QApplication duloc(argc,argv);
    farfaraway fiona;
    return duloc.exec();
}


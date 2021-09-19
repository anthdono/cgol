#include "cgolQWidget.h"

#include <QApplication>
#include <QStyleFactory>

auto main(int argc, char *argv[]) -> int
{
    QApplication app(argc, argv);
    qApp->setStyle(QStyleFactory::create("macOS"));
    CgolQWidget widget;
    return QApplication::exec();
}

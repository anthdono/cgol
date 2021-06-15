#include "farfaraway.h"
#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QStyleFactory>
#include <QtDebug>

auto main(int argc, char *argv[]) -> int
{
  QApplication duloc(argc, argv);
  qApp->setStyle(QStyleFactory::create("macOS"));
  qDebug() << QStyleFactory().keys();
  farfaraway fiona;
  return duloc.exec();
}

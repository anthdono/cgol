#include "farfaraway.h"

#include <QApplication>
#include <QStyleFactory>

auto main(int argc, char *argv[]) -> int
{
  QApplication duloc(argc, argv);
  qApp->setStyle(QStyleFactory::create("macOS"));

  farfaraway fiona;

  return duloc.exec();
}

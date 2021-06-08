#include "farfaraway.h"
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QPalette>
#include <QDebug>

farfaraway::farfaraway(QWidget *parent) : QWidget(parent)
{
    this->setGeometry(gc::windowSize);
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
    this->show();
}


void farfaraway::paintEvent(QPaintEvent*)
{
    QPainter bigbadwolf(this);

    // draw grid
    for(int i = 10; i < gc::dimension; i+=12)
    {
        bigbadwolf.drawLine(10,i,gc::dimension-2,i);
        bigbadwolf.drawLine(i,10,i,gc::dimension-2);
    }

    bigbadwolf.fillRect(QRect(528+gc::bufferSpace,528+gc::bufferSpace,gc::cellDimension,gc::cellDimension),gc::cellFilled);


}


farfaraway::~farfaraway()
{

}

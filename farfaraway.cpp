#include "farfaraway.h"
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QPalette>
#include <QVector>
#include <QDebug>

void farfaraway::updateGrid()
{
//    this->rectLoc += gc::cellDimension;
    update();
}

void farfaraway::regen()
{
    int* temp = new int;
    for(int i = 0; i < gc::dimension; i++)
    {
    *temp = arc4random() % 3;
        if(*temp == 1)
        {
            currentGrid[i] = true;
        }
    else{
            currentGrid[i] = false;
        }
    qDebug()<<currentGrid[i];
    }

    delete temp;
    temp = nullptr;
}

farfaraway::farfaraway(QWidget *parent) : QWidget(parent)
{
    // widget config
    this->setGeometry(gc::windowSize);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setPalette(pal);
    this->setAutoFillBackground(true);
    this->show();

    // connecting signals with slots
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(updateGrid()));
    connect(regenButton, SIGNAL(clicked()), this, SLOT(regen()));

    // refresh button
    this->refreshButton->setGeometry(gc::bufferSpace,650,100,50);
    this->refreshButton->setText("refresh grid");
    this->refreshButton->show();

    // regen button
    this->regenButton->setGeometry(gc::bufferSpace + 100,650,100,50);
    this->regenButton->setText("regen");
    this->regenButton->show();
}

void farfaraway::paintEvent(QPaintEvent*)
{
    // instantiate the QPainter object
    QPainter bigbadwolf(this);

    // draw grid
    for(int i = 10; i < gc::dimension; i+=12)
    {
        bigbadwolf.drawLine(10,i,gc::dimension-2,i);
        bigbadwolf.drawLine(i,10,i,gc::dimension-2);
    }

    // draw single cell
//    bigbadwolf.fillRect(QRect(rectLoc,rectLoc,gc::cellDimension,gc::cellDimension),gc::cellFilled);
}

farfaraway::~farfaraway()
{
    delete refreshButton;
    refreshButton = nullptr;
    delete regenButton;
    regenButton = nullptr;
}

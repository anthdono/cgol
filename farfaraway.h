#ifndef FARFARAWAY_H
#define FARFARAWAY_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QPushButton>

// graphical constants
namespace  gc
{
const QBrush cellFilled = QBrush(Qt::white, Qt::SolidPattern);
const QBrush cellEmpty = QBrush(Qt::transparent, Qt::SolidPattern);
const int dimension = 600;
const int cellDimension = dimension/50;
const QPen gridPen= QPen(Qt::white, 1, Qt::SolidLine);
const int bufferSpace = 10;
const QRect windowSize(100,100,gc::dimension + gc::bufferSpace, 700);
}

class farfaraway : public QWidget
{
    Q_OBJECT

private:

public:
    QPushButton refreshButton = QPushButton(this);
    explicit farfaraway(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent*);
    int rectLoc = gc::bufferSpace;

    ~farfaraway();

signals:


};

#endif // FARFARAWAY_H

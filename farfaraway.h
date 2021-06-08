#ifndef FARFARAWAY_H
#define FARFARAWAY_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QPushButton>
#include <QVector>

// constant values used for graphics
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
public:
    // widget constructor
    explicit farfaraway(QWidget *parent = nullptr);
    // button for refreshing canvas
    QPushButton* refreshButton = new QPushButton(this);
    // button to generate new random vector
    QPushButton* regenButton = new QPushButton(this);
    // coords of singular cell – whilst debugging
//    int rectLoc = gc::bufferSpace + gc::cellDimension;
    // grid values
    QVector<bool> currentGrid = QVector<bool>(gc::dimension);
    // widget's paint event
    virtual void paintEvent(QPaintEvent*);
    // widget deconstructor
    ~farfaraway();
public slots:
    // refreshButton response
    void updateGrid();
    void regen();
};
#endif // FARFARAWAY_H

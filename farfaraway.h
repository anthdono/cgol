#ifndef FARFARAWAY_H
#define FARFARAWAY_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QPushButton>
#include <QVector>


// constants used for graphics
namespace  gc
{
    const int rc = 50; // rows and collumns
    const QBrush cellFilled = QBrush(Qt::white, Qt::SolidPattern);
    const QBrush cellEmpty = QBrush(Qt::transparent, Qt::SolidPattern);
    const int gridDimension = 600;
    const int cellDimension = gc::gridDimension/gc::rc;
    const int windowDimension = gc::gridDimension+gc::cellDimension;
    const QPen gridPen= QPen(Qt::white, 1, Qt::SolidLine);
    const int bufferSpace = 10;
    const QRect windowSize(100,100,gc::windowDimension + gc::bufferSpace*2, gc::windowDimension + gc::bufferSpace + 100); // +100 for buttons
}

// constants used for cell maths
namespace cm
{
    const int numOfCells = gc::rc*gc::rc;
    const int cellNorth = -gc::rc;
    const int cellSouth = gc::rc;
    const int cellEast = 1;
    const int cellWest = -1;
}

class farfaraway : public QWidget
{
    Q_OBJECT
public:
    int debug = gc::bufferSpace;
    // widget constructor
    explicit farfaraway(QWidget *parent = nullptr);
    // button for refreshing canvas
    QPushButton* refreshButton = new QPushButton(this);
    // button to generate new random vector
    QPushButton* regenButton = new QPushButton(this);
    // coords of singular cell – whilst debugging
//    int rectLoc = gc::bufferSpace + gc::cellDimension;
    // grid values
    QVector<bool> currentGrid = QVector<bool>(cm::numOfCells);
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

#ifndef FARFARAWAY_H
#define FARFARAWAY_H

#include <QWidget>
#include <QPainter>
#include <QRect>
#include <QPushButton>
#include <QVector>
#include <QJsonObject>

// constants used for cell calculations
namespace cm
{
  const int ROWS_AND_COLUMNS = 50;
  const int NUM_OF_CELLS = cm::ROWS_AND_COLUMNS * cm::ROWS_AND_COLUMNS;
  const int NORTH_CELL = -(cm::ROWS_AND_COLUMNS);
  const int SOUTH_CELL = cm::ROWS_AND_COLUMNS;
  const int EAST_CELL = 1;
  const int WEST_CELL = -1;
}

// constants used for graphics
namespace gc
{
  const int SCREEN_POS = 100;
  const QBrush FULL_CELL = QBrush(Qt::black, Qt::SolidPattern);
  //    const QBrush EMPTY_CELL = QBrush(Qt::transparent, Qt::SolidPattern);
  const int GRID_PXL_DIM = 600;
  const int CELL_PXL_DIM = gc::GRID_PXL_DIM / cm::ROWS_AND_COLUMNS;
  //    const int WINDOW_PXL_DIM = gc::GRID_PXL_DIM ;
  const QPen GRID_PEN_STROKE = QPen(Qt::white, 1, Qt::SolidLine);
  const int WINDOW_BUFFER = 10;
  const QRect WINDOW_SIZE(gc::SCREEN_POS, gc::SCREEN_POS, gc::GRID_PXL_DIM + (gc::WINDOW_BUFFER * 2), gc::GRID_PXL_DIM + gc::WINDOW_BUFFER + 100); // +100 for buttons
  const int BUTTON_Y = 650;
  const int BUTTON_W = 120;
  const int BUTTON_H = 50;

}

struct cell
{
  int x;
  int y;
  bool state;
  int neighbours;
};

class farfaraway : public QWidget
{
  Q_OBJECT
public:
  int debug = gc::WINDOW_BUFFER;
  // widget constructor
  explicit farfaraway(QWidget *parent = nullptr);
  // button for refreshing canvas
  QPushButton *refreshButton = new QPushButton(this);
  // button to generate new random vector
  QPushButton *regenButton = new QPushButton(this);
  // button for debugging
  //	QPushButton* debugButton = new QPushButton(this);
  // coords of singular cell – whilst debugging
  //    int rectLoc = gc::BUFFERSPACE + gc::PXLDIMCELL;
  // grid values
  QVector<cell> cells = QVector<cell>(cm::NUM_OF_CELLS);
  // widget's paint event
  virtual void paintEvent(QPaintEvent *);
  // game of life maths
  void golCheckCells();
  void golPerformChanges();
  // json array of cells
  QJsonObject cellsJson;
  // save to json button
  QPushButton *saveToJsonButton = new QPushButton(this);
  // widget deconstructor
  ~farfaraway();
public slots:
  // refreshButton response
  void updateGrid();
  void regen();
  void debugging();
  void saveToJson();
};
#endif // FARFARAWAY_H

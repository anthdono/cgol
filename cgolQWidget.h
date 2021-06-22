#ifndef CGOLQWIDGET_H
#define CGOLQWIDGET_H 

#include <QPainter>
#include <QPushButton>
#include <QJsonObject>
#include <QString>
#include <QLineEdit>

#define ROWS_AND_COLUMNS 50
#define SPAWN_DENSITY 10

namespace constant
{
  const int NUM_OF_CELLS = ROWS_AND_COLUMNS * ROWS_AND_COLUMNS;
  const int NORTH_CELL = -ROWS_AND_COLUMNS;
  const int SOUTH_CELL = ROWS_AND_COLUMNS;
  const int EAST_CELL = 1;
  const int WEST_CELL = -1;
  const int SCREEN_POS = 100;
  const QBrush FULL_CELL = QBrush(Qt::black, Qt::SolidPattern);
  const int GRID_PXL_DIM = 12*ROWS_AND_COLUMNS;
  const int CELL_PXL_DIM = GRID_PXL_DIM / ROWS_AND_COLUMNS;
  const int WINDOW_BUFFER = 10;
  const QRect WINDOW_SIZE(SCREEN_POS, SCREEN_POS, GRID_PXL_DIM + (WINDOW_BUFFER * 2), GRID_PXL_DIM + WINDOW_BUFFER + 100); // +100 for buttons
  const int BUTTON_Y = GRID_PXL_DIM + GRID_PXL_DIM / 25;
  const int LINEEDIT_Y =  GRID_PXL_DIM + GRID_PXL_DIM / 21;
}

struct cell
{
  int x;
  int y;
  bool state;
  int neighbours;
};

class CgolQWidget : public QWidget
{
  Q_OBJECT

public:
  explicit CgolQWidget(QWidget *parent = nullptr);
  virtual void paintEvent(QPaintEvent *);
  void checkCells();
  void performChanges();
  QPushButton *updateButton = new QPushButton(this);
  QPushButton *regenButton = new QPushButton(this);
  QPushButton *saveToJsonButton = new QPushButton(this);
  QPushButton *loadCustomButton = new QPushButton(this);
  QVector<cell> cells = QVector<cell>(constant::NUM_OF_CELLS);
  QVector<cell> cellsNextGen = QVector<cell>(constant::NUM_OF_CELLS);
  QJsonObject cellsJson;
  QLineEdit *setGridSizeLineEdit = new QLineEdit(this);
  const QString *str = new const QString();

public slots:
  void updateGrid();
  void regenerate();
  void saveToJson();
  void loadCustom();
  void setGridSize(const QString& str);
};
#endif // CGOLQWIDGET_H

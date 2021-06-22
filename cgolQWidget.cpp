#include "cgolQWidget.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QDir>
#include <QDebug>

CgolQWidget::CgolQWidget(QWidget *parent) : QWidget(parent)
{
  this->setGeometry(constant::WINDOW_SIZE);
  this->show();

  connect(updateButton, SIGNAL(clicked()), this, SLOT(updateGrid()));
  connect(regenButton, SIGNAL(clicked()), this, SLOT(regenerate()));
  connect(saveToJsonButton, SIGNAL(clicked()), this, SLOT(saveToJson()));
  connect(loadCustomButton, SIGNAL(clicked()), this, SLOT(loadCustom()));
  connect(setGridSizeLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(setGridSize(const QString&)));

  this->updateButton->move(((constant::GRID_PXL_DIM/7) * 0) + constant::WINDOW_BUFFER, constant::BUTTON_Y);
  this->updateButton->setText("refresh");
  this->updateButton->show();

  this->regenButton->move(((constant::GRID_PXL_DIM/7) * 1) + constant::WINDOW_BUFFER, constant::BUTTON_Y);
  this->regenButton->setText("generate");
  this->regenButton->show();

  this->saveToJsonButton->move(((constant::GRID_PXL_DIM/7) * 2) + constant::WINDOW_BUFFER, constant::BUTTON_Y);
  this->saveToJsonButton->setText("save");
  this->saveToJsonButton->show();

  this->loadCustomButton->move(((constant::GRID_PXL_DIM/7) * 3) + constant::WINDOW_BUFFER, constant::BUTTON_Y);
  this->loadCustomButton->setText("load");
  this->loadCustomButton->show();

  this->setGridSizeLineEdit->move(((constant::GRID_PXL_DIM/7) * 4) + constant::WINDOW_BUFFER, constant::LINEEDIT_Y);
  this->setGridSizeLineEdit->show();
}

void CgolQWidget::updateGrid()
{
  this->checkCells();
  this->performChanges();
  cells = cellsNextGen;
  update();
}

void CgolQWidget::regenerate()
{
  int *setState = new int;

  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
  {
    *setState = arc4random() % SPAWN_DENSITY;

    if (*setState == 1)
      this->cells[i].state = true;
    else
      this->cells[i].state = false;

    cells[i].x = i % ROWS_AND_COLUMNS;

    for (int y = 0; y < ROWS_AND_COLUMNS; y++)
      if (i >= y * ROWS_AND_COLUMNS && i < (y + 1) * ROWS_AND_COLUMNS)
        this->cells[i].y = y;
  }

  update();
  delete setState;
  setState = nullptr;
}

void CgolQWidget::paintEvent(QPaintEvent *)
{
  QPainter bigbadwolf(this);
  for (int i = 0; i < constant::CELL_PXL_DIM * ROWS_AND_COLUMNS + 1; i += constant::CELL_PXL_DIM)
  {
    bigbadwolf.drawLine(constant::WINDOW_BUFFER, i + constant::WINDOW_BUFFER, constant::CELL_PXL_DIM * ROWS_AND_COLUMNS + constant::WINDOW_BUFFER, i + constant::WINDOW_BUFFER);
    bigbadwolf.drawLine(i + constant::WINDOW_BUFFER, constant::WINDOW_BUFFER, i + constant::WINDOW_BUFFER, constant::CELL_PXL_DIM * ROWS_AND_COLUMNS + constant::WINDOW_BUFFER);
  }
  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
  {
    if (cells[i].state == true)
    {
      bigbadwolf.fillRect(QRect(constant::WINDOW_BUFFER + cells[i].x * constant::CELL_PXL_DIM, constant::WINDOW_BUFFER + cells[i].y * constant::CELL_PXL_DIM, constant::CELL_PXL_DIM, constant::CELL_PXL_DIM), constant::FULL_CELL);
    }
  }
}

void CgolQWidget::checkCells()
{

  // reset neighbours
  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
    cells[i].neighbours = 0;

  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
  {

    // NORTH CELL ––working––
    if (i > ROWS_AND_COLUMNS - 1)
      if (cells[i + constant::NORTH_CELL].state)
        cells[i].neighbours++;

    // SOUTH CELL ––working––
    if (i < constant::NUM_OF_CELLS - ROWS_AND_COLUMNS - 1)
      if (cells[i + constant::SOUTH_CELL].state)
        cells[i].neighbours++;

    // EAST CELL ––working––
    if (i % ROWS_AND_COLUMNS < ROWS_AND_COLUMNS - 1)
      if (cells[i + constant::EAST_CELL].state)
        cells[i].neighbours++;

    // WEST CELL ––working––
    if (i % ROWS_AND_COLUMNS > 0)
      if (cells[i + constant::WEST_CELL].state)
        cells[i].neighbours++;

    /* NORTH EAST
     * – we need to avoid top most row and far right column
     * – relative to the cell in consideration, the index will be the cell index minus ROWS_AND_COLLUMNS plus 1
     */
     if ((i > ROWS_AND_COLUMNS -1) && (i % ROWS_AND_COLUMNS < ROWS_AND_COLUMNS - 1))
       if (cells[i + constant::EAST_CELL + constant::NORTH_CELL].state)
         cells[i].neighbours++;

    // north west
    if ((i > ROWS_AND_COLUMNS - 1) && (i % ROWS_AND_COLUMNS > 0))
      if (cells[i + constant::NORTH_CELL + constant::WEST_CELL].state)
        cells[i].neighbours++;

    // south east
    if ((i < constant::NUM_OF_CELLS - ROWS_AND_COLUMNS - 1) && (i % ROWS_AND_COLUMNS < ROWS_AND_COLUMNS - 1))
      if (cells[i + constant::SOUTH_CELL + constant::EAST_CELL].state)
        cells[i].neighbours++;

    // south west
    if ((i < constant::NUM_OF_CELLS - ROWS_AND_COLUMNS - 1) && (i % ROWS_AND_COLUMNS > 0))
      if (cells[i + constant::SOUTH_CELL + constant::WEST_CELL].state)
        cells[i].neighbours++;

  }
}

void CgolQWidget::performChanges()
{

  cellsNextGen = cells;

  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
  {

    // any live cell with fewer than two neighbours dies
    if (cells[i].state && cells[i].neighbours < 2)
      cellsNextGen[i].state = false;

    // any live cell with two or three live neighbours lives
    if (cells[i].state == true && (cells[i].neighbours == 2 || cells[i].neighbours == 3))
      cellsNextGen[i].state = true;

    // any live cell with more than three neighbours dies
    if (cells[i].state && cells[i].neighbours == 4)
      cellsNextGen[i].state = false;

    // any dead cell with exactly three live neighbours becomes a live cell
    if (!cells[i].state && cells[i].neighbours == 3)
      cellsNextGen[i].state = true;
  }
}

void CgolQWidget::saveToJson()
{
  QDir::setCurrent("../Resources/");
  QFile file;
  file.setFileName("save.json");
  QJsonArray array;

  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
    array.append(QJsonArray() << cells[i].x << cells[i].y << cells[i].state << cells[i].neighbours);

  QJsonDocument doc(array);
  file.open(QIODevice::WriteOnly | QIODevice::Text);
  file.write(doc.toJson());
  file.close();
}

void CgolQWidget::loadCustom()
{

  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
  {
    this->cells[i].state = false;

    cells[i].x = i % ROWS_AND_COLUMNS;

    for (int y = 0; y < ROWS_AND_COLUMNS; y++)
      if (i >= y * ROWS_AND_COLUMNS && i < (y + 1) * ROWS_AND_COLUMNS)
        this->cells[i].y = y;
  }

  cells[220].state = true;
  cells[220 + ROWS_AND_COLUMNS].state = true;
  cells[220 - ROWS_AND_COLUMNS].state = true;
  cells[221].state = true;
  update();
}

void CgolQWidget::setGridSize(const QString& str)
{
  qDebug()<<str;
}

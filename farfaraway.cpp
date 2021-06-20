#include "farfaraway.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QDir>
#include <QDebug>

farfaraway::farfaraway(QWidget *parent) : QWidget(parent)
{
  this->setGeometry(constant::WINDOW_SIZE);
  this->show();

  connect(updateButton, SIGNAL(clicked()), this, SLOT(updateGrid()));
  connect(regenButton, SIGNAL(clicked()), this, SLOT(regenerate()));
  connect(saveToJsonButton, SIGNAL(clicked()), this, SLOT(saveToJson()));
  connect(loadCustomButton, SIGNAL(clicked()), this, SLOT(loadCustom()));

  this->updateButton->move(0 + constant::WINDOW_BUFFER, constant::BUTTON_Y);
  this->updateButton->setText("refresh");
  this->updateButton->show();

  this->regenButton->move(100 + constant::WINDOW_BUFFER, constant::BUTTON_Y);
  this->regenButton->setText("generate");
  this->regenButton->show();

  this->saveToJsonButton->move(300 + constant::WINDOW_BUFFER, constant::BUTTON_Y);
  this->saveToJsonButton->setText("save");

  this->loadCustomButton->move(500 + constant::WINDOW_BUFFER, constant::BUTTON_Y);
  this->loadCustomButton->setText("load");
}

void farfaraway::updateGrid()
{
  this->checkCells();
  this->performChanges();
  cells = cellsNextGen;
  update();
}

void farfaraway::regenerate()
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

void farfaraway::paintEvent(QPaintEvent *)
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

  //  int x = 49;
  //  int y = 0;
  //  bigbadwolf.fillRect(QRect(constant::WINDOW_BUFFER + x * constant::CELL_PXL_DIM, constant::WINDOW_BUFFER + y * constant::CELL_PXL_DIM, constant::CELL_PXL_DIM, constant::CELL_PXL_DIM), Qt::red);
}

void farfaraway::checkCells()
{

  // reset neighbours
  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
    cells[i].neighbours = 0;

  for (int i = 0; i < constant::NUM_OF_CELLS; i++)
  {

    // north cell ––working––
    if (i > ROWS_AND_COLUMNS - 1)
      if (cells[i + constant::NORTH_CELL].state)
        cells[i].neighbours++;

    // south cell ––working––
    if (i < constant::NUM_OF_CELLS - ROWS_AND_COLUMNS - 1)
      if (cells[i + constant::SOUTH_CELL].state)
        cells[i].neighbours++;

    // east cell ––working––
    if (i % ROWS_AND_COLUMNS < ROWS_AND_COLUMNS - 1)
      if (cells[i + constant::EAST_CELL].state)
        cells[i].neighbours++;

    // west cell ––working––
    if (i % ROWS_AND_COLUMNS > 0)
      if (cells[i + constant::WEST_CELL].state)
        cells[i].neighbours++;

    // north east

    // north west

    // south east

    // south west
  }
}

void farfaraway::performChanges()
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

void farfaraway::saveToJson()
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

void farfaraway::loadCustom()
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
  update();
}

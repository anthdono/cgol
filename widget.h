#ifndef WIDGET_H
#define WIDGET_H

#include <QPainter>
#include <QPushButton>
#include <QJsonObject>
#include <QString>
#include <QInputDialog>
#include <QLineEdit>
#include <QInputDialog>

struct cell
{
    int x;
    int y;
    bool state;
    int neighbours;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);

    int spawn_density = 10;

    int ROWS_AND_COLUMNS = 50;
    int NUM_OF_CELLS = ROWS_AND_COLUMNS * ROWS_AND_COLUMNS;
    int NORTH_CELL = -ROWS_AND_COLUMNS;
    int SOUTH_CELL = ROWS_AND_COLUMNS;
    const int EAST_CELL = 1;
    const int WEST_CELL = -1;
    const int SCREEN_POS = 0;
    const QBrush FULL_CELL = QBrush(Qt::white, Qt::SolidPattern);
    int GRID_PXL_DIM = 12 * ROWS_AND_COLUMNS;
    int CELL_PXL_DIM = GRID_PXL_DIM / ROWS_AND_COLUMNS;
    const int WINDOW_BUFFER = 10;
    QRect WINDOW_SIZE = QRect(SCREEN_POS, SCREEN_POS, GRID_PXL_DIM + (WINDOW_BUFFER * 2), GRID_PXL_DIM + WINDOW_BUFFER + GRID_PXL_DIM / 10);
    int BUTTON_Y = GRID_PXL_DIM + 10;
    QVector<cell> cells = QVector<cell>(NUM_OF_CELLS);
    QVector<cell> cellsNextGen = QVector<cell>(NUM_OF_CELLS);
    QJsonObject cellsJson;

    void checkCells();
    void performChanges();
    void buttons(bool repaint);
    void varUpdates();
    virtual void paintEvent(QPaintEvent *);

    QPushButton* updateButton = new QPushButton(this);
    QPushButton* regenButton = new QPushButton(this);
    QPushButton* saveToJsonButton = new QPushButton(this);
    QPushButton* loadCustomButton = new QPushButton(this);
    QPushButton* customGridSizeButton = new QPushButton(this);
    QPushButton* spawnDensityButton = new QPushButton(this);




    // button for "auto refresh mode"

public slots:
    void updateGrid();
    void regenerate();
    void saveToJson();
    void loadCustom();
    void gridSize();
    void updateSpawnDensity();
};

#endif // CGOLQWIDGET_H

#include "farfaraway.h"
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QPalette>
#include <QVector>
#include <QDebug>








void farfaraway::updateGrid()
{
    //    this->rectLoc += gc::PXLDIMCELL;
    //    debug += 12;
    cellMaths();
    update();
}

void farfaraway::regen()
{


    int* setState = new int;
    for (int i = 0; i < cm::NUM_OF_CELLS; i++)
    {
        *setState = arc4random() % 3;
        if (*setState == 1)
        {
            this->cells[i].state = true;
        }
        else
        {
            this->cells[i].state = false;
        }
    }

    //    int x = 0;
    //    int y = 0;
    for(int i = 0; i < cm::NUM_OF_CELLS; i++)
    {
        for(int y = 0; y < cm::ROWS_AND_COLUMNS; y++)
        {
            // for y axis
            if(i >= y*cm::ROWS_AND_COLUMNS && i < (y+1)*cm::ROWS_AND_COLUMNS)
            {
                qDebug()<<i<<y;
            }
        }
    }

    delete setState;
    setState = nullptr;
}

farfaraway::farfaraway(QWidget *parent) : QWidget(parent)
{
    // widget config
    this->setGeometry(gc::WINDOW_SIZE);

    // set background color
    QPalette pal = this->palette();
    pal.setColor(QPalette::Window, Qt::black);
    this->setPalette(pal);
    this->setAutoFillBackground(true);
    this->show();

    // connecting signals with slots
    connect(refreshButton, SIGNAL(clicked()), this, SLOT(updateGrid()));
    connect(regenButton, SIGNAL(clicked()), this, SLOT(regen()));

    // refresh button
    this->refreshButton->setGeometry(gc::WINDOW_BUFFER, gc::BUTTON_Y, gc::BUTTON_W, gc::BUTTON_H);
    this->refreshButton->setText("refresh");
    this->refreshButton->show();

    // regen button
    this->regenButton->setGeometry(gc::WINDOW_BUFFER + 120, gc::BUTTON_Y, gc::BUTTON_W, gc::BUTTON_H);
    this->regenButton->setText("generate pattern");
    this->regenButton->show();
}

void farfaraway::paintEvent(QPaintEvent *)
{
    // instantiate the QPainter object
    QPainter bigbadwolf(this);

    for (int i = 0; i < gc::WINDOW_PXL_DIM + 1; i += gc::CELL_PXL_DIM)
    {
        /*
        draw grid
        -2 is used here to tidy the overdrawing of lines
        */

        bigbadwolf.drawLine(gc::WINDOW_BUFFER, i + gc::WINDOW_BUFFER, gc::WINDOW_PXL_DIM + gc::WINDOW_BUFFER, i + gc::WINDOW_BUFFER);
        bigbadwolf.drawLine(i + gc::WINDOW_BUFFER, gc::WINDOW_BUFFER, i + gc::WINDOW_BUFFER, gc::WINDOW_PXL_DIM + gc::WINDOW_BUFFER);
    }

    /*
    for loop of num_of_cells calling cellMaths for each cell
    */


//     for (int i = 0; i < cm::NUM_OF_CELLS; i++)
//     {
//         if (currentGrid[i])
//         {
//             bigbadwolf.fillRect(QRect(gc::WINDOW_BUFFER + 600, gc::WINDOW_BUFFER + 600, gc::CELL_PXL_DIM, gc::CELL_PXL_DIM), gc::FULL_CELL);
//         }
//     }


    // test cell at 600,600
     //             bigbadwolf.fillRect(QRect(gc::WINDOW_BUFFER + 600, gc::WINDOW_BUFFER + 600, gc::CELL_PXL_DIM, gc::CELL_PXL_DIM), gc::FULL_CELL);
}

cell farfaraway::cellMaths()
{


    cell cell;
    cell.x = 10;

    return cell;
}

farfaraway::~farfaraway()
{
    delete refreshButton;
    refreshButton = nullptr;
    delete regenButton;
    regenButton = nullptr;
}
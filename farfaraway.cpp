#include "farfaraway.h"
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QPalette>
#include <QVector>
#include <QDebug>
#include <QStyleFactory>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>
#include <QPair>
#include <QFile>
#include <QDir>
#include <iostream>
#include <string>
#include <QLocale>

void farfaraway::updateGrid()
{
	this->golCheckCells(); // add number of neighbours to cell struct
	update();	// refresh paint event
}



void farfaraway::regen()
{
	int *setState = new int;
	for (int i = 0; i < cm::NUM_OF_CELLS; i++)
	{
		*setState = arc4random() % 5;
		if (*setState == 1)
		{
			this->cells[i].state = true;
		}
		else
		{
			this->cells[i].state = false;
		}
	}

	// for x axis
	for (int i = 0; i < cm::NUM_OF_CELLS; i++)
	{
		cells[i].x = i % 50;
	}

	// for y axis
	for (int i = 0; i < cm::NUM_OF_CELLS; i++)
	{
		for (int y = 0; y < cm::ROWS_AND_COLUMNS; y++)
		{
			if (i >= y * cm::ROWS_AND_COLUMNS && i < (y + 1) * cm::ROWS_AND_COLUMNS)
			{
				this->cells[i].y = y;
			}
		}
	}

	update();

	delete setState;
	setState = nullptr;
}

void farfaraway::debugging()
{
//	for(int i = 0; i < cm::NUM_OF_CELLS; i++)
//		{
//			qDebug()<<cells[i].x<<" "<<cells[i].y<<"\n";
//		}

	qDebug()<<cellsJson;

}

farfaraway::farfaraway(QWidget *parent) : QWidget(parent)
{
	// widget config
	this->setGeometry(gc::WINDOW_SIZE);
	this->show();

	// connecting signals with slots
	connect(refreshButton, SIGNAL(clicked()), this, SLOT(updateGrid()));
	connect(regenButton, SIGNAL(clicked()), this, SLOT(regen()));
//	connect(debugButton, SIGNAL(clicked()), this, SLOT(debugging()));
	connect(saveToJsonButton, SIGNAL(clicked()),this, SLOT(saveToJson()));

	// refresh button
	this->refreshButton->move(0+gc::WINDOW_BUFFER, gc::BUTTON_Y);
	this->refreshButton->setText("refresh");
	this->refreshButton->show();

	// regen button
	this->regenButton->move(100+gc::WINDOW_BUFFER, gc::BUTTON_Y);
	this->regenButton->setText("generate");
	this->regenButton->show();

	// debug button
//	this->debugButton->move(200+gc::WINDOW_BUFFER, gc::BUTTON_Y);
//	this->debugButton->setText("debug");

	// save to json button
	this->saveToJsonButton->move(300+gc::WINDOW_BUFFER, gc::BUTTON_Y);
	this->saveToJsonButton->setText("save");
}

void farfaraway::paintEvent(QPaintEvent *)
{
	// instantiate the QPainter object
	QPainter bigbadwolf(this);

	for (int i = 0; i < gc::CELL_PXL_DIM * cm::ROWS_AND_COLUMNS + 1; i += gc::CELL_PXL_DIM)
	{
		bigbadwolf.drawLine(gc::WINDOW_BUFFER, i + gc::WINDOW_BUFFER, gc::CELL_PXL_DIM * cm::ROWS_AND_COLUMNS + gc::WINDOW_BUFFER, i + gc::WINDOW_BUFFER);
		bigbadwolf.drawLine(i + gc::WINDOW_BUFFER, gc::WINDOW_BUFFER, i + gc::WINDOW_BUFFER, gc::CELL_PXL_DIM * cm::ROWS_AND_COLUMNS + gc::WINDOW_BUFFER);
	}

	// draw the cells
	for (int i = 0; i < cm::NUM_OF_CELLS; i++)
	{
		if (cells[i].state == true)
		{
			bigbadwolf.fillRect(QRect(gc::WINDOW_BUFFER + cells[i].x * gc::CELL_PXL_DIM, gc::WINDOW_BUFFER + cells[i].y * gc::CELL_PXL_DIM, gc::CELL_PXL_DIM, gc::CELL_PXL_DIM), gc::FULL_CELL);
		}
	}
}

void farfaraway::golCheckCells()
{
	// the temp variable to hold number of cell neighbours before adding to cell struct instances
	// for each cell
	int n;
	for (int i = 0; i < cm::NUM_OF_CELLS; i++)
	{
		n = 0;

		//	check northern cell
		if (i > cm::ROWS_AND_COLUMNS)	//	check if cell is in top most row (cannot have north cell)
			if (cells[i+cm::NORTH_CELL].state)
				n++;

		// check southern cell
		if (i < cm::NUM_OF_CELLS-cm::ROWS_AND_COLUMNS)
			if (cells[i+cm::SOUTH_CELL].state)
				n++;


		// check cell east
		// check cell west

		cells[i].neighbours = n;
//		qDebug()<<n;
	}

}

void farfaraway::golPerformChanges()
{

}

void farfaraway::saveToJson()
{
	QDir::setCurrent("../Resources/");
	QFile file;
	file.setFileName("save.json");
	QJsonArray array;

	for (int i = 0; i < cm::NUM_OF_CELLS; i++)
	{
		array.append(QJsonArray() << cells[i].x << cells[i].y << cells[i].state);
	}

	QJsonDocument doc(array);
	file.open(QIODevice::WriteOnly|QIODevice::Text);
	file.write(doc.toJson());
	file.close();

}




farfaraway::~farfaraway()
{
	delete refreshButton;
	refreshButton = nullptr;
	delete regenButton;
	regenButton = nullptr;
}

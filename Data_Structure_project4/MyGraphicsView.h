#pragma once

#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <qobject.h>
#include <qgraphicsview.h>
#include <qpoint.h>
#include <qevent.h>

class MyGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	MyGraphicsView(QWidget *parent);
	~MyGraphicsView();

protected:
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);

signals:
	void mouseMovePoint(QPoint point);
	void mouseClicked(QPoint point);
};
#endif // !MYGRAPHICSVIEW_H
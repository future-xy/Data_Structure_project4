#include "MyGraphicsView.h"

MyGraphicsView::MyGraphicsView(QWidget *parent)
	: QGraphicsView(parent)
{
}

MyGraphicsView::~MyGraphicsView()
{
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{//����ƶ��¼�
	QPoint point = event->pos(); //QGraphicsView������
	emit mouseMovePoint(point); //�ͷ��ź�
	QGraphicsView::mouseMoveEvent(event);
}

void MyGraphicsView::mousePressEvent(QMouseEvent *event)
{ //�����������¼�
	if (event->button() == Qt::LeftButton)
	{
		QPoint point = event->pos(); //QGraphicsView������
		emit mouseClicked(point);//�ͷ��ź�
	}
	QGraphicsView::mousePressEvent(event);
}

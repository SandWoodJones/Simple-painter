#include "graphicsscene.h"
#include <QDebug>

GraphicsScene::GraphicsScene(QObject *parent)
	: QGraphicsScene(parent) {
	setSceneRect(0, 0, 500, 500);

	pen = QPen(Qt::red);
	brush = QBrush(Qt::red, Qt::SolidPattern);
}

GraphicsScene::~GraphicsScene() { qDebug() << "deleted scene"; }

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	if (event->button() != Qt::LeftButton)
		return;

	QPointF pt = event->scenePos();

	QGraphicsEllipseItem *el = this->addEllipse(
		0, 0, POINT_RADIUS * 2, POINT_RADIUS * 2, pen, brush
	);

	el->setPos(pt.x() - POINT_RADIUS, pt.y() - POINT_RADIUS);

	point_list.append(el);

	this->polygon = this->addPolygon(handlePoints(), pen, brush);

	QGraphicsScene::mousePressEvent(event);
}

QPolygonF GraphicsScene::handlePoints() {
	QList<QPointF> points;

	foreach(QGraphicsEllipseItem *item, point_list) {
		points.append(item->scenePos());
	}

	return QPolygonF(points);
}

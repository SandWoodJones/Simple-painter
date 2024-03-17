#include "graphicsview.h"
#include "graphicsscene.h"
#include <QDebug>

graphicsview::graphicsview(QWidget *parent)
	: QGraphicsView(parent) {}

void graphicsview::wheelEvent(QWheelEvent *event) {
	setTransformationAnchor(AnchorUnderMouse);

	if (event->angleDelta().y() > 0) {
		scale(SCALE_FACTOR, SCALE_FACTOR);

	} else {
		scale(1 / SCALE_FACTOR, 1 / SCALE_FACTOR);
	}
}

void graphicsview::clearPoints() {
	GraphicsScene *_scene = dynamic_cast<GraphicsScene *>(scene());

	foreach(QGraphicsEllipseItem *item, _scene->point_list) {
		_scene->removeItem(item);
		_scene->point_list.clear();
	}

	_scene->clear();
}

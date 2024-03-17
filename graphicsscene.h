#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#define POINT_RADIUS 1.5

#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPoint>

class GraphicsScene : public QGraphicsScene {
	Q_OBJECT

	public:
	explicit GraphicsScene(QObject *parent = nullptr);
	~GraphicsScene();
	QList<QGraphicsEllipseItem *> point_list;
	QGraphicsPolygonItem *polygon;

	private:
	QPen pen;
	QBrush brush;
	QPolygonF handlePoints();

	protected:
	virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // GRAPHICSSCENE_H

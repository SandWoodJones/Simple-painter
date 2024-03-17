#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#define SCALE_FACTOR 1.1

#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QWheelEvent>

class graphicsview : public QGraphicsView {
	Q_OBJECT

	public:
	explicit graphicsview(QWidget *parent = nullptr);

	public slots:
	void clearPoints();

	protected:
	virtual void wheelEvent(QWheelEvent *event);
};

#endif // GRAPHICSVIEW_H

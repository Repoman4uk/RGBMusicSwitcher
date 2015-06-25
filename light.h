#ifndef LIGHT_H
#define LIGHT_H

#include <QWidget>
#include "trackbar.h"
#include <QStyleOption>
#include <QPainter>

//class trackbar;

class Light : public trackbar
{
    Q_OBJECT
public:
    explicit Light(trackbar *parent = 0);
    virtual void mousePressEvent(QMouseEvent *m);
    virtual void mouseReleaseEvent(QMouseEvent *m);
    virtual void mouseMoveEvent(QMouseEvent *m);

signals:

public slots:
private:
    int x,y,x_old,y_old;
};

#endif // LIGHT_H

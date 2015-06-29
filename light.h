#ifndef LIGHT_H
#define LIGHT_H

#include <QWidget>
#include "trackbar.h"
#include <QStyleOption>
#include <QPainter>
#include "oneLight.h"

//class trackbar;

class Light : public trackbar
{
    Q_OBJECT
public:

    explicit Light(trackbar *parent = 0);
    virtual void mousePressEvent(QMouseEvent *m);
    virtual void mouseReleaseEvent(QMouseEvent *m);
    virtual void mouseMoveEvent(QMouseEvent *m);
    void setLR(int left, int right);
    int left(){return this->l;}
    int right(){return this->r;}



signals:

public slots:
private:
    int x,y,x_old,y_old;
    int l,r;
    trackbar *parent;

};

#endif // LIGHT_H

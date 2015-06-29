#ifndef TRACKBAR_H
#define TRACKBAR_H

#include <QWidget>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>
#include <QVector>
#include <QDebug>
#include "oneLight.h"
class Light;

class trackbar : public QWidget
{
    Q_OBJECT

private:
    int x,y;
    Light *one,*two;

    QVector <oneLight> lights;
    int customWidth;
public:


    explicit trackbar(QWidget *parent = 0);
    virtual void mousePressEvent(QMouseEvent *m);
    virtual void mouseReleaseEvent(QMouseEvent *m);
    virtual void mouseMoveEvent(QMouseEvent *m);
    virtual void paintEvent(QPaintEvent *);
    void pasteLight(oneLight a);
    void setScopes();
    void updateLightPos();
signals:

public slots:

};

#endif // TRACKBAR_H

#ifndef TRACKBAR_H
#define TRACKBAR_H

#include <QWidget>
#include <QMouseEvent>
#include <QStyleOption>
#include <QPainter>
class Light;

class trackbar : public QWidget
{
    Q_OBJECT

private:
    int x,y;
    Light *one,*two;
public:
    explicit trackbar(QWidget *parent = 0);
    virtual void mousePressEvent(QMouseEvent *m);
    virtual void mouseReleaseEvent(QMouseEvent *m);
    virtual void mouseMoveEvent(QMouseEvent *m);
    virtual void paintEvent(QPaintEvent *);
signals:

public slots:

};

#endif // TRACKBAR_H

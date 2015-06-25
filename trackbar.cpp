#include "trackbar.h"
#include "light.h"

trackbar::trackbar(QWidget *parent) :
    QWidget(parent)
{
    one=0;
    setStyleSheet("border:1px solid grey;");
    this->show();

}
void trackbar::mousePressEvent(QMouseEvent *m)
{
    if (one)
    {
        delete one;
        one=0;
    }
    x=m->x();
    y=m->y();
    //one=new Light(this);
    //one->setGeometry(x,y,0,0);
}
void trackbar::mouseMoveEvent(QMouseEvent *m)
{
    if (!one) one=new Light(this);
    if (m->x()>=x) one->setGeometry(x,0,abs(x-m->x()),this->height());
    else one->setGeometry(m->x(),0,abs(x-m->x()),this->height());
    //if (m->x()>=x && !(m->y()>=y)) one->setGeometry(x,m->y(),abs(x-m->x()),abs(y-m->y()));
    //if (!(m->x()>=x) && !(m->y()>=y)) one->setGeometry(m->x(),m->y(),abs(x-m->x()),abs(y-m->y()));
    one->show();

}
void trackbar::mouseReleaseEvent(QMouseEvent *m)
{

}
void trackbar::paintEvent(QPaintEvent *a)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

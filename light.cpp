#include "light.h"
#include "trackbar.h"
#include <QDebug>

Light::Light(trackbar *parent) :
    trackbar(parent)
{
    /*QPalette pall;
    pall.setColor(this->backgroundRole(), Qt::blue);
    this->setPalette(pall);
    this->setAutoFillBackground(true);*/
    setStyleSheet("background: blue; border:0px");
    this->parent=parent;

}
void Light::mousePressEvent(QMouseEvent *m)
{
    /*QPalette p;
    p.setColor(this->backgroundRole(),Qt::yellow);
    this->setPalette(p);*/
    setStyleSheet("background: yellow; border:0px");
    x=m->globalX();
    //y=m->globalY();
    x_old=pos().x();
    //y_old=pos().y();
    //qDebug()<<"11111";
}
void Light::mouseReleaseEvent(QMouseEvent *m)
{
    parent->updateLightPos();
    parent->setScopes();
}
void Light::mouseMoveEvent(QMouseEvent *m)
{

    if (x_old-x+m->globalX()+this->width()>=this->r)
        this->move(this->r-this->width(),0);
    else if (x_old-x+m->globalX()<=this->l) this->move(this->l,0);
    else this->move(x_old-x+m->globalX(),0);
    //qDebug()<<m->globalX();
}
void Light::setLR(int left, int right)
{
    this->l=left;
    this->r=right;
}

#include "trackbar.h"
#include "light.h"

trackbar::trackbar(QWidget *parent) :
    QWidget(parent)
{
    one=0;
    setStyleSheet("border:1px solid grey;");
    this->show();
    customWidth=this->width();


}
void trackbar::mousePressEvent(QMouseEvent *m)
{
    if (one)
    {
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
    if (m->x()>=x) one->setGeometry(x,0,abs(x-m->x()),this->height());
    else one->setGeometry(m->x(),0,abs(x-m->x()),this->height());
    one->show();
    oneLight l;
    l.begin=one->pos().x();
    l.end=one->pos().x()+one->width();
    l.light=one;
    pasteLight(l);
    setScopes();
    //.append(l);
    for (int i=0;i<lights.size();i++) qDebug()<< lights.at(i).begin;
    qDebug()<<11;
}
void trackbar::paintEvent(QPaintEvent *a)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
void trackbar::pasteLight(oneLight a)
{
    if (lights.size()==0)
    {
        lights.append(a);
        return;
    }
    if (a.end<=lights.at(0).begin)
    {
        lights.insert(0,a);
        return;
    }
    for (int i=0;i<lights.size()-1;i++)
    {
        if (a.begin>=lights.at(i).end && a.end<=lights.at(i+1).begin)
        {

            lights.insert(i+1,a);
            return;
        }
    }

    lights.push_back(a);
    return;
}
void trackbar::setScopes()
{
    if (lights.size()==2)
    {
        if (lights.at(0).light->left()!=0 || lights.at(0).light->right()!=lights.at(1).begin)
        {
            lights.at(0).light->setLR(0,lights.at(1).begin);
        }
        if (lights.at(1).light->left()!=lights.at(0).end || lights.at(0).light->right()!=this->width())
        {
            lights.at(1).light->setLR(lights.at(0).end,this->width());
        }
    }
    else
    if (lights.size()>2)
    {
        if (lights.at(0).light->left()!=0 || lights.at(0).light->right()!=lights.at(1).begin)
        {
            lights.at(0).light->setLR(0,lights.at(1).begin);
        }
        for (int i=1;i<lights.size()-1;i++)
        {
            if (lights.at(i).light->left()!=lights.at(i-1).end
                    || lights.at(i).light->right()!=lights.at(i+1).begin)
                lights.at(i).light->setLR(lights.at(i-1).end,lights.at(i+1).begin);
        }
        if (lights.last().light->left()!=lights.at(lights.size()-2).end
                || lights.last().light->right()!=this->width())
            lights.last().light->setLR(lights.at(lights.size()-2).end,this->width());
    }
    else lights.at(0).light->setLR(0,this->width());
}
void trackbar::updateLightPos()
{
    for (int i=0;i<lights.size();i++)
    {
        lights[i].begin=lights.at(i).light->pos().x();
        lights[i].end=lights.at(i).light->pos().x()+lights.at(i).light->width();

    }
}

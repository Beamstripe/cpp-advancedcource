#include "rightwidget.h"
#include <QPainter>
rightwidget::rightwidget(QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(400,200);
    balls.clear(); //��պ��ֹ���� 3 ��С�����ڲ���
    addBall(Ball(30,20,10,10,49,Qt::red));
    addBall(Ball(56,200,10,4,39,Qt::blue));
    addBall(Ball(80,100,10,7,69,Qt::yellow));
}
void rightwidget::paintEvent(QPaintEvent *){
    QPainter p(this);
//    ball.draw(&p);
    for(auto& b:balls)
    b.draw(&p);
}
void rightwidget::updateBalls() //��װ�Ŀ���С���ƶ��Ľӿ�
{
//    ball.setRectangle(this->geometry()); //ΪС�����ü��Ĵ��ڱ߽�
//    ball.move();
    for(auto &b:balls){
        b.setRectangle(this->geometry());
        b.move();
    }
    int i,j;
    for(i=0;i<balls.size()-1;++i){
        for(j=i+1;j<balls.size();++j)
            balls[i].checkCollision(balls[j]);
    }
    update(); //���´�����ʾ���ػ�С��
}
void rightwidget::addBall(const Ball &b){
    balls.append(b);
}
void rightwidget::mousePressEvent(QMouseEvent *e){
    double posx=e->x(),posy=e->y();
    setPre(posx,posy);
}
void rightwidget::mouseReleaseEvent(QMouseEvent *e){
    double x=e->x(),y=e->y();
    double speed=0.5*sqrt((prex-x)*(prex-x)+(prey-y)*(prey-y));
    double sgn=prex>x?1:-1;
    double theta=sgn*(acos(-1)-atan((prey-y)/(prex-x)))*180/acos(-1);
    addBall(Ball(x,y,10,speed,theta,Qt::red));
}

#ifndef BALL_H
#define BALL_H
#include <QColor>
#include <QRect>
#include <QPainter>
class Ball
{
public:
    Ball();
    Ball(double xpos,double ypos,double r,double s,double a,
         QColor c);
    void setRectangle(const QRect& rect){
        this->rect=rect;
    }
    void draw(QPainter *p); //����С��
    void move(); //��ָ���ķ������ƶ� 1 ��
    void checkCollision(Ball &b);
private:
    double x,y; //С�������Ϊλ��
    double radius; //С��뾶
    double speed; //С���ƶ��ٶ�
    double angle; //С���ƶ��Ƕ�
    QColor color; //С�������ɫ
    QRect rect; //���ڼ��Ĵ��ھ�������
    void checkBoundary();
};

#endif // BALL_H

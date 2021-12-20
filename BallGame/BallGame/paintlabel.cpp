#include "paintlabel.h"
#include <QPainter>
#include <QWidget>
#include <QColorDialog>

PaintLabel::PaintLabel(QWidget *parent) :
    QLabel(parent)
{
    fillColor=Qt::blue;
}
void PaintLabel::setFillColor(QColor color){
    fillColor=color;
}
QColor PaintLabel::getFillColor(){
    return fillColor;
}
void PaintLabel::paintEvent(QPaintEvent *event){
    QLabel::paintEvent(event);
    QPainter p(this);
    QPen pen(fillColor,2,Qt::SolidLine);
    QBrush brush(fillColor);
    p.setPen(pen);
    p.setBrush(brush);
    p.drawRect(0,0,this->width(),this->height());
    //���� fillColor ��� Label �ؼ���ʵ����ɫԤ��
}
void PaintLabel::mousePressEvent(QMouseEvent *e){
    QColor chooseColor=QColorDialog::getColor(fillColor); //������ɫֵ
    if(chooseColor.isValid()==true) //����û�ȡ�����򷵻���Ч��ɫֵ
    {
        fillColor=chooseColor;
        update();
    }
}

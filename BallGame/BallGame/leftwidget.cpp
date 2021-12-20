#include "leftwidget.h"
#include <QGridLayout>
#include <QPalette>
#include <QEvent>
#include <QPainter>
#include <QString>
#include "mainwindow.h"
leftwidget::leftwidget(QWidget *parent) :
    QWidget(parent)
{
    pmain=(MainWindow *)parent;
    xLabel=new QLabel(this);
    xLabel->setText(tr("x ����:"));
    yLabel=new QLabel(this);
    yLabel->setText(tr("y ����:"));
    radiusLabel=new QLabel(this);
    radiusLabel->setText(tr("�뾶:"));
    speedLabel=new QLabel(this);
    speedLabel->setText(tr("�ٶ�:"));
    angleLabel=new QLabel(this);
    angleLabel->setText(tr("�Ƕ�:"));
    colorLabel=new QLabel(this);
    colorLabel->setText(tr("��ɫ:"));
    xEdit=new QLineEdit("100",this);
    yEdit=new QLineEdit("50",this);
    radiusEdit=new QLineEdit("10",this);
    speedEdit=new QLineEdit("5",this);
    colorPreview=new PaintLabel(this);
    colorPreview->setText(tr(" ")); //��ʼ�ַ���ȷ���ؼ���С
    angleEdit=new QLineEdit("40",this);
    addButton=new QPushButton(tr("���"),this);
    stopButton=new QPushButton(tr("��ͣ"),this);
    QGridLayout *mainLayout=new QGridLayout(this);
    mainLayout->addWidget(xLabel,0,0);
    mainLayout->addWidget(xEdit,0,1);
    mainLayout->addWidget(yLabel,1,0);
    mainLayout->addWidget(yEdit,1,1);
    mainLayout->addWidget(radiusLabel,2,0);
    mainLayout->addWidget(radiusEdit,2,1);
    mainLayout->addWidget(speedLabel,3,0);
    mainLayout->addWidget(speedEdit,3,1);
    mainLayout->addWidget(angleLabel,4,0);
    mainLayout->addWidget(angleEdit,4,1);
    mainLayout->addWidget(colorLabel,5,0);
    mainLayout->addWidget(colorPreview,5,1);
    mainLayout->addWidget(addButton,6,0);
    mainLayout->addWidget(stopButton,6,1);
    setLayout(mainLayout);
    connect(addButton,SIGNAL(clicked()),this,SLOT(addBall()));
    connect(stopButton,SIGNAL(clicked()),this,SLOT(stopBall()));
}
void LeftWidget::addBall(){
    RightWidget *right=pmain->getRightWidget();
    //pmain ʱָ�������ڵ�ָ�룬ͨ����ӿ� getRightWidget ���
    //�Ҳര��ָ�룬�ٵ��� right �� addBall �ӿ����С��
    double x,y;
    double radius,angle,speed;
    QColor fillColor;
    bool ok;
    x=xEdit->text().toDouble(&ok);
    y=yEdit->text().toDouble(&ok);
    radius=radiusEdit->text().toDouble(&ok);
    speed=speedEdit->text().toDouble(&ok);
    angle=angleEdit->text().toDouble(&ok);
    fillColor=colorPreview->getFillColor();
    right->addBall(Ball(x,y,radius,speed,angle,fillColor));
}
void LeftWidget::stopBall(){
    if(stopButton->text()==tr("��ͣ")){
        pmain->StopTimer();
        stopButton->setText(tr("��ʼ"));
    }
    else{
        pmain->resumeTimer();
        stopButton->setText(tr("��ͣ"));
    }
}

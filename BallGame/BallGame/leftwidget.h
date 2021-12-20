#ifndef LEFTWIDGET_H
#define LEFTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "paintlabel.h"
class MainWindow;
class leftwidget : public QWidget
{
    Q_OBJECT
public:
    explicit leftwidget(QWidget *parent = 0);
private:
    QLabel *xLabel,*yLabel,*radiusLabel,
    *speedLabel,*angleLabel,*colorLabel;
    QLineEdit *xEdit,*yEdit,*radiusEdit,*speedEdit,*angleEdit;
    QPushButton *addButton,*stopButton;
    MainWindow *pmain; //ָ�������ڵ�ָ��
    PaintLabel *colorPreview;
signals:

public slots:
    void addBall(); //���С��
    void stopBall(); //���ƶ�ʱ������������ͣ
};

#endif // LEFTWIDGET_H

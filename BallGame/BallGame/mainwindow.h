#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include "leftwidget.h"
#include "rightwidget.h"
#include <QTimer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    rightwidget* getRightWidget(){return right;}
    void StopTimer(); //ֹͣ��ʱ���Ľӿ�
    void resumeTimer(); //������ʱ���Ľӿ�
protected slots:
    void timeToShow();
private:
    leftwidget *left;
    rightwidget *right;
    QSplitter *splitter;
    QTimer *timer; //��ʱ������
};

#endif // MAINWINDOW_H

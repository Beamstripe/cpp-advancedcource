#include <QCoreApplication>
#include <iostream>
#include "header.h"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"��ӭʹ�ù���������ϵͳ��\n";
    readData(pCommodities,"commmodity2.dat");
    while(true){
        char choice=menu();
        if(choice=='0')
            break;
        switch(choice)  {
        case '1':
            addCommodity(pCommodities,commodityNum);
            break;
        case '2':
            removeCommodity(pCommodities,commodityNum);
            break;
        case '4':
            viewCommodity(pCommodities,commodityNum);
            break;
        case '5':
            displayCommodities(pCommodities,commodityNum);
            break;
        case '6':
            checkOut(pCommodities,commodityNum);
            break;
        case '3':
            modifyCommodity(pCommodities,commodityNum);
            break;
        default:
            cout<<"��Ч���룡�����ԣ�\n";
            break;
        }
    }
    writeData(pCommodities,"commodity2.dat");
    delete[] pCommodities;
    cout<<"�ټ���\n";
    return a.exec();
}

#include <QCoreApplication>
#include <iostream>
#include "header.h"
using namespace std;
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"��ӭʹ�ù���������ϵͳ��\n";
    readData("commmodity2.dat");
    while(true){
        char choice=menu();
        if(choice=='0')
            break;
        switch(choice)  {
        case '1':
            addCommodity(commodities,commodityNum);
            break;
        case '2':
            removeCommodity(commodities,commodityNum);
            break;
        case '3':
            viewCommodity(commodities,commodityNum);
            break;
        case '4':
            displayCommodities(commodities,commodityNum);
            break;
        case '5':
            checkOut(commodities,commodityNum);
            break;
        default:
            cout<<"��Ч���룡�����ԣ�\n";
            break;
        }
    }
    writeData("commodity2.dat");
    delete[] pCommodities;
    cout<<"�ټ���\n";
    return a.exec();
}

#include <QCoreApplication>
#include <iostream>
#include "header.h"

using namespace std;
//void doAddCommodity(CommodityManage& cm){
//    string name;
//    double price,discount;
//    double tariff;
//    int num,type;
//    cout<<"ѡ����Ʒ����(0-��ͨ��Ʒ�� 1-���⹺��Ʒ)";
//    cin>>type;
//    fflush(stdin);
//    cout<<"������Ʒ����:";
//    getline(cin,name);
//    cout<<"����۸����Ʒ����:";
//    cin>>price>>num;
//    if(type==0){
//        cout<<"������Ʒ�ۿ�:";
//        cin>>discount;
//        cm.addCommodity(new
//                        NormalCommodity(name,price,num,discount));
//    }
//    else if(type==1){
//        cout<<"������Ʒ�ۿۺ͹�˰:";
//        cin>>discount>>tariff;
//        cm.addCommodity(new
//                        OverseaCommodity(name,price,num,discount,tariff));
//    }
//}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout<<"��ӭʹ�ù���������ϵͳ!\n";
    char choice;
    CommodityManage cm;
    cm.readData("d:\\commodity04.data");
    while(true){
        choice=menu();
        if(choice=='0')
            break;
        switch(choice){
        case '1':
            doAddCommodity(cm);
            break;
        case '2':
            doRemoveCommodity(cm);
            break;
        case '3':
            doViewCommodity(cm);
            break;
        case '4':
            doViewAllCommodity(cm);
            break;
        case '5':
            doCheckout(cm);
            break;
        default:
            cout<<"��Ч����! ������!\n";
            break;
        }
    }
    cout<<"�ټ�!\n";
    cm.saveData("d:\\commodity04.data");
    return a.exec();
}

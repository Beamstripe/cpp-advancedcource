#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;
char menu(){
    cout<<"  0)�˳�ϵͳ\n";
    cout<<"  1)�����������Ʒ\n";
    cout<<"  2)�ӹ������Ƴ���Ʒ\n";
    cout<<"  3)�鿴ָ����Ʒ\n";
    cout<<"  4)�鿴������Ʒ\n";
    cout<<"  5)����\n";
    cout<<"�����빦��ѡ�\n";
    char choice;
    cin>>choice;
    return choice;
}
void displayCommodities(CommodityInfo *pCommodities, int num){
    int i;
    cout<<"��Ʒ���ࣺ"<<num<<endl;
    for(i=0;i<num;i++){
        showCommodityInfo(&pCommodities[i]);
    }
    cout<<endl;
}
void addCommodity(CommodityInfo *pCommodities, int &num){
    int id;
    cout<<"  ������Ʒ���(id)��";
    cin>>id;
    CommodityInfo *pCommodity = findCommodityById(pCommodities,num,id);
    if(pCommodity!=nullptr){
        cout<<"���Ϊ"<<id<<"����Ʒ�Ѿ����ڣ�\n";
        cout<<"���������ӵ���Ʒ������";
        int number;
        cin>>number;
        pCommodity->num+=number;
        return;
    }
    if(num==MAX_COMMODITY_NUM){
        cout<<"û���㹻�ռ��ˣ�\n";
        return;
    }
    pCommodity = &pCommodities[num];
    pCommodity->id=id;
    setCommodityInfo(pCommodity);
    num++;
    cout<<"��Ʒ��ӳɹ���\n\n";
}
void removeCommodity(CommodityInfo *pCommodities, int &num){
    int id;
    cout<<"  ������Ʒ���(id)��";
    cin>>id;
    CommodityInfo *pCommodity = findCommodityById(pCommodities,num,id);
    if(pCommodity==nullptr){
        cout<<"���Ϊ"<<id<<"����Ʒ�����ڣ�\n";
        return;
    }
    num--;
    CommodityInfo *pNext = pCommodity+1;
    while (pCommodity < pCommodities + num) {
        pCommodity->id=pNext->id;
        pCommodity->name=pNext->name;
        pCommodity->price=pNext->price;
        pCommodity->discount=pNext->dicount;
        pCommodity++;
        pNext++;
    }
    showCommodityInfo(pCommodity);
    cout<<endl;
}
void checkOut(CommodityInfo *pCommodities, int num){
    double totalPrice=0;
    int totalNum=0;
    cout<<"��Ʒ���ࣺ"<<num<<endl;
    cout<<"  ��Ʒ����\t\t�۸�\t����\t�ۿ�\t�ܼ�\n";
    for(int i=0;i<num;i++){
        double price=getCommodityPrice(pCommodities+i);
        cout<<"  "<<pCommodities[i].name<<'\t'
            <<pCommodities[i].price<<'\t'
            <<pCommodities[i].num<<'\t'
            <<pCommodities[i].dicount<<'\t'
            <<price<<'\t';
        totalPrice+=price;
        totalNum+=pCommodities[i].num��
    }
    cout<<"��������Ʒ�ܼ�����"<<totalNum<<"\n";
    cout<<"�����������ܼۣ�"<<totalPrice<<endl;
}
void readData(std::string filename){
    ifstream in(filename);
    if(in){
        in>>commodityNum;
        if(commodityNum>MAX_COMMODITY_NUM)
            commodityNum=MAX_COMMODITY_NUM;
        string buf;
        for(int i=0;i<commodityNum;i++){
            in>>commodities[i].id;
            getline(cin,buf);
            getline(in,commodities[i].name);
            in>>commodities[i].price>>commodities[i].num
              >>commodities[i].dicount;
        }
    }
}
void writeData(std::string filename){
    ofstream out(filename);
    if(out){
        out<<commodityNum<<endl;
        for(int i=0;i<commodityNum;i++){
            out<<commodities[i].id<<endl;
            out<<commodities[i].name<<endl;
            out<<commodities[i].price<<' '<<commodities[i].num
               <<' '<<commodities[i].dicount<<endl;
        }
    }
}

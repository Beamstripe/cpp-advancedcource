#include <iostream>
#include <fstream>
#include "header.h"
char menu(){
    using std::cout;
    using std::cin;
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
void viewCommodity(CommodityInfo *pCommodities, int num){
    using std::cout;
    using std::endl;
    cout<<"  ��Ʒ����\t\t�۸�\t����\t�ۿ�\t�ܼ�\n";
    cout<<"  "<<pCommodities->name<<'\t'
        <<pCommodities->price<<'\t'
        <<pCommodities->num<<'\t'
        <<pCommodities->discount<<'\t'
        <<getCommodityPrice(pCommodities)<<'\t';
}

void displayCommodities(CommodityInfo *pCommodities, int num){
    using std::cout;
    using std::cin;
    using std::endl;
    int i;
    cout<<"��Ʒ���ࣺ"<<num<<endl;
    for(i=0;i<num;i++){
        showCommodityInfo(&pCommodities[i]);
    }
    cout<<endl;
}
void addCommodity(CommodityInfo* &pCommodities, int &num){
    using std::cout;
    using std::cin;
    long id;
    cout<<"  ������Ʒ���(id)��";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    if(pos!=-1){
        cout<<"���Ϊ"<<id<<"����Ʒ�Ѿ����ڣ�\n";
        cout<<"���������ӵ���Ʒ������";
        int number;
        cin>>number;
        pCommodities[pos].num+=number;
        return;
    }
    if(num==maxCommodityNum){
        reAllocMemory(pCommodities,num);
    }
    CommodityInfo* pCommodity = &pCommodities[num];
    pCommodity->id=id;
    setCommodityInfo(pCommodity);
    num++;
    cout<<"��Ʒ��ӳɹ���\n\n";
}
void removeCommodity(CommodityInfo *pCommodities, int &num){
    using std::cout;
    using std::cin;
    using std::endl;
    long id;
    cout<<"  ������Ʒ���(id)��";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    if(pos==-1){
        cout<<"���Ϊ"<<id<<"����Ʒ�����ڣ�\n";
        return;
    }
    num--;
    CommodityInfo* pCommodity = pCommodities+pos;
    CommodityInfo *pNext = pCommodity+1;
    while (pCommodity < pCommodities + num) {
        pCommodity->id=pNext->id;
        pCommodity->name=pNext->name;
        pCommodity->price=pNext->price;
        pCommodity->discount=pNext->discount;
        pCommodity++;
        pNext++;
    }
    showCommodityInfo(pCommodity);
    cout<<endl;
}
void checkOut(CommodityInfo *pCommodities, int num){
    using std::cout;
    using std::cin;
    using std::endl;
    double totalPrice=0;
    int totalNum=0;
    cout<<"��Ʒ���ࣺ"<<num<<endl;
    cout<<"  ��Ʒ����\t\t�۸�\t����\t�ۿ�\t�ܼ�\n";
    for(int i=0;i<num;i++){
        double price=getCommodityPrice(pCommodities+i);
        cout<<"  "<<pCommodities[i].name<<'\t'
            <<pCommodities[i].price<<'\t'
            <<pCommodities[i].num<<'\t'
            <<pCommodities[i].discount<<'\t'
            <<price<<'\t';
        totalPrice+=price;
        totalNum+=pCommodities[i].num;
    }
    cout<<"��������Ʒ�ܼ�����"<<totalNum<<"\n";
    cout<<"�����������ܼۣ�"<<totalPrice<<endl;
}
void readData(CommodityInfo *&pCommodities,char* filename){
    std::ifstream in(filename);
    if(in){
        in>>maxCommodityNum;
        pCommodities=new CommodityInfo[maxCommodityNum];
        in>>commodityNum;
        if(commodityNum>maxCommodityNum)
            commodityNum=maxCommodityNum;
        std::string buf;
        for(int i=0;i<commodityNum;i++){
            in>>pCommodities[i].id;
            std::getline(in,buf);
            std::getline(in,pCommodities[i].name);
            in>>pCommodities[i].price>>pCommodities[i].num
              >>pCommodities[i].discount;
        }
    }
}
void writeData(CommodityInfo *&pCommodities,char *filename){
    using std::endl;
    std::ofstream out(filename);
    if(out){
        out<<maxCommodityNum<<endl;
        out<<commodityNum<<endl;
        for(int i=0;i<commodityNum;i++){
            out<<pCommodities[i].id<<endl;
            out<<pCommodities[i].name<<endl;
            out<<pCommodities[i].price<<' '<<pCommodities[i].num
               <<' '<<pCommodities[i].discount<<endl;
        }
    }
}
void modifyCommodity(CommodityInfo *&pCommodities, int num){
    using std::cout;
    using std::cin;
    long id;
    cout<<"  ������Ʒ���:";
    cin>>id;
    int pos = findCommodityById(pCommodities,num,id);
    if(pos!=-1){
        CommodityInfo* commodity = pCommodities+pos;
        setCommodityInfo(commodity);
        cout<<"  ��Ʒ�޸ĳɹ���\n";
    }else{
        char option;
        cout<<"��Ҫ��Ӵ���Ʒ��(y/n)";
        cin>>option;
        if(option=='y'){
            addCommodity(pCommodities,num);
        }
    }
}

#include <iostream>
#include <algorithm>
#include "header.h"
void reAllocMemory(CommodityInfo *&pCommodities, int num){
    maxCommodityNum*=2;
    CommodityInfo *temp=pCommodities;
    pCommodities=new CommodityInfo[maxCommodityNum];
    for(int i=0;i<num;i++){
        pCommodities[i]=temp[i];
    }
    delete[] temp;
}

void setCommodityInfo(CommodityInfo *pCommodity){
    using std::cout;
    using std::cin;
    fflush(stdin);
    cout<<" ������Ʒ���ƣ�";
    getline(cin,pCommodity->name);
    cout<<" ������Ʒ�۸�";
    cin>>pCommodity->price;
    cout<<" ������Ʒ������";
    cin>>pCommodity->num;
    cout<<" ������Ʒ�ۿۣ�";
    cin>>pCommodity->discount;
}
/*
CommodityInfo* findCommodityById(CommodityInfo *pCommodities,int num,long id){
    CommodityInfo *pCommodity=pCommodities;
    for(;pCommodity < pCommodities+num;pCommodity++){
        if(pCommodity->id==id){
            return pCommodity;
        }
    }
    return nullptr;
}
*/
//Modification of findCommodityById
int findCommodityById(CommodityInfo *pCommodities,int num,long id){
    CommodityInfo *pCommodity=pCommodities;
    int pos=0;
    for(;pCommodity < pCommodities+num;pCommodity++){
        if(pCommodity->id==id){
            return pos;
        }
        pos++;
    }
    return -1;
}


double getCommodityPrice(CommodityInfo *pCommodity){
    return pCommodity->price*pCommodity->num*pCommodity->discount;
}

void showCommodityInfo(CommodityInfo *pCommodity){
    using std::cout;
    using std::cin;
    using std::endl;
    cout<<"��Ʒ���(id):"<<pCommodity->id<<endl;
    cout<<"   ��Ʒ����:"<<pCommodity->name<<endl;
    cout<<"   ��Ʒ�ܼ�:"<<getCommodityPrice(pCommodity)
        <<"���۸�:"<<pCommodity->price<<"������:"
        <<pCommodity->num<<"���ۿ�:"<<pCommodity->discount<<"��\n";
}
void sortCommodity(CommodityInfo *&pCommodities, int num){
    using std::cout;
    using std::cin;
    using std::endl;
    using std::sort;
    cout<<"����������ʽ��"<<endl;
    cout<<"  1)����Ʒ�������"<<endl;
    cout<<"  2)����Ʒ��������"<<endl;
    cout<<"  3)����Ʒ�۸�����"<<endl;
    cout<<"  4)����Ʒ�ۿ�����"<<endl;
    cout<<"  5)����Ʒ�ܼ�����"<<endl;
    char choice;
    cin>>choice;
    switch(choice){
    case '1':
        sort(pCommodities,pCommodities+num,cmpById);
    break;
    case '2':
        sort(pCommodities,pCommodities+num,cmpByName);
    break;
    case '3':
        sort(pCommodities,pCommodities+num,cmpByPrice);
    break;
    case '4':
        sort(pCommodities,pCommodities+num,cmpByDiscount);
    break;
    case '5':
        sort(pCommodities,pCommodities+num,cmpByTotalPrice);
    break;
    default:
        cout<<"�����ѡ��Ƿ���"<<endl;
        break;
    }
}
bool cmpById(CommodityInfo a, CommodityInfo b){
    return a.id<b.id;
}
bool cmpByName(CommodityInfo a, CommodityInfo b){
    return a.name<b.name;
}
bool cmpByPrice(CommodityInfo a, CommodityInfo b){
    return a.price<b.price;
}
bool cmpByDiscount(CommodityInfo a, CommodityInfo b){
    return a.discount<b.discount;
}
bool cmpByTotalPrice(CommodityInfo a, CommodityInfo b){
    return getCommodityPrice(&a)<getCommodityPrice(&b);
}

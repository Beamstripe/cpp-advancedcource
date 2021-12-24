#include "Commodity.h"
#include "commodityManage.h"
#include "NormalCommodity.h"
#include "OverseaCommodity.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
CommodityManage::~CommodityManage(){
    for(auto e:pCommodities)
        delete e;
}

const Commodity* CommodityManage::findCommodityById(int id)const{
    vector<Commodity*>::const_iterator it=find_if(pCommodities.begin(),
                                            pCommodities.end(), [=](Commodity* p){return p->getId()==id;});
    if(it!=pCommodities.end())
        return *it;
    return nullptr;
}
Commodity* CommodityManage::findCommodityById(int id){
    vector<Commodity*>::const_iterator it=find_if(pCommodities.begin(),
                                                  pCommodities.end(), [=](const Commodity* p){return p->getId()==id;});
    if(it!=pCommodities.end())
        return *it;
    return nullptr;
}
void CommodityManage::addCommodity(Commodity *p){
    Commodity* pCommodity=findCommodityById(p->getId());
    if(pCommodity!=nullptr){
        cout<<"���Ϊ"<<p->getId()<<"����Ʒ�Ѿ�����!�ۼ�������\n";
        pCommodity->setNum(pCommodity->getNum()+p->getNum());
        return;
    }
    pCommodities.push_back(p);
    sortCommodities(); //�����Ʒ����ݵ�ǰ������������
}
void CommodityManage::sortCommodities(){
    switch(sortType){
    case 0: //���� id ����
        sort(pCommodities.begin(),pCommodities.end(),
             [=](Commodity* p1,Commodity* p2){
            return p1->getId()<p2->getId();});
        break;
    case 1: //������������
        sort(pCommodities.begin(),pCommodities.end(),
             [=](Commodity* p1,Commodity* p2){
                if(p1->getName()!=p2->getName()){
                    return p1->getName()<p2->getName();
                }else return p1->getId()<p2->getId();
            });
        break;
    case 2: //���ݾ�������
        sort(pCommodities.begin(),pCommodities.end(),
             [=](Commodity* p1,Commodity* p2){
                if(p1->getNetPrice()!=p2->getNetPrice())
                    return p1->getNetPrice()<p2->getNetPrice();
                else return p1->getId()<p2->getId();
            });
        break;

    case 3://���ݹ�����������
        sort(pCommodities.begin(),pCommodities.end(),
             [=](Commodity* p1,Commodity* p2){
                if(p1->getNum()!=p2->getNum())
                    return p1->getNum()<p2->getNum();
                else return p1->getId()<p2->getId();
            });
        break;
    case 4://������Ʒ�۸�����
        sort(pCommodities.begin(),pCommodities.end(),
             [=](Commodity* p1,Commodity* p2){
                if(p1->getPrice()!=p2->getPrice())
                    return p1->getPrice()<p2->getPrice();
                else return p1->getId()<p2->getId();
            });
        break;
    }
}
void CommodityManage::sortCommoditiesByType(int type){
    if(type==sortType) //�Ѿ���ָ����������ֱ�ӷ���
        return;
    sortType=type;
    sortCommodities();
}
void CommodityManage::removeCommodity(int id){
    Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr){
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n";
        return;
    }
    delete pCommodity;
    pCommodities.erase(getIterator(pCommodity));
}
void CommodityManage::viewCommodity(int id)const{
    const Commodity* pCommodity=findCommodityById(id);
    if(pCommodity==nullptr){
        cout<<"���Ϊ"<<id<<"����Ʒ������!\n";
        return;
    }
    pCommodity->output();
}
void CommodityManage::viewAllCommodities()const{
    cout<<"��Ʒ����:"<< pCommodities.size()<<endl;
    if(pCommodities.size()==0)
        return;
    cout<<"ָ������ʽ(0-��Ʒ id,1-��Ʒ����,2-��Ʒ����,3-��Ʒ����,4-��Ʒ����):";
    int type;
    cin>>type;
    const_cast<CommodityManage*>(this)->sortCommoditiesByType(type);
    for(auto e:pCommodities)
        e->output();
}
void CommodityManage::checkOut()const{
    double totalPrice=0;
    int totalNum=0;
    cout<<"��Ʒ����: "<< pCommodities.size()<<endl;
    cout<<" ��Ʒ����\t\t"<<"�۸�\t"<<"����\t"<<"�ܼ�\n";
    for(auto e : pCommodities){
        double price=e->getNetPrice();
        cout<<" "<<e->getName()<<"\t";
        cout<<e->getPrice()<<"\t"
           <<e->getNum()<<"\t"
          <<price<<endl;
        totalPrice+=price;
        totalNum+=e->getNum();
    }
    cout<<"��������Ʒ�ܼ���: "<<totalNum<<"\n";
    cout<<"�����������ܼ�: "<<totalPrice<<endl;
}
vector<Commodity*>::iterator CommodityManage::getIterator(Commodity* p){
    for(auto it=pCommodities.begin();it!=pCommodities.end();++it)
        if(*it==p)
            return it;
    return pCommodities.end();
}
void CommodityManage::saveData(string filename){
    ofstream out(filename);
    if(out){
        out<< pCommodities.size()<<endl;
        out<<Commodity::getNextId()<<endl;
        for(auto e : pCommodities){
            out<<e->getInfo();
        }
    }
}
void CommodityManage::readData(string filename){
    ifstream in(filename);
    if(in){
        int fileMax,fileSize;
        long nextId;
        in>>fileMax>>fileSize>>nextId;
        Commodity::setNextId(nextId);
        int type;
        long id;
        string name,buf;
        double price,discount;
        double tariff;
        int num;
        for(int i=0;i<fileSize;++i){
            in>>type;
            in>>id;
            getline(in,buf);
            getline(in,name);
            in>>price>>num;
            if(type==0){
                in>>discount;
                addCommodity(new
                             NormalCommodity(id,name,price,num,discount));
            }
            else if(type==1){
                in>>discount>>tariff;
                addCommodity(new
                             OverseaCommodity(id,name,price,num,discount,tariff));
            }
        }
    }
    sortCommodities();
}

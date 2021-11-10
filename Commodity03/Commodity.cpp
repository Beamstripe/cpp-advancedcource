#include <iostream>
#include <string>
#include "header.h"
using namespace std;
Commodity::Commodity(long i,std::string n,double p,int nu,double d)
    :id(i),name(n),price(p),num(nu),discount(d) {}
double Commodity::getNetPrice()const {
    return price*num*discount;
}
void Commodity::output()const {
    cout<<" ��Ʒ���(id):"<<id<<endl;
    cout<<" ��Ʒ����:"<<name<<endl;
    cout<<" ��Ʒ�ܼ�:"<<getNetPrice()
        <<" (�۸�:"<<price<<", ����:"<<num<<", �ۿ�:"
        <<discount<<" )\n";
}
long Commodity::nextId=100;
Commodity::Commodity(string n, double p, int nu, double d):name(n),price(p),num(nu),discount(d){
    id=autoNextId();
}

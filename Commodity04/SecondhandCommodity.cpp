#include <iostream>
#include <sstream>
#include "SecondhandCommodity.h"
using namespace std;
int SecondhandCommodity::getType()const{
    return 2; //2 ��ʾ������Ʒ
}
string SecondhandCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<discount<<" "<<newnessRate<<endl; //���������Ϣ
    return ostr.str();
}
SecondhandCommodity::SecondhandCommodity(long id,std::string name,
                                   double p,int n,double d,double nr)
    :Commodity(id,name,p,n),discount(d),newnessRate(nr){}
SecondhandCommodity::SecondhandCommodity(std::string name,double p,
                                   int n,double d,double nr)
    :Commodity(name,p,n),discount(d),newnessRate(nr){}
double SecondhandCommodity::getNetPrice()const{
    return Commodity::getNetPrice()*discount*newnessRate;
}
void SecondhandCommodity::output()const{
    Commodity::output();
    cout<<" ��Ʒ�ܼ�:"<<getNetPrice()<<" (�۸�:"
       <<getPrice()<<", ����:"<<getNum()<<", �ۿ�:"
      <<discount<<", ������:"<<newnessRate<<" )\n";
}
void SecondhandCommodity::modify(){
    string newName;
    int newNum;
    double newPrice,newDiscount,newNewnessRate;
    cout<<"��������޸���Ʒ�����ƣ�";
    fflush(stdin);
    getline(cin,newName);
    cout<<"��������޸���Ʒ�ļ۸��������ۿ�������ʣ�";
    cin>>newPrice>>newNum>>newDiscount>>newNewnessRate;
    setName(newName);
    setPrice(newPrice);
    setNum(newNum);
    this->discount=newDiscount;
    this->newnessRate=newNewnessRate;
}

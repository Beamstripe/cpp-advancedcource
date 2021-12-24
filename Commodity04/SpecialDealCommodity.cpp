#include <iostream>
#include "SpecialDealCommodity.h"

using namespace std;
int SpecialDealCommodity::getType()const{
    return 3; //3 ��ʾ�ؼ���Ʒ
}
string SpecialDealCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<promotionPrice<<endl; //���������Ϣ
    return ostr.str();
}
SpecialDealCommodity::SpecialDealCommodity(long id,std::string name,
                                   double p,int n,double pp)
    :Commodity(id,name,p,n),promotionPrice(pp){}
SpecialDealCommodity::SpecialDealCommodity(std::string name,double p,
                                   int n,double pp)
    :Commodity(name,p,n),promotionPrice(pp){}
double SpecialDealCommodity::getNetPrice()const{
    return promotionPrice*getNum();
}
void SpecialDealCommodity::output()const{
    Commodity::output();
    cout<<" ��Ʒ�ܼ�:"<<getNetPrice()<<" (ԭ��:"
       <<getPrice()<<", �ּ�:"<<promotionPrice<<", ����:"<<getNum()<<" )\n";
}
void SpecialDealCommodity::modify(){
    string newName;
    int newNum;
    double newPrice,newPromotionPrice;
    cout<<"��������޸���Ʒ�����ƣ�";
    fflush(stdin);
    getline(cin,newName);
    cout<<"��������޸���Ʒ��ԭ�ۣ��������ۿۼۣ�";
    cin>>newPrice>>newNum>>newPromotionPrice;
    setName(newName);
    setPrice(newPrice);
    setNum(newNum);
    this->promotionPrice=newPromotionPrice;
}

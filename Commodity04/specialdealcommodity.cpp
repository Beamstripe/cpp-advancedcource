#include "specialdealcommodity.h"
#include "header.h"
using namespace std;
int SpecialDealCommodity::getType()const{
    return 3; //3 ��ʾ�ؼ���Ʒ
}
std::string SpecialDealCommodity::getInfo()const{
    ostringstream ostr;
    ostr<<getType()<<" "; //��������ͱ���
    ostr<<Commodity::getInfo(); //����������Ϣ
    ostr<<discountedPrice<<endl; //���������Ϣ
    return ostr.str();
}
SpecialDealCommodity::SpecialDealCommodity(long id,std::string name,
                                   double p,int n,double d)
    :Commodity(id,name,p,n),discountedPrice(d){}
SpecialDealCommodity::SpecialDealCommodity(std::string name,double p,
                                   int n,double d)
    :Commodity(name,p,n),discountedPrice(d){}
double SpecialDealCommodity::getNetPrice()const{
    return getNum()*discountedPrice;
}
double SpecialDealCommodity::getPrice()const{
    return discountedPrice;
}

void SpecialDealCommodity::output()const{
    Commodity::output();
    cout<<" ��Ʒԭ��:"<<price<<"���ּ�:"
       <<discountedPrice<<", ����:"<<getNum()<<"����Ʒ�ܼ�:"
      <<getNetPrice()<<" \n";
}

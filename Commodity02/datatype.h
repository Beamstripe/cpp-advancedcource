#ifndef DATATYPE_H
#define DATATYPE_H
#include <string>
struct CommodityInfo{
    long id;    //��Ʒ���
    std::string name;   //��Ʒ���ƣ�ͷ�ļ��б���ʹ��using namespace std
    double price;   //����
    int num;    //����
    double dicount; //�ۿ�
};
const int MAX_COMMODITY_NUM=100;
#endif // DATATYPE_H

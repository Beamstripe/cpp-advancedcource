#ifndef COMMODITYMANAGE_H
#define COMMODITYMANAGE_H
#include "Commodity.h"
class CommodityManage{
public:
    CommodityManage();
    CommodityManage(int s);
    ~CommodityManage();
    CommodityManage(const CommodityManage& c)=delete;
    CommodityManage& operator=(const CommodityManage& c)=delete;
    void readData(char* filename);
    void saveData(char* filename);
    void reAllocMemory();
    void addCommodity(Commodity* p);
    void removeCommodity(long id);
    void viewCommodity(long id)const;
    void viewAllCommodities()const;
    void checkOut()const;
    void modifyCommodity(long id);
private:
    Commodity **pCommodities; //ָ��̬��������Ʒ����
    int maxSize; //��ǰ����Ŀռ�����
    int size; //ʵ�ʵ���Ʒ����
    Commodity* findCommodityById(long id)const;
};
#endif // COMMODITYMANAGE_H

#include "highspeedtrain.h"
#include "function.h"

using namespace std;
HighspeedTrain::HighspeedTrain(Time_t dt, int d, string num, string dept, string dest, bool smart, bool silent){
    setDepartureTime(dt);
    setDuration(d);
    setTrainNum(num);
    setDeparture(dept);
    setDestination(dest);
    setIfSilientCarriage(silent);
    setIfSmartCarriage(smart);
}
string HighspeedTrain::getTrainType()const{
    return "�����г�";
}
void HighspeedTrain::output()const{
    if(ifSilientCarriage)cout<<"�������� ";
    if(ifSmartCarriage)cout<<"���ܳ��� ";
    cout<<endl;
    cout<<"��ֹ�أ�"<<getDeparture()<<"---"<<getDestination()<<endl;
    cout<<"����ʱ�䣺"<<outputTime(getDepartureTime())<<endl;
    cout<<"�г�ʱ����"<<outputTime(getDuration())<<endl;
//    cout<<"����ʱ�䣺"<<outputTime(getArrivalTime())<<endl;
}

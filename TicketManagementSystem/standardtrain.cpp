#include "standardtrain.h"
#include "function.h"

StandardTrain::StandardTrain(Time_t dt, int d, string num, string dept, string dest){
    setDepartureTime(dt);
    setDuration(d);
    setTrainNum(num);
    setDeparture(dept);
    setDestination(dest);
}

void StandardTrain::output()const{
    cout<<"��ֹ�أ�"<<getDeparture()<<"---"<<getDestination()<<endl;
    cout<<"����ʱ�䣺"<<outputTime(getDepartureTime())<<endl;
    cout<<"�г�ʱ����"<<outputTime(getDuration())<<endl;
//    cout<<"����ʱ�䣺"<<outputTime(getArrivalTime())<<endl;
}
string StandardTrain::getTrainType()const{
    return "�����г�";
}

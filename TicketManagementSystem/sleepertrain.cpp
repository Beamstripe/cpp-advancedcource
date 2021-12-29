#include "sleepertrain.h"
#include "function.h"
SleeperTrain::SleeperTrain(Time_t dt, int d, string num, string dept, string dest, string pos){
    setDepartureTime(dt);
    setDuration(d);
    setTrainNum(num);
    setDeparture(dept);
    setDestination(dest);
    setSleeperPosition(pos);
}

void SleeperTrain::output()const{
    cout<<"���Σ�"<<getTrainNum()<<endl;
    cout<<"��ֹ�أ�"<<getDeparture()<<"---"<<getDestination()<<endl;
    cout<<"����ʱ�䣺"<<outputTime(getDepartureTime())<<endl;
    cout<<"�г�ʱ����"<<outputTime(getDuration())<<endl;
//    cout<<"����ʱ�䣺"<<outputTime(getArrivalTime())<<endl;
}
string SleeperTrain::getTrainType()const{
    return "�����г�";
}

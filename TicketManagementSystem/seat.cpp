#include "seat.h"
#include <iostream>
void Seat::output()const{
    cout<<"��λ���ͣ�"<<category<<endl;
    if(!ifNoSeat){
        cout<<"����ţ�"<<carriageNum<<endl;
        if(category=="Ӳ��"||category=="����")
            cout<<"��λ�ţ�";
        else cout<<"��λ�ţ�";
        cout<<position<<endl;
    }
}

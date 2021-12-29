#include "function.h"
#include <sstream>
Time_t getTime(int year, int month, int day, int hour, int minute){
    return Time_t(year,month,day,hour,minute);
}
string outputTime(Time_t t){
    stringstream ss;
    ss<<t.year<<'-'<<t.month<<'-'<<t.day<<' '<<t.hr<<':'<<t.min;
    return ss.str();
}

char modifyMenu(Ticket* p){
    string s;
    int dpy,dpmon,dpd,dph,dpmin,durh,durm;
    double price;
    Time_t t;
    puts("�����������޸ĵ�ѡ�");
    puts("1-����");
    puts("2-����ʱ��");
    puts("3-Ʊ��");
    puts("4-�г�ʱ��");
    char c;
    cin>>c;
    switch(c){
    case '1':
        cout<<"���복�Σ�";
        fflush(stdin);
        getline(cin,s);
        p->setTrainNum(s);
        break;
    case '2':
        cout<<"�������ʱ��(�꣬�£��գ�Сʱ(24ʱ��)������)��";
        cin>>dpy>>dpmon>>dpd>>dph>>dpmin;
        t=getTime(dpy,dpmon,dpd,dph,dpmin);
        p->setDepartureTime(t);
        break;
    case '3':
        cout<<"����Ʊ�ۣ�";
        cin>>price;
        p->setPrice(price);
        break;
    case '4':
        cout<<"�����г�ʱ�䣺(Сʱ:����)";
        scanf("%d:%d",&durh,&durm);
        p->setDepartureTime(durh*60+durm);
        break;
    }
}
string outputTime(int t){
    stringstream ss;
    ss<<(t/60)<<":"<<(t%60);
    return ss.str();
}
char menu(){
    cout<<"--------------��ӭʹ�ó�Ʊ����ϵͳ---------------"<<endl;
    cout<<"��ѡ�������"<<endl;
    cout<<"  0-�˳�ϵͳ"<<endl;
    cout<<"  1-��ӳ�Ʊ"<<endl;
    cout<<"  2-ɾ����Ʊ"<<endl;
    cout<<"  3-�޸ĳ�Ʊ��Ϣ"<<endl;
    cout<<"  4-���ҳ�Ʊ"<<endl;
    cout<<"  5-�鿴���г�Ʊ"<<endl;
    cout<<"  6-���㳵Ʊ�ܼ�"<<endl;
    char c;
    cin>>c;
    return c;
}

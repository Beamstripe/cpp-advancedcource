#include "ticketmanage.h"
#include "function.h"
#include <cstdio>
TicketManage::~TicketManage(){
    for(auto e:pTickets)
        delete e;
}

Ticket* TicketManage::findTicketById(long id){
    for(auto e:pTickets){
        if(e->getId()==id)return e;
    }
    return nullptr;
}
const Ticket* TicketManage::findTicketById(long id) const{
    for(auto e:pTickets){
        if(e->getId()==id)return e;
    }
    return nullptr;
}
Ticket* TicketManage::findTicketByName(string name){
    for(auto e:pTickets){
        if(e->getName()==name)return e;
    }
    return nullptr;
}
const Ticket* TicketManage::findTicketByName(string name)const{
    for(auto e:pTickets){
        if(e->getName()==name)return e;
    }
    return nullptr;
}
void TicketManage::addTicket(){
    string name,departure,destination,trainNum,position="D.C.";
    int type;
    double price;
    int dpy,dpmon,dpd,dph,dpmin,durh,durm,carriageNum;
    Ticket* p;
    char ifSmart,ifSilent;
    {
        cout<<"ѡ���г�����(1-�����г���2-�����г���3-�����г�)��";
        cin>>type;
        cout<<"����˳���������";
        fflush(stdin);
        getline(cin,name);
        cout<<"�������վ��";
        getline(cin,departure);
        cout<<"���뵽��վ��";
        getline(cin,destination);
        cout<<"���복�Σ�";
        getline(cin,trainNum);
        cout<<"���복Ʊ���ã�";
        cin>>price;
        cout<<"�������ʱ��(�꣬�£��գ�Сʱ(24ʱ��)������)��";
        cin>>dpy>>dpmon>>dpd>>dph>>dpmin;
        cout<<"�����г�ʱ�䣺(Сʱ:����)";
        scanf("%d:%d",&durh,&durm);
        cout<<"���복��ţ�";
        cin>>carriageNum;
    }
    type=trainCategory(type);
    switch(type){
    case STANDARD_TRAIN:{
        int category;
        cout<<"������λ���ͣ�(0-������1-Ӳ��)";
        cin>>category;
        category=normalSeatCategory(category);
        if(category!=NO_SEAT){
            cout<<"������λ��";
            cin>>position;
        }
        string str_category;
        switch(category){
        case NO_SEAT:
            str_category="����";
            break;
        case HARD_SEAT:
            str_category="Ӳ��";
            break;
        }

        Time_t tDeparture=getTime(dpy,dpmon,dpd,dph,dpmin);
        int dur=durh*60+durm;
        p=new Ticket(new StandardTrain(tDeparture,dur,trainNum,departure,destination)
                             ,name
                             ,price,new Seat(carriageNum,position,str_category,category==NO_SEAT));

        //        sortTickets();
        break;
    }
    case SLEEPER_TRAIN:{
        int category;
        int slprpos;
        cout<<"������λ���ͣ�(0-������1-Ӳ����2-Ӳ�ԣ�3-����)";
        cin>>category;
        category=normalSeatCategory(category);
        if(category!=NO_SEAT){
            if(category==HARD_SEAT){
                cout<<"������λ��";
                cin>>position;
            }else if(category==HARD_SLEEPER){
                cout<<"������λ��";
                cin>>position;
                cout<<"������λ(1-���̣�2-���̣�3-����)";
                cin>>slprpos;
                slprpos=sleeperPositionCategory(slprpos);
            }else if(category==SOFT_SLEEPER){
                cout<<"������λ��";
                cin>>position;
                cout<<"������λ(1-���̣�2-����)";
                cin>>slprpos;
                slprpos=sleeperPositionCategory(slprpos);
            }
        }
        Time_t tDeparture=getTime(dpy,dpmon,dpd,dph,dpmin);
        int dur=durh*60+durm;
        string str_category,str_sleeperPosition;

        switch(category){
        case NO_SEAT:
            str_category="����";
            break;
        case HARD_SEAT:
            str_category="Ӳ��";
            break;
        case HARD_SLEEPER:
            str_category="Ӳ��";
            switch(slprpos){
            case LOWER_BERTH:
                str_sleeperPosition="����";
                break;
            case MIDDLE_BERTH:
                str_sleeperPosition="����";
                break;
            case UPPER_BERTH:
                str_sleeperPosition="����";
                break;
            }
            break;
        case SOFT_SLEEPER:
            str_category="����";
            switch(slprpos){
            case LOWER_BERTH:
                str_sleeperPosition="����";
                break;
            case UPPER_BERTH:
                str_sleeperPosition="����";
                break;
            }
            break;
        }
        p=new Ticket(new SleeperTrain(tDeparture,dur,trainNum,departure,destination,str_sleeperPosition)
                             ,name
                             ,price,new Seat(carriageNum,position,str_category,category==NO_SEAT));
        break;
    }
    case HIGHSPEED_TRAIN:{
        int category;
        cout<<"������λ���ͣ�(0-������1-��������2-һ������3-������)";
        cin>>category;
        category=expressSeatCategory(category);
        if(category!=NO_SEATS){
            cout<<"������λ��";
            cin>>position;
        }
        cout<<"�Ƿ�Ϊ�������᣿(y/n):";
        cin>>ifSilent;
        cout<<"�Ƿ�Ϊ�����г���(y/n):";
        cin>>ifSmart;
        string str_category;
        switch(category){
        case NO_SEATS:
            str_category="����";
            break;
        case SECONDARY_CLASS:
            str_category="������";
            break;
        case FIRST_CLASS:
            str_category="һ����";
            break;
        case BUSINESS_CLASS:
            str_category="������";
            break;
        }
        Time_t tDeparture=getTime(dpy,dpmon,dpd,dph,dpmin);
        int dur=durh*60+durm;
        p=new Ticket(new HighspeedTrain(tDeparture,dur,trainNum,departure,destination,ifSmart=='y',ifSilent=='y')
                             ,name
                             ,price,new Seat(carriageNum,position,str_category,category==NO_SEATS));
        break;
    }
    }
    if(findTicketById(p->getId())!=nullptr){
        cout<<"����ӵĳ�Ʊ�Ѵ���";
        delete p;
        return;
    }
    pTickets.push_back(p);
}
void TicketManage::removeTicket(){
    long id;
    cout<<"����������ɾ����Ʊ�ı�ţ�";
    cin>>id;
    Ticket* p=findTicketById(id);
    if(p==nullptr){
        cout<<"����ɾ���ĳ�Ʊ������";
        return;
    }
    pTickets.erase(getIterator(p));
}
void TicketManage::viewTicket(){
    long id;
    cout<<"����������鿴��Ʊ�ı�ţ�";
    cin>>id;
    Ticket* p=findTicketById(id);
    if(p==nullptr){
        cout<<"����鿴�ĳ�Ʊ������"<<endl;
        return;
    }
    p->output();
}
void TicketManage::viewAllTickets(){
    cout<<"��Ʊ������"<<pTickets.size()<<endl;
    for(auto e:pTickets){
        cout<<"-------------------------------------"<<endl;
        e->output();
    }
}
void TicketManage::modifyTicket(){
    long id;
    cout<<"�����������޸ĳ�Ʊ�ı�ţ�";
    cin>>id;
    Ticket* p=findTicketById(p->getId());
    if(p==nullptr){
        cout<<"�����޸ĵĳ�Ʊ������"<<endl;
        return;
    }
    modifyMenu(p);
}
vector<Ticket*>::iterator TicketManage::getIterator(Ticket *p){
    for(auto it=pTickets.begin();it!=pTickets.end();it++)
        if((*it)==p)
            return it;
    return pTickets.end();
}
void TicketManage::printCosts(){
    double s=0;
    for(auto e:pTickets){
        s+=e->getPrice();
    }
    cout<<"�ܷ��ã�"<<s<<"Ԫ"<<endl;
}

#include "function.h"
using namespace std;
long Ticket::nextId=100000001;
int main()
{
    TicketManage tm;
    while(true){
        char c=menu();
        switch (c) {
        case '0':
            cout<<"�ټ���"<<endl;
            return 0;
        case '1':
            tm.addTicket();
            break;
        case '2':
            tm.removeTicket();
            break;
        case '3':
            tm.modifyTicket();
            break;
        case '4':
            tm.viewTicket();
            break;
        case '5':
            tm.viewAllTickets();
            break;
        case '6':
            tm.printCosts();
            break;
        default:
            cout<<"������Ĳ�������!����������";
        }
    }
    return 0;
}


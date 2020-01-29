#include <iostream>
#include "functions.h"
using namespace std;

int main()
{
ip=100;
   while(ip!=00)
    {
    cout<<"Press 1 for login"<<endl;
    cout<<"Press 2 for new registration"<<endl;

    cout<<"Press 0 to exit "<<endl;

    cin>>ip;

    if(ip==1)
        openLogin(0);
    else if(ip==2)
        newregistration();
    else if(ip==0)
    {
        cout<<"!!PROGRAM TERMINATED"<<endl;
    }
    else
        {
        cout<<"Invalid Option Entered"<<endl;
        home();
        }
    }

}


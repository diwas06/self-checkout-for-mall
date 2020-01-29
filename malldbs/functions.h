#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<time.h>

using namespace std;



void home();
void newregistration();
void billing();

void openLogin(int);

short int ip,login=0;


class user
{
public:
    char name[30];
    char loginId[30];
    char password[20];
    char phoneNo[10];



     void creatId()                 //createId() is a function to check for possible duplicate Id's
    {
    int f=0;

    void home();
    cout<<"Enter Email Id"<<endl;
    cin>>loginId;

    user ob;
    ifstream readId;
    readId.open("userData.txt");

    while(readId)
    {
        readId.read((char*)&ob,sizeof(ob));
        if(strcmp(ob.loginId,loginId)==0)
           {
            f=1;
            break;
           }
    }
    if(f==1)
    {
        cout<<"!!Account already exit!!"<<endl<<endl;
        home();

    }
    }


    void display()              //display() function to display profile of the user
    {
        cout<<"NAME-"<<name<<endl;
        cout<<"LOGIN ID-"<<loginId<<endl;
        cout<<"PHONE NO.-"<<phoneNo<<endl;


        cout<<endl<<endl;
    }

};
user ob;

void showHistory(user);
void settings(user);
void change_password(user);
void change_phone_no(user);

class product               //"product" is a class, containing data of product
{
  public:
    int pcode;
    char pname[20];
    int pcost;

    void pdisplay()         //pdisplay() is function to display info about product
    {
        cout<<pcode<<setw(20)<<pname<<setw(7)<<setw(10)<<pcost<<endl;
    }
};
product billob;

class historyClass          //"historyClass" is a class whose object is being used to store data in history.txt file
{
public:
    char loginId[30];
    int pcode;
    int total;
    int transactionId=0;
    char date[40];
    int discount=0;


    void displayHistory()       //displayHistory() is a function to display stored history
    {

        ifstream readProduct;
        readProduct.open("products.txt");

        while(readProduct)
        {
            readProduct.read((char*)&billob,sizeof(billob));
            if(pcode==billob.pcode)
            {
                billob.pdisplay();
                break;
            }
        }
    }
};
historyClass historyob;

int checkout(float sum)         // checkout() is a function which will return 1 on successful submission of all the card details
{
    int cvv;
    char cardNumber[16],c,op;
    int mm,yy;




    cout<<"Enter DEBIT CARD no."<<endl;
    cin>>cardNumber;
    cout<<"Enter EXPIRY DATE (mm/yy)"<<endl;
    cin>>mm>>c>>yy;
    cout<<"Enter CVV no."<<endl;
    cin>>cvv;

    cout<<"Press y to ontinue and n to cancel"<<endl;
    cin>>op;



if(op=='y'||op=='Y')
    {cout<<"!!Checkout Completed"<<endl;
    return 1;
    }
else if(op=='n'||op=='N')
{
    cout<<"!!Checkout Interrupted!!"<<endl;
    return 0;
}
else
    {
    cout<<"!!Invalid Entry Please Try Again!!"<<endl;
    checkout(sum);
    }
}

void home()         //home() is welcome page of the program
{
    while(ip!=00)
    {
    cout<<"Press 1 for LOGIN"<<endl;
    cout<<"Press 2 for NEW REGISTRATION"<<endl;

    cout<<"Press 00 to EXIT "<<endl;

    cin>>ip;

    if(ip==1)
        openLogin(0);
    else if(ip==2)
        newregistration();
    else
        cout<<"Invalid Option Entered"<<endl;
    }
}

void newregistration()      //newregistration() is the function to register new users in the database
{
user userId;
cout<<"enter name"<<endl;
cin>>userId.name;
//cout<<"enter email"<<endl;
userId.creatId();

cout<<"enter phone no"<<endl;
{cin>>userId.phoneNo;}

cout<<"enter password"<<endl;
{
     int i=0;
   char ch=getch();
    while(ch!=13)
    {
        if(ch==8)
        {
            if(i>0)
            {
            i--;
            cout<<"\b \b";

            }
        }
        else
        {
        userId.password[i++]=ch;
        cout<<'*';

        }
ch=getch();
    }
    userId.password[i]='\0';
}



ofstream newUser;

newUser.open("userData.txt",ios::app);

newUser.write((char*)&userId,sizeof(userId));

newUser.close();
cout<<"****registration succesful*****"<<endl<<endl;

}

void openLogin(int x=0)         //openLogin(int x), is a funtion in which by default x=0, ie. logged out condition
{                               //and 1 is passed into x, ie logged in condition, if the user enters correct userid
    login=x;                    //and password in login paage.


    if(login==0)
    {

    char id[30],pass[20],ch;

    cout<<"enter email id"<<endl;
    cin>>id;
    cout<<"enter password"<<endl;
{
     int i=0;
   char ch=getch();
    while(ch!=13)
    {
        if(ch==8)
        {
            if(i>0)
            {
            i--;
            cout<<"\b \b";

            }
        }
        else
        {
        pass[i++]=ch;
        cout<<'*';

        }
ch=getch();
    }
    pass[i]='\0';
}

    cout<<endl<<endl<<endl;
    ifstream checkUser;
    checkUser.open("userData.txt",ios::in);

    while(checkUser)
    {
        checkUser.read((char*)&ob,sizeof(ob));
        if(strcmp(ob.loginId,id)==0)
        {
            if(strcmp(ob.password,pass)==0)
               {

                login=1;
               break;
               }
        }
    }
  }
if(login==1)
   {
char temp_pass[20];                 //temp_pass will be used for double verifying user, if setting option is opted
        cout<<"looged in"<<endl<<endl<<endl;

        cout<<"welcome "<<ob.name<<"!!"<<endl;


        cout<<"Press 1 for billing"<<endl;
        cout<<"Press 2 for payment history"<<endl<<endl<<endl;
        cout<<"Press 3 for settings"<<endl;
        cout<<"Press 4 to view profile"<<endl;
        cout<<"Press 5 to logout"<<endl;
        cin>>ip;


         if(ip==1)
        {
            billing();
        }
        else if(ip==2)
        {
            showHistory(ob);
        }
        else if(ip==3)
        {
            cout<<"Enter password for verification"<<endl;
            {
            int i=0;
            char ch=getch();
            while(ch!=13)
            {
                if(ch==8)
                {
                    if(i>0)
                    {
                    i--;
                    cout<<"\b \b";

                    }
                }
                else
                {
                    temp_pass[i++]=ch;
                    cout<<'*';

                }
            ch=getch();
            }
                temp_pass[i]='\0';
            }
            cout<<endl;

            if(strcmp(temp_pass,ob.password)==0)
            settings(ob);
            else{cout<<"!!Incorrect Password!!"<<endl;
                openLogin(1);
                }
        }
        else if(ip==4)
        {
            ob.display();
            openLogin(1);
        }
        else if(ip==5)
        {
            cout<<"LOGED OUT"<<endl;
            login=0;

        }
        else
            cout<<"Invalid Input"<<endl;

   }
else


   cout<<"record not found"<<endl;
}

void billing()              //billing(), is function to start billing procedure
{
    int code,check_checkout,dis_flag=0;
    float sum=0.0;
    char discount_code[10];
    int discount=0;



    ifstream in;
    in.open("history.txt");

    in.seekg(-sizeof(historyob),ios::end);
    in.read((char*)&historyob,sizeof(historyob));
    int temp_transactionId=historyob.transactionId+1;

    in.close();

    strcpy(historyob.loginId,ob.loginId);



    cout<<"enter code 000 for no further enteries"<<endl<<endl<<endl;

    ifstream productSearch;
    ofstream history;
history.open("tempfile.txt");

        cout<<"enter product code"<<endl<<endl<<endl;
        cout<<setw(10)<<"Pcode     "<<setw(15)<<"P name     "<<setw(10)<<"P cost"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;

    while(1)
    {
        cin>>code;

        if(code==0&&sum!=0)
        {
            cout<<"!!Billing Complete!!"<<endl;
            cout<<"!!Net Amount!!"<<"       "<<sum<<endl<<endl;
            cout<<"*Discount coupon available on purchase of 200+*"<<endl;
            cout<<endl<<endl<<"Enter discount code if any else enter no"<<endl;
            cin>>discount_code;

            if(strcmp(discount_code,"LUCKY")==0&&(sum>200))
            {
                cout<<"Discount coupon appplied"<<endl;
                dis_flag=1;
                discount=50;
                sum=sum-discount;
            }
            else
            {   cout<<"!!Coupon not applied!!"<<endl;


            }

                check_checkout=checkout(sum);
                break;

        }
        if(code==0&&sum==0)
        {
            cout<<"!!!No Product Was Purchased"<<endl;
            break;

        }

         productSearch.open("products.txt",ios::in);


         historyob.transactionId=temp_transactionId;

        while(productSearch)
        {

            productSearch.read((char*)&billob,sizeof(billob));

            if(billob.pcode==code)
            {
            billob.pdisplay();

            sum+=billob.pcost;
            historyob.total=sum;
            historyob.pcode=billob.pcode;

            history.write((char*)&historyob,sizeof(historyob));

            productSearch.close();
            break;

            }

        }
        productSearch.close();


    }
    history.close();


    if(check_checkout==1)           //if checkout func. returned 1 means transaction successful
    {
        ifstream history_from;
        ofstream history_to;

        history_from.open("tempfile.txt");
        history_to.open("history.txt",ios::app);


        time_t tt;
        struct tm *ti;
        time(&tt);

        ti=localtime(&tt);


        while(history_from)
        {
            history_from.read((char*)&historyob,sizeof(historyob));
            strcpy(historyob.date,asctime(ti));
            if(dis_flag==1)
            {
                historyob.discount=discount;

            }
            else
                historyob.discount=0;

            if(!history_from.eof())
            history_to.write((char*)&historyob,sizeof(historyob));
        }

        history_from.close();
        history_to.close();
        discount=0;

    }




        openLogin(1);
}

void showHistory(user ob)       //showHistory() function to display transactioni history of the user
{
int prev_transid;

char prev_id[30];

    cout<<setw(10)<<"Pcode     "<<setw(15)<<"P name     "<<setw(10)<<"P cost"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    ifstream readHistory;

int tempsum,temp_dis=0;
char prev_date[50];
    readHistory.open("history.txt",ios::in);

    while(readHistory)
    {

    readHistory.read((char*)&historyob,sizeof(historyob));
        if(strcmp(historyob.loginId,ob.loginId)==0)
        {
            strcpy(prev_id,historyob.loginId);
            prev_transid=historyob.transactionId;
            break;
        }
    }

    readHistory.seekg(0);

    while(readHistory)
    {


        readHistory.read((char*)&historyob,sizeof(historyob));




if((prev_transid!=historyob.transactionId&&strcmp(prev_id,ob.loginId)==0)&&tempsum>0)
    {
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"TOTAL AMOUNT="<<tempsum<<endl;
    cout<<"DISCOUNT="<<-(temp_dis)<<endl;
    cout<<"NET PAID AMOUNT="<<tempsum-temp_dis<<endl;
    cout<<"TRANSACTION DATE= "<<prev_date<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"---------------------------------------------------"<<endl<<endl<<endl;
    }
        if(strcmp(historyob.loginId,ob.loginId)==0)
        {

            if(!readHistory.eof())
            historyob.displayHistory();
            tempsum=historyob.total;
            temp_dis=historyob.discount;
            strcpy(prev_date,historyob.date);

        }

prev_transid=historyob.transactionId;
strcpy(prev_id,historyob.loginId);


    }

    if(strcmp(prev_id,ob.loginId)==0)
    {
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"TOTAL AMOUNT=     "<<setw(6)<<tempsum<<endl;
    cout<<"DISCOUNT=         "<<setw(6)<<-(temp_dis)<<endl;
    cout<<"NET PAID AMOUNT=  "<<setw(6)<<tempsum-temp_dis<<endl;
    cout<<"TRANSACTION DATE= "<<prev_date<<endl<<endl;}
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"---------------------------------------------------"<<endl<<endl<<endl;
    readHistory.close();


    cout<<endl<<endl<<endl;

openLogin(1);
}

void settings(user ob)          //settings(), function to change password of the profile
{
    int sip;
    cout<<"Press 1 to change password"<<endl;

    cout<<"Press 3 to return to home"<<endl;
    cin>>sip;

    if(sip==1)
    {
        change_password(ob);
        openLogin(1);
    }

    else if(sip==3)
    {

       openLogin(1);
    }
    else
    {
        cout<<"INVALID OPTION"<<endl;
        settings(ob);
    }

}



void change_password(user ob)       //change_password(), func to change password of the profile
{                                   //when called in settings function
    char temp_pass1[20],temp_pass2[20];
    user temp_ob;

    cout<<"Enter New Password"<<endl;
    {
     int i=0;
   char ch=getch();
    while(ch!=13)
    {
        if(ch==8)
        {
            if(i>0)
            {
            i--;
            cout<<"\b \b";

            }
        }
        else
        {
        temp_pass1[i++]=ch;
        cout<<'*';

        }
ch=getch();
    }
    temp_pass1[i]='\0';
}

    cout<<endl<<"Re-Enter New Password"<<endl;
    {
     int i=0;
   char ch=getch();
    while(ch!=13)
    {
        if(ch==8)
        {
            if(i>0)
            {
            i--;
            cout<<"\b \b";

            }
        }
        else
        {
        temp_pass2[i++]=ch;
        cout<<'*';

        }
ch=getch();
    }
    temp_pass2[i]='\0';
}

    if(strcmp(temp_pass1,temp_pass2)==0)
    {
        fstream pass_change;
        pass_change.open("userData.txt");


        while(pass_change)
        {
            int pos=pass_change.tellg();
            pass_change.read((char*)&temp_ob,sizeof(temp_ob));

            if(strcmp(temp_ob.loginId,ob.loginId)==0)
            {
                pass_change.seekp(pos);
                strcpy(temp_ob.password,temp_pass1);
                pass_change.write((char*)&temp_ob,sizeof(temp_ob));
            }
        }
        pass_change.close();
        cout<<endl<<"!!Password changed!!"<<endl;
    }
    else
    {
    cout<<"!!Password not matched!!"<<endl;
    change_password(ob);
    }

}


#endif // FUNCTIONS_H_INCLUDED

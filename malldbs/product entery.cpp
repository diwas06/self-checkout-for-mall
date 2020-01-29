#include<iostream>
#include<fstream>

using namespace std;

class product
{
  public:
    int pcode;
    char pname[20];
    int pcost;
};
int main()
{
    product ob;
    int ans=1;
    ofstream out;
    out.open("products.txt",ios::app);
    while(ans!=0)
    {
    cout<<"enter product code"<<endl;
    cin>>ob.pcode;
    cout<<"enter product name"<<endl;
    cin>>ob.pname;
    cout<<"enter product cost"<<endl;
    cin>>ob.pcost;
    out.write((char*)&ob,sizeof(ob));

    cout<<"do you want to countinue?"<<endl;
    cout<<"press 0 if you want to end"<<endl;

    cin>>ans;
    }
}

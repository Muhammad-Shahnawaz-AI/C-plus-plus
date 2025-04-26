#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<5;i++)
    {
        cout<<i+1<<endl;
    }
    cout<<"------------------------------"<<endl;
    int a = 10;
    do
    {
        cout<<a<<endl;
        a--;
    }
    while(a>0);
    cout<<"------------------------------"<<endl;
    while(a<10)
    {
        cout<<a<<endl;
        a++;
    }
    return 0;
}

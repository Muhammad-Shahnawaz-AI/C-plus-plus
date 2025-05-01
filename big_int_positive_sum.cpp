#include<iostream>
using namespace std;
int main()
{
    string n1="",n2="",n3="";
    cout<<"Enter the value of num 1: ";
    cin>>n1;
    cout<<"Enter the value of num 2: ";
    cin>>n2;
    int a=n1.length();
    int b=n2.length();
    int r=0;
    int max;
    if(a>b)
    max=a;
    else 
    max=b;
    for(int i=max;i>0;i--)
    {
        if(a>0&&b>0)
        {
            n3=n3+char((int(n1[a-1])+int(n2[b-1])-96+r)%10+48);
          r=((int(n1[a-1])+int(n2[b-1])-96+r)-(int(n1[a-1])+int(n2[b-1])-96+r)%10)/10;
        }
        else if(a>0)
        {
            n3=n3+char((int(n1[a-1])-48+r)%10+48);
             r=(((int(n1[a-1])-48+r)-(((int(n1[a-1])-48)+r)%10)))/10;
        }
        else if(b>0)
        {
            n3=n3+char((int(n2[b-1])-48+r)%10+48);
            r=((int(n2[b-1])-48+r)-(int(n2[b-1])-48+r)%10)/10;
        }
        a--;
        b--;
    }
    if(r>0)
    {
        n3=n3+char(r+48);
    }
    r=n3.length();
    for(int i=r-1;i>=0;i--)
    {
        cout<<n3[i];
    }
    cout<<endl;
    return 0;
}
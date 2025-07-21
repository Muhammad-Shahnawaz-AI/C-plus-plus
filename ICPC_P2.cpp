#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string a;
        cin>>a;
        int l=a.length();
        bool check = true;
        for(int j=0;j<l;j=j+3)
        {
            check=check&&((a[j]>=65&&a[j]<=71)&&(a[j+1]==48)&&(a[j+2]>=48&&a[j+2]<=52));
            if(!check)
            {
                cout<<-1<<" "<<a[j]<<a[j+1]<<a[j+2]<<endl;
                break;
            }
        }
        if(check)
        {
         int c[7][4];
         for(int j=0;j<7;j++)
         {
             for(int k=0;k<4;k++)
             {
                 c[j][k]=0;
             }
         }
         for(int j=0;j<7;j++)
         {
             for(int k=0;k<4;k++)
             {
                 for(int o=0;o<l;o=o+3)
                 {
                     if(a[o]==(j+65)&&a[o+2]==(k+49))
                     {
                         c[j][k]=c[j][k]+1;
                     }
                 }
             }
         }
         int cal=0;
         for(int j=0;j<7;j++)
         {
             for(int k=0;k<4;k++)
             {
                 if(c[j][k]!=0)
                 cal++;
             }
         }
         cout<<cal<<" ";
         char z1='A',z2='1';
        for(int j=0;j<7;j++)
         {
             for(int k=0;k<4;k++)
             {
                 if(c[j][k]!=0)
                 
                 
                 cout<<" "<<char(int(z1)+j)<<"0"<<char(int(z2)+k)<<" ";
             }
         }
         for(int j=0;j<7;j++)
         {
             cal=0;
             for(int k=0;k<4;k++)
             {
                 if(c[j][k]!=0)
                 cal++;
             }
             if(cal!=0)
             {
                 switch(j)
                 {
                     case 0:
                     cout<<cal<<" Competitions ";
                     break;
                     case 1:
                     cout<<cal<<" Entertainment ";
                     break;
                     case 2:
                     cout<<cal<<" Social Gatherings ";
                     break;
                     case 3:
                     cout<<cal<<" Dinners ";
                     break;
                     case 4:
                     cout<<cal<<" Processions ";
                     break;
                     case 5:
                     cout<<cal<<" Training Workshops ";
                     break;
                     case 6:
                     cout<<cal<<" Exams ";
                     break;
                     
                 }
             }
         }
         
         
        }
        cout<<endl;
    }
    return 0;
}
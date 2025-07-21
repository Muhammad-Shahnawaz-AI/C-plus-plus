// #include<iostream>
// #include<string>
// #include<queue>
// using namespace std;

// int main()
// {
//     queue<int> address;
//     string a, s;
//     cin >> a >> s;

//     int al = a.length();
//     int sl = s.length();

//     if (sl > al) {
//         cout << 0 << endl;
//         return 0;
//     }

//     int c = 0;
//     for (int i = 0; i <= al - sl; i++)  
//     {
//         bool x = true;
//         for (int j = 0; j < sl; j++)
//         {
//             if (int(s[j]) != 63) {
//                 if(int(a[i + j] )!= int(s[j]))
//                 x = false;
//                 break;
//             }
//         }
//         if (x)
//         {
//             c++;
//             address.push(i);
//         }
//     }

//     cout << c << endl;
//     while (!address.empty())
//     {
//         cout << address.front() << " ";
//         address.pop();
//     }

//     return 0;
// }


// #include<iostream>
// using namespace std;
// int main()
// {
//     int s;
//     int n;
//     cin>>n;
//     cin>>s;
//     s=s+n;
//     int k=0;
//     int r=0;
//     if(s>n)
//     {
//     for(int i=s;r!=2;i++)
//     {
//         r=0;
//         k=i;
//     while((!(s==0&&n==0))&&r<4)
//     {
//         if(s>n)
//         {
//             int t=n;
//             if(n==1)
//             n=1;
//             else
//             n=n/2;
//             s=s-t;
//         }
//         else if(n>s)
//         {
//             int t=s;
//             if(s==1)
//             s=1;
//             else
//             s=s/2;
//             n=n-t;
//         }
//         else 
//         {
//         s=0;
//         n=0;
//         }

//         r++;
//     }
// }
// }
// else
// {
//     for(int i=s;r!=2&&i>0;i--)
//     {
//         r=0;
//         k=i;
//     while((!(s==0&&n==0))&&r<4)
//     {
//         if(s>n)
//         {
//             int t=n;
//             if(n==1)
//             n=1;
//             else
//             n=n/2;
//             s=s-t;
//         }
//         else if(n>s)
//         {
//             int t=s;
//             if(s==1)
//             s=1;
//             else
//             s=s/2;
//             n=n-t;
//         }
//         else 
//         {
//         s=0;
//         n=0;
//         }

//         r++;
//     }
// }
// }
// if(r==2)
// cout<<k<<endl;
// else 
// cout<<-1<<endl;
//     return 0;
// }

// #include<iostream>
// #include<string>
// using namespace std;
// int mul(int m)
// {
//     if(m==0)
//     return 1;
//     else
//     return 2*mul(m-1);
// }
// int main()
// {
//     string a="",f="",x="";
//     int n;
//     cin>>n;
//     while(n>0)
//     {
//         a=a+char(n%2+48);
//         n=n/2;
//     }
//     int l=a.length();
//     int k=l-2;
//     while(a[k]!=48)
//     {
//         f=f+"1";
//         k--;
//     }
//     while(k>=0)
//     {
//         if(a[k]==48)
//         x="0"+x;
//         else
//         x=x+"1";
//         k--;
//     }
//     a=f+x+"1";
//     l=a.length();
//     int s=0;
//     int j=0;
//     for(int i=l-1;i>=0;i--)
//     {
//         s=s+(a[i]-48)*mul(j);
//         j++;
//     }
//     cout<<s<<endl;
//     return 0;
// }
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s;
    cin>>s;
    s=s+n;
    if(s>n)
    {
        bool x=true;
        int r=0;
        int re=0;
        for(int i=s;r!=2;i++)
        {
            r=0;
            re=i;
            while(r<4)
            {
                if(s>n)
                {
                s=s-n;
                n=n/2;
                }
                else if(n>s)
                {
                    n=n-s;
                    s=s/2;
                }
                else
                {
                    s=0;
                    n=0;
                }
                r++;
                if(s==0&&n==0)
                break;
                }
        }
        cout<<re<<endl;

    }
    else
    {

    }
    return 0;
} 
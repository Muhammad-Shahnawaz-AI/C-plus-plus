// // #include<iostream>
// // using namespace std;
// // long long int co (long long int a)
// // {
// //     long long int c=0;
// //     for(long long int i=2;i<a;i++)
// //     {
// //         bool x = true; 
// //         for(long long int j=2;j<i;j++)
// //         {
// //             x = x &&(a%j!=0&&i%j!=0);
// //             if(!x);
// //             break;
// //         }
// //         if(x)
// //         c++;
// //     }
// //     return c;
// // }
// // int main()
// // {
// //     long long int n;
// //     long long int s=0;
// //     for(long long int i=1;i<=n;i++)
// //     {
// //         s=s+(i%co(i));
// //     }
// //     cout<<(s)<<endl;
// //     return 0;
// // }

#include <iostream>
using namespace std;

long long int co(long long int a)
{
if(a==1||a==2)
return 1;
if(a==3||a==4)
return 2;
long long int c=0;
for(long long int i=3;i<a;i++)
{
    bool x=true;
    for(long long int j=2;j<i;j++)
    {
      x=x &&(a%j!=0||i%j!=0);
      if(!x)
      break;
    }
    if(x)
    c++;

}
return c;


}

int main() {
    long long int n;
    cin >> n; // Prompt user for input
    long long int s = 0;
    for (long long int i = 1; i <= n; i++) {
        s = s + (i % co(i));
    }
    cout << s%4294967296 << endl;
    return 0;
}



//This program calculatesthe total number of prime numbers from zero to the entered number
#include<iostream>
using namespace std;
void calculate (long long int a )
{
    int n = 0;
    for(long long int i=a;i>1;i--)
    {
        long long int k = i-1;
        bool x = true;
        for(long long int j = k; j > 1;j--)
        {
            if(i%j==0)
            {
            x = false;
            break;
            }
        }
        if(x)
        n++;
    }
    cout<<"Total number of prime numbers from 0 to "<<a<<" is = "<<n<<endl;
    
}
int main()
{
    long long int b;
    cout<<"Enter the value: ";
    cin>>b;
    calculate(b);
    return 0;
}
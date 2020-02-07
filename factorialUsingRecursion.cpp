#include<iostream>

using namespace std;
int fib(int n)
{
    int b;
    cout<<"Calculating factorial of "<<n<<endl;
    if(n==0) return 1;
    else
    {
        b=n*fib(n-1);
    cout<<"F("<<n<<")"<<" is "<<b<<endl;
    return b;}
}
int main()
{
    
    cout<<fib(7)<<endl;
}

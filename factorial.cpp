#include<iostream>
using namespace std;
int factorial(int n)
{
    int i,f=1;
     for(i=1;i<=n;i++){
      f=f*i;
  }
   cout<<"factorial for"<<" "<<n<<" "<<"is"<<" "<<f;
}
int main()
{
 int n;
 cout<<"Enter a number: ";
  cin>>n;
    factorial(n);

return 0;
}

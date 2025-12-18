#include<iostream>
#define f(x,y) x+y
using namespace std;
int main()
{
 float x0=0,y0=1;
 float xn=0.4;
 float h;
 cout<<"Enter the value of h:"<<endl;
 cin>>h;
 float yn,m1,m2;
 int i;
 float n=1;
 for(i=0; i < n; i++){
  n=(xn-0)/h;
  m1=f(x0,y0);
  m2=f(x0+h,y0+m1*h);
  yn = y0 + (m1+m2)/2 * h;
  y0 = yn;
  x0 = x0+h;
 }
 cout<<"\nValue of y at x = "<< xn<< " is " << yn;
 return 0;
}
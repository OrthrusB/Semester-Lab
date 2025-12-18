#include<iostream>
#include<cmath>
#define f(x,y) x+y
using namespace std;
int main()
{
 float x0=0,y0=1;
 float xn=0.4;
 float h;
 cout<<"Enter the value of h:"<<endl;
 cin>>h;
 float yn,k1,k2,k3,k4,k;
 int i;
 float n=1;
 for(i=0; i < n; i++){
  n=(xn-0)/h;
  k1 = h * (f(x0, y0));
  k2 = h * (f((x0+h/2), (y0+k1/2)));
  k3 = h * (f((x0+h/2), (y0+k2/2)));
  k4 = h * (f((x0+h), (y0+k3)));
  k = (k1+2*k2+2*k3+k4)/6;
  yn = y0 + k;
  x0 = x0+h;
  y0 = yn;
 }
 cout<<"\nValue of y at x = "<< xn<< " is " << yn;
 return 0;
}
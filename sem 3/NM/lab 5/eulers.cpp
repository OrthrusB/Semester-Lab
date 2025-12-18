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
 float yn, slope;
 int i;
 float n=1;
 for(i=0; i < n; i++){
  n=(xn-0)/h;
  slope = f(x0, y0);
  yn = y0 + h * slope;
  y0 = yn;
  x0 = x0+h;
 }
 cout<<"\nValue of y at x = "<< xn<< " is " << yn;
 return 0;
}
#include<iostream>
#include<math.h>
#define f(x,y) x*x*x+y*y
using namespace std;
int main(){
 float a,b,c,d,integration,h,k;
 cout<<"Enter lower limit a: ";
 cin>>a;
 cout<<"Enter upper limit b:";
 cin>>b;
 cout<<"Enter lower limit c:";
 cin>>c;
 cout<<"Enter upper limit d:";
 cin>>d;
 h = (d- c)/2*(b-a)/2;
integration=(f(b,d))+(f(b,c))+(f(a,c))+(f(a,d));
integration=integration*h;
cout<<"The result of double integration is "<<integration<<endl;
 return 0;
}
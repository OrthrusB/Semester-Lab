#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
//6x1-2x2+x3=11
//x1+2x2-5x3=-1
//-2x1+7x2+2x3=5
#define f1(x,y,z) (11+2*y-z)/6
#define f2(x,y,z) (5+2*x-2*z)/7
#define f3(x,y,z) (1+x+2*y)/5
int main(){
float a=0,b=0,c=0,a1,a2,a3,e1,e2,e3,e;
int n=1;
cout<<"Enter error:"<<endl;
cin>>e;
do{
	a1=f1(a,b,c);
	a2=f2(a1,b,c);
	a3=f3(a1,a2,c);
		cout<<"Step-"<<n<<"  a1="<<a1<<"  a2="<<a2<<"  a3="<<a3<<" "<<endl;	
	e1=fabs(a-a1);
	e2=fabs(a-a2);
	e3=fabs(a-a3);
	
	a=a1;
	b=a2;
	c=a3;
	
	n++;
}while(e1>e&& e2>e&&e3>e);
cout<<"The value of x,y and z is "<<a1<<" "<<a2<<" and "<<a3<<endl;
return 0;
	
}
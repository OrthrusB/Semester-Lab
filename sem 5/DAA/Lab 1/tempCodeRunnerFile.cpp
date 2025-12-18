#include<iostream>
using namespace std;
int gcd(int h, int i, int &steps){
    steps++;
    if (i==0){
        return h;
    }
    return gcd (i,h%i, steps);
}
int main(){
    int a,b, steps=0;
    cout<<"enter two numbers: ";
    cin>>a>>b;
    cout<<"GCD: "<<gcd(a,b,steps)<<endl;
    cout<<"steps required: "<<steps<<endl;
    return 0;
}
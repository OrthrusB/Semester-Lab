#include<iostream>
using namespace std;
int Fibo(int n, int &steps){
    steps++;
    if(n==0)
    return 0;

    if (n==1)
    return 1;

    return  Fibo(n-1,steps)+Fibo(n-2,steps);
}

int main(){
    int n, steps=0;
    cout<<"enter the position(n): ";
    cin>>n;
    cout<<"fibonacci term: "<<Fibo(n,steps)<<endl;
    cout<<"steps required: "<<steps<<endl;
    return 0;
}

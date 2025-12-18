#include<iostream>
using namespace std;
int Factorial(int n, int &steps){
    steps++;
    if(n==0){
        return 1;
    }

    return n*Factorial(n-1,steps);
}

int main(){
    int n,steps=0;
    cout<<"enter a number: ";
    cin>>n;
    cout<<"Factorial: "<<Factorial(n,steps)<<endl;
    cout<<"steps required: "<<steps<<endl;
    return 0;
}
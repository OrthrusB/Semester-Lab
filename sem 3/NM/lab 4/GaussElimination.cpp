#include<iostream>
#include<math.h>
#define max 10
using namespace std;
int main(){
	float a[max][max],x[max],ratio;
	int n,i,j,k;
	cout<<"Enter the number of datas:"<<endl;
	cin>>n;
	cout<<"Enter coefficients of matrix:"<<endl;
	for(i=1;i<=n;i++){
		for(j=1;j<=n+1;j++){
			cout<<"Enter a["<<i<<"]["<<j<<"]:";
			cin>>a[i][j];
		}
	}
	for(i=1;i<=n;i++){
		if(a[i][i]==0.0){
			cout<<"Error"<<endl;
			exit(0);
		}
			for(j=i+1;j<=n;j++){
					ratio=a[j][i]/a[i][i];
					for( k=1;k<=n+1;k++){
						a[j][k]=a[j][k]-ratio*a[i][k];
					}
				}
			}
	    x[n] = a[n][n+1]/a[n][n];
	 for(i=n-1;i>=1;i--)
	 {
		  x[i] = a[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		x[i] = x[i] - a[i][j]*x[j];
		  }
		  x[i] = x[i]/a[i][i];
	 }
		 cout<<"Solution is:"<<endl;
		 for(i=1;i<=n;i++){
		 	cout<<"x["<<i<<"]="<<x[i]<<endl;
		 }
	return 0;
}
#include<iostream>
using namespace std;

bool isConnected(int num1, int num2){
    if(num1==num2){
        return true;
    }
    return false;
}

int main()
{

    int noVer = 0;

    cin>>noVer;

    int graph[noVer][noVer];

    for(int i=0;i<noVer;i++)
    {
        for(int j=0;j<noVer;j++)
        {
            cin>>graph[i][j];
        }
    }

    int shortPath=0;

    int newPath=999;

    int x=0;

    int s=999;

    int i=0;
    int j=0;

    int row=0;

    int col=0;


    while(row!=noVer && col!=noVer)
    {
        if(graph[row][col]!=0)
        {
            if(isConnected(graph[row][col],graph[col][row]))
            {
                if(graph[row][col]<s)
                {
                    s=graph[row][col];
                    i=row;
                    j=col;
                }
            }
            if(col==noVer-1){
                if(isConnected(graph[row][col],graph[col][row])){
                    x=shortPath+graph[row][col];

                    if(x<newPath)
                    {
                        newPath=x;
                    }
                }
            }
        }
    
if(row==noVer-1){

    if (isConnected(graph[row][col],graph[col][row])){
        break;
    }
}
if(col==noVer-1){
    shortPath+=s;
    row=j;
    col=i;
    s=999;
}
col++;
    }

    if(shortPath<newPath){
        cout<<"the shortest path to travel in the given graph is: "<<shortPath<<endl;
    }
    else{
        cout<<"the shortes path to travel in the graph is: "<<newPath<<endl;
    }
    return 0;
}
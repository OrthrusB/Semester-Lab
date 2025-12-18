#include<iostream>

using namespace std;
 class circularqueue{
int arr[5];
int front ;
int rear;
int itemcount;

public:
circularqueue(){ //the default constructor which will be called whenever the object is made
	itemcount=0;
	front=-1;
	rear=-1;
for(int i=0; i<5; i++)
{
	arr[i]=0;
}
}
bool isfull()
{
	if((rear+1)%5==front)
	{
	return true;
	}
	else{
	return false;
	}
	}
bool isempty()
{
	if(front==-1 && rear==-1)
	{
	return true;
	}
	else
	{
	return false;
	}
}
void enqueue(int val)
{
if(isfull())
{
cout<<"the queue is full:  ";
return;
}
else if (isempty())
{
rear=0;
front=0; // is empty situtation both rear and front are -1 index which does not exist in the array so we make it 0
arr[rear]=val;
itemcount++;
}
else {
rear=(rear+1)%5 ;
arr[rear]=val;
}
itemcount++;
}

int dequeue()
{
	int x=0;
	if(isempty())
	{
	cout<<"queue is empty"<<endl;
	return 0;
	}
	else if(front==rear)
	{
	x=arr[front];
	
	rear=-1;
	front=-1;
	itemcount--;
	return x;
	}
	else
	{
	x=arr[front];
	arr[front]=0;
	front=(front+1)%5;
	itemcount--;
	return x;
	}
}
 int count()
 {
return (itemcount);
 }
 void display()
 {
 for (int i=0;i<5; i++)
 {
 	cout<<arr[i]<<endl;
 }
 }
 };
 int main(){
circularqueue q1;
int option,val;
do
{
	cout<<"what operation do you want to perform? select option number.enter zero to exit"<<endl;
	cout<<"1. enqueue() "<<endl;
	cout<<"2. dequeue()"<<endl;
	cout<<"3. isempty()"<<endl;
    cout<<"4. isfull()"<<endl;
	cout<<"5. count()"<<endl;
	cout<<"6. display()"<<endl;
	cout<<"7. clear screen"<<endl;	
	cin>>option;
	switch(option)
	{
	case 1:
	cout<<"enqueue.enter enqueue funtion is called. the option to be entered is : "<<endl;
	cin>>val;
	q1.enqueue(val);
	break;
	case 2:
	cout<<"dequeue.\n dequed value: "<<q1.dequeue()<<endl;
	break;
	case 3:
	if(q1.isempty())
	cout<<"the queue is empty"<<endl;
	else
	cout<<"queue is not empty"<<endl;
	break;
	case 4:
	if(q1.isfull())
	cout<<"queue is full"<<endl;
	else
	cout<<"queue is not full"<<endl;
	break;
	case 5:
	cout<<"the count of the items in queue is : "<<endl;
	break;
	case 6: 
	cout<<"display function is called: "<<endl;
	q1.display();
	break;
	case 7: 
	system("cls");
	break;
	
	}
}
 while(option!=0);
 return 0;
 
 	
 
} 
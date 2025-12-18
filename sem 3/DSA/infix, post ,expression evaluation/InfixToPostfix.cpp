#include<iostream>
#include<cctype>
#include<cstring>
using namespace std;
 class expressionconversion{
char stack[20];
int top;
public:
expressionconversion(){
top=-1;
}
void push (char x){
top++;
stack[top]=x;
}
char pop(){
return stack[top--];

 }
 int priority(char ch){
if(ch=='(')
return 0;
else if(ch== '+'|| ch=='-')
return 1;
else if (ch=='*'|| ch=='/')
return 2;
else if(ch=='^')
return 3;
}
void infixtopostfix()
{
    char ch;
	char infix [20], postfix[20];
	cout<<"enter the infix epression: "<<endl;
	cin>>infix;
	int j = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
    ch = infix[i];

    if (ch == '(')
    push(ch); 
     
     // for a to z 
    else if (isalpha(ch) || isdigit(ch))
	{
    postfix[j] = ch;
    j++;
    } else if (ch == ')') 
	{
    while (stack[top] != '(' && top != -1) 
	{
    postfix[j] = pop();
    j++;
    }
    pop(); // Pop the '(' and don't sit in postfix
    }
    // for operator  + - 
	else {
    while (priority(ch) <= priority(stack[top]) && top != -1) {
    postfix[j] = pop();
    j++;
    }
    push(ch);
    }
    }
	while (top != -1) {
    postfix[j] = pop();
    j++;
    }
    postfix[j] = '\0';
    cout<<"results is:"<<postfix;
    }
};
int main() {
    expressionconversion e1;


    e1.infixtopostfix();

    

    return 0;
}

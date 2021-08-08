#include<stdio.h>
#include<stdlib.h>
#define size 5
int stack[10];
int top=-1;
void push(int x)
{
	if(top==size-1)
	{
		printf("Stack overflow");
	}
	else
	{
		top=top+1;
		stack[top]=x;
	}
}
int pop()
{
	int item;
	if(top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		item=stack[top];
		top=top-1;
		return item;
	}
}
int peek()
{
	int item;
	if(top==-1)
	{
		printf("Stack underflow");
	}
	else
	{
		item=stack[top];
		return item;
	}
}
void display()
{
	int i;
	for(i=0;i<=top;i++)
	{
		printf("%d ",stack[i]);
	}
}
int main()
{
	int ch,val;
	while(1)
	{
		printf("choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the value to be pushed");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				printf("the element popped is %d",pop());
				break;
			case 3:
				printf("top element is %d",peek());
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
			default:
				printf("invalid");
				
		}
	}
}




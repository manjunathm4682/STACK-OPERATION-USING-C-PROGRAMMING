#include<stdio.h>
#include<stdlib.h>
#define ele 5
int stack[ele];
int top=-1;

void push(void)
{
	if(top>=ele-1)
	{
	printf("stack is overflow...!\n");
	return;
	}

	top++;
	printf("enter the number to push\n");
	scanf("%d",&stack[top]);

}

void pop(void)
{
	if(top<=-1)
	{
	printf("stack is under flow\n");
	return;
	}

	printf("deleted : %d",stack[top]);
	top--;
}

void display(void)
{
	if(top<=-1)
	{
	printf("stack is empty\n");
	return;
	}

	for(int i=0;i<=top;i++)
	{
	printf("%d ",stack[i]);
	}
	printf("\n");


}

int main()
{
int op;
while(1)
{
printf("Enter option: \n");
printf("1.push 2.pop 3.display\n");
scanf("%d",&op);
switch(op)
{
	case 1:push();break;
	case 2:pop();break;
	case 3:display();break;
	       
	default: printf("you entered wrong option\n");
}
}
}

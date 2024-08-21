#include<stdio.h>
#include<stdlib.h>
#define ele 5
typedef struct stk
{
int num;
struct stk *next;
}stack;

void push(stack **);
void pop(stack **);
void display(stack *);
int count_node(stack *);

int top=-1;

int main()
{
	stack *head=0;

int op;
while(1)
{
printf("Enter the option\n");
printf("1.push 2.pop 3.display 4.exit\n");
scanf("%d",&op);
switch(op)
{
	case 1:push(&head);break;
	case 2:pop(&head);break;
	case 3:display(head);break;
	case 4:exit(0);
	default:printf("wrong option entered, try again...!\n");
}
}
}

void push(stack **ptr)	//add_end
{
if(top>=ele-1)
{
printf("stack is overflow\n");
return;
}

top++;
stack *new,*last;
new=malloc(sizeof(stack));
printf("enter the number\n");
scanf("%d",&new->num);
new->next=0;

if(*ptr==0)
{
*ptr=new;
}
else
{
	last=*ptr;
	while(last->next)
	last=last->next;
	last->next=new;
}
}

int count_node(stack *ptr)
{
int c=0;
if(ptr==0)
{
return c;
}
else
{
while(ptr)
{
	c++;
ptr=ptr->next;
}
}
return c;
}

void pop(stack **ptr)
{
if(top<=-1 || *ptr==0)
{
printf("stack is underflow\n");
return;
}
stack *del;
stack *t=*ptr;
int c=count_node(*ptr);
if(c==1)
{
del=t;
t->next=0;
}
else
{
for(int i=0;i<c-2;i++)
t=t->next;
del=t->next;
t->next=0;
}
printf("the number : %d\n",del->num);
free(del);
top--;
}

void display(stack *ptr)
{
if(ptr==0 || top<=-1)
{
printf("stack is empty\n");
return;
}
while(ptr)
{
printf("%d\n",ptr->num);
ptr=ptr->next;
}
}

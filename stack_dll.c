#include<stdio.h>
#include<stdlib.h>
#define ele 5
int top=-1;
typedef struct stk
{
struct stk *prev;
int num;
struct stk *next;
}stack;

void push(stack **);
void pop(stack **);
void display(stack *);
int count_node(stack *);




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

void push(stack **ptr)	//using DLL add_end method
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
new->next=0; 		//assigning null on both prev and next pointer
new->prev=0;

if(*ptr==0)		//if the headptr is pointing 0
{
*ptr=new;
}
else			
{
last=*ptr;
while(last->next)
last=last->next;
last->next=new;
new->prev=last;
}
}

void pop(stack **ptr)
{
if(top<=-1 || *ptr==0)
{
printf("stack is underflow\n");
return;
}

stack *last,*del;
last=*ptr;
while(last->next)
last=last->next;

del=last;		//last node address

if(last->prev!=0)	//if more than 1 nodes 
last->prev->next=0;	//then assign 0 to last before 2nd node

printf("the number deleting is : %d\n",del->num);
free(del);		//delete the node;
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





















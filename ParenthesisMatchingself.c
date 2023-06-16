#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	char* arr;
};
void CreateStack(struct stack* s)
{
	printf("Enter the size of the stack\n");
	scanf("%d",&s->size);
	s->arr=(char*)malloc(s->size*sizeof(char));	
	s->top=-1;
	printf("Dynamically allocated memory successfully\n");
}

int IsEmpty(struct stack *s)
{
	if(s->top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(struct stack* s,char element)
{ 
	s->top++;
	s->arr[s->top]=element;
}

int pop(struct stack* s)
{
	if(IsEmpty(s))
	{
	   printf("Stack Underflow\n");
	   return 0;
	}
	else
	{
		s->top--;
		return 1;
	}
}

void display(struct stack* s)
{
	int i;
	for(i=0;i<=s->top;i++)
	{
		printf("%c\n",s->arr[i]);
	}
}

void Check(char s[],struct stack* stk)
{
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='(')
		{
			push(stk,'(');
		}
		if(s[i]==')')
		{
			if(!pop(stk))
			{
				printf("Your string is unbalanced\n");
				return;
			}
		}
	}
	
	if(IsEmpty)
	{
		printf("Your string is balanced\n");
	}
	else
	{
		printf("Your string is unbalanced\n");
	}
}

int main()
{
	char s1[]="(3*)2*(6+7)";
	struct stack s2;
	CreateStack(&s2);
	
	Check(s1,&s2);
	return 0;
}

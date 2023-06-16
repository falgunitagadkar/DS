//parenthesis matching

#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	char *arr;
};

void push(struct stack* s,char ele)
{ 
   s->top++;
 	 s->arr[s->top]=ele;
}

int pop(struct stack* s)
{
	if(s->top==-1)
	{
		return 0;
  }
	s->top--;
	return 1;
}
int main()
{
  char sarr[15]="3+8)*((4-5)";
	struct stack* s=(struct stack*)malloc(sizeof(struct stack));
	s->size=10;
	s->top=-1;
	s->arr=(char*)malloc(s->size*sizeof(char));
	int i;
	for(i=0;sarr[i]!='\0';i++)
	{
		if(sarr[i]=='(')
		{
			push(s,sarr[i]);
		}
		if(sarr[i]==')')
		{
			int q;
			q=pop(s);
			if(q==0)
			{
				printf("Invalid expression\n");
				break;
			}
		}
	}
	
	if(sarr[i]=='\0')//check if yoou reached end of expression
	{
		if(s->top==-1)
		{
			printf("Valid expression\n");
		}
		else
		{
			printf("Invalid expression\n");
		}
	}
	return 0;
}

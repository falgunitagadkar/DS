

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack
{
	int size;
	int top;
	char* arr;
};

int isEmpty(struct stack* s)
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

int isFull(struct stack* s)
{
	if(s->top==s->size-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(struct stack* s,char ele)
{
	s->top++;
	s->arr[s->top]=ele;
}

int matching(char a,char b)
{
	if(a=='(' && b==')')
	{
		return 1;
	}
	if(a=='[' && b==']')
	{
		return 1;
	}
	if(a=='{' && b=='}')
	{
		return 1;
	}
	return 0;//if not matched
}

char pop(struct stack *s)//don't check isEmpty here as it is checked in the function itself
{
	  char c;
	  c=s->arr[s->top];
		s->top--;
		return c;
}
int parenthesisCheck(char* exp)
{
	int i;
	struct stack* s=(struct stack*)malloc(sizeof(struct stack));
	s->size=strlen(exp);
	s->top=-1;
	s->arr=(char*)malloc(s->size*sizeof(char));
	for(i=0;exp[i]!='\0';i++)
	{
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
		{
			push(s,exp[i]);
		}
		else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
		{
			if(isEmpty(s))
			{
				return 0;//return from the check function
			}
			if(!matching(pop(s),exp[i]))//matching the popped element and the element being checked 
			{
				return 0;
			}
		}
	}
	
	if(isEmpty(s))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char* exp="{[(8+9-(7*8))]}";
	if(parenthesisCheck(exp))
	{
		printf("The expression has matching parenthesis\n");
	}
	else
	{
		printf("The expression don't have matching parenthesis\n");
	}
	return 0;
}

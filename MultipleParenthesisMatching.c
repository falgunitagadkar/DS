
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
//Since no use of ifFull so not defined here in this program
void push(struct stack* s,char ele)
{
	s->top++;
	s->arr[s->top]=ele;
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
		else if(exp[i]==')')
		{
			 if(isEmpty(s) || s->arr[s->top]!='(')
			 {
			 	return 0;
			 }
			 else
			 {
			 	 if(s->arr[s->top]=='(')
			 	 {
			 	 	 pop(s);
			   }
			 }
		}
		else if(exp[i]==']')
		{
			if(isEmpty(s) || s->arr[s->top]!='[')//while pop checks condition
			 {
			 	return 0;
			 }
			 else
			 {
			 	 if(s->arr[s->top]=='[')
			 	 {
			 	 	 pop(s);
			   }
			 }
		}
		else if(exp[i]=='}')
		{
			if(isEmpty(s) || s->arr[s->top]!='{')
			 {
			 	return 0;
			 }
			 else
			 {
			 	 if(s->arr[s->top]=='{')
			 	 {
			 	 	 pop(s);
			   }
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
	char* exp="8(}+9-[(7*8)])";
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

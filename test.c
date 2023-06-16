#include<stdio.h>

int main()
{
	
	int size=3;
	int i=0;
	int j;
	for(j=0;j<6;j++)
	{
		printf("%d\n",i);
		i=(i+1)%size;
	}
	return 0;
}

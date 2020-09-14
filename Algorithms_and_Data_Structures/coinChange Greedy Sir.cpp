#include<stdio.h>
#include<limits.h>
int cc[10000];
int S[10000];
int min(int a, int b)
{
	return a<b?a:b;
}

int CoinChange(int n)
{
	if(cc[n]!=-1) return cc[n];
	cc[n]=INT_MAX;
	int temp;
	if(n>=50)
	{
		temp=1+CoinChange(n-50);
		if(cc[n]>temp)
		{
			cc[n]=temp;
			S[n]=50;

		}
	}
	if(n>=25)
	{
		temp=1+CoinChange(n-25);
		if(cc[n]>temp)
		{
			cc[n]=temp;
			S[n]=25;

		}
	}
	if(n>=10)
	{
		temp=1+CoinChange(n-10);
		if(cc[n]>temp)
		{
			cc[n]=temp;
			S[n]=10;

		}
	}
	if(n>=1)
	{
		temp=1+CoinChange(n-1);
		if(cc[n]>temp)
		{
			cc[n]=temp;
			S[n]=1;

		}
	}
	return cc[n];
}

int main()
{
	int amount =30;
	for(int i=0;i<=amount;i++)
		cc[i]=-1;
	cc[0]=0;
	CoinChange(amount);
	for(int i=0;i<=amount;i++)
		printf("%d ",cc[i]);
	printf("\n");
	for(int i=0;i<=amount;i++)
		printf("%d ",S[i]);


	return 0;
}

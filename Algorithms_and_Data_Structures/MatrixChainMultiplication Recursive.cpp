#include<stdio.h>
#include<limits.h>
#define  SIZE 6
//int p[SIZE];
int p[]={30,35,15,5,10,20,25};
int mcm(int,int);
int M[SIZE+1][SIZE+1];
int S[SIZE+1][SIZE+1];

int main()
{
	int n=6;
	/*printf("How many matrices?");
	scanf("%d",&n);
	printf("Please enter the dimensions:");
	for(int i=0;i<=n;i++)
	{
		scanf("%d",p+i);
	}*/
	for(int i=0;i<=SIZE;i++)
		for(int j=0;j<=SIZE;j++)
			if(i==j)
				M[i][j]=0;
			else
				M[i][j]=-1;
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE;j++)
		{
			printf("%6d ",M[i][j]);
		}
		printf("\n");
	}
	printf("Number of Multiplications needed: %d\n",mcm(1,n));
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE;j++)
		{
			printf("%6d ",M[i][j]);
		}
		printf("\n");
	}
	printf("\n Now the array S:\n");
	for(int i=1;i<=SIZE;i++)
	{
		for(int j=1;j<=SIZE;j++)
		{
			printf("%6d ",S[i][j]);
		}
		printf("\n");
	}
}




int mcm(int i,int j)
{
	if(i==j) return 0;
	else
	{
		int qmin=INT_MAX;
		int kmin=-1;
		for(int k=i;k<j;k++)
		{
			int temp=mcm(i,k)+mcm(k+1,j)+p[i-1]*p[k]*p[j];
			if(temp<qmin)
			{
				qmin=temp;
				kmin=k;
			}
		}
		S[i][j]=kmin;
		M[i][j]=qmin;
		return qmin;
	}
}

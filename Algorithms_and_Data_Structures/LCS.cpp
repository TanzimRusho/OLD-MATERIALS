#include<stdio.h>
#include<string.h>
#define SIZE 10000

int dp[SIZE][SIZE];
char X[]="HUMAN";
char Y[]="CHIMPANZEE";

int MemoizedLCS(int m,int n)
{
	if(dp[m][n]!=-1) return dp[m][n];
	if(X[m-1]==Y[n-1])
	{
		dp[m][n]=MemoizedLCS(m-1,n-1)+1;

	}
	else
	{
		dp[m][n]=MemoizedLCS(m-1,n);
		int temp=MemoizedLCS(m,n-1);
		if(temp> dp[m][n])
		{
			dp[m][n]=temp;
		}
	}
	return dp[m][n];
}

int LCS(int m,int n)
{
	if(m==0||n==0) return 0;
	if(X[m-1]==Y[n-1])
		return LCS(m-1,n-1)+1;
	else
	{
		int temp1=LCS(m-1,n);
		int temp2=LCS(m,n-1);
		if(temp1>temp2) return temp1;
		else return temp2;
	}
}
void printLCS(int m,int n)
{
	if(m==0||n==0) return;
	if(X[m-1]==Y[n-1])
	{
		printLCS(m-1,n-1);
		printf("%c",X[m-1]);
	}
	else if(dp[m-1][n]>=dp[m][n-1])
		printLCS(m-1,n);
	else
		printLCS(m,n-1);
}
int main()
{
	int m=strlen(X);
	int n=strlen(Y);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=-1;
	printf("The length of LCS: %d\n",MemoizedLCS(m,n));

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	printf("LCS: ");
	printLCS(m,n);
	printf("\n");

	return 0;
}

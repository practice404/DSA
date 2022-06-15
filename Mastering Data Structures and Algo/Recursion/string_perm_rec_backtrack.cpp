#include<iostream>
using namespace std;

void perm(char S[], int k)
{
	static char A[10]{0}, R[10];
	int i;
	if(S[k] == '\0')
	{
		R[k] = '\0';
		cout << R <<endl;
		return;
	}
	for(i=0; S[i] != '\0'; i++)
	{
		if(A[i] == 0)
		{
			A[i] = 1;
			R[k] = S[i];
			perm(S, k+1);
			A[i] = 0;
		}
	}
}

int main()
{
	char S[] = "ABCD";
	perm(S,0);
}
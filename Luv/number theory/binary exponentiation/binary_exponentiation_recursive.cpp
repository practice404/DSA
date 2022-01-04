const int M = 1e9+7;

int binary_expo_recursive(int a, int b)
{
	if (b==0)
		return 1;
	int res = binary_expo_recursive(a,b/2);

	if(b&1) // checking if b is even or odd
	{
		return (a*(res* 1LL * res)%M)%M;
	}
	else
	{
		return (res*res)%M;
	}
}
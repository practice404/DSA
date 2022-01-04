const long long int M = 1e18+7;

long long binary_multiplication(long long a, long long b)
{
	long long ans = 0;
	while(b)
	{
		if(b&1)
			ans = (ans + a)%M;
		a = (a + a)%M;
		b = b>>1;
	}

	return ans;
}

long long binary_expo_iterative_big_M(long long a, long long b)
{
	// a = a % M;  if a <= 10^18
	// a = binary_expo_iterative(2,1024) if a is (2,1024) large number in power, this valaue already comes after modulus
	long long ans = 1;

	while(b)
	{
		if(b&1)
			ans = binary_multiplication(ans,a)%M;
		a = binary_multiplication(a,a)%M;
		b = b>>1;
	}

	return ans;
}


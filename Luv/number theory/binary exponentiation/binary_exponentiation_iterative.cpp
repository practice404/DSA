const int M = 1e9+7;

int binary_expo_iterative(int a, int b)
{
	// a = a % M;  if a <= 10^18
	// a = binary_expo_iterative(2,1024) if a is (2,1024) large number in power, this valaue already comes after modulus
	int ans = 1;

	while(b)
	{
		if(b&1)
			ans = (ans* 1LL *a)%M;
		a = (a* 1LL *a)%M;
		b = b>>1;
	}

	return ans;
}
const int M (1e9+7);

/*

- if b is very large say (a^b^c)% M
- Using Euler totient function and Euler's theorum

- (a^b)%M = (a ^ (b%(M-1)))%M

*/

long long binary_expo_iterative_big_b(long long a, long long b, int M)
{
	long long ans = 1;

	while(b)
	{
		if(b&1)
			ans = (ans*a) % M;
		a = (a*a)%M;
		b = b >> 1;
	}

	return ans;
}


int main()
{
	std::cout<< binary_expo_iterative_big_b(2, binary_expo_iterative_big_b(2,2,M-1), M) << std::endl;
}
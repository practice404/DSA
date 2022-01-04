const int N = 1e7 + 10;

int sieve(int n) // O(N*log(log(N)))
{
	std::vector<bool> is_prime(N, true);
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i <= N; ++i)
	{
		if(is_prime[i])
		{
			for(int j = 2*i; j<= N; j += i)
				is_prime[j] = false;
		}
	}

	return is_prime[n];
}
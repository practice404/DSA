void prime_fs(int n) // O(sqrt(N))
{
	std::vector<int> prime_factors;
	for(int i = 2; i*i <= n; ++i)
	{
		while(n%i == 0)
		{
			prime_factors.push_back(i);
			 n = n/i;
		}
	}

	if(n > 1)
		prime_factors.push_back(n);

	for(auto prime : prime_factors)
		std::cout<<prime<<" ";
}
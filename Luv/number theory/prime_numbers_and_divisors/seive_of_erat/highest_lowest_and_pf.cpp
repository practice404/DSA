#include<bits/stdc++.h>

const int N = 1e7+10;

std::vector<bool> is_prime(N, true);
std::vector<int> lowest_prime(N,0);
std::vector<int> highest_prime(N,0);

void sieve()
{
	is_prime[0] = is_prime[1] = false;

	for(int i = 2; i<=N; ++i)
	{
		if(is_prime[i])
		{
			lowest_prime[i] = highest_prime[i] = i;
			for(int j = 2*i; j<=N; j += i)
			{
				is_prime[j] = false;


				highest_prime[j] = i;


				if(lowest_prime[j] == 0)
					lowest_prime[j] = i;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	sieve(); // calculation of prime and (highest, lowest) prime factor of a number

	// prime factors

	int n; 
	std::cin >> n;
	std::vector<int>prime_factors;
	while(n > 1)
	{
		int prime = highest_prime[n];
		while(n%prime == 0)
		{
			prime_factors.push_back(prime);
			n = n/prime;
		}
	}

	for(auto i : prime_factors)
		std::cout << i << " ";
}
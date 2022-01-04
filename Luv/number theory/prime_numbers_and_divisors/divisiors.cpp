void divisor(int n) // O(sqrt(N))
{
	int count = 0;
	int sum = 0;
	for(int i = 1; i*i <= n; ++i)
	{
		if(n%i == 0)
		{
			count += 1;
			sum += i;
			if(n/i != i)
			{
				count += 1;
				sum += n/i;
			}

			std::cout << i << " " << n/i << std::endl;
		}
	}

	std::cout<<"Count: " << count << " " << "Sum: " << sum << std::endl;
}
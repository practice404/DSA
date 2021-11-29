#include<bits/stdc++.h>
using namespace std;

double sqrt(int n)
{
	double epsilon = 1e-6; // if need n digit accuracy keep epsilon = 1e-(n+1)

	double lo = 0, hi = n;

	while(hi - lo > epsilon)
	{
		double mid = lo + (hi - lo)/2;

		if(mid * mid < n)
			lo = mid;
		else
			hi = mid;

	}

	return lo;
}

int main()
{
	int n;
	cin >> n;

	cout<<sqrt(n);
}
// program to find the Module Multiplicative Inverse of a number w.r.t M
// - M should be prime
// - A,M are co-prime i.e gcd(A,M) = 1

// theorum:

// (A^(M-2) % M) is the MMI of A (B)

#include<bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

int binary_exponentiation(int a, int b, int m)
{
	int ans = 1;
	while(b)
	{
		if(b&1)
			ans = (ans* 1LL *a)%m;
		a = (a* 1LL *a)%m;
		b = b>>1;
	}

	return ans;
}

int main()
{
	int a = 2;
	int mmi_of_a = binary_exponentiation(a,M-2,M);
	cout << mmi_of_a;
}

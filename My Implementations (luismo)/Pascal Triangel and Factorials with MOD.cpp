
// >> Pascal Triangle
ll pascal[lim][lim];

void buildPascal(int sz)
{
	pascal[0][0] = 1;
	for(int i = 1; i < sz; i++)
	{
		pascal[i][0] = pascal[i][i] = 1;
		for(int j = 1; j < i; j++)
		{
			pascal[i][j] = (pascal[i-1][j] + pascal[i-1][j-1]) % mod;
		}
	}
}

// << Pascal Triangle

// >> Factorials
ll fact[lim];

void buildFactorials(int sz)
{
	fact[0] = 1;
	for(int i = 1; i < sz; i++)
	{
		fact[i] = (i * fact[i - 1]) % mod;
	}
}
// << Factorials
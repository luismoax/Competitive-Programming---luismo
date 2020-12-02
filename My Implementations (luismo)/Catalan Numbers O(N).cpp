
// >> Catalan
ll catalan[lim];
void buildCatalan()
{
	catalan[0] = 1;

	for(int i = 1; i < lim; i++)
	{
		for(int k = 0; k < i; k++)
		{
			catalan[i] += (catalan[k] * catalan[i - k - 1]) % mod;
			catalan[i] %= mod;
		}
	}
}
// << Catalan
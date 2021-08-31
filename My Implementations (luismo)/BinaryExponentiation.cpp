// Recursive
ll binPow(ll b, ll exp)
{
    if(exp == 0)
        return 1;
    ll aux = binPow(b, exp / 2);
    aux = (aux * aux) % mod;
    if(exp % 2 == 1)
        aux = (aux * b) % mod;
    return aux;
}

// Iterative
ll binExp(ll b, ll exp)
{
	ll ret = 1;
	ll cur = b % mod;
	while(exp > 0)
	{
		if(exp % 2 == 1)
			ret = (cur * ret) % mod;		
		cur = (cur * cur) % mod;		
		exp >>= 1;
	}
	return ret;
}
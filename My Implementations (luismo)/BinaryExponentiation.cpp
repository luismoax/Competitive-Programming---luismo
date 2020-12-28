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

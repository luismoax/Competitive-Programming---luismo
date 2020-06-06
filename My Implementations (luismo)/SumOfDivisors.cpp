
// >> Sieve
int sieve[lim];
vector<int> primes;
void buildSieve()
{
    primes.push_back(2);
    for(int i = 2; i < lim; i+= 2)
        sieve[i] = 2;

    for(int i = 3; i < lim; i+= 2)
    {
        if(sieve[i] == 0)
        {
            primes.push_back(i);
            for(int j = i; j < lim; j+= i)
                sieve[j] = i;
        }
    }
}
// << Sieve

map<ll, ll> toDecompose(ll x)
{
    ll aux = x;
    map<ll, ll> ret;
    for(int i = 0; aux > 1 && i < primes.size(); i++)
    {
        while(aux % primes[i] == 0)
        {
            ret[primes[i]]++;
            aux /= primes[i];
        }
    }
    if(aux > 1)
        ret[aux]++;
    return ret;
}

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

ll sumSeries(ll b, ll until)
{
    ll k = (binPow(b, until + 1) - 1 + mod) % mod;
    ll invMod = binPow(b - 1, mod - 2);

    ll ret = (k * invMod) % mod;
}

ll sumOfDivisors(ll x)
{
    map<ll, ll> dec = toDecompose(x);

    ll ret = 1;

    for(auto item: dec)
    {
        ll b = item.first;
        ll until = item.second;

        ret = (ret * sumSeries(b, until)) % mod;
    }
    return ret;
}
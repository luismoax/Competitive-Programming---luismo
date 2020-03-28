/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1160 - Discovering Paths in Grid
	Online Judge: LightOJ
	Idea: Lets say 2 different configurations are adjacent if from one I can turn
	into the other and vice-versa.
	Set a matrix of adjacency for each pair of configurations (no more than
	35 = C(7, 4) ). Elevate it to the N - 1 power and solve
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf
#define mkp make_pair
#define fi first
#define se second
#define endl "\n"

using namespace std;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll inf = 1e16 + 3;
const int mod = 1000000007;
const int lim = 35;

int tc, N;

// >> MATRIX EXPNENTIATION - Fixed Memory
ull base[lim][lim];
ull elev[lim][lim];
ull auxMt[lim][lim];

// multiply elev by another square matrix of the same dimension
// using auxMt as an auxiliar Matrix
void multiply(ull mt[lim][lim], int d)
{
    //
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            for(int k = 0; k < d; k++)
            {
                auxMt[i][j] = ((elev[i][k] * mt[k][j]) % mod
                            + auxMt[i][j]) % mod;
            }
        }
    }
    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
        {
            elev[i][j] = auxMt[i][j];
            auxMt[i][j] = 0;
        }
}

void printMatrix(ull mt[lim][lim] ,int d)
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
            cout << mt[i][j] << " ";
        cout << endl;
    }
}

// Binary Exponentiation of the Static Matrix B
void binPow(ull b[lim][lim], ll ex, int d)
{
    if(ex == 1)
        return;

    if(ex == 0)
    {
        for(int i = 0; i < d; i++)
            for(int j = 0; j < d; j++)
            {
                b[i][j] = 0;
                if(i == j)
                    b[i][j] = 1;
            }
        return;
    }

    binPow(b, ex / 2, d);

    multiply(b, d);

    if(ex % 2 == 1)
        multiply(base, d);
}

// >> MATRIX EXPNENTIATION - Fixed Memory


int activeBits(int x)
{
    int cnt = 0;
    while(x > 0)
    {
        if(x&1)
            cnt++;
        x >>= 1;
    }
    return cnt;
}

// check whether 2 configurations (in binary) are adjacents
bool check(int x, int y)
{
    bool arr[7];
    fill(arr, arr+7, 0);
	// matched
    int mtch = 0;
    for(int i = 0; i < 7; i++)
    {
        bool ok = false;
        // if ith bit active
        if((x&(1<<i)))
        {
            // if not the top left
            if(i > 0)
            {
                if(!arr[i-1] && (y&(1<<(i-1))))
                {
                    arr[i-1] = true;
                    ok = true;
                    mtch++;
                }
            }
			// if not top right and still not matched
            if(i < 7 && !ok)
            {
                if(!arr[i+1] && (y&(1<<(i+1))))
                {
                    arr[i+1] = true;
                    ok = true;
                    mtch++;
                }
            }
        }
    }
    // return if all matched
    return mtch == 4;
}

string toBinary(int x)
{
    string ret = "";
    while(x > 0)
    {
        if(x&1)
            ret = "1" + ret;
        else ret = "0" + ret;
        x >>= 1;
    }
    return ret;
}
// each configuration in binary
vector<int> config;

void solve()
{
	// add every possible configuration
    for(int i = 0; i < 128; i++)
        if(activeBits(i) == 4)
            config.push_back(i);

    // set the base with each pair of adjacent configurations
    for(int i = 0; i < config.size(); i++)
    {
        for(int j = 0; j < config.size(); j++)
        {
            if(check(config[i], config[j]))
                base[i][j] = 1;
        }
    }

    // vector for solution
    int vm[35];

    sf("%d", &tc);
    for(int cs = 1; cs <= tc; cs++)
    {
        // read N
        sf("%d", &N);

		
        int maskConf = 0; // mask of the initial config
        int x; // auxiliar value
        for(int i = 0; i < 7; i++)
        {
            // reading
            sf("%d", &x);
            // adding to the mask which represents the initial config
            if(x != 0)
                maskConf |= (1<<(6-i));
        }

        // reset all
        memset(vm, 0, sizeof vm);
        memset(elev, 0, sizeof elev);
        memset(auxMt, 0, sizeof auxMt);
        memcpy(elev, base, sizeof elev);

        // checking which configuration is the initial among all
        for(int i = 0; i < config.size(); i++)
        {
            if(config[i] == maskConf)
            {
                vm[i] = 1;
                break;
            }
        }

        // elevate the matrix
        binPow(elev, N - 1, 35);

        ll answ = 0;
        for(int i = 0; i < 35; i++)
        {
            for(int j = 0; j < 35; j++)
                answ = (answ + (elev[i][j] * vm[j]) % mod) % mod;
        }
        // print answer
        pf("Case %d: %lld\n", cs, answ);
    }
}

void fastIO()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
}

void IO()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
	}
	else if(fopen("/media/luismo/Pablo's Destruction/lmo.in","r") != NULL)
	{
		freopen("/media/luismo/Pablo's Destruction/lmo.in", "r", stdin);
	}
}

int main()
{
	solve();
}
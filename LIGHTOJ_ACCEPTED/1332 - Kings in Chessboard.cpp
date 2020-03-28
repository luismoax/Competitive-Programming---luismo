/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1332 - Kings in Chessboard
	Online Judge: LightOJ
	Idea: Beautiful Problem. Matrix Exponentiation
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define uint unsigned int
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
const int lim = 36;

int tc;
ll N;

// >> MATRIX EXPNENTIATION - Fixed Memory
uint base[lim][lim];
uint elev[lim][lim];
uint auxMt[lim][lim];

// multiply by another square matrix of the same dimension
// using auxMt as an auxiliar Matrix
void multiply(uint mt[lim][lim], int d)
{
    //
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            for(int k = 0; k < d; k++)
            {
                auxMt[i][j] = ((elev[i][k] * mt[k][j])
                            + auxMt[i][j]);
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

void printMatrix(uint mt[lim][lim] ,int d)
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
            cout << mt[i][j] << " ";
        cout << endl;
    }
}

// Binary Exponentiation of the Static Matrix B
void binPow(uint b[lim][lim], ll ex, int d)
{
    if(ex == 0 || ex == 1)
        return;

    binPow(b, ex / 2, d);

    multiply(b, d);

    if(ex % 2 == 1)
        multiply(base, d);
}

// >> MATRIX EXPNENTIATION - Fixed Memory


string toBinary(int x)
{
    string ret = "";
    while(x > 0)
    {
        ret = (char)((x%2) + '0') + ret;
        x/=2;
    }
    return ret;
}

// to store possible configurations in an integer (as its binary representation)
vector<int> vbin;
void processBinary()
{
    for(int i = 0; i < 10; i++)
    {
        int aux = (1<<i);
        for(int j = i + 2; j < 10; j++)
            vbin.push_back(aux | (1<<j));
    }
}

// checks whether two configurations (binary x and binary y) can form a transition
bool valid(int x, int y)
{
    if((x&y) > 0)
        return false;
    if((x&(y>>1)) > 0)
        return false;
    if((x&(y<<1)) > 0)
        return false;
    return true;
}


void solve()
{
    processBinary();
	
	// fill the vector with the binary configurations
    for(int i = 0; i < vbin.size(); i++)
    {
        for(int j = i + 1; j < vbin.size(); j++)
        {
            if(valid(vbin[i], vbin[j]))
            {
                base[i][j] = base[j][i] = 1;
            }
        }
    }

    int cs = 1;
    sf("%d", &tc);
    while(tc-->0)
    {
        sf("%lld", &N);
	
		// reset matrices
        memset(elev, sizeof elev, 0);
        memset(auxMt, sizeof auxMt, 0);
		// copy the base to the matrix for elevation
        memcpy(elev, base, sizeof elev);        
		
		// elevate the matrix (not rise ELEVATE)
        binPow(elev, N - 1, lim);
		
		// to store answer
        uint answ = 0;
        for(int i = 0; i < lim; i++)
            for(int j = 0; j < lim; j++)
                answ = (answ + elev[i][j]);
        // since I don't have an identity matrix
        if(N == 1)
            answ = 36;

        pf("Case %d: ", cs++);
        pf("%lld\n", answ);
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
	// IO();

	//fastIO();

	solve();
}
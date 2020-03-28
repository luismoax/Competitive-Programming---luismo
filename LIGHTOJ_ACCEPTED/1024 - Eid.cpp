/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 1024 - Eid
	Online Judge: LightOJ
	Idea: Find LCM. Prime Decomposition. Multiplicative Function
	*** I used a third party code to multiply 2 strings ***
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
const int mod = 1e9 + 7;
const int lim = 1e7 + 2;

int tc, n, x;

string toString(int xx) {
    string ret = "";
    while(xx > 0)
    {
        ret = (char)((xx%10) + '0') + ret;
        xx /= 10;
    }
    return ret;
}

int sieve[10003];
void buildSeive(){
    for(int i = 2; i < 10003; i += 2) sieve[i] = 2;
    for(int i = 3; i < 10003; i += 2){
        if(sieve[i] == 0){
            for(int j = i; j < 10003; j+= i)
                sieve[j] = i;
        }
    }
}

map<int, int> lcm;
map<int, int> m;

// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
    return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
    return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
        s += (char)(result[i--] + '0');

    return s;
}

string binPow(string x, ll e)
{
    if(e == 0) return  "1";
    if(e == 1) return x;
    string aux = binPow(x, e / 2);
    aux = multiply(aux, aux);
    if(e&1)
        aux = multiply(aux, x);
    return aux;
}


void solve()
{
    buildSeive();
    sf("%d", &tc);
    int cs = 1;
    while(tc -- > 0)
    {
        lcm.clear();
        sf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            sf("%d", &x);
            // decompose
            int k = x;
            m.clear();
            while(k > 1)
            {
                m[sieve[k]]++;
                k /= sieve[k];
            }
            for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
                lcm[it->first] = max(it->second, lcm[it->first]);
        }

        string answ = "1";
        for(map<int, int>::iterator it = lcm.begin(); it != lcm.end(); it++)
        {
            answ = multiply(answ, binPow(toString(it->first), it->second));
        }
        pf("Case %d: ", cs++);
        pf("%s", answ.c_str());
        pf("\n");
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

	//fastIO();

	solve();
}
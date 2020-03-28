/*
    Author: Luis Manuel Díaz Barón (LUISMO)
    Problem: 3279 - Grounded I
    Online Judge: COJ
    Idea: Bitmask level 1
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int mod = 1000000007;
ll answ[10][10];
int N, K;

vector<string> vect[5];

void preprocess()
{
	// 1
	vect[1].push_back("0");
	vect[1].push_back("1");

	// 2
	vect[2].push_back("00");
	vect[2].push_back("01");
	vect[2].push_back("10");
	vect[2].push_back("11");

	// v3
	vect[3].push_back("000");
	vect[3].push_back("001");
	vect[3].push_back("010");
	vect[3].push_back("011");
	vect[3].push_back("100");
	vect[3].push_back("101");
	vect[3].push_back("110");
	vect[3].push_back("111");

	// v4
	vect[4].push_back("0000");
	vect[4].push_back("0001");
	vect[4].push_back("0010");
	vect[4].push_back("0011");
	vect[4].push_back("0100");
	vect[4].push_back("0101");
	vect[4].push_back("0110");
	vect[4].push_back("0111");
	vect[4].push_back("1000");
	vect[4].push_back("1001");
	vect[4].push_back("1010");
	vect[4].push_back("1011");
	vect[4].push_back("1100");
	vect[4].push_back("1101");
	vect[4].push_back("1110");
	vect[4].push_back("1111");

}

string XOR(string a, string b)
{
	string ret = "";
	int len = a.length();
	for(int i = 0; i < len; i++)
		ret+= ((a[i] - '0') ^ (b[i] - '0')) + '0';
	return ret;
}

int mask[100];

void rec(int n, int idx)
{
	// base
	if(idx == vect[n].size())
	{
		string aux = "";
		// reading the mask
		for(int i = 0; i < vect[n].size(); i++)
		{
			if(mask[i])
			{
				if(aux == "")
					aux = vect[n][i];
				else aux = XOR(aux, vect[n][i]);
			}
		}

		if(aux == "")
			answ[n][0]++;
		else
		{
			int ones = 0;
			for(int i = 0; i < aux.length(); i++)
				if(aux[i] == '1') ones++;
			// increase
			answ[n][ones]++;
		}
		return;
	}

	mask[idx] = 0;
	rec(n, idx + 1);
	mask[idx] = 1;
	rec(n, idx + 1);
}

void preprocess2()
{
	for(int i = 1; i <= 4; i++)
		rec(i, 0);
}

void solve()
{
	preprocess();
	preprocess2();

	while(cin >> N >> K)
		cout << answ[N][K] << "\n";
}

void open_file()
{
    // freopen("//media//Trabajo//lmo.in","r",stdin);
	freopen("e:\\lmo.in","r",stdin);
	// freopen("e:\\lmo.out","w",stdout);
}

int main()
{
   // open_file();

    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
}

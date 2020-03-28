/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem: 3590 - Gambling With Anders III
	Online Judge: COJ
	Idea:
*/
#include<bits/stdc++.h>
// Types
#define ll long long
#define ull unsigned long long
// IO
#define sf scanf
#define pf printf

using namespace std;

const int lim = 1e6 + 7;

int N, T, A, P;
string alph;
char str[100];


void check()
{
	cin >> N >> alph >> T;
	// checking N is on the range
	assert(N >= 1 && N <= 36);
	// check length of the string matches N
	assert(alph.length() == N);
	// T
	assert(T >= 1);

	// reading queries
	for(int i = 0; i < T; i++)
	{
		// checking range
		cin >> A >> P;
		assert(A >= 0 && A <= 1000000);
		assert(P >= 0 && P <= 1000000);
	}

}

void solve()
{
	//cin >> N >> alph >> T;
	sf("%d", &N);
	sf("%s", str);
	sf("%d", &T);

	//int len = alph.length(); // length
	int len = strlen(str);

	int rot = 0;
	// reading queries
	for(int i = 0; i < T; i++)
	{
		//cin >> A >> P;
		sf("%d%d", &A, &P);
		A %= len;
		P %= len;
		rot+= (A - P + len) % len;
	}

	// printing alhp
	for(int i = 0; i < len; i++)
		//cout << alph[(i + rot) % len];
		pf("%c", str[(i + rot) % len]);
}


string rotate(string str, int k, bool dir)
{
	string ret = "";

	if(dir) // left
		k = (-(k % str.length()) + str.length()) % str.length();
	else
		k = k % str.length();

	for(int i = 0; i < str.length(); i++)
		ret+= str[(i + k)%str.length()];
	return ret;
}

void solveBrute()
{
	cin >> N >> alph >> T;

	int len = alph.length(); // length

	int rot = 0;
	// reading queries
	for(int i = 0; i < T; i++)
	{
		cin >> A >> P;

		alph = rotate(alph, A, false);
		alph = rotate(alph, P, true);
	}

	cout << alph;
}



void rotate1Right(int len)
{
	str[len] = str[0];
	for(int i = 0; i < len; i++)
		str[i] = str[i + 1];
}
string rotate1Left(int len)
{
	str[len] = str[len - 1];
	for(int i = len - 1; i > 0; i--)
		str[i] = str[i - 1];
	str[0] = str[len];
}

void solveBruteII()
{
	cin >> N >> alph >> T;
	int len = alph.length();
	for(int i = 0; i < len; i++)
		str[i] = alph[i];

	// reading queries
	for(int i = 0; i < T; i++)
	{
		cin >> A >> P;
		for(int i = 0; i < A; i++)
			rotate1Right(len);
		for(int i = 0; i < P; i++)
			rotate1Left(len);
	}
	for(int i = 0; i < len; i++)
		cout << str[i];
}

int main()
{	
	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
	//check();
	//solveBruteII();
}

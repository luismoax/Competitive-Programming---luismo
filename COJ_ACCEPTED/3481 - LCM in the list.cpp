/*
	Author: Luis Manuel Díaz Barón (LUISMO)
	Problem:
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

const int lim = 1e4 + 7;
const int mod = 1e9 + 7;

vector<ll> primePowers[100];

vector<int> primes;

// generate all primenumbers below 100
bool sieve[101];
void preprocess()
{
	int mxx = 101;

	sieve[0] = sieve[1] = true;
	// prime number TWO
	primes.push_back(2);
	for(int i = 4; i < mxx; i+=2)
		sieve[i] = true;
	// adding powers of two
	primePowers[2].push_back(1);
	for(int p = 1; p <= 6; p++)
		primePowers[2].push_back(primePowers[2][p - 1] * 2);

	for(int i = 3; i < mxx; i+= 2)
	{
		// if not marked -> IS PRIME
		if(!sieve[i])
		{
			// process prime i
			primes.push_back(i);
			primePowers[i].push_back(1);
			for(int p = 1; p <= 6; p++)
				primePowers[i].push_back(primePowers[i][p - 1] * i);

			for(int j = i * i; j < mxx; j+= i)
				sieve[j] = true;
		}
	}



/*
	int cnt = 0;
	// print sieve
	for(int i = 0; i < mxx; i++)
		if(!sieve[i])
		{
			cout << i;

			cout << ": ";

			for(int p = 0; p < primePowers[i].size(); p++)
				cout << primePowers[i][p] << " ";

			cout << endl;

			cnt++;
		}

	cout << "Total: " << cnt << endl;
*/

}


int arr[lim], N, Q, a, b; // array of values
char c;

// SEGMENT TREE
int QL, QR;
struct node
{
	int powers[25];
	node(){}
} t[lim << 2];

inline int ls(int idx){return (idx << 1) + 1;}
inline int rs(int idx){return (idx << 1) + 2;}

void printNode(int idx, int L, int R)
{
	cout << "[" << L << ", " << R << "]: ";
	for(int i = 0; i < 25; i++)
		cout << t[idx].powers[i] << " ";

	cout << "\n";
}


void buildTree(int idx, int L, int R)
{
	memset(t[idx].powers, 0, sizeof t[idx].powers);
	// if leaf
	if(L == R)
	{
		// decompose in primes
		int aux = arr[L];
		while(aux % 2 == 0)
		{
			t[idx].powers[0]++;
			aux /= 2;
		}

		for(int p = 1; p < primes.size(); p++)
			while(aux % primes[p] == 0)
			{
				t[idx].powers[p]++;
				aux /= primes[p];
			}

		//printNode(idx, L, R);

		return;
	}

	int mid = (L + R) >> 1;
	int le = ls(idx), ri = rs(idx);
	// build both subtrees
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);

	// merge solution
	for(int i = 0; i < 25; i++)
		t[idx].powers[i] = max(t[le].powers[i], t[ri].powers[i]);

	//printNode(idx, L, R);
}

void update(int idx, int L, int R, int ii, int upd)
{
	// if leaf
	if(L == R)
	{
		memset(t[idx].powers, 0, sizeof t[idx].powers);
		arr[L] = upd;
		// decompose in primes
		int aux = arr[L];
		while(aux % 2 == 0)
		{
			t[idx].powers[0]++;
			aux /= 2;
		}

		for(int p = 1; p < primes.size(); p++)
			while(aux % primes[p] == 0)
			{
				t[idx].powers[p]++;
				aux /= primes[p];
			}

		return;
	}

	int mid = (L + R) >> 1;
	int le = ls(idx), ri = rs(idx);

	if(ii <= mid)
		update(le, L, mid, ii, upd);
	else update(ri, mid + 1, R, ii, upd);

	// merge solution
	// merge solution
	for(int i = 0; i < 25; i++)
		t[idx].powers[i] = max(t[le].powers[i], t[ri].powers[i]);
}

vector<int> retrieve(int idx, int L, int R)
{
	vector<int> ret;
	for(int i = 0; i < 25; i++)
		ret.push_back(0);

	// if contained
	if(L >= QL && R <= QR)
	{
		for(int i = 0; i < 25; i++)
			ret[i] = t[idx].powers[i];
		return ret;
	}
	// if not contained
	if(L > QR || R < QL)
		return ret;

	int mid = (L + R) >> 1;
	int le = ls(idx), ri = rs(idx);

	vector<int> fromLeft = retrieve(le, L, mid);
	vector<int> fromRight = retrieve(ri, mid + 1, R);

	// merge solution
	for(int i = 0; i < 25; i++)
		ret[i] = max(fromLeft[i], fromRight[i]);
	return ret;
}



void solve()
{
	preprocess();

	cin >> N;
	// reading integers
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	// build Segment Tree
	buildTree(0, 0, N - 1);

	cin >> Q;
	// reading queries
	for(int i = 0; i < Q; i++)
	{
		cin >> c >> a >> b;

		if(c == 'Q')
		{
			a--; b--;
			QL = a; QR = b;
			vector<int> result = retrieve(0, 0, N - 1);

			ll answ = 1;

			for(int i = 0; i < result.size(); i++)
				if(result[i] > 0)
				{
					int exp = result[i];
					ll pw = primePowers[primes[i]][exp];

					pw %= mod;

					answ = (answ * pw) % mod;
				}

			cout << answ % mod << "\n";

		}
		else
		{
			a--;
			update(0, 0, N - 1, a, b);
		}
	}

}

int main()
{
	if(fopen("d:\\lmo.in","r") != NULL)
	{
		freopen("d:\\lmo.in","r",stdin);
		// freopen("d:\\lmo.out","w",stdout);
	}
	cin.sync_with_stdio(false);
	cin.tie(0);

	solve();
}

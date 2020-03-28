// Solved During a Contest
// Use a Heap

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int lim = 500 + 7;

struct door
{
	int stars, superBoss;
	int current;
	door(){}

	bool operator < (const door & other) const
	{
		return current > other.current;
	}
};
door arr[1007];

int tc, N;

priority_queue<door> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> tc;
	while(tc--)
	{
		cin >> N;




		for(int i = 0; i < N; i++)
		{
			cin >> arr[i].stars >> arr[i].superBoss;
			arr[i].current = arr[i].stars;

			q.push(arr[i]);
		}

		int totalStars = 0;
		int asked = 0;

		while(q.size() > 0)
		{
			// take the top
			door t = q.top();
			q.pop();
			// if if the first door
			if(t.current == t.stars)
			{
				if(t.current > totalStars)
				{
					asked+= t.current - totalStars;
					totalStars = t.current;
				}
				// update the current
				t.current = t.superBoss;
				t.stars = -1;
				// insert in the queue
				q.push(t);

				totalStars++;
			}
			else if(t.current == t.superBoss)
			{
				if(t.current > totalStars)
				{
					asked+= t.current - totalStars;
					totalStars = t.current;
					// let this door go
				}
				totalStars+= 2;
			}
		}
		cout << asked << " \n";
	}
}

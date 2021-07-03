#include <bits/stdc++.h>
#define ll long long

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'nonDivisibleSubset' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY s
 */

// Idea: For two different complementary remainders get the one with most frequency
int nonDivisibleSubset(int K, vector<int> s) {
    
    int N = (int)s.size();
    map<ll, ll> m;
    for(int i = 0; i < N; i++)
    {        
        m[s[i] % K]++;
    }

    ll answ = 0;
    for(auto item: m)
    {
        ll val = item.first;

        if(val == 0)
        {
            answ = 1;
            continue;
        }            

        if(K % 2 == 0 && val == K / 2)
        {
            answ++;
            continue;
        }

        if(m.find(K - val) != m.end())
        {
            if(val <= K / 2)
            {
                ll add = max(m[val], m[K - val]);
                answ += add;
            }
        }
        else
        {
            answ += m[val];
        }        
    }
    return answ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s_temp_temp;
    getline(cin, s_temp_temp);

    vector<string> s_temp = split(rtrim(s_temp_temp));

    vector<int> s(n);

    for (int i = 0; i < n; i++) {
        int s_item = stoi(s_temp[i]);

        s[i] = s_item;
    }

    int result = nonDivisibleSubset(k, s);

    fout << result << "\n";

    fout.close();

    return 0;
}


string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

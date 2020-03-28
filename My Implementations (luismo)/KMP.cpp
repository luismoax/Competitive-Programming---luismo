// >> KMP
// Prefix Function
vector<int> PrefixFunction(string pattern)
{
	vector<int> pi (pattern.size(), 0);
	int matched = 0;
	for(int i = 1; i < pattern.size(); i++)
	{
		while(pattern[matched] != pattern[i] && matched > 0)
			matched = pi[matched - 1];
		
		if(pattern[matched] == pattern[i])
			matched++;

		pi[i] = matched;
	}
	return pi;
}


vector<int> KMP(string pattern, string text)
{
	// value of the predfix function
	vector<int> pi = PrefixFunction(pattern);
	// indexes of shifts
	vector<int> ret;

	int matched = 0;
	for(int i = 0; i < text.size(); i++)
	{
		while(text[i] != pattern[matched] && matched > 0)
			matched = pi[matched - 1];
		
		if(text[i] == pattern[matched])
			matched++;

		if(matched == pattern.size())
		{
			ret.push_back(i - matched + 1);
			matched = pi[pattern.size() - 1];
		}
	}
	return ret;
}
// << KMP
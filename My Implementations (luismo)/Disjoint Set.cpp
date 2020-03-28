struct DisjointSet
{
	vector<int> ds;
	DisjointSet(int len)
	{
		ds.resize(len, -1);
	}

	int setOf(int idx)
	{
		if(ds[idx] < 0)
			return idx;
		ds[idx] = setOf(ds[idx]);
		return ds[idx];
	}

	void merge(int a, int b)
	{
		int stA = setOf(a);
		int stB = setOf(b);
		if(ds[stA] < ds[stB])
		{
			ds[stA] += ds[stB];
			ds[stB] = stA;
		}
		else
		{
			ds[stB] += ds[stA];
			ds[stA] = stB;
		}		
	}
};
// >> RMQ - Sparse Table
int arr[lim]; // array with values
int sparseTable[lim][int(log2(lim) + 1)];

void buildTable()
{
	for(int i = 0; i < n; i++)
		sparseTable[i][0] = arr[i];

	for(int j = 1; (1<<j) <= n; j++)
	{
		for(int i = 0; i + (1<<j) - 1 < n; i++)
		{
			sparseTable[i][j] = min(sparseTable[i][j-1], sparseTable[i + (1 << (j - 1))][j-1]);
		}
	}
}

int query(int a, int b)
{
	int len = b - a + 1;
	int lg = log2(len);
	return min( sparseTable[a][lg], sparseTable[b - (1<<lg) + 1][lg] );
}
// << RMQ - Sparse Table

struct matrix
{
    int row, col;
    ll ** mt;
    matrix(int r, int c)
    {
        row = r;
        col = c;
        mt = new ll * [r];
        for(int i = 0; i < row; i++)
        {
            mt[i] = new ll[col];
            for(int j = 0; j < col; j++)
                mt[i][j] = 0;
        }
    }
    matrix(){}

    matrix operator * (matrix other)
    {
        matrix ret = matrix(row, other.col);
        for(int i = 0; i < ret.row; i++)
        {
            for(int j = 0; j < ret.col; j++)
            {
                for(int k = 0; k < other.row; k++)
                    ret.mt[i][j] = (ret.mt[i][j] +
                                    (this->mt[i][k] * other.mt[k][j]) % mod
                                     ) % mod;
            }
        }
        return ret;
    }

    void printMatrix()
    {
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                cout << mt[i][j] << " ";
            cout << endl;
        }
    }
};

matrix identity(int d)
{
    matrix ret = matrix(d, d);
    for(int i = 0; i < d; i++)
        ret.mt[i][i] = 1;
    return ret;
}

matrix powBin(matrix b, ll exp)
{
    if(exp == 0)
        return identity(b.row);

	matrix ret = identity(b.row);
	matrix aux = b;
	while(exp > 0)
	{
		if(exp % 2 == 1)
			ret = (aux * ret);		
		aux = (aux * aux);		
		exp >>= 1;
	}
	return ret;
}
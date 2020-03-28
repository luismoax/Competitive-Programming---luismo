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
// identity matrix (needs to be instanciated)
matrix iden;

matrix binPow(matrix b, ll ex)
{
    if(ex == 0)
        return iden;
    if(ex == 1)
        return b;
    matrix aux = binPow(b, ex / 2);
    aux = aux * aux;
    if(ex % 2 == 1)
        aux = aux * b;
    return aux;
}
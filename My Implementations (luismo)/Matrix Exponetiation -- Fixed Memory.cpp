// >> MATRIX EXPNENTIATION - Fixed Memory
ull base[lim][lim];
ull elev[lim][lim];
ull auxMt[lim][lim];

// multiply elev by another square matrix of the same dimension
// using auxMt as an auxiliar Matrix
void multiply(ull mt[lim][lim], int d)
{
    //
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
        {
            for(int k = 0; k < d; k++)
            {
                auxMt[i][j] = ((elev[i][k] * mt[k][j]) % mod
                            + auxMt[i][j]) % mod;
            }
        }
    }
    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
        {
            elev[i][j] = auxMt[i][j];
            auxMt[i][j] = 0;
        }
}

void printMatrix(ull mt[lim][lim] ,int d)
{
    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d; j++)
            cout << mt[i][j] << " ";
        cout << endl;
    }
}

// Binary Exponentiation of the Static Matrix B
void binPow(ull b[lim][lim], ll ex, int d)
{
    if(ex == 1)
        return;
	// return identity
    if(ex == 0)
    {
        for(int i = 0; i < d; i++)
            for(int j = 0; j < d; j++)
            {
                b[i][j] = 0;
                if(i == j)
                    b[i][j] = 1;
            }
        return;
    }

    binPow(b, ex / 2, d);

    multiply(b, d);

    if(ex % 2 == 1)
        multiply(base, d);
}

// >> MATRIX EXPNENTIATION - Fixed Memory
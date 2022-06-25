
struct SegmentTreeGCD
{
    vector<ll> gcd;
    int sz;
    SegmentTreeGCD(vector<ll> &arr)
    {
        sz = arr.size();
        gcd.resize(sz << 2);
        buildTree(0, 0, sz - 1, arr);       
    }

    void buildTree(int idx, int L, int R, vector<ll> &arr)
    {
        if(L == R)
        {
            gcd[idx] = arr[L];            
            return;
        }
        int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
        buildTree(le, L, mid, arr);
        buildTree(ri, mid + 1, R, arr);
        // merge
        gcd[idx] = __gcd(gcd[le], gcd[ri]);
    }

    void update(int ii, ll upd)
    {
        update(0, 0, sz - 1, ii, upd);
    }

    void update(int idx, int L, int R, int ii, ll upd)
    {
        int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
        if(L == R)
        {
            gcd[idx] = upd;
            return;
        }
        if(ii <= mid)
            update(le, L, mid, ii, upd);
        else
            update(ri, mid + 1, R, ii, upd);
        // merge
        gcd[idx] = __gcd(gcd[le], gcd[ri]);
    }

    ll retrieve(int QL, int QR)
    {
        return retrieve(0, 0, sz - 1, QL, QR);
    }

    ll retrieve(int idx, int L, int R, int QL, int QR)
    {
        int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
        if(L >= QL && R <= QR)
            return  gcd[idx];

        if(L > QR || R < QL)
            return 0;
        
        ll g1 = retrieve(le, L, mid, QL, QR);
        ll g2 = retrieve(ri, mid + 1, R, QL, QR);

        ll ret = 0;
        if(g1 == 0)
            ret = g2;
        else if(g2 == 0)
            ret = g1;
        else ret = __gcd(g1, g2);
        return ret;
    }
};


// MIN / MAX SegmentTree - Point Update

int mx[lim << 2];
int mn[lim << 2];

void update(int idx, int L, int R, int ii, int upd)
{
    if(L == R)
    {
        mx[idx] = mn[idx] = upd;
        return;
    }
    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
    if(ii <= mid)
        update(le, L, mid, ii, upd);
    else update(ri, mid + 1, R, ii, upd);
    // merge
    mx[idx] = max(mx[le], mx[ri]);
    mn[idx] = min(mn[le], mn[ri]);
}

pii retrieve(int idx, int L, int R, int QL, int QR)
{
    if(L >= QL && R <= QR)
        return mkp(mx[idx], mn[idx]);

    if(L > QR || R < QL)
        return mkp(-1, mod + 59);

    int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;

    pii s1 = retrieve(le, L, mid, QL, QR);
    pii s2 = retrieve(ri, mid + 1, R, QL, QR);
    // merge
    pii ret = mkp(max(s1.first, s2.first), min(s1.second, s2.second));
    return ret;
}

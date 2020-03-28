
struct SegmentTree
{
	vector<int> tsum;
	vector<int> lazy;
	SegmentTree(){}
	SegmentTree(int len)
	{
		tsum.resize(len << 2, 0);
		lazy.resize(len << 2, 0);
	}

	void propagate(int idx, int L, int R)
	{
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
        // download
		tsum[idx] += (R - L + 1) * lazy[idx];
        // if not leaf push down
		if(L != R)
		{
			lazy[le] += lazy[idx];
			lazy[ri] += lazy[idx];
		}
		lazy[idx] = 0;
	}

	void update(int idx, int L, int R, int QL, int QR, int upd)
	{
		// pointers
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		// first of all propagate
		propagate(idx, L, R);
		if(L > QR || R < QL)
			return;
		if(L >= QL && R <= QR)
		{
			tsum[idx] += (R - L + 1) * upd;
			if(L != R)
			{
				lazy[le] += upd;
				lazy[ri] += upd;
			}
			return;
		}
        // update both subtrees
		update(le, L, mid, QL, QR, upd);
		update(ri, mid + 1, R, QL, QR, upd);
		// merge
		tsum[idx] = tsum[le] + tsum[ri];
	}

	int retrieve(int idx, int L, int R, int QL, int QR)
	{		
		// pointers
		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
		// first of all propagate
		propagate(idx, L, R);
		// if outside
		if(L > QR || R < QL)
			return 0;
		// if inside
		if(L >= QL && R <= QR)
			return tsum[idx];
		int sLe = retrieve(le, L, mid, QL, QR);
		int sRi = retrieve(ri, mid + 1, R, QL, QR);
		return sLe + sRi;
	}
};

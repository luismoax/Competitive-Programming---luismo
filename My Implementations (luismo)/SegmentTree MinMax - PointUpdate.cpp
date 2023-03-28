// MIN / MAX SegmentTree - Point Update
struct SegmentTree
{

	vector<ll> mx;
	vector<ll> mn;
	int SZ;

	SegmentTree(int len)
	{
		SZ = len;
		mx.resize(len << 2 + 3, 0);
		mn.resize(len << 2 + 3, 0);
	}

	void update(int ii, ll upd)
	{
		update(0, 0, SZ - 1, ii, upd);
	}

	void update(int idx, int L, int R, int ii, ll upd)
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

	pll retrieve(int QL, int QR)
	{
		return retrieve(0, 0, SZ - 1, QL, QR);
	}

	pll retrieve(int idx, int L, int R, int QL, int QR)
	{
		if(L >= QL && R <= QR)
			return mkp(mx[idx], mn[idx]);

		if(L > QR || R < QL)
			return mkp(-inf, inf);

		int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;

		pll s1 = retrieve(le, L, mid, QL, QR);
		pll s2 = retrieve(ri, mid + 1, R, QL, QR);
		// merge
		pll ret = mkp(max(s1.first, s2.first), min(s1.second, s2.second));
		return ret;
	}
};
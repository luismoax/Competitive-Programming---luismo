// >> SegmentTree
ll t[lim << 2];
ll lazyAdd[lim << 2];
ll lazySet[lim << 2];

void buildTree(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		t[idx] = arr[L];
		return;
	}
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	t[idx] = t[le] + t[ri];
}

void propagate(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(lazySet[idx] > 0)
	{
		t[idx] = (R - L + 1) * lazySet[idx];
		if(L != R)
		{
			// reset the add load
			lazyAdd[le] = lazyAdd[ri] = 0;
			// update the set load
			lazySet[le] = lazySet[idx];
			lazySet[ri] = lazySet[idx];
		}
	}
	else if(lazyAdd[idx] > 0)	
	{
		t[idx] += (R - L + 1) * lazyAdd[idx];
		// if not leaf
		if(L != R)
		{
			// if there is a set load increase it
			if(lazySet[le] > 0)
				lazySet[le] += lazyAdd[idx];
			// otherwise increase the add load
			else			
				lazyAdd[le] += lazyAdd[idx];

			// if there is a set load increase it
			if(lazySet[ri] > 0)
				lazySet[ri] += lazyAdd[idx];
			// otherwise increase the add load
			else			
				lazyAdd[ri] += lazyAdd[idx];
		}
	}
	// reset lazyness
	lazyAdd[idx] = lazySet[idx] = 0;
}

void updateSet(int idx, int L, int R, int QL, int QR, ll val)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	propagate(idx, L, R);

	// if outside
	if(L > QR || R < QL)
		return;
	
	// if contained
	if(L >= QL && R <= QR)
	{
		t[idx] = (R - L + 1) * val;
		if(L != R)
		{
			lazyAdd[le] = lazyAdd[ri] = 0;
			lazySet[le] = val;
			lazySet[ri] = val;
		}
		return;
	}

	updateSet(le, L, mid, QL, QR, val);
	updateSet(ri, mid + 1, R, QL, QR, val);
	// merge
	t[idx] = t[le] + t[ri];
}

void updateAdd(int idx, int L, int R, int QL, int QR, ll val)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	propagate(idx, L, R);

	// if outside
	if(L > QR || R < QL)	
		return;
	// if contained
	if(L >= QL && R <= QR)
	{
		t[idx] += (R - L + 1) * val;		
		
		if(L != R)
		{
			// if there is a set load increase it
			if(lazySet[le] > 0)
				lazySet[le] += val;
			// otherwise increase the add load
			else lazyAdd[le] += val;

			// if there is a set load increase it
			if(lazySet[ri] > 0)
				lazySet[ri] += val;
			// otherwise increase the add load
			else lazyAdd[ri] += val;
		}
		return;
	}
	updateAdd(le, L, mid, QL, QR, val);
	updateAdd(ri, mid + 1, R, QL, QR, val);
	// merge
	t[idx] = t[le] + t[ri];
}

ll retrieve(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	propagate(idx, L, R);

	// if outside
	if(L > QR || R < QL)
		return 0;
	
	// if contained
	if(L >= QL && R <= QR)	
		return t[idx];
	
	ll s1 = retrieve(le, L, mid, QL, QR);
	ll s2 = retrieve(ri, mid + 1, R, QL, QR);

	return s1 + s2;
}

// << SegmentTree
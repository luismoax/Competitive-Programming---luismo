// >> SEGMENT TREE - For Sub array sums
struct node
{
	ll sum; // sum of all values in the interval
	ll bestSum; // best sum of the interval
	ll bestLeft; // best sum of a prefix in the interval
	ll bestRight; // best sum of a sufix in the interval
 
	node(){sum = bestLeft = bestRight = bestSum = 0;}
	node(ll sm, ll bs, ll bl, ll br)
	{ sum = sm; bestSum = bs; bestLeft = bl; bestRight = br; }
};
node t[lim << 2];
 
node merge(node leNode, node riNode)
{
    node ret;
	ret.sum = leNode.sum + riNode.sum;
	ret.bestSum = max(leNode.bestSum, riNode.bestSum);
 
	if(leNode.bestRight + riNode.bestLeft > ret.bestSum)
		ret.bestSum = leNode.bestRight + riNode.bestLeft;
 
	ret.bestLeft = max(leNode.bestLeft, leNode.sum + riNode.bestLeft);
	ret.bestRight = max(riNode.bestRight, riNode.sum + leNode.bestRight);

	return ret;
}

void buildTree(int idx, int L, int R)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		t[idx] = node(arr[L], arr[L], arr[L], arr[L]);
		return;
	}
	buildTree(le, L, mid);
	buildTree(ri, mid + 1, R);
	// merge
	t[idx] = merge(t[le], t[ri]);
}
 
void update(int idx, int L, int R, int ii, int upd)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L == R)
	{
		arr[L] = upd;
		t[idx] = node(arr[L], arr[L], arr[L], arr[L]);
		return;
	}
	if(ii <= mid)
		update(le, L, mid, ii, upd);
	else 
		update(ri, mid + 1, R, ii, upd);
	// merge
	t[idx] = merge(t[le], t[ri]);
}

node retrieve(int idx, int L, int R, int QL, int QR)
{
	int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
	if(L >= QL && R <= QR)
		return t[idx];
	if(L > QR || R < QL)
		return node(-inf, -inf, -inf, -inf);

	node leNode = retrieve(le, L, mid, QL, QR);
	node riNode = retrieve(ri, mid + 1, R, QL, QR);

	if(riNode.sum == -inf)
		return leNode;
	if(leNode.sum == -inf)
		return riNode;

	node ret = merge(leNode, riNode);

	return ret;
}
// << SEGMENT TREE
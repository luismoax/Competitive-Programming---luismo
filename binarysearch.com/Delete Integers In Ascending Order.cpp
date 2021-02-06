#define pii pair<int, int>
#define mkp make_pair

struct SegmentTree
{
    vector<int> t;
    SegmentTree(int n)
    {
        t.resize(n * 4, 0);
    }
    
    void update(int idx, int L, int R, int ii, int upd)
    {
        int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
        if(L == R)
        {
            t[idx] += upd;
            return;
        }
        if(ii <= mid)
            update(le, L, mid, ii, upd);
        else update(ri, mid + 1, R, ii, upd);
        t[idx] = t[le] + t[ri];
    }

    int retrieve(int idx, int L, int R, int QL, int QR)
    {
        int le = idx * 2 + 1, ri = le + 1, mid = (L + R) / 2;
        if(L >= QL && R <= QR)
            return t[idx];
        if(L > QR || R < QL)
            return 0;
        int s1 = retrieve(le, L, mid, QL, QR);
        int s2 = retrieve(ri, mid + 1, R, QL, QR);
        return s1 + s2;
    }
};

vector<int> solve(vector<int>& nums) {
    vector<pii> v;
    for(int i = 0; i < nums.size(); i++)
    {
        v.push_back(make_pair(nums[i], i));
    }
    sort(v.begin(), v.end());

    int sz = nums.size() + 2;
    SegmentTree st = SegmentTree(sz);

    for(int i = 0; i < nums.size(); i++)
        st.update(0, 0, sz - 1, i, 1);

    vector<int> ret;

    for(auto item: v)
    {
        int idx = item.second;
        cout << idx << endl;
        int k = st.retrieve(0, 0, sz - 1, 0, idx);
        ret.push_back(k - 1);
        st.update(0, 0, sz - 1, idx, -1);
    }
    return ret;
}
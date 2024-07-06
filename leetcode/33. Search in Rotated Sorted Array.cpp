class Solution {
public:

    int BinarySearch(vector<int> &nums, int le, int ri, int k)
    {
        while(le < ri)
        {
            int mid = (le + ri) / 2;
            int v = nums[mid];
            if(k <= v)
                ri = mid;
            else
                le = mid + 1;
        }
        if(nums[le] == k)
            return le;
        return -1;
    }

    pair<int, int> SearchSpace(vector<int>& nums, int target, int le, int ri)
    {
        int mid = (le + ri) / 2;

        if(le == ri)
            return make_pair(le, ri);

        // left sorted half
        if(nums[le] < nums[mid] || le == mid)
        {
            if(target >= nums[le] && target <= nums[mid])
                return make_pair(le, mid);
            return SearchSpace(nums, target, mid + 1, ri);
        }
        // right sorted half
        if(nums[mid + 1] < nums[ri] || mid + 1 == ri)
        {
            if(target >= nums[mid + 1] && target <= nums[ri])
                return make_pair(le, ri);
            return SearchSpace(nums, target, le, mid);
        }

        return make_pair(0, 0);
    }

    int search(vector<int>& nums, int target)
    {
        pair<int, int> pp = SearchSpace(nums, target, 0, nums.size() - 1);
        
        int answ = BinarySearch(nums, pp.first, pp.second, target);

        return answ;
    }
};
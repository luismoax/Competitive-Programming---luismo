class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int answ = nums[nums.size() - 1];
        for(int i = 1; i < nums.size(); i+=2)
        {
            if(nums[i] != nums[i-1])
            {
                answ = nums[i-1];
                break;
            }
        }        
        return answ;
    }
};
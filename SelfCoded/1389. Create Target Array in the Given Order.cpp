class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> v(nums.size(),0);
        for(int i=0;i<nums.size();i++)
        {
            v.insert(v.begin()+index[i],nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            v.pop_back();
        }
        return v;
    }
};

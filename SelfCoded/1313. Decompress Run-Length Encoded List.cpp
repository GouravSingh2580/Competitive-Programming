class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        
        vector<int> v;
        for(int i=1;i<nums.size();i+=2)
        {
            while(nums[i-1])
            {
                v.push_back(nums[i]);
                --nums[i-1];
            }
        }
        return v;
    }
};

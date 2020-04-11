/*
Runtime: 564 ms, faster than 10.10% of C++ online submissions for Two Sum.
Memory Usage: 7 MB, less than 100.00% of C++ online submissions for Two Sum.
*/



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a=0;
        int b=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    a=i;
                    b=j;
                }
            }
        }
        return {a,b};
    }
};

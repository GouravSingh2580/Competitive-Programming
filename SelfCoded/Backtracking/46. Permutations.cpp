// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Idk why I love this solution of mine so much ;)

class Solution {
public:
    vector<vector<int>> v;
    void permut(vector<int> nums, int l, int r)
    {
        if(l==r) v.push_back(nums);
        else
        {
            for(int i=l;i<=r;i++)
            {
                swap(nums[l],nums[i]);
                
                permut(nums, l+1, r);
                
                swap(nums[l],nums[i]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permut(nums,0,nums.size()-1);
        return v;
    }
};

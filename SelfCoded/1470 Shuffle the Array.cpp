class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> v;
        v.push_back(nums[0]);
        int i=0;
        int x=1,y=1;
        for(int k=0;k<n;k++)
        {
            i=i+(n);
            v.push_back(nums[i]);
            i=i-(n-1);
            v.push_back(nums[i]);
        }
        v.pop_back();
        return v;
    }
};

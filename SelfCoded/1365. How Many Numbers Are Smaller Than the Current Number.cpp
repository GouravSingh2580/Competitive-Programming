class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int k=0;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            k=0;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]<nums[i] && j!=i)
                {
                    k++;
                }
            }
            v.push_back(k);
        }
        return v;
    }
};

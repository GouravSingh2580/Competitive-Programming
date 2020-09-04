class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int k=0;
        int z=0;
        for(int i=0;i<nums.size();i++)
        {
            k=0;
            while(nums[i])
            {
                nums[i]/=10;
                k++;
            }
            if(k%2==0)
            {
                z++;
            }
        }
        return z;
    }
};


/*
	15. 3Sum
	solution C++
	O(N-square)
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n= nums.size();
        if(n <3)
            return {};
        
        sort(nums.begin(), nums.end()); //for using two pointers technique
            
        for(int i=0; i<n-2; i++){
            //now using two pointers to find the second and third
            
            if(i >0 && nums[i] == nums[i-1])
                continue;
            int start = i+1, end= n-1;
            while(start < end){
                int sum = nums[i] + nums[start]+ nums[end];
                if(sum == 0)
                { ans.insert({nums[i],nums[start], nums[end]}); start +=1;}
                
                else if(sum > 0)
                    end -=1;
                else
                    start +=1;
               
            }
        }
        
        vector<vector<int>> yo;
        for(auto i= ans.begin(); i != ans.end(); i++)
            yo.push_back(*i);
        return yo;
    }
};

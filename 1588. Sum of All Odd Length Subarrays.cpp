class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int res=0;
        vector<int> v;
        for(int i=0;i<arr.size();i++)
        {
            v.clear();
            sum=0;
            for(int j=i;j<arr.size();j++)
            {
                v.push_back(arr[j]);
                sum+=arr[j];
                
                if(v.size()%2!=0) res+=sum;
            }
        }
        return res;
    }
};

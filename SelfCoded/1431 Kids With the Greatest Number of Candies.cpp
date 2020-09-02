class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int e) {
        vector<bool> v;
        
        for(int i=0;i<c.size();i++)
        {
            if(c[i]+e>=*max_element(c.begin(), c.end()))
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
        }
        return v;
    }
};

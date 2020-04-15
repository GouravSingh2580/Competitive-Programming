/*
Runtime: 44 ms, faster than 65.08% of C++ online submissions for Contains Duplicate.
Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Contains Duplicate.
*/




class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        sort(v.begin(), v.end());
        
        if(v.size()==0)
            return false;
        
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1])
            {
                return true;
            }
        }
        return false;
    }
};

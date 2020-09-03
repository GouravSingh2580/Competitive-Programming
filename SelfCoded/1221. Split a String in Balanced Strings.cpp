class Solution {
public:
    int balancedStringSplit(string s) {
        
        int res=0;
        int k=0;
        for(auto c:s)
        {
            res+=c=='L'?1:-1;
            if(res==0) k++;
        }
        return k;
    }
};

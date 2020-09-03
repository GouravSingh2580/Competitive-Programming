class Solution {
public:
    string restoreString(string s, vector<int>& in) {
        
        string z=s;
        
        for(int i=0;i<in.size();i++)
        {
            z[in[i]]=s[i];
        }
        return z;
    }
};

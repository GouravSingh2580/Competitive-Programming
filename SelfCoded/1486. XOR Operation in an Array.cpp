class Solution {
public:
    int xorOperation(int n, int start) {
        
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(start+2*i);
        }
        int k=0;
        for(int i=0;i<v.size();i++)
        {
            k^=v[i];
        }
        
        return k;
    }
};

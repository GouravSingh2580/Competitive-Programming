class Solution {
public:
    string defangIPaddr(string a) {
        
        string v;
        
        for(int i=0;i<a.size();i++)
        {
            if(a[i]=='.')
            {
                v.push_back('[');
                v.push_back(a[i]);
                v.push_back(']');
            }
            else
            {
                v.push_back(a[i]);
            }
        }
        return v;
    }
};

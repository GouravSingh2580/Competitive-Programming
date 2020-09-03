class Solution {
public:
    int subtractProductAndSum(int n) {
        int z=n;
        int x=n;
        int r=1;
        int m=0;
        while(z)
        {
            r*=z%10;
            z=z/10;
        }
        while(x)
        {
            m+=x%10;
            x=x/10;
        }
        return (r-m);
    }
};

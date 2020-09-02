class Solution {
public:
    int numberOfSteps (int num) {
        int k=0;
        while(num)
        {
            if(num%2==0)
            {
                num=num/2;
                k++;
            }
            else
            {
                num-=1;
                k++;
            }
        }
        return k;
    }
};

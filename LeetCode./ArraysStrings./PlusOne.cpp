class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int carryFwd = 0;
        vector<int> vtRes(digits.begin(), digits.end());
        auto rItr = vtRes.rbegin();
        
        while(rItr != vtRes.rend())
        {
            if(*rItr < 9)
            {
                ++(*rItr);
                carryFwd = 0;
                break;
            }
            else
            {
                *rItr = 0;
                carryFwd = 1;
            }
            ++rItr;
        }
        
        if(carryFwd == 1)
            vtRes.insert(vtRes.begin(), 1);
        
        return vtRes;
    }
};

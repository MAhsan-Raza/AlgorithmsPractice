class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> sNums;
        
        for(auto x : nums)
        {
            if(sNums.find(x) == sNums.end())
                sNums.insert(x);
            else    return true;
        }
        
        return false;
    }
};

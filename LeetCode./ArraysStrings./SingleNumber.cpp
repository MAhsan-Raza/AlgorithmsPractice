class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_set<int> sNums;
        
        for(auto x : nums)
        {
            if(sNums.find(x) != sNums.end())
                sNums.erase(x);
            else
                sNums.insert(x);
        }
        
        return *sNums.begin();
    }
};

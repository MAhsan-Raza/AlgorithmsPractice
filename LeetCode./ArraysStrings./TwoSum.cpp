class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> vRes;
        unordered_map<int, int> nMp;
        
        for(size_t i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            auto xitr = nMp.find(x);
            if(xitr != nMp.end())
            {
                vRes.push_back(xitr->second);
                vRes.push_back(i);
                break;
            }
            else
                nMp.insert(make_pair(target - x, i));
        }
        
        return vRes;
    }
};

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> vRes;
        unordered_map<int, int> sNums; // number vs its occurance
        
        for(auto x : nums1)
        {
            if(sNums.find(x) == sNums.end())
                sNums.insert(make_pair(x, 1));
            else    ++sNums[x];
        }
        
        for(auto x : nums2)
        {
            if(sNums.find(x) != sNums.end() && sNums[x] > 0)
            {
                vRes.push_back(x);
                --sNums[x];
            }
        }
        return vRes;
    }
};

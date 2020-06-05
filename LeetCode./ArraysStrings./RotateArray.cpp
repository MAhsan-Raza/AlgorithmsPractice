class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        if(nums.empty()) return;
        
        /*if (k > nums.size()) k = k - nums.size();
        
        int i=0;
        int tmp=nums[0];
        size_t j=0;
        size_t endIndx = nums.size() - 1;*/
        
        while(k--)
        {
            int tmp = *nums.rbegin();
            nums.pop_back();
            nums.insert(nums.begin(), tmp);
        }
    }
};

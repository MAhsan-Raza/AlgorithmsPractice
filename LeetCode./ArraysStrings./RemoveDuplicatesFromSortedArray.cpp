class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if(nums.size() <= 0) return 0;
        
        int jumpCount = 0;
        int last = nums[0];
        
        for(size_t i=1; i<nums.size(); i++)
        {
            if(nums[i] == last) // duplicate
                ++jumpCount;
            else
            {
                if(jumpCount != 0)
                    nums[i-jumpCount] = nums[i];
                last = nums[i];
            }
        }
        
        size_t nuSize = nums.size() - jumpCount;
        nums.resize(nuSize);
        return nuSize;
    }
};

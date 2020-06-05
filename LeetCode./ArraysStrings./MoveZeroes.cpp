class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int nZeros = 0;
        
        for(size_t i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                ++nZeros;
            else
            {
                nums[i - nZeros] = nums[i];
            }            
        }
        
        for(size_t i = nums.size() - nZeros; i < nums.size(); i++)
            nums[i] = 0;
    }
};

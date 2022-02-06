class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int minproduct= nums[0];  // for negative no
        int maxproduct= nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int temp = max(nums[i], max(maxproduct*nums[i], minproduct*nums[i]));
            
            minproduct = min(nums[i],min(maxproduct*nums[i],minproduct*nums[i]));  // negative no
            
            maxproduct =temp; // update it later for previous min we need previoous max 
            
            ans = max(ans ,maxproduct);
        }
        
        return ans;
    }
};

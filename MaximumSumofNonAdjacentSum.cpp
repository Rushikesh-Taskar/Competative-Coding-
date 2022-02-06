class Solution 
{
public:
    int helper(vector<int>nums )
    {
        // find max sum of non adjecent element in array 
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        
        vector<int>dp(n);  // n-1 entries 
        
        
        dp[0] =nums[0];
        dp[1] =nums[1];
        dp[2] =nums[2]+dp[0];
        
        for(int i=3;i<n ;i++)
        {
            dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
        }
        return max(dp[n-1],dp[n-2]);  
        
        
        
    }
    int rob(vector<int>& nums) 
    {
        
        // base case
        
       if(nums.size()==1)
        {
            return nums[0];
        }
        
        else if(nums.size()==2)
        {
            return max(nums[0],nums[1]);
        }
        
        
        return helper(nums);
        }
};

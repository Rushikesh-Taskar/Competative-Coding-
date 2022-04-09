class Solution 
{
public:
    vector<int> ans;
    int printlis(vector<int> nums ,int ind, int prev , int n , vector<vector<int>>& dp)
    {
        if(ind ==n)
        {
            return 0;
        }
        
        
        if(dp[ind][prev+1]!=-1)
        {
           return dp[ind][prev+1];
        }
        
        int len = printlis(nums,ind+1,prev,n,dp);
        
        if(prev==-1 || nums[ind]>nums[prev])
        {
          
            len = max(len , 1+printlis(nums , ind+1 ,ind ,n,dp));
           
        }
        
        return dp[ind][prev+1] =len;  // shift index 
    }
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> ans;
        
        //int n=nums.size();
        //vector<vector<int>> dp(n,vector<int>(n+1,-1));
        //int x=printlis(nums,0,-1,nums.size(),dp);
       
        
        for(int i=0;i<nums.size();i++)
        {
            auto it = lower_bound(ans.begin() ,ans.end() ,nums[i]);
            // uper bound if same eleemnt are allowed 7 7 7 7
            if(it==ans.end())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                *it = nums[i];
            }
        }
        return ans.size();
    }
};






// for printing hash array required 
class Solution 
{
public:
    
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int> len(n,1);
        vector<int> hash(n); // parent array
            
        int maxi=1;
        int last_ind=0;
        
       sort(nums.begin(),nums.end());  // every pair  answer[i], answer[j]) of elements in this subset satisfies:
        
        
       for(int i=0;i<n;i++)
       {
           hash[i]=i;
           
           for(int j=0;j<i;j++) // previous 
           {
               if(nums[j]<nums[i] && len[i] < 1+len[j])
               {
                   len[i]=1+len[j];
                   hash[i]=j;
                   
               }
               
           }
           
           if(len[i]>maxi)
           {
               maxi=len[i];
               last_ind=i;
           }
       }
        
        
        vector<int> ans;
        
       ans.push_back(nums[last_ind]);
        while(hash[last_ind]!=last_ind)
        {
            last_ind= hash[last_ind];
            ans.push_back(nums[last_ind]);
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

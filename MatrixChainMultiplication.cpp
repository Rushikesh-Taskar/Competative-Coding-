class Solution {
public:
     int minoperation(int i,int j ,vector<int>& arr,vector<vector<int>>& dp)
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        dp[i][j]=INT_MAX;
    
        for(int k=i;k<j;k++)
        {
            //left +right+current
            dp[i][j]=min(dp[i][j],minoperation(i,k ,arr,dp)+minoperation(k+1,j ,arr,dp)+
                                             arr[i-1]*arr[k]*arr[j]);
        }
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) 
    {   
        
        // problem is same as maxtix chain multiplication (mcm)
        // bacause adjacent side sharing one common edge between them which same as matrix 
        int n=values.size();
         vector<vector<int>>dp(n,vector<int>(n,-1));
         return minoperation(1,n-1 ,values,dp);
    }
};

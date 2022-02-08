// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int totalarray(int arr[] ,int i ,int sum,int n,vector<vector<int>>& dp)
	{
	   /* if(sum==0)
	    {
	        return 1;
	    }*/
	    
	    
	    if(i==0)
	    {
	        if(arr[i]==0 && sum==0)
	        {
	            return 2;
	        }
	        if(arr[i]==sum || sum==0)
	        {
	            return 1;
	        }
	        return 0;
	    }
	    if(dp[i][sum]!=-1)
	    {
	        return dp[i][sum];
	    }
	    int notpick= totalarray(arr,i-1,sum,n,dp);
	    int pick=0;
	    
	    if(arr[i]<=sum)
	    {
	        pick=totalarray(arr,i-1,sum-arr[i],n,dp);
	    }
	    dp[i][sum]=(pick+notpick)%1000000007;
	    return dp[i][sum];
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
	   vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	   
       return totalarray(arr,n-1,sum,n,dp);
	}
	  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends

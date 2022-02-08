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







// min difference code and tabulation
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
  
	int minDifference(int arr[], int n)  
	{ 
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum=sum+arr[i];
	    }
	    vector<vector<int>> dp (n,vector<int>(sum+1,0));
	    
	     for(int i=0;i<n;i++)
      {
          dp[i][0]=1;
      }
      if(arr[0]<=sum)
      {
          dp[0][arr[0]]=1;
      }
      for(int i=1;i<n;i++)
      {
          for(int j=1;j<=sum;j++)
          {
              int notpick = dp[i-1][j];
              int pick =0;
               if(arr[i]<=j)
               {
                pick =dp[i-1][j-arr[i]];
               }
      
              dp[i][j]=pick|notpick;
          }
      }
      
      int mini=INT_MAX;
      for(int i=0;i<=sum;i++)
      {
          if(dp[n-1][i]==1)
          {
              mini=min(mini,abs(i-(sum-i)));
          }
      }
      return mini;
      
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends


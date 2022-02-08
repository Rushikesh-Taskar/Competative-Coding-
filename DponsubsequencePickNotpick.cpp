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







// min difference code 

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
   
   int ispossible(int arr[] ,int i, int sum ,vector<vector<int>>& dp,int n)
   {
       /*if(sum==0)
       {
           return 1;
       }
      
       if(i==0)
       {
           if(arr[i]==sum)
           {
               return 1;
           }
           return 0;
       }
       
        if(dp[i][sum]!=-1)
       {
           return dp[i][sum];
       }
      int notpick = ispossible(arr,i-1,sum,dp,n);
      int pick =0;
      if(arr[i]<=sum)
      {
          pick = ispossible(arr,i-1,sum-arr[i],dp,n);
      }
      
      
      dp[i][sum]=pick|notpick;*/
      
      
      
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
      
      return dp[i][sum];
      
   }
    bool isSubsetSum(int N, int arr[], int sum)
    {
        vector<vector<int>> dp (N,vector<int>(sum+1,0));
        
        bool ans =ispossible(arr,N-1,sum,dp,N);
        for(int i=0;i<=sum;i++)
        {
            cout<<dp[N-1][i]<<" ";
        }
        cout<<endl;
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends

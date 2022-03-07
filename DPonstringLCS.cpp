// printing the length of largest common subsequence 

class Solution 
{
public:
    
    // recursion + memoization 
     int lcs(string &text1 ,string &text2 ,int  i, int j ,vector<vector<int>>& dp)
     {
         if(i<0 || j<0)
         {
             return 0;
         }
         
         if(dp[i][j]!=-1)
         {
             return dp[i][j];
         }
         // match condition 
         
         if(text1[i]==text2[j])
         {
             return dp[i][j] = 1+lcs(text1 ,text2 , i-1, j-1,dp);  // move to next position 
         }
         
         // not match condition 
         
         else
         {
             return dp[i][j] = max(lcs(text1 ,text2 , i-1, j ,dp),lcs(text1 ,text2 , i, j-1 ,dp));
         }
                        
     }
    int longestCommonSubsequence(string text1, string text2)
    {
      
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        // tabulation with shift index approach 
        
        // base cases 
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=0;
        }
        
        for(int i =1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                // match condition 
                 if(text1[i-1]==text2[j-1])
                {
                  dp[i][j] = 1+dp[i-1][j-1];  // move to next position 
                }
         
                 // not match condition 
         
                 else
                {
                   dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
        //return lcs(text1 ,text2 , n-1, m-1 ,dp);
    }
};

// for printing any LCS 
// in tabulation we got largest string len we will work on tabulation dp we will get sequence 
// we have dp[n+1][m+1]

int i=n ,j=m;
string ans ="";
while(i>0 && j>0)  // at any position i & j goes in -ve then stop
{
  if(text1[i-1]==text[j-1])
  {
     ans=anss+text1[i-1];
     i--;
     j--;
    
  }
  else
  {
      dp[i-1][j]>dp[i][j-1] ? i-- : j--;
  }
  
}
reverse(ans.begin() ,ans.end());
return ans ;
      









#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define endl "\n"


void printarray(vector<pair<int,int>> ans)
{
    
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
    
}

void solve()
{
    
    int n;
    cin>>n;
    vector<int>A(n);
    
    // odd even odd even.....
    // even odd even odd .......
    
    bool evenpos =false , oddexists=false, oddpos=false;
    
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        if(A[i]%2==1)  // oddexists
        {
            oddexists=true;
            if(i%2==0)
            {
                evenpos =true;  // odd element is exists at even position 
            }
            
            else
            {
                oddpos =true ;  // odd element is exists at odd position 
            }
        }
    }
    
    if(!oddexists)  // if all element are even then it is impossible to convert
    {
        cout<<-1<<endl;
        return;
    }
    
    // odd odd case 
    // odd element is exists at odd position 
    //// even odd even odd .......
    vector<pair<int,int>> ans1 ,ans2;
    if(oddpos)
    {
        int oddposition =-1;
         
         for(int i=0;i<n;i++)
         {
             if(A[i]%2==1 && i%2==1)  // odd odd 
             {
                 oddposition =i;
             }
         }
         
         for(int i=0;i<n;i++)
         {
             if(A[i]%2==0 && i%2==1)  // element is even but position is odd 
             {
                ans1.push_back({i,oddposition});
             }
             else if(A[i]%2==1 && i%2==0)  // element is odd position is even 
             {
                ans1.push_back({i,oddposition});
             }
         }
         
    }
     
     //even odd case 
     //odd even odd even.....
     
    if(evenpos)
    {
        int evenposition =-1;
         
         for(int i=0;i<n;i++)
         {
             if(A[i]%2==1 && i%2==0)  // even odd  
             {
                 evenposition =i;
             }
         }
         
         for(int i=0;i<n;i++)
         {
             if(A[i]%2==0 && i%2==0)   // even element is at evenposition 
             {
                ans2.push_back({i,evenposition});
             }
             else if(A[i]%2==1 && i%2==1)  // odd element at odd position 
             {
                ans2.push_back({i,evenposition});
             }
         }
    }
    
    if (oddpos && evenpos)
    {
        if(ans1.size()<ans2.size())
        {
            cout<<ans1.size()<<endl;
            printarray(ans1);
            return; 
        }
        else
        {
            cout<<ans2.size()<<endl;
            printarray(ans2);
            return;
        }
    }
   else if(oddpos)
    {
        cout<<ans1.size()<<endl;
        printarray(ans1);
        return;
    }
    else
    {
        cout<<ans2.size()<<endl;
        printarray(ans2);
        return;
    }
}
int32_t main() 
{   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(nullptr);
    cout.tie(NULL);
	int t=1;
	cin>>t;
	while(t--)
	{  
	    solve();
	    
	}
	return 0;
}

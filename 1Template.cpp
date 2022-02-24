#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define endl "\n"

int mod = 1e9+7;

int gcd( int a,  int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}


int fact(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return n*fact(n-1);
    }
}

bool isprime(int num){
    bool flag=true;
    for(int i = 2; i <= num / 2; i++) 
    {
       if(num % i == 0)
       {
          flag = false;
          break;
       }
    }
    return flag;
}

int power(int x,  int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}
int LIS(vector<int> &v)
{
    vector<int>lis;
    
    for(auto &x : v)
    {
       auto it = upper_bound(lis.begin(),lis.end(),x);  // equal element are also allowed if not then lowerbound 
       
        if(it==lis.end())
        {
            lis.push_back(x);
            
        }
        else
        {
            *it =x;
        }
    }
    return lis.size();
}

int uniqueprime(int m)
{   
    int count =0;
    for(int i=2;i*i<=m ;i++)
    {
        if(m%i==0)
        {
            count++;
            while(m%i==0)  // check for unique remove unique
            {
                m=m/i;
            }
        }
    }
    if(m!=1)
    {
        count++;
    }
    return count;
}

int solve()
{
    
    
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

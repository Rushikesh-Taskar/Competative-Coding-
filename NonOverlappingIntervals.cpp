class Solution {
public:
    static bool sortbysecond(vector<int>& a ,vector<int>& b)  
    {
        if(b[1]>a[1])
        {
            return true ;
        }
        return false;
    }
       
    int eraseOverlapIntervals(vector<vector<int>>& A) 
    {
         int arrow =0; 
        
        sort(A.begin(),A.end(),sortbysecond);
        
        int end = A[0][1];   // first vector last element 
        
        for(int i=1;i<A.size();i++)
        {
            if(A[i][0]<end)   // check interval 
            {
                arrow++;
                
            }
            else
            {
                end =A[i][1];   // update end value 
            }
        }
        
        return arrow;
    }
};

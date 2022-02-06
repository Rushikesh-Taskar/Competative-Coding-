class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
         map<char ,int> pt;
        map<char ,int> st;
        
        int n= s.size();
        int i=0;
        //if size is not equal 
        
        while(i<n)
        {     
            
            if(pt.find(s[i])==pt.end() && st.find( t[i] )!=st.end())
            {
              return false;
            }
            
            if(pt.find(s[i])==pt.end() && st.find(t[i])==st.end())
            {
                pt[s[i]] =i+1;
                st[t[i]]=i+1;
            }
            
            if(pt.find(s[i])!=pt.end())
            {
                if(pt[s[i]]!=st[t[i]])
                {
                    return false;
                }
            }
            i++;
        }
        return true;
    }
};

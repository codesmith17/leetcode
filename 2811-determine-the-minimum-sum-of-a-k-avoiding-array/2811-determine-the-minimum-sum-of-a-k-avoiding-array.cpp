class Solution {
public:
    int minimumSum(int n, int k) {
        
        map<int,int>mp;
        int x=1;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(k-x)==mp.end())
            {ans+=x;
            mp[x]++;}
            else
                i--;
            x++;
            
        }
        return ans;
        
        
        
        
        
    }
};
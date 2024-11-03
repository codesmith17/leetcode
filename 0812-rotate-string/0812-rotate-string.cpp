class Solution {
public:
    bool rotateString(string s, string goal) {
        int len=s.size();
        
        string x=s+s;
        for(int i=0;i<x.size()-len+1;i++)
        {
            if(x.substr(i,len)==goal)
                return true;
        }     
        return false;
    }
};
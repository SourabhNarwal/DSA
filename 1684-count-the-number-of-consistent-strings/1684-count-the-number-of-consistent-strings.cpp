class Solution {
    bool consistent(string &s,unordered_map<char,bool> &m)
    {
       int n3=s.size();
        
        for(int i=0;i<n3;i++)
        {
           if(!m[s[i]])return false;
        }
        return true;
    }
    
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,bool> m;
        int n1=allowed.size();
        for(int i=0;i<n1;i++)
        {
            m[allowed[i]]=true;
        }
        
        int n2=words.size();
        int count =0;
        for(int i=0;i<n2;i++)
        {
            if(consistent(words[i],m))count++;
        }
        return count;
    }
};
struct node{
    node* links[26];
    int count=0;
    bool flag=false;
    
    
    void put(char ch,node* nod)
    {
        links[ch-'a']=nod;
        nod->count++;
    }
    
    node* get(char ch)
    {
      return links[ch-'a'];
    }
    
    void inccount()
    {
        count++;
    }
    bool containchar(char ch)
    {
        return links[ch-'a'];
    }
    
    void setflag()
    {
         flag=true;
    
    }
    
    bool isend()
    {
        return flag;
    }
};

class Trie{
private:
  node* root=NULL;
    
    public:
    Trie(){
        root=new node();
    }
    
    void insertword(string word)
    {  node* nod= root;
       for(int i=0;i<word.size();i++)
       {
          
          if(!nod->containchar(word[i]))
          {
              nod->put(word[i],new node());
              nod=nod->get(word[i]);
          }
           else{
               nod=nod->get(word[i]);
               nod->inccount();
           }
          
       }
     nod->setflag();
    }
    string longestpfx(string word,int size)
    {
      char ch=word[0];
        int i=0;
        int wsize=word.size();
       string pf="";
        
        if(!ch)return pf;
        node * nod=root;
        char prev=word[i];
        nod=nod->get(ch);
        while(i<wsize)
        { //cout<<nod->count<<"/";
          if(nod->count==size)
          {
            pf=pf+prev;
          if(i+1<wsize){
            nod=nod->get(word[++i]);
            prev=word[i];
          }
              else
                  return pf;
          }
            else{
                return pf;
            }
            
        }
        return pf;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        Trie trie;
        for(int i=0;i<strs.size();i++)
        {
            trie.insertword(strs[i]);
        }
        
        
        return trie.longestpfx(strs[0],strs.size());
    }
};
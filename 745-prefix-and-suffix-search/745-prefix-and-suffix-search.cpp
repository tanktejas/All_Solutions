class Node
{
    public:
    Node *links[28]={NULL};
    int index=-1;
    bool containsKey(char ch)
    {
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    void setIndex(int _index)
    {
        index=_index;
    }
    int getIndex()
    {
        return index;
    }
    
    
};
class Trie
{
    public : Node *root;
    public:
    Trie()
    {
        root=new Node();
    }
    void insert(string &word,int idx)
    {
        
        Node *temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsKey(word[i]))
            {
                temp->put(word[i],new Node());
            }
            temp=temp->get(word[i]);
            temp->setIndex(idx);
        }
    }
    int startsWith(string &prefix)
    {
        Node *temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->containsKey(prefix[i]))
            {
                return -1;
            }
            temp=temp->get(prefix[i]);
            
        }
       
        return temp->getIndex();
        
    }
};
class WordFilter {
public:
    Trie *trie;
    
    WordFilter(vector<string>& words) {
        trie=new Trie();
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            string temp="|";
            temp+=s;
            for(int j=s.size()-1;j>=0;j--)
            {
                char ch=s[j];
                temp=ch+temp;
                trie->insert(temp,i);
         
            }
        }
     }
    
    int f(string prefix, string suffix) {
        
        string s=suffix+'|'+prefix;
        
        int res=trie->startsWith(s);
        return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
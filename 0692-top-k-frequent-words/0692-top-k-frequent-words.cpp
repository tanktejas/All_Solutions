class Solution {
public:
    struct cmp{
        
        bool operator()(pair<int,string> &p1,pair<int,string> &p2)
        {
            if(p1.first == p2.first)
            {
                return p1.second < p2.second;
            }
            
            return p1.first > p2.first;
        }
        
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        int n=words.size();
        
        for(int i=0;i<n;i++)
        {
            mp[words[i]]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        
        for(auto ele:mp)
        { 
            int siz=pq.size();
            if(siz < k)
            {
                pq.push(make_pair(ele.second,ele.first));
            }else{
                pq.push(make_pair(ele.second,ele.first));
                pq.pop();
            }
        }
        
        vector<string>ans;
        
        while(!pq.empty())
        { 
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
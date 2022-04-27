// class Solution {
// public:
    
    
//     void dfs(vector<vector<int>> &adj,int start,unordered_set<int> &vis,vector<string> &sorted,string s,int uniq,unordered_map<int,int> &par){
//           par[start]=uniq;
//           vis.insert(start); 
//           sorted[uniq].push_back(s[start]); 
        
//           for(auto &ele:adj[start]){
//                if(vis.find(ele)==vis.end()){ 
//                   dfs(adj,ele,vis,sorted,s,uniq,par); 
//                }
//           }
         
//     }
    
//     string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
//         int n=s.length();
//         vector<vector<int>>adj(n);
//          for(int i=0;i<pairs.size();i++){
//              adj[pairs[i][0]].push_back(pairs[i][1]);
//              adj[pairs[i][1]].push_back(pairs[i][0]);
//          }
        
        
//         vector<string>sorted;
        
//         int uniq=0;
//         unordered_map<int,int>par;
        
//         unordered_set<int>vis;
        
        
//          string newstr="";
        
//         for(int i=0;i<n;i++){
//           if(vis.find(i)==vis.end()){ 
//               newstr="";
//               sorted.push_back(newstr);
//               dfs(adj,i,vis,sorted,s,uniq,par); 
//               sorted.push_back(newstr); 
//               uniq++; 
//           }
//         }
     
//         for(auto &thi:sorted){
//             sort(thi.begin(),thi.end());
//         }
//         vector<int>cnt(sorted.size());
         
        
//         for(int i=0;i<n;i++){
//             int j=par[i];
//             s[i]=sorted[j][cnt[j]++];
//         }
        
//         return s;
        
//     }
// };

class Solution {
    
public:
    void dfs(vector<vector<int>> &adjList, int x, unordered_set<int>& seen, vector<string>& sets, int seti, unordered_map<int, int>& parentSet, string& s) {
       
        seen.insert(x);
        sets[seti].push_back(s[x]);
        parentSet[x] = seti; 
        for(auto child : adjList[x]) {
             if(seen.find(child) == seen.end()) 
               dfs(adjList, child, seen, sets, seti, parentSet, s);
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vector<vector<int>> adjList(s.length());
        
        for(int i=0;i<pairs.size();i++) {
            adjList[pairs[i][0]].push_back(pairs[i][1]);
            adjList[pairs[i][1]].push_back(pairs[i][0]);
        } 
        
        unordered_set<int> seen;
        vector<string> sets;
        unordered_map<int, int> parentSet;
        int seti = 0;
        string newSet;
        
        for(int i = 0; i <  s.length(); i++) {
            if(seen.find(i) == seen.end()) {
                 newSet = "";
                sets.push_back(newSet);
                dfs(adjList, i, seen, sets, seti, parentSet, s);
                seti++;
            }
        }
        int setSize = sets.size();
        
        vector<int> its(setSize);
        for(auto& thing : sets) {
            sort(thing.begin(), thing.end());
        }
        for(int i = 0; i < s.length(); i++) {
            int j = parentSet[i];      
            s[i]  = sets[j][its[j]++];  
        }

        return s;
        
    }
};
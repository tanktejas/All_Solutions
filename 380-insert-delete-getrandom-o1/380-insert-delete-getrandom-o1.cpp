class RandomizedSet {
public:
    unordered_map<int,int>m; 
    vector<int>v; 
    
    RandomizedSet() {     
        
    }
    
    bool insert(int val) {
        if(m.count(val)) return 0;
        
        v.push_back(val);  
        m[val]=v.size()-1; 
        return 1;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return 0;
        
        int pos=m[val];  
        v[pos]=v.back(); 
        m[v.back()]=pos;
        v.pop_back();
        m.erase(val); 
         
        return 1; 
    }
    
    int getRandom() {
        
        return v[rand()%v.size()];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
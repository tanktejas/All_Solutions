class MyHashMap {
public:
    vector<vector<pair<int,int>>>v;
    int mod=10007;
    MyHashMap() {
        v.resize(mod);
    }
    
    void put(int key, int value) {
        int idx=key%mod;
        for(int i=0;i<v[idx].size();i++){
            if(v[idx][i].first==key){
                v[idx][i].second=value;
                return ;
            }
        }
        v[idx].push_back(make_pair(key,value));
    }
    
    int get(int key) {
        int idx=key%mod;
        for(int i=0;i<v[idx].size();i++){
            if(v[idx][i].first==key){
                return v[idx][i].second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int idx=key%mod;
        for(int i=0;i<v[idx].size();i++){
            if(v[idx][i].first==key){
                v[idx][i].second=-1;
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
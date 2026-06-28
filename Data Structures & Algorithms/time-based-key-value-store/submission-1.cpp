class TimeMap {
public:

    unordered_map<string,vector<pair<int,string>>> store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(store.find(key)==store.end()) return "";
        auto i = store[key];
        
        int n= i.size();
        for(int k=n-1;k>=0;k--)
        {
            if(i[k].first<=timestamp){
                return i[k].second;
            }
        }
        return "";
    }
};

class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // const auto& it = mp.find(key);
        if (mp.find(key) == end(mp)) {
            mp[key].reserve(512);
        }
        mp[key].emplace_back(value, timestamp);
    }
    
    string get(string key, int timestamp) {
        const auto& it = mp.find(key);
        if (it == end(mp)) {
            return "";
        }
        string res = "";
        const auto& ents = mp[key];
        if (timestamp >= ents.back().second) {
            return ents.back().first;
        }
        int left = 0, right = ents.size() - 1;        
        // first t that is <= timestamp
        while (left <= right) {
            int mid = (left + right) / 2;
            const auto& [val, currentTime] = ents[mid];
            if (currentTime <= timestamp) {
                res = val;
                left = mid + 1;
            } else {                
                right = mid - 1;
            }
        }
        return res;
    }

    
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

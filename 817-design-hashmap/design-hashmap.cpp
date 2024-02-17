class MyHashMap {
public:

    int data[1000001];
    MyHashMap() {
        memset(data, -1, sizeof data);
    }
    
    void put(int key, int value) {
        data[key] = value;
    }
    
    int get(int key) {
        return data[key];
    }
    
    void remove(int key) {
        data[key] = -1;
    }
    // vector<pair<int, int>> hashMap;
    // MyHashMap() {
        
    // }
    
    // void put(int key, int value) {
    //     if(hashMap.size() == 0){
    //         hashMap.push_back({key, value});
    //     }
    //     else{
    //         bool present = false;
    //         for(int i=0;i<hashMap.size();i++){
    //             if(hashMap[i].first == key){
    //                 present = true;
    //                 hashMap[i].second = value;
    //                 break;
    //             }
    //         }
    //         if(!present){
    //             hashMap.push_back({key, value});
    //         }
    //     }
    // }
    
    // int get(int key) {
    //     for(int i=0;i<hashMap.size();i++){
    //         if(hashMap[i].first == key){
    //             return hashMap[i].second;
    //         }
    //     }
    //     return -1;
    // }
    
    // void remove(int key) {
    //     for(int i = 0; i < hashMap.size(); ++i){
    //         if(hashMap[i].first == key){
    //             hashMap.erase(hashMap.begin() + i);
    //             break;
    //         }
    //     }
    // }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
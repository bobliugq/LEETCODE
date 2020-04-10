class LRUCache {
    int _capacity;
    list<pair<int, int>> dList;
    unordered_map<int, list<pair<int, int>::iterator>> mp;
public:
    LRUCache(int capacity) : _capacity(capacity) {};
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        auto it = *mp[key];
        dList.erase(mp[key]);
        dList.push_front(it);
        mp[key] = dList.begin();
        return it.first;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            dList.erase(mp[key]);
            dList.push_front({key, value});
            mp[key] = dList.begin();
        } else {
            if (dList.size() < _capacity) {
                dList.push_back({key, value});
                mp[key] = dList.begin();
            } else {
                auto it = dList.back();
                dList.pop_back();
                mp.erase(it.first);
                dList.push_front({key, value});
                mp[key] = dList.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

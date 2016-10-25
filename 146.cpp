class LRUCache{
private:
    typedef list<pair<int, int>>::iterator it;
    unordered_map<int, it> mapping;
    list<pair<int, int>> storage;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (mapping.find(key) == mapping.end()) {
            return -1;
        } else {
            int result = mapping[key]->second;
            storage.erase(mapping[key]);
            storage.push_front({key, result});
            mapping[key] = storage.begin();
            return result;
        }
    }
    
    void set(int key, int value) {
        if (mapping.find(key) != mapping.end()) {
            storage.erase(mapping[key]);
        }
        if (storage.size() == _capacity) {
            mapping.erase(storage.back().first);
            storage.pop_back();
        }
        storage.push_front({key, value});
        mapping[key] = storage.begin();
    }
};
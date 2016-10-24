class RandomizedSet {
private:
    unordered_map<int, int> mapping;
    vector<int> storage;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mapping.find(val) != mapping.end()) return false;
        mapping[val] = storage.size();
        storage.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mapping.find(val) == mapping.end()) return false;
        int index = mapping[val];
        storage[index] = storage.back();
        mapping[storage.back()] = index;
        mapping.erase(val);
        storage.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return storage[rand() % storage.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
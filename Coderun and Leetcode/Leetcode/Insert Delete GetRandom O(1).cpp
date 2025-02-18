class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(m.count(val)) return false;
        v.push_back(val);
        m[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        int idx = m[val];
        v[idx] = v.back();
        m[v.back()] = idx;
        m.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[static_cast<int>(rand()) % (v.size())];
    }
private:
    std::map<int, int> m;
    std::vector<int> v;
};
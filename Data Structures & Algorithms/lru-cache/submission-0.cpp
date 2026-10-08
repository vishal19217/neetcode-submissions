class LRUCache {
public:

    unordered_map<int,int> kv;
    list<int> lst;
    unordered_map<int,list<int>::iterator> mp;
    int cap;
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(kv.count(key) == 0){
            return -1;
        }
        else{
            updateCache(key,kv[key]);
            return kv[key];
        }
    }
    void updateCache(int key,int val){
       // it will be remove the element
        if(mp.count(key)>0){
            auto it = mp[key];
            lst.erase(it);
        }
        //reinsert to the first
       // it will update the value in the kv map
        lst.push_front(key);
        mp[key] = lst.begin();
        kv[key] = val;
    }
    void put(int key, int value) {
        if(mp.count(key) == 0){
            if(cap == 0){
                evict();
            }
            else{
                cap--;
            }
        }
        updateCache(key,value);
            
    }
    void evict(){
        auto it = lst.end();it--;
        int key = *it;
        lst.erase(it);
        kv.erase(key);
        mp.erase(key);


    }
};

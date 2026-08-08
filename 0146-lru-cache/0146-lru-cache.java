class Pair{
    int key; 
    int value;

    Pair(int key, int value){
        this.key = key;
        this.value = value;
    }
}
class LRUCache {
    int cap;
    ArrayList<Pair> cache = new ArrayList<>();

    public LRUCache(int capacity) {
       this.cap = capacity;
    }
    
    public int get(int key) {
        int index = -1;
        for(int i=0; i<cache.size(); i++){
            if(cache.get(i).key == key){
                index = i;
            }
        }
        //If we dont find key in our cache db then return -1
        if(index == -1){
            return -1;
        }

        Pair temp = cache.get(index);
        //delet kr do yaha se aur last mein add kr do taki ye wala recent update ho jayega
        cache.remove(index);
        //wapas add kr do
        cache.add(temp);
        // key ki value return kr do 
        return temp.value;
    }
    
    public void put(int key, int value) {
        int idx = -1;
        for (int i = 0; i < cache.size(); i++) {
            if (cache.get(i).key == key) {
                idx = i;
                break;
            }
        }

        if (idx != -1) {
            // key exists: update value, move to end (most recently used)
            cache.remove(idx);
            cache.add(new Pair(key, value));
        } else {
            // key doesn't exist: evict least-recently-used (front) if full, then insert
            if (cache.size() >= cap) {
                cache.remove(0);
            }
            cache.add(new Pair(key, value));
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
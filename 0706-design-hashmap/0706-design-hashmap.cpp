class MyHashMap {  
public:
    vector<int> MyMapArray;
    MyHashMap() {
        MyMapArray = vector<int>(1000001,-1);        
    }
    
    void put(int key, int value) {
        MyMapArray[key] = value;
    }
    
    int get(int key) {
        return MyMapArray[key];
    }
    
    void remove(int key) {
        MyMapArray[key] = -1;
    }
};

/*
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
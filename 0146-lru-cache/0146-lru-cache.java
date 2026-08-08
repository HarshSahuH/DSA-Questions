class Node{
    int key; 
    int value;
    Node prev;
    Node next;

    Node(int key, int value){
        this.key = key;
        this.value = value;
    }
}

class LRUCache {
    int cap;
    HashMap<Integer,Node> cache = new HashMap<>();
    Node head = new Node(-1,-1);
    Node tail = new Node(-1,-1);

    public LRUCache(int capacity) {
       this.cap = capacity;
       head.next = tail;
       tail.prev = head;
    }
    
    public void remove(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev; 
    }

    public void insertAtFront(Node node){
        node.next = head.next; 
        node.prev = head;
        head.next.prev = node; 
        head.next = node;
    }

    public int get(int key) {
        if(!cache.containsKey(key)){
           return -1; 
        }
        Node node = cache.get(key);
        remove(node);           // detach from current position
        insertAtFront(node);     // move to front (most recently used)
        return node.value;
    }
    
    public void put(int key, int value) {
        if (cache.containsKey(key)) {
            // key exists: update value, move to end (most recently used)
            Node node = cache.get(key);
            node.value = value;
            remove(node);
            insertAtFront(node);
        } else {
            // key doesn't exist: evict least-recently-used (front) if full, then insert
            if (cache.size() >= cap) {
                Node lru = tail.prev;
                remove(lru);
                cache.remove(lru.key);
            }
            Node newNode = new Node(key, value);
            insertAtFront(newNode);
            cache.put(key, newNode);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
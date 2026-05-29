class LRUCache {
public:
    struct Node {
            int key, val;
            Node* prev;
            Node* next;
            Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
        };
    int cap;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    void insertFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;
        Node* node = mp[key];
        remove(node);
        insertFront(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            remove(mp[key]);
            delete mp[key];
            mp.erase(key);
        }
        if(mp.size() == cap){
            Node* lru = tail->prev;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
        Node* node = new Node(key, value);
        insertFront(node);
        mp[key] = node;
    }
};

class LRUCache {
public:
    class Node{ // class for doubly linked list node
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key , int _val){
            this->key = _key;
            this->val = _val;
        }
    };
    Node* head = new Node(-1,-1); //assign two dummy nodes as head and tail
    Node* tail = new Node(-1,-1);
    
    int maxSize=0; //stores the max size of cache
    unordered_map <int,Node*> mp; //hashmap
    
    LRUCache(int capacity) {
        maxSize = capacity; // assign max size
        head -> next = tail; //link previously created nodes
        tail -> prev = head;
    }
    void addnode(Node* newNode){
        Node* temp = head -> next;
        newNode -> next = temp;
        newNode -> prev = head;
        head -> next = newNode;
        temp -> prev = newNode;
    }
    void deletenode(Node* node){
        Node *after = node -> next;
        Node *before = node -> prev;
        before -> next = after;
        after -> prev = before;
    }
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* resnode = mp[key];
            int res = resnode -> val;
            mp.erase(key);
            deletenode(resnode);
            addnode(resnode);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            mp.erase(key);
            deletenode(existing);
        }
        if(mp.size() == maxSize){
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;
    int maxCapacity;
    std::unordered_map<int, Node*> cache;

public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        head = new Node;
        tail = new Node;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }
    
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }
        Node* node = cache[key];
        remove(node);
        addAfterHead(node);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->val = value;
            remove(node);
            addAfterHead(node);
        }
        else{
            Node* node = new Node;
            node->key = key;
            node->val = value;
            //store address in hashmap
            cache[key] = node;
            addAfterHead(node);
            if(cache.size() > maxCapacity){
                Node* lru = tail->prev;
                remove(lru);
                cache.erase(lru->key);
                delete lru;
            }
        }
    }

    void addAfterHead(Node* node){
        //this function will add the node directly after the head
        //that is why prev is head
        Node* prev = head;
        Node* next = head->next;

        node->prev = prev;
        node->next = next;
        prev->next = node;
        next->prev = node;
    }
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }
};

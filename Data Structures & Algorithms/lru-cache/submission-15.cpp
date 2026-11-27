class LRUCache {
private:
    struct Node{
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int k = 0, int v = 0){
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> cache;
    int maxCapacity;

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
        else{
            Node* node = cache[key];
            removeNode(node);
            insertNodeAfterHead(node);
            return node->val;
        }
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->val = value;
            removeNode(node);
            insertNodeAfterHead(node);
        }
        else{
            if(cache.size() == maxCapacity){
                Node* node = tail->prev;
                removeNode(node);
                cache.erase(node->key);
                delete node;
            }
            Node* node = new Node(key, value);
            cache[key] = node;
            insertNodeAfterHead(node);
        }
    }

    void insertNodeAfterHead(Node* node){
        Node* currentAfterHead = head->next;
        head->next = node;
        node->next = currentAfterHead;
        node->prev = head;
        currentAfterHead->prev = node;
    }

    void removeNode(Node* node){
        Node* prevNode = node->prev;  
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};

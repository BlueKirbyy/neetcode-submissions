class MyLinkedList {
private:
    struct Node{
        int val;
        Node* next;
    };
    Node* head;
public:
    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        if(index < 0){
            return -1;
        }
        Node* current = head;
        for(int i = 0; i < index && current != nullptr; i++){
            current = current->next;
        }
        if(current == nullptr){
            return -1;
        }
        return current->val;
    }
    
    void addAtHead(int val) {
        Node* nodeToAdd = new Node;
        nodeToAdd->val = val;
        nodeToAdd->next = head;
        head = nodeToAdd;
    }
    
    void addAtTail(int val) {
        if(head == nullptr){
            addAtHead(val);
            return;
        }
        Node* current = head;
        while(current->next != nullptr){
            current = current->next;
        }
        if(current == nullptr){
            return;
        }
        Node* nodeToAdd = new Node;
        nodeToAdd->val = val;
        nodeToAdd->next = nullptr;
        current->next = nodeToAdd;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        Node* current = head;
        for(int i = 0; i < index - 1 && current != nullptr; i++){
            current = current->next;
        }
        if(current == nullptr){
            return;
        }
        Node* nodeToAdd = new Node;
        nodeToAdd->val = val;
        nodeToAdd->next = current->next;
        current->next = nodeToAdd;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || head == nullptr){
            return;
        }
        if(index == 0){
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }
        Node* current = head;
        for(int i = 0; i < index - 1 && current != nullptr; i++){
            current = current->next;
        }
        if(current == nullptr || current->next == nullptr){
            return;
        }
        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
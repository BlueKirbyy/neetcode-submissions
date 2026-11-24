class BrowserHistory {
private:
    struct Node{
        string url;
        Node* prev;
        Node* next;
    };
    Node* current;
    Node* head;

public:
    BrowserHistory(string homepage) {
        head = new Node;
        head->url = homepage;
        head->next = nullptr;
        head->prev = nullptr;
        current = head;
    }
    
    void visit(string url) {
        Node* newPage = new Node;
        newPage->url = url;
        newPage->next = nullptr;
        newPage->prev = current;
        current->next = newPage;
        current = newPage;
    }
    
    string back(int steps) {
        while(steps > 0 && current->prev != nullptr){
            current = current->prev;
            steps--;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while(steps > 0 && current->next != nullptr){
            current = current->next;
            steps--;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
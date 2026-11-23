class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
    };

    ListNode* head;
    ListNode* tail;

    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    int get(int index) {
        ListNode* current = head;
        int currentIndex = 0;

        while (current != nullptr) {
            if (currentIndex == index) {
                return current->val;
            }

            current = current->next;
            currentIndex++;
        }

        return -1;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode();
        newNode->val = val;
        newNode->next = head;

        head = newNode;

        // If this was the first node,
        // it is also the tail
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode();
        newNode->val = val;
        newNode->next = nullptr;

        // Empty list
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        ListNode* current = head;
        int currentIndex = 0;

        // Stop at the node BEFORE index
        while (current != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }

        // Index is too large
        if (current == nullptr) {
            return;
        }

        ListNode* newNode = new ListNode();
        newNode->val = val;

        newNode->next = current->next;
        current->next = newNode;

        // If inserted at the end,
        // update tail
        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }

    void deleteAtIndex(int index) {
        if (head == nullptr) {
            return;
        }

        // Delete head
        if (index == 0) {
            ListNode* nodeToDelete = head;

            head = head->next;

            // If list became empty
            if (head == nullptr) {
                tail = nullptr;
            }

            delete nodeToDelete;
            return;
        }

        ListNode* current = head;

        // Stop at the node BEFORE index
        for (int i = 0; i < index - 1; i++) {
            if (current == nullptr) {
                return;
            }

            current = current->next;
        }

        // Invalid index
        if (current == nullptr || current->next == nullptr) {
            return;
        }

        ListNode* nodeToDelete = current->next;

        // If deleting the tail
        if (nodeToDelete == tail) {
            tail = current;
        }

        current->next = nodeToDelete->next;

        delete nodeToDelete;
    }
};
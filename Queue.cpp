struct ListNode {
    ListNode* next;
    int val;
    ListNode(int x) {
        val = x;
        this->next = nullptr;
    }
};

class Queue {
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor for freeing all dynamically allocated memory
    ~Queue() {
        if (head) {
            ListNode* cur = head;
            ListNode* next;
            // iterate through the list and free all memory
            while (cur) {
                next = cur->next;
                delete cur;
                cur = next;
            }
            head = nullptr;
        }
    }

    void push_front(int x) { // add node at then end of linked list
        // Need to dynamically allocate front bc want it to persist after leaving this block
        ListNode* front = new ListNode(x);
        if (!head) {
            head = front;
            tail = head;
        }
        else {
            tail->next = front;
            tail = tail->next;
        }
    }

    void pop_back() { // remove the first node of the linked list
        if (!head) {
            return;
        }
        ListNode* newHead = head->next;
        delete head; // free memory
        head = newHead;
    }

private:
    ListNode* head;
    ListNode* tail;
};

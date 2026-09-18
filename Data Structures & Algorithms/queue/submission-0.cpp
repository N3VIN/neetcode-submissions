class Deque {
   public:
    Deque() {}

    bool isEmpty() {
        if (m_size <= 0) {
            return true;
        }

        return false;
    }

    void append(int value) {
        Node* node = new Node{value, nullptr, nullptr};
        ++m_size;

        if (m_size == 1) {
            m_pHead = node;
            m_pTail = node;
            return;
        }

        auto prev = m_pTail;
        node->pPrev = prev;
        prev->pNext = node;
        m_pTail = node;
    }

    void appendleft(int value) {
        if (m_size == 0) {
            append(value);
            return;
        }
        
        auto next = m_pHead;
        Node* node = new Node{value, nullptr, next};
        next->pPrev = node;
        m_pHead = node;
        ++m_size;
    }

    int pop() {
        if(m_size == 0){
            return -1;
        }

        if(m_size == 1){
            auto node = m_pHead;
            auto val = node->val;
            m_pHead = nullptr;
            m_pTail = nullptr;
            delete node;
            --m_size;
            return val;
        }

        auto node = m_pTail;
        auto val = node->val;
        auto prev = node->pPrev;
        prev->pNext = nullptr;
        m_pTail = prev;
        delete node;
        --m_size;
        return val;
    }

    int popleft() {
        if(m_size <= 1){
            return pop();
        }

        auto node = m_pHead;
        auto val = node->val;
        auto next = node->pNext;
        next->pPrev = nullptr;
        m_pHead = next;
        delete node;
        --m_size;
        return val;
    }

   private:
    struct Node {
        int val{0};
        Node* pPrev{nullptr};
        Node* pNext{nullptr};
    };

    Node* m_pHead{nullptr};
    Node* m_pTail{nullptr};
    int m_size{0};
};

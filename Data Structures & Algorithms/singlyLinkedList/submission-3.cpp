class LinkedList {
   public:
    LinkedList() {}

    int get(int index) {
        if (index > m_size - 1) {
            return -1;
        }

        auto node = m_pHead;
        for (int i = 0; i < index; ++i) {
            node = node->pNext;
        }

        return node->val;
    }

    void insertHead(int val) {
        Node* head = new Node{val, m_pHead};

        if (m_size == 0) {
            m_pHead = head;
            m_pTail = head;
        } else {
            m_pHead = head;
        }

        ++m_size;
    }

    void insertTail(int val) {
        if (m_size == 0) {
            insertHead(val);
        } else {
            ++m_size;
            Node* tail = new Node{val, nullptr};
            m_pTail->pNext = tail;
            m_pTail = tail;
        }
    }

    bool remove(int index) {
        if (index >= m_size) {
            return false;
        }

        if (index == 0) {
            Node* toDelete = m_pHead;
            m_pHead = m_pHead->pNext;
            delete toDelete;

            --m_size;
            if (m_size == 0) {
                m_pTail = nullptr;
            }

            return true;
        }

        auto prevNode = m_pHead;
        for (int i = 0; i < index - 1; ++i) {  // we get the node before the index
            prevNode = prevNode->pNext;
        }

        auto nodeToBeDeleted = prevNode->pNext;
        auto nextNode = prevNode->pNext->pNext;

        prevNode->pNext = nextNode;
        if (nodeToBeDeleted == m_pTail) {
            m_pTail = prevNode;
        }
        delete nodeToBeDeleted;
        --m_size;

        return true;
    }

    vector<int> getValues() {
        std::vector<int> values;
        auto node{m_pHead};
        while (node != nullptr) {
            values.push_back(node->val);
            node = node->pNext;
        }

        return values;
    }

   private:
    struct Node {
        int val{};
        Node* pNext{nullptr};
    };

    Node* m_pHead{nullptr};
    Node* m_pTail{nullptr};
    int m_size{0};
};
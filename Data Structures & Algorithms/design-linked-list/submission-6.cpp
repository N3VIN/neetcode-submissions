class MyLinkedList {
   public:
    MyLinkedList() {}

    int get(int index) {
        if(index < 0 || index >= m_size || m_size == 0){
            return -1;
        }

        auto node = m_pHead;
        for(int i{0}; i < index; ++i){
            node = node->pNext;
        }

        return node->val;
    }

    void addAtHead(int val) {
        Node* node = new Node{val, nullptr, m_pHead};

        if(m_size == 0){
            m_pHead = node;
            m_pTail = node;
        }
        else{
            m_pHead->pPrev = node;
            m_pHead = node;
        }

        ++m_size;
    }

    void addAtTail(int val) {
        if(m_size == 0){
            addAtHead(val);
        }
        else{
            Node* node = new Node{val, m_pTail, nullptr};
            m_pTail->pNext = node;
            m_pTail = node;
            ++m_size;
        }
    }

    void addAtIndex(int index, int val) {
        if(index > m_size || index < 0){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == m_size){
            addAtTail(val);
            return;
        }

        auto node = m_pHead;
        for(int i{0}; i < index; ++i){
            node = node->pNext;
        }

        auto prevNode = node->pPrev;
        Node* addNode = new Node{val, prevNode, node};
        prevNode->pNext = addNode;
        node->pPrev = addNode;
        ++m_size;
    }

    void deleteAtIndex(int index) {
        if(index >= m_size || index < 0 || m_size == 0){
            return;
        }

        // TODO: handle case for index 0
        if(index == 0){
            auto node = m_pHead;
            m_pHead = node->pNext;
            if(m_pHead){
                m_pHead->pPrev = nullptr;
            } else {
                m_pTail = nullptr;
            }

            delete node;
            --m_size;
            return;
        }

        auto node = m_pHead;
        for(int i{0}; i < index; ++i){
            node = node->pNext;
        }

        auto prevNode = node->pPrev;
        auto nextNode = node->pNext;
        if(prevNode){
            prevNode->pNext = nextNode;
        }
        if(nextNode){
            nextNode->pPrev = prevNode;
        } else {
            m_pTail = prevNode;
        }


        delete node;
        --m_size;
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

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
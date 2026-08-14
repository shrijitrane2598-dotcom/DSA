class LRUCache {
public:

    class node {
    public:
        int key, val;
        node* prev;
        node* next;

        node(int k, int v) {
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    unordered_map<int, node*> m;
    int limit;

    // Add node just after head
    void addnode(node* newnode) {
        node* oldnext = head->next;

        head->next = newnode;
        oldnext->prev = newnode;

        newnode->next = oldnext;
        newnode->prev = head;
    }

    // Delete a node from the list
    void delnode(node* oldnode) {
        node* oldprev = oldnode->prev;
        node* oldnext = oldnode->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        // Key not present
        if (m.find(key) == m.end()) {
            return -1;
        }

        node* ansnode = m[key];
        int ans = ansnode->val;

        // Remove from current position
        delnode(ansnode);

        // Move to front = most recently used
        addnode(ansnode);

        return ans;
    }

    void put(int key, int value) {

        // Key already exists
        if (m.find(key) != m.end()) {

            node* oldnode = m[key];

            delnode(oldnode);
            m.erase(key);
        }

        // Capacity reached
        if (m.size() == limit) {

            // Remove least recently used node
            node* lru = tail->prev;

            m.erase(lru->key);
            delnode(lru);

            delete lru;
        }

        // Add new node as most recently used
        node* newnode = new node(key, value);

        addnode(newnode);
        m[key] = newnode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class Node {
    public: 
    //doubly linked list
    int key;
    int val;
    Node* prev;
    Node* next;

Node(int k, int v):  val(v), key(k),prev(nullptr), next(nullptr) {} //constructor
};




class LRUCache {
private:
int capacity;
unordered_map<int,Node*> cache; //to find the address is o(1)

//dummy nodes at beginning and end of the doubly linked list
Node* left;
Node* right;

void remove(Node* node) {
    //unlinks a node, doesn't actually delete it
    Node* prev = node->prev;
    Node* next = node->next;
    prev->next = next;
    next->prev = prev;
}

void insert(Node* node) {
    //insert at right side: just before the dummy right node
    Node* prev = right->prev;

    prev->next = node;
    node->prev = prev;

    node->next = right;
    right->prev = node;

}

public:
    LRUCache(int capacity) {
        this->capacity = capacity; //myObject.doSomething(), the compiler translates this under the hood to doSomething(&myObject). therefore this pointer knows the object I am refering too
        
        cache.clear();

        //create the dummy
        left = new Node(0, 0);
        right = new Node(0, 0);

        //link them
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node); //unlink it 
            insert(node); //push it to the right;
            return node->val;
        }
        return -1; //not found
    }
    
    void put(int key, int value) {
      
      //if found, remove it
    if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node); //unlink
        }
    
        //if new: 
         // Create a new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            insert(newNode);
    
        if(cache.size() > capacity) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
            return;
        }
}
    
};

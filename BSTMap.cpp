template <typename K, typename V>
class BSTMap {
private:
    // nested class
    template <typename X, typename Y>
    class BSTNode {
    private:
        BSTNode<X,Y>* left;
        BSTNode<X, Y>* right;
        X val;
        Y key;

    public:
        BSTNode(X k, Y v) {
            key = k;
            val = v;
            left = nullptr;
            right = nullptr;
        }
    };

    BSTNode<K, V>* root;
    int size;
    V searchResult;

    // recursive function for insert
    BSTNode<K, V>* put(BSTNode<K, V>* node, K key, V val) {
        if (!node) {
            return new BSTNode<K, V>*(key, val);
        }
        if (key < node->key) {
            node->left = put(node->left, key, val);
        }
        else if (key > node->key) {
            node->right = put(node->right, key, val);
        }
        return node;
    }

    bool search(BSTNode<K, V>* node, K key) {
        if (!node) {
            return false;
        }
        if (key == node->key) {
            searchResult = node->val;
            return true;
        }
        else if (key < node->key) {
            node->left = put(node->left, key);
        }
        else if (key > node->key) {
            node->right = put(node->right, key);
        }
        
        return true;
    }

public:
    BSTMap() {
        size = 0;
        root = nullptr;
    }
    /** Removes all of the mappings from this map. */
    void clear() {
        root = nullptr;
    }

    /* Returns true if this map contains a mapping for the specified key.
     * Should run on average constant time when called on a HashMap.
     */
    bool contains(K key) {
        return search(root, key);
    }

    /* Returns the value to which the specified key is mapped, or null if this
     * map contains no mapping for the key. Should run on average constant time
     * when called on a HashMap.*/
    V* get(K key) {
        if (!contains(key)) {
            return nullptr;
        }
        else {
            return &searchResult;
        }
    }

    /* Returns the number of key-value mappings in this map. */
    int getSize() {
        return size;
    }

    /* Associates the specified value with the specified key in this map.
     * Should run on average constant time when called on a HashMap. */
    void insert(K key, V val) {
        size++;
        root = put(root, key, val);
    }
};

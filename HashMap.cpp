#include <vector>
using namespace std;

template <typename K, typename V>
class HashMap {
protected:
    // nested class
    template <typename X, typename Y>
    class Node {
    private:
        Node<X, Y>* next;
        X key;
        Y value;
    public:
        Node(X k, Y v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };
private:
    // Returns a new node to be placed in a hash table bucket
    Node<K,V>* createNode(K key, V val) {
        return new Node(key, val);
    }

    int hashFunction(K key) {
        return 0;
    }

    void resize() {
        // double the size of table
        int curSize = table.size();
        while (table.size() < 2 * curSize) {
            table.push_back(nullptr);
        }
        // need to move each element to new bucket (implementation omitted)
    }

    int size; // total number of elements stored in the hash map
    double loadFactor;
    double maxLoadFactor;
    vector<Node<K, V>*> table;

public:
    HashMap() {
        size = 0;
        loadFactor = 0;
        table = {};
    }
    HashMap(int initialSize) { 
        size = 0;
        loadFactor = 0;
        table = vector<Node<K, V>*>(initialSize, nullptr);
    }
    /**
     * MyHashMap constructor that creates a backing array of initialSize.
     * The load factor (# items / # buckets) should always be <= loadFactor
     * @param initialSize initial size of backing array
     * @param maxLoadFactor maximum load factor*/
    HashMap(int initialSize, double maxLF) {
        size = 0;
        loadFactor = 0;
        maxLoadFactor = maxLF;
        table = vector<Node<K, V>*>(initialSize, nullptr);
    }

    /** Removes all of the mappings from this map. */
    void clear() {
        for (int i = 0; i < table.size(); i++) {
            table[i] = nullptr;
        }
    }

    /* Returns true if this map contains a mapping for the specified key.
     * Should run on average constant time when called on a HashMap.
     */
    bool contains(K key) {
        int hashCode = hashFunction(key);
        int i = hashCode % table.size();
        Node<K, V>* p = table[i];

        if (!p) {
            return false;
        }
        
        while (p->next != nullptr) {
            if (p->key == key) {
                return true;
            }
            p = p->next;
        }
        return false;
    }

    /* Returns the value to which the specified key is mapped, or null if this
     * map contains no mapping for the key. Should run on average constant time
     * when called on a HashMap.*/
    V* get(K key) {
        int hashCode = hashFunction(key);
        int i = hashCode % table.size();
        Node<K, V>* p = table[i];

        if (!p) {
            return nullptr;
        }

        while (p->next != nullptr) {
            if (p->key == key) {
                return p->value;
            }
            p = p->next;
        }
        return nullptr;
    }

    /* Returns the number of key-value mappings in this map. */
    int getSize() {
        return size;
    }

    /* Associates the specified value with the specified key in this map.
     * Should run on average constant time when called on a HashMap. */
    void insert(K key, V val) {
        // update size
        size++; 

        // update lf
        loadFactor = size / (double)table.size();

        // resize by doubling the number of buckets
        if (loadFactor > maxLoadFactor) {
            resize(); 
        }

        // calculate the hash code for key
        int hashCode = hashFunction(key);

        // reduce hashCode to avoid overflow
        int index = hashCode % table.size();

        Node<K, V>* head = table[index];
        Node<K, V>* p;
        if (!head) {
            head = createNode(key, val);
        }
        else {
            // append to the end of linked list;
            p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = createNode(key, val);
        }
    }
};

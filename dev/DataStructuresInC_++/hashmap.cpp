#include <vector>



struct Node { // Custom Node struct stores key, value, and pointer to next node as collisions result in a linked list
    int key;
    int value;
    //int hash; hash will be same as int
    Node* next;

    Node(int k, int v) : key(k), value(v), next(nullptr) {}
};

class hashmap {
    std::vector<Node*> table;
    int size; // num key:value inserted

    int hash(const int key) { // Private method users dont need to call hash
        return key;
    }

    void resize() {
        int newSize = table.size() * 2;
        std::vector<Node*> newTable(newSize, nullptr);

        for (int i = 0; i < table.size(); i++) {
            if (table[i] == nullptr) continue;

            Node* top = table[i];
            while (top != nullptr) {
                Node* next = top->next;
                top->next = nullptr;

                int newBucket = top->key % newSize;
                if (newTable[newBucket] != nullptr) {
                    top->next = newTable[newBucket];
                }
                newTable[newBucket] = top;
                top = next;
            }
        }
        table = newTable;
    }

    void removeFromFront(Node* toRemove, const int bucket) {
            if (toRemove->next == nullptr) {
                table[bucket] = nullptr;
                return;
            }

            Node* next = toRemove->next;
            table[bucket] = next;
            return;
        }

    public:
        hashmap(): table(16, nullptr), size(0) {} // Constructor

        void put(const int key, const int value) { // add this key:value to the map
            Node* curr = new Node(key, value); // allocate new node for this key:value
            //curr.hash = hash(key);
            int bucket = key % table.size(); // Bucket to be inserted at

            if (table[bucket] != nullptr) {
                curr->next = table[bucket];
            }
            
            table[bucket] = curr;
            size++;

            if ((double)size / table.size() > 0.75) resize();
        }

        void remove(const int key) { // Remove this key:value from map
            int bucket = key % table.size();
            Node* top = table[bucket];
            if (top == nullptr) return;
            if (top->key == key) { removeFromFront(top, bucket);
                delete top;
                size--;
                return;
            }
            //Node to remove may be in the middle or the end in this case maintain the previous and next nodes
            Node* prev = nullptr;
            while (top != nullptr && top->key != key) {
                Node* next = top->next;
                prev = top;
                top = next;
            }

            Node* after = top->next == nullptr ? nullptr : top->next;
            prev->next = after;
            delete top;
            size--;
            return;
        }

        bool containsKey(const int key) { // Is this key in the map?
            int bucket = key % table.size();

            if (table[bucket] == nullptr) return false;

            Node* top = table[bucket];
            while (top != nullptr && top->key != key) {
                top = top->next;
            }
            return top != nullptr;
        }

        int get(const int key) { // Return value of this key
            if (!cotainsKey(key)) return -1 << 25;

            int bucket = key % table.size();
            Node* curr = table[bucket];
            while (curr->key != key) {
                curr = curr->next;
            }

            return curr->value;
        }
}


int main() {
    hashmap hm = hashmap();

    hm.put(5, 10);
    hm.put(3, 7);
    hm.put(1, 5);

    cout << "Does the map contain the key 6? (No): " << hm.containsKey(6) << '/n';

    hm.remove(3);

    cout << "Did the map remove 3? (should return false) " << hm.containsKey(3) << '/n/;
    
}
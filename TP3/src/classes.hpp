#include <iostream>
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* data;
    size_t size;
    size_t capacity;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    Vector() : data(nullptr), size(0), capacity(0) {}

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            resize(newCapacity);
        }
        data[size++] = value;
    }

    size_t getSize() const {
        return size;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range.");
        }
        return data[index];
    }

    // Iterator implementation
    class Iterator {
    private:
        T* ptr;

    public:
        Iterator(T* pointer) : ptr(pointer) {}

        bool operator!=(const Iterator& other) const {
            return ptr != other.ptr;
        }

        Iterator& operator++() {
            ++ptr;
            return *this;
        }

        T& operator*() const {
            return *ptr;
        }
    };

    Iterator begin() const {
        return Iterator(data);
    }

    Iterator end() const {
        return Iterator(data + size);
    }
};


template<typename Key, typename Value>
class Map {
private:
    struct Node {
        std::pair<Key, Value> data;
        Node* left;
        Node* right;

        Node(const Key& key, const Value& value)
            : data(key, value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insertNode(Node*& node, const Key& key, const Value& value) {
        if (node == nullptr) {
            node = new Node(key, value);
        } else if (key < node->data.first) {
            insertNode(node->left, key, value);
        } else if (key > node->data.first) {
            insertNode(node->right, key, value);
        } else {
            node->data.second = value;
        }
    }

    Value& findNode(Node* node, const Key& key) {
        if (node == nullptr) {
            throw std::out_of_range("Key not found in map.");
        } else if (key < node->data.first) {
            return findNode(node->left, key);
        } else if (key > node->data.first) {
            return findNode(node->right, key);
        } else {
            return node->data.second;
        }
    }

public:
    Map() : root(nullptr) {}

    void insert(const Key& key, const Value& value) {
        insertNode(root, key, value);
    }

    Value& operator[](const Key& key) {
        try {
            return findNode(root, key);
        } catch (const std::out_of_range& e) {
            insertNode(root, key, Value());
            return findNode(root, key);
        }
    }

    // Iterator implementation
    class Iterator {
    private:
        std::vector<Node*> store;
        int index;

    public:
        Iterator(Node* root) : index(0) {
            traverse(root);
        }

        void traverse(Node* node) {
            if (node == nullptr) {
                return;
            }
            traverse(node->left);
            store.push_back(node);
            traverse(node->right);
        }

        bool operator!=(const Iterator& other) const {
            return index != other.store.size();
        }

        Iterator& operator++() {
            ++index;
            return *this;
        }

        std::pair<Key, Value>& operator*() const {
            return store[index]->data;
        }
    };

    Iterator begin() const {
        return Iterator(root);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }
};
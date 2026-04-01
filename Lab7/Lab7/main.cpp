#include <iostream>

float operator"" _Kelvin(unsigned long long int k) {
    return (float)k - 273.15f;
}

float operator"" _Fahrenheit(unsigned long long int f) {
    return ((float)f - 32.0f) * 5.0f / 9.0f;
}

template <class T>
class Tree {
public:
    struct Node {
        T value;
        Node** children;
        unsigned int count;
        unsigned int capacity;

        Node(T val);
    };

private:
    Node* root;

public:
    Tree();
    ~Tree();

    Node* add_node(Node* parent, T val);
    Node* get_node(Node* parent);
    void delete_node(Node* node);
    Node* find(Node* node, T val, bool (*compare)(T, T));
    Node* insert(Node* parent, T val, unsigned int index);
    void sort(Node* node, bool (*compare)(T, T) = nullptr);
    unsigned int count(Node* node);
};

template <class T>
Tree<T>::Node::Node(T val) : value(val), count(0), capacity(10) {
    children = new Node * [capacity];
}

template <class T>
Tree<T>::Tree() : root(nullptr) {}

template <class T>
Tree<T>::~Tree() {
    delete_node(root);
}

template <class T>
typename Tree<T>::Node* Tree<T>::add_node(Node* parent, T val) {
    if (parent == nullptr) {
        if (root != nullptr) return nullptr;
        root = new Node(val);
        return root;
    }

    if (parent->count == parent->capacity) {
        parent->capacity *= 2;
        Node** tmp = new Node * [parent->capacity];
        for (unsigned int i = 0; i < parent->count; ++i)
            tmp[i] = parent->children[i];
        delete[] parent->children;
        parent->children = tmp;
    }

    Node* n = new Node(val);
    parent->children[parent->count++] = n;
    return n;
}

template <class T>
typename Tree<T>::Node* Tree<T>::get_node(Node* parent) {
    return (parent == nullptr) ? root : parent;
}

template <class T>
void Tree<T>::delete_node(Node* node) {
    if (node == nullptr) return;
    for (unsigned int i = 0; i < node->count; ++i)
        delete_node(node->children[i]);
    delete[] node->children;
    delete node;
}

template <class T>
typename Tree<T>::Node* Tree<T>::find(Node* node, T val, bool (*compare)(T, T)) {
    if (node == nullptr) return nullptr;
    if (compare(node->value, val)) return node;
    for (unsigned int i = 0; i < node->count; ++i) {
        Node* res = find(node->children[i], val, compare);
        if (res != nullptr) return res;
    }
    return nullptr;
}

template <class T>
typename Tree<T>::Node* Tree<T>::insert(Node* parent, T val, unsigned int index) {
    if (parent == nullptr) {
        if (root == nullptr && index == 0) {
            root = new Node(val);
            return root;
        }
        return nullptr;
    }
    if (index > parent->count) return nullptr;

    if (parent->count == parent->capacity) {
        parent->capacity *= 2;
        Node** tmp = new Node * [parent->capacity];
        for (unsigned int i = 0; i < parent->count; ++i)
            tmp[i] = parent->children[i];
        delete[] parent->children;
        parent->children = tmp;
    }

    for (unsigned int i = parent->count; i > index; --i)
        parent->children[i] = parent->children[i - 1];

    Node* n = new Node(val);
    parent->children[index] = n;
    ++parent->count;
    return n;
}

template <class T>
void Tree<T>::sort(Node* node, bool (*compare)(T, T)) {
    if (node == nullptr || node->count < 2) return;
    for (unsigned int i = 0; i < node->count - 1; ++i) {
        for (unsigned int j = 0; j < node->count - i - 1; ++j) {
            bool shouldSwap = false;
            if (compare) {
                if (compare(node->children[j + 1]->value, node->children[j]->value))
                    shouldSwap = true;
            }
            else {
                if (node->children[j + 1]->value < node->children[j]->value)
                    shouldSwap = true;
            }
            if (shouldSwap) {
                Node* temp = node->children[j];
                node->children[j] = node->children[j + 1];
                node->children[j + 1] = temp;
            }
        }
    }
}

template <class T>
unsigned int Tree<T>::count(Node* node) {
    node = get_node(node);
    if (node == nullptr) return 0;
    unsigned int total = node->count;
    for (unsigned int i = 0; i < node->count; ++i)
        total += count(node->children[i]);
    return total;
}

bool cmpInt(int a, int b) { return a == b; }
bool descInt(int a, int b) { return a > b; }

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    std::cout << "300 Kelvin = " << a << " Celsius\n";
    std::cout << "120 Fahrenheit = " << b << " Celsius\n";

    Tree<int> tree;
    Tree<int>::Node* root = tree.add_node(nullptr, 10);
    Tree<int>::Node* child1 = tree.add_node(root, 5);
    Tree<int>::Node* child2 = tree.add_node(root, 15);
    tree.add_node(child1, 2);
    tree.add_node(child1, 8);
    tree.add_node(child2, 12);
    tree.add_node(child2, 18);

    std::cout << "Total nodes: " << tree.count(nullptr) + 1<< "\n";

    Tree<int>::Node* found = tree.find(root, 8, cmpInt);
    if (found) std::cout << "Found node with value 8\n";

    tree.sort(root, descInt);

    return 0;
}
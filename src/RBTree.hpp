#pragma once

#include <cassert>
#include <iostream>
#include <string>

#define DECLARE_RULE5(Class, Action)               \
    Class(const Class &other) = Action;            \
    Class(Class &&other) = Action;                 \
    Class &operator=(const Class &other) = Action; \
    Class &operator=(Class &&other) = Action

#define DISABLE_COPY(Class) \
    DECLARE_RULE5(Class, delete);

enum Color
{
    RED,
    BLACK
};

template <typename Type>
class RBTree
{

    class Node
    {
    private:
        std::string key;
        Type *value;
        Color color;
        Node *left, *right, *parent;

    public:
        explicit Node(Type *value, std::string key, Color color = RED, Node *left = nullptr, Node *right = nullptr, Node *parent = nullptr)
            : key(key), value(value), color(color), left(left), right(right), parent(parent)
        {
        }

        Node(const Node &other, Node *parent)
        {
            this->key = other.key;
            this->color = other.color;
            this->value = new Type(*other.value);
            this->parent = parent;
            if (other.left)
            {
                this->left = new Node(*other.left, this);
            }
            else
            {
                this->left = nullptr;
            }
            if (other.right)
            {
                this->right = new Node(*other.right, this);
            }
            else
            {
                this->right = nullptr;
            }
        }

        ~Node()
        {
            delete this->value;
        }

    public:
        inline bool operator<(const Node &other) const { return this->key < other.key; }

        void setColor(Color color) { this->color = color; }
        void setLeft(Node *left) { this->left = left; }
        void setRight(Node *right) { this->right = right; }

        void setParent(Node *parent) { this->parent = parent; }
        std::string getKey() { return this->key; }
        Type *getValue() { return this->value; }
        Color getColor() { return this->color; }
        Node *getLeft() { return this->left; }
        Node *getRight() { return this->right; }
        Node *getParent() { return this->parent; }
    };

private:
    Node *root;
    int count;

public:
    RBTree()
    {
        this->root = nullptr;
        this->count = 0;
    }

    inline int getCount() { return this->count; }

    void insertNode(Node *node)
    {
        if (!this->root)
        {
            this->root = node;
            this->root->setColor(BLACK);
            this->root->setLeft(nullptr);
            this->root->setRight(nullptr);
        }
        else
        {
            Node *current = this->root;
            while (current)
            {
                if (*node < *current)
                {
                    if (!current->getLeft())
                    {
                        current->setLeft(node);
                        node->setParent(current);
                        break;
                    }
                    else
                    {
                        current = current->getLeft();
                    }
                }
                else
                {
                    if (!current->getRight())
                    {
                        current->setRight(node);
                        node->setParent(current);
                        break;
                    }
                    else
                    {
                        current = current->getRight();
                    }
                }
            }
        }
        node->setColor(RED);
        node->setLeft(nullptr);
        node->setRight(nullptr);
        this->count++;
        this->fixup(node);
    }

    void insertNode(Type *value, std::string key)
    {
        Node *node = new Node(value, key);
        this->insertNode(node);
    }

    Type *search(Node *node, std::string key)
    {

        // std::cout << "Searching for |" << key << "| in node: |" << node->getKey() <<"|"<< std::endl;
        if (node->getKey() == key)
        {
            // std::cout << "Found key: " << std::endl;
            return node->getValue();
        }
        else if (key < node->getKey())
        {
            if (node->getLeft())
            {
                // std::cout << "Going left" << std::endl;
                return this->search(node->getLeft(), key);
            }
        }
        else if (node->getKey() < key)
        {
            if (node->getRight())
            {
                // std::cout << "Going right" << std::endl;
                return this->search(node->getRight(), key);
            }
        }
        return nullptr;
    }

    void printTreeOrder()
    {
        int conter = 1;
        for (Iterator it = this->begin(); it != this->end(); ++it)
        {
            std::cout << "\t" << conter << ": " << it.getKey() << std::endl;
            ++conter;
        }
        if (conter == 1)
        {
            std::cout << "Tree is empty" << std::endl;
        }
    }

    Type *searchPerNumber(int number)
    {
        int counter = 1;
        for (Iterator it = this->begin(); it != this->end(); ++it)
        {
            // std::cout << conter << ": "<< it.getKey() << std::endl;
            if (counter == number)
                return it.getValue();
            ++counter;
        }
        return nullptr;
    }

private:
    void leftRotate(Node *node)
    {
        Node *pivot = node->getRight();
        node->setRight(pivot->getLeft());

        if (pivot->getLeft())
        {
            pivot->getLeft()->setParent(node);
        }

        pivot->setParent(node->getParent());

        if (!node->getParent())
        {
            this->root = pivot;
        }
        else if (node == node->getParent()->getLeft())
        {
            node->getParent()->setLeft(pivot);
        }
        else
        {
            node->getParent()->setRight(pivot);
        }

        pivot->setLeft(node);
        node->setParent(pivot);
    }

    void rightRotate(Node *node)
    {
        Node *pivot = node->getLeft();
        node->setLeft(pivot->getRight());

        if (pivot->getRight())
        {
            pivot->getRight()->setParent(node);
        }

        pivot->setParent(node->getParent());

        if (!node->getParent())
        {
            this->root = pivot;
        }
        else if (node == node->getParent()->getRight())
        {
            node->getParent()->setRight(pivot);
        }
        else
        {
            node->getParent()->setLeft(pivot);
        }

        pivot->setRight(node);
        node->setParent(pivot);
    }

    void fixup(Node *node)
    {
        while (node->getParent() && node->getParent()->getColor() == RED)
        {
            if (node->getParent() == node->getParent()->getParent()->getLeft())
            {
                Node *uncle = node->getParent()->getParent()->getRight();
                if (uncle && uncle->getColor() == RED)
                {
                    node->getParent()->setColor(BLACK);
                    uncle->setColor(BLACK);
                    node->getParent()->getParent()->setColor(RED);
                    node = node->getParent()->getParent();
                }
                else
                {
                    if (node == node->getParent()->getRight())
                    {
                        node = node->getParent();
                        leftRotate(node);
                    }
                    node->getParent()->setColor(BLACK);
                    node->getParent()->getParent()->setColor(RED);
                    rightRotate(node->getParent()->getParent());
                }
            }
            else
            {
                Node *uncle = node->getParent()->getParent()->getLeft();
                if (uncle && uncle->getColor() == RED)
                {
                    node->getParent()->setColor(BLACK);
                    uncle->setColor(BLACK);
                    node->getParent()->getParent()->setColor(RED);
                    node = node->getParent()->getParent();
                }
                else
                {
                    if (node == node->getParent()->getLeft())
                    {

                        node = node->getParent();
                        rightRotate(node);
                    }
                    node->getParent()->setColor(BLACK);
                    node->getParent()->getParent()->setColor(RED);
                    leftRotate(node->getParent()->getParent());
                }
            }
        }
        this->root->setColor(BLACK);
    }

    void clear(Node *node)
    {
        if (node != nullptr)
        {
            this->clear(node->getLeft());
            this->clear(node->getRight());
            delete node;
        }
    }

    static Node *findMinimum(Node *subtree)
    {
        if (subtree)
        {
            while (subtree->getLeft())
            {
                subtree = subtree->getLeft();
            }
        }
        return subtree;
    }

    static Node *findMaximum(Node *subtree)
    {
        if (subtree)
        {
            while (subtree->getRight())
            {
                subtree = subtree->getRight();
            }
        }
        return subtree;
    }

    static Node *findNextNode(Node *current)
    {
        Node *original = current;
        if (current->getRight())
        {
            return findMinimum(current->getRight());
        }
        while (current->getParent() && current == current->getParent()->getRight())
        {
            current = current->getParent();
            if (!current->getParent())
            {
                return nullptr;
            }
        }
        if (current && current->getParent() && current == current->getParent()->getLeft())
            current = current->getParent();

        return current == original ? nullptr : current;
    }

public:
    class Iterator
    {

    private:
        Node *node;

    public:
        explicit Iterator(Node *node)
            : node(node)
        {
        }

        DECLARE_RULE5(Iterator, default);

        inline bool operator!=(const Iterator &other) const
        {
            return this->node != other.node;
        }

        inline bool operator==(const Iterator &other) const
        {
            return this->node == other.node;
        }

        inline std::string getKey()
        {
            assert(this->node);
            return this->node->getKey();
        }

        inline const std::string getKey() const
        {
            assert(this->node);
            return this->node->getKey;
        }

        inline Type *getValue()
        {
            assert(this->node);
            return this->node->getValue();
        }

        inline const Type &getValue() const
        {
            assert(this->node);
            return this->node->getValue();
        }

        inline Color getColor() const
        {
            assert(this->node);
            return this->node->getColor();
        }

        inline Iterator &operator++()
        {
            this->node = RBTree::findNextNode(this->node);
            return *this;
        }

        inline Iterator operator++(int)
        {
            Iterator temp = *this;
            this->node = RBTree::findNextNode(this->node);
            return temp;
        }
    };

    Iterator begin() const
    {
        return Iterator(this->findMinimum(this->root));
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }
    Node *getRoot() const { return this->root; }

    Iterator cbegin() const
    {
        return Iterator(nullptr);
    }

    Iterator cend() const
    {
        return Iterator(this->findMaximum(this->root));
    }

    RBTree(const RBTree &other)
    { // copy constructor
        if (other.root == nullptr)
        {
            this->root = nullptr;
            this->count = 0;
        }
        else
        {
            this->root = new Node(*(other.root), nullptr);
            this->count = other.count;
        }
    }

    RBTree(RBTree &&other)
    { // move constructor
        //std::cout << "---move contructor---" << std::endl;
        this->root = other.root;
        this->count = other.count;
        other.root = nullptr;
        other.count = 0;
    }

    RBTree &operator=(const RBTree &other)
    { // copy assignment
        if (this != &other)
        {
            if (this->root != nullptr)
            {
                this->clear(this->root);
            }
            this->root = new Node(*(other.root), nullptr);
            this->count = other.count;
        }
        return *this;
    }

    RBTree &operator=(RBTree &&other)
    { // move assignment
        // std::cout << "---move assignment---" << std::endl;
        if (this != &other)
        {
            if (this->root != nullptr)
            {
                this->clear(this->root);
            }
            this->root = other.root;
            this->count = other.count;
            other.root = nullptr;
            other.count = 0;
        }
        return *this;
    }

    ~RBTree()
    { // destructor
        if (this->root != nullptr)
        {
            this->clear(this->root);
            this->root = nullptr;
            this->count = 0;
        }
    }
};
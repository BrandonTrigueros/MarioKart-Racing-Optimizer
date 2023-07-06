#pragma once

#include <cassert>
#include <iostream>
#include <string>

enum Color {
    RED,
    BLACK
};

template <typename Type>
class RBTree {

    class Node {
        private:
            std::string key;
            Type value;
            Color color;
            Node *left, *right, *parent;

        public:
            explicit Node(Type& value, std::string key = value.name, Color color = RED, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr)
                : key(key), value(value), color(color), left(left), right(right), parent(parent)
            {}

        public:
            inline bool operator<(const Node& other) const {return this->key < other.key;}

            void setColor(Color color) {this->color = color;}
            void setLeft(Node* left) {this->left = left;}
            void setRight(Node* right) {this->right = right;}

            void setParent(Node* parent) {this->parent = parent;}
            std::string getKey() {return this->key;}
            Type& getValue() {return this->value;}
            Color getColor() {return this->color;}
            Node* getLeft() {return this->left;}
            Node* getRight() {return this->right;}
            Node* getParent() {return this->parent;}
    };

    private:
        Node* root;

    public:
        RBTree () {
            this->root = nullptr;
        }
        
        void insertNode(Node* node) {
            if (!this->root) {
                this->root = node;
                this->root->setColor(BLACK);
                this->root->setLeft(nullptr);
                this->root->setRight(nullptr);
            }
            else {
                Node* current = this->root;
                while (current) {
                    if (*node < *current) {
                        if (!current.getLeft()) {
                            current.setLeft(node);
                            node->setParent(current);
                            break;
                        }
                        else {
                            current = current.getLeft();
                        }
                    }
                    else {
                        if (!current.getRight()) {
                            current.setRight(node);
                            node->setParent(current);
                            break;
                        }
                        else {
                            current = current.getRight();
                        }
                    }
                }
            }
            node->setColor(RED);
            node->setLeft(nullptr);
            node->setRight(nullptr);
            this->fixup (node);
        }

        void insertNode(Type& value){
            Node* node = new Node(value);
            this->insertNode(node);
        }

    //     Node* search(Node* node, std::string key){

    //     }

    // private:
    //     void leftRotate(Node* node){

    //     }

    //     void rightRotate(Node* node){

    //     }

    //     void fixup(Node* node){

    //     }

    //     void clear(Node* node){

    //     }

        static Node *findMinimum(Node *subtree) {
            if (subtree) {
                while (subtree->left) {
                    subtree = subtree->left;
                }
            }
            return subtree;
        }

        static Node& findNextNodeOrder (Node* current) {
            Node* original = current;
            if (current->right) {
                return RNTree::findMinimum(node->right);
            }
            while (current->parent && current == current->parent->right) {
                current = node->parent;
                if (!current->parent) {
                    return = nullptr;
                }
            }
            if (current && current->parent && current == current->parent->left)
                current = current->parent;

            return current == original ? nullptr : current;
        }

        class Iterator {
            private:
                Node* node;

            public:
                explicit Iterator(Node* node)
                    : node(node)
                {}
                
                DECLARE_RULE5(Iterator, default);

                inline bool operator != (const Iterator& other) const {
                    return this->node != other.node;
                }

                inline std::string getKey() {
                    assert(this->node);
                    return this->node->key;
                }

                inline const std::string getKey() const {
                    assert(this->node);
                    return this->node->key;
                }

                inline Type& getValue()  {
                    assert(this->node);
                    return this->node->value;
                }

                inline const Type& getValue() const {
                    assert(this->node);
                    return this->node->value;
                }

                inline Iterator& operator ++() {
                    this->node = RBTree::findNextNodeOrder(this->node);
                    return *this;
                }

        };

        Iterator begin() {
                return Iterator(this->findMinimum(this->root));
        }

        Iterator end(){
                return Iterator(nullptr);
        }

    public:

        RBTree(const RBTree& other) {           //copy constructor
            for (Iterator it = other.begin(); it != other.end(); ++it) {
                this->insertNode(it.getValue());
            }
        }

        RBTree(RBTree&& other){                 //move constructor

        }

        RBTree& operator=(const RBTree& other){ //copy assignment

        }

        RBTree& operator=(RBTree&& other){      //move assignment

        }

        ~RBTree(){                              //destructor
            this->clear(this->root);
        }
};
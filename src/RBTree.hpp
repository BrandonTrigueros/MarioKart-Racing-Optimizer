#pragma once

#include <cassert>
#include <iostream>
#include <string>

#define DECLARE_RULE5(Class, Action)               \
    Class(const Class &other) = Action;            \
    Class(Class &&other) = Action;                 \
    Class &operator=(const Class &other) = Action; \
    Class &operator=(Class &&other) = Action        \

#define DISABLE_COPY(Class) \
    DECLARE_RULE5(Class, delete);

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
            explicit Node(Type& value, std::string key, Color color = RED, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr)
                : key(key), value(value), color(color), left(left), right(right), parent(parent)
            {}

        public:
            inline bool operator<(const Node& other) const {return this->key < other.key;}

            void setColor(Color color) {this->color = color;}
            void setLeft(Node* left) {this->left = left;}
            void setRight(Node* right) {this->right = right;}

            void setParent(Node* parent) {this->parent = parent;}
            std::string getKey() {return this->key;}
            Type* getValue() {return &this->value;}
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
                        if (!current->getLeft()) {
                            current->setLeft(node);
                            node->setParent(current);
                            break;
                        }
                        else {
                            current = current->getLeft();
                        }
                    }
                    else {
                        if (!current->getRight()) {
                            current->setRight(node);
                            node->setParent(current);
                            break;
                        }
                        else {
                            current = current->getRight();
                        }
                    }
                }
            }
            node->setColor(BLACK);
            node->setLeft(nullptr);
            node->setRight(nullptr);
            //this->fixup (node);
        }

        void insertNode(Type value, std::string key){
            Node* node = new Node(value, key);
            this->insertNode(node);
        }

    //     Node* search(Node* node, std::string key){

    //     }
        Type* search(Node* node, std::string key){

            // std::cout << "Searching for |" << key << "| in node: |" << node->getKey() <<"|"<< std::endl;
            if(node->getKey() == key) {
                //std::cout << "Found key: " << std::endl;
                return node->getValue();
            }
            else if(key < node->getKey()){
                if (node->getLeft()){
                    //std::cout << "Going left" << std::endl;
                    return this->search(node->getLeft(), key);
                }
            }
            else if(node->getKey() < key){
                if (node->getRight()){
                    //std::cout << "Going right" << std::endl;
                    return this->search(node->getRight(), key);
                }
            }
            return nullptr;
        }

        void printTreeOrder (){
            int conter = 1;
            for (Iterator it = this->begin(); it != this->end(); ++it){
                std::cout << "\t" << conter << ": "<< it.getKey() << std::endl;
                ++conter;
            }
        }
        
        Type* searchPerNumber (int number){
            int counter = 1;
            for (Iterator it = this->begin(); it != this->end(); ++it){
                // std::cout << conter << ": "<< it.getKey() << std::endl;
                if (counter == number)
                    return it.getValue();
                ++counter;
            }
            return nullptr;
        }

    // private:
    //     void leftRotate(Node* node){

    //     }

    //     void rightRotate(Node* node){

    //     }

    //     void fixup(Node* node){

    //     }

        // void clear(Node* node){
            
        // }

        static Node* findMinimum(Node* subtree) {
            if (subtree) {
                while (subtree->getLeft()) {
                    subtree = subtree->getLeft();
                }
            }
            return subtree;
        }

        static Node* findNextNode(Node* current) {
            Node* original = current;
            if (current->getRight()) {
                return findMinimum(current->getRight());
            }
            while (current->getParent() && current == current->getParent()->getRight()) {
                current = current->getParent();
                if (!current->getParent()) {
                    return nullptr;
                }
            }
            if (current && current->getParent() && current == current->getParent()->getLeft())
                current = current->getParent();

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
                    return this->node->getKey();
                }

                inline const std::string getKey() const {
                    assert(this->node);
                    return this->node->getKey;
                }

                inline Type* getValue()  {
                    assert(this->node);
                    return this->node->getValue();
                }

                inline const Type& getValue() const {
                    assert(this->node);
                    return this->node->getValue();
                }

                inline Iterator& operator ++() {
                    this->node = RBTree::findNextNode(this->node);
                    return *this;
                }
        };

        Iterator begin() {
            return Iterator(this->findMinimum(this->root));
        }

        Iterator end(){
            return Iterator(nullptr);
        }
        Node* getRoot() {return this->root;}

    public:

        RBTree(const RBTree& other) {           //copy constructor
        }

        RBTree(RBTree&& other){                 //move constructor

        }

        RBTree& operator=(const RBTree& other){ //copy assignment

        }

        RBTree& operator=(RBTree&& other){      //move assignment

        }

        // ~RBTree(){                              //destructor
        //     this->clear(this->root);
        // }
};
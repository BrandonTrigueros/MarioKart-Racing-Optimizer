#pragma once

#include <string>

enum Color {
    RED,
    BLACK
};

template <typename Type>
class Node {
    private:    //ATRIBUTES
        std::string key;
        Type value;
        Color color;
        Node *left, *right, *parent;
    public:     //CONSTRUCTORS
        explicit Node() {               // Creates a nil node
            this->key = "nil";
            this->value = Type();       // TODO: default constructor for Type
            this->color = BLACK;
            left = right = parent = nullptr;
        }
        explicit Node(Type& value) {
            this->key = value.name;
            this->value = value;
            this->color = RED;
            left = right = parent = nullptr;
        }
    public:    //SETTERS AND GETTERS
        void setColor(Color color) {this->color = color;}
        void setLeft(Node<T>* left) {this->left = left;}
        void setRight(Node<T>* right) {this->right = right;}
        void setParent(Node<T>* parent) {this->parent = parent;}

        std::string getKey() {return this->key;}
        T& getValue() {return this->value;}
        Color getColor() {return this->color;}
        Node<T>* getLeft() {return this->left;}
        Node<T>* getRight() {return this->right;}
        Node<T>* getParent() {return this->parent;}
};

template <typename Type>
class RBTree {
    private:    //ATRIBUTES
        Node<Type> *root;
        Node<Type> *nil = new Node<Type>();

    public:     //CONSTRUCTORS
        RBTree () {
            this->root = this->nil;
        }
        explicit RBTree (Type& value) {
            this->root = new Node<Type>(value);
            this->root->setColor(BLACK);
            this->root->setLeft(this->nil);
            this->root->setRight(this->nil);
        }

    public:     //METHODS
        void insertNode(Node<Type>* node){
            if (this->root == this->nil) {
                this->root = node;
                this->root->setColor(BLACK);
                this->root->setLeft(this->nil);
                this->root->setRight(this->nil);
            }
            else {
                Node<Type> current = this->root;
                while (current != this->nil) {
                    if (node->getKey < current.getKey()) {
                        if (current.getLeft() == this->nil) {
                            current.setLeft(node);
                            node->setParent(current);
                            break;
                        }
                        else {
                            current = current.getLeft();
                        }
                    }
                    else {
                        if (current.getRight() == this->nil) {
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
            node->setLeft(this->nil);
            node->setRight(this->nil);
            this->fixup (node);
        }

        void insertNode(Type& value){
            Node<Type> node = new Node<Type>(value);
            this->insertNode(node);
        }

        Node<T>* search(Node<T> *node, std::string key){

        }

    private:    //FIX UP METHODS
        void leftRotate(Node<T>* node){

        }

        void rightRotate(Node<T>* node){

        }

        void fixup(Node<T>* node){

        }

        void clear(Node<T>* node){

        }

    public:     //RULE OF FIVE

        RBTree(const RBTree& other) {           //copy constructor

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
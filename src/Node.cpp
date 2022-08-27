#include "Node.hpp"

Node::Node(const int& data, const int& size, int* array, Node* left, Node* right){
    this->data = data;
    this->size = size;
    this->array = array;
    this->left = left;
    this->right = right;
    this->height = 0;
}

Node::~Node(){
    if(this->array != NULL){
        delete [] this->array;
    }
}

void Node::printScreen(){
    for(int i=0; i<this->size; i++){
        cout << this->array[i] << " ";
    }
}

void Node::set(int &size){
    this->size = size;
    size--;
}
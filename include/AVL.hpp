#ifndef AVL_HPP
#define AVL_HPP
#include <cmath>
#include "Node.hpp"
using namespace std;

class AVL{
	private:
		Node *root;	
		Node* SearchAndAdd(Node *,const int&, const int&, int*);
		Node* SwapWithLeftChild(Node*);
		Node* SwapWithRightChild(Node*);
		bool DeleteNode(Node*&);
		void preorder(Node*);
		//void postorderMax(Node*);
		//void postorderMin(Node*);
		int Height(Node*);
		void PrintLevel(Node*, int);
		bool Search(Node*, const int&);
		void postorderMax(Node *);
		void postorderMin(Node *);

	public:
		AVL();
		bool isEmpty()const;
		void Add(int,const int&, int*);
		void preorder();
		int Height();
		bool Search(const int&);
		void Clear();
		~AVL();
};

#endif

#include "AVL.hpp"
#include "Dosya.hpp"

Node* AVL::SearchAndAdd(Node *subNode, const int& item, const int& size, int* array){
	if(subNode == NULL) subNode = new Node(item, size, array); 
	else if(item < subNode->data){
		subNode->left = SearchAndAdd(subNode->left, item, size, array);
		
		if(Height(subNode->left) == Height(subNode->right)+2){
			if(item < subNode->left->data)//tek cevrim
				subNode = SwapWithLeftChild(subNode);
			else{//çift cevrim
				subNode->left = SwapWithRightChild(subNode->left);
				subNode = SwapWithLeftChild(subNode);
			}
		}
	}
	else if(item > subNode->data){
		subNode->right = SearchAndAdd(subNode->right, item, size, array);
		
		if(Height(subNode->right) == Height(subNode->left)+2){ 
			if(item > subNode->right->data)//tek cevrim
				subNode = SwapWithRightChild(subNode);
			else{//çift cevrim
				subNode->right = SwapWithLeftChild(subNode->right);
				subNode = SwapWithRightChild(subNode);
			}
		}
	}
	else;
	
	subNode->height = Height(subNode);
	return subNode;
}
Node* AVL::SwapWithLeftChild(Node *subNode){
    Node *tmp = subNode->left;
	subNode->left = tmp->right;
	tmp->right = subNode;

	subNode->height = Height(subNode);
	tmp->height = 1 + max(Height(tmp->left),subNode->height);

	Dosya *dosya = new Dosya();
	
    cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->array[subNode->size - 1] << " sayisi silinmistir" << endl;
    dosya->deleteElement(subNode->array,subNode->size, subNode->size-1);
    if(subNode->size > 0) subNode->size--;
	postorderMax(subNode->right);
    
    cout << tmp->data << " nolu dugum yukari ciktigi icin en kucuk " << tmp->array[0] << " sayisi silinmistir" << endl;
    dosya->deleteElement(tmp->array,tmp->size, 0);
   	if(tmp->size > 0) tmp->size--;
	postorderMin(tmp->left);
	
	//cout<<"tmp yukari cikar  ";
	//cout<<"subNode asagi iner "<< subNode->data << endl;
	//tmp yukarı çıkar dizideki en küçük sayı silinir // 0. indis
	//subNode asagi iner ve dizideki en büyük sayi silinir //dizinin son elemanı
	delete dosya;
	return tmp;
}
Node* AVL::SwapWithRightChild(Node *subNode){
	Node *tmp = subNode->right;
	subNode->right = tmp->left;
	tmp->left = subNode;
	
	subNode->height = Height(subNode);
	tmp->height = 1+max(Height(tmp->right),subNode->height);
	Dosya *dosya = new Dosya();

	cout << subNode->data << " "  << " nolu dugum asagi indigi icin en buyuk " << subNode->array[subNode->size - 1] << " sayisi silinmistir" << endl;
	dosya->deleteElement(subNode->array,subNode->size, subNode->size-1);
	if(subNode->size > 0) subNode->size--;
	postorderMax(subNode->left);

	cout << tmp->data << " " << tmp->size << " nolu dugum yukari ciktigi icin en kucuk " << tmp->array[0] << " sayisi silinmistir" << endl;
	dosya->deleteElement(tmp->array,tmp->size, 0);
	if(tmp->size > 0) tmp->size--;
	postorderMin(tmp->right);

	//cout << tmp->array[0] << "  yukari ilk deger silindi"<< endl; // ilk degeri sil yeni diziye ata eski değerleri 
	//cout<<"tmp yukari cikar (SwapWithRightChild)  "<< tmp->data <<endl;
	//cout<<"subNode asagi iner (SwapWithRightChild)"<< subNode->data << endl;
	//tmp yukarı çıkar dizideki en küçük sayı silinir // 0. indis
	//subNode asagi iner ve dizideki en büyük sayi silinir //dizinin son elemanı
	delete dosya;
	return tmp;
}
bool AVL::DeleteNode(Node *&subNode){
	Node *delNode = subNode;
	
	if(subNode->right == NULL) subNode = subNode->left;
	else if(subNode->left == NULL) subNode = subNode->right;
	else{
	delNode = subNode->left;
		Node *parentNode = subNode;
		while(delNode->right != NULL){
			parentNode = delNode;
			delNode = delNode->right;
		}
		subNode->data = delNode->data;
		if(parentNode == subNode) subNode->left = delNode->left;
		else parentNode->right = delNode->left;
	}
	delete delNode;
	return true;
}

void AVL::preorder(Node *subNode){
	if(subNode != NULL){
		cout << endl;
		cout << subNode->data << " : " ;
		for(int i=0; i< subNode->size; i++){
			cout << subNode->array[i] << "  ";
		}
		preorder(subNode->left);
		preorder(subNode->right);
	}
}
int AVL::Height(Node *subNode){
	if(subNode == NULL) return -1;
	return 1+max(Height(subNode->left),Height(subNode->right));
}
bool AVL::Search(Node *subNode,const int& item){
	if(subNode == NULL) return false;
	if(subNode->data == item) return true;
	if(item < subNode->data) return Search(subNode->left,item);
	else return Search(subNode->right,item);
}
void AVL::postorderMax(Node *subNode) {
	Dosya *dosya = new Dosya();
    if (subNode != NULL) {
        postorderMax(subNode->left);
        postorderMax(subNode->right);
        cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->array[subNode->size - 1] << " sayisi silinmistir" << endl;
		dosya->deleteElement(subNode->array, subNode->size, subNode->size-1);
		if(subNode->size > 0) subNode->size--;
    }
	delete dosya;
}

void AVL::postorderMin(Node *subNode) {
	Dosya *dosya = new Dosya();
    if (subNode != NULL) {
        postorderMin(subNode->left);
        postorderMin(subNode->right);
        cout << subNode->data << " nolu dugum yukari ciktigi icin en kucuk " << subNode->array[0] << " sayisi silinmistir" << endl; 
		dosya->deleteElement(subNode->array, subNode->size, 0); 
		if(subNode->size > 0) subNode->size--; 
    }
	delete dosya;
}
AVL::AVL(){
	root = NULL;
}
bool AVL::isEmpty()const{
	return root == NULL;
}
void AVL::Add(int item, const int& size, int* array){
	root = SearchAndAdd(root, item, size, array);	
}
void AVL::preorder(){
	cout << endl << "Preorder Yazim Sekli :" ;
	preorder(root);
}
int AVL::Height(){
	return Height(root);
}
bool AVL::Search(const int& item){
	return Search(root,item);
}
void AVL::Clear(){
    while(!isEmpty()) DeleteNode(root);
}
AVL::~AVL(){
	Clear();
}

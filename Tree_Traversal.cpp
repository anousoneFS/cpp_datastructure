#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	
	Node(){
		left = NULL;
		right = NULL;
	}
	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
};

class Tree{
	public:
		Node *root = NULL;
		Node *left = NULL;
		Node *right = NULL;
		
	Node *newNode(int value){
		Node *temp = new Node(value);
		return temp;
	}
	
	void setLeft(int value){
		left = newNode(value);
	}
	void setRight(int value){
		right = newNode(value);
	}
//	void setData(int value){
//		data = value;
//	}
	Node *getLeft(){
		return left;
	}
	Node *getRight(){
		return right;
	}
//	int getData(){
//		return data;
//	}
	void preorder(Node *newNode){
		if(newNode != NULL){
			cout<<newNode->data<<endl;
			preorder(newNode->left);
			preorder(newNode->right);
			return;
		}
	}
};

int main(){
	Node *root = new Node(16);
	Tree *mytree = new Tree();
	mytree->root = root;
	
	mytree->setLeft(11);
	mytree->setRight(18);
	mytree->left->setLeft(10);
	
	mytree->preorder(root);
	
	return 0;
}

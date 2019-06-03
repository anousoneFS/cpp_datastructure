#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *left;
	Node *right;
	Node(){
		left=NULL;
		right=NULL;
	}
	Node(int value){
		data = value;
		left = NULL;
		right = NULL;
	}
};

struct Node *newNode(int value){
	Node *temp = new Node(value);
	return temp;
}

struct Node *insert(struct Node *node, int value){
	if(node == NULL){
		return newNode(value);
	}
	if(value < node->data){
		node->left = insert(node->left, value);
	}else{
		node->right = insert(node->right, value);
	}
	return node;

}

void preorder(struct Node *root){
	if(root != NULL){
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
int main(){
	Node *root = NULL;
	root = insert(root, 16);
	insert(root, 11);
	insert(root, 18);
	insert(root, 10);
	insert(root,26);
	insert(root,14);
	insert(root,13);
	insert(root,21);
	insert(root,20);
//	insert(root,20);
	insert(root,19);
	cout<<"after preorder Traversal: "<<endl;
	preorder(root);
	return 0;
}

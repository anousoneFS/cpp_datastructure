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
	
	//Create new Node	
	Node *newNode(int value){
		Node *newNode = new Node(value);
		return newNode;
	}
	
	//Add node into tree
	//begin------------------------------
	void insert(int value){
		if(root != NULL){
			insertV2(root, value);
		}else{
			root = newNode(value);
		}
	}
	Node *insertV2(Node *node, int value){
		if(value == node->data){
			cout<<"can not insert"<<endl;
		//if value less than current node insert at left
		}else if(value < node->data){
			if(node->left != NULL){
				node->left = insertV2(node->left, value);
			}else{
				//Create node of left node
				node->left = newNode(value);
			}
			
		//else insert at right	
		}else{
			if(node->right != NULL){
				node->right = insertV2(node->right, value);
			}else{
				//Create new Node at right 
				node->right = newNode(value);
			}
			
		}
		return node;
	}
	//the end-----------------------------------------------
	
	//preorder Traversal
	//begin------------------------------------------------
	void preorder(){
		if(root != NULL){
			cout<<"AFTER PREORDER TRAVERSAL: "<<endl;
			preorderV2(root);
			cout<<"\n";
		}else{
			cout<<"can not preorder"<<endl;
		}
	}
	void preorderV2(Node *node){
		if(node != NULL){
			cout<<node->data<<" ";
			preorderV2(node->left);
			preorderV2(node->right);
		}
	}
	//the end-----------------------------------------
	
	//count of leaf node of Tree
	//begin------------------------------------------
	void countLeafNode(){
		if(root != NULL){
			cout<<"count of leaf node of Tree is "<<countLeafNodeV2(root)<<endl;
		}else{
			cout<<"can not "<<endl;
		}
	}
	
	int countLeafNodeV2(Node *node){
		if(node == NULL){
			return 0;
		}else if(node->left == NULL && node->right == NULL){
			return 1;
		}else{
			return 	countLeafNodeV2(node->left) + countLeafNodeV2(node->right);
		}
	}
	//the end-----------------------------------------
};

int main(){
	Tree *tree = new Tree();
	tree->insert(35);
	tree->insert(13);
	tree->insert(72);
	tree->insert(9);
	tree->insert(16);
	tree->insert(54);
//	tree->insert(83);
//	tree->insert(55);
	tree->preorder();
	tree->countLeafNode();
}

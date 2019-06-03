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
		
	//Create Node
	Node *newNode(int value){
		Node *newNode = new Node(value);
		return newNode;
	}
	
	//begin ------------------------------------------
	//add node into tree
	void insert(int value){
		if(root == NULL){
			root = newNode(value);		
		}else{
			insertV2(root, value);
		}
	}
	Node *insertV2(Node *node, int value){
		if(value == node->data){
			cout<<"can not insert"<<endl;
		
		}else if(value < node->data){
			if(node->left != NULL){
				node->left = insertV2(node->left, value);	
			}else{
				node->left = newNode(value);
			}
			
		
		}else{
			if(node->right != NULL){
				node->right = insertV2(node->right, value);	
			}else{
				node->right = newNode(value);
			}
		}
		
		return node;
	}
	//the end-------------------------------------------
	
	//begin-----------------------------------------
	// preorder Traversal
	void preorder(){		
		if(root != NULL){
			cout<<"AFTER PREORDER TRAVERSAL:"<<endl;
			preorderV2(root);
			cout<<endl;
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
	//the end------------------------------------------
	
	//begin ---------------------------------------------
	// main function
	void breadthFirstTraversal(){
		if(root != NULL){
			cout<<"AFTER Breadth First Traversal: "<<endl;
			breadthFirstTraversalV2(root);
		}else{
			cout<<"root is empty"<<endl;
		}
	}
	
	void breadthFirstTraversalV2(Node *node){
		// h is height of Tree
		int h = height(node);  
		
		//print each level of Tree
		for(int i=1; i<=h; i++){
			printBFT(node, i);   
		}
	}
	
	//height of Tree
	int height(Node *node){
		//if node->left = NULL or node->right = NULL
		if(node == NULL){
			return 0;
		}
		
		int leftHeight = height(node->left);
		int rightHeight = height(node->right);
		
		//decide leftHeight+1 or rightHeight+1	
		if(leftHeight > rightHeight){
			return leftHeight+1;
		}else{
			return rightHeight+1;
		}
	}
	
	// test function height
	void h(){
		cout<<height(root);
	}
	
	// print node at level 1
	int printBFT(Node *node, int level){
		//empty node can not print
		if(node == NULL){ 
		return 0;
		
		}else{
			
			if(level == 1){
				cout<<node->data<<" ";
			
			//if level > 1
			}else{  
				printBFT(node->left, level-1);
				printBFT(node->right, level-1);
			}
		}		
	}
	//the end ------------------------------------------
};

int main(){
	Tree *myTree = new Tree();
	myTree->insert(35);
	myTree->insert(13);
	myTree->insert(72);
	myTree->insert(9);
	myTree->insert(16);
	myTree->insert(54);
	myTree->insert(83);
	myTree->insert(7);
	myTree->insert(24);
	
	myTree->preorder();
	myTree->breadthFirstTraversal();
	
	return 0;
}

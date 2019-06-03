#include<iostream>
using namespace std;

int id;
int append[10];

struct Node{
	int data;
	int index;
	Node *left;
	Node *right;
	Node(){
		left = NULL;
		right = NULL;
	}
	Node(int value, int id){
		data = value;
		index = id;
		left = NULL;
		right = NULL;
	}
};

class Tree{
	public:
		Node *root;
		
		Node *newNode(int value, int id){
			Node *newNode = new Node(value, id);
			return newNode;
		}
		
		//function insert
		//begin--------------------------------
		void insert(int value){
			if(root == NULL){
				root = newNode(value, 1);
			}else{
				id = 1;
				insertV2(root, value);
			}
		}
		void insertV2(Node *node, int value){
			if(value == node->data){
				cout<<"!! can not insert"<<endl;
			// LEFT
			}else if(value < node->data){
				if(node->left != NULL){
					id++;
					insertV2(node->left, value);
				}else{
					id++;
					node->left = newNode(value, id);
				}
			// RIGHT
			}else{
				if(node->right != NULL){
					id++;
					insertV2(node->right, value);
				}else{
					id++;
					node->right = newNode(value, id);
				}
			}
		}
		//the end--------------------------------------
		
		//function preorder traversal
		//begin----------------------------------------
		void preorder(){
			if(root != NULL){
				cout<<"AFTER PREORDER TRAVERSAL: "<<endl;
				preorderV2(root);
				cout<<endl;
			}else{
				cout<<"can not"<<endl;
			}
		}
		
		void preorderV2(Node *node){
			if(node != NULL){
				cout<<node->data<<" ";
				preorderV2(node->left);
				preorderV2(node->right);
			}
		}
		//function Root to Leaf Paths
		//begin----------------------------
		void root2LeafPath(){
			if(root != NULL){
				cout<<"Root to Leaf Path is :"<<endl;
				root2LeafPathV2(root, append);
			}else{
				cout<<"can not"<<endl;
			}
		}
		
		Node *root2LeafPathV2(Node *node, int append[]){
			if(node == NULL){
				return node;	
			}
			append[node->index-1] = node->data;
			if(node->left == NULL && node->right == NULL){
				for(int i=0; i <= node->index - 1; i++){
					cout<<append[i]<<" ";
				}
				cout<<endl;
			}else{
				root2LeafPathV2(node->left,append);
				root2LeafPathV2(node->right,append);
			}
		}
		//the end--------------------------------------
		
		//my own function Root to Leaf Paths
		//begin-----------------------------------------
		
};

int main(){
	Tree *t = new Tree();
	t->insert(10);
	t->insert(4);
	t->insert(18);
	t->insert(3);
	t->insert(20);
	t->insert(8);
	t->insert(2);
	t->insert(19);
	t->insert(15);
	t->preorder();
	
	t->root2LeafPath();
	return 0;
}

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
class Tree{
	public:
		Node *root = NULL;
		
	struct Node *newNode(int data){    // create newNode
		Node *temp = new Node(data);
		return temp;
	}

struct Node *insertV2(struct Node *node, int data){    // insert into Tree
	if(data == node->data){
		cout<<"can not insert "<<node->data<<endl;
	}
	else if(data < node->data){    // LEFT
		if(node->left != NULL){
			node->left = insertV2(node->left, data);	
		}else{
			node->left = newNode(data);     
		}
		
	}else{                      // RIGHT
		if(node->right != NULL){
			node->right = insertV2(node->right, data);	
		}else{
			node->right = newNode(data);
		}
	}
	return node;
}

struct Node *insert(int data){             // create root node
	if(root == NULL){
		root = newNode(data);
		return root;
	}else{
		return insertV2(root, data);
	}
}

void preorderV2(struct Node *node){        //preorder Traversal
	if(node != NULL){
		cout<<node->data<<" ";
		preorderV2(node->left);
		preorderV2(node->right);
	}
}
void preorder(){                    // if have root node --> preorder
	if(root != NULL){
		cout<<"--> AFTER PREORDER TRAVERSAL: ";
		preorderV2(root);
		cout<<'\n';
	}else{
		cout<<"root == NULL"<<endl;
	}
}
};
int length(int a[]){
	int n=0;
	while(a[n] != 83){
		n++;
	}
	return n+1;
}

int main(){
	
Tree *myTree = new Tree();	

int T[30] = {35,72,13,9,54,16,7,24,55,60,17,19,20,57,83};

int L = length(T);
for(int i = 0; i < L; i++){
	myTree->insert(T[i]);	
}
myTree->preorder();

//int n=0;
//while(T[n] != 83){
//	myTree->insert(T[n]);
//	n++;
//}
//myTree->insert(T[n]);
//myTree->preorder();
	
	
//char c;
//int x;
//
//cout<<"press 'i' for insert into Tree"<<endl;
//cout<<"press 'p' for preorder Traversal"<<endl;
//cout<<"press 'q' for close program\n"<<endl;

//// 35,72,13,9,54,16,7,24,55,60,17,19,20,57,83
//do{
//	cout<<"========>> choose your choice: ";
//	cin>>c;
//	
//	switch(c){
//		case 'i':
//			cout<<"---> enter VALUE: ";
//			cin>>x;
//			myTree->insert(x);
//			break;
//		case 'p':
//			myTree->preorder();
//			break;
//	}
//	
//}while(c != 'q');
//	
//cout<<"close program";

	return 0;
}

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

//-------------------------------------------------
void minNode(){
	Node *min = minValueNode(root);
	cout<<"min value node is "<<min->data<<endl;
}
Node *minValueNode(Node *node){            // find min value node
	Node *temp = node;
	while(temp->left != NULL){
		temp = temp->left;
	}
	return temp;
}

//------------------------------------------------------------
Node *removeV2(Node *node, int data){     // remove node
	if(data < node->data){   // LEFT
		node->left = removeV2(node->left, data);
		
	//---------------------------------------------
	}else if(data > node->data){  // RIGHT
		node->right = removeV2(node->right, data);
	
	//-------------------------------------------
	}else{ // if found --> removing node
		// if Node have one child or not
		if(node->left == NULL){
			Node *temp = node->right;
			node = NULL;
			return temp;
		}else if(node->right == NULL){
			Node *temp = node->left;
			node = NULL;
			return temp;
			
		// -------------------------------
		}else{  // if Node have two childes
			Node *MIN = minValueNode(node->right);
			node->data = MIN->data;
			node->right = removeV2(node->right, MIN->data);
		}
	}
	return node;
}
Node *remove(int data){
	if(root != NULL){
		return removeV2(root, data);
	}else{
		cout<<"can not remove"<<endl;
	}
}

//--------------------------------------------------
Node *findV2(Node *node, int data){       // function find
	if(data == node->data){               // found node
		cout<<"yes the tree have "<<data<<endl;
	}else if(data < node->data){      // LEFT
		if(node->left != NULL){
			findV2(node->left, data);
		}else{
			cout<<"no the tree don't have "<<data<<endl;
		}
	}else{                            // RIGHT
		if(node->right != NULL){
			findV2(node->right, data);
		}else{
			cout<<"no the tree don't have "<<data<<endl;
		}
	}
}
void find(int data){               // before find
	if(root != NULL){
		findV2(root, data);
	}else{
		cout<<"root is empty"<<endl;
	}
}

//----------------------------------------------------
void preorderV2(struct Node *node){        // PREORDER
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
		cout<<"!! root is empty"<<endl;
	}
}

//-----------------------------------------------
void inorderV2(Node *node){          // INORDER
	if(node != NULL){
		inorderV2(node->left);
		cout<<node->data<<" ";
		inorderV2(node->right);
	}
}
void inorder(){
	if(root != NULL){
		cout<<"---> AFTER INORDER TRAVERSAL: ";
		inorderV2(root);
		cout<<endl;
	}else{
		cout<<"!! root is empty"<<endl;
	}
}

// ----------------------------------
void postorderV2(Node *node){
	if(node != NULL){
		postorderV2(node->left);
		postorderV2(node->right);
		cout<<node->data<<" ";
	}
}
void postorder(){
	if(root != NULL){
		cout<<"--> AFTER POSTORDER TRAVERSAL: ";
		postorderV2(root);
		cout<<endl;
	}else{
		cout<<"!! root is empty"<<endl;
	}
	
}
};

//----------------------------------
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

myTree->remove(35);
myTree->preorder();

myTree->find(83);

return 0;
}

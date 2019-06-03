#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	
	Node(){
	next = NULL;
	}
	Node(int value){
		data = value;
		next = NULL;
	}
};

class LinkList{
	public:
		Node *head;
		Node *tail;
	
	void addToTail(int value){
		Node *newNode = new Node(value);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		
	}
	
	void addToHead(int value){
		Node *newNode = new Node(value);
		
		if(head==NULL){
			head=newNode;
			tail=newNode;
		}else{
			newNode->next=head;
			head=newNode;
		}
	}
	
	int length(){
		Node *cur = new Node;
		cur=head;
		int l=0;
		while(cur!=NULL){
			cur = cur->next;
			l++;
		}
		return l;
	}
	void insert(int id, int value){
		int len = length();
		
		if(id == 1){
			addToHead(value);
		}
		else if(id == len+1){
			addToTail(value);
		}
		else if(id>1 && id<=len){
			Node *newNode = new Node(value);
			Node *cur = new Node;
			
			cur = head;
			int i=2;
			while(cur!=NULL){
			
				if(id == i){
					newNode->next = cur->next;
					cur->next = newNode;
					break;
				}
				
				cur = cur->next;
				i++;
			}
		}else{
			cout<<"invalid Id"<<endl;
		}
						
	}
//	void deLeteTail(){
//		int len = length();
//		
//		if(head!=NULL){
//			Node *cur = new Node();
//			cur = head;
//			int z =1;
//			while(cur != NULL){
//				if(z == len-1){
//					cur->next = NULL;
//					tail=cur;
//				}
//				cur = cur->next;
//				z++;
//			}	
//		}
//	}
//	
	Node *deLeteTail(){
		int len = length();
		
		if(head!=NULL){
			Node *cur = new Node();
			Node *pre = new Node();
			Node *del = new Node();
			cur = head;
			int z =1;
			while(cur != NULL){
				if(z == len){
					del = cur;
					pre->next = NULL;
					tail=pre;
					
					delete cur;
					return del;
				}
				
				pre = cur;
				cur = cur->next;
				z++;
			}	
		}
	}
	
	Node *deLeteHead(){
		if(head!=NULL){	
			Node *pre = new Node;
			Node *cur = new Node;
			cur = head;	
			pre = cur;
			head = head->next;
			pre->next = NULL;
	
			delete cur;
			return pre;
			
		}else{
			cout<<"head == NULL"<<endl;
		}
	}
	Node *deleteIndex(int id){
		int n = 1;
		int len = length();
		
		//case:id at head
		if(id == 1){
			deLeteHead();
		}
		
		//case:id at tail
		if(id == len){
			deLeteTail();
		}
		
		//case:id at middle
		if(id>1 && id<len){
			Node *cur = new Node;
			Node *pre = new Node;
			Node *del = new Node;
			cur = head;
			
			while(cur!=NULL){
				if(id == n){
					del = cur;			
					pre->next = cur->next;
					cur->next=NULL;
					
					delete cur;
					return del; 
					break;
				}
				pre = cur;
				cur = cur->next;
				n++;
			}
		}
		
		// case: id not found
		if(id<=0 || id>len){
			if(len==0){
				cout<<"Empty LinkedList !!!"<<endl;
			}else{
				cout<<"invalid Id"<<endl;
			}
		}
	}
	
	Node *deleteValue(int value){
		Node *cur = new Node;
		Node *pre = new Node;
		cur = head;
		if(cur == NULL){
			cout<<"Empty LinkedList"<<endl;
		}
		while(cur!=NULL){
			
			if(value == cur->data){
				if(cur == head){	
					pre = cur;
					head = head->next;
					pre->next = NULL;
	
					delete cur;
					return pre;
	
				}else if(cur == tail){
					pre->next = NULL;
					tail=pre;
				}else{
					
					pre->next = cur->next;
					cur->next=NULL;
					
				}
			}
			pre = cur;
			cur = cur->next;
		}
	}
	
	void printFromId(int id){
		Node *cur = new Node;
		cur = head;
		int n=1;
		
		while(cur!=NULL){
			if(id == n){
				cout<<n<<".) "<<cur->data<<endl;
				n=0;
				break;
			}
			cur = cur->next;
			n++;
		}
		if(n!=0){
			cout<<"invalid Id"<<endl;
		}
	}
	void printAll(){
		Node *cur = new Node;
		cur = head;
		int n=1;	
		while(cur != NULL){
			
			cout<<n<<".) "<<cur->data<<endl;
			cur = cur->next;
			n++;
		}
		
	}
	
};

int main(){
	
	LinkList *myList = new LinkList();
	myList->addToHead(11);
	myList->addToHead(48);
	myList->addToHead(39);
	myList->addToTail(30);
	myList->printAll();

	cout<<"----------------"<<endl;

//	myList->deLeteTail();
//	myList->deLeteTail();
//	myList->deLeteHead();
//	myList->printAll();
	
	int x;
	do{
		
		cout<<"Enter Id: ";
		cin>>x;
		
//		cout<<"Enter Value: ";
//		cin>>y;
		
//		myList->deleteValue(x);
		myList->printFromId(x);
		
	}while( x!=0 );
	
}

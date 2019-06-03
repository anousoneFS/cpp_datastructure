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
		Node *head=NULL;
		Node *tail=NULL;
		
	void addToTail(int value){
		Node *newNode = new Node(value);
		
		if(head==NULL){
			head = newNode;
			tail = head;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
	}
	
	void sortList(){
		int temp;
		Node *i = new Node;
		Node *j = new Node;
		for(i=head; i->next != NULL; i=i->next){
			for(j = i->next; j != NULL; j = j->next){
				if(i->data > j->data){
					temp = i->data;
					i->data = j->data;
					j->data = temp;
				}
			}
//			printAll();
//			cout<<"======="<<endl;
		}
	}
	void printAll(){
		Node *cur= new Node;
		cur = head;
		int n=1;
		while(cur != NULL){
			cout<<n<<"). "<<cur->data<<endl;
			cur = cur->next;
			n++;
		}
	}
};

int main(){
	LinkList *mylist = new LinkList();
	mylist->addToTail(9);
	mylist->addToTail(6);
	mylist->addToTail(5);
	mylist->addToTail(2);
	mylist->addToTail(3);
	mylist->printAll();
	cout<<"after sortList"<<endl;
	mylist->sortList();
	mylist->printAll();
	
}

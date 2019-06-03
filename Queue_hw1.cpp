#include<iostream>
using namespace std;
#define SIZE 10

char A[SIZE];
int front = -1;
int rear = -1;

bool isempty(){
	if(front == -1 && rear == -1)
		return true;
	else
		return false;
}

void enqueue( char value){
	if(rear == SIZE - 1) // queue is full
		cout<<"Queue is full \n";
	else{
		if(front == -1) // first element is inserted
			front = 0;
		rear ++;
		A[rear] = value; // insert at rear
	}
}

void dequeue(){
	if(isempty())
		cout<<"Queue is empty\n";
	else{
		if(front == rear){ // only one element
			cout<<"delete "<<A[front]<<endl;
			front = rear = -1;
		}
		else{
			cout<<"delete "<<A[front]<<endl;
			front++;
		}
	}		
}

void showfront(){
	if(isempty())
		cout<<"Queue is empty\n";
	else
		cout<<"element at front is:"<<A[front]<<endl;
}

void displayQueue(){
	if(isempty())
		cout<<"Queue is empty\n";
	else{
		for(int i = front ; i<=rear; i++)
			cout<<A[i]<<endl;
	}
}

int main(){
	cout<<"press 'i' for insert to queue"<<endl;
	cout<<"press 'o' for delete from queue"<<endl;
	cout<<"press 'd' for displayQueue"<<endl;
	cout<<"press 'f' for showfront"<<endl;
	cout<<"press 'q' for exit "<<endl;
	char c;
	char x;
	do{
		cout<<"enter your choice:";
		cin>>c;
		
		if(c == 'i'){
			cout<<"enter value:";
			cin>>x;
			enqueue(x);
		}else if(c == 'o'){
			dequeue();
		}else if(c == 'd'){
			displayQueue();
		}else if(c == 'f'){
			showfront();
		}else if(c == 'q'){
			cout<<"close program!!!"<<endl;	
		}else{
			cout<<"ERROR"<<endl;
		}
		
	}while(c != 'q');
	
	return 0;
}

#include<iostream>
using namespace std;

int n=5;
char Q[n],x;
int front,rear;

void Enqueue(){
	if(rear == n){
		rear = 1;
	}else{
		rear= rear + 1;
		
	}
	if(front == rear){
		cout<<"full queue!!"
	}else{
		cout<<"please enter a element to queue:"<<endl;
		cin>>x;
		if(front==0){
			front = 1;
		}
	}
}

int main(){
	
}


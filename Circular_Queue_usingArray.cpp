#include<iostream>
using namespace std;

#define SIZE 5
int A[SIZE];
int front = -1, rear = -1;

bool isempty(){
	if(front == -1 && rear == -1){
		return true;
	}else{
		return false;
	}
}
void enqueue(int value){
	if((rear + 1)%SIZE == front){
		cout<<"!!! Queue is full"<<endl;
	}else{
		if(isempty()){
			front = rear = 0;
		}else if(rear == SIZE - 1){
			rear = 0;
		}else{
			rear ++;
		}
		A[rear] = value;
		cout<<"front= "<<front<<"; rear= "<<rear<<endl;
	}
}

void dequeue(){
	if(isempty()){
		cout<<"!!! Queue is empty"<<endl;
	}else{
		cout<<"you delete "<<A[front]<<" at front = "<<front<<endl;
		
		if(front == rear){
			front = rear = -1;
			cout<<"front= "<<front<<"; rear= "<<rear<<endl;
		}else{
			if(front == SIZE - 1){
				front = 0;
			}else{
				front ++;
			}
			cout<<"front= "<<front<<"; rear= "<<rear<<endl;
		}
	}
}

void display(){
	if(isempty()){
		cout<<"!!! can not display"<<endl;
	}else{
		int i, n = 1;	
		if(front <= rear){
			for(i = front; i <= rear; i++){
				cout<<n<<".) "<<A[i]<<" at "<<i<<endl;
				n++;
			}
		}else{     // front > rear
//			int c = rear;
//			for(int i = front; i != c ; i = (i + 1) % SIZE ){
//				if( i == rear+1 && i <= c-1){   // break loop
//					break;
//				}
//				cout<<n<<".) "<<A[i]<<" at "<<i<<endl;
//				c = front;
//				n ++;
//			}
			for(i = front; i!=rear; i=(i+1)%SIZE){
				cout<<n<<".) "<<A[i]<<" at "<<i<<endl;
				n++;
			}
			cout<<n<<".) "<<A[i]<<" at "<<i<<endl;

		}
	}
}

int main(){
	char choice;
 int flag=1, value;
  
  cout<<"\ni for enqueue; o for dequeue; f for showfront; d for displayQueue; q for exit;\n";
 
 while( flag == 1){
	cout<<"\n";
  	cout<<"------> enter your choice:";
  	cin>>choice;
  	cout<<endl;
  switch (choice)
  {
  case 'i': cout<<"==> Enter Value:";
          cin>>value;
          enqueue(value);
          break;
  case 'o': dequeue();
          break;
  case 'd': display();
          break;
  case 'q': flag = 0;
          break;
  }
 }

	
	return 0;
}

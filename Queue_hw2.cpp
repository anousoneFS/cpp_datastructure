#include <iostream>
using namespace std;
#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;


bool isempty()
{
 if(front == -1 && rear == -1)
 return true;
 else
 return false;
}


void enqueue ( int value )
{
 
 if ((rear + 1)%SIZE == front)
    cout<<"Queue is full \n";
 else
 {
  
  if( front == -1)
     front = 0;
 
 rear = (rear+1)%SIZE;
   A[rear] = value;
 }
}


void dequeue ( )
{
 if( isempty() )
  cout<<"Queue is empty\n";
 else
 
 if( front == rear )
  front = rear = -1;
 else
  front = (front + 1)%SIZE;
}


void showfront( )
{
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"element at front is:"<<A[front]<<endl;
}


void displayQueue()
{
 if(isempty())
  cout<<"Queue is empty\n";
 else
 {
  int i;
  if( front <= rear )
  {
   for( i=front ; i<= rear ; i++)
   cout<<A[i]<<endl;
  }
  else
  {
   i=front;
   while( i < SIZE)
   {
   cout<<A[i]<<endl;
   i++;
   }
   i=0;
   while( i <= rear)
   {
   cout<<A[i]<<endl;
   i++;
   }
  }
 }
 cout<<"front-> "<<front<<endl;
 cout<<"rear-> "<<rear<<endl;
}


int main()
{
 char choice;
 int flag=1, value;
  cout<<"\ni for enqueue; o for dequeue; f for showfront; d for displayQueue; q for exit;\n";
 while( flag == 1)
 {
  cout<<"enter your choice:";
  cin>>choice;
  cout<<endl;
  switch (choice)
  {
  case 'i': cout<<"Enter Value:";
          cin>>value;
          enqueue(value);
          break;
  case 'o': dequeue();
          break;
  case 'f': showfront();
          break;
  case 'd': displayQueue();
          break;
  case 'q': flag = 0;
          break;
  }
 }

 return 0;
}


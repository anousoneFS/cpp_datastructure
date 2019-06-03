#include<iostream>
using namespace std;
int length(int A[]){
	int n=0;
	for(int i=0 ; A[i] != 8; i++){
		n++;
	}
	return n+1;
}

int main(){
	int array[10] = {4,11,5,10,20,1,2,6,8};
	int i, temp, len=length(array);

//	for(int j=0; j<=len-2; j++){
//		for(i=j; i<=len-2; i++){
//			if(array[i] > array[i+1]){
//				temp = array[i+1];
//				array[i+1] = array[i];
//				array[i] = temp;
//			}
//		}
//	}
	for(int i=0; i<=len-2; i++){
		if(array[i] > array[i+1]){
			temp = array[i+1];
			array[i] = array[i+1];
			array[i+1] = temp;
		}	
	}
	
	for(int i=0; i<=len-1; i++){
		cout<<i+1<<".) "<<array[i]<<endl;
	}
	cout<<"is "<<len;
}

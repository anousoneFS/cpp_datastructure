#include<iostream>
using namespace std;

int main(){
	int array[10] = {4,11,5,10,20,1,2,6,8};
	int a;
	for(int j=0; j<=7; j++){
		for(int i=j+1; i<=8; i++){
			if(array[j] > array[i]){
				a = array[j];
				array[j] = array[i];
				array[i] = a;
			}
		}
	}
	for(int i=0; i<=8; i++){
		cout<<i+1<<".) "<<array[i]<<endl;
	}
}

#include<bits/stdc++.h>

using namespace std;

int i=0;

void towerOfHanoi(int n,char from_rod,char to_rod,char aux_rod){
	
	if(n==1){
		cout<<"Move disk 1 from rod "<<from_rod<<" to rod "<<to_rod<<endl;
		i++;
//		cout<<"Hello =========="<<endl;
		return;
	}
	
	towerOfHanoi(n-1,from_rod,aux_rod,to_rod);
	
	cout<<"Move disk "<<n<<" from rod "<<from_rod<<" to rod "<<to_rod<<endl;
	i++;
	
	towerOfHanoi(n-1,aux_rod,to_rod,from_rod);
	
//	cout<<"Hello tower of hanoi"<<endl;
	
}

int main(){
	
	int n = 3;
	towerOfHanoi(n,'A','C','B');
	
	cout<<"="<<i<<endl;
	return 0;
}

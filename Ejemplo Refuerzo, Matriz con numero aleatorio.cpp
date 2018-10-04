#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(){
	
		srand(time(NULL));
	
	
	int matriz[3][3];
	for (int i =0; i< 3; i++){
		
		for (int j =0; j< 3; j++){
		
			matriz[i][j]= rand()% 101;
		}
	}
	for (int i =0; i< 3; i++){
		for (int j =0; j< 3; j++){
			cout<<matriz[i][j]<<"    ";
		}
		cout<<endl;
	}
	
system("pause");
	return 0;
}

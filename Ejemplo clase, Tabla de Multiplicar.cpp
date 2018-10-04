#include <iostream>
#include<stdlib.h>

using namespace std;

int main(){

	for(int j=1; j<=10; j++){
		cout<<"\n";
		cout<<"TABLA DE MULTIPLICAR DE "<<j<<endl;
		for (int i=0; i<=10; i++){	
		cout<<j<<" x "<<i<<" = "<< j*i<<endl;
		}
	}
	return 0;		
}


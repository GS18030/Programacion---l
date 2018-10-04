#include<iostream>
#include<windows.h>

using namespace std; 

int factorial (int num){//funcion factorial
	int fact = 1; // se inicia con valor de uno 
	for (int x=1;x<=num ; x++) //ciclo para calcular el factorial al numero ingresado
	{
		
		fact = fact*x; //acumulador que mulitiplica el numero ingresado
	}
	return fact; //retorna un valor
}


int main(){ 
	int num;
	cout<<"Digite un numero: "; 
	cin>>num; 
	cout<<"El Resultado es: "<<factorial(num)<<endl;//se imprime el resultado de la funcion
		
	system("pause");
	return 0; 
}

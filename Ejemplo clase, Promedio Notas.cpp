//Ciclo For; 
//Ejemplo de promedio de notas.

#include<iostream>
#include <stdlib.h>

using namespace std; 

int main(){
	float notas[5];//arreglo de espacio en la memoria 
	float suma=0; // acumulador iniciado en cero 
	float promedio; // variable para calcular promedio 
	
	for (int i=1; i<=5 ; i++){ //contador i para recorrer los espacios del arreglo
		do{
			cout<<"Ingrese la nota No. "<<i<<" :"<<endl; 
			cin>>notas[i];// lee el dato de acuerdo a el contador 
			system ("cls"); 
		}while (notas[i]<0 || notas[i]>10);// validacion para que los datos ingresados sean mayores a cero y menores a diez
	
	suma=suma+notas[i];//acumulador donde se guardan la notas y se suman.
	}
	
	for (int i=1; i<=5; i++){
		cout<<"La nota "<<i<<" es: "<<notas[i]<<endl;//imprime los datos ingresados
	}
	promedio = suma/5;
	cout<<"\nEl promedio es: "<<promedio<<endl;//calcula el promedio del total de datos y lo imprime en pantalla.
	
	system ("pause");
	return 0; 
}

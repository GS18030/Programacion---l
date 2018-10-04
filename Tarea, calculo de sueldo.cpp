//Jose Adolfo Guzman Solis 
//GS18030 

#include <iostream> //utilizado para operaciones de entrada/salida
#include <iomanip> //Establecer precision decimal
#include <windows.h> //Color de texto y fondo en la consola

using namespace std; 

int main() {

system ("color 1f"); //Permite cambiar el color del fondo de la consola y el color del texto del programa
	
	float venta; //Variable de entrada que guarda la cantidad de ventas realizadas
	float sueldo;//Variable de salida que calcula el resultado
	
	cout<<"----------------- PROGRAMA PARA CALCULAR SUELDO DE VENDEDORES -----------------"<<endl;//
	cout<<endl;// imprime un espacio entre el texto
do{
	cout<<"Ingrese cantidad vendida en el mes: ";//imprime la indicacion 
	cin>> venta; // lee la cantidad ingresada
}
while (venta<=0); //condicion para que la cantidad no sea menor o igual a cero
	
	if(venta <=500000){ //condiciones para el calculo del sueldo segun la tabla respectiva
		sueldo = 80.00;
	}
	else if (venta>500000 && venta <=1000000){
		sueldo = 160.00;
	}
	else if (venta>1000000 &&venta <=1500000){
		sueldo = 320.00;
	}
	else if (venta>1500000 && venta <=2500000){
		sueldo = 450.00;
	}
	else if (venta>2500000 && venta <=4000000){
		sueldo = 550.00;
	}
	else {
		sueldo = (venta*.20);
	}
	cout<<fixed<<setprecision(2)<<"El sueldo es: $"<<sueldo;// imprime el resultado del calculo segun la condicion
	
	
return 0;
}

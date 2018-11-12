#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std; 
void header();
int valid (int a);//declaracion de la funcion con nombre valid 
void lim();//declaracion de la funcion con nombre lim, no retorna ningun valo

int main(){
	int a;//datos para soda
	int b;//datos para jugo
	int bebida;//determina si será soda o jugo
	int cantAzucar;//calculo para insumo de azucar
	int cantAgua;//calculo para insumo de agua
	int continuar=1; //vuelve a ejecutar el programa
	
	header();
	while (continuar=1){//condicion para volver a ejecutar el programa si se cumple
		do{
			cout<<"Elija la bebida a calcular su produccion: \n1) Soda\n2) Jugo"<<endl;
			cin>>bebida;
		valid(bebida);//se llama a la funcion valid 
		}while (bebida<1||bebida>3);
		
		switch(bebida){//condicion para cumplir los casos que se presentan para la variable bebida
			case 1:
			do{
				cout<<"Ingrese cantida de sodas a producir: "<<endl;
				cin>>a;//se lee los datos para soda
			valid(a);//se llama la funcion valid
			} while (a<1);
			cantAgua=500*a;//se calcula la variable por la constante para el Agua
			cantAzucar=800*a;//se calcula la variable por la constante para el Azucar
			cout<<"El total de produccion es: "<<a<<" unidades"<<endl; 
			break;//se sale de la condicion switch
			
			
			case 2:
			do{
				cout<<"Ingrese cantidad de jugos a producir: ";
				cin>>b;//se lee los datos para jugo
			valid(b);//se llama la funcion valid
			} while (b<1);	
			cantAgua=600*b;//se calcula la variable por la constante para el Agua
			cantAzucar=700*b;//se calcula la variable por la constante para el Azucar
			cout<<"El total de produccion es: "<<b<<" unidades"<<endl;
			break;// se sale de la condicion switch
			
			case 3:
				cout<<"Saliendo"<<endl;
				system ("pause");
				return 0;		
		}
		
		cout<<"\n-----INSUMOS REQUERIDOS-----\n"<<endl;//imprime los calculos realizados en caso1 o caso2 del switch
		cout<<"Agua : "<<cantAgua<<" ml."<<endl;
		cout<<"Azucar : "<<cantAzucar<<" ml."<<endl;
		system ("pause");
		cout<<endl;
		do{
			cout<<"¿Desea calcular otra vez? \n(1=Si - 2=No)";//se pide ingresar la opcion si desea volver a ejcutar
			cin>>continuar;
		valid(continuar);//valida que el dato sea numerico
		} while (continuar<1||continuar>2);
		
		if (continuar == 2){//si la condicon se cumple imprime 
		cout<<"Saliendo...";
		return 0;
		}
			
	}
}//fin main

//Declaracion de funciones


void header(){//funcion que impirme un encabezado
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"			°°°° PRODUCCION DE BEBIDAS  °°°° \n";
	cout<<"-------------------------------------------------------------------------------"<<endl;	
}

int valid (int a){ //funcion para validar que el dato ingresado sea un digito numerico
	if(cin.fail()||a<=0){
		cin.clear();
		cin.ignore();
		cout<<"Ingrese un numero valido"<<endl;
		system("pause");
	}
	lim();
	header();
	return a;
}


void lim(){//limpia la pantalla del programa
	system ("cls");
}

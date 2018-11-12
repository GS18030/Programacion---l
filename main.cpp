//Jose Adolfo Guzman Solis
//Carnet: GS18030

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std; 

//declaracion de funciones
float totalPagar (int min);//la funcion es llamada totalPagar 
void header();//la funcion llamada header, imprime en pantalla un encabezado, no retorna ningun valor
void lim();//la funcion llamada lim, limpia la pantalla al ejecutar, no retorna ningun valor
int valid (int a);//la funcion llamada valid, valida que se ingrese un digito numerico

int main(){

	int min;
	int con=1;
	header();//imprime el encabezado del programa

	while (con=1){//condicion que permite volver a ejecutar el programa
	do{
	cout<<"Por favor ingrese la duracion de su llamada en minutos: "; 
	cin>>min; //variable donde se guardan los digitos numericos ingresados
	valid(min);//se llama la funcion donde se valida que sean digitos numericos
	}while(min<1);//condicion para que los digitos ingresados sean mayores a 0
	
	cout<<"\n El total a pagar por su llamada es de: $"<<fixed<<setprecision(2)<<totalPagar(min)<<" ctvs."<<endl;//imprime la informacion mediante la funcion de nombre totalPagar
	
	do{
		cout<<"\n¿Desea calcular otra vez?: \n1) Si \n2) No"<<endl;//
		cin>>con;//variable donde se guardan los digitos si se quiere continuar o no
		valid(con);//se llama la funcion donde se valida que sean digitos numericos
	} while(con<1||con>2);// condicion donde los digitos numericos ingresados tienen que ser 1 o 2

if (con==2){//condicion para terminar el programa
	cout<<"Saliendo..."<<endl;
	return 0;
}
}
	
	getch();
	return 0; 
	
}

//definicion de funciones

float totalPagar (int min){ //funcion que calcula los datos ingresados de acuerdo a la tabla enunciada
	float cuenta; 	
	if (min>0&&min<11){
		cuenta=min*0.05;
	}
	else if (min>10&&min<16){
		cuenta=((min-10)*0.08)+.50;
	}
	else {
		cuenta=((min-15)*0.10)+.90;
	}
	
	return cuenta;
	
}

void header(){//funcion que impirme un encabezado
	cout<<"-------------------------------------------------------------------------------\n";
	cout<<"			°°°° EMPRESA TELEFONICA °°°°			\n";
	cout<<"-------------------------------------------------------------------------------"<<endl;	
}

void lim(){//funcion que limpia la pantalla del programa
system("cls");
}

int valid (int a){//funcion que valida que el dato ingresado sea numerico
	if(cin.fail()||a<=0){
		cin.clear();
		cin.ignore();
		cout<<"Error, ingrese un digito numerico"<<endl;
		system ("pause");
	}

	lim();
	header ();
	return a;
}


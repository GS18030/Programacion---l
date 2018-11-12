//DESCUENTOS EMPLEADO


#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

using namespace std; 

struct empleado{ //estructura para obtener los datos del empleado
	char cod[5];
	char nombre[40]; 
	int edad; 	
	float salbase; 
	float isss; 
	float afp; 
	float renta; 
	float salLiquido; 
	float prestamo; 
};
//declaracion de las funciones 
float calisss (float salbase, float porcentaje); //calcula el descuento de ISSS
float calafp (float salbase, float porcentaje);  // calcula el descuento de AFP
float calrenta (float salbase, float calisss, float calafp); //calcula el Impuesto sobre la Renta
float salLiq (float salbase, float calisss, float calafp, float calrenta); // Resta los descuento y calcula el salario liquido
void lim(); //limpia la pantalla


int main(){ //funcion principal
	int n;
	cout<<"Ingrese numero de empleados: "; 
	cin>>n;// se guarda el dato de numero de empleados
	lim(); //llama la funcion de limpiar pantalla
	empleado e[n]; // llama la estructura 
	for (int i=0;i<n;i++){ //ciclo que recorre el dato del numero de empleados
	cout<<"EMPLEADO NO."<<i+1<<endl;
	cout<<"Codigo: " ; // se imprime en pantalla los datos que se dean guardar
	cin>>e[i].cod;
	
	cin.ignore(256,	'\n'); //limpia el buffer del teclado
		
	cout<<"Nombre: " ; 
	cin.getline(e[i].nombre, 40); //una cadena de caracteres con limite de 40 que permite espacios
	cout<<"Edad: ";
	cin>>e[i].edad ;
	cout<<"Salario Base: "; 
	cin>>e[i].salbase; 
	e[i].isss=calisss (e[i].salbase, 0.03);//llama la funcion calisss que calcula el ISSS
	e[i].afp=calafp (e[i].salbase, 0.0725);//llama la funcion calafp que calcula el AFP
	e[i].renta=calrenta (e[i].salbase, e[i].isss, e[i].afp); //llama la funcion calrenta que calcula el ISR
	e[i].salLiquido=salLiq(e[i].salbase, e[i].isss, e[i].afp, e[i].renta); //llama la funcion que calcula el Salario Liquido
	
	
	//PRESTAMOS****--------------
	
	lim();
	}
	
	for (int i=0;i<n;i++){ // recorre el numero de empleados para imprimir los resultados
		cout<<"Codigo: "<<e[i].cod<<endl; 
		cout<<"Nombre: "<<e[i].nombre<<endl; 
		cout<<"Edad: "<<e[i].edad<<endl; 
		cout<<"El salario base es: $"<<e[i].salbase<<endl;
		cout<<"El descuento del ISSS es: $"<<fixed<<setprecision(2)<<e[i].isss<<endl;  
		cout<<"El descuento de AFP es: $"<<fixed<<setprecision(2)<<e[i].afp<<endl;
		cout<<"La Impuesto sobre la Renta es: $"<<fixed<<setprecision(2)<<e[i].renta<<endl; 
		cout<<"\n El salario liquido es de: $"<<fixed<<setprecision(2)<<e[i].salLiquido<<endl; 
		cout<<"\n Los prestamos son: $"<<e[i].prestamo<<endl; 
		cout<<"\n \n" "---------------------"<<endl; //linea que divide los resultados
	}
	system("pause");
}

//*--------Definicion de funciones---------**

float calisss (float sal, float porcentaje)
{
	float isss;
	if (sal>1000)// Se valida que el sueldo sea menor a 1000 que es el tope para el descuento
	isss = 30;
	else 
	isss = sal*0.03; //si es menor a 1000 se calcula el 3%
	return isss;//retorna el resultado
}

float calafp (float sal, float porcentaje)
{
	float afp; 
	afp = sal*0.0725; //se calcula el descuento del 7.25% segun la tabla
	return afp; 
}

float calrenta(float sal, float isss, float afp)
{
	float descuentos; 
	float renta;
	
	descuentos=sal-isss-afp; //se resta al salario base el ISSS y AFP, para calcular el ISR
	
	//tramo 2
	if (descuentos>472&&descuentos<895.25) // se tienen que cumplir las condiciones de la tabla de retencion
		renta=((descuentos-472)*0.10)+17.67; 
	//tramo 3
	else if (descuentos>895.25&&descuentos<2038.11)
		renta=((descuentos-895.24)*0.20)+60; 
	//tramo 4
	else if (descuentos>2038.10)
		renta=((descuentos-2038.11)*0.30)+288.57;
	//tramo 1 
	else 
		renta=0;
	return renta; 	//retorna el resultado de si aplica el ISR o no y cuanto es el calculo

}

float salLiq (float sal, float calisss, float calafp, float calrenta)
{
	float liquido; 
	liquido = sal-(calisss+calafp+calrenta); // Se restan los tres descuentos y se obtiene el Salario liquido
	return liquido; 
}

void lim()
{
	system("cls");
}

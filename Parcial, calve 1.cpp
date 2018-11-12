//Programa creado por Adolfo Guzman
//GS18030

#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std; 

//ESTRUCTURAS--------------------------------------------------------------------"
struct agregar_autos{  //estructura que almacena las variables para agregar la datos de los autos
	int idAuto;
	string marca;
	string modelo; 
	int year;
	string chasis; 
	float precio;
} autos[15]; //nombre con el que se identificara la estrcutura
struct alquiler_autos{//estructura que almacena las variables para agregar la datos de los autos
	int idcliente;
	int idauto;
	int dias_renta;
	float total_renta;
}Renta[15];//nombre con el que se identificara la estrcutura
struct agregar_clientes{   //estructura que almacena las variables para agregar los datos del cliente
	int idcliente;
	string nombre; 
	int dui; 
	int licencia;
} clientes[15]; //nombre con el que se identificara la estrcutura

//DECLARACION DE FUNCIONES--------------------------------------------------------------------"
//declaracion de las funciones que se utilizaran
void bienvenidos();
void cliente_header();
void autos_header();
void vercliente_header();
void verautos_header();
void lim();
void addclientes();
void mostrar_clientes();
void addautos();
void mostrar_autos();
void renta_autos();
void menu();

int posicionClientes;//variable globlal
int posicionAutos;//variable global
int renta_vehiculo;//variable global
int valid(int a);

//FUNCION PRINCIPAL--------------------------------------------------------------------"
int main() {
	int opcion;
	bienvenidos();//imprime texto 
	lim(); //funcion que limpia pantalla
	do{
		menu();//imprime las opciones del menu
		cout<<"Opcion: ";
		cin>>opcion;//guarda el dato de las opciones del menu
		valid(opcion);//valida que el dato ingresado sea un numero
		lim();
		switch (opcion){ //verificaion de procesos dependiendo del dato ingresado
			case 1: //muestra datos de los autos que se han agregado
				lim();
				verautos_header();
				mostrar_autos();
			break; 
			case 2://se agregan datos de los autos
				lim();
				autos_header();
				addautos();
				posicionAutos +=1; 
			break;
			case 3:  //muestra los datos de los clientes
				lim();
				vercliente_header();
				mostrar_clientes();	
			break; 
			case 4: //se agregan los datos de los clientes
				lim();
				cliente_header();
				addclientes();
				posicionClientes +=1;
			break;
			case 5: //si se tiene agregado datos de autos y clientes , se realiza el calcula de el alquiler del auto
				renta_autos();
				renta_vehiculo+=1;				
			break;
			case 6: //salir
				cout<<"\n\n";
				cout<<"\t\t\t     *********Saliendo*********"<<endl;
				return 0;
		}
	}while (opcion!=6);
	
	system ("pause>nul");
	return 0;
}


//FUNCIONES--------------------------------------------------------------------"
void lim(){
	system ("cls");
} 

void menu(){ //imprime las opciones del menu identificandolas por un numero
	
	cout<<"\n";
	cout<<"\t\t\t\t  MENU PRINCIPAL"<<endl;
	cout<<"\n";
	cout<<"\t\t\t    ---------------------------"<<endl;
	cout<<"\t\t\t||\t1.Mostrar Autos	\t||"<<endl;
	cout<<"\t\t\t||\t2.Agregar Autos	\t||"<<endl;
	cout<<"\t\t\t||\t3.Mostrar Clientes\t||"<<endl;
	cout<<"\t\t\t||\t4.Agregar Clientes\t||"<<endl;
	cout<<"\t\t\t||\t5.Renta Autos	\t||"<<endl;
	cout<<"\t\t\t||\t6.Salir		\t||"<<endl;
}

int numero_cliente;//acumulador 
void addclientes(){ //funcion para agregar datos de clientes
	numero_cliente+=1;//acumulador
	//cout<<"Ingresa ID: "; 
	clientes[posicionClientes].idcliente = numero_cliente;
	clientes[posicionClientes].idcliente;
	cout<<"\t\t\tNombre completo: ";
	cin.ignore();//no tomar datos cuando se presione enter
	getline(cin, clientes[posicionClientes].nombre);
	cout<<"\t\t\t\tNo. Dui: ";
	cin>>clientes[posicionClientes].dui;
	cout<<"\t\t\t   No. licencia: ";
	cin>>clientes[posicionClientes].licencia;
	lim();
}

void mostrar_clientes(){//funcion para mostrar clientes
	for (int a=0; a<15; a++){//ciclo que recorre todas las posiciones de los clientes agregados
			cout<<"\n";
		if(clientes[a].nombre != ""){//verifica el numero de cliente agregado
			cout<<clientes[a].idcliente<<" ";			
	    	cout<<"Nombre completo: "<<(clientes[a].nombre)<<" ";
	    	cout<<"No. Dui: "<<(clientes[a].dui)<<" "<<"  ";
	    	cout<<"No. licencia: "<<(clientes[a].licencia)<<" "<<endl;
    	}
	}
}
	
void mostrar_autos(){//funcion que muestra los datos de los autos agregados
	
	for (int n=0; n<15; n++){//ciclo que recorre todas las posiciones de los autos agregados
		if(autos[n].modelo != ""){	//verifica el numero de auto agregado						
			cout<<autos[n].idAuto<< " ";			
	    	cout<<"Modelo: "<<(autos[n].modelo)<<" ";
	    	cout<<"Año: "<<(autos[n].year)<<" ";
	    	//cout<<(autos[n].chasis)<<" ";
	    	cout<<"Precio por dia: $"<<(autos[n].precio)<<endl;
    	}
	}
}

int numero_autos;//acumulador
void addautos(){//funcnion que agrega datos de los autos
	numero_autos+=1;//acumulador
	autos[posicionAutos].idAuto = numero_autos;
	cout<<"\t\t\tModelo: ";
	cin.ignore();
	getline(cin, autos[posicionAutos].modelo);
	cout<<"\t\t\tAño: ";
	cin>>autos[posicionAutos].year;
	cout<<"\t\t\tChasis: ";
	cin>>autos[posicionAutos].chasis;
	cout<<"\t\t\tPrecio por dia: $"; 
	cin>>autos[posicionAutos].precio;
	lim();
}


void renta_autos(){	// funcion para calcular el alquiler de los autos 
	int IdCliente; //definicion de variables
	string Nombre_Cliente;//definicion de variables
			cout<<"\n"<<endl;
			cout<<"\t\t\t-------Listado de clientes-------"<<endl;
	for (int t=0; t<15; t++){//ciclo recorre las posiciones de los clientes ingresados y obtiene su nombre
		if(clientes[t].nombre != ""){//se genera una lista de los clientes ingresados						
			cout<<clientes[t].idcliente<< " ";			
	    	cout<<"\t\t\t Nombre Cliente: "<<(clientes[t].nombre)<<endl;  	
    	}
	}
	
	
	for	(int p=0; p<1; p++){//ciclo que se ejecuta una vez
		if(clientes[p].nombre !=""){ //obtiene el dato del cliente que se quiere obtener
			cout<<"\t\t\t Ingrese el Id de Cliente: ";
			cin>>IdCliente;//guarda el dato
		}
		if(clientes[p].idcliente == IdCliente){
			Nombre_Cliente = clientes[p].nombre;
		}		
		
	}
	cout<<"\n";
	cout<<"\t\t\t-------Listado de autos-------"<<endl;	
	for (int x=0; x<15; x++){//ciclo que recorre las posiciones de los autos ingresados
		if(autos[x].modelo != ""){	//se genera una lista de los autos ingresados					
			cout<<autos[x].idAuto<< " ";			
	    	cout<<"Modelo: "<<(autos[x].modelo)<<" ";
	    	cout<<"Año: "<<(autos[x].year)<<" ";
	    	//cout<<(autos[x].chasis)<<" ";
	    	cout<<"Precio por dia: $"<<(autos[x].precio)<<endl;	    	
    	}
	}


	for	(int z=0; z<1; z++){//ciclo para obtener numero entero de los dias 
		float totalapagar;//variable para calcular monto de alquiler
		int IdAuto; //definicion de variables
		int dias=0;
		string Auto;
		
		if(autos[z].modelo != ""){
			cout<<"\t\t\t Ingrese el id del auto: ";
			cin>>Renta[renta_vehiculo].idauto;//se ingresa el identificar del auto 
			IdAuto = Renta[renta_vehiculo].idauto;//se identifica con la variable IdAuto 
			cout<<"\t\t\t Ingrese los dias de renta: ";
			cin>>Renta[renta_vehiculo].dias_renta;//se ingresa los dias a calcular 
			dias = Renta[renta_vehiculo].dias_renta;//se identifica con la variable dias
		}
		if(autos[z].idAuto == IdAuto){//se valida el auto ingresado 
			totalapagar = (autos[z].precio * dias);// variable para el calculo de precio * dias
			Renta[renta_vehiculo].total_renta = totalapagar;
			Auto = autos[z].modelo;
			
			cout<<"\t\t\t********** RESUMEN DE RENTA **********"<<endl;//se imprime el calculo de el alquiler
			cout<<"\t\t\t Vehiculo: "<<Auto<<endl;//se imprime el modelo del auto
			cout<<"\t\t\t "<<"Nombre cliente: "<<Nombre_Cliente<<endl;//se imprime nombre de cliente
			cout<<"\t\t\t "<<"Dias: "<<dias<<endl;//se imprimen los dias
			cout<<"\t\t\t "<<"Precio a Pagar por Alquiler: $"<<totalapagar<<endl;//se imprime el monto a pagar
			cout<<"\t\t\t**************************************";
			
			cout<<"\n"<<endl;
		}		
	}	

}
//variable para los encabezados de cada proceso, solo imprimen texto
void bienvenidos(){ 
cout<<"\n\n********************************************************************************"<<endl;
cout<<"\n\n\t\t\t\t     Bienvenidos    ";
cout<<"\n\n\n\n\t\t\t\tRENTA DE AUTOS EQUIS"<<endl;
cout<<"\n\n\n\n\t\t\t  Presione una tecla para continuar"<<endl;
system ("pause>nul");
}
void cliente_header(){
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t\t    INGRESA CLIENTE"<<endl;
	cout<<"\t\t\t\---------------------------------------"<<endl;
}
void autos_header(){
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t\t    INGRESA VEHICULO"<<endl;
	cout<<"\t\t\t\---------------------------------------"<<endl;
	
}
void vercliente_header(){
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t\t    LISTA DE CLIENTES"<<endl;
	cout<<"\t\t\t\---------------------------------------"<<endl;
}
void verautos_header(){
	
	cout<<"\t\t\t---------------------------------------"<<endl;
	cout<<"\t\t\t\t   VEHICULOS DISPONIBLES"<<endl;
	cout<<"\t\t\t\---------------------------------------"<<endl;
	
}

int valid(int a){
 	if (cin.fail()||a<=0){
 		cin.clear();
 		cin.ignore();
 		cout<<"Error"<<endl;
		system("pause>nul");
	 }
	 lim();

return a;
 }

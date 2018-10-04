#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

int main()
{
	int sacos;
	int descuento;
	int precio = 100;
	float porcentaje;
	float total;
	
	do{
		cout<<"Ingrese la cantidad de sacos: "<<endl;
		cin>>sacos;
	}
	while (sacos<=0);

	if (sacos<100){
		descuento = 0;
	}
	else if (sacos>100&&sacos<=200){
		descuento = (precio*sacos)*.10;
	}
	else if (sacos>200&&sacos<=250){
		descuento = (precio*sacos)*.15;
	}
	else if (sacos>250&&sacos<300){
		descuento = (precio*sacos)*.20;
	}
	else{
		descuento = (precio*sacos)*.25;
	}

	porcentaje = ((sacos*precio)-descuento);
	total = porcentaje+(porcentaje*0.13);
	cout<<"El total es de: $"<<total<<endl;
	
	system("pause");
	return 0;
}

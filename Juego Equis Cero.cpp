#include <iostream>
#include <stdlib.h>

using namespace std; 

char matriz[3][3] = {'1','2','3','4','5','6','7','8','9'};	//Variable global para la matriz 3x3
char player = 'X';		//variable global para determinar el jugador
int n;		//variable global para el numero de veces al elegir un campo

//declaracion de funciones
void tabl ();
void entrada();
void playerDos();
void lim();
char ganador();
//Funcion Principal
int main(){
	
	n=0;	//el numero de intentos inicia en cero
	tabl ();	//se llama a ejecutar la funcion
	while (1)
	{
		n++; //se incrementa el numero de intentos
		entrada();
		lim();
		tabl();
		if (ganador() == 'X') //se comparan los resultados y si cumple las condiciones se imprime el ganador
		{																	
			cout<<"La X gana!"<<endl;
			break;
		}
		else if (ganador() =='O')
		{
			cout<<"El O gana!"<<endl;
			break;
		}
		else if(ganador()== '/' && n==9)	//si el jugador 1 y 2 no ganan y los intentos son 9
		{
			cout<<"Es un empate"<<endl;		//imprime el empate.
			break;	
		}
		playerDos();
	}
	
		
	system ("pause");
	return 0;
}


//----------------

//Definicion de funciones

void tabl ()	//imprime el tablero con sus filas y columnas
{
	cout << "\t\t\t\tJuego Equis - Cero\n\n\n";	//imprime un encabezado
    cout << "\t      	      Player 1:  (X)  -  Player 2:  (O)" << endl << endl << endl << endl;  
    
	for(int i=0;i<3;i++)  	//Se Encarga de las Columnas del Tablero.
    {
        cout<<"\t\t\t       ";cout<<"  ";                                                               
        for(int j=0;j<3;j++)   		//Se Encarga de las Filas del Tablero.
        {   
            cout<<matriz[i][j];  	//Los Numeros del Arreglo se iran Acomodando en el Orden Correspondiente Mediante 
            if(j<3-1)            //Las Columnas Junto A las FiLas se Formen.                                                                                     
            {
                cout<<" | ";   	//Divisiones Verticales para el Tablero.
            }
        }
        cout<<endl;  	//Salto de Linea, Nos Ayuda a Comenzar los Preparativos para las Divisiones Horizontales.

    if(i<3-1)
        {
            for (int lines=0;lines<1;lines++ )    //Se Encarga de las Filas del Tablero.
            {
                cout<<"\t\t\t\t--- --- ---";     //Divisiones Horizantales para el Tablero.
            }
            cout<<endl; //imprime un salto de linea
        }

    }
    return;
}
	 

void entrada() // Funcion para elegir los numeros del campo de la matriz
{
	int a;
	cout<<"\nTurno de: "<<player<<endl; //indica que turno de jugador es
	cout<<"Elija el campo que desea marcar: ";
	cin>>a;
	
	if (a==1)		// condiciones para reemplazar el campo de la matriz por la X o O y verificar que no se encuentre ocupado
	{
		if (matriz[0][0] == '1')
		 	matriz[0][0] = player;
        else
        {
            cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}
	
	else if (a==2)
	{
		if (matriz[0][1] == '2')
		 	matriz[0][1] = player;
        else
        {
            cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}
	
	else if (a==3)
	{
		if (matriz [0][2] =='3')
			matriz [0][2]= player;
		else{
			cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}
	
	else if (a==4)
	{
		if (matriz [1][0] =='4')
		matriz [1][0]= player;
		else{
			cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}
	
	else if (a==5)
	{
		if (matriz [1][1] =='5')
			matriz [1][1]= player;
		else{
			cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}
	
	else if (a==6)
	{
		if (matriz [1][2] =='6')
		matriz [1][2]= player;
		else{
			cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}
	
	else if (a==7)
	{
		if (matriz [2][0] =='7')
		matriz [2][0]= player;
		else{
			cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}
	
	else if (a==8)
	{
		if (matriz [2][1] =='8')
		matriz [2][1]= player;
		else{
			cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}
	
	else if (a==9)
	{
		if (matriz [2][2] =='9')
		matriz [2][2]= player;
	else{
			cout << "\nCampo ocupado, intente otra vez!" << endl;
            entrada();
		}
	}	
}

void playerDos() //Cambio de Turno
{
	if (player == 'X'){ //Mientras la Variable Player sea X al llegar aqui Pasara a Convertrise en O.
		player = 'O';
	}
	else{				//Mientras la Variable Player sea O al llegar aqui Pasara a Convertirse en X
		player = 'X';
	}
	
}

void lim() //Funcion para limpiar la pantalla
{
	system("cls");
}

char ganador() //Funcion que Dicta al GANADOR
{
	//PRIMER JUGADOR
	//Horizontal
	if (matriz[0][0]== 'X' && matriz[0][1]=='X' && matriz [0][2]=='X')
	return 'X';
	else if (matriz[1][0]== 'X' && matriz[1][1]=='X' && matriz [1][2]=='X')
	return 'X';
	else if (matriz[2][0]== 'X' && matriz[2][1]=='X' && matriz [2][2]=='X')
	return 'X';
	//Vertical
	else if (matriz[0][0]== 'X' && matriz[1][0]=='X' && matriz [2][0]=='X')
	return 'X';
	else if (matriz[0][1]== 'X' && matriz[1][1]=='X' && matriz [2][1]=='X')
	return 'X';
	else if (matriz[0][2]== 'X' && matriz[1][2]=='X' && matriz [2][2]=='X')
	return 'X';
	//Diagonal
	else if (matriz[0][0]== 'X' && matriz[1][1]=='X' && matriz [2][2]=='X')
	return 'X';
	else if (matriz[0][2]== 'X' && matriz[1][1]=='X' && matriz [2][0]=='X')
	return 'X';
	
	//SEGUNDO JUGADOR
	
	if (matriz[0][0]== 'O' && matriz[0][1]=='O' && matriz [0][2]=='O')
	return 'O';
	else if (matriz[1][0]== 'O' && matriz[1][1]=='O' && matriz [1][2]=='O')
	return 'O';
	else if (matriz[2][0]== 'O' && matriz[2][1]=='O' && matriz [2][2]=='O')
	return 'O';
	//Vertical
	else if (matriz[0][0]== 'O' && matriz[1][0]=='O' && matriz [2][0]=='O')
	return 'O';
	else if (matriz[0][1]== 'O' && matriz[1][1]=='O' && matriz [2][1]=='O')
	return 'O';
	else if (matriz[0][2]== 'O' && matriz[1][2]=='O' && matriz [2][2]=='O')
	return 'O';
	//Diagonal
	else if (matriz[0][0]== 'O' && matriz[1][1]=='O' && matriz [2][2]=='O')
	return 'O';
	else if (matriz[0][2]== 'O' && matriz[1][1]=='O' && matriz [2][0]=='O')
	return 'O';
			
	return'/';	
	
}

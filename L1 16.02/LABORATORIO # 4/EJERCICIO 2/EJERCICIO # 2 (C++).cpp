// 2.-Debe realizar un programa en c++ leer el archivo txt y contar cuántas palabras tiene el texto,
// luego debe grabar un archivo txt con el número de palabras que logro contar
#include <iostream>
#include <fstream>
#include <stdlib.h>
#define MAX 10000
using namespace std;
void Inicio();
void Leer();
void Operaciones();
void Agregar();
void Mostrar();
struct texto{
	string linea,comentario;
}registro[MAX];

double n1=0,n2=0;
int lin=1,t=0;

int main(){
	Inicio();
	Leer();
	Operaciones();
	Agregar();
	Mostrar();
	return 0;
}
void Inicio(){
	char op;
	
	do{
		cout<<"\nQUE DESEA REALIZAR..."<<endl<<endl;
		cout<<"\t\ta. Contar el numero de palabras que tiene"<<endl;
		cout<<"\t\tb. Agregar comentario"<<endl;
		cout<<"\t\tc. Visualizar el archivo"<<endl;
		cout<<"\t\tPresione s para Salir"<<endl<<endl;
		cout<<"\tINGRESE SU ELECCION "<<endl;
		cout<<" --> ";cin>>op;
		system("cls");
		switch(op){
			case 'a': {
				Leer();
				Operaciones();
				system("pause");
				system("cls");
				break;
			}
			case 'b': {
				Agregar();
				system("pause");
				system("cls");
				break;
			}
			case 'c': {
				Mostrar();
				system("pause");
				system("cls");
				break;
			}
			case 's': {
				cout<<"\nGracias, vuelva pronto..."<<endl;
				exit(1);
				system("cls");
				break;
			}
			default: {
				cout<<"\nERROR! OPCION INEXISTENTE..."<<endl;
				system("pause");
				system("cls");	
				break;
			}
					 	
		}
	}while((op=='a')||(op=='b')||(op=='c')||(op=='s'));
}

void Leer(){
	string texto1;
	
	ifstream archivo;
	archivo.open("lady-gaga.txt",ios::in);

	//Controlar el acceso al archivo
	if(archivo.fail()){
		cout<<"\n\tHAY UN PROBLEMA CON EL ACCESO AL ARCHIVO"<<endl;
	}

	while(!archivo.eof()){
		getline(archivo,texto1);
		n1=n1+texto1.length();
		//cout<<n1<<endl;
	}
	archivo.close();
	cout<<"\n\tEL ARCHIVO TIENE "<<n1<<" CARACTERES"<<endl;
}

void Operaciones(){
	
	int c=1;
	
	ifstream archivo;
	archivo.open("lady-gaga.txt",ios::in);
	//Controlar el acceso al archivo
	if(archivo.fail()){
		cout<<"\n\tHAY UN PROBLEMA CON EL ACCESO AL ARCHIVO"<<endl;
	}

	while(!archivo.eof()){
		getline(archivo,(registro[lin].linea));
		n2=registro[lin].linea.length();
		for(int i=1;i<=n2;i++){
	        if(((registro[lin].linea)[i])==' '){
	            c=c+1;
	        }
	    }
		lin=lin+1;
	}
	cout<<"\n\tEL TEXTO TIENE "<<lin<<" LINEAS"<<endl;
	cout<<"\n\tEL TEXTO TIENE "<<c+lin<<" PALABRAS"<<endl<<endl;
	t=c+lin;
	archivo.close();
	
	
}

void Agregar(){int n;
	
	ofstream archivo;
	archivo.open("lady-gaga.txt",ios::app);
	
	if(archivo.fail()){
		cout<<"ERROR EN EL ACCESO AL ARCHIVO"<<endl;
		exit(1);
	}
	
	cout<<"\nQUE DESEA REALIZAR..."<<endl<<endl;
	cout<<"\t\t1. Agregar comentario"<<endl;
	cout<<"\t\t2. Agregar el predeterminado"<<endl;
	cout<<"\t\tPresione s para Salir"<<endl<<endl;
	cout<<"\tINGRESE SU ELECCION "<<endl;
	cout<<" --> ";cin>>n;
	system("cls");
	switch(n){
		case 1: {
			do{
				cout<<"Cuantas lineas desea ingresar"<<endl;
				cin>>n;
			}while(n<0 or n>100);
				
			for(int i=1;i<=n;i++){
				cout<<" INGRESAR --> "<<endl;
				fflush(stdin);
				getline(cin,registro[i].comentario);
					
				archivo<<registro[i].comentario<<endl;
			}
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			archivo<<"EL ARCHIVO TIENE "<<t<<" PALABRAS"<<endl;
			system("pause");
			system("cls");
			break;
		}
		case 's': {
			cout<<"\nGracias..."<<endl;
			exit(1);
			system("cls");
			break;
		}
		default: {
			cout<<"\nERROR! LA OPCION ES INEXISTENTE..."<<endl;
			system("pause");
			system("cls");	
			break;
		}		 	
	}
	
	archivo.close();
}

void Mostrar(){
	string texto;
	
	ifstream archivo;
	archivo.open("lady-gaga.txt",ios::in);

	//Controlar el acceso al archivo
	if(archivo.fail()){
		cout<<"EXISTE UN PROBLEMA CON EL ACCESO AL ARCHIVO"<<endl;
		cout<<"\tVUELVA A INTENTARLO"<<endl;
	}
	cout<<"\nESTE ES EL ARCHIVO: "<<endl<<endl;
	while(!archivo.eof()){
		getline(archivo,texto);
		cout<<texto<<endl;		
	}
	
	archivo.close();
}
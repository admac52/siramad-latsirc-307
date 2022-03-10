//2. Generar matrices enésimas de Vandermonde y calcular el determinante

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(){
	int op,n,f,c;
	double det=1;
	float Vector[100];
	float Matriz[100][100];
	
	cout<<"\n\t******** MATRICES DE VANDERMONDE *********"<<endl;
	cout<<"\t--------------------------------------------"<<endl;
	cout<<"\t\t1.- EN FILAS"<<endl;
	cout<<"\t\t2.- EN COLUMNAS"<<endl;
	cout<<"\t\t3.- SALIR"<<endl<<endl;
	cout<<"INGRESE SU ELECCION: "<<endl;
	cin>>op;
	cout<<"--------------------------------"<<endl;
	do{cout<<"INGRESE UN VALOR < n > PARA EL TAMANO DE LA MATRIZ: "<<endl;
		cin>>n;
	}while(n<0 or n>100);
	switch(op){
		case 1:{cout<<"INGRESE UN VALOR BASE POR FILA : "<<endl;
				//TOMA DE DATOS
				for (int i=0;i<n;i++){
					cout<<"M["<<i+1<<",2] = ";
					cin>>Vector[i];
				}
				//OPERACIONES
				for (int i=0;i<n;i++){
					for (int j=0;j<n;j++){
						Matriz[i][j]=pow((Vector[i]),j);	
					}
				}
				//MOSTRAR
				cout<<"\n\tLA MATRIZ DE VANDERMONDE ES : "<<endl<<endl;
				cout<<"---------------------------------------------"<<endl;
				for (int i=0;i<n;i++){
					cout<<"\t";
					for (int j=0;j<n;j++){
						cout<<Matriz[i][j]<<"\t";
					}cout<<"\n";
				}
				//DETERMINANTE
				for(int i=0;i<n-1;i++){
					for(int j=i+1;j<n;j++){
						det=det*(Vector[j]-Vector[i]);
					}
				}
				cout<<"\n\tY SU DETERMINANTE ES : " <<det<<endl;
				break;
   			}
		case 2:{cout<<"INGRESE UN VALOR BASE POR COLUMNA: "<<endl;
				//TOMA DE DATOS
				for (int i=0;i<n;i++){
					cout<<"M[2,"<<i+1<<"] = "<<endl;
					cin>>Vector[i];
				}
				//OPERACIONES
				for (int i=0;i<n;i++){
					for (int j=0;j<n;j++){
						Matriz[i][j]=pow((Vector[i]),j);	
					}
				}
				//MOSTRAR
				cout<<"\n\tLA MATRIZ DE VANDERMONDE ES : "<<endl<<endl;
				cout<<"---------------------------------------------"<<endl;
				for (int i=0;i<n;i++){
					cout<<"\t";
					for (int j=0;j<n;j++){
						cout<<Matriz[j][i]<<"\t";
					}cout<<"\n";
				}
				//DETERMINANTE POR VANDERMONDE
				for(int i=0;i<n-1;i++){
					for(int j=i+1;j<n;j++){
						det=det*(Vector[j]-Vector[i]);
					}
				}
				
				cout<<"\n\tY SU DETERMINANTE ES : " <<det<<endl;
			break;
		}
		case 3:{cout<<"Hasta luego..."<<endl;
			break;
		}
	default:	cout<<"Error"<<endl;
	}
	return 0;
} 

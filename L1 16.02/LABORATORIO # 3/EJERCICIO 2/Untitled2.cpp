//1. Dadas 2 matrices A y B de orden m x n  y j x k  calcular  axb, a+b, a-b, a/b

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>

using namespace std;

int main(){
	int opA,opB,m1,n1,m2,n2;
	char op1;
	double det=1;
	float MA[100][100],MB[100][100];
	float S[100][100];
	float R[100][100];
	float M[100][100];
	float D[100][100];
	
	cout<<"\n\t********** CALCULADORA MATRICIAL ***********"<<endl;
	cout<<"\t--------------------------------------------"<<endl;
	// DIMENSIONES A
	cout<<"\tMATRIZ A"<<endl;
	cout<<"------------------------"<<endl;
	do{cout<<" INGRESE EL NUMERO DE FILAS PARA LA MATRIZ A "<<endl;
		cout<<" --> ";cin>>m1;
	}while(m1<0 or m1>100);
	do{cout<<" INGRESE EL NUMERO DE COLUMNAS PARA LA MATRIZ A "<<endl;
		cout<<" --> ";cin>>n1;
	}while(n1<0 or n1>100);
	// LLENADO A
	cout<<"----------------------------------------------------"<<endl;
	cout<<" USTED PUEDE :"<<endl;
	cout<<"\t\t1.- Ingresar datos por teclado"<<endl;
	cout<<"\t\t2.- Llenar datos al azar"<<endl<<endl;
	cout<<"INGRESE SU ELECCION: "<<endl;
	cin>>opA;
	if(opA==1 or opA==2){
		if(opA==1){
			cout<<"INTRODUZCA LOS DATOS PARA LA MATRIZ A "<<endl;
			for (int i=0;i<m1;i++){
				for (int j=0;j<n1;j++){
					cout<<"Matriz A["<<i+1<<","<<j+1<<"] = ";
					cin>>MA[i][j];
				}
			}
		}
		if(opA==2){
			for (int i=0;i<m1;i++){
				for (int j=0;j<n1;j++){
					MA[i][j]=1+(rand()%(16-1));
				}
			}
		}
	}else{cout<<"\nError de dato de entrada, vuelva a ingresar"<<endl;
	}cout<<"\n";
	cout<<"----------------------------------------------------"<<endl;
	// DIMENSIONES B
	cout<<"\tMATRIZ B"<<endl;
	cout<<"------------------------"<<endl;
	do{cout<<" INGRESE EL NUMERO DE FILAS PARA LA MATRIZ B "<<endl;
		cout<<" --> ";cin>>m2;
	}while(m2<0 or m2>100);
	do{cout<<" INGRESE EL NUMERO DE COLUMNAS PARA LA MATRIZ B "<<endl;
		cout<<" --> ";cin>>n2;
	}while(n2<0 or n2>100);
	//LLENADO B
	cout<<"----------------------------------------------------"<<endl;
	cout<<" USTED PUEDE :"<<endl;
	cout<<"\t\t1.- Ingresar datos por teclado"<<endl;
	cout<<"\t\t2.- Llenar datos al azar"<<endl<<endl;
	cout<<"INGRESE SU ELECCION: "<<endl;
	cin>>opB;
	if(opB==1 or opB==2){
		if(opB==1){
			cout<<"INTRODUZCA LOS DATOS PARA LA MATRIZ A "<<endl;
			for (int i=0;i<m2;i++){
				for (int j=0;j<n2;j++){
					cout<<"Matriz B["<<i+1<<","<<j+1<<"] = ";
					cin>>MB[i][j];
				}
			}
		}
		if(opB==2){
			for (int i=0;i<m2;i++){
				for (int j=0;j<n2;j++){
					MB[i][j]=1+(rand()%(16-1));
				}
			}
		}
	}else{cout<<"\nError de dato de entrada, vuelva a ingresar"<<endl;
	}
	//MOSTRAR
	cout<<"\n\tDADAS LAS MATRICES: "<<endl<<endl;
	cout<<"\t\tMATRIZ A"<<endl;
	cout<<"\t-------------------------------"<<endl<<endl;
	for (int i=0;i<m1;i++){cout<<"\t";
		for (int j=0;j<n1;j++){
			cout<<MA[i][j]<<"\t";
		}cout<<"\n";
	}cout<<"\n";
	cout<<"\t\tMATRIZ B"<<endl;
	cout<<"\t-------------------------------"<<endl<<endl;
	for (int i=0;i<m2;i++){cout<<"\t";
		for (int j=0;j<n2;j++){
			cout<<MB[i][j]<<"\t";
		}cout<<"\n";
	}cout<<"\n";
	// OPERACIONES
	// SUMA
	if((m1==m2) and (n1==n2)){
		for (int i=0;i<m1;i++){
			for (int j=0;j<n1;j++){
				S[i][j]=MA[i][j]+MB[i][j];	
			}
		}				
	}
	// RESTA
	if((m1==m2) and (n1==n2)){
		for (int i=0;i<m1;i++){
			for (int j=0;j<n1;j++){
				R[i][j]=MA[i][j]-MB[i][j];	
			}
		}				
	}
	// MULTIPLICACION
	if((n1==m2)){
		for (int i=0;i<m1;i++){
			for (int j=0;j<n2;j++){
				for (int k=0;k<m2;k++){
					M[i][j]=M[i][j]+(MA[i][k]*MB[k][j]);
				}	
			}
		}				
	}
	// DIVISION
	cout<<"----------------------------------------------------"<<endl;
	cout<<"Que operacion desea mostrar..."<<endl;
	cout<<"\t\ta.- A + B"<<endl;
	cout<<"\t\tb.- A - B"<<endl;
	cout<<"\t\tc.- A x B"<<endl;
	cout<<"\t\td.- A / B"<<endl;
	cout<<"\t\te.- SALIR"<<endl<<endl;
	cout<<"INGRESE SU ELECCION: "<<endl;
	cin>>op1;
	cout<<"--------------------------------"<<endl;
	switch(op1){
		case 'a':{cout<<"\t******** S U M A ********"<<endl;
				cout<<"\n\t MATRIZ A + MATRIZ B "<<endl<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((m1==m2) and (n1==n2)){
					for (int i=0;i<m1;i++){
						for (int j=0;j<n1;j++){
							cout<<S[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN SUMAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN"<<endl;
				}
			break;
		}
		case 'b':{cout<<"\t******** R E S T A ********"<<endl;
				cout<<"\n\t MATRIZ A - MATRIZ B "<<endl<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((m1==m2) and (n1==n2)){
					for (int i=0;i<m1;i++){
						for (int j=0;j<n1;j++){
							cout<<R[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN RESTAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN"<<endl;
				}
			break;
		}
		case 'c':{cout<<"\t******** M U L T I P L I C A C I O N ********"<<endl;
				if((n1==m2)){
					for (int i=0;i<m1;i++){
						for (int j=0;j<n2;j++){
							cout<<M[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN MULTIPLICAR..."<<endl;
					cout<<"PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A ES DIFERENTE DEL NUMERO DE FILAS DE LA MATRIZ B"<<endl;
				}
			break;
		}
		case 'd':{cout<<"\t******** D I V I S I O N ********"<<endl;
			break;
		}
		case 'e':{cout<<"Hasta luego..."<<endl;
			break;
		}
	default:	cout<<"Error de eleccion"<<endl;
	}
	return 0;
} 
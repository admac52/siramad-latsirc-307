// CALCULADORA MATRICIAL
//1. Dadas 2 matrices A y B de orden m x n  y j x k  calcular  axb, a+b, a-b, a/b

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cstdlib>

using namespace std;
// FUNCIONES
float DETA(float MA[100][100], int m1);
float DETB(float MB[100][100], int m2);
float COFA(float MA[100][100], int m1, int f, int c);
float COFB(float MB[100][100], int m2, int f, int c);

int main(){
	int opA,opB,m1,n1,m2,n2,extra,adia,adib;//datos
	float rango,fil,col,elev,elea,eleb,coea,coeb,a;
	float escalar,x,auxa[100],auxb[100];
	char op1;
	float MA[100][100],MB[100][100];
	float S[100][100],R[100][100];
	float M[100][100],D[100][100];
	float OPA[100][100],OPB[100][100];
	float AEA[100][100],AEB[100][100];
	double INA[100][100],INB[100][100];
	float LA[100][100],LB[100][100];
	
	cout<<"\n\t\t\t\t  ********** CALCULADORA MATRICIAL ***********"<<endl;
	cout<<"\t\t\t\t  --------------------------------------------"<<endl<<endl;
	cout<<"  //////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
	cout<<"  //                                                                                                          //"<<endl;
	cout<<"  //\t++++++ OPERACIONES ENTRE MATRICES ++++++\t++++++ OPERACIONES ADICIONALES ++++++                 //"<<endl;
	cout<<"  //                                                                                                          //"<<endl;
	cout<<"  //\t\t\t A + B\t\t\t\t\tDeterminante                                  //"<<endl;
	cout<<"  //\t\t\t A - B\t\t\t\t\tMatriz Inversa                                //"<<endl;
	cout<<"  //\t\t\t A x B\t\t\t\t\tMatriz transpuesta                            //"<<endl;
	cout<<"  //\t\t\t A / B\t\t\t\t\tMultiplicar por un escalar                    //"<<endl;
	cout<<"  //\t\t\t      \t\t\t\t\tRango                                         //"<<endl;
	cout<<"  //\t\t\t      \t\t\t\t\tMatriz Triangular                             //"<<endl;
	cout<<"  //\t\t\t      \t\t\t\t\tMatriz Diagonal                               //"<<endl;
	cout<<"  //\t\t\t      \t\t\t\t\tMatriz Elevada a...                           //"<<endl;
	cout<<"  //\t\t\t      \t\t\t\t\tFactorizacion LU                              //"<<endl;
	cout<<"  //\t\t\t      \t\t\t\t\tFactorizacion de Cholesky                     //"<<endl;
	cout<<"  //\t\t\t      \t\t\t\t\tValores y Vectores propios                    //"<<endl;
	cout<<"  //                                                                                                          //"<<endl;
	cout<<"  //////////////////////////////////////////////////////////////////////////////////////////////////////////////"<<endl<<endl;
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
	cout<<" --> ";cin>>opA;
	switch(opA){
		case 1:{cout<<"INTRODUZCA LOS DATOS PARA LA MATRIZ A "<<endl;
			for (int i=0;i<m1;i++){
				for (int j=0;j<n1;j++){
					cout<<"Matriz A["<<i+1<<","<<j+1<<"] = ";
					cin>>MA[i][j];
				}
			}
			break;
		}
		case 2:{
			for (int i=0;i<m1;i++){
				for (int j=0;j<n1;j++){
					MA[i][j]=1+(rand()%(16-1));
				}
			}
			break;
		}
		default: cout<<"Error de dato de entrada"<<endl;
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
	cout<<" --> ";cin>>opB;
	switch(opB){
		case 1:{cout<<"INTRODUZCA LOS DATOS PARA LA MATRIZ B "<<endl;
			for (int i=0;i<m2;i++){
				for (int j=0;j<n2;j++){
					cout<<"Matriz B["<<i+1<<","<<j+1<<"] = ";
					cin>>MB[i][j];
				}
			}
			break;
		}
		case 2:{
			for (int i=0;i<m2;i++){
				for (int j=0;j<n2;j++){
					MB[i][j]=1+(rand()%(16-1));
				}
			}
			break;
		}
		default: cout<<"Error de dato de entrada"<<endl;
	}
	//MOSTRAR
	cout<<"\n\tDADAS LAS MATRICES: "<<endl<<endl;
	cout<<"\t\tMATRIZ A"<<endl;
	cout<<"\t-------------------------------"<<endl<<endl;
	for (int i=0;i<m1;i++){cout<<"\t";
		for (int j=0;j<n1;j++){
			INA[i][j]=MA[i][j];
			cout<<MA[i][j]<<"\t";
		}cout<<"\n";
	}cout<<"\n";
	cout<<"\t\tMATRIZ B"<<endl;
	cout<<"\t-------------------------------"<<endl<<endl;
	for (int i=0;i<m2;i++){cout<<"\t";
		for (int j=0;j<n2;j++){
			INB[i][j]=MB[i][j];
			cout<<MB[i][j]<<"\t";
		}cout<<"\n";
	}cout<<"\n";
	// OPERACIONES
	// **** SUMA****
	if((m1==m2) and (n1==n2)){
		for (int i=0;i<m1;i++){
			for (int j=0;j<n1;j++){
				S[i][j]=MA[i][j]+MB[i][j];	
			}
		}				
	}
	// **** RESTA ****
	if((m1==m2) and (n1==n2)){
		for (int i=0;i<m1;i++){
			for (int j=0;j<n1;j++){
				R[i][j]=MA[i][j]-MB[i][j];	
			}
		}				
	}
	// **** MULTIPLICACION ****
	if(n1==m2){
		for (int i=0;i<m1;i++){
			for (int j=0;j<n2;j++){
				for (int k=0;k<m2;k++){
					M[i][j]=M[i][j]+(MA[i][k]*MB[k][j]);
				}	
			}
		}				
	}
	// **** INVERSA Y DETERMINANTE **** A
	if(m1==n1){
		if((DETA(MA, m1))!=0){
			for (int i=0;i<m1;i++){
				for(int j=m1;j<2*m1;j++){
					if(i==(j-m1)){
						INA[i][j]=1;
					}else{
						INA[i][j]=0;
					}	
				}
			}
			for (int k=0;k<m1;k++){
				elea=INA[k][k];
				for (int j=0;j<2*m1;j++){
					INA[k][j]=INA[k][j]/elea;
				}
				for(int i=0;i<m1;i++){
					if (i==k);
					else{
						coea=INA[i][k];
						for (int j=0;j<2*m1;j++){
							auxa[j]=INA[k][j]*(coea*(-1));
						}	
						for (int j=0;j<2*m1;j++){
							INA[i][j]=INA[i][j]+auxa[j];
						}		
					}
				}
			}
			for (int i=0;i<m1;i++){
				for (int j=m1;j<2*m1;j++){
					INA[i][j-m1]=INA[i][j];
				}	
			}
		}
	}
	// **** INVERSA Y DETERMINANTE **** B
	if(m2==n2){
		if((DETB(MB, m2))!=0){
			for (int i=0;i<m2;i++){
				for(int j=m2;j<2*m2;j++){
					if(i==(j-m2)){
						INB[i][j]=1;
					}else{
						INB[i][j]=0;
					}	
				}
			}
			for (int k=0;k<m2;k++){
				eleb=INB[k][k];
				for (int j=0;j<2*m2;j++){
					INB[k][j]=INB[k][j]/eleb;
				}
				for(int i=0;i<m2;i++){
					if (i==k);
					else{
						coeb=INB[i][k];
						for (int j=0;j<2*m2;j++){
							auxb[j]=INB[k][j]*(coeb*(-1));
						}	
						for (int j=0;j<2*m2;j++){
							INB[i][j]=INB[i][j]+auxb[j];
						}		
					}
				}
			}
			for (int i=0;i<m2;i++){
				for (int j=m2;j<2*m2;j++){
					INB[i][j-m2]=INB[i][j];
				}cout<<"\n";	
			}
		}
	}
	
	// **** DIVISION ****
	if((m2==n2) and ((DETB(MB, m2))!=0)){
		if(n1==m2){
			for (int i=0;i<m1;i++){
				for (int j=0;j<n2;j++){
					for (int k=0;k<m2;k++){
						D[i][j]=D[i][j]+(MA[i][k]*INB[k][j]);
					}	
				}
			}				
		}
	}cout<<"\n";
	cout<<"----------------------------------------------------"<<endl;
	cout<<"Que operacion desea mostrar..."<<endl;
	cout<<"\t\ta.- A + B"<<endl;
	cout<<"\t\tb.- A - B"<<endl;
	cout<<"\t\tc.- A x B"<<endl;
	cout<<"\t\td.- A / B"<<endl;
	cout<<"\t\te.- Mostrar todas las anteriores"<<endl;
	cout<<"\t\tf.- CONTINUAR"<<endl<<endl;
	cout<<"INGRESE SU ELECCION: "<<endl;
	cout<<" --> ";cin>>op1;
	cout<<"----------------------------------"<<endl;
	switch(op1){
		case 'a':{cout<<"\t******** S U M A ********"<<endl;
				cout<<"\n\t MATRIZ A + MATRIZ B "<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((m1==m2) and (n1==n2)){
					for (int i=0;i<m1;i++){cout<<"\t";
						for (int j=0;j<n1;j++){
							cout<<S[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN SUMAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN"<<endl;
				}
			break;
		}
		case 'b':{cout<<"\t******** R E S T A ********"<<endl;
				cout<<"\n\t MATRIZ A - MATRIZ B "<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((m1==m2) and (n1==n2)){
					for (int i=0;i<m1;i++){cout<<"\t";
						for (int j=0;j<n1;j++){
							cout<<R[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN RESTAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN"<<endl;
				}
			break;
		}
		case 'c':{cout<<"\t******** M U L T I P L I C A C I O N ********"<<endl;
				cout<<"\n\t MATRIZ A x MATRIZ B "<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((n1==m2)){
					for (int i=0;i<m1;i++){cout<<"\t";
						for (int j=0;j<n2;j++){
							cout<<M[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN MULTIPLICAR..."<<endl;
					cout<<"PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A, ES DIFERENTE DEL NUMERO DE FILAS DE LA MATRIZ B"<<endl;
				}
			break;
		}
		case 'd':{cout<<"\t******** D I V I S I O N ********"<<endl;
				cout<<"\n\t MATRIZ A / MATRIZ B "<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((m2==n2) and ((DETB(MB, m2))!=0)){
					if((n1==m2)){
						for (int i=0;i<m1;i++){cout<<"\t";
							for (int j=0;j<n2;j++){
								cout<<D[i][j]<<"\t";
							}cout<<"\n";
						}	
					}else{cout<<"NO SE PUEDEN MULTIPLICAR..."<<endl;
						cout<<"PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A, ES DIFERENTE DEL NUMERO DE FILAS DE LA INVERSA DE B"<<endl;
					}
				}else{cout<<"NO SE PUEDE DIVIDIR LA MATRIZ A CON LA MATRIZ B"<<endl;
				}
			break;
		}
		case 'e':{// SUMA
				cout<<"\t******** S U M A ********"<<endl;
				cout<<"\n\t MATRIZ A + MATRIZ B "<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((m1==m2) and (n1==n2)){
					for (int i=0;i<m1;i++){cout<<"\t";
						for (int j=0;j<n1;j++){
							cout<<S[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN SUMAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN"<<endl;
				}cout<<"\n";cout<<"\n";
				// RESTA
				cout<<"\t******** R E S T A ********"<<endl;
				cout<<"\n\t MATRIZ A - MATRIZ B "<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((m1==m2) and (n1==n2)){
					for (int i=0;i<m1;i++){cout<<"\t";
						for (int j=0;j<n1;j++){
							cout<<R[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN RESTAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN"<<endl;
				}cout<<"\n";cout<<"\n";
				// MULTIPLICACION
				cout<<"\t******** M U L T I P L I C A C I O N ********"<<endl;
				cout<<"\n\t MATRIZ A x MATRIZ B "<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((n1==m2)){
					for (int i=0;i<m1;i++){cout<<"\t";
						for (int j=0;j<n2;j++){
							cout<<M[i][j]<<"\t";
						}cout<<"\n";
					}	
				}else{cout<<"NO SE PUEDEN MULTIPLICAR..."<<endl;
					cout<<"PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A ES DIFERENTE DEL NUMERO DE FILAS DE LA MATRIZ B"<<endl;
				}cout<<"\n";cout<<"\n";
				// DIVISION
				cout<<"\t******** D I V I S I O N ********"<<endl;
				cout<<"\n\t MATRIZ A / MATRIZ B "<<endl;
				cout<<"---------------------------------------------"<<endl;
				if((m2==n2) and ((DETB(MB, m2))!=0)){
					if((n1==m2)){
						for (int i=0;i<m1;i++){cout<<"\t";
							for (int j=0;j<n2;j++){
								cout<<D[i][j]<<"\t";
							}cout<<"\n";
						}	
					}else{cout<<"NO SE PUEDEN MULTIPLICAR..."<<endl;
						cout<<"PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A, ES DIFERENTE DEL NUMERO DE FILAS DE LA INVERSA DE B"<<endl;
					}
				}else{cout<<"NO SE PUEDE DIVIDIR LA MATRIZ A CON LA MATRIZ B"<<endl;
				}
			break;
		}
		case 'f':{cout<<"Continue..."<<endl;
			break;
		}
	default:	cout<<"Error de eleccion"<<endl;
	}cout<<"\n";
	cout<<"----------------------------------------------------"<<endl;
	cout<<" DESEA REALIZAR OPERACIONES ADICIONALES PARA A"<<endl;
	cout<<"\t\t1.- SI"<<endl;
	cout<<"\t\t2.- NO"<<endl<<endl;
	cout<<"INGRESE SU ELECCION: "<<endl;
	cout<<" --> ";cin>>adia;
	if(adia==1){cout<<"\n\t********** OPERACIONES ADICIONALES **********"<<endl;
		cout<<"\t\t1.- Determinante"<<endl;
		cout<<"\t\t2.- Matriz inversa"<<endl;
		cout<<"\t\t3.- Matriz transpuesta"<<endl;
		cout<<"\t\t4.- Multiplicar por un escalar"<<endl;
		cout<<"\t\t5.- Rango"<<endl;
		cout<<"\t\t6.- Matriz Triangular"<<endl;
		cout<<"\t\t7.- Matriz Diagonal"<<endl;
		cout<<"\t\t8.- Matriz Elevada a..."<<endl;
		cout<<"\t\t9.- Factorizacion LU"<<endl;
		cout<<"\t\t10.- Factorizacion de Cholesky"<<endl;
		cout<<"\t\t11.- Valores y Vectores propios "<<endl;
		cout<<"\t\t12.- CONTINUAR"<<endl<<endl;
		cout<<"INGRESE SU ELECCION: "<<endl;
		cout<<" --> ";cin>>extra;
		cout<<"---------------------------------------------------------"<<endl;
		switch(extra){
			case 1:{cout<<"\t******** DETERMINANTE ********"<<endl<<endl;
				if(m1==n1){cout<<" La Determinante de la MATRIZ A es : "<<DETA(MA, m1)<<endl;
				}else{cout<<" LA MATRIZ A NO ES CUADRADA"<<endl;
					cout<<" POR TANTO NO SE PUEDE HALLAR LA DETERMINANTE"<<endl;
				}
				break;
			}
			case 2:{cout<<"\t******** MATRIZ INVERSA ********"<<endl<<endl;
				if(m1==n1){
					if((DETA(MA, m1))!=0){
						for (int i=0;i<m1;i++){cout<<"\t";
							for (int j=0;j<m1;j++){
								cout<<INA[i][j]<<"\t";
							}cout<<"\n";
						}
					}else{cout<<"\nNO SE PUEDE HALLAR LA INVERSA, PORQUE LA DETERMINANTE ES CERO"<<endl;
					}
				}else{cout<<"\nLA MATRIZ A NO ES CUADRADA"<<endl;
					cout<<" POR TANTO NO SE PUEDE HALLAR LA DETERMINANTE, NI LA INVERSA"<<endl;
				}
				break;
			}
			case 3:{cout<<"\t******** MATRIZ TRANSPUESTA ********"<<endl<<endl;
				for(int i=0;i<m1;i++){cout<<"\t";
					for(int j=0;j<n1;j++){
						cout<<MA[j][i]<<"\t";
					}cout<<"\n";
				}
				break;
			}
			case 4:{cout<<"\t******** MULTIPLICAR POR UN ESCALAR ********"<<endl;
				cout<<"POR FAVOR, INTRODUZCA UN ESCALAR PARA MULTIPLICAR A LA MATRIZ A"<<endl;
				cout<<" --> ";cin>>escalar;cout<<"\n";
				for (int i=0;i<m1;i++){cout<<"\t";
					for (int j=0;j<n1;j++){
						OPA[i][j]=(escalar)*(MA[i][j]);
						cout<<OPA[i][j]<<"\t";
					}cout<<"\n";
				}
				break;
			}
			case 5:{cout<<"\t******** RANGO ********"<<endl<<endl;
				cout<<"EL RANGO DE LA MATRIZ A ES : ";rango=0;
				for (int i=0;i<m1;i++){
					for (int j=0;j<n1;j++){
						if((MA[i][j])!=0){
							col=col+1;
						}
					}
					if(col>=1){
						fil=fil+1;
					}
				}rango=fil;fil=0;col=0;
				for (int j=0;j<n1;j++){
					for (int i=0;i<m1;i++){
						if((MA[i][j])!=0){
							fil=fil+1;
						}
					}
					if(fil>=1){
						col=col+1;
					}
				}
				if(rango>=col){rango=col;
				}
				cout<<rango<<endl;
				break;
			}
			case 6:{cout<<"\t******** MATRIZ TRIANGULAR ********"<<endl;
				for(int k=0;k<n1-1;k++){
					for(int i=0;i<m1;i++){
						x=MA[i+1][k];
						int p=0;
						if(k<i+1){
							if((MA[i+1][k])!=0){
								for(int j=k;j<n1;j++){
									MA[i+1][j]=MA[i+1][j]-((x/MA[k][k])*MA[k][j]);
									//cout<<"\n("<<i+1<<","<<j<<") ="<<MA[i+1][j];
									p=p+1;
								}
							}
						}	
					}cout<<"\n";cout<<"\n";
					for(int i=0;i<m1;i++){cout<<"\t";
						for(int j=0;j<n1;j++){
							cout<<MA[i][j]<<"\t";
						}cout<<"\n";
					}cout<<"\n";cout<<"\n";
				}
				for(int i=0;i<m1;i++){cout<<"\t";
					for(int j=0;j<n1;j++){
						cout<<MA[i][j]<<"\t";
					}cout<<"\n";
				}
				break;
			}
			case 7:{cout<<"\t******** MATRIZ DIAGONAL ********"<<endl;
				if(m1==n1){
					// MATENME xddddddd
				}else{cout<<"\nLA MATRIZ A NO ES CUADRADA"<<endl;
					cout<<" NO SE PUEDE HALLAR"<<endl;
				}
				break;
			}
			case 8:{cout<<"\t******** MATRIZ ELEVADA A ********"<<endl<<endl;	
				if(m1==n1){
					do{cout<<"INTRODUZCA UN ENTERO A ELEVAR LA MATRIZ A"<<endl;
					cout<<" --> ";cin>>elev;
					}while(elev<0);
					for (int i=0;i<m1;i++){
						for (int j=0;j<n1;j++){
							for (int k=0;k<m1;k++){
								OPA[i][j]=OPA[i][j]+(MA[i][k]*MA[k][j]);
							}	
						}
					}
					for (int i=0;i<m1;i++){
						for (int j=0;j<n1;j++){
							AEA[i][j]=OPA[i][j];
							OPA[i][j]=0;
						}
					}
					for (int l=2;l<elev;l++){
						for (int i=0;i<m1;i++){
							for (int j=0;j<n1;j++){
								for (int k=0;k<m1;k++){
									OPA[i][j]=OPA[i][j]+(AEA[i][k]*MA[k][j]);
								}	
							}
						}
						for (int i=0;i<m1;i++){
							for (int j=0;j<n1;j++){
								AEA[i][j]=OPA[i][j];
								OPA[i][j]=0;
							}
						}
					}
					for (int i=0;i<m1;i++){cout<<"\t";
						for (int j=0;j<n1;j++){
							cout<<AEA[i][j]<<"\t";
						}cout<<"\n";
					}
				}else{cout<<" LA MATRIZ A NO ES CUADRADA"<<endl;
					cout<<" NO SE PUEDE REALIZAR LA OPERACION"<<endl;
				}
				break;
			}
			case 9:{cout<<"\t******** FACTORIZACION LU ********"<<endl;
				for(int i=0;i<m1;i++){cout<<"\t";
					for(int j=0;j<n1;j++){
						if(i==j){
							LA[i][j]=1;
						}else{
							LA[i][j]=0;
						}
					}
				}
				for(int k=0;k<n1-1;k++){
					for(int i=0;i<m1;i++){
						x=MA[i+1][k];
						int p=0;
						if(k<i+1){
							if((MA[i+1][k])!=0){
								for(int j=k;j<n1;j++){
									MA[i+1][j]=MA[i+1][j]-((x/MA[k][k])*MA[k][j]);
									LA[i+1][k]=x/MA[k][k];
									//cout<<"\n("<<i+1<<","<<j<<") ="<<MA[i+1][j];
									p=p+1;
								}
							}
						}	
					}cout<<"\n";cout<<"\n";
					for(int i=0;i<m1;i++){cout<<"\t";
						for(int j=0;j<n1;j++){
							cout<<MA[i][j]<<"\t";
						}cout<<"\n";
					}cout<<"\n";cout<<"\n";
				}
				cout<<"\tPOR TANTO TENEMOS:"<<endl<<endl;
				cout<<"\t\t L "<<endl;
				cout<<"  ------------------------------------"<<endl;
				for(int i=0;i<m1;i++){cout<<"\t";
					for(int j=0;j<n1;j++){
						cout<<LA[i][j]<<"\t";
					}cout<<"\n";
				}cout<<"\n";cout<<"\n";
				cout<<"\t\t U "<<endl;
				cout<<"  ------------------------------------"<<endl;
				for(int i=0;i<m1;i++){cout<<"\t";
					for(int j=0;j<n1;j++){
						cout<<MA[i][j]<<"\t";
					}cout<<"\n";
				}cout<<"\n";
				break;
			}
			case 10:{cout<<"\t******** FACTORIZACION CHOLESKY ********"<<endl;
				if(m1==n1){a=0;
					for(int i=0;i<m1;i++){
						for(int j=0;j<n1;j++){
							LA[i][j]=0;
							if(MA[i][j]==MA[j][i]){a=a+1;
							}
						}
					}
					if(a==(m1*n1)){cout<<"\nLA MATRIZ A ES SIMETRICA, POR TANTO"<<endl<<endl;
						for(int i=0;i<m1;i++){
							for(int j=0;j<=i;j++){
								float sum=0;
								if(j==i){
									for(int k=0;k<j;k++){
										sum+=pow(LA[j][k],2);
									}
									LA[j][j]=sqrt((MA[j][j])-sum);
									//cout<<"\n("<<i<<","<<j<<") = "<<LA[i][j]<<endl;
								}else{
									for(int k=0;k<j;k++){
										sum+=(LA[i][k]*LA[j][k]);
									}
									LA[i][j]=(MA[i][j]-sum)/LA[j][j];
									//cout<<"\n("<<i<<","<<j<<") = "<<LA[i][j]<<endl;
								}
							}
						}
						cout<<"\t\t L "<<endl;
						cout<<"  ------------------------------------"<<endl;
						for(int i=0;i<m1;i++){cout<<"\t";
							for(int j=0;j<n1;j++){
								cout<<LA[i][j]<<"\t";
							}cout<<"\n";
						}cout<<"\n";cout<<"\n";
						cout<<"\t\t Ltranspuesta "<<endl;
						cout<<"  ------------------------------------"<<endl;
						for(int i=0;i<m1;i++){cout<<"\t";
							for(int j=0;j<n1;j++){
								cout<<LA[j][i]<<"\t";
							}cout<<"\n";
						}cout<<"\n";
					}else{cout<<"\nLA MATRIZ A NO ES SIMETRICA"<<endl;
					cout<<" POR TANTO NO SE PUEDE FACTORIZAR POR ESTE METODO"<<endl;
					}
				}else{cout<<"\nLA MATRIZ A NO ES CUADRADA"<<endl;
					cout<<" POR TANTO NO PUEDE SATISFACER SU CONDICION DE SIMETRIA"<<endl;
				}
				break;
			}
			case 11:{cout<<"\t******** VALORES Y VECTORES PROPIOS ********"<<endl;
				break;
			}
			case 12:{cout<<"\n";
				break;
			}
			default: cout<<"Error de dato de entrada"<<endl;
		}cout<<"\n";
	}
	if(adia==2){cout<<" ENTONCES ";
	}
	if((adia!=1) and (adia!=2)){cout<<"Error de dato de entrada..."<<endl;
	}
	cout<<"DESEA REALIZAR OPERACIONES ADICIONALES PARA B"<<endl;
	cout<<"\t\t1.- SI"<<endl;
	cout<<"\t\t2.- NO"<<endl<<endl;
	cout<<"INGRESE SU ELECCION: "<<endl;
	cout<<" --> ";cin>>adib;
	if(adib==1){cout<<"\t********** OPERACIONES ADICIONALES **********"<<endl;
		cout<<"\t\t1.- Determinante"<<endl;
		cout<<"\t\t2.- Matriz inversa"<<endl;
		cout<<"\t\t3.- Matriz transpuesta"<<endl;
		cout<<"\t\t4.- Multiplicar por un escalar"<<endl;
		cout<<"\t\t5.- Rango"<<endl;
		cout<<"\t\t6.- Matriz Triangular"<<endl;
		cout<<"\t\t7.- Matriz Diagonal"<<endl;
		cout<<"\t\t8.- Matriz Elevada a..."<<endl;
		cout<<"\t\t9.- Factorizacion LU"<<endl;
		cout<<"\t\t10.- Factorizacion de Cholesky"<<endl;
		cout<<"\t\t11.- Valores y Vectores propios "<<endl;
		cout<<"\t\t12.- CONTINUAR"<<endl<<endl;
		cout<<"INGRESE SU ELECCION: "<<endl;
		cout<<" --> ";cin>>extra;
		cout<<"---------------------------------------------------------"<<endl;
		switch(extra){
			case 1:{cout<<"\t******** DETERMINANTE ********"<<endl;
				if(m2==n2){cout<<" La Determinante de la MATRIZ B es : "<<DETB(MB, m2)<<endl;
				}else{cout<<" LA MATRIZ B NO ES CUADRADA"<<endl;
					cout<<" POR TANTO NO SE PUEDE HALLAR LA DETERMINANTE"<<endl;
				}
				break;
			}
			case 2:{cout<<"\t******** MATRIZ INVERSA ********"<<endl<<endl;
				if(m2==n2){
					if((DETA(MB, m2))!=0){
						for (int i=0;i<m2;i++){cout<<"\t";
							for (int j=m2;j<2*m2;j++){
								cout<<INB[i][j]<<"\t";
							}cout<<"\n";
						}
					}else{cout<<"\nNO SE PUEDE HALLAR LA INVERSA, PORQUE LA DETERMINANTE ES CERO"<<endl;
					}
				}else{cout<<"\nLA MATRIZ B NO ES CUADRADA"<<endl;
					cout<<" POR TANTO NO SE PUEDE HALLAR LA DETERMINANTE, NI LA INVERSA"<<endl;
				}
				break;
			}
			case 3:{cout<<"\t******** MATRIZ TRANSPUESTA ********"<<endl;
				for(int i=0;i<m2;i++){
					for(int j=0;j<n2;j++){
						cout<<MB[j][i]<<"\t";
					}cout<<"\n";
				}
				break;
			}
			case 4:{cout<<"\t******** MULTIPLICAR POR UN ESCALAR ********"<<endl;
				cout<<"POR FAVOR, INTRODUZCA UN ESCALAR PARA MULTIPLICAR A LA MATRIZ B"<<endl;
				cout<<" --> ";cin>>escalar;
				for (int i=0;i<m2;i++){
					for (int j=0;j<n2;j++){
						OPB[i][j]=(escalar)*(MB[i][j]);
						cout<<OPB[i][j]<<"\t";
					}cout<<"\n";
				}
				break;
			}
			case 5:{cout<<"\t******** RANGO ********"<<endl;
				cout<<"EL RANGO DE LA MATRIZ A ES : ";rango=0;
				for (int i=0;i<m2;i++){
					for (int j=0;j<n2;j++){
						if((MB[i][j])!=0){
							col=col+1;
						}
					}
					if(col>=1){
						fil=fil+1;
					}
				}rango=fil;fil=0;col=0;
				for (int j=0;j<n2;j++){
					for (int i=0;i<m2;i++){
						if((MB[i][j])!=0){
							fil=fil+1;
						}
					}
					if(fil>=1){
						col=col+1;
					}
				}
				if(rango>=col){rango=col;
				}
				cout<<rango<<endl;
				break;
			}
			case 6:{cout<<"\t******** MATRIZ TRIANGULAR ********"<<endl;
				for(int k=0;k<n2-1;k++){
					for(int i=0;i<m2;i++){
						x=MB[i+1][k];
						int p=0;
						if(k<i+1){
							if((MB[i+1][k])!=0){
								for(int j=k;j<n2;j++){
									MB[i+1][j]=MB[i+1][j]-((x/MB[k][k])*MB[k][j]);
									//cout<<"\n("<<i+1<<","<<j<<") ="<<MA[i+1][j];
									p=p+1;
								}
							}
						}	
					}cout<<"\n";cout<<"\n";
					for(int i=0;i<m2;i++){cout<<"\t";
						for(int j=0;j<n2;j++){
							cout<<MB[i][j]<<"\t";
						}cout<<"\n";
					}cout<<"\n";cout<<"\n";
				}
				for(int i=0;i<m2;i++){cout<<"\t";
					for(int j=0;j<n2;j++){
						cout<<MB[i][j]<<"\t";
					}cout<<"\n";
				}
				break;
			}
			case 7:{cout<<"\t******** MATRIZ DIAGONAL ********"<<endl;
				break;
			}
			case 8:{cout<<"\t******** MATRIZ ELEVADA A ********"<<endl;
				if(m1==n1){
					do{cout<<"INTRODUZCA UN ENTERO A ELEVAR LA MATRIZ B"<<endl;
					cout<<" --> ";cin>>elev;
					}while(elev<0);
					for (int i=0;i<m2;i++){
						for (int j=0;j<n2;j++){
							for (int k=0;k<m2;k++){
								OPB[i][j]=OPB[i][j]+(MB[i][k]*MB[k][j]);
							}	
						}
					}
					for (int i=0;i<m2;i++){
						for (int j=0;j<n2;j++){
							AEB[i][j]=OPB[i][j];
							OPB[i][j]=0;
						}
					}
					for (int l=2;l<elev;l++){
						for (int i=0;i<m2;i++){
							for (int j=0;j<n2;j++){
								for (int k=0;k<m2;k++){
									OPB[i][j]=OPB[i][j]+(AEB[i][k]*MB[k][j]);
								}	
							}
						}
						for (int i=0;i<m2;i++){
							for (int j=0;j<n2;j++){
								AEB[i][j]=OPB[i][j];
								OPB[i][j]=0;
							}
						}
					}
					for (int i=0;i<m2;i++){cout<<"\t";
						for (int j=0;j<n2;j++){
							cout<<AEB[i][j]<<"\t";
						}cout<<"\n";
					}
				}else{cout<<" LA MATRIZ B NO ES CUADRADA"<<endl;
					cout<<" NO SE PUEDE REALIZAR LA OPERACION"<<endl;
				}
				break;
			}
			case 9:{cout<<"\t******** FACTORIZACION LU ********"<<endl;
				for(int i=0;i<m2;i++){cout<<"\t";
					for(int j=0;j<n2;j++){
						if(i==j){
							LB[i][j]=1;
						}else{
							LB[i][j]=0;
						}
					}
				}
				for(int k=0;k<n2-1;k++){
					for(int i=0;i<m2;i++){
						x=MB[i+1][k];
						int p=0;
						if(k<i+1){
							if((MB[i+1][k])!=0){
								for(int j=k;j<n2;j++){
									MB[i+1][j]=MB[i+1][j]-((x/MB[k][k])*MB[k][j]);
									LB[i+1][k]=x/MB[k][k];
									//cout<<"\n("<<i+1<<","<<j<<") ="<<MA[i+1][j];
									p=p+1;
								}
							}
						}	
					}cout<<"\n";cout<<"\n";
					for(int i=0;i<m2;i++){cout<<"\t";
						for(int j=0;j<n2;j++){
							cout<<MB[i][j]<<"\t";
						}cout<<"\n";
					}cout<<"\n";cout<<"\n";
				}
				cout<<"\tPOR TANTO TENEMOS:"<<endl<<endl;
				cout<<"\t\t L "<<endl;
				cout<<"  ------------------------------------"<<endl;
				for(int i=0;i<m2;i++){cout<<"\t";
					for(int j=0;j<n2;j++){
						cout<<LB[i][j]<<"\t";
					}cout<<"\n";
				}cout<<"\n";cout<<"\n";
				cout<<"\t\t U "<<endl;
				cout<<"  ------------------------------------"<<endl;
				for(int i=0;i<m2;i++){cout<<"\t";
					for(int j=0;j<n2;j++){
						cout<<MB[i][j]<<"\t";
					}cout<<"\n";
				}cout<<"\n";
				break;
			}
			case 10:{cout<<"\t******** FACTORIZACION CHOLESKY ********"<<endl;
				if(m2==n2){a=0;
					for(int i=0;i<m2;i++){
						for(int j=0;j<n2;j++){
							if(MB[i][j]==MB[j][i]){a=a+1;
							}
						}
					}
					if(a==(m2*n2)){cout<<"\nLA MATRIZ A ES SIMETRICA, POR TANTO"<<endl;
						for(int i=0;i<m2;i++){
							for(int j=0;j<=i;j++){
								float sum=0;
								if(j==i){
									for(int k=0;k<j;k++){
										sum+=pow(LB[j][k],2);
									}
									LB[j][j]=sqrt((MB[j][j])-sum);
									//cout<<"\n("<<i<<","<<j<<") = "<<LB[i][j]<<endl;
								}else{
									for(int k=0;k<j;k++){
										sum+=(LB[i][k]*LB[j][k]);
									}
									LB[i][j]=(MB[i][j]-sum)/LB[j][j];
									//cout<<"\n("<<i<<","<<j<<") = "<<LB[i][j]<<endl;
								}
							}
						}
						cout<<"\t\t L "<<endl;
						cout<<"  ------------------------------------"<<endl;
						for(int i=0;i<m2;i++){cout<<"\t";
							for(int j=0;j<n2;j++){
								cout<<LB[i][j]<<"\t";
							}cout<<"\n";
						}cout<<"\n";cout<<"\n";
						cout<<"\t\t Ltranspuesta "<<endl;
						cout<<"  ------------------------------------"<<endl;
						for(int i=0;i<m2;i++){cout<<"\t";
							for(int j=0;j<n2;j++){
								cout<<LB[j][i]<<"\t";
							}cout<<"\n";
						}cout<<"\n";
					}else{cout<<"\nLA MATRIZ B NO ES SIMETRICA"<<endl;
					cout<<" POR TANTO NO SE PUEDE FACTORIZAR POR ESTE METODO"<<endl;
					}
				}else{cout<<"\nLA MATRIZ B NO ES CUADRADA"<<endl;
					cout<<" POR TANTO NO PUEDE SATISFACER SU CONDICION DE SIMETRIA"<<endl;
				}
				break;
			}
			case 11:{cout<<"\t******** VALORES Y VECTORES PROPIOS ********"<<endl;
				break;
			}
			case 12:{cout<<"\n";
				break;
			}
			default: cout<<"Error de dato de entrada"<<endl;
		}cout<<"\n";
	}
	if(adib==2){cout<<"\n";
	}
	if((adib!=1) and (adib!=2)){cout<<"Error de dato de entrada"<<endl;
	}
	
	return 0;
}
	// ***** PARA A *****
float DETA(float MA[100][100], int m1){
   float deta=0;
   
	if(m1==1){
		deta=MA[0][0];
	}else{
		for(int i=0;i<m1;i++){
			deta=deta + ((MA[0][i])*(COFA(MA, m1, 0, i)));
		}
	}
   return deta;
}

float COFA(float MA[100][100], int m1, int fa, int ca){
   float AUXA[100][100],cofa;
   int rna=m1-1;
   int aa=0,ba=0;
   
   for(int i=0;i<m1;i++){
		for(int j=0;j<m1;j++){
			if((i!=fa) && (j!=ca)){
            	AUXA[aa][ba]=MA[i][j];
            	ba=ba+1;
	            if(ba>=rna){
	               aa=aa+1;
	               ba=0;
	            }
        	}
		}
	}
	cofa=pow(-1,(fa+ca)) * (DETA(AUXA, rna));
   return cofa;
}
	// ***** PARA B *****
float DETB(float MB[100][100], int m2){
   float detb=0;
   
	if(m2==1){
		detb=MB[0][0];
	}else{
		for(int i=0;i<m2;i++){
			detb=detb + ((MB[0][i])*(COFB(MB, m2, 0, i)));
		}
	}
   return detb;
}

float COFB(float MB[100][100], int m2, int fb, int cb){
   float AUXB[100][100],cofb;
   int rnb=m2-1;
   int ab=0,bb=0;
   
   for(int i=0;i<m2;i++){
		for(int j=0;j<m2;j++){
			if((i!=fb) && (j!=cb)){
            	AUXB[ab][bb]=MB[i][j];
            	bb=bb+1;
	            if(bb>=rnb){
	               ab=ab+1;
	               bb=0;
	            }
        	}
		}
	}
	cofb=pow(-1,(fb+cb)) * (DETB(AUXB, rnb));
	
   return cofb;
}
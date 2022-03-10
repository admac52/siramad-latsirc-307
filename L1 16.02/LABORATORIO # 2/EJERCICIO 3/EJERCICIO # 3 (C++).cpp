//3. Realizar la division de polinomios con el método Horner

#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

int main(){
	int n1,n2,m1,m2,m3,m4,grado,resto;
	float VectorA[100],VectorB[100],Cociente[100];
	float MH[100][100];
	char op;
	
	do{
		cout<<"\n\t\t********** METODO HORNER ***********"<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"DADO UN POLINOMIO: "<<endl;
		cout<<"\t\tPx(n) = ax^n + bx^n-1 + cx^n-2 + ... + dx + e"<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"\tNUMERADOR"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Escriba el grado < n > del polinomio :"<<endl;
		cin>>n1;cout<<"\n";
    	cout<<"Ingrese los coeficientes en grado descendente con su signo correspondiente :"<<endl;
		for(int i=0;i<=n1;i++){
			m1=n1-i;
			cout<<"\n--> Px1("<<m1<<") = ";
			cin>>VectorA[n1-i];
		}
		cout<<"---------------------------"<<endl;
		cout<<"\tDENOMINADOR"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Escriba el grado < n > del polinomio :"<<endl;
		cin>>n2;cout<<"\n";
    	cout<<"Ingrese los coeficientes en grado descendente con su signo correspondiente :"<<endl;
		for(int i=0;i<=n2;i++){
			m2=n2-i;
			cout<<"\n--> Px2("<<m2<<") = ";
			cin>>VectorB[n2-i];
		}cout<<"\n";
		cout<<"\tTENEMOS: "<<endl;cout<<"\n\t\t";
		for(int i=0;i<=n1;i++){
			m1=n1-i;
			if(m1!=0){
				cout<<VectorA[n1-i]<<"x^"<<m1<<" + ";	
			}
			if(m1==0){
				cout<<VectorA[n1-i]<<"x^"<<m1;
			}	
		}cout<<"\n";
		cout<<"\t-->   ----------------------------------------------"<<endl;cout<<"\t\t";
		for(int i=0;i<=n2;i++){
			m2=n2-i;
			if(m2!=0){
				cout<<VectorB[n2-i]<<"x^"<<m2<<" + ";	
			}
			if(m2==0){
				cout<<VectorB[n2-i]<<"x^"<<m2;
			}	
		}cout<<"\n";cout<<"\n";
		// RELLENADO
		for(int i=0;i<=0;i++){
			for(int j=0;j<=n1+1;j++){
				MH[i][n1-j+1]=VectorA[j];
			}	
		}
		for(int j=0;j<=0;j++){
			for(int i=0;i<=n2;i++){
				if(i==n2){
					MH[n2-i][j]=VectorB[i];
				}else{
					MH[n2-i][j]=(-1)*VectorB[i];
					VectorB[i]=MH[n2-i][j];
				}	
			}	
		}
		resto=n1-n2+1;
		// ****** APLICACION DE HORNER ******
		// DIVISION
		for(int i=0;i<=n2;i++){
			Cociente[i+1]=MH[0][i+1]/MH[i][i];
		}
		for(int k=0;k<=n1+1;k++){
			// MULTIPLICACION 1
			for(int i=k+1;i<=k+1;i++){
				for(int j=k+1;j<=n2+k;j++){
					if(i==resto+1){break;
					}
					MH[i][j+1]=Cociente[i]*VectorB[n2-j+k];
				}	
			}
			// SUMATORIA 1
			for(int j=k+2;j<=k+2;j++){Cociente[j]=0;
				for(int i=0;i<=resto+1;i++){
					if(j>=resto+1){
						Cociente[j]=Cociente[j]+MH[i][j];
					}else{
						Cociente[j]=Cociente[j]+MH[i][j];
						if(i==resto+1){
							Cociente[j]=Cociente[j]/MH[0][0];
						}
					}	
				}	
			}
		}
		// MOSTRAR LO REALIZADO
		cout<<"\n\t*************** PROCEDIMIENTO ***************"<<endl<<endl;
		for(int i=0;i<=resto+1;i++){cout<<"\t";
			for(int j=0;j<=n1+1;j++){
				cout<<MH[i][j]<<"\t";
			}cout<<"\n";
		}cout<<"\n";cout<<"----------------------------------------------------------------"<<endl;cout<<"\t\t";
		for(int i=1;i<=n1+1;i++){
			cout<<Cociente[i]<<"\t";
		}cout<<"\n";
		grado=n1-n2;
		cout<<"\n LA DIVISION ENTRE LOS POLINOMIOS ES : "<<endl<<endl;
		cout<<"\t--> ";
		for(int i=0;i<=grado;i++){
			m3=grado-i;
			if(m3!=0){
				cout<<Cociente[i+1]<<"x^"<<m3<<" + ";	
			}
			if(m3==0){
				cout<<Cociente[i+1]<<"x^"<<m3;
			}	
		}cout<<"\n";
		cout<<"\n Y TIENE RESTO : "<<endl<<endl;
		cout<<"\t--> ";
		for(int i=grado+1;i<=n1+1;i++){
			m4=n1-i;
			if(m4!=0){
				cout<<Cociente[i+1]<<"x^"<<m4<<" + ";	
			}
			if(m4==0){
				cout<<Cociente[i+1]<<"x^"<<m4;
				break;
			}	
		}cout<<"\n\n";
		cout<<"\nDESEA REALIZAR OTRA OPERACION (S/N) "<<endl;
		cin>>op;
	}while(op=='s' or op=='S');
	cout<<"\nGRACIAS..."<<endl;
	
	
	return 0;
}
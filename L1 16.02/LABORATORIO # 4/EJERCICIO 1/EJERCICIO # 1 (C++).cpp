// 1.- Comprueba si una palabra es palindroma por ejemplo: ANA,ANNA, OTTO

#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

int main() {
	int n=0,m=0,c=0;
	char Palabra[100];
	char op;

	do{
		cout<<"\n\t\tBIENVENIDO, VAMOS A DETERMINAR SI UNA PALABRA ES PALINDROMA O NO"<<endl;
		cout<<"\t----------------------------------------------------------------------------"<<endl;
		cout<<"\n\t\tNota: Por favor escribir todo el MAYUSCULAS o todo en minusculas"<<endl;
		cout<<"\n\t\t      o todo en minusculas, sino puede presentar error."<<endl;
		cout<<"\n\t\t    - Ademas de no colocar signos,acentos u otros caracteres"<<endl;
		cout<<"\n\t\t      sino puede presentar error."<<endl;
		cout<<"\t----------------------------------------------------------------------------"<<endl;
		cout<<"\n\t\tEscriba una palabra por favor"<<endl;cout<<" ---> ";
		cin.getline(Palabra, 100);
		cout<<"\n";cout<<"\n";
		n=strlen(Palabra);
		
		if(n%2==0){m=(n/2);
			for(int i=0;i<m;i++){
				//cout<<Palabra[i]<<" ES IGUAL A ";
				//cout<<Palabra[n-i-1]<<endl;
				if(Palabra[i]==Palabra[n-1-i]){
					c=c+1;
				}
			}
			if(c==m){
					cout<<"LA PALABRA < ";
					for(int j=0;j<n;j++){
						cout<<Palabra[j];
					}
					cout<<" > ES PALINDROMA"<<endl;
				}else{
					cout<<"LA PALABRA < ";
					for(int j=0;j<n;j++){
						cout<<Palabra[j];
					}
					cout<<" > NO ES PALINDROMA"<<endl;
				}
		}else{m=((n-1)/2);
			for(int i=0;i<m;i++){
				if(Palabra[i]==Palabra[n-1-i]){
					c=c+1;
				}
			}
			if(c==m){
				cout<<"LA PALABRA < ";
				for(int j=0;j<n;j++){
					cout<<Palabra[j];
				}
				cout<<" > ES PALINDROMA"<<endl;
			}else{
				cout<<"LA PALABRA < ";
				for(int j=0;j<n;j++){
					cout<<Palabra[j];
				}
				cout<<" > NO ES PALINDROMA"<<endl;
			}	
		}
		cout<<"\nDESEA REALIZAR OTRA OPERACION (S/N) "<<endl;
		cin>>op;
		
	}while(op=='s' or op=='S');
		
	return 0;
}

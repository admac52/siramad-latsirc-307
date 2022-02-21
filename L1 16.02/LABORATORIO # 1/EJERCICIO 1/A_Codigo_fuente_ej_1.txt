//1. Series de Mclaurin y Taylor

#include<iostream>
#include<math.h>
#define PI 3.14159265359
using namespace std;

int main(){
	int i,j,x,op,n,punto,d=0;
	float S=0,f=1,p=0,a=0,b=0,c=0,mult=0;
	float e=2.718281828,rad=0,seno=0,coseno=0;
	double VectorA[100];
	double VectorB[100];
	
	cout<<"\n\t******** SERIES DE TAYLOR y MCLAURIN *********"<<endl;
	cout<<"\t-----------------------------------------------"<<endl;
	cout<<"\t\t1.- e^x"<<endl;
	cout<<"\t\t2.- Sen x"<<endl;
	cout<<"\t\t3.- Cos x"<<endl;
	cout<<"\t\t4.- SALIR"<<endl<<endl;
	cout<<"INGRESE SU ELECCION: "<<endl;
	cin>>op;
	cout<<"--------------------------------"<<endl;
	switch(op){
		case 1:{VectorA[0]=1;
			do{cout<<"INGRESE UN VALOR PARA x : "<<endl;
				cin>>x;
			}while(x<0);
			do{cout<<"INGRESE EL VALOR LIMITE n DE LA SERIE : "<<endl;
				cin>>n;
			}while(n<0 or n>100);
			cout<<"ALREDEDOR DEL PUNTO : "<<endl;
			cin>>punto;
			//Potencia
			for (i=0;i<=n;i++){
				p=pow(x,i);
				VectorB[i]=p;
			}
			//Factorial
			for (i=1;i<=n;i++){
				f=1;
				for (j=1;j<=i;j++){
					f=f*j;
				}
				VectorA[i]=f;
			}
			//Sumatoria
			for (i=0;i<=n;i++){
				S=S+((VectorB[i])/(VectorA[i]));
			}cout<<"\n";
			cout<<"LA SERIE DE MCLAURIN DE LA FUNCION EXPONENCIAL VALE : "<<S<<endl;
	S=0;f=1;p=0;
			//Numerador
			for (i=0;i<=n;i++){
				p=pow(e,punto);
				mult=p*(pow((x-punto),i));
				VectorB[i]=mult;
			}
			//Factorial
			for (i=1;i<=n;i++){
				f=1;
				for (j=1;j<=i;j++){
					f=f*j;
				}
				VectorA[i]=f;
			}
			for (i=0;i<=n;i++){
				S=S+((VectorB[i])/(VectorA[i]));
				//cout<<"suma "<<S<<endl;
			}cout<<"\n";
			cout<<"LA SERIE DE TAYLOR DE LA FUNCION EXPONENCIAL EN EL PUNTO "<<punto<<" VALE : "<<S<<endl;
			break;
		}
		case 2:{f=1,a=0,b=0,S=0;
			do{cout<<"INGRESE UN VALOR PARA x : "<<endl;
				cin>>x;
			}while(x<0);
			do{cout<<"INGRESE EL VALOR LIMITE n DE LA SERIE : "<<endl;
				cin>>n;	
			}while(n<0 or n>100);
			cout<<"ALREDEDOR DEL PUNTO (EN GRADOS) : "<<endl;
			cin>>punto;
			
			for (i=0;i<=n;i++){
				a=(2*i)+1;
				p=pow(x,a);
				VectorB[i]=p;
			}
			for (i=0;i<=n;i++){f=1;
				b=(2*i)+1;
				for (j=1;j<=b;j++){
					f=f*j;
				}
				VectorA[i]=f;
			}
			for (i=0;i<=n;i++){
				c=pow((-1),i);
				S=S+((VectorB[i])*c/(VectorA[i]));
			}cout<<"\n";
			cout<<"LA SERIE DE MCLAURIN DE LA FUNCION sen x VALE : "<<S<<endl;
	S=0;f=1;mult=0;a=-4;b=-3;c=-2;d=-1;
	rad=punto*PI/180;
	//FuncionNumerador
			for (i=0;i<=n;i++){
				if(i==a+4){
					seno=sin(rad);
					mult=seno*(pow((x-rad),i));
					VectorB[i]=mult;
					a=a+4;
				}
				if(i==b+4){
					coseno=cos(rad);
					mult=coseno*(pow((x-rad),i));
					VectorB[i]=mult;
					b=b+4;
				}
				if(i==c+4){
					seno=sin(rad);
					mult=(-1)*seno*(pow((x-rad),i));
					VectorB[i]=mult;
					c=c+4;
				}
				if(i==d+4){
					coseno=cos(rad);
					mult=(-1)*coseno*(pow((x-rad),i));
					VectorB[i]=mult;
					d=d+4;
				}	
			}
//			for (i=0;i<=n;i++){
//				cout<<"\nvectorb "<<VectorB[i];
//			}
	//Factorial
			for (i=1;i<=n;i++){
				f=1;
				for (j=1;j<=i;j++){
					f=f*j;
				}
				VectorA[i]=f;
			}
			for (i=0;i<=n;i++){
				S=S+((VectorB[i])/(VectorA[i]));
			}cout<<"\n";
			cout<<"LA SERIE DE TAYLOR DE LA FUNCION sen x EN EL PUNTO "<<punto<<"° VALE : "<<S<<endl;
			break;
		}
		case 3:{f=1,a=0,b=0,S=0;
			do{cout<<"INGRESE UN VALOR PARA x : "<<endl;
				cin>>x;
			}while(x<0);
			do{cout<<"INGRESE EL VALOR LIMITE n DE LA SERIE : "<<endl;
				cin>>n;	
			}while(n<0 or n>100);
			cout<<"ALREDEDOR DEL PUNTO (EN GRADOS) : "<<endl;
			cin>>punto;
			for (i=0;i<=n;i++){
				a=(2*i);
				p=pow(x,a);
				VectorB[i]=p;
			}
			for (i=0;i<=n;i++){f=1;
				b=(2*i);
				for (j=1;j<=b;j++){
					f=f*j;
				}
				VectorA[i]=f;
			}
			for (i=0;i<=n;i++){
				c=pow((-1),i);
				S=S+((VectorB[i])*c/(VectorA[i]));
			}cout<<"\n";
			cout<<"LA SERIE DE MCLAURIN DE LA FUNCION cos x VALE : "<<S<<endl;
	S=0;f=1;mult=0;a=-4;b=-3;c=-2;d=-1;
	rad=punto*PI/180;
	//FuncionNumerador
			for (i=0;i<=n;i++){
				if(i==a+4){
					coseno=cos(rad);
					//cout<<"\nsen "<<coseno;
					mult=coseno*(pow((x-rad),i));
				//	cout<<"\nmult "<<mult;
					VectorB[i]=mult;
					a=a+4;
				}
				if(i==b+4){
					seno=sin(rad);
					mult=(-1)*seno*(pow((x-rad),i));
					VectorB[i]=mult;
					b=b+4;
				}
				if(i==c+4){
					coseno=cos(rad);
					mult=(-1)*coseno*(pow((x-rad),i));
					VectorB[i]=mult;
					c=c+4;
				}
				if(i==d+4){
					seno=sin(rad);
					mult=seno*(pow((x-rad),i));
					VectorB[i]=mult;
					d=d+4;
				}	
			}
//			for (i=0;i<=n;i++){
//				cout<<"\nvectorb "<<VectorB[i];
//			}
	//Factorial
			for (i=1;i<=n;i++){
				f=1;
				for (j=1;j<=i;j++){
					f=f*j;
				}
				VectorA[i]=f;
			}
			for (i=0;i<=n;i++){
				S=S+((VectorB[i])/(VectorA[i]));
			}cout<<"\n";
			cout<<"LA SERIE DE TAYLOR DE LA FUNCION cos x EN EL PUNTO "<<punto<<"° VALE : "<<S<<endl;
			break;
		}
		case 4:{cout<<"Hasta luego..."<<endl;
			break;
		}
	default:	cout<<"Error"<<endl;
	}
	return 0;	
}

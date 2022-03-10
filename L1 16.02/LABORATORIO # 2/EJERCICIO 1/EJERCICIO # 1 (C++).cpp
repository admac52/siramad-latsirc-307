// 1. Resolución de triángulos  dados 3 datos: a) tres lados
//                                             b) tres ángulos
//                                             c) dos lados y un ángulo
//                                             d) dos ángulos y un lado
//   Resolver los otros tres valores, calcular el area o superficie del triangulo y medianas

#include<iostream>
#include<math.h>
#include<string.h>
#define PI 3.14159265359

using namespace std;
int main(){
	int op1,cl=0,ca=0,gl[10],ga[10];
	float lado[10],angulo[10],mediana[10];
	float area=0,x=0;
	char op2;
	
	do{
		cout<<"\n\t******** RESOLUCION DE TRIANGULOS *********"<<endl;
		cout<<"\t-------------------------------------------"<<endl;
		cout<<"\t\t1.- INGRESAR DATOS"<<endl;
		cout<<"\t\t2.- SALIR"<<endl<<endl;
		cout<<"INGRESE SU ELECCION: "<<endl;
		cin>>op1;
		cout<<"--------------------------------------------"<<endl;
		switch(op1){
			case 1:{cout<<"\n\t\t***** TRIANGULOS *****"<<endl;
					cout<<"\t\t----------------------"<<endl<<endl;
					cout<<"\t\t         /\\"<<endl;
					cout<<"\t\t        /  \\"<<endl;
					cout<<"\t\t       / 1* \\"<<endl;
					cout<<"\t    LADO 1    /      \\"<<endl;
					cout<<"\t\t     /        \\    LADO 2"<<endl;
					cout<<"\t\t    /          \\"<<endl;
					cout<<"\t\t   /            \\"<<endl;
					cout<<"\t\t  /              \\"<<endl;
					cout<<"\t\t /                \\"<<endl;
					cout<<"\t\t/__)3*________2*(__\\"<<endl<<endl;
					cout<<"\t\t       LADO 3"<<endl;
					cout<<"\t--------------------------------"<<endl;
					cout<<"\tINGRESE LOS DATOS CONFORME SE DENOTA EN EL TRIANGULO MOSTRADO :"<<endl;
					cout<<"\t(En caso de no poseer un dato ingresar cero)"<<endl;
					cout<<"\t(Ingresar los angulos en grados positivos)"<<endl;
					cout<<"\n\t\tLADOS"<<endl;
					cout<<"\t----------------------"<<endl;
					for(int i=1;i<=3;i++){
						do{	cout<<" --> Lado < "<<i<<" > = ";
							cin>>lado[i];
						}while(lado[i]<0);
						if(lado[i]!=0){cl=cl+1;
							gl[cl]=i;
						}
					}cout<<"\n\t\tANGULOS"<<endl;
					cout<<"\t----------------------"<<endl;
					for(int i=1;i<=3;i++){
						do{	cout<<" --> Angulo < "<<i<<" > en grados = ";
							cin>>angulo[i];
						}while(angulo[i]<0);
						if(angulo[i]!=0){ca=ca+1;
							ga[ca]=i;
						}
					}cout<<"\n";cout<<"\n";   
					cout<<"SE TIENE "<<cl<<" LADOS Y "<<ca<<" ANGULOS COMO DATOS"<<endl<<endl;
					if(cl==3){cout<<"\t\ta) Tres lados"<<endl;// LEY DE COSENOS
						angulo[3]= acos( double (((pow((lado[3]),2))+(pow((lado[1]),2))-(pow((lado[2]),2)))/(2*lado[3]*lado[1])));angulo[3]=angulo[3]*180/PI;            //
						angulo[1]= acos( double (((pow((lado[2]),2))+(pow((lado[1]),2))-(pow((lado[3]),2)))/(2*lado[2]*lado[1])));angulo[1]=angulo[1]*180/PI;
						angulo[2]=180-angulo[3]-angulo[1];
					}
					if(ca==3 and cl==0){cout<<"\t\tb) Tres angulos"<<endl;
						cout<<"\t\tNO ES POSIBLE CALCULAR..."<<endl;
						cout<<"\tDEBIDO A QUE EXISTEN INFINITOS TRIANGULOS DE DIVERSOS TAMANOS, QUE PUEDEN POSEER LOS MISMOS ANGULOS"<<endl;
					}
					// LEY DE SENOS con un angulo que NO forman estos
					// LEY DE COSENOS con un angulo que SI forman estos
					if(cl==2 and ca==1){cout<<"\t\tc) Dos lados y un angulo"<<endl;
						for(int i=1;i<=3;i++){	
							if(gl[i]==1 and gl[i+1]==2 and ga[i]==1){// LEY DE COSENOS Y LEY DE SENOS
								lado[3]= sqrt(pow((lado[1]),2)+(pow((lado[2]),2))-(2*lado[1]*lado[2]*(cos(double (angulo[1]*(PI/180))))));
								angulo[3]= asin(double ((lado[2]*(sin(double (angulo[1]*(PI/180)))))/lado[3]));angulo[3]=angulo[3]*180/PI;
								angulo[2]=180-angulo[1]-angulo[3];
							}
							if(gl[i]==1 and gl[i+1]==3 and ga[i]==1){// LEY DE SENOS
								angulo[2]= asin(double ((lado[1]*(sin(double (angulo[1]*(PI/180)))))/lado[3]));angulo[2]=angulo[2]*180/PI;
								angulo[3]=180-angulo[1]-angulo[2];
								lado[2]=lado[3]*(sin(double (angulo[3]*(PI/180))))/(sin(double (angulo[1]*(PI/180))));
							}
							if(gl[i]==2 and gl[i+1]==3 and ga[i]==1){// LEY DE SENOS
								angulo[3]= asin(double ((lado[2]*(sin(double (angulo[1]*(PI/180)))))/lado[3]));angulo[3]=angulo[3]*180/PI;
								angulo[2]=180-angulo[1]-angulo[3];
								lado[1]=lado[3]*(sin(double (angulo[2]*(PI/180))))/(sin(double (angulo[1]*(PI/180))));
							}
							if(gl[i]==1 and gl[i+1]==2 and ga[i]==2){// LEY DE SENOS
								angulo[3]= asin(double ((lado[2]*(sin(double (angulo[2]*(PI/180)))))/lado[1]));angulo[3]=angulo[3]*180/PI;
								angulo[1]=180-angulo[2]-angulo[3];
								lado[3]=lado[1]*(sin(double (angulo[1]*(PI/180))))/(sin(double (angulo[2]*(PI/180))));
							}
							if(gl[i]==1 and gl[i+1]==3 and ga[i]==2){// LEY DE SENOS
								angulo[1]= asin(double ((lado[3]*(sin(double (angulo[2]*(PI/180)))))/lado[1]));angulo[1]=angulo[1]*180/PI;
								angulo[3]=180-angulo[1]-angulo[2];
								lado[2]=lado[3]*(sin(double (angulo[3]*(PI/180))))/(sin(double (angulo[3]*(PI/180))));
							}
							if(gl[i]==2 and gl[i+1]==3 and ga[i]==2){// LEY DE COSENOS Y LEY DE SENOS
								lado[1]= sqrt(pow((lado[2]),2)+(pow((lado[3]),2))-(2*lado[2]*lado[3]*(cos(double (angulo[2]*(PI/180))))));
								angulo[3]= asin(double ((lado[2]*(sin(double (angulo[2]*(PI/180)))))/lado[1]));angulo[3]=angulo[3]*180/PI;
								angulo[1]=180-angulo[3]-angulo[2];
							}
							if(gl[i]==1 and gl[i+1]==2 and ga[i]==3){// LEY DE SENOS
								angulo[2]= asin(double ((lado[1]*(sin(double (angulo[3]*(PI/180)))))/lado[2]));angulo[2]=angulo[2]*180/PI;
								angulo[1]=180-angulo[3]-angulo[2];
								lado[3]=lado[2]*(sin(double (angulo[1]*(PI/180))))/(sin(double (angulo[3]*(PI/180))));
							}
							if(gl[i]==1 and gl[i+1]==3 and ga[i]==3){// LEY DE TANGENTES Y LEY DE SENOS
								x=((lado[1]-lado[3])*(tan(double (((180-angulo[3])/2)*(PI/180)))))/(lado[1]+lado[3]);x=atan(double (x));
								angulo[2]=((180-angulo[3])/2)-(x*(180/PI));
								angulo[1]=(2*(x*(180/PI)))+angulo[2];
								lado[2]=lado[1]*(sin(double (angulo[3]*(PI/180))))/(sin(double (angulo[1]*(PI/180))));
							}
							if(gl[i]==2 and gl[i+1]==3 and ga[i]==3){// LEY DE SENOS
								angulo[1]= asin(double ((lado[3]*(sin(double (angulo[3]*(PI/180)))))/lado[2]));angulo[1]=angulo[1]*180/PI;
								angulo[2]=180-angulo[3]-angulo[1];
								lado[1]=lado[2]*(sin(double (angulo[2]*(PI/180))))/(sin(double (angulo[3]*(PI/180))));
							}
						}	
					}
					if(cl==1 and ca==2){cout<<"\t\td) Dos angulos y un lado"<<endl;
						for(int i=1;i<=3;i++){	
							if(gl[i]==1 and ga[i]==1 and ga[i+1]==2){// LEY DE COSENOS Y LEY DE SENOS
								angulo[3]=180-angulo[1]-angulo[2];
								lado[3]= lado[1] * (sin(double (angulo[1]*(PI/180))))/(sin(double (angulo[2]*(PI/180))));
								lado[2]= sqrt(pow((lado[1]),2)+(pow((lado[3]),2))-(2*lado[1]*lado[3]*(cos(double (angulo[3]*(PI/180))))));
							}
							if(gl[i]==1 and ga[i]==1 and ga[i+1]==3){// LEY DE COSENOS Y LEY DE SENOS
								angulo[2]=180-angulo[1]-angulo[3];
								lado[3]= lado[1] * (sin(double (angulo[1]*(PI/180))))/(sin(double (angulo[2]*(PI/180))));
								lado[2]= sqrt(pow((lado[1]),2)+(pow((lado[3]),2))-(2*lado[1]*lado[3]*(cos(double (angulo[3]*(PI/180))))));
							}
							if(gl[i]==1 and ga[i]==2 and ga[i+1]==3){// LEY DE COSENOS Y LEY DE SENOS
								angulo[1]=180-angulo[2]-angulo[3];
								lado[3]= lado[1] * (sin(double (angulo[1]*(PI/180))))/(sin(double (angulo[2]*(PI/180))));
								lado[2]= sqrt(pow((lado[1]),2)+(pow((lado[3]),2))-(2*lado[1]*lado[3]*(cos(double (angulo[3]*(PI/180))))));
							}
							if(gl[i]==2 and ga[i]==1 and ga[i+1]==2){// LEY DE SENOS
								angulo[3]=180-angulo[1]-angulo[2];
								lado[3]= lado[2] * (sin(double (angulo[1]*(PI/180))))/(sin(double (angulo[3]*(PI/180))));
								lado[1]= lado[3] * (sin(double (angulo[2]*(PI/180))))/(sin(double (angulo[1]*(PI/180))));
							}
							if(gl[i]==2 and ga[i]==1 and ga[i+1]==3){// LEY DE COSENOS Y LEY DE SENOS
								angulo[2]=180-angulo[1]-angulo[3];
								lado[3]= lado[2] * (sin(double (angulo[1]*(PI/180))))/(sin(double (angulo[3]*(PI/180))));
								lado[2]= sqrt(pow((lado[2]),2)+(pow((lado[3]),2))-(2*lado[2]*lado[3]*(cos(double (angulo[2]*(PI/180))))));
							}
							if(gl[i]==2 and ga[i]==2 and ga[i+1]==3){// LEY DE SENOS
								angulo[1]=180-angulo[2]-angulo[3];
								lado[3]= lado[2] * (sin(double (angulo[1]*(PI/180))))/(sin(double (angulo[3]*(PI/180))));
								lado[1]= lado[2] * (sin(double (angulo[2]*(PI/180))))/(sin(double (angulo[3]*(PI/180))));
							}
							if(gl[i]==3 and ga[i]==1 and ga[i+1]==2){// LEY DE COSENOS Y LEY DE SENOS
								angulo[3]=180-angulo[1]-angulo[2];
								lado[1]= lado[3] * (sin(double (angulo[2]*(PI/180))))/(sin(double (angulo[1]*(PI/180))));
								lado[2]= sqrt(pow((lado[1]),2)+(pow((lado[3]),2))-(2*lado[1]*lado[3]*(cos(double (angulo[3]*(PI/180))))));
							}
							if(gl[i]==3 and ga[i]==1 and ga[i+1]==3){// LEY DE COSENOS Y LEY DE SENOS
								angulo[2]=180-angulo[1]-angulo[3];
								lado[1]= lado[3] * (sin(double (angulo[2]*(PI/180))))/(sin(double (angulo[1]*(PI/180))));
								lado[2]= sqrt(pow((lado[1]),2)+(pow((lado[3]),2))-(2*lado[1]*lado[3]*(cos(double (angulo[3]*(PI/180))))));
							}
							if(gl[i]==3 and ga[i]==2 and ga[i+1]==3){// LEY DE COSENOS Y LEY DE SENOS
								angulo[1]=180-angulo[2]-angulo[3];
								lado[1]= lado[3] * (sin(double (angulo[2]*(PI/180))))/(sin(double (angulo[1]*(PI/180))));
								lado[2]= sqrt(pow((lado[1]),2)+(pow((lado[3]),2))-(2*lado[1]*lado[3]*(cos(double (angulo[3]*(PI/180))))));
							}
						}
					}
					if((cl+ca)>3){cout<<"Ingreso mas datos de los requeridos"<<endl;
					}
					area=0.5*lado[2]*lado[3]*((sin(double (angulo[2]*(PI/180)))));
					// MEDIANAS
					mediana[1]=0.5*sqrt(2*((pow((lado[1]),2))+(pow((lado[2]),2)))-(pow((lado[3]),2)));
					mediana[2]=0.5*sqrt(2*((pow((lado[2]),2))+(pow((lado[3]),2)))-(pow((lado[1]),2)));
					mediana[3]=0.5*sqrt(2*((pow((lado[1]),2))+(pow((lado[3]),2)))-(pow((lado[2]),2)));
					cout<<"\t\tPOR TANTO TENEMOS :"<<endl<<endl;
					for(int i=1;i<=3;i++){
						cout<<"\t--> LADO < "<<i<<" > = "<<lado[i]<<"[u]\t\t\t\tANGULO Alfa "<<i<<"* = "<<angulo[i]<<" grados"<<endl;
					}cout<<"\n";cout<<"\n";
					
					cout<<"\t--> MEDIANA A1-L3 = "<<mediana[1]<<" [u]"<<endl;
					cout<<"\t--> MEDIANA A2-L1 = "<<mediana[2]<<" [u]"<<endl;
					cout<<"\t--> MEDIANA A3-L2 = "<<mediana[3]<<" [u]"<<endl<<endl;
					cout<<"\t--> AREA = "<<area<<" [u^2]"<<endl;
					cout<<"---------------------------------------------------------------------------------------------"<<endl;
				break;
			}
			case 2:{cout<<"Hasta luego..."<<endl;
				break;
			}
		default:	cout<<"Error de entrada"<<endl;
		}
		cout<<"\nDESEA REALIZAR OTRA OPERACION (S/N) "<<endl;
		cin>>op2;
	}while(op2=='s' or op2=='S');
	cout<<"\nGRACIAS..."<<endl;
	return 0;
}	
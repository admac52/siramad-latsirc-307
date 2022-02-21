//3. Ecuacion de tercer grado

#include<iostream>
#include<conio.h>
#include<math.h>
#define PI 3.14159265359
#define MAR 0.0000000009
using namespace std;

int main(){
	double a,b,c,d;
	double a1,b1,c1;
	double p,q,disc;
	double x,y,z;
	double ab,ac;
	double u,v;
	
	cout<<"\nSI SE TIENE :"<<endl;
	cout<<"\t\tax^3 + bx^2 + cx + d"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Escriba el coeficiente de < a > x al cubo:"<<endl;
	cin>>a;
	cout<<"Escriba el coeficiente de < b > x al cuadrado:"<<endl;
	cin>>b;
	cout<<"Escriba el coeficiente de < c > x:"<<endl;
	cin>>c;
	cout<<"Escriba la constante < d >:"<<endl;
	cin>>d;
	cout.precision(3);
	a1=b/a;
	b1=c/a;
	c1=d/a;
	p=b1-((a1*a1)/3);
	q=((2*a1*a1*a1)/27) - ((a1*b1)/3) + c1;
	disc=(q*q) + ((4*p*p*p)/27);

	// CASO 1 - disc>0
	if(disc>=MAR){
		ab=0.5*(-q + sqrt(disc));
		double racub(ab);              //*
		if(ab>0){
			racub=exp(log(ab)/3);
    	}
    	if(ab==0){
			racub=0;
		}
		if(ab<0){
			racub=-exp(log(-ab)/3);
		}
		ac=(-0.5)*(q + sqrt(disc));
		double racub2(ac);             //*
		if(ac>0){
			racub2=exp(log(ac)/3);  
		}
		if(ac==0){
			racub2=0;
		};
		if(ac<0){
			racub2=-exp(log(-ac)/3);
		}
		u=racub;
		v=racub2;
		x=u+v-(a1/3);
		y=((-0.5)*(u+v)) - (a1/3);
		z=(0.5)*(sqrt(3))*(u-v);
		cout<<"\nPor tanto, las tres soluciones de la ecuacion son: "<<endl<<endl;
		cout<<"\t\tx1 = "<<x<<endl;
		cout<<"\t\tx2 = "<<y<<" + "<<z<<"i"<<endl;
		cout<<"\t\tx3 = "<<y<<" - "<<z<<"i"<<endl;
    }
 
	// CASO 2 - disc=0
	if(((disc<MAR) and (disc>-MAR)) and ((p>=-MAR) and (p<=MAR))){
		cout<<"\nPor tanto, las soluciones unica solucion de la ecuacion es:"<<endl<<endl;
		cout<<"\t\tx = "<<-(a1/3);
	}
 
	if(((disc<MAR) and (disc>-MAR)) and ((p>=MAR) or (p<=-MAR))){
		ab=(-0.5)*q;
		double racub(ab);
		if(ab>0){
			racub=exp(log(ab)/3);
		}
		if(ab==0){
			racub=0;
		}
		if(ab<0){
			racub=-exp(log(-ab)/3);
		}
		u=racub;
		x=(2*u)-(a1/3);
		y=-u-(a1/3);
		cout<<"\nPor tanto, la ecuacion tiene raices multiples y son:"<<endl<<endl;
		cout<<"\t\tx1 = "<<x<<endl;
		cout<<"\t\tx2 = x3 = "<<y<<endl;
	}
 
	// CASO 3 - disc<0
	if(disc<=-MAR){
		x=((2*sqrt(-p/3))*(cos(acos((-q/2)*sqrt(-27/(p*p*p)))/3))) - (a1/3);
		y=((2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +2*PI/3)) - (a1/3);
		z=((2*sqrt(-p/3))*cos(acos((-q/2)*sqrt((-27)/(p*p*p)))/3 +4*PI/3)) - (a1/3);
		cout<<"\nPor tanto, la ecuacion tiene 3 raices distintas y son:"<<endl<<endl;
		cout<<"\t\tx1 = "<<x<<endl;
		cout<<"\t\tx2 = "<<y<<endl;
		cout<<"\t\tx3 = "<<z<<endl;
	}
	
	return 0;
}


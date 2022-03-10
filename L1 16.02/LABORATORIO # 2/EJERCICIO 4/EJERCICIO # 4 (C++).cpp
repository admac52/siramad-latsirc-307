//4. Resolver un sistema de 2 ecuaciones y 2 incógnitas

#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main(){
	float a1,b1,c1,a2,b2,c2;
	float delta=0,dx=0,dy=0;
	float x=0,y=0;
	char op;
	
	do{
		cout<<"\nSI SE TIENE DOS ECUACIONES DE LA FORMA :"<<endl;
		cout<<"\t\tax + by = c"<<endl;
		cout<<"------------------------------------------"<<endl;
		cout<<"\tPRIMERA ECUACION"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"Escriba el coeficiente de < a > x:"<<endl;
		cin>>a1;
		cout<<"Escriba el coeficiente de < b > y:"<<endl;
		cin>>b1;
		cout<<"Escriba la constante < c >:"<<endl;
		cin>>c1;
		cout<<"------------------------------------------"<<endl;
		cout<<"\tSEGUNDA ECUACION"<<endl;
		cout<<"--------------------------------"<<endl;
		cout<<"Escriba el coeficiente de < a > x:"<<endl;
		cin>>a2;
		cout<<"Escriba el coeficiente de < b > y:"<<endl;
		cin>>b2;
		cout<<"Escriba la constante < c >:"<<endl;
		cin>>c2;
		
		// USO DEL METODO DETERMINANTE
		delta=((a1*b2)-(a2*b1));
		dx=((c1*b2)-(c2*b1));
		dy=((a1*c2)-(a2*c1));
		if(delta!=0){
			x=dx/delta;
			y=dy/delta;
			cout<<"\nPor tanto, las soluciones del sistema son:"<<endl<<endl;
			cout<<"\t\tx = "<<x<<endl;
			cout<<"\t\ty = "<<y<<endl;
		}
		if(delta==0){
			cout<<"\n\tNo es posible resolver ya que presenta una division entre cero"<<endl;
		}
		cout<<"\nDESEA REALIZAR OTRA OPERACION (S/N) "<<endl;
		cin>>op;
	}while(op=='s' or op=='S');
	cout<<"\nGRACIAS..."<<endl;
	
	
	return 0;
}


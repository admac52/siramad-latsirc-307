//2. Ecuacion de segundo grado

#include<iostream>
#include<math.h>
using namespace std;
int main(){
	float a,b,c,disc=0,raiz=0,conv=0,x1=0,x2=0;
	float real1=0,real2=0,im1=0,im2=0;
	
	cout<<"\nSI SE TIENE :"<<endl;
	cout<<"\t\tax^2 + bx + c"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Escriba el coeficiente de <a> x al cuadrado:"<<endl;
	cin>>a;
	cout<<"Escriba el coeficiente de <b> x:"<<endl;
	cin>>b;
	cout<<"Escriba la constante <c>:"<<endl;
	cin>>c;
	disc=(b*b)-(4*a*c);
	if(disc>=0){
		raiz=sqrtf(disc);
		x1=((-b)+raiz)/(2*a);
		x2=((-b)-raiz)/(2*a);
		cout<<"Por tanto, las soluciones de la ecuacion son:"<<endl<<endl;
		cout<<"\t\tx1 = "<<x1<<endl;
		cout<<"\t\tx2 = "<<x2<<endl;
	}
	if(disc<0){
		conv=(-1)*disc;
		raiz=sqrtf(conv);
		real1=(-b)/(2*a);
		im1=(raiz)/(2*a);
		real2=(-b)/(2*a);
		im2=(-raiz)/(2*a);
		cout<<"Por tanto, las soluciones de la ecuacion son:"<<endl<<endl;
		if(im1>=0){
			cout<<"\t\tx1 = "<<real1<<"+"<<im1<<"i"<<endl;
		}else{
			cout<<"\t\tx1 = "<<real1<<im1<<"i"<<endl;
		}
		if(im2>=0){
			cout<<"\t\tx2 = "<<real2<<"+"<<im2<<"i"<<endl;
		}else{
			cout<<"\t\tx2 = "<<real2<<im2<<"i"<<endl;
		}
	}
	
	return 0;
}


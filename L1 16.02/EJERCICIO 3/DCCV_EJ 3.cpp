//3. Ecuacion de tercer grado

#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main(){
	float a,b,c,d,x1=0,x2=0,x3=0;
	
	cout<<"\nSI SE TIENE :"<<endl;
	cout<<"\t\tax^3 + bx^2 + cx + d"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Escriba el coeficiente de <a> x al cubo:"<<endl;
	cin>>a;
	cout<<"Escriba el coeficiente de <b> x al cuadrado:"<<endl;
	cin>>b;
	cout<<"Escriba el coeficiente de <c> x:"<<endl;
	cin>>c;
	cout<<"Escriba la constante <d>:"<<endl;
	cin>>d;
	x1=(-b/(3*a))-(((2^(1/3))*(-(b*b)+3*a*c))/(3*a*(pow((-2*(b*b*b)+(9*a*b*c)-27*(a*a)*d+(sqrt(4*((-(b*b)+3*a*c)*(-(b*b)+3*a*c)*(-(b*b)+3*a*c))+((-2*(b*b*b)+9*a*b*c-27*(a*a)*d)*(-2*(b*b*b)+9*a*b*c-27*(a*a)*d))))),(1/3))))+((pow((-2*(b*b*b)+9*a*b*c-27*(a*a)*d+(sqrtf((4*((-(b*b)+3*a*c)*(-(b*b)+3*a*c)*(-(b*b)+3*a*c)))+((-2*(b*b*b)+9*a*b*c-27*(a*a)*d)*(-2*(b*b*b)+9*a*b*c-27*(a*a)*d))))),(1/3)))/(3*(2^(1/3))*a));
	cout<<"x1 = "<<x1<<endl;
	
	return 0;
}


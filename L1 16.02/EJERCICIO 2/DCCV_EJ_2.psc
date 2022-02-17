Proceso DCCV_EJ_2
	// 2. Ecuacion de segundo grado
	// <  >
	Definir a,b,c,disc,raz,conv,x1,x2 Como Real;
	Definir real1,real2,im1,im2 Como Real;
	Escribir 'SI SE TIENE :';
	Escribir '              ax^2 + bx + c';
	Escribir 'Escriba el coeficiente de <a> x al cuadrado:';
	Leer a;
	Escribir 'Escriba el coeficiente de <b> x:';
	Leer b;
	Escribir 'Escriba la constante <c>:';
	Leer c;
	disc <- (b*b)-(4*a*c);
	Escribir ' ';
	Si disc>=0 Entonces
		raz <- rc((b*b)-(4*a*c));
		x1 <- ((-b)+raz)/(2*a);
		x2 <- ((-b)-raz)/(2*a);
		Escribir 'Por tanto, las soluciones de la ecuacion son:';
		Escribir ' ';
		Escribir '             x1 = ',x1;
		Escribir '             x2 = ',x2;
	FinSi
	Si disc<0 Entonces
		conv <- (-1)*disc;
		raz <- rc(conv);
		real1 <- (-b)/(2*a);
		real2 <- (-b)/(2*a);
		im1 <- (raz)/(2*a);
		im2 <- (-raz)/(2*a);
		Escribir 'Por tanto, las soluciones de la ecuacion son:';
		Escribir ' ';
		Si im1>=0 Entonces
			Escribir '         x1 = ',real1,'+',im1,'i';
		SiNo
			Escribir '         x1 = ',real1,im1,'i';
		FinSi
		Si im2>=0 Entonces
			Escribir '         x2 = ',real2,'+',im2,'i';
		SiNo
			Escribir '         x2 = ',real2,im2,'i';
		FinSi
	FinSi
FinProceso

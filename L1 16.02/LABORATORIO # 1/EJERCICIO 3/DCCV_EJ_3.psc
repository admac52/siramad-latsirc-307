Proceso DCCV_EJ_3
	// 3. Ecuacion de terer grado
	// deb_precision de decimales
	Definir a,b,c,d,a1,b1,c1,disc,p,q Como Real;
	Definir x,ye,z,ab,ac,eu,VPI,MAR Como Real;
	Definir racub1,racub2 Como Real;
	eu <- 2.718281828;
	VPI <- 3.14159265359;
	MAR <- 0.0000000009;
	Escribir 'SI SE TIENE :';
	Escribir '              ax^3 + bx^2 + cx + d';
	Escribir 'Escriba el coeficiente de < a > x al cubo:';
	Leer a;
	Escribir 'Escriba el coeficiente de < b > x al cuadrado:';
	Leer b;
	Escribir 'Escriba el coeficiente de < c > x:';
	Leer c;
	Escribir 'Escriba la constante < d >:';
	Leer d;
	a1 <- b/a;
	b1 <- c/a;
	c1 <- b/a;
	p <- b1-((a1*a1)/3);
	q <- ((2*a1*a1*a1)/27)-((a1*b1)/3)+c1;
	disc <- (q*q)+((4*p*p*p)/27);
	// CASO 1 - disc>0
	Si disc>=MAR Entonces
		ab <- 0.5*(-q+(rc(disc)));
		Si ab>0 Entonces
			racub1 <- eu^(((ln(ab))/(ln(10)))/3);
		FinSi
		Si ab=0 Entonces
			racub1 <- 0;
		FinSi
		Si ab<0 Entonces
			racub1 <- -eu^(((ln(-ab))/(ln(10)))/3);
		FinSi
		ac <- (-0.5)*(q+(rc(disc)));
		Si ac>0 Entonces
			racub2 <- eu^(((ln(ac))/(ln(10)))/3);
		FinSi
		Si ac=0 Entonces
			racub2 <- 0;
		FinSi
		Si ac<0 Entonces
			racub2 <- -eu^(((ln(-ac))/(ln(10)))/3);
		FinSi
		x <- racub1+racub2-(a1/3);
		ye <- ((-0.5)*(racub1+racub2))-(a1/3);
		z <- (0.5)*(rc(3))*(racub1-racub2);
		Escribir 'Por tanto, las tres soluciones de la ecuacion son:';
		Escribir ' ';
		Escribir '             x1 = ',x;
		Escribir '             x2 = ',ye,'+',z,'i';
		Escribir '             x3 = ',ye,'-',z,'i';
	FinSi
	// CASO 2 - disc=0
	Si (((disc<MAR) Y (disc>-MAR)) Y ((p>=-MAR) Y (p<=MAR))) Entonces
		x <- -(a1/3);
		Escribir 'Por tanto, las soluciones unica solucion de la ecuacion es:';
		Escribir ' ';
		Escribir '             x = ',x;
	FinSi
	Si (((disc<MAR) Y (disc>-MAR)) Y ((p>=MAR) O (p<=-MAR))) Entonces
		ab <- (-0.5)*q;
		Si ab>0 Entonces
			racub1 <- eu^(((ln(ab))/(ln(10)))/3);
		FinSi
		Si ab=0 Entonces
			racub1 <- 0;
		FinSi
		Si ab<0 Entonces
			racub1 <- -eu^(((ln(-ab))/(ln(10)))/3);
		FinSi
		x <- (2*racub1)-(a1/3);
		ye <- ((-1)*(racub1))-(a1/3);
		z <- (0.5)*(rc(3))*(racub1-racub2);
		Escribir 'Por tanto, la ecuacion tiene raices multiples y son:';
		Escribir ' ';
		Escribir '             x1 = ',x;
		Escribir '             x2 = x3 = ',ye;
	FinSi
	// CASO 3 - disc<0
	Si disc<=-MAR Entonces
		x <- ((2*rc(-p/3))*(cos(acos((-q/2)*rc(-27/(p*p*p)))/3)))-(a1/3);
		ye <- ((2*rc(-p/3))*cos(acos((-q/2)*rc((-27)/(p*p*p)))/3+2*PI/3))-(a1/3);
		z <- ((2*rc(-p/3))*cos(acos((-q/2)*rc((-27)/(p*p*p)))/3+4*PI/3))-(a1/3);
		Escribir 'Por tanto, la ecuacion tiene 3 raices distintas y son:';
		Escribir ' ';
		Escribir '             x1 = ',x;
		Escribir '             x2 = ',ye;
		Escribir '             x3 = ',z;
	FinSi
FinProceso

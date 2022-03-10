Proceso DCCV_EJ_4
	// 4. Resolver un sistema de 2 ecuaciones y 2 incógnitas
	// <  >
	Definir a1,b1,c1,a2,b2,c2 Como Real;
	Definir delta,dx,dy,x,ye Como Real;
	Definir op Como Caracter;
	Repetir
		Escribir 'SI SE TIENE DOS ECUACIONES DE LA FORMA :';
		Escribir '              ax + by = c';
		Escribir '-------------------------------------------';
		Escribir 'PRIMERA ECUACION :';
		Escribir '------------------';
		Escribir 'Escriba el coeficiente de < a > x :';
		Leer a1;
		Escribir 'Escriba el coeficiente de < b > y :';
		Leer b1;
		Escribir 'Escriba la constante < c >:';
		Leer c1;
		Escribir '-------------------------------------------';
		Escribir 'SEGUNDA ECUACION :';
		Escribir '------------------';
		Escribir 'Escriba el coeficiente de < a > x :';
		Leer a2;
		Escribir 'Escriba el coeficiente de < b > y :';
		Leer b2;
		Escribir 'Escriba la constante < c >:';
		Leer c2;
		// METDODO DETERMINANTES
		delta <- (a1*b2)-(a2*b1);
		dx <- (c1*b2)-(c2*b1);
		dy <- (a1*c2)-(a2*c1);
		Si delta<>0 Entonces
			x <- dx/delta;
			ye <- dy/delta;
			Escribir ' ';
			Escribir 'Por tanto, las soluciones del sistema son :';
			Escribir ' ';
			Escribir '             x = ',x;
			Escribir '             y = ',ye;
		SiNo
			Escribir 'No es posible resolver ya que presenta una division entre cero';
		FinSi
		Escribir 'DESEA REALIZAR OTRA OPERACION';
		Escribir 'Pulse N para salir de lo contrario pulse cualquiera';
		Leer op;
	Hasta Que op='n' O op='N'
FinProceso

Proceso DCCV_EJ_2
	// 2. Generar matrices enésimas de Vandermonde y calcular el determinante
	Definir i,j,op,n,f,c Como Entero;
	Definir Vector,Matriz,det Como Real;
	Dimension Vector[100];
	Dimension Matriz[100,100];
	det <- 1;
	Escribir '   ******** MATRICES DE VANDERMONDE *********';
	Escribir '   ------------------------------------------';
	Escribir '        1.- EN FILAS';
	Escribir '        2.- EN COLUMNAS';
	Escribir '        3.- SALIR';
	Escribir 'INGRESE SU ELECCION: ';
	Leer op;
	Escribir '-----------------------------';
	Repetir
		Escribir 'INGRESE UN VALOR < n > PARA EL TAMANO DE LA MATRIZ: ';
		Leer n;
	Hasta Que n>0 O n<100
	Segun op  Hacer
		1:
			Escribir 'INGRESE UN VALOR BASE POR FILA';
			// TOMA DE DATOS
			Para i<-0 Hasta n-1 Hacer
				Escribir 'M[',i+1,',2] = ';
				Leer Vector[i];
			FinPara
			// OPERACIONES
			Para i<-0 Hasta n-1 Hacer
				Para j<-0 Hasta n-1 Hacer
					Matriz[i,j]<-Vector[i]^j;
				FinPara
			FinPara
			// MOSTRAR
			Escribir 'LA MATRIZ DE VANDERMONDE ES :';
			Escribir '-----------------------------';
			Para i<-0 Hasta n-1 Hacer
				Para j<-0 Hasta n-1 Hacer
					Escribir Matriz[i,j],' ' Sin Saltar;
				FinPara
				Escribir ' ';
			FinPara
			// DETERMINANTE
			Para i<-0 Hasta n-2 Hacer
				Para j<-i+1 Hasta n-1 Hacer
					det <- det*(Vector[j]-Vector[i]);
				FinPara
			FinPara
			Escribir ' Y SU DETERMINANTE ES :',det;
			Escribir ' ';
		2:
			Escribir 'INGRESE UN VALOR BASE POR COLUMNA';
			// TOMA DE DATOS
			Para i<-0 Hasta n-1 Hacer
				Escribir 'M[2,',i+1,'] = ';
				Leer Vector[i];
			FinPara
			// OPERACIONES
			Para i<-0 Hasta n-1 Hacer
				Para j<-0 Hasta n-1 Hacer
					Matriz[i,j]<-Vector[i]^j;
				FinPara
			FinPara
			// MOSTRAR
			Escribir 'LA MATRIZ DE VANDERMONDE ES :';
			Escribir '-----------------------------';
			Para i<-0 Hasta n-1 Hacer
				Para j<-0 Hasta n-1 Hacer
					Escribir Matriz[j,i],' ' Sin Saltar;
				FinPara
				Escribir ' ';
			FinPara
			// DETERMINANTE
			Para i<-0 Hasta n-2 Hacer
				Para j<-i+1 Hasta n-1 Hacer
					det <- det*(Vector[j]-Vector[i]);
				FinPara
			FinPara
			Escribir ' Y SU DETERMINANTE ES :',det;
			Escribir ' ';
		3:
			Escribir 'HASTA LUEGO...';
		De Otro Modo:
			Escribir 'ERROR';
			Escribir ' ';
	FinSegun
FinProceso

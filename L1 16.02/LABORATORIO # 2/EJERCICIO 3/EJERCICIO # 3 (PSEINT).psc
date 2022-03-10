Proceso DCCV_EJ_3
	// 3. Realizar la division de polinomios con el método Horner
	Definir i,j,k,n1,n2,m1,m2,m3,m4,grado,resto Como Entero;
	Definir VectorA,VectorB,Cociente,MH Como Real;
	Definir op Como Caracter;
	Dimension VectorA[100],VectorB[100],Cociente[100];
	Dimension MH[100,100];
	Repetir
		Escribir '   ********** METODO HORNER ***********';
		Escribir '   ------------------------------------';
		Escribir ' DADO UN POLINOMIO: ';
		Escribir '   Px(n) = ax^n + bx^n-1 + cx^n-2 + ... + dx + e';
		Escribir '   ------------------------------------';
		Escribir '    NUMERADOR';
		Escribir '-----------------';
		Escribir 'Escriba el grado < n > del polinomio :';
		Leer n1;
		Escribir ' ';
		Escribir 'Ingrese los coeficientes en grado descendente con su signo correspondiente :';
		Para i<-0 Hasta n1 Hacer
			m1 <- n1-i;
			Escribir '--> Px1(',m1,') = ';
			Leer VectorA[n1-i];
		FinPara
		Escribir '-----------------';
		Escribir '   DENOMINADOR';
		Escribir '-----------------';
		Escribir 'Escriba el grado < n > del polinomio :';
		Leer n2;
		Escribir ' ';
		Escribir 'Ingrese los coeficientes en grado descendente con su signo correspondiente :';
		Para i<-0 Hasta n2 Hacer
			m2 <- n2-i;
			Escribir '--> Px1(',m2,') = ';
			Leer VectorB[n2-i];
		FinPara
		Escribir ' ';
		Escribir 'TENEMOS :';
		Para i<-0 Hasta n1 Hacer
			m1 <- n1-i;
			Si m1<>0 Entonces
				Escribir VectorA[n1-i],'x^',m1,' + ' Sin Saltar;
			FinSi
			Si m1=0 Entonces
				Escribir VectorA[n1-i],'x^',m1;
			FinSi
		FinPara
		Escribir '-----------------------------------------------';
		Para i<-0 Hasta n2 Hacer
			m2 <- n2-i;
			Si m2<>0 Entonces
				Escribir VectorB[n2-i],'x^',m2,' + ' Sin Saltar;
			FinSi
			Si m2=0 Entonces
				Escribir VectorB[n2-i],'x^',m2;
			FinSi
		FinPara
		Escribir ' ';
		// RELLENADO
		Para i<-0 Hasta 0 Hacer
			Para j<-0 Hasta n1+1 Hacer
				MH[i,n1-j+1]<-VectorA[j];
			FinPara
		FinPara
		Para j<-0 Hasta 0 Hacer
			Para i<-0 Hasta n2 Hacer
				Si i=n2 Entonces
					MH[n2-i,j]<-VectorB[i];
				SiNo
					MH[n2-i,j]<-(-1)*VectorB[i];
					VectorB[i] <- MH[n2-i,j];
				FinSi
			FinPara
		FinPara
		resto <- n1-n2+1;
		// ****** APLICACION DE HORNER ******
		// DIVISION
		Para i<-0 Hasta n2 Hacer
			Cociente[i+1]<-MH[0,i+1]/MH[i,i];
		FinPara
		Para k<-0 Hasta n1+1 Hacer
			// MULTIPLICACION
			Para i<-k+1 Hasta k+1 Hacer
				Para j<-k+1 Hasta n2+k Hacer
					Si i=resto+1 Entonces
						Escribir ' ' Sin Saltar;
					FinSi
					MH[i,j+1]<-Cociente[i]*VectorB[n2-j+k];
				FinPara
			FinPara
			// SUMATORIA 
			Para j<-k+2 Hasta k+2 Hacer
				Para i<-0 Hasta resto+1 Hacer
					Si j>=resto+1 Entonces
						Cociente[j] <- Cociente[j]+MH[i,j];
					SiNo
						Cociente[j] <- Cociente[j]+MH[i,j];
						Si i=resto+1 Entonces
							Cociente[j] <- Cociente[j]/MH[0,0];
						FinSi
					FinSi
				FinPara
			FinPara
		FinPara
		// MOSTRAR LO REALIZADO
		Escribir ' ';
		Escribir '*************** PROCEDIMIENTO ***************';
		Escribir ' ';
		Escribir ' ';
		Escribir '    ';
		Para i<-0 Hasta resto+1 Hacer
			Para j<-0 Hasta n1+1 Hacer
				Escribir MH[i,j],'    ';
			FinPara
			Escribir ' ';
		FinPara
		Escribir ' ';
		Escribir ' ------------------------------------------';
		Para i<-1 Hasta n1+1 Hacer
			Escribir Cociente[i],'    ';
		FinPara
		Escribir ' ';
		grado <- n1-n2;
		Escribir ' ';
		Escribir ' LA DIVISION ENTRE LOS POLINOMIOS ES : ';
		Escribir ' --> ';
		Para i<-0 Hasta grado Hacer
			m3 <- grado-i;
			Si m3<>0 Entonces
				Escribir Cociente[i+1],'x^',m3,' + ';
			FinSi
			Si m3=0 Entonces
				Escribir Cociente[i+1],'x^',m3;
			FinSi
		FinPara
		Escribir ' ';
		Escribir ' Y TIENE DE RESTO : ';
		Escribir ' --> ';
		Para i<-grado+1 Hasta n1+1 Hacer
			m4 <- n1-i;
			Si m4<>0 Entonces
				Escribir Cociente[i+1],'x^',m4,' + ';
			FinSi
			Si m4=0 Entonces
				Escribir Cociente[i+1],'x^',m4;
			FinSi
		FinPara
		Escribir ' ';
		Escribir ' ';
		Escribir 'DESEA REALIZAR OTRA OPERACION';
		Escribir 'Pulse N para salir de lo contrario pulse cualquiera';
		Leer op;
	Hasta Que op='n' O op='N'
FinProceso

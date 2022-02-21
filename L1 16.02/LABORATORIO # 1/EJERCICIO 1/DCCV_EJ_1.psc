Proceso DCCV_EJ_1
	// 1. Series de Mclaurin y Taylor
	Definir i,j,x,n,op,punto,d Como Entero;
	Definir S,f,p,a,b,c,mult Como Real;
	Definir eu,vpi,rad,seno,coseno Como Real;
	eu <- 2.718281828;
	vpi <- 3.14159265359;
	Definir VectorA,VectorB Como Real;
	Dimension VectorA[100],VectorB[100];
	Repetir
		Escribir '********* SERIES DE TAYLOR Y MACLAURIN *********';
		Escribir '------------------------------------------------';
		Escribir '1.- e^x';
		Escribir '2.- Sen x';
		Escribir '3.- Cos x';
		Escribir '4.- SALIR';
		Escribir 'INGRESE SU ELECCION:';
		Leer op;
		Escribir '--------------------------------------';
		Segun op  Hacer
			1:
				VectorA[0] <- 1; S <- 0;
				Repetir
					Escribir 'INGRESE UN VALOR PARA x : ';
					Leer x;
				Hasta Que x>=0
				Repetir
					Escribir 'INGRESE EL VALOR LIMITE n DE LA SERIE : ';
					Leer n;
				Hasta Que n>=0 Y n<=100
				Escribir 'ALREDEDOR DEL PUNTO : ';
				Leer punto;
				// POTENCIA
				Para i<-0 Hasta n Hacer
					p <- x^i;
					VectorB[i] <- p;
				FinPara
				// FACTORIAL
				Para i<-1 Hasta n Hacer
					f <- 1;
					Para j<-1 Hasta i Hacer
						f <- f*j;
					FinPara
					VectorA[i] <- f;
				FinPara
				// SUMATORIA
				Para i<-0 Hasta n Hacer
					S <- S+((VectorB[i])/(VectorA[i]));
				FinPara
				Escribir ' ';
				Escribir 'LA SERIE DE MCLAURIN DE LA FUNCION EXPONENCIAL VALE : ',S;
				S <- 0; f <- 1; p <- 0;
				// NUMERADOR
				Para i<-0 Hasta n Hacer
					p <- eu^punto;
					mult <- p*((x-punto)^i);
					VectorB[i] <- mult;
				FinPara
				// FACTORIAL
				Para i<-1 Hasta n Hacer
					f <- 1;
					Para j<-1 Hasta i Hacer
						f <- f*j;
					FinPara
					VectorA[i] <- f;
				FinPara
				// SUMATORIA
				Para i<-0 Hasta n Hacer
					S <- S+((VectorB[i])/(VectorA[i]));
				FinPara
				Escribir ' ';
				Escribir 'LA SERIE DE TAYLOR DE LA FUNCION EXPONENCIAL EN EL PUNTO ',punto,' VALE : ',S;
			2:
				f <- 1; a <- 0; b <- 0; S <- 0;
				Repetir
					Escribir 'INGRESE UN VALOR PARA x : ';
					Leer x;
				Hasta Que x>=0
				Repetir
					Escribir 'INGRESE EL VALOR LIMITE n DE LA SERIE : ';
					Leer n;
				Hasta Que n>=0 Y n<=100
				Escribir 'ALREDEDOR DEL PUNTO (EN GRADOS) : ';
				Leer punto;
				Para i<-0 Hasta n Hacer
					a <- (2*i)+1;
					p <- x^a;
					VectorB[i] <- p;
				FinPara
				// FACTORIAL
				Para i<-0 Hasta n Hacer
					f <- 1;
					b <- (2*i)+1;
					Para j<-1 Hasta b Hacer
						f <- f*j;
					FinPara
					VectorA[i] <- f;
				FinPara
				// SUMATORIA
				Para i<-0 Hasta n Hacer
					c <- (-1)^i;
					S <- S+((VectorB[i])*c/(VectorA[i]));
				FinPara
				Escribir ' ';
				Escribir 'LA SERIE DE MCLAURIN DE LA FUNCION sen x VALE : ',S;
				S <- 0; f <- 1; mult <- 0; a <- -4; b <- -3; c <- -2; d <- -1;
				rad <- punto*vpi/180;
				// NUMERADOR
				Para i<-0 Hasta n Hacer
					Si i=a+4 Entonces
						seno <- sen(rad);
						mult <- seno*((x-rad)^i);
						VectorB[i] <- mult;
						a <- a+4;
					FinSi
					Si i=b+4 Entonces
						coseno <- cos(rad);
						mult <- coseno*((x-rad)^i);
						VectorB[i] <- mult;
						b <- b+4;
					FinSi
					Si i=c+4 Entonces
						seno <- sen(rad);
						mult <- (-1)*seno*((x-rad)^i);
						VectorB[i] <- mult;
						c <- c+4;
					FinSi
					Si i=d+4 Entonces
						coseno <- cos(rad);
						mult <- (-1)*coseno*((x-rad)^i);
						VectorB[i] <- mult;
						d <- d+4;
					FinSi
				FinPara
				// FACTORIAL
				Para i<-1 Hasta n Hacer
					f <- 1;
					Para j<-1 Hasta i Hacer
						f <- f*j;
					FinPara
					VectorA[i] <- f;
				FinPara
				// SUMATORIA
				Para i<-0 Hasta n Hacer
					S <- S+((VectorB[i])/(VectorA[i]));
				FinPara
				Escribir ' ';
				Escribir 'LA SERIE DE TAYLOR DE LA FUNCION sen x EN EL PUNTO ',punto,'° VALE : ',S;
			3:
				f <- 1; a <- 0; b <- 0; S <- 0;
				Repetir
					Escribir 'INGRESE UN VALOR PARA x : ';
					Leer x;
				Hasta Que x>=0
				Repetir
					Escribir 'INGRESE EL VALOR LIMITE n DE LA SERIE : ';
					Leer n;
				Hasta Que n>=0 Y n<=100
				Escribir 'ALREDEDOR DEL PUNTO (EN GRADOS) : ';
				Leer punto;
				Para i<-0 Hasta n Hacer
					a <- (2*i);
					p <- x^a;
					VectorB[i] <- p;
				FinPara
				// FACTORIAL
				Para i<-0 Hasta n Hacer
					f <- 1;
					b <- (2*i);
					Para j<-1 Hasta b Hacer
						f <- f*j;
					FinPara
					VectorA[i] <- f;
				FinPara
				// SUMATORIA
				Para i<-0 Hasta n Hacer
					c <- (-1)^i;
					S <- S+((VectorB[i])*c/(VectorA[i]));
				FinPara
				Escribir ' ';
				Escribir 'LA SERIE DE MCLAURIN DE LA FUNCION cos x VALE : ',S;
				S <- 0; f <- 1; mult <- 0; a <- -4; b <- -3; c <- -2; d <- -1;
				rad <- punto*vpi/180;
				// NUMERADOR
				Para i<-0 Hasta n Hacer
					Si i=a+4 Entonces
						coseno <- cos(rad);
						mult <- coseno*((x-rad)^i);
						VectorB[i] <- mult;
						a <- a+4;
					FinSi
					Si i=b+4 Entonces
						seno <- sen(rad);
						mult <- (-1)*seno*((x-rad)^i);
						VectorB[i] <- mult;
						b <- b+4;
					FinSi
					Si i=c+4 Entonces
						coseno <- cos(rad);
						mult <- (-1)*coseno*((x-rad)^i);
						VectorB[i] <- mult;
						c <- c+4;
					FinSi
					Si i=d+4 Entonces
						seno <- sen(rad);
						mult <- seno*((x-rad)^i);
						VectorB[i] <- mult;
						d <- d+4;
					FinSi
				FinPara
				// FACTORIAL
				Para i<-1 Hasta n Hacer
					f <- 1;
					Para j<-1 Hasta i Hacer
						f <- f*j;
					FinPara
					VectorA[i] <- f;
				FinPara
				// SUMATORIA
				Para i<-0 Hasta n Hacer
					S <- S+((VectorB[i])/(VectorA[i]));
				FinPara
				Escribir ' ';
				Escribir 'LA SERIE DE TAYLOR DE LA FUNCION cos x EN EL PUNTO ',punto,'° VALE : ',S;
			4:
				Escribir ' ';
		FinSegun
		Escribir ' ';
	Hasta Que op=4
	Escribir 'Hasta luego...';
FinProceso

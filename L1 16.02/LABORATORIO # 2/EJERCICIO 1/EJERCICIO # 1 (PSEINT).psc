Proceso DCCV_EJ_1
	// 1. Resolución de triángulos  dados 3 datos: a) tres lados
	// b) tres ángulos
	// c) dos lados y un ángulo
	// d) dos ángulos y un lado
	// Resolver los otros tres valores, calcular el area o superficie del triangulo y medianas
	Definir i,j,op1,cl,ca,gl,ga Como Entero;
	Definir lado,angulo,mediana,area,x Como Real;
	Dimension gl[10],ga[10];
	Dimension lado[10],angulo[10],mediana[10];
	Definir op2 Como Caracter;
	cl <- 0; ca <- 0;
	Repetir
		Escribir '******** RESOLUCION DE TRIANGULOS *********';
		Escribir '-------------------------------------------';
		Escribir '      1.- EMPEZAR';
		Escribir '      2.- SALIR';
		Escribir 'INGRESE SU ELECCION :';
		Leer op1;
		Escribir '-------------------------------------------';
		Segun op1  Hacer
			1:
				Escribir '***** TRIANGULOS *****';
				Escribir '----------------------';
				Escribir '              /\';
				Escribir '             /  \';
				Escribir '            / 1* \';
				Escribir '  LADO 1   /      \';
				Escribir '          /        \    LADO 2';
				Escribir '         /          \';
				Escribir '        /            \';
				Escribir '       /              \';
				Escribir '      /                \';
				Escribir '     /__)3*________2*(__\';
				Escribir '            LADO 3';
				Escribir '--------------------------------';
				Escribir 'INGRESE LOS DATOS CONFORME SE DENOTA EN EL TRIANGULO MOSTRADO :';
				Escribir '(En caso de no poseer un dato ingresar cero)';
				Escribir '(Ingresar los angulos en grados positivos)';
				Escribir '      LADOS';
				Escribir '-----------------';
				Para i<-1 Hasta 3 Hacer
					Repetir
						Escribir ' --> Lado < ',i,' > =';
						Leer lado[i];
					Hasta Que lado[i]>=0
					Si lado[i]<>0 Entonces
						cl <- cl+1;
						gl[cl] <- i;
					FinSi
				FinPara
				Escribir '     ANGULOS';
				Escribir '-----------------';
				Para i<-1 Hasta 3 Hacer
					Repetir
						Escribir ' --> Angulo < ',i,' > en grados =';
						Leer angulo[i];
					Hasta Que angulo[i]>=0
					Si angulo[i]<>0 Entonces
						ca <- ca+1;
						ga[ca] <- i;
					FinSi
				FinPara
				Escribir ' ';
				Escribir 'SE TIENE ',cl,' LADOS Y ',ca,' ANGULOS COMO DATOS ';
				Si cl=3 Entonces
					Escribir '  a) Tres lados'; // LEY DE COSENOS
					angulo[3] <- acos(((((lado[3])^2)+((lado[1])^2)-((lado[2])^2))/(2*lado[3]*lado[1])));
					angulo[3] <- angulo[3]*180/PI;
					angulo[1] <- acos(((((lado[2])^2)+((lado[1])^2)-((lado[3])^2))/(2*lado[2]*lado[1])));
					angulo[1] <- angulo[1]*180/PI;
					angulo[2] <- 180-angulo[3]-angulo[1];
				FinSi
				Si ca=3 Entonces
					Escribir '  b) Tres angulos'; // LEY DE COSENOS
					Escribir '  NO ES POSIBLE CALCULAR...';
					Escribir '  DEBIDO A QUE EXISTEN INFINITOS TRIANGULOS DE DIVERSOS TAMANOS, QUE PUEDEN POSEER LOS MISMOS ANGULOS';
				FinSi
				// LEY DE SENOS con un angulo que NO forman estos
				// LEY DE COSENOS con un angulo que SI forman estos
				Si cl=2 Y ca=1 Entonces
					Escribir '  c) Dos lados y un angulo';
					Para i<-1 Hasta 3 Hacer
						Si gl[i]=1 Y gl[i+1]=2 Y ga[i]=1 Entonces // LEY DE COSENOS Y LEY DE SENOS
							lado[3] <- rc(((lado[1])^2)+((lado[2])^2)-(2*lado[1]*lado[2]*(cos((angulo[1]*(PI/180))))));
							angulo[3] <- asen(((lado[2]*(sen((angulo[1]*(PI/180)))))/lado[3]));
							angulo[3] <- angulo[3]*180/PI;
							angulo[2] <- 180-angulo[1]-angulo[3];
						FinSi
						Si gl[i]=1 Y gl[i+1]=3 Y ga[i]=1 Entonces // LEY DE SENOS
							angulo[2] <- asen(((lado[1]*(sen((angulo[1]*(PI/180)))))/lado[3]));
							angulo[2] <- angulo[2]*180/PI;
							angulo[3] <- 180-angulo[1]-angulo[2];
							lado[2] <- lado[3]*(sen((angulo[3]*(PI/180))))/(sen((angulo[1]*(PI/180))));
						FinSi
						Si gl[i]=2 Y gl[i+1]=3 Y ga[i]=1 Entonces // LEY DE SENOS
							angulo[3] <- asen(((lado[2]*(sen((angulo[1]*(PI/180)))))/lado[3]));
							angulo[3] <- angulo[3]*180/PI;
							angulo[2] <- 180-angulo[1]-angulo[3];
							lado[1] <- lado[3]*(sen((angulo[2]*(PI/180))))/(sen((angulo[1]*(PI/180))));
						FinSi
						Si gl[i]=1 Y gl[i+1]=2 Y ga[i]=2 Entonces // LEY DE SENOS
							angulo[3] <- asen(((lado[2]*(sen((angulo[2]*(PI/180)))))/lado[1]));
							angulo[3] <- angulo[3]*180/PI;
							angulo[1] <- 180-angulo[2]-angulo[3];
							lado[3] <- lado[1]*(sen((angulo[1]*(PI/180))))/(sen((angulo[2]*(PI/180))));
						FinSi
						Si gl[i]=1 Y gl[i+1]=3 Y ga[i]=2 Entonces // LEY DE SENOS
							angulo[1] <- asen(((lado[3]*(sen((angulo[2]*(PI/180)))))/lado[1]));
							angulo[1] <- angulo[1]*180/PI;
							angulo[3] <- 180-angulo[1]-angulo[2];
							lado[2] <- lado[3]*(sen((angulo[3]*(PI/180))))/(sen((angulo[3]*(PI/180))));
						FinSi
						Si gl[i]=2 Y gl[i+1]=3 Y ga[i]=2 Entonces // LEY DE COSENOS Y LEY DE SENOS
							lado[1] <- rc(((lado[2])^2)+((lado[3])^2)-(2*lado[2]*lado[3]*(cos((angulo[2]*(PI/180))))));
							angulo[3] <- asen(((lado[2]*(sen((angulo[2]*(PI/180)))))/lado[1]));
							angulo[3] <- angulo[3]*180/PI;
							angulo[1] <- 180-angulo[3]-angulo[2];
						FinSi
						Si gl[i]=1 Y gl[i+1]=2 Y ga[i]=3 Entonces // LEY DE SENOS
							angulo[2] <- asen(((lado[1]*(sen((angulo[3]*(PI/180)))))/lado[2]));
							angulo[2] <- angulo[2]*180/PI;
							angulo[1] <- 180-angulo[3]-angulo[2];
							lado[3] <- lado[2]*(sen((angulo[1]*(PI/180))))/(sen((angulo[3]*(PI/180))));
						FinSi
						Si gl[i]=1 Y gl[i+1]=3 Y ga[i]=3 Entonces // LEY DE TANGENTES Y LEY DE SENOS
							x <- ((lado[1]-lado[3])*(tan((((180-angulo[3])/2)*(PI/180)))))/(lado[1]+lado[3]); x <- atan((x));
							angulo[2] <- ((180-angulo[3])/2)-(x*(180/PI));
							angulo[1] <- (2*(x*(180/PI)))+angulo[2];
							lado[2] <- lado[1]*(sen((angulo[3]*(PI/180))))/(sen((angulo[1]*(PI/180))));
						FinSi
						Si gl[i]=2 Y gl[i+1]=3 Y ga[i]=3 Entonces // LEY DE SENOS
							angulo[1] <- asen(((lado[3]*(sen((angulo[3]*(PI/180)))))/lado[2]));
							angulo[1] <- angulo[1]*180/PI;
							angulo[2] <- 180-angulo[3]-angulo[1];
							lado[1] <- lado[2]*(sen((angulo[2]*(PI/180))))/(sen((angulo[3]*(PI/180))));
						FinSi
					FinPara
				FinSi
				Si cl=1 Y ca=2 Entonces
					Escribir '  c) Dos angulos y un lado';
					Para i<-1 Hasta 3 Hacer
						Si gl[i]=1 Y ga[i]=1 Y ga[i+1]=2 Entonces // LEY DE COSENOS Y LEY DE SENOS
							angulo[3] <- 180-angulo[1]-angulo[2];
							lado[3] <- lado[1]*(sen((angulo[1]*(PI/180))))/(sen((angulo[2]*(PI/180))));
							lado[2] <- rc(((lado[1])^2)+((lado[3])^2)-(2*lado[1]*lado[3]*(cos((angulo[3]*(PI/180))))));
						FinSi
						Si gl[i]=1 Y ga[i]=1 Y ga[i+1]=3 Entonces // LEY DE COSENOS Y LEY DE SENOS
							angulo[1] <- 180-angulo[2]-angulo[3];
							lado[3] <- lado[1]*(sen((angulo[1]*(PI/180))))/(sen((angulo[2]*(PI/180))));
							lado[2] <- rc(((lado[1])^2)+((lado[3])^2)-(2*lado[1]*lado[3]*(cos((angulo[3]*(PI/180))))));
						FinSi
						Si gl[i]=1 Y ga[i]=2 Y ga[i+1]=3 Entonces // LEY DE COSENOS Y LEY DE SENOS
							angulo[1] <- 180-angulo[2]-angulo[3];
							lado[3] <- lado[1]*(sen((angulo[1]*(PI/180))))/(sen((angulo[2]*(PI/180))));
							lado[2] <- rc(((lado[1])^2)+((lado[3])^2)-(2*lado[1]*lado[3]*(cos((angulo[3]*(PI/180))))));
						FinSi
						Si gl[i]=2 Y ga[i]=1 Y ga[i+1]=2 Entonces // LEY DE SENOS
							angulo[3] <- 180-angulo[1]-angulo[2];
							lado[3] <- lado[2]*(sen((angulo[1]*(PI/180))))/(sen((angulo[3]*(PI/180))));
							lado[1] <- lado[3]*(sen((angulo[2]*(PI/180))))/(sen((angulo[1]*(PI/180))));
						FinSi
						Si gl[i]=2 Y ga[i]=1 Y ga[i+1]=3 Entonces // LEY DE COSENOS Y LEY DE SENOS
							angulo[2] <- 180-angulo[1]-angulo[3];
							lado[3] <- lado[2]*(sen((angulo[1]*(PI/180))))/(sen((angulo[3]*(PI/180))));
							lado[2] <- rc(((lado[2])^2)+((lado[3])^2)-(2*lado[2]*lado[3]*(cos((angulo[2]*(PI/180))))));
						FinSi
						Si gl[i]=2 Y ga[i]=2 Y ga[i+1]=3 Entonces // LEY DE SENOS
							angulo[1] <- 180-angulo[2]-angulo[3];
							lado[3] <- lado[2]*(sen((angulo[1]*(PI/180))))/(sen((angulo[3]*(PI/180))));
							lado[1] <- lado[2]*(sen((angulo[2]*(PI/180))))/(sen((angulo[3]*(PI/180))));
						FinSi
						Si gl[i]=3 Y ga[i]=1 Y ga[i+1]=2 Entonces // LEY DE COSENOS Y LEY DE SENOS
							angulo[3] <- 180-angulo[1]-angulo[2];
							lado[1] <- lado[3]*(sen((angulo[2]*(PI/180))))/(sen((angulo[1]*(PI/180))));
							lado[2] <- rc(((lado[1])^2)+((lado[3])^2)-(2*lado[1]*lado[3]*(cos((angulo[3]*(PI/180))))));
						FinSi
						Si gl[i]=3 Y ga[i]=1 Y ga[i+1]=3 Entonces // LEY DE COSENOS Y LEY DE SENOS
							angulo[2] <- 180-angulo[1]-angulo[3];
							lado[1] <- lado[3]*(sen((angulo[2]*(PI/180))))/(sen((angulo[1]*(PI/180))));
							lado[2] <- rc(((lado[1])^2)+((lado[3])^2)-(2*lado[1]*lado[3]*(cos((angulo[3]*(PI/180))))));
						FinSi
						Si gl[i]=3 Y ga[i]=2 Y ga[i+1]=3 Entonces // LEY DE COSENOS Y LEY DE SENOS
							angulo[1] <- 180-angulo[2]-angulo[3];
							lado[1] <- lado[3]*(sen((angulo[2]*(PI/180))))/(sen((angulo[1]*(PI/180))));
							lado[2] <- rc(((lado[1])^2)+((lado[3])^2)-(2*lado[1]*lado[3]*(cos((angulo[3]*(PI/180))))));
						FinSi
					FinPara
				FinSi
				area <- 0.5*lado[2]*lado[3]*((sen((angulo[2]*(PI/180)))));
				// MEDIANAS
				mediana[1] <- 0.5*rc(2*((((lado[1])^2))+(((lado[2])^2)))-(((lado[3])^2)));
				mediana[2] <- 0.5*rc(2*((((lado[2])^2))+(((lado[3])^2)))-(((lado[1])^2)));
				mediana[3] <- 0.5*rc(2*((((lado[1])^2))+(((lado[3])^2)))-(((lado[2])^2)));
				Escribir '  POR TANTO TENEMOS :';
				Para i<-1 Hasta 3 Hacer
					Escribir '  --> LADO < ',i,' > = ',lado[1],'          ANGULO Alfa ',i,'* = ',angulo[i],' grados';
				FinPara
				Escribir ' ';
				Escribir ' ';
				Escribir '  --> MEDIANA A1-L3 = ',mediana[1],' [u]';
				Escribir '  --> MEDIANA A2-L1 = ',mediana[2],' [u]';
				Escribir '  --> MEDIANA A3-L2 = ',mediana[3],' [u]';
				Escribir ' ';
				Escribir '  --> AREA = ',area,' [u^2]';
				Escribir '-----------------------------------------------------------------------------------------------';
			2:
				Escribir 'Hasta luego...';
			De Otro Modo:
				Escribir 'Error de entrada';
		FinSegun
		Escribir 'DESEA REALIZAR OTRA OPERACION';
		Escribir 'Pulse N para salir de lo contrario pulse cualquiera';
		Leer op2;
	Hasta Que op2='n' O op2='N'
	Escribir ' ';
	Escribir 'GRACIAS...';
FinProceso

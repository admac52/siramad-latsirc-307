// PARA A
Funcion DEE<-DETA(MA,m1)
	Definir detaa Como Real;
	detaa=0;
	Si m1=1 Entonces
		detaa=MA[0,0];
	SiNo
		Para i<-1 Hasta m1 Con Paso 1 Hacer
			detaa=detaa+(MA[0,i]*(COFA(MA,m1,0,i)));
		FinPara
	FinSi
	Escribir detea;
FinFuncion
Funcion COFF<-COFA(MA,m1,fa,ca)
	Definir rna,aa,ba Como Entero;
	Definir cofaa, AUXA Como Real;
	Dimension AUXA[100,100];
	rna=m1-1;
	aa=0;ba=0;
	Para i<-1 Hasta m1 Con Paso 1 Hacer
		Para j<-1 Hasta m1 Con Paso 1 Hacer
			Si ((i<>fa) y (j<>ca)) Entonces
				AUXA[aa,ba]=MA[i,j];
				ba=ba+1;
				Si ba>=rna Entonces
					aa=aa+1;
					ba=0;
				FinSi
			FinSi
		FinPara
	FinPara
	cofaa=(-1^(fa+ca)) * (DETA(AUXA, rna));
FinFuncion
// PARA B
Funcion DEE<-DETB(MB,m1)
	Definir detbb Como Real;
	detabb=0;
	Si m2=1 Entonces
		detabb=MB[0,0];
	SiNo
		Para i<-1 Hasta m2 Con Paso 1 Hacer
			detbb=detbb+(MB[0,i]*(COFB(MB,m2,0,i)));
		FinPara
	FinSi
	Escribir detea;
FinFuncion
Funcion COFF<-COFB(MB,m2,fb,cb)
	Definir rnb,ab,bb Como Entero;
	Definir cofbb, AUXB Como Real;
	Dimension AUXB[100,100];
	rna=m2-1;
	ba=0;bb=0;
	Para i<-1 Hasta m2 Con Paso 1 Hacer
		Para j<-1 Hasta m2 Con Paso 1 Hacer
			Si ((i<>fb) y (j<>cb)) Entonces
				AUXB[ab,bb]=MB[i,j];
				bb=bb+1;
				Si bb>=rnb Entonces
					ab=ab+1;
					bb=0;
				FinSi
			FinSi
		FinPara
	FinPara
	cofbb=(-1^(fb+cb)) * (DETB(AUXB, rnb));
FinFuncion
Proceso DCCV_1
	// 1. CALCULADORA MATRICIAL
	// Dadas 2 matrices A y B de orden m x n  y j x k  calcular  axb, a+b, a-b, a/b
	Definir opA,opB,m1,n1,m2,n2,extra,adia,adib Como Entero;
	Definir rango,fil,col,elev,elea,eleb,coea,coeb,escalar,x,auxaa,auxbb Como Real;
	Definir op1 Como Caracter;
	Definir MA,MB,S,R,M,D,OPA,OPB,AEA,AEB,INA,INB Como Real;
	Dimension MA[100,100],MB[100,100],S[100,100],R[100,100],M[100,100],D[100,100];
	Dimension OPAA[100,100],OPBB[100,100],AEA[100,100],AEB[100,100],INA[100,100],INB[100,100];
	Dimension auxaaa[100,100],auxbbb[100,100];
	
	Repetir
		Escribir '********** CALCULADORA MATRICIAL ***********';
		Escribir '-------------------------------------------';
		Escribir '  //////////////////////////////////////////////////////////////////////////////////////////////////////////////';
		Escribir '  //                                                                                                          //';
		Escribir '  //      ++++++ OPERACIONES ENTRE MATRICES ++++++      ++++++ OPERACIONES ADICIONALES ++++++                 //';
		Escribir '  //                                                                                                          //';
		Escribir '  //\t\t\t A + B\t\t\t\t\tDeterminante                                  //';
		Escribir '  //\t\t\t A - B\t\t\t\t\tMatriz Inversa                                //';
		Escribir '  //\t\t\t A x B\t\t\t\t\tMatriz transpuesta                            //';
		Escribir '  //\t\t\t A / B\t\t\t\t\tMultiplicar por un escalar                    //';
		Escribir '  //\t\t\t      \t\t\t\t\tRango                                         //';
		Escribir '  //\t\t\t      \t\t\t\t\tMatriz Triangular                             //';
		Escribir '  //\t\t\t      \t\t\t\t\tMatriz Diagonal                               //';
		Escribir '  //\t\t\t      \t\t\t\t\tMatriz Elevada a...                           //';
		Escribir '  //\t\t\t      \t\t\t\t\tFactorizacion LU                              //';
		Escribir '  //\t\t\t      \t\t\t\t\tFactorizacion de Cholesky                     //';
		Escribir '  //\t\t\t      \t\t\t\t\tValores y Vectores propios                    /';
		Escribir '  //                                                                                                          //';
		Escribir '  //////////////////////////////////////////////////////////////////////////////////////////////////////////////';
		// DIMENSIONES A
		Escribir '   MATRIZ A';
		Escribir '------------------------';
		Repetir
			Escribir ' INGRESE EL NUMERO DE FILAS PARA LA MATRIZ A ';
			Escribir ' --> ';
			Leer m1;
		Hasta Que m1>=0
		Repetir
			Escribir ' INGRESE EL NUMERO DE COLUMNAS PARA LA MATRIZ A';
			Escribir ' --> ';
			Leer n1;
		Hasta Que n1>=0
		// LLENADO A
		Escribir '----------------------------------------------------';
		Escribir ' USTED PUEDE :';
		Escribir '      1.- Ingresar datos por teclado';
		Escribir '      2.- Llenar datos al azar';
		Escribir 'INGRESE SU ELECCION :';
		Leer opA;
		Escribir '-------------------------------------------';
		Segun opA  Hacer
			1:
				Escribir 'INTRODUZCA LOS DATOS PARA LA MATRIZ A ';
				Para i<-1 Hasta m1 Con Paso 1 Hacer
					Para j<-1 Hasta n1 Con Paso 1 Hacer
						Escribir ' MATRIZ A[',i+1,',',j+1,'] =';
						Leer MA[i,j];
					FinPara
				FinPara
			2:
				Para i<-1 Hasta m1 Con Paso 1 Hacer
					Para j<-1 Hasta n1 Con Paso 1 Hacer
						MA[i,j]=azar(20)+1;
					FinPara
				FinPara
			De Otro Modo:
				Escribir 'Error de dato de entrada';
		FinSegun
		Escribir '--------------------------------------------------------------';
		// DIMENSIONES B
		Escribir '   MATRIZ B';
		Escribir '------------------------';
		Repetir
			Escribir ' INGRESE EL NUMERO DE FILAS PARA LA MATRIZ B ';
			Escribir ' --> ';
			Leer m2;
		Hasta Que m2>=0
		Repetir
			Escribir ' INGRESE EL NUMERO DE COLUMNAS PARA LA MATRIZ B';
			Escribir ' --> ';
			Leer n2;
		Hasta Que n2>=0
		// LLENADO B
		Escribir '----------------------------------------------------';
		Escribir ' USTED PUEDE :';
		Escribir '      1.- Ingresar datos por teclado';
		Escribir '      2.- Llenar datos al azar';
		Escribir 'INGRESE SU ELECCION :';
		Leer opA;
		Escribir '-------------------------------------------';
		Segun opA  Hacer
			1:
				Escribir 'INTRODUZCA LOS DATOS PARA LA MATRIZ B ';
				Para i<-1 Hasta m2 Con Paso 1 Hacer
					Para j<-1 Hasta n2 Con Paso 1 Hacer
						Escribir ' MATRIZ B[',i+1,',',j+1,'] =';
						Leer MB[i,j];
					FinPara
				FinPara
			2:
				Para i<-1 Hasta m2 Con Paso 1 Hacer
					Para j<-1 Hasta n2 Con Paso 1 Hacer
						MB[i,j]=azar(20)+1;
					FinPara
				FinPara
			De Otro Modo:
				Escribir 'Error de dato de entrada';
		FinSegun
		//MOSTRAR
		Escribir 'DADAS LAS MATRICES: ';
		Escribir '           MATRIZ A';
		Escribir '-------------------------------';
		Para i<-1 Hasta m1 Con Paso 1 Hacer
			Para j<-1 Hasta n1 Con Paso 1 Hacer
				INA[i,j]=MA[i,j];
				Escribir MA[i,j],"   ";
			FinPara
			Escribir ' ';
		FinPara
		Escribir '           MATRIZ B';
		Escribir '-------------------------------';
		Para i<-1 Hasta m1 Con Paso 1 Hacer
			Para j<-1 Hasta n1 Con Paso 1 Hacer
				INB[i,j]=MB[i,j];
				Escribir MB[i,j],"   ";
			FinPara
			Escribir ' ';
		FinPara
		// OPERACIONES
		// **** SUMA****
		Si ((m1==m2) y (n1==n2)) Entonces
			Para i<-1 Hasta m1 Con Paso 1 Hacer
				Para j<-1 Hasta n1 Con Paso 1 Hacer
					S[i,j]=MA[i,j]+MB[i,j];
				FinPara
			FinPara
		FinSi
		// **** RESTA ****
		Si ((m1=m2) y (n1=n2)) Entonces
			Para i<-1 Hasta m1 Con Paso 1 Hacer
				Para j<-1 Hasta n1 Con Paso 1 Hacer
					R[i,j]=MA[i,j]-MB[i,j];
				FinPara
			FinPara
		FinSi
		// **** MULTIPLICACION ****
		Si ((n1=m2)) Entonces
			Para i<-1 Hasta m1 Con Paso 1 Hacer
				Para j<-1 Hasta n2 Con Paso 1 Hacer
					Para k<-1 Hasta m2 Con Paso 1 Hacer
						M[i,j]=M[i,j]+(MA[i,k]*MB[k,j]);
					FinPara
				FinPara
			FinPara
		FinSi
		// **** INVERSA Y DETERMINANTE **** A
		Si ((m1=n1)) Entonces
			Si ((DETA(MA,m1))<>0) Entonces
				Para i<-1 Hasta m1 Con Paso 1 Hacer
					Para j<-m1 Hasta 2*m1 Con Paso 1 Hacer
						Si i=j-m1 Entonces
							INA[i,j]=1;
						SiNo
							INA[i,j]=0;
						FinSi
					FinPara
				FinPara
				Para k<-1 Hasta m1 Con Paso 1 Hacer
					elea=INA[k,k];
					Para j<-1 Hasta 2*m1 Con Paso 1 Hacer
						INA[k,j]=INA[k,j]/elea;
					FinPara
					Para i<-1 Hasta m1 Con Paso 1 Hacer
						Si i=k Entonces
							Escribir Sin Saltar " ";
						SiNo
							coea=INA[i,k];
							Para j<-1 Hasta 2*m1 Con Paso 1 Hacer
								auxaaa[i,j]=INA[k,j]+(coea*(-1));
							FinPara
							Para j<-1 Hasta 2*m1 Con Paso 1 Hacer
								INA[i,j]=INA[i,j]+auxaaa[j];
							FinPara
						FinSi
					FinPara
				FinPara
				Para i<-1 Hasta m1 Con Paso 1 Hacer
					Para j<-m1 Hasta 2*m1 Con Paso 1 Hacer
						INA[i,j-m1]=INA[i,j];
					FinPara
				FinPara
			FinSi
		FinSi
		// **** INVERSA Y DETERMINANTE **** B
		Si ((m2=n2)) Entonces
			Si ((DETB(MB,m2))<>0) Entonces
				Para i<-1 Hasta m2 Con Paso 1 Hacer
					Para j<-m1 Hasta 2*m2 Con Paso 1 Hacer
						Si i=j-m2 Entonces
							INB[i,j]=1;
						SiNo
							INB[i,j]=0;
						FinSi
					FinPara
				FinPara
				Para k<-1 Hasta m2 Con Paso 1 Hacer
					eleb=INB[k,k];
					Para j<-1 Hasta 2*m2 Con Paso 1 Hacer
						INB[k,j]=INB[k,j]/eleb;
					FinPara
					Para i<-1 Hasta m2 Con Paso 1 Hacer
						Si i=k Entonces
							Escribir Sin Saltar " ";
						SiNo
							coeb=INB[i,k];
							Para j<-1 Hasta 2*m2 Con Paso 1 Hacer
								auxbbb[i,j]=INB[k,j]+(coeb*(-1));
							FinPara
							Para j<-1 Hasta 2*m2 Con Paso 1 Hacer
								INB[i,j]=INB[i,j]+auxbbb[j];
							FinPara
						FinSi
					FinPara
				FinPara
				Para i<-1 Hasta m2 Con Paso 1 Hacer
					Para j<-m1 Hasta 2*m2 Con Paso 1 Hacer
						INB[i,j-m2]=INB[i,j];
					FinPara
				FinPara
			FinSi
		FinSi
		// **** DIVISION ****
		Si ((m2=n2) y ((DETB(MB, m2))<>0)) Entonces
			Si (n1=m2) Entonces
				Para i<-1 Hasta m1 Con Paso 1 Hacer
					Para j<-1 Hasta n2 Con Paso 1 Hacer
						Para k<-1 Hasta m2 Con Paso 1 Hacer
							D[i,j]=D[i,j]+(MA[i,k]*INB[k,j]);
						FinPara
					FinPara
				FinPara
			FinSi
		FinSi
		Escribir 'Que operacion desea mostrar...';
		Escribir '         a.- A + B';
		Escribir '         b.- A - B';
		Escribir '         c.- A x B';
		Escribir '         d.- A / B';
		Escribir '         e.- Mostrar todas las anteriores';
		Escribir '         f.- CONTINUAR';
		Escribir 'INGRESE SU ELECCION:';
		Leer op1;
		
		
		Escribir '--------------------------------';
		Escribir 'INGRESE LOS DATOS CONFORME SE DENOTA EN EL TRIANGULO MOSTRADO :';
		Escribir '(En caso de no poseer un dato ingresar cero)';
		Escribir '(Ingresar los angulos en grados positivos)';
		Escribir '      LADOS';
		Escribir '-----------------';
		
		Escribir '     ANGULOS';
		Escribir '-----------------';
		
		Escribir 'DESEA REALIZAR OTRA OPERACION';
		Escribir 'Pulse N para salir de lo contrario pulse cualquiera';
		Leer op2;
	Hasta Que op2='n' O op2='N'
	Escribir ' ';
	Escribir 'GRACIAS...';
FinProceso

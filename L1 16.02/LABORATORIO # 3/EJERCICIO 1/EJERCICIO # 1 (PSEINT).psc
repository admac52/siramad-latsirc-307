// PARA A
SubProceso DEE <- DETA(MA,m1)
	Definir detaa Como Real;
	detaa <- 0;
	Si m1=1 Entonces
		detaa <- MA[0,0];
	SiNo
		Para i<-1 Hasta m1 Hacer
			detaa <- detaa+(MA[0,i]*(COFA(MA,m1,0,i)));
		FinPara
	FinSi
	Escribir detea;
FinSubProceso

SubProceso COFF <- COFA(MA,m1,fa,ca)
	Definir rna,aa,ba Como Entero;
	Definir cofaa,AUXA Como Real;
	Dimension AUXA[100,100];
	rna <- m1-1;
	aa <- 0; ba <- 0;
	Para i<-1 Hasta m1 Hacer
		Para j<-1 Hasta m1 Hacer
			Si ((i<>fa) Y (j<>ca)) Entonces
				AUXA[aa,ba]<-MA[i,j];
				ba <- ba+1;
				Si ba>=rna Entonces
					aa <- aa+1;
					ba <- 0;
				FinSi
			FinSi
		FinPara
	FinPara
	cofaa <- (-1^(fa+ca))*(DETA(AUXA,rna));
FinSubProceso

// PARA B
SubProceso DEE <- DETB(MB,m1)
	Definir detbb Como Real;
	detabb <- 0;
	Si m2=1 Entonces
		detabb <- MB[0,0];
	SiNo
		Para i<-1 Hasta m2 Hacer
			detbb <- detbb+(MB[0,i]*(COFB(MB,m2,0,i)));
		FinPara
	FinSi
	Escribir detea;
FinSubProceso

SubProceso COFF <- COFB(MB,m2,fb,cb)
	Definir rnb,ab,bb Como Entero;
	Definir cofbb,AUXB Como Real;
	Dimension AUXB[100,100];
	rna <- m2-1;
	ba <- 0; bb <- 0;
	Para i<-1 Hasta m2 Hacer
		Para j<-1 Hasta m2 Hacer
			Si ((i<>fb) Y (j<>cb)) Entonces
				AUXB[ab,bb]<-MB[i,j];
				bb <- bb+1;
				Si bb>=rnb Entonces
					ab <- ab+1;
					bb <- 0;
				FinSi
			FinSi
		FinPara
	FinPara
	cofbb <- (-1^(fb+cb))*(DETB(AUXB,rnb));
FinSubProceso

Proceso DCCV_1
	// 1. CALCULADORA MATRICIAL
	// Dadas 2 matrices A y B de orden m x n  y j x k  calcular  axb, a+b, a-b, a/b
	Definir opA,OPB,m1,n1,m2,n2,extra,adia,adib Como Entero;
	Definir rango,fil,col,elev,elea,eleb,coea,coeb,escalar,x,auxaa,auxbb Como Real;
	Definir op1,op2 Como Caracter;
	Definir MA,MB,S,R,M,D,opA,OPB,AEA,AEB,INA,INB Como Real;
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
				Para i<-1 Hasta m1 Hacer
					Para j<-1 Hasta n1 Hacer
						Escribir ' MATRIZ A[',i+1,',',j+1,'] =';
						Leer MA[i,j];
					FinPara
				FinPara
			2:
				Para i<-1 Hasta m1 Hacer
					Para j<-1 Hasta n1 Hacer
						MA[i,j]<-azar(20)+1;
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
				Para i<-1 Hasta m2 Hacer
					Para j<-1 Hasta n2 Hacer
						Escribir ' MATRIZ B[',i+1,',',j+1,'] =';
						Leer MB[i,j];
					FinPara
				FinPara
			2:
				Para i<-1 Hasta m2 Hacer
					Para j<-1 Hasta n2 Hacer
						MB[i,j]<-azar(20)+1;
					FinPara
				FinPara
			De Otro Modo:
				Escribir 'Error de dato de entrada';
		FinSegun
		Escribir 'DADAS LAS MATRICES: ';
		// MOSTRAR
		Escribir '           MATRIZ A';
		Escribir '-------------------------------';
		Para i<-1 Hasta m1 Hacer
			Para j<-1 Hasta n1 Hacer
				INA[i,j]<-MA[i,j];
				Escribir MA[i,j],'   ';
			FinPara
			Escribir ' ';
		FinPara
		Escribir '           MATRIZ B';
		Escribir '-------------------------------';
		Para i<-1 Hasta m1 Hacer
			Para j<-1 Hasta n1 Hacer
				INB[i,j]<-MB[i,j];
				Escribir MB[i,j],'   ';
			FinPara
			Escribir ' ';
		FinPara
		// OPERACIONES
		// **** SUMA****
		Si ((m1==m2) Y (n1==n2)) Entonces
			Para i<-1 Hasta m1 Hacer
				Para j<-1 Hasta n1 Hacer
					S[i,j]<-MA[i,j]+MB[i,j];
				FinPara
			FinPara
		FinSi
		// **** RESTA ****
		Si ((m1=m2) Y (n1=n2)) Entonces
			Para i<-1 Hasta m1 Hacer
				Para j<-1 Hasta n1 Hacer
					R[i,j]<-MA[i,j]-MB[i,j];
				FinPara
			FinPara
		FinSi
		// **** MULTIPLICACION ****
		Si ((n1=m2)) Entonces
			Para i<-1 Hasta m1 Hacer
				Para j<-1 Hasta n2 Hacer
					Para k<-1 Hasta m2 Hacer
						M[i,j]<-M[i,j]+(MA[i,k]*MB[k,j]);
					FinPara
				FinPara
			FinPara
		FinSi
		// **** INVERSA Y DETERMINANTE **** A
		Si ((m1=n1)) Entonces
			Si ((DETA(MA,m1))<>0) Entonces
				Para i<-1 Hasta m1 Hacer
					Para j<-m1 Hasta 2*m1 Hacer
						Si i=j-m1 Entonces
							INA[i,j]<-1;
						SiNo
							INA[i,j]<-0;
						FinSi
					FinPara
				FinPara
				Para k<-1 Hasta m1 Hacer
					elea <- INA[k,k];
					Para j<-1 Hasta 2*m1 Hacer
						INA[k,j]<-INA[k,j]/elea;
					FinPara
					Para i<-1 Hasta m1 Hacer
						Si i=k Entonces
							Escribir ' ' Sin Saltar;
						SiNo
							coea <- INA[i,k];
							Para j<-1 Hasta 2*m1 Hacer
								auxaaa[i,j]<-INA[k,j]+(coea*(-1));
							FinPara
							Para j<-1 Hasta 2*m1 Hacer
								INA[i,j]<-INA[i,j]+auxaaa[j];
							FinPara
						FinSi
					FinPara
				FinPara
				Para i<-1 Hasta m1 Hacer
					Para j<-m1 Hasta 2*m1 Hacer
						INA[i,j-m1]<-INA[i,j];
					FinPara
				FinPara
			FinSi
		FinSi
		// **** INVERSA Y DETERMINANTE **** B
		Si ((m2=n2)) Entonces
			Si ((DETB(MB,m2))<>0) Entonces
				Para i<-1 Hasta m2 Hacer
					Para j<-m1 Hasta 2*m2 Hacer
						Si i=j-m2 Entonces
							INB[i,j]<-1;
						SiNo
							INB[i,j]<-0;
						FinSi
					FinPara
				FinPara
				Para k<-1 Hasta m2 Hacer
					eleb <- INB[k,k];
					Para j<-1 Hasta 2*m2 Hacer
						INB[k,j]<-INB[k,j]/eleb;
					FinPara
					Para i<-1 Hasta m2 Hacer
						Si i=k Entonces
							Escribir ' ' Sin Saltar;
						SiNo
							coeb <- INB[i,k];
							Para j<-1 Hasta 2*m2 Hacer
								auxbbb[i,j]<-INB[k,j]+(coeb*(-1));
							FinPara
							Para j<-1 Hasta 2*m2 Hacer
								INB[i,j]<-INB[i,j]+auxbbb[j];
							FinPara
						FinSi
					FinPara
				FinPara
				Para i<-1 Hasta m2 Hacer
					Para j<-m1 Hasta 2*m2 Hacer
						INB[i,j-m2]<-INB[i,j];
					FinPara
				FinPara
			FinSi
		FinSi
		// **** DIVISION ****
		Si ((m2=n2) Y ((DETB(MB,m2))<>0)) Entonces
			Si (n1=m2) Entonces
				Para i<-1 Hasta m1 Hacer
					Para j<-1 Hasta n2 Hacer
						Para k<-1 Hasta m2 Hacer
							D[i,j]<-D[i,j]+(MA[i,k]*INB[k,j]);
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
		Segun op1  Hacer
			'a':
				Escribir '******** S U M A ********';
				Escribir ' MATRIZ A + MATRIZ B';
				Escribir '-------------------------';
				Si m1=m2 Y n1=n2 Entonces
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n1 Hacer
							Escribir S[i,j];
						FinPara
						Escribir ' ';
					FinPara
				SiNo
					Escribir 'NO SE PUEDEN SUMAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN';
				FinSi
			'b':
				Escribir '******** R E S T A ********';
				Escribir ' MATRIZ A - MATRIZ B';
				Escribir '-------------------------';
				Si m1=m2 Y n1=n2 Entonces
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n1 Hacer
							Escribir R[i,j];
						FinPara
						Escribir ' ';
					FinPara
				SiNo
					Escribir 'NO SE PUEDEN RESTAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN';
				FinSi
			'c':
				Escribir '******** M U L T I P L I C A C I O N ********';
				Escribir ' MATRIZ A x MATRIZ B';
				Escribir '-------------------------';
				Si n1=m2 Entonces
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n2 Hacer
							Escribir M[i,j];
						FinPara
						Escribir ' ';
					FinPara
				SiNo
					Escribir 'NO SE PUEDEN MULTIPLICAR...';
					Escribir 'PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A, ES DIFERENTE DEL NUMERO DE FILAS DE LA MATRIZ B';
				FinSi
			'd':
				Escribir '******** D I V I S I O N ********';
				Escribir ' MATRIZ A / MATRIZ B';
				Escribir '-------------------------';
				Si ((m2=n2) Y ((DETB(MB,m2))<>0)) Entonces
					Si (n1=m2) Entonces
						Para i<-1 Hasta m1 Hacer
							Para j<-1 Hasta n2 Hacer
								Escribir D[i,j];
							FinPara
							Escribir ' ';
						FinPara
					SiNo
						Escribir 'NO SE PUEDEN MULTIPLICAR...';
						Escribir 'PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A, ES DIFERENTE DEL NUMERO DE FILAS DE LA INVERSA B';
					FinSi
				SiNo
					Escribir 'NO SE PUEDE DIVIDIR LA MATRIZ A CON LA MATRIZ B';
				FinSi
			'e':
				Escribir '******** S U M A ********';
				Escribir ' MATRIZ A + MATRIZ B';
				Escribir '-------------------------';
				Si m1=m2 Y n1=n2 Entonces
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n1 Hacer
							Escribir S[i,j];
						FinPara
						Escribir ' ';
					FinPara
				SiNo
					Escribir 'NO SE PUEDEN SUMAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN';
				FinSi
				Escribir ' ';
				Escribir '******** R E S T A ********';
				Escribir ' MATRIZ A - MATRIZ B';
				Escribir '-------------------------';
				Si m1=m2 Y n1=n2 Entonces
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n1 Hacer
							Escribir R[i,j];
						FinPara
						Escribir ' ';
					FinPara
				SiNo
					Escribir 'NO SE PUEDEN RESTAR, PORQUE LA MATRIZ A Y B SON DE DIFERENTE ORDEN';
				FinSi
				Escribir ' ';
				Escribir '******** M U L T I P L I C A C I O N ********';
				Escribir ' MATRIZ A x MATRIZ B';
				Escribir '-------------------------';
				Si n1=m2 Entonces
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n2 Hacer
							Escribir M[i,j];
						FinPara
						Escribir ' ';
					FinPara
				SiNo
					Escribir 'NO SE PUEDEN MULTIPLICAR...';
					Escribir 'PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A, ES DIFERENTE DEL NUMERO DE FILAS DE LA MATRIZ B';
				FinSi
				Escribir ' ';
				Escribir '******** D I V I S I O N ********';
				Escribir ' MATRIZ A / MATRIZ B';
				Escribir '-------------------------';
				Si ((m2=n2) Y ((DETB(MB,m2))<>0)) Entonces
					Si (n1=m2) Entonces
						Para i<-1 Hasta m1 Hacer
							Para j<-1 Hasta n2 Hacer
								Escribir D[i,j];
							FinPara
							Escribir ' ';
						FinPara
					SiNo
						Escribir 'NO SE PUEDEN MULTIPLICAR...';
						Escribir 'PORQUE EL NUMERO DE COLUMNAS DE LA MATRIZ A, ES DIFERENTE DEL NUMERO DE FILAS DE LA INVERSA B';
					FinSi
				SiNo
					Escribir 'NO SE PUEDE DIVIDIR LA MATRIZ A CON LA MATRIZ B';
				FinSi
				Escribir ' ';
			'f':
				Escribir 'Continue...';
			De Otro Modo:
				Escribir 'Error de eleccion';
		FinSegun
		Escribir '---------------------------------------------------------------';
		Escribir ' DESEA REALIZAR OPERACIONES ADICIONALES PARA A';
		Escribir '              1.- SI';
		Escribir '              2.- NO';
		Escribir ' INGRESE SU ELECCION:';
		Leer adia;
		Escribir ' ';
		Si adia=1 Entonces
			Escribir '********** OPERACIONES ADICIONALES **********';
			Escribir '       1.- Determinante';
			Escribir '       2.- Matriz inversa';
			Escribir '       3.- Matriz transpuesta';
			Escribir '       4.- Multiplicar por un escalar';
			Escribir '       5.- Rango';
			Escribir '       6.- Matriz Triangular';
			Escribir '       7.- Matriz Diagonal';
			Escribir '       8.- Matriz Elevada a...';
			Escribir '       9.- Factorizacion LU';
			Escribir '       10.- Factorizacion de Cholesky';
			Escribir '       11.- Valores y Vectores propios';
			Escribir '       12.- CONTINUAR';
			Escribir ' INGRESE SU ELECCION:';
			Leer extra;
			Escribir ' ';
			Escribir '---------------------------------------------------------------';
			Segun extra  Hacer
				1:
					Escribir '******** DETERMINANTE ********';
					Si m1=n1 Entonces
						Escribir ' LA DETERMINANTE DE LA MATRIZ A ES : ',DETA(MA,m1);
					SiNo
						Escribir 'LA MATRIZ A NO ES CUADRADA';
						Escribir 'POR TANTO NO SE PUEDE HALLAR LA DETERMINANTE';
					FinSi
				2:
					Escribir '******** MATRIZ INVERSA ********';
					Si m1=n1 Entonces
						Si ((DETA(MA,m1))<>0) Entonces
							Para i<-1 Hasta m1 Hacer
								Para j<-1 Hasta m1 Hacer
									Escribir INA[i,j];
								FinPara
								Escribir ' ';
							FinPara
						SiNo
							Escribir 'NO SE PUEDE HALLAR LA INVERSA, PORQUE LA DETERMINANTE ES CERO';
						FinSi
					SiNo
						Escribir 'LA MATRIZ A NO ES CUADRADA';
						Escribir 'POR TANTO NO SE PUEDE HALLAR LA DETERMINANTE, NI LA INVERSA';
					FinSi
				3:
					Escribir '******** MATRIZ TRANSPUESTA ********';
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n1 Hacer
							Escribir MA[j,i];
						FinPara
						Escribir ' ';
					FinPara
				4:
					Escribir '******** MULTIPLICAR POR UN ESCALAR ********';
					Escribir ' POR FAVOR, INTRODUZCA UN ESCALAR PARA MULTIPLICAR A LA MATRIZ A';
					Leer escalar;
					Escribir ' ';
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n1 Hacer
							OPAA[i,j]<-(escalar)*(MA[i,j]);
							Escribir OPAA[i,j];
						FinPara
						Escribir ' ';
					FinPara
				5:
					Escribir '******** RANGO ********';
					Escribir ' EL RANGO DE LA MATRIZ A ES : ';
					rango <- 0;
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n1 Hacer
							Si MA[i,j]<>0 Entonces
								col <- col+1;
							FinSi
						FinPara
						Si col>=1 Entonces
							fil <- fil+1;
						FinSi
					FinPara
					rango <- fil; fil <- 0; col <- 0;
					Para j<-1 Hasta n1 Hacer
						Para i<-1 Hasta m1 Hacer
							Si MA[i,j]<>0 Entonces
								fil <- fil+1;
							FinSi
						FinPara
						Si fil>=1 Entonces
							col <- col+1;
						FinSi
					FinPara
					Si rango>=col Entonces
						rango <- col;
					SiNo
						Escribir rango;
					FinSi
				6:
					Escribir '******** MATRIZ TRIANGULAR ********';
					Para k<-1 Hasta n1-1 Hacer
						Para i<-1 Hasta m1 Hacer
							x <- MA[i+1,k];
							p <- 0;
							Si (k<i+1) Entonces
								Si ((MA[i+1,k])<>0) Entonces
									Para j<-k Hasta n1 Hacer
										Si p>=k Entonces
											MA[i+1,j]<-MA[i+1,j]-((x/MA[k,k])*MA[k,p]);
											p <- p+1;
										SiNo
											p <- k; q <- k+1;
											MA[i+1,j]<-MA[i+1,j]-((x/MA[k,q])*MA[k,q]);
											p <- p+1; q <- q+1;
										FinSi
									FinPara
								FinSi
							FinSi
						FinPara
					FinPara
					Para i<-1 Hasta m1 Hacer
						Para j<-1 Hasta n1 Hacer
							Escribir MA[i,j];
						FinPara
						Escribir ' ';
					FinPara
				7:
					Escribir '******** MATRIZ DIAGONAL ********';
				8:
					Escribir '******** MATRIZ ELEVADA A ********';
					Si ((m1=n1)) Entonces
						Repetir
							Escribir ' INTRODUZCA UN ENTERO A ELEVAR LA MATRIZ A';
							Escribir ' --> ';
							Leer elev;
						Hasta Que elev>=0
						Para i<-1 Hasta m1 Hacer
							Para j<-1 Hasta n1 Hacer
								Para k<-1 Hasta m1 Hacer
									OPAA[i,j]<-OPAA[i,j]+(MA[i,k]*MA[k,j]);
								FinPara
							FinPara
						FinPara
						Para i<-1 Hasta m1 Hacer
							Para j<-1 Hasta n1 Hacer
								AEA[i,j]<-OPAA[i,j];
								OPAA[i,j]<-0;
							FinPara
						FinPara
						Para l<-1 Hasta elev Hacer
							Para i<-1 Hasta m1 Hacer
								Para j<-1 Hasta n1 Hacer
									Para k<-1 Hasta m1 Hacer
										OPAA[i,j]<-OPAA[i,j]+(AEA[i,k]*MA[k,j]);
									FinPara
								FinPara
							FinPara
							Para i<-1 Hasta m1 Hacer
								Para j<-1 Hasta n1 Hacer
									AEA[i,j]<-OPAA[i,j];
									OPAA[i,j]<-0;
								FinPara
							FinPara
						FinPara
						Para i<-1 Hasta m1 Hacer
							Para j<-1 Hasta n1 Hacer
								Escribir AEA[i,j];
							FinPara
							Escribir '  ';
						FinPara
					SiNo
						Escribir ' LA MATRIZ A NO ES CUADRADA';
						Escribir ' NO SE PUEDE REALIZAR LA OPERACION';
					FinSi
				9:
					Escribir '******** FACTORIZACION LU ********';
				10:
					Escribir '******** FACTORIZACION LU ********';
				De Otro Modo:
					Escribir 'Error de dato de entrada';
			FinSegun
		FinSi
		Si adia=2 Entonces
			Escribir 'ENTONCES ';
		FinSi
		Si ((adia<>1) Y (adia<>2)) Entonces
			Escribir 'Error de dato de entrada...';
		FinSi
		Escribir '---------------------------------------------------------------';
		Escribir ' DESEA REALIZAR OPERACIONES ADICIONALES PARA B';
		Escribir '              1.- SI';
		Escribir '              2.- NO';
		Escribir ' INGRESE SU ELECCION:';
		Leer adib;
		Escribir ' ';
		Si adib=1 Entonces
			Escribir '********** OPERACIONES ADICIONALES **********';
			Escribir '       1.- Determinante';
			Escribir '       2.- Matriz inversa';
			Escribir '       3.- Matriz transpuesta';
			Escribir '       4.- Multiplicar por un escalar';
			Escribir '       5.- Rango';
			Escribir '       6.- Matriz Triangular';
			Escribir '       7.- Matriz Diagonal';
			Escribir '       8.- Matriz Elevada a...';
			Escribir '       9.- Factorizacion LU';
			Escribir '       10.- Factorizacion de Cholesky';
			Escribir '       11.- Valores y Vectores propios';
			Escribir '       12.- CONTINUAR';
			Escribir ' INGRESE SU ELECCION:';
			Leer extra;
			Escribir ' ';
			Escribir '---------------------------------------------------------------';
			Segun extra  Hacer
				1:
					Escribir '******** DETERMINANTE ********';
					Si m1=n1 Entonces
						Escribir ' LA DETERMINANTE DE LA MATRIZ B ES : ',DETB(MB,m2);
					SiNo
						Escribir 'LA MATRIZ B NO ES CUADRADA';
						Escribir 'POR TANTO NO SE PUEDE HALLAR LA DETERMINANTE';
					FinSi
				2:
					Escribir '******** MATRIZ INVERSA ********';
					Si m2=n2 Entonces
						Si ((DETB(MB,m2))<>0) Entonces
							Para i<-1 Hasta m2 Hacer
								Para j<-1 Hasta m2 Hacer
									Escribir INB[i,j];
								FinPara
								Escribir ' ';
							FinPara
						SiNo
							Escribir 'NO SE PUEDE HALLAR LA INVERSA, PORQUE LA DETERMINANTE ES CERO';
						FinSi
					SiNo
						Escribir 'LA MATRIZ B NO ES CUADRADA';
						Escribir 'POR TANTO NO SE PUEDE HALLAR LA DETERMINANTE, NI LA INVERSA';
					FinSi
				3:
					Escribir '******** MATRIZ TRANSPUESTA ********';
					Para i<-1 Hasta m2 Hacer
						Para j<-1 Hasta n2 Hacer
							Escribir MB[j,i];
						FinPara
						Escribir ' ';
					FinPara
				4:
					Escribir '******** MULTIPLICAR POR UN ESCALAR ********';
					Escribir ' POR FAVOR, INTRODUZCA UN ESCALAR PARA MULTIPLICAR A LA MATRIZ B';
					Leer escalar;
					Escribir ' ';
					Para i<-1 Hasta m2 Hacer
						Para j<-1 Hasta n2 Hacer
							OPBB[i,j]<-(escalar)*(MB[i,j]);
							Escribir OPBB[i,j];
						FinPara
						Escribir ' ';
					FinPara
				5:
					Escribir '******** RANGO ********';
					Escribir ' EL RANGO DE LA MATRIZ B ES : ';
					rango <- 0;
					Para i<-1 Hasta m2 Hacer
						Para j<-1 Hasta n2 Hacer
							Si MB[i,j]<>0 Entonces
								col <- col+1;
							FinSi
						FinPara
						Si col>=1 Entonces
							fil <- fil+1;
						FinSi
					FinPara
					rango <- fil; fil <- 0; col <- 0;
					Para j<-1 Hasta n2 Hacer
						Para i<-1 Hasta m2 Hacer
							Si MB[i,j]<>0 Entonces
								fil <- fil+1;
							FinSi
						FinPara
						Si fil>=1 Entonces
							col <- col+1;
						FinSi
					FinPara
					Si rango>=col Entonces
						rango <- col;
					SiNo
						Escribir rango;
					FinSi
				6:
					Escribir '******** MATRIZ TRIANGULAR ********';
					Para k<-1 Hasta n2-1 Hacer
						Para i<-1 Hasta m2 Hacer
							x <- MB[i+1,k];
							p <- 0;
							Si (k<i+1) Entonces
								Si ((MB[i+1,k])<>0) Entonces
									Para j<-k Hasta n2 Hacer
										Si p>=k Entonces
											MB[i+1,j]<-MB[i+1,j]-((x/MB[k,k])*MB[k,p]);
											p <- p+1;
										SiNo
											p <- k; q <- k+1;
											MB[i+1,j]<-MB[i+1,j]-((x/MB[k,q])*MB[k,q]);
											p <- p+1; q <- q+1;
										FinSi
									FinPara
								FinSi
							FinSi
						FinPara
					FinPara
					Para i<-1 Hasta m2 Hacer
						Para j<-1 Hasta n2 Hacer
							Escribir MB[i,j];
						FinPara
						Escribir ' ';
					FinPara
				7:
					Escribir '******** MATRIZ DIAGONAL ********';
				8:
					Escribir '******** MATRIZ ELEVADA A ********';
					Si ((m2=n2)) Entonces
						Repetir
							Escribir ' INTRODUZCA UN ENTERO A ELEVAR LA MATRIZ B';
							Escribir ' --> ';
							Leer elev;
						Hasta Que elev>=0
						Para i<-1 Hasta m2 Hacer
							Para j<-1 Hasta n2 Hacer
								Para k<-1 Hasta m2 Hacer
									OPBB[i,j]<-OPBB[i,j]+(MB[i,k]*MB[k,j]);
								FinPara
							FinPara
						FinPara
						Para i<-1 Hasta m2 Hacer
							Para j<-1 Hasta n2 Hacer
								AEB[i,j]<-OPBB[i,j];
								OPBB[i,j]<-0;
							FinPara
						FinPara
						Para l<-1 Hasta elev Hacer
							Para i<-1 Hasta m2 Hacer
								Para j<-1 Hasta n2 Hacer
									Para k<-1 Hasta m2 Hacer
										OPBB[i,j]<-OPBB[i,j]+(AEB[i,k]*MB[k,j]);
									FinPara
								FinPara
							FinPara
							Para i<-1 Hasta m2 Hacer
								Para j<-1 Hasta n2 Hacer
									AEB[i,j]<-OPBB[i,j];
									OPBB[i,j]<-0;
								FinPara
							FinPara
						FinPara
						Para i<-1 Hasta m2 Hacer
							Para j<-1 Hasta n2 Hacer
								Escribir AEB[i,j];
							FinPara
							Escribir '  ';
						FinPara
					SiNo
						Escribir ' LA MATRIZ A NO ES CUADRADA';
						Escribir ' NO SE PUEDE REALIZAR LA OPERACION';
					FinSi
				9:
					Escribir '******** FACTORIZACION LU ********';
				10:
					Escribir '******** FACTORIZACION LU ********';
				De Otro Modo:
					Escribir 'Error de dato de entrada';
			FinSegun
		FinSi
		Si adib=2 Entonces
			Escribir 'ENTONCES ';
		FinSi
		Si ((adib<>1) Y (adib<>2)) Entonces
			Escribir 'Error de dato de entrada...';
		FinSi
		Escribir 'DESEA REALIZAR OTRA OPERACION';
		Escribir 'Pulse N para salir de lo contrario pulse cualquiera';
		Leer op2;
	Hasta Que op2='n' O op2='N'
	Escribir ' ';
	Escribir 'GRACIAS...';
FinProceso

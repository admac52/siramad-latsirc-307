Proceso DCCV_2
	// 2. Problema del domino
	// <  >
	Definir i,j,k,a,b,c,elec,aux,aux2,rep,med,lecti,lectd,mano,giro,usar,new Como Entero;
	Definir xx,yy,posi,mesax,mesay,manox,manoy,usx,usy Como Entero;
	Dimension xx[100],yy[100],posi[100],mesax[100],mesay[100],manox[100],manoy[100];
	Definir op Como Caracter;
	Repetir
		Escribir ' BIENVENIDO A... ';
		Escribir '           EL JUEGO DEL DOMINO ';
		Escribir '---------------------------------------------';
		Escribir '  /////////////////////////////////////////////////////////////////////////////////////////////';
		Escribir '  //                                                                                         //';
		Escribir '  //                                                                                         //';
		Escribir '  //         SE TIENEN 28 FICHAS DE DOMINO COMO EN UN JUEGO REAL, LAS CUALES IRAN            //';
		Escribir '  //                                                                                         //';
		Escribir '  //        SALIENDO DE FORMA ALEATORIA LA CUAL DEBERA ACOMODAR POR EL LADO IZQUIERO         //';
		Escribir '  //                                                                                         //';
		Escribir '  //      O DERECHO DE LA PRIMERA FICHA DADA O TAMBIEN PEDIR UNA NUEVA SI ES NECESARIO.      //';
		Escribir '  //                                                                                         //';
		Escribir '  //         SE SABE QUE EL JUEGO TERMINA CUANDO SE TERMINAN LAS FICHAS DEL DOMINO.          //';
		Escribir '  //                                                                                         //';
		Escribir '  //                             ENTONCES QUE EMPIECE EL JUEGO                               //';
		Escribir '  //                                                                                         //';
		Escribir '  //                                                                                         //';
		Escribir '  /////////////////////////////////////////////////////////////////////////////////////////////';
		Para i<-1 Hasta 28 Hacer
			aux <- 1+Azar(28);
			aux2 <- 1;
			Mientras aux2<i Hacer
				Si (aux<>(posi[aux2])) Entonces
					aux2 <- aux2+1;
				SiNo
					aux <- 1+Azar(28);
					aux2 <- 1;
				FinSi
			FinMientras
			posi[i] <- aux;
			// Escribir Sin Saltar posi[i],"   "
		FinPara
		a <- 1;
		Para i<-0 Hasta 6 Hacer
			Para j<-0 Hasta i Hacer
				xx[a] <- i;
				a <- a+1;
			FinPara
		FinPara
		a <- 1;
		Para i<-0 Hasta 6 Hacer
			b <- 0;
			Para j<-0 Hasta i Hacer
				yy[a] <- b;
				b <- b+1;
				a <- a+1;
			FinPara
		FinPara
		Escribir ' '; // ces1
		rep <- 0; med <- 50; c <- 1;
		mesax[med] <- xx[posi[c]];
		mesay[med] <- yy[posi[c]];
		Escribir 'EN MESA...';
		Escribir '  /////////////////////////////////////////////////////////////////////////';
		Escribir ' ';
		Escribir ' ';
		Escribir '                                  [',xx[posi[c]],'|',yy[posi[c]],']';
		Escribir ' ';
		Escribir ' ';
		Escribir '  /////////////////////////////////////////////////////////////////////////';
		Escribir ' ';
		Escribir 'EN MANO...'; // ces2
		mano <- 1; c <- c+1;
		Escribir '========================================================================';
		Escribir ' [',xx[posi[c]],'|',yy[posi[c]],']';
		lecti <- 0; lectd <- 0;
		manox[mano] <- xx[posi[c]];
		manoy[mano] <- yy[posi[c]];
		Repetir
			rep <- rep+1;
			Escribir ' ____________________________';
			Escribir '| ******** ACCIONES ******** |';
			Escribir '|----------------------------|';
			Escribir '| 1.- Poner a la derecha     |';
			Escribir '| 2.- Poner a la izquierda   |';
			Escribir '| 3.- Pedir una ficha        |';
			Escribir '| 4.- Usar una que tengo     |';
			Escribir '| 5.- SALIR                  |';
			Escribir '|____________________________|';
			Escribir 'INGRESE SU ELECCION';
			Leer elec;
			Escribir ' ';
			Segun elec  Hacer
				1:
					lectd <- lectd+1;
					Escribir 'GIRAR LA FICHA';
					Escribir '1.- SI';
					Escribir '2.- NO';
					Leer giro;
					Si giro=1 Entonces
						mesay[med+lectd]<-xx[posi[c]];
						mesax[med+lectd]<-yy[posi[c]];
					FinSi
					Si giro=2 Entonces
						mesax[med+lectd]<-xx[posi[c]];
						mesay[med+lectd]<-yy[posi[c]];
					FinSi
					Si giro<>1 Y giro<>2 Entonces
						Escribir 'ERROR';
					FinSi
					Escribir 'EN MESA...';
					Escribir '  /////////////////////////////////////////////////////////////////////////';
					Escribir ' ';
					Para i<-med-lecti Hasta med+lectd Hacer
						Escribir ' [',mesax[i],'|',mesay[i],']' Sin Saltar;
					FinPara
					Escribir ' ';
					Escribir ' ';
					Escribir '  /////////////////////////////////////////////////////////////////////////';
					Escribir ' ';
					mano <- mano-1;
					Escribir 'EN MANO...';
					Escribir '========================================================================';
					Para i<-1 Hasta mano Hacer
						Escribir '[',manox[i],'|',manoy[i],'], ' Sin Saltar;
					FinPara
					Escribir ' ';
				2:
					lecti <- lecti+1;
					Escribir 'GIRAR LA FICHA';
					Escribir '1.- SI';
					Escribir '2.- NO';
					Leer giro;
					Si giro=1 Entonces
						mesay[med-lecti]<-xx[posi[c]];
						mesax[med-lecti]<-yy[posi[c]];
					FinSi
					Si giro=2 Entonces
						mesax[med-lecti]<-xx[posi[c]];
						mesay[med-lecti]<-yy[posi[c]];
					FinSi
					Si giro<>1 Y giro<>2 Entonces
						Escribir 'ERROR';
					FinSi
					Escribir 'EN MESA...';
					Escribir '  /////////////////////////////////////////////////////////////////////////';
					Escribir ' ';
					Para i<-med-lecti Hasta med+lectd Hacer
						Escribir ' [',mesax[i],'|',mesay[i],']' Sin Saltar;
					FinPara
					Escribir ' ';
					Escribir ' ';
					Escribir '  /////////////////////////////////////////////////////////////////////////';
					Escribir ' ';
					mano <- mano-1;
					Escribir 'EN MANO...';
					Escribir '========================================================================';
					Para i<-1 Hasta mano Hacer
						Escribir '[',manox[i],'|',manoy[i],'], ' Sin Saltar;
					FinPara
					Escribir ' ';
				3:
					c <- c+1; mano <- mano+1; // ces3
					manox[mano] <- xx[posi[c]];
					manoy[mano] <- yy[posi[c]];
					Escribir 'EN MESA...';
					Escribir '  /////////////////////////////////////////////////////////////////////////';
					Escribir ' ';
					Para i<-med-lecti Hasta med+lectd Hacer
						Escribir ' [',mesax[i],'|',mesay[i],']' Sin Saltar;
					FinPara
					Escribir ' ';
					Escribir ' ';
					Escribir '  /////////////////////////////////////////////////////////////////////////';
					Escribir ' ';
					Escribir 'EN MANO...';
					Escribir '========================================================================';
					Para i<-1 Hasta mano Hacer
						Si lectd+lecti<1 Entonces
							Escribir '[',manox[i],'|',manoy[i],'], ' Sin Saltar;
						SiNo
							Escribir '[',manox[i],'|',manoy[i],'], ' Sin Saltar;
						FinSi
					FinPara
					Escribir ' ';
				4:
					Escribir 'QUE NUMERO DE FICHA DESEA USAR';
					Leer usar;
					Para i<-1 Hasta mano Hacer
						Si i=usar Entonces
							usx <- manox[i];
							usy <- manoy[i];
							manox[i] <- manox[i+1];
							manoy[i] <- manoy[i+1];
						FinSi
					FinPara
					Escribir 'LA FICHA ES : [',usx,'|',usy,'], ';
					Escribir 'DESEA...';
					Escribir '1.- Poner a la derecha';
					Escribir '2.- Poner a la izquierda';
					Leer new;
					Si new=1 Entonces
						Escribir 'GIRAR LA FICHA';
						Escribir '1.- SI';
						Escribir '2.- NO';
						Leer giro;
						Si giro=1 Entonces
							mesay[med+lectd+1]<-usx;
							mesax[med+lectd+1]<-usy;
						FinSi
						Si giro=2 Entonces
							mesax[med+lectd+1]<-usx;
							mesay[med+lectd+1]<-usy;
						FinSi
						Si giro<>1 Y giro<>2 Entonces
							Escribir 'ERROR';
						FinSi
						Escribir 'EN MESA...';
						Escribir '  /////////////////////////////////////////////////////////////////////////';
						Escribir ' ';
						Para i<-med-lecti Hasta med+lectd+1 Hacer
							Escribir ' [',mesax[i],'|',mesay[i],']' Sin Saltar;
						FinPara
						Escribir ' ';
						Escribir ' ';
						Escribir '  /////////////////////////////////////////////////////////////////////////';
						Escribir ' ';
						mano <- mano-1;
						Escribir 'EN MANO...';
						Escribir '========================================================================';
						Para i<-1 Hasta mano Hacer
							Escribir '[',manox[i],'|',manoy[i],'], ' Sin Saltar;
						FinPara
						Escribir ' ';
						lectd <- lectd+1;
					FinSi
					Si new=2 Entonces
						Escribir 'GIRAR LA FICHA';
						Escribir '1.- SI';
						Escribir '2.- NO';
						Leer giro;
						Si giro=1 Entonces
							mesay[med-lecti-1]<-usx;
							mesax[med-lecti-1]<-usy;
						FinSi
						Si giro=2 Entonces
							mesax[med-lecti-1]<-usx;
							mesay[med-lecti-1]<-usy;
						FinSi
						Si giro<>1 Y giro<>2 Entonces
							Escribir 'ERROR';
						FinSi
						Escribir 'EN MESA...';
						Escribir '  /////////////////////////////////////////////////////////////////////////';
						Escribir ' ';
						Para i<-med-lecti-1 Hasta med+lectd Hacer
							Escribir ' [',mesax[i],'|',mesay[i],']' Sin Saltar;
						FinPara
						Escribir ' ';
						Escribir ' ';
						Escribir '  /////////////////////////////////////////////////////////////////////////';
						Escribir ' ';
						mano <- mano-1;
						Escribir 'EN MANO...';
						Escribir '========================================================================';
						Para i<-1 Hasta mano Hacer
							Escribir '[',manox[i],'|',manoy[i],'], ' Sin Saltar;
						FinPara
						Escribir ' ';
						lecti <- lecti+1;
					FinSi
					Si new<>1 Y new<>2 Entonces
						Escribir 'ERROR AL USO DE FICHA';
					FinSi
				5:
					Escribir ' ';
				De Otro Modo:
					Escribir 'Error, vuelva a ingresar';
			FinSegun
		Hasta Que elec=5
		Escribir 'QUIERE VOLVER A EMPEZAR EL JUEGO...';
		Escribir 'Pulse N para salir de lo contrario pulse cualquier tecla';
		Leer op;
	Hasta Que op='n' O op='N'
	Escribir 'GRACIAS POR JUGAR ';
FinProceso

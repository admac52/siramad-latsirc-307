
// 2. Problema del domino

#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int a,b,c,aux,aux2,elec,giro,lectd,lecti,mano,med,newn,rep,usar,usx,usy;
	int xx[100],yy[100],manox[100],manoy[100],mesax[100],mesay[100],posi[100];
	string op;

	do {
		cout<<"\n\t\t\t   -------------------------------------------------"<<endl;
		cout<<"\t\t\t  |                                                 |"<<endl;
		cout<<"\t\t\t  |\t\t     BIENVENIDO A...                |"<<endl;
		cout<<"\t\t\t  |                                                 |"<<endl;
		cout<<"\t\t\t  |\t\t  EL JUEGO DEL DOMINO               |"<<endl;
		cout<<"\t\t\t  |                                                 |"<<endl;
		cout<<"\t\t\t   -------------------------------------------------"<<endl<<endl;
		cout<<"\t/////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
		cout<<"\t//                                                                                         //"<<endl;
		cout<<"\t//                                                                                         //"<<endl;
		cout<<"\t//         SE TIENEN 28 FICHAS DE DOMINO COMO EN UN JUEGO REAL, LAS CUALES IRAN            //"<<endl;
		cout<<"\t//                                                                                         //"<<endl;
		cout<<"\t//        SALIENDO DE FORMA ALEATORIA LA CUAL DEBERA ACOMODAR POR EL LADO IZQUIERO         //"<<endl;
		cout<<"\t//                                                                                         //"<<endl;
		cout<<"\t//      O DERECHO DE LA PRIMERA FICHA DADA O TAMBIEN PEDIR UNA NUEVA SI ES NECESARIO.      //"<<endl;
		cout<<"\t//                                                                                         //"<<endl;
		cout<<"\t//         SE SABE QUE EL JUEGO TERMINA CUANDO SE TERMINAN LAS FICHAS DEL DOMINO.          //"<<endl;
		cout<<"\t//                                                                                         //"<<endl;
		cout<<"\t//                             ENTONCES QUE EMPIECE EL JUEGO                               //"<<endl;
		cout<<"\t//                                                                                         //"<<endl;
		cout<<"\t//                                                                                         //"<<endl;
		cout<<"\t/////////////////////////////////////////////////////////////////////////////////////////////"<<endl;
		// POSICIONES
		for (int i=1;i<=28;i++){
			aux=1+(rand()%28);
			aux2=1;
			while (aux2<i){
				if ((aux!=(posi[aux2]))){
					aux2=aux2+1;
				}else{
					aux=1+(rand()%28);
					aux2=1;
				}
			}
			posi[i]=aux;
			// Escribir Sin Saltar posi[i],"   ";
		}
		// LAS FICHAS
		a=1;
		for (int i=0;i<=6;i++) {
			for (int j=0;j<=i;j++) {
				xx[a]=i;
				a=a+1;
			}
		}
		a=1;
		for (int i=0;i<=6;i++) {
			b=0;
			for (int j=0;j<=i;j++) {
				yy[a]=b;
				b=b+1;
				a=a+1;
			}
		}cout<<"\n";cout<<"\n";
		// ces1
		rep=0;
		med=50;
		c=1;
		mesax[med]=xx[posi[c]];
		mesay[med]=yy[posi[c]];
		cout<<"\tEN MESA..."<<endl<<endl;
		cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
		cout<<"\t\t\t\t\t["<<xx[posi[c]]<<"|"<<yy[posi[c]]<<"]"<<endl<<endl<<endl;
		cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl;
		// ces2
		cout<<"\tEN MANO..."<<endl;
		mano=1;
		c=c+1;
		cout<<"\t========================================================================"<<endl;
		cout<<"\t["<<xx[posi[c]]<<"|"<<yy[posi[c]]<<"]"<<endl;
		cout<<"\t========================================================================"<<endl;
		lecti=0;
		lectd=0;
		manox[mano]=xx[posi[c]];
		manoy[mano]=yy[posi[c]];cout<<"\n";
		do {
			rep=rep+1;
			cout<<"\t\t\t ____________________________"<<endl;
			cout<<"\t\t\t| ******** ACCIONES ******** |"<<endl;
			cout<<"\t\t\t|----------------------------|"<<endl;
			cout<<"\t\t\t| 1.- Poner a la derecha     |"<<endl;
			cout<<"\t\t\t| 2.- Poner a la izquierda   |"<<endl;
			cout<<"\t\t\t| 3.- Pedir una ficha        |"<<endl;
			cout<<"\t\t\t| 4.- Usar una que tengo     |"<<endl;
			cout<<"\t\t\t| 5.- SALIR                  |"<<endl;
			cout<<"\t\t\t|____________________________|"<<endl<<endl;
			cout<<"\tINGRESE SU ELECCION"<<endl;
			cout<<"\t--> ";cin>>elec;
			cout<<"\n";cout<<"\n";
			switch (elec) {
			case 1:
				lectd=lectd+1;
				cout<<"\tGIRAR LA FICHA"<<endl;
				cout<<"\t\t1.- SI"<<endl;
				cout<<"\t\t2.- NO"<<endl<<endl;
				cout<<"\t--> ";cin>>giro;
				if (giro==1){
					mesay[med+lectd]=xx[posi[c]];
					mesax[med+lectd]=yy[posi[c]];
				}
				if (giro==2){
					mesax[med+lectd]=xx[posi[c]];
					mesay[med+lectd]=yy[posi[c]];
				}
				if (giro!=1 && giro!=2){
					cout<<"ERROR"<<endl;
				}
				cout<<"\tEN MESA..."<<endl<<endl;
				cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t";
				for (int i=med-lecti;i<=med+lectd;i++) {
					cout<<" ["<<mesax[i]<<"|"<<mesay[i]<<"]";
				}cout<<"\n";cout<<"\n";
				cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl;
				mano=mano-1;
				cout<<"\tEN MANO..."<<endl;
				cout<<"\t========================================================================"<<endl;cout<<"\t";
				for (int i=1;i<=mano;i++) {
					cout<<"["<<manox[i]<<"|"<<manoy[i]<<"], ";
				}cout<<"\n";
				cout<<"\t========================================================================"<<endl;
				cout<<"\n";
				break;
			case 2:
				lecti = lecti+1;
				cout<<"\tGIRAR LA FICHA"<<endl;
				cout<<"\t\t1.- SI"<<endl;
				cout<<"\t\t2.- NO"<<endl<<endl;
				cout<<"\t-->";cin >> giro;
				if (giro==1){
					mesay[med-lecti]=xx[posi[c]];
					mesax[med-lecti]=yy[posi[c]];
				}
				if (giro==2){
					mesax[med-lecti]=xx[posi[c]];
					mesay[med-lecti]=yy[posi[c]];
				}
				if (giro!=1 && giro!=2){
					cout<<"ERROR"<<endl;
				}
				cout<<"\tEN MESA..."<<endl<<endl;
				cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t";
				for (int i=med-lecti;i<=med+lectd;i++){
					cout<<" ["<<mesax[i]<<"|"<<mesay[i]<<"]";
				}cout<<"\n";cout<<"\n";
				cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl;
				mano= mano-1;
				cout<<"\tEN MANO..." << endl;
				cout<<"\t========================================================================"<<endl;cout<<"\t";
				for (int i=1;i<=mano;i++) {
					cout << "[" << manox[i] << "|" << manoy[i] << "], ";
				}cout<<"\n";
				cout<<"\t========================================================================"<<endl;
				cout<<"\n";
				break;
			case 3:
				// ces3
				c = c+1;
				mano = mano+1;
				manox[mano] = xx[posi[c]];
				manoy[mano] = yy[posi[c]];
				cout<<"\tEN MESA..."<<endl<<endl;
				cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
				cout<<"\t\t\t\t\t";
				for (int i=med-lecti;i<=med+lectd;i++){
					cout<<" ["<<mesax[i]<<"|"<<mesay[i]<<"]";
				}cout<<"\n";cout<<"\n";
				cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl;
				cout<<"\tEN MANO..."<<endl;
				cout<<"\t========================================================================"<<endl;cout<<"\t";
				for (int i=1;i<=mano;i++){
					if (lectd+lecti<1) {
						cout<<"["<<manox[i]<<"|"<<manoy[i]<<"], ";
					}else{
						cout<<"["<<manox[i]<<"|"<<manoy[i]<<"], ";
					}
				}cout<<"\n";
				cout<<"\t========================================================================"<<endl;
				cout<<"\n";
				break;
			case 4:
				cout<<"\tQUE NUMERO DE FICHA DESEA USAR"<<endl;
				cout<<"\t--> ";cin >> usar;
				for (int i=1;i<=mano;i++){
					if (i==usar){
						usx=manox[i];
						usy=manoy[i];
						manox[i]=manox[i+1];
						manoy[i]=manoy[i+1];
					}
				}
				cout<<"   LA FICHA ES : ["<<usx<<"|"<<usy<<"], "<<endl;
				cout<<"\tDESEA..."<<endl;
				cout<<"\t\t1.- Poner a la derecha"<<endl;
				cout<<"\t\t2.- Poner a la izquierda"<<endl<<endl;
				cout<<"\t--> ";cin>>newn;
				if (newn==1){
					cout<<"\tGIRAR LA FICHA"<<endl;
					cout<<"\t\t1.- SI"<<endl;
					cout<<"\t\t2.- NO"<<endl<<endl;
					cout<<"\t--> ";cin>>giro;
					if (giro==1) {
						mesay[med+lectd+1] = usx;
						mesax[med+lectd+1] = usy;
					}
					if (giro==2) {
						mesax[med+lectd+1] = usx;
						mesay[med+lectd+1] = usy;
					}
					if (giro!=1 && giro!=2) {
						cout << "ERROR" << endl;
					}
					cout<<"\tEN MESA..."<<endl<<endl;
					cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
					cout<<"\t\t\t\t\t";
					for (int i=med-lecti;i<=med+lectd+1;i++) {
						cout << " [" << mesax[i] << "|" << mesay[i] << "]";
					}cout<<"\n";cout<<"\n";
					cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl;
					mano = mano-1;
					cout<<"\tEN MANO..."<<endl;
					cout<<"\t========================================================================"<<endl;cout<<"\t";
					for (int i=1;i<=mano;i++){
						cout<<"["<<manox[i]<<"|"<<manoy[i]<<"], ";
					}cout<<"\n";
					cout<<"\t========================================================================"<<endl;
					cout<<"\n";
					lectd = lectd+1;
				}cout<<"\n";
				if (newn==2){
					cout<<"\tGIRAR LA FICHA"<<endl;
					cout<<"\t\t1.- SI"<<endl;
					cout<<"\t\t2.- NO"<<endl<<endl;
					cout<<"\t--> ";cin>>giro;
					if (giro==1){
						mesay[med-lecti-1] = usx;
						mesax[med-lecti-1] = usy;
					}
					if (giro==2){
						mesax[med-lecti-1]=usx;
						mesay[med-lecti-1]=usy;
					}
					if (giro!=1 && giro!=2){
						cout<<"ERROR"<<endl;
					}
					cout<<"\tEN MESA..."<<endl<<endl;
					cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl<<endl;
					cout<<"\t\t\t\t\t";
					for (int i=med-lecti-1;i<=med+lectd;i++) {
						cout<<" ["<<mesax[i]<<"|"<<mesay[i]<<"]";
					}cout<<"\n";cout<<"\n";
					cout<<"\t/////////////////////////////////////////////////////////////////////////"<<endl<<endl;
					mano=mano-1;
					cout<<"\tEN MANO..."<<endl;
					cout<<"\t========================================================================"<<endl;cout<<"\t";
					for (int i=1;i<=mano;i++) {
						cout << "[" << manox[i] << "|" << manoy[i] << "], ";
					}cout<<"\n";
					cout<<"\t========================================================================"<<endl;
					cout<<"\n";
					lecti = lecti+1;
				}
				if (newn!=1 && newn!=2) {
					cout << "ERROR AL USO DE FICHA" << endl;
				}
				break;
			case 5:{cout<<"\n";
				break;
			}
			default:
				cout<<"Error, vuelva a ingresar"<<endl;
			}
		} while (elec!=5);
		cout<<"  QUIERE VOLVER A EMPEZAR EL JUEGO..."<<endl;
		cout<<"  Pulse N para salir de lo contrario pulse cualquier tecla"<<endl;
		cin>>op;
	} while (!(op=="n" || op=="N"));
	cout<<"  GRACIAS POR JUGAR "<<endl;
	return 0;
}


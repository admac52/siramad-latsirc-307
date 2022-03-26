// 3.- Debe realizar un programa en c++ y leer un archivo csv y contestar las siguientes preguntas, grabandolas en un archivo

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#define MAX 10000

using namespace std;

void Agregar();

struct texto{
	string num,passenger,survived,pclass,name,ex,sex,age,sibsp,parch,ticket,fare,cabin,embarked;

}registro[MAX];

int c=1;
int hombres=0,mujeres=0,ninos=0,joven=0,mayor=0,senio=0,mast=0,sobre=0;

int main()
{
    ifstream archivo("titanic.csv");
    string linea;
    char delimitador = ',';
    getline(archivo, linea);
    cout<<"==============================================================================================================================================================="<<endl;
    cout<<"NUM\tPSS\tSURV\tPCL\t\t\tNAME\t\t\tSEX\tAGE\tSIB\tPARCH\tTICK\tFARE\tCAB\tEMBrked"<<endl;
    cout<<"==============================================================================================================================================================="<<endl;
    while (getline(archivo, linea)){
        stringstream stream(linea);

        getline(stream, registro[c].num, delimitador);
        getline(stream, registro[c].passenger, delimitador);
        getline(stream, registro[c].survived, delimitador);
        	for(int i=0;i<=0;i++){
		    	if(((registro[c].survived)[i])=='1'){
		        	sobre=sobre+1;
				}
			}
        getline(stream, registro[c].pclass, '"');
        getline(stream, registro[c].name, '"');
        getline(stream, registro[c].ex, delimitador);
        getline(stream, registro[c].sex, delimitador);
	        for(int i=0;i<=0;i++){
	        	//cout<<registro[c].sex[i]<<"\t";
		    	if(((registro[c].sex)[i])=='m'){
		        	hombres=hombres+1;
				}else{
					mujeres=mujeres+1;
				}
			}
        getline(stream, registro[c].age, delimitador);
        	for(int i=1;i<=1;i++){
		    	if((registro[c].age[i-1])=='1'){
		        	if(((registro[c].age[i])=='.') or ((registro[c].age[i])=='0') or ((registro[c].age[i])=='1') or ((registro[c].age[i])=='2') or ((registro[c].age[i])=='3') or ((registro[c].age[i])=='4') or ((registro[c].age[i])=='5')){
						ninos=ninos+1;
					}
				}
				if((registro[c].age[i-1])=='1'){
					if(((registro[c].age[i])=='5') or ((registro[c].age[i])=='6') or ((registro[c].age[i])=='7') or ((registro[c].age[i])=='8') or ((registro[c].age[i])=='9')){
			        	joven=joven+1;
					}
				}
				if((registro[c].age[i-1])=='2'){
					if(((registro[c].age[i])=='1')){
			        	joven=joven+1;
					}
				}
				if((registro[c].age[i-1])=='2'){
					if(((registro[c].age[i])=='2') or ((registro[c].age[i])=='3') or ((registro[c].age[i])=='4') or ((registro[c].age[i])=='5') or ((registro[c].age[i])=='6') or ((registro[c].age[i])=='7') or ((registro[c].age[i])=='8') or ((registro[c].age[i])=='9')){
			        	mayor=mayor+1;
					}
				}
				if((registro[c].age[i-1])=='3'){
					mayor=mayor+1;
				}
				if((registro[c].age[i-1])=='4'){
					if(((registro[c].age[i])=='0')){
			        	mayor=mayor+1;
					}
				}
				if((registro[c].age[i-1])=='4'){
					senio=senio+21;
				}
				if((registro[c].age[i-1])=='5'){
					senio=senio+21;
				}
				if((registro[c].age[i-1])=='6'){
					if(((registro[c].age[i])=='0')){
						senio=senio+21;
					}
				}
				if(((registro[c].age[i-1])=='6') or ((registro[c].age[i-1])=='7') or ((registro[c].age[i-1])=='8') or ((registro[c].age[i-1])=='9') or ((registro[c].age[i+1])=='0')){
					mast=mast+21;
				}
			}
        getline(stream, registro[c].sibsp, delimitador);
        getline(stream, registro[c].parch, delimitador);
        getline(stream, registro[c].ticket, delimitador);
        getline(stream, registro[c].fare, delimitador);
        getline(stream, registro[c].cabin, delimitador);
        getline(stream, registro[c].embarked, delimitador);
        
        //cout<<registro[c].num<<"\t";
        //cout<<registro[c].passenger<<"\t";
        //cout<<registro[c].survived<<"\t";
        //cout<<registro[c].pclass<<"\t";
        //cout<<registro[c].name<<"\t\t\t";
        //cout<<registro[c].sex<<"\t";
		//cout<<registro[c].age<<"\t";
        //cout<<registro[c].sibsp<<"\t";
		//cout<<registro[c].parch<<"\t";
		//cout<<registro[c].ticket<<"\t";
		//cout<<registro[c].fare<<"\t";
		//cout<<registro[c].cabin<<"\t";
		//cout<<registro[c].embarked<<endl;
		
        c=c+1;
    }
    
    archivo.close();
    cout<<"\n\n\tSE TIENE UN TOTAL DE "<<c-1<<" BASES DE DATOS"<<endl;
    
    cout<<"  LOS RESULTADOS SON LOS SIGUIENTES: "<<endl<<endl;
    cout<<"\t___________________________________________________"<<endl;
    cout<<"\t|                                                 |"<<endl;
    cout<<"\t|\ta) TOTAL HOMBRES =                "<<hombres<<"     |"<<endl;
    cout<<"\t|\tb) TOTAL MUJERES =                "<<mujeres<<"     |"<<endl;
    cout<<"\t|\tc) TOTAL NINIOS HASTA 15 ANIOS =  "<<ninos<<"      |"<<endl;
    cout<<"\t|\td) TOTAL JOVENES 15-21 ANIOS =    "<<joven<<"     |"<<endl;
    cout<<"\t|\te) TOTAL MAYORES DE 22-40 ANIOS = "<<mayor<<"     |"<<endl;
    cout<<"\t|\tf) TOTAL SENIOR DE 40-60  =       "<<senio<<"    |"<<endl;
    cout<<"\t|\tg) TOTAL MASTERS 70-100 =         "<<mast<<"    |"<<endl;
    cout<<"\t|\th) TOTAL SOBREVIVIENTES =         "<<sobre<<"     |"<<endl;
    cout<<"\t|_________________________________________________|"<<endl;
    
    Agregar();
    system("pause");
    
    return 0;
}
void Agregar(){
	
	ofstream archivo;
	archivo.open("titanic.txt",ios::app);
	
	if(archivo.fail()){
		cout<<"ERROR EN EL ACCESO AL ARCHIVO"<<endl;
		exit(1);
	}
	
	archivo<<"\n\n\tSE TIENE UN TOTAL DE "<<c-1<<" BASES DE DATOS"<<endl;
    
    archivo<<"  LOS RESULTADOS SON LOS SIGUIENTES: "<<endl<<endl;
    archivo<<"\t___________________________________________________"<<endl;
    archivo<<"\t|                                                 |"<<endl;
    archivo<<"\t|\ta) TOTAL HOMBRES =                "<<hombres<<"     |"<<endl;
    archivo<<"\t|\tb) TOTAL MUJERES =                "<<mujeres<<"     |"<<endl;
    archivo<<"\t|\tc) TOTAL NINIOS HASTA 15 ANIOS =  "<<ninos<<"      |"<<endl;
    archivo<<"\t|\td) TOTAL JOVENES 15-21 ANIOS =    "<<joven<<"     |"<<endl;
    archivo<<"\t|\te) TOTAL MAYORES DE 22-40 ANIOS = "<<mayor<<"     |"<<endl;
    archivo<<"\t|\tf) TOTAL SENIOR DE 40-60  =       "<<senio<<"    |"<<endl;
    archivo<<"\t|\tg) TOTAL MASTERS 70-100 =         "<<mast<<"    |"<<endl;
    archivo<<"\t|\th) TOTAL SOBREVIVIENTES =         "<<sobre<<"     |"<<endl;
    archivo<<"\t|_________________________________________________|"<<endl;
	
	archivo.close();
}
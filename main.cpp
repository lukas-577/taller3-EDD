#include <iostream>
#include "dosis.h"
#include "run.h"
#include "fecha.h"
#include "fechaActual.h"
#include "paciente.h"
#include "inoculacion.h"
#include "lista.h"
#include "lista2.h"
#include "lista3.h"
#include <time.h>
#include <fstream> //lectura y escritura de archivos
#include <sstream>
#include <vector> //para usar vector 
#include <string>

const char *arreglo [12]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","septiembre","octubre ","noviembre", "diciembre"};

struct arreglo  {
  string fechaNacimiento;
  string paterno;
  string materno;
  string nombre;
  string rut;
  string genero;

};

using namespace std;

string nombre_archivo = "pacientes.csv";

vector<string> split(string lineaASeparar, char delimitador) 
{
    vector<string> vector_interno;
    stringstream linea(lineaASeparar);
    string parteDelString;
    while(getline(linea, parteDelString, delimitador))
    {
      vector_interno.push_back(parteDelString);
    }
    return vector_interno;

}


int mes_correspondiente(string fecha){
    if(fecha=="enero")
        return 1;
    else if(fecha=="febrero")
        return 2;
    else if(fecha=="marzo")
        return 3;
    else if(fecha=="abril")
        return 4;
    else if(fecha=="mayo")
        return 5;
    else if(fecha=="junio")
        return 6;
    else if(fecha=="julio") 
        return 7;
    else if(fecha=="agosto")
        return 8;
    else if(fecha=="septiembre")
        return 9;
    else if(fecha=="octubre")
        return 10;
    else if(fecha=="noviembre")
        return 11;
    else if(fecha=="diciembre")
        return 12;
    return 0;                              
}


//Lista2 & todos_los_datos

void leeProcesa(string nombre_archivo,Lista2 & todos_los_datos,int & total,int & cantidad){
  ifstream archivo;
  archivo.open (nombre_archivo.c_str (), ios::in);
  vector<struct arreglo> arreg;
  int contador=0;
  int j=0;
  if(archivo.is_open()){
    string linea;
    bool primeraLinea = true;
    while(getline(archivo,linea,'\n')){
      struct arreglo aux;
      if(!primeraLinea){
        stringstream ss (linea);
        string temp;
        contador++;
        //con este for separo las columnas para guardarlo en cada nodo
        for(int columna=0;getline(ss,temp,',');columna++){
          if(columna==0){
            aux.rut=temp;
            //nuevo->paciente.setRun(temp);
            //cout<<nuevo->inoculacion<<endl;
          }
          if(columna==1){
            aux.paterno=temp;
            //nuevo->paciente.setNombresApellidos(temp);
          }
          if(columna==2){
            aux.materno=temp;
            //nuevo->paciente.setNombresApellidos(temp);
          }
          if(columna==3){
            aux.nombre=temp;
            //nuevo->paciente.setFechaDeNacimiento(Fecha());
            //nuevo->numero_de_camas= atoi(temp.c_str());
            //cout<<nuevo->numero_de_camas<<endl;
          }
          if(columna==4){
            aux.genero=temp;
            //nuevo->paciente.setNombresApellidos(temp);
          }
          if(columna==5){
            aux.fechaNacimiento=temp;
            //nuevo->paciente.setNombresApellidos(temp);
          }
        }
        arreg.push_back(aux);
        //nuevo->sgte=NULL;
      }
      if(primeraLinea){ 
        primeraLinea = false;
        }
    }
    for(vector< struct arreglo>::iterator i=arreg.begin();i!=arreg.end();i++){
      vector<string> vectorSepara = split(i->fechaNacimiento,'-');
      //cout<<i->fechaNacimiento<<endl;
      int mesInt= mes_correspondiente(vectorSepara.at(1));
      int dia = stoi(vectorSepara.at(0));
      int anho = stoi(vectorSepara.at(2));
      //cout<<"validando Fecha: "<<validarFecha(vectorSepara)<<endl;
      Fecha fecha;

      fecha.setDia(dia);
      fecha.setMes(mesInt);
      fecha.setAnho(anho);


      vector<string> vectorSeparaRun = split(i->rut,'-');

      //cout<<i->rut<<endl;
      //cout<<"validando Run: "<<runValido(vectorSeparaRun)<<endl;
      if(validarFecha(vectorSepara)==true&&runValido(vectorSeparaRun)==true){
        //cout<<"agregar ala lista"<<contador<<endl;
       
            Lista2 lista;
            Lista2 nuevo = new(struct nodo2);
            nuevo->paciente.setRun(i->rut);
            nuevo->paciente.setNombre(i->nombre);
            nuevo->paciente.setMaterno(i->materno);
            nuevo->paciente.setPaterno(i->paterno);
            nuevo->paciente.setGenero(i->genero);
            nuevo->paciente.setFechaDeNacimiento(fecha);
            nuevo->sgte=NULL;

            nuevo->sgte=todos_los_datos;
            todos_los_datos=nuevo;

            j++;
            
        }
      

      cantidad=j;
    }
    total=contador;
     cout <<"Se han procesado "<< contador << " registros"<<endl;
  }else {
        cout << "Error en la apertura del archivo "+nombre_archivo;
    }
  archivo.close();//cerramos el archivo

}


void imprimir_lista_sinVacunar (Lista2  lista)
{
  // con variable auxiliar
  Lista2 q;			// otra variable, para copiar la lista
  q = lista;			// hago que q sea una copia de lista
  while (q != NULL)   
    {
      if(q->paciente.getEstadoVacunacion()==1){
        cout<<"------------------------"<<endl;
        cout << "Sin vacunar"<<endl;
        q->paciente.mostrarPaciente();
        cout<<"------------------------"<<endl;
        
      }
      q = q->sgte;
    }
}



//solo de preuba
//para verificar si estan los datos cargados en los nodos
void imprimir_lista_sinPerderDatos (Lista2 & lista)
{
  // con variable auxiliar
  Lista2 q;			// otra variable, para copiar la lista
  q = lista;			// hago que q sea una copia de lista
  while (q != NULL)   
    {
      cout<<"------------------------"<<endl;
      cout << "LLS2"<<endl;
      q->paciente.mostrarPaciente();
      cout<<"------------------------"<<endl;
      q = q->sgte;
    }
}


//solo de preuba
void imprimir_lista_sinPerderDatosEdad (Lista2 & lista)
{
  // con variable auxiliar
  Lista2 q;			// otra variable, para copiar la lista
  q = lista;			// hago que q sea una copia de lista
  while (q != NULL)   
    {
      cout<<"------------------------"<<endl;
      cout << "LLS2"<<endl;
      q->paciente.edad();
      cout<<"------------------------"<<endl;
      q = q->sgte;
    }
}


//solo de preuba
void imprimir_lista_sinPerderDatos (Lista3 & lista)
{
  // con variable auxiliar
  Lista3 q;			// otra variable, para copiar la lista
  q = lista;			// hago que q sea una copia de lista
  while (q != NULL)   
    {
      cout<<"------------------------"<<endl;
      cout << "LLS3"<<endl;
      q->dosis.mostrar();
      cout<<"------------------------"<<endl;
      q = q->sgte;
    }
}



void CrearDosis(Lista3 &L)
{
   Lista3 dosis;
   dosis=L;
   string dosis1,dosis2,dosis3;
   int numeroIdentificador=10000;
   dosis1="Sinovac";
   dosis2="Pfizer";
   dosis3="Aztrazeneca";
   
   for(int j=1;j<=90;j++)
   {
    numeroIdentificador=numeroIdentificador+3;
    dosis = new ( struct nodo3);
    dosis->dosis.setTipoVacuna(dosis1);
    dosis->dosis.setEdadMin(18);
    dosis->dosis.setEdadMax(80);
    dosis->dosis.setNumeroIdentificador(numeroIdentificador);
    dosis->dosis.setUtilizada(true);
    dosis->sgte = L;
    L = dosis;
   }
   for(int j=91;j<=210;j++)
   {
    numeroIdentificador=numeroIdentificador+5;
    dosis = new (struct nodo3);
    dosis->dosis.setTipoVacuna(dosis2);
    dosis->dosis.setEdadMin(15);
    dosis->dosis.setEdadMax(55);
    dosis->dosis.setNumeroIdentificador(numeroIdentificador);
    dosis->dosis.setUtilizada(true);
    dosis->sgte = L;
    L = dosis;
   }
   for(int j=211;j<281;j++)
   {
    dosis = new (struct nodo3);
    dosis->dosis.setTipoVacuna(dosis3);
    dosis->dosis.setEdadMin(18);
    dosis->dosis.setEdadMax(120);
    dosis->dosis.setNumeroIdentificador(numeroIdentificador);
    dosis->dosis.setUtilizada(true);
    dosis->sgte = L;
    L = dosis;
   }
}


void iniciarVacunacion(Lista & L,Lista2  L2, Lista3 & L3){
int Pfizer=0,Sinovac=0,Astrazeneca=0;
int rango1=0,rango2=0,rango3=0,rango4=0,rango5=0;
  while(L2!=NULL){
    bool vacunado=false;
    //trabajo con la copia 
    Lista3 p=L3;
    Lista ino=NULL;
    do{
      if(p->dosis.getTipoVacuna()=="Sinovac"){
        if(p->dosis.getEdadMin()<=L2->paciente.edad()&&p->dosis.getEdadMax()>=L2->paciente.edad()&&p->dosis.getUtilizada()==true){
          p->dosis.setUtilizada(false);
          L2->paciente.setEstadoVacunacion(0);
          Paciente auxPaciente;
          Dosis auxDosis;
          auxPaciente.setNombre(L2->paciente.getNombre());
          auxPaciente.setMaterno(L2->paciente.getMaterno());
          auxPaciente.setPaterno(L2->paciente.getPaterno());
          auxPaciente.setGenero(L2->paciente.getGenero());
          auxPaciente.setRun(L2->paciente.getRun());
          auxDosis.setTipoVacuna(p->dosis.getTipoVacuna());
          auxDosis.setEdadMin(p->dosis.getEdadMin());
          auxDosis.setEdadMax(p->dosis.getEdadMax());
          auxDosis.setNumeroIdentificador(p->dosis.getNumeroIdentificador());
          auxDosis.setUtilizada(p->dosis.getUtilizada()); 
          ino=new(struct nodo);
          ino->inoculacion.setPaciente(auxPaciente);
          ino->inoculacion.setDosisAplicada(auxDosis);
          ino->inoculacion.setFechaActual(fechaYHora());
          ino->sgte=L;
          L=ino;

          Sinovac++;
          if(L2->paciente.edad()>=0&&L2->paciente.edad()<=18){
            rango1++;
          }
          if(L2->paciente.edad()>=19&&L2->paciente.edad()<=25){
            rango2++;
          }
          if(L2->paciente.edad()>=25&&L2->paciente.edad()<=35){
            rango3++;
          }
          if(L2->paciente.edad()>=45&&L2->paciente.edad()<=65){
            rango4++;
          }
          if(L2->paciente.edad()>65){
            rango4++;
          }
          vacunado=true;
         
        }else{
          p=p->sgte;
        }
      }else if(p->dosis.getTipoVacuna()=="Pfizer"){
        if(p->dosis.getEdadMin()<=L2->paciente.edad()&&p->dosis.getEdadMax()>=L2->paciente.edad()&&p->dosis.getUtilizada()==true){
          p->dosis.setUtilizada(false);
          L2->paciente.setEstadoVacunacion(0);
          Paciente auxPaciente;
          Dosis auxDosis;
          auxPaciente.setNombre(L2->paciente.getNombre());
          auxPaciente.setMaterno(L2->paciente.getMaterno());
          auxPaciente.setPaterno(L2->paciente.getPaterno());
          auxPaciente.setGenero(L2->paciente.getGenero());
          auxPaciente.setRun(L2->paciente.getRun());
          auxDosis.setTipoVacuna(p->dosis.getTipoVacuna());
          auxDosis.setEdadMin(p->dosis.getEdadMin());
          auxDosis.setEdadMax(p->dosis.getEdadMax());
          auxDosis.setNumeroIdentificador(p->dosis.getNumeroIdentificador());
          auxDosis.setUtilizada(p->dosis.getUtilizada()); 

          ino=new(struct nodo);
          ino->inoculacion.setPaciente(auxPaciente);
          ino->inoculacion.setDosisAplicada(auxDosis);
          ino->inoculacion.setFechaActual(fechaYHora());
          ino->sgte=L;
          L=ino;

          Pfizer++;
          if(L2->paciente.edad()>=0&&L2->paciente.edad()<=18){
            rango1++;
          }
          if(L2->paciente.edad()>=18&&L2->paciente.edad()<=25){
            rango2++;
          }
          if(L2->paciente.edad()>=25&&L2->paciente.edad()<=35){
            rango3++;
          }
          if(L2->paciente.edad()>=45&&L2->paciente.edad()<=65){
            rango4++;
          }
          if(L2->paciente.edad()>65){
            rango5++;
          }
          vacunado=true;
      }else{
        p=p->sgte;
      }
    }else{
      if(L2->paciente.getGenero()=="h"){
        if(p->dosis.getEdadMin()<=L2->paciente.edad()&&p->dosis.getEdadMax()>=L2->paciente.edad()&&p->dosis.getUtilizada()==true){
          p->dosis.setUtilizada(false);
          L2->paciente.setEstadoVacunacion(0);
          Paciente auxPaciente;
          Dosis auxDosis;
          auxPaciente.setNombre(L2->paciente.getNombre());
          auxPaciente.setMaterno(L2->paciente.getMaterno());
          auxPaciente.setPaterno(L2->paciente.getPaterno());
          auxPaciente.setGenero(L2->paciente.getGenero());
          auxPaciente.setRun(L2->paciente.getRun());
          auxDosis.setTipoVacuna(p->dosis.getTipoVacuna());
          auxDosis.setEdadMin(p->dosis.getEdadMin());
          auxDosis.setEdadMax(p->dosis.getEdadMax());
          auxDosis.setNumeroIdentificador(p->dosis.getNumeroIdentificador());
          auxDosis.setUtilizada(p->dosis.getUtilizada()); 
          ino=new(struct nodo);
          ino->inoculacion.setPaciente(auxPaciente);
          ino->inoculacion.setDosisAplicada(auxDosis);
          ino->inoculacion.setFechaActual(fechaYHora());
          ino->sgte=L;
          L=ino;
          Astrazeneca++;
          if(L2->paciente.edad()>=0&&L2->paciente.edad()<=18){
            rango1++;
          }
          if(L2->paciente.edad()>=19&&L2->paciente.edad()<=25){
            rango2++;
          }
          if(L2->paciente.edad()>=25&&L2->paciente.edad()<=35){
            rango3++;
          }
          if(L2->paciente.edad()>=45&&L2->paciente.edad()<=65){
            rango4++;
          }
          if(L2->paciente.edad()>65){
            rango5++;
          }
          vacunado=true;

        }else{
          p=p->sgte;
        }
      }else if(L2->paciente.getGenero()=="f"){
        if(41<=L2->paciente.edad()&&p->dosis.getEdadMax()>=L2->paciente.edad()&&p->dosis.getUtilizada()==true){
          p->dosis.setUtilizada(false);
          L2->paciente.setEstadoVacunacion(0);
          Paciente auxPaciente;
          Dosis auxDosis;
          auxPaciente.setNombre(L2->paciente.getNombre());
          auxPaciente.setMaterno(L2->paciente.getMaterno());
          auxPaciente.setPaterno(L2->paciente.getPaterno());
          auxPaciente.setGenero(L2->paciente.getGenero());
          auxPaciente.setRun(L2->paciente.getRun());
          auxDosis.setTipoVacuna(p->dosis.getTipoVacuna());
          auxDosis.setEdadMin(p->dosis.getEdadMin());
          auxDosis.setEdadMax(p->dosis.getEdadMax());
          auxDosis.setNumeroIdentificador(p->dosis.getNumeroIdentificador());
          auxDosis.setUtilizada(p->dosis.getUtilizada()); 
          ino=new(struct nodo);
          ino->inoculacion.setPaciente(auxPaciente);
          ino->inoculacion.setDosisAplicada(auxDosis);
          ino->inoculacion.setFechaActual(fechaYHora());
          ino->sgte=L;
          L=ino;
          Astrazeneca++;
          if(L2->paciente.edad()>=0&&L2->paciente.edad()<=18){
            rango1++;
          }
          if(L2->paciente.edad()>=19&&L2->paciente.edad()<=25){
            rango2++;
          }
          if(L2->paciente.edad()>=25&&L2->paciente.edad()<=35){
            rango3++;
          }
          if(L2->paciente.edad()>=45&&L2->paciente.edad()<=65){
            rango4++;
          }
          if(L2->paciente.edad()>65){
            rango5++;
          }
          vacunado=true;
        }else{
          p=p->sgte;
        }
      }
    }
  }while(p != NULL &&vacunado == false);

  L2=L2->sgte;

}
cout<<"La vacunacion se a realizado con exito"<<endl<<endl;
cout<<"Datos obtenidos"<<endl<<endl;
cout<<"1-Cantidad de dosis utilizada por vacuna: "<<endl;
cout<<"Sinovac: "<<Sinovac<<endl;
cout<<"Pfizer: "<<Pfizer<<endl;
cout<<"Astrazeneca: "<<Astrazeneca<<endl<<endl;
cout<<"2-Cantidad de dosis disponibles por tipo de vacuna: "<<endl<<endl;
cout<<"Sinovac: "<<90-Sinovac<<endl;
cout<<"Pfizer: "<<120-Pfizer<<endl;
cout<<"Astrazeneca: "<<70-Astrazeneca<<endl<<endl;
cout<<"3-Cantidad de vacunas segun rango etario disponible"<<endl;
cout<<"0 a 18 anhos: "<<rango1<<endl;
cout<<"19 a 25 anhos: "<<rango2<<endl;
cout<<"25 a 35 anhos: "<<rango3<<endl;
cout<<"45 a 65 anhos: "<<rango4<<endl;
cout<<"mayors a 65 anhos: "<<rango5<<endl;



}


void buscarPaciente(string x,Lista2 L2,Lista L){
  bool aux=false;
  while(L2!=NULL&& L!=NULL&&aux==false){
    if(x==L2->paciente.getRun().getRun()&&L2->paciente.getEstadoVacunacion()==1){
      cout<<"Nombre: "<<L2->paciente.getNombre()<<endl;
      cout<<"Apellidos: "<<L2->paciente.getMaterno()<<" "<<L2->paciente.getPaterno()<<endl;
      cout<<"Rut: "<<L2->paciente.getRun().getRun()<<endl;
      cout<<"Fecha de nacimiento: "<<L2->paciente.getFechaDeNacimiento().getDia()<<"/"<<L2->paciente.getFechaDeNacimiento().getMes()<<"/"<<L2->paciente.getFechaDeNacimiento().getAnho()<<endl;
      cout<<"Paciente no vacunado"<<endl;
      aux=true;
    }else if(x==L->inoculacion.getPaciente().getRun().getRun()){
      cout<<"Nombre: "<<L->inoculacion.getPaciente().getNombre()<<endl;
      cout<<"Apellidos: "<<L->inoculacion.getPaciente().getMaterno()<<""<<L->inoculacion.getPaciente().getPaterno()<<endl;
      cout<<"Rut: "<<L->inoculacion.getPaciente().getRun().getRun()<<endl;
      cout<<"Fecha de nacimiento: "<<L->inoculacion.getPaciente().getFechaDeNacimiento().getDia()<<"/"<<L->inoculacion.getPaciente().getFechaDeNacimiento().getMes()<<"/"<<L->inoculacion.getPaciente().getFechaDeNacimiento().getAnho()<<endl;
      cout<<"Dosis: "<<L->inoculacion.getDosisAplicada().getTipoVacuna()<<endl;
      cout<<"Numero de serie: "<<L->inoculacion.getDosisAplicada().getNumeroIdentificador()<<endl;
      aux=true;
    }else{
      L2=L2->sgte;
      L=L->sgte;
    }
  }
}




int main() {
  int cantidad=0,total=0;
  vector<struct arreglo> arreg;
  string fechaAcSeparada;
  string x;
  bool f = false;
  int todos=100;
  Lista todosDatos =NULL;
  Lista2 todosDatos2=NULL;
  Lista3 todosDatos3=NULL;



  

  //leeProcesa(nombre_archivo,todosDatos2,total,cantidad);
  //imprimir_lista_sinPerderDatos(todosDatos2);


  //para comprovar el funcionamiento de calcula edad.
  //imprimir_lista_sinPerderDatosEdad(todosDatos2);


  //menu 
   char opMenu;
  do{
 
    cout<<endl;
    cout << "Ingrese una opcion para continuar.." << endl;
    cout << "a.- Informar Fecha actual" << endl;
    cout << "b.- Cargar base de datos de pacientes" << endl;
    cout << "c.- Resultado de carga de datos de pacientes: " << endl;
    cout << "d.- Crear Dosis" << endl;
    cout << "e.- Iniciar Vacunacion" << endl;
    cout << "f.- Consultar paciente" << endl;
    cout << "g.- Pacientes no vacunados" << endl;
    cout << "h.- Salir" << endl;
    cin>>opMenu;
  switch (opMenu){
    case 'a':
      cout<<fechaYHora();
    break;
      
    case 'b':
      leeProcesa(nombre_archivo,todosDatos2,total,cantidad);
      //imprimir_lista_sinPerderDatos(todosDatos2);
    break;

    case 'c':
      cout<<endl;
      cout<<"Pacientes leidos: "<<total<<" pacientes agregados: "<<cantidad<<endl;
    break;

    case 'd':
      CrearDosis(todosDatos3);
      cout<<"dosis creada exitosamente";
    break;

    case 'e':
      iniciarVacunacion(todosDatos,todosDatos2,todosDatos3);
    break;

    case 'f':
      cout<<"Ingrese run del paciente sin puntos y con digito verificador"<<endl;
      cin>>x;
      buscarPaciente(x, todosDatos2, todosDatos);
    break;
    case 'g':
      cout<<"todos los pacientes sin vacunar:"<<endl;
      imprimir_lista_sinVacunar(todosDatos2);
    break;
    
    case 'h':
    
    break;

    default: cout<<"opcion incorrecta"<<endl<<endl;
  }
  }while(opMenu!='h');


}
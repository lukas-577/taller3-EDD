#include <iostream> // esto por el cout
#include <sstream>
#include <vector> //para usar vector 
#include "fechaActual.h"
using namespace std; // esto por el cout

//solo para tener la funcion separada y usarla en las clases correspondientes.

const string fechaYHora() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d/%m/%Y", &tstruct);

    return buf;
}

int separaFActual(){
   string fecha_hora_a=fechaYHora();
   //Divide la fecha
   vector<string> partes_fecha_hA;
   stringstream linea(fecha_hora_a);
   string parteDelString;
   while(getline(linea,parteDelString,'/'))
   {
      partes_fecha_hA.push_back(parteDelString);
   }

   int fActualInt=atoi(partes_fecha_hA[2].c_str());

   return fActualInt;
}
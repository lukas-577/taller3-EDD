#include <iostream> // esto por el cout
#include "inoculacion.h"
using namespace std; // esto por el cout

Inoculacion::Inoculacion(){//contructor por defecto
  this->fechaActual="";
}

Inoculacion::Inoculacion(string _fechaActual){//contructor por parametrizado
  this->fechaActual=_fechaActual;
}

//setters

void Inoculacion::setPaciente(Paciente _paciente){
  this->paciente=_paciente;
}

void Inoculacion::setDosisAplicada(Dosis _dosis){
  this->dosisAplicada=_dosis;
}

void Inoculacion::setFechaActual(string _fechaActual){
  this->fechaActual=_fechaActual;
}



//getters

Paciente Inoculacion::getPaciente(){
  return paciente;
}

Dosis Inoculacion::getDosisAplicada(){
  return dosisAplicada;
}

string Inoculacion::getFechaActual(){
  return fechaActual;
}



//destructor
Inoculacion::~Inoculacion(){
}

//metodo de la clase

void Inoculacion::mostrarInoculacion(){

  cout<<"paciente: "<<endl;
  this->paciente.mostrarPaciente();
  cout<<"Dosis aplicada: "<<endl;
  this->dosisAplicada.mostrar();
  cout<<"fechaActual: "<<this->fechaActual<<endl;
  
}
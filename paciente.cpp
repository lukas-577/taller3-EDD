#include <iostream> // esto por el cout
#include <string>
#include "paciente.h"
#include "fechaActual.h"
#include "lista2.h"
using namespace std; // esto por el cout

Paciente::Paciente(){//contructor por defecto
  this->nombre="";
  this->materno="";
  this->paterno="";
  this->setEstadoVacunacion(1);
}

Paciente::Paciente(string _nombre,string _materno,string _paterno){//contructor por parametrizado
  this->nombre=_nombre;
  this->materno=_materno;
  this->paterno=_paterno;
  
}

//setters

void Paciente::setFechaDeNacimiento(Fecha _fechaNacimiento){
  this->fechaDeNacimiento=_fechaNacimiento;
}

void Paciente::setRun(Run _run){
  this->run=_run;
}

void Paciente::setNombre(string _nombre){
  this->nombre=_nombre;
}

void Paciente::setPaterno(string _paterno){
  this->paterno=_paterno;
}

void Paciente::setMaterno(string _materno){
  this->materno=_materno;
}

void Paciente::setEstadoVacunacion(int estado){
  this->estado=estado;
}

void Paciente::setGenero(string genero){
  this->genero=genero;
}



//getters

Fecha Paciente::getFechaDeNacimiento(){
  return fechaDeNacimiento;
}

Run Paciente::getRun(){
  return run;
}

string Paciente::getNombre(){
  return nombre;
}

string Paciente::getMaterno(){
  return materno;
}

string Paciente::getPaterno(){
  return paterno;
}

string Paciente::getGenero(){
  return genero;
}

int Paciente::getEstadoVacunacion(){
  return estado;
}



//destructor
Paciente::~Paciente(){
}

//metodo de la clase

void Paciente::mostrarPaciente(){
  cout<<"fechaDeNacimiento: ";
  this->fechaDeNacimiento.obtenerFecha();
  cout<<"run :";
  this->run.ver();
  cout<<"nombre: "<<this->nombre<<endl;
  cout<<"materno: "<<this->materno<<endl;
  cout<<"paterno: "<<this->paterno<<endl;
}


//calcula y devuelve los años cumplidos del paciente.

int Paciente::edad(){
  //Lista2 l;
  int fechaAnho=fechaDeNacimiento.getAnho();
  int edad=0;
  //int fActualInt=atoi(fActual.c_str());
  int fActualAnho = separaFActual();
  edad=fActualAnho-fechaAnho;

  return edad;
}
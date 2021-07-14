#include <iostream> // esto por el cout
#include "dosis.h"
using namespace std; // esto por el cout

Dosis::Dosis(){//contructor por defecto
  this->tipoVacuna="";
  this->edadMin=0;
  this->edadMax=0;
  this->numeroIdentificador=0;
  this->utilizada=true;
}

Dosis::Dosis(string tipoVacuna,int edadMin,int edadMax,int numeroIdentificador,bool utilizada){
  this->tipoVacuna=tipoVacuna;
  this->edadMin=edadMin;
  this->edadMax=edadMax;
  this->numeroIdentificador=numeroIdentificador;
  this->utilizada=utilizada;
}

//setters

void Dosis::setTipoVacuna(string tipoVacuna){
  this->tipoVacuna=tipoVacuna;
}

void Dosis::setEdadMin(int edadMin){
  this->edadMin=edadMin;
}

void Dosis::setEdadMax(int edadMax){
  this->edadMax=edadMax;
}

void Dosis::setNumeroIdentificador(int numeroIdentificador){
  this->numeroIdentificador=numeroIdentificador;
}

void Dosis::setUtilizada(bool utilizada){
  this->utilizada=utilizada;
}

//getters

string Dosis::getTipoVacuna(){
  return tipoVacuna;
}

int Dosis::getEdadMin(){
  return edadMin;
}

int Dosis::getEdadMax(){
  return edadMax;
}

int Dosis::getNumeroIdentificador(){
  return numeroIdentificador;
}

bool Dosis::getUtilizada(){
  return utilizada;
}
//destructor
Dosis::~Dosis(){
}

//metodo de la clase

void Dosis::mostrar(){
  cout<<"tipo de vacuna: "<<this->tipoVacuna<<",edadMin: "<<this->edadMin<<",edadMax; "<<getEdadMax()<<",utilizada: "<<getUtilizada()<<endl;
}
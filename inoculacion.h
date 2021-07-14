#include <iostream> // esto por el string
#include "paciente.h"
#include "dosis.h"
using namespace std; // esto por el string
#ifndef INOCULACION_H
#define INOCULACION_H

class Inoculacion
{
  public:
  Inoculacion();//constructor vacio o constructor por defecto
  Inoculacion(string fechaActual);//porMeintras xd
  virtual ~Inoculacion(); //destructor

  //setters and getters

  void setPaciente(Paciente);
  Paciente getPaciente();

  void setDosisAplicada(Dosis);
  Dosis getDosisAplicada();

  void setFechaActual(string fechaActual);
  string getFechaActual();




  //metodo propio de la clases

  void mostrarInoculacion();


private:
  //atributos
  Paciente paciente;
  Dosis dosisAplicada;
  string fechaActual;



};

#endif // INOCULACION_H
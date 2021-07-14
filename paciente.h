#include <iostream> // esto por el string
#include "fecha.h"
#include "run.h"
using namespace std; // esto por el string
#ifndef PACIENTE_H
#define PACIENTE_H

class Paciente
{
  public:
  Paciente();//constructor vacio o constructor por defecto
  Paciente(string,string,string);
  virtual ~Paciente(); //destructor

  //setters and getters

  void setFechaDeNacimiento(Fecha);
  Fecha getFechaDeNacimiento();

  void setRun(Run);
  Run getRun();

  void setNombre(string nombre);
  string getNombre();

  void setMaterno(string materno);
  string getMaterno();

  void setPaterno(string paterno);
  string getPaterno();

  void setEstadoVacunacion(int estado);
  int getEstadoVacunacion();

  void setGenero(string genero);
  string getGenero();

  //metodo de la clase
  void mostrarPaciente();

  //calcula y devuelve los años cumplidos del paciente.
  int edad();


private:
  //atributos
  Fecha fechaDeNacimiento;
  Run run;
  string nombre;
  string materno;
  string paterno;
  string genero;
  int estado;




};

#endif // PACIENTE_H
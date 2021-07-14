#include <iostream> // esto por el string
using namespace std; // esto por el string
#ifndef DOSIS_H
#define DOSIS_H

class Dosis
{
  public:
  Dosis();//constructor vacio o constructor por defecto
  Dosis(string tipoVacuna,int edadMin,int edadMax,int numeroIdentificador,bool utilizada);
  virtual ~Dosis(); //destructor

  //setters and getters

  void setTipoVacuna(string tipoVacuna);
  string getTipoVacuna();

  void setEdadMin(int edadMin);
  int getEdadMin();

  void setEdadMax(int edadMax);
  int getEdadMax();

  void setNumeroIdentificador(int numeroIdentificador);
  int getNumeroIdentificador();

  void setUtilizada(bool utilizada);
  bool getUtilizada();


  void mostrar();


private:
  //atributos
  string tipoVacuna;
  int edadMin;
  int edadMax;
  int numeroIdentificador;
  bool utilizada;



};

#endif // DOSIS_H
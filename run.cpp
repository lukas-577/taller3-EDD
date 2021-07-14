#include <iostream> // esto por el cout
#include <sstream>
#include <vector> //para usar vector 
#include "run.h"
using namespace std; // esto por el cout

Run::Run(){//contructor por defecto
  this->run="";

}

Run::Run(string run){
  this->run=run;

}

//setters

void Run::setRun(string run){
  this->run=run;
}

//getters

string Run::getRun(){
  return run;
}

//destructor
Run::~Run(){
}



//metodo de la clase


void Run::ver(){
  cout<<this->run<<endl;
}

bool runValido(vector<string> vectorSepara){
  bool esValidoK=false,esValido=false;
  if( vectorSepara.size()<9 || vectorSepara.size()>10){
    esValido=false;
  }
    
  
   string digitoV = vectorSepara.at(1);
   int _run_entero=stoi(vectorSepara.at(0));//Se ingresa el Run sin digito a variable de enteros;
   int _run_array[9];//Se declara Array para dejar cada digito de la variable entera para trabajar con ellas por separado
   if(digitoV=="K"){
     esValidoK=true;
   }
    //Divide el entero y los ingresa al array
    for(int i=0;i<8;i++){
      _run_array[i]=_run_entero%10;
      _run_entero=_run_entero/10;
    }
   
   //se da vuelta el array
   int i=0,suma=0,j=2;
   while(i<=7)
   {
      suma=suma+(_run_array[i]*j);
      j++;
      if(j>7)
      {
         j=2;
      }
      i++;

   }
  
   int suma2=suma/11;
   suma2=suma/11;
   suma=suma-suma2;
   suma=11-suma;
   if(digitoV=="K"){
     digitoV="10";
   }else if (digitoV=="0"){
     digitoV="11";
     esValido= true;
   }else if(suma==stoi(digitoV)){
     esValido= false;
   }else{
     esValido= true;
   }
   return esValido||esValidoK;
    
}

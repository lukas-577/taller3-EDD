#ifndef LISTA2_H
#define LISTA2_H
#include "dosis.h"
#include "run.h"
#include "fecha.h"
#include "paciente.h"
#include "inoculacion.h"


struct nodo2{
    Paciente paciente;
    struct nodo2 *sgte;
};

typedef nodo2 *Lista2;

#endif // LISTA2_H
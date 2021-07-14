#ifndef LISTA_H
#define LISTA_H
#include "dosis.h"
#include "run.h"
#include "fecha.h"
#include "paciente.h"
#include "inoculacion.h"


struct nodo{
    Inoculacion inoculacion;
    struct nodo *sgte;
};

typedef nodo *Lista;

#endif // LISTA_H
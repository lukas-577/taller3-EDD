#ifndef LISTA3_H
#define LISTA3_H
#include "dosis.h"
#include "run.h"
#include "fecha.h"
#include "paciente.h"
#include "inoculacion.h"


struct nodo3{
    Dosis dosis;
    struct nodo3 *sgte;
};

typedef nodo3 *Lista3;

#endif // LISTA3_H
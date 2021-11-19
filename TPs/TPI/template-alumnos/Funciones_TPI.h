#ifndef UTILES_FUNCIONES_TPI_H
#define UTILES_FUNCIONES_TPI_H

#include <iostream>
#include <vector>
#include <fstream>
#include "definiciones.h"

using namespace std;

bool flotante_valido(float valor_esperado, float valor_recibido, float umbral);

vector < vector < int > > leerEncuestaIH( string nombreArchivo );
void leerEncuesta ( string filename, eph_h & th, eph_i & ti );

#endif //UTILES_FUNCIONES_TPI_H

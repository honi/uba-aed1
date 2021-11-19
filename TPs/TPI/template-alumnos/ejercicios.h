#ifndef ETPH_EJERCICIOS_H
#define ETPH_EJERCICIOS_H

#include <iostream>
#include <vector>
#include <math.h>
#include <tuple>
#include "definiciones.h"

using namespace std;

bool esEncuestaValida ( eph_h th, eph_i ti );
vector < int > histHabitacional ( eph_h th, eph_i ti, int region );
vector < pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti );
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i );
int costoSubsidioMejora( eph_h th, eph_i ti, int monto );
join_hi generarJoin( eph_h th, eph_i ti );
void ordenarRegionYCODUSU ( eph_h & th, eph_i & ti );
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti );
void corregirRegion( eph_h & th, eph_i ti );
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias );
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda );

#endif //ETPH_EJERCICIOS_H

#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"


// Auxiliares comunes

bool esCasa(hogar &h);

bool esCasaPropia(hogar &h);

bool esDepto(hogar &h);

bool estaEnLaRegion(hogar &h, dato region);

bool esHogarDePueblo(hogar &h);

int cantidadDeDormitorios(hogar &h);

int cantidadDeHabitantes(eph_i &ti, hogar &h);

hogar hogarDelIndividuo(eph_h &th, individuo &i);


// Auxiliares problema 1

bool cantidadValidaDormitorios(eph_h &th);

bool esMatriz(matriz &m, int columnas);

bool esVacia(matriz &m);

bool hayHogaresRepetidos(eph_h &th);

bool hayHogaresSinIndividuos(eph_i &ti, eph_h &th);

bool hayIndividuosRepetidos(eph_i &ti);

bool hayIndividuosSinHogares(eph_i &ti, eph_h &th);

bool menosDe21MiembrosPorHogar(eph_i &ti, eph_h &th);

bool mismoAnioYTrimestre(eph_i &ti, eph_h &th);

bool valoresHogarEnRango(eph_h &th);

bool valoresIndividuoEnRango(eph_i &ti);


// Auxiliares problema 3

bool hogarConHacinamientoCritico(eph_i &ti, hogar &h);


// Auxiliares problema 4

bool esCasaChica(eph_i &ti, hogar &h);

bool hogarValidoParaTeleworking(hogar &h);

float proporcionTeleworking(eph_h &th, eph_i &ti);

bool trabajaEnSuVivienda(individuo &i, hogar &h);


// Auxiliares problemas 5 y 8

int ingresosDelHogar(hogar &h, eph_i &ti);


// Auxiliares problema 7

bool hogarVaAdelante(hogar &h1, hogar &h2);

bool individuoVaAdelante(individuo &i1, individuo &i2);

int seleccionarIndiceProximoHogar(eph_h &th, int indiceInicio);

void ordenarIndividuosDelMismoHogar(eph_i &ti, int &tiOrdenadoHasta, dato codigoHogar);

void ordenarIndividuosPorComponente(eph_i &ti, int indiceUltimoIndividuoDelMismoHogar);


// Auxiliares problema 8

vector<int> buscarMuestra(vector<int> &ingresosPorHogar);

vector<int> calcularIngresosPorHogar(eph_h &th, eph_i &ti);

void llenarMuestra(vector<int> &muestra, int diferencia, vector<int> &ingresosPorHogar);

void ordenarHogaresPorIngresos(eph_h &th, vector<int> &ingresos);


// Auxiliares problema 10

bool individuoMatcheaBusqueda(individuo &individuo, vector<pair<int, dato>> &busqueda);


// Auxiliares problema 11

float distanciaEuclideana(pair<int, int> p1, pair<int, int> p2);


#endif //SOLUCION_AUXILIARES_H

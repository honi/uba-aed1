#ifndef UTILES_DEFINICIONES_H
#define UTILES_DEFINICIONES_H

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// CONSTANTES

enum ItemHogar {
    HOGCODUSU,    // CODUSU
    HOGANIO,      // Año
    HOGTRIMESTRE, // Trimestre
    HOGLATITUD,   // latitud
    HOGLONGITUD,  // Longitud
    II7,          // Régimen de tenencia (Propietario, Inquilino, Ocupante)
    REGION,       // Región
    MAS_500,      // Aglomerados de más de 500.000 habitantes
    IV1,          // Tipo de hogar (Casa, Depto, etc.)
    IV2,          // Cantidad de habitaciones
    II2,          // ¿Cuántas se usan para dormir?
    II3           // ¿Alguna se usa para trabajar?
};

#define FILAS_HOGAR 12
#define COLUMNAS_HOGAR FILAS_HOGAR

enum ItemInd {
    INDCODUSU,    // CODUSU
    INDANIO,      // Año
    COMPONENTE,   // Componente (id de persona dentro de un mismo CODUSU)
    NIVEL_ED,     // Estudios Universitarios completos
    INDTRIMESTRE, // Trimestre
    CH4,          // Género
    CH6,          // Edad
    ESTADO,       // Condición de actividad (Desocupado, Ocupado, No informado)
    CAT_OCUP,     // Categoría ocupacional (Patrón, Empleado, etc.)
    p47T,         // Ingreso
    PP04G         // Ubicación laboral (Oficina, Calle, Hogar, etc.)
};

#define FILAS_INDIVIDUO 11
#define COLUMNAS_INDIVIDUO FILAS_INDIVIDUO

#define GBA 1
#define PAMPEANA 43

#define CASA 1
#define DEPTO 2

// DEFINICIONES DE TIPO

typedef int dato;
typedef vector<dato> individuo;
typedef vector<dato> hogar;
typedef vector<individuo> eph_i;
typedef vector<hogar> eph_h;
typedef pair<hogar, individuo> par_hi;
typedef vector<par_hi> join_hi;
typedef vector<vector<dato>> matriz;

#endif //UTILES_DEFINICIONES_H

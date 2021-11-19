#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

// Auxiliares comunes

bool esCasa(hogar &h) {
    return h[IV1] == CASA;
}

bool esCasaPropia(hogar &h) {
    return h[II7] == 1;
}

bool esDepto(hogar &h) {
    return h[IV1] == DEPTO;
}

bool estaEnLaRegion(hogar &h, dato region) {
    return h[REGION] == region;
}

bool esHogarDePueblo(hogar &h) {
    return h[MAS_500] == 0;
}

int cantidadDeDormitorios(hogar &h) {
    return h[II2];
}

int cantidadDeHabitantes(eph_i &ti, hogar &h) {
    int res = 0;
    for (int i = 0; i < ti.size(); i++) {
        bool viveEnElHogar = ti[i][INDCODUSU] == h[HOGCODUSU];
        if (viveEnElHogar) {
            res++;
        }
    }
    return res;
}

hogar hogarDelIndividuo(eph_h &th, individuo &i) {
    hogar res;
    for (int h = 0; h < th.size() && res.empty(); h++) {
        bool viveEnElHogar = i[INDCODUSU] == th[h][HOGCODUSU];
        if (viveEnElHogar) {
            res = th[h];
        }
    }
    return res;
}


// Auxiliares problema 1

bool cantidadValidaDormitorios(eph_h &th) {
    bool res = true;
    for (int h = 0; h < th.size() && res; h++) {
        bool suficientesHabitaciones = th[h][IV2] >= th[h][II2];
        if (!suficientesHabitaciones) {
            res = false;
        }
    }
    return res;
}

bool esVacia(matriz &m) {
    return m.empty();
}

bool esMatriz(matriz &m, int columnas) {
    bool res = true;
    for (int i = 0; i < m.size() && res; i++) {
        if (m[i].size() != columnas) {
            res = false;
        }
    }
    return res;
}

bool hayHogaresRepetidos(eph_h &th) {
    bool res = false;
    for (int i = 0; i < th.size() && !res; i++) {
        for (int j = 0; j < th.size() && !res; j++) {
            bool mismoCodigo = th[i][HOGCODUSU] == th[j][HOGCODUSU];
            if (i != j && mismoCodigo) {
                res = true;
            }
        }
    }
    return res;
}

bool hayHogaresSinIndividuos(eph_i &ti, eph_h &th) {
    bool res = false;
    for (int h = 0; h < th.size() && !res; h++) {
        int i = 0;
        while (i < ti.size() && th[h][HOGCODUSU] != ti[i][INDCODUSU]) {
            i++;
        }
        if (i == ti.size()) {
            res = true;
        }
    }
    return res;
}

bool hayIndividuosRepetidos(eph_i &ti) {
    bool res = false;
    for (int i = 0; i < ti.size() && !res; i++) {
        for (int j = 0; j < ti.size() && !res; j++) {
            bool mismoHogar = ti[i][INDCODUSU] == ti[j][INDCODUSU];
            bool mismoComponente = ti[i][COMPONENTE] == ti[j][COMPONENTE];
            if (i != j && mismoHogar && mismoComponente) {
                res = true;
            }
        }
    }
    return res;
}

bool hayIndividuosSinHogares(eph_i &ti, eph_h &th) {
    bool res = false;
    for (int i = 0; i < ti.size() && !res; i++) {
        int h = 0;
        while (h < th.size() && th[h][HOGCODUSU] != ti[i][INDCODUSU]) {
            h++;
        }
        if (h == th.size()) {
            res = true;
        }
    }
    return res;
}

bool menosDe21MiembrosPorHogar(eph_i &ti, eph_h &th) {
    bool res = true;
    for (int h = 0; h < th.size() && res; h++) {
        int miembros = 0;
        int i = 0;
        while (i < ti.size() && miembros < 21) {
            if (th[h][HOGCODUSU] == ti[i][INDCODUSU]) {
                miembros++;
            }
            i++;
        }
        if (miembros == 21) {
            res = false;
        }
    }
    return res;
}

bool mismoAnioYTrimestre(eph_i &ti, eph_h &th) {
    bool res = true;

    // Ya validamos que las tablas no son vacías.
    dato anio = ti[0][INDANIO];
    dato trimestre = ti[0][INDTRIMESTRE];

    for (int i = 0; i < ti.size() && res; i++) {
        bool mismoAnio = ti[i][INDANIO] == anio;
        bool mismoTrimestre = ti[i][INDTRIMESTRE] == trimestre;
        if (!mismoAnio || !mismoTrimestre) {
            res = false;
        }
    }

    for (int h = 0; h < th.size() && res; h++) {
        bool mismoAnio = th[h][HOGANIO] == anio;
        bool mismoTrimestre = th[h][HOGTRIMESTRE] == trimestre;
        if (!mismoAnio || !mismoTrimestre) {
            res = false;
        }
    }

    return res;
}

bool valoresHogarEnRango(eph_h &th) {
    bool res = true;
    for (int h = 0; h < th.size() && res; h++) {
        bool hogarValido = 0 < th[h][HOGCODUSU]
                           && 0 < th[h][HOGTRIMESTRE] && th[h][HOGTRIMESTRE] <= 4
                           && 0 < th[h][II7] && th[h][II7] <= 3
                           && (th[h][REGION] == 1 || (40 <= th[h][REGION] && th[h][REGION] <= 44))
                           && 0 <= th[h][MAS_500] && th[h][MAS_500] <= 1
                           && 0 < th[h][IV1] && th[h][IV1] <= 5
                           && 0 < th[h][IV2]
                           && 0 < th[h][II2]
                           && 1 <= th[h][II3] && th[h][II3] <= 2;
        if (!hogarValido) {
            res = false;
        }
    }
    return res;
}

bool valoresIndividuoEnRango(eph_i &ti) {
    bool res = true;
    for (int i = 0; i < ti.size() && res; i++) {
        bool individuoValido = 0 < ti[i][INDCODUSU]
                               && 0 < ti[i][COMPONENTE]
                               && 0 < ti[i][INDTRIMESTRE] && ti[i][INDTRIMESTRE] <= 4
                               && 0 < ti[i][CH4] && ti[i][CH4] <= 2
                               && 0 <= ti[i][CH6]
                               && 0 <= ti[i][NIVEL_ED] && ti[i][NIVEL_ED] <= 1
                               && -1 <= ti[i][ESTADO] && ti[i][ESTADO] <= 1
                               && 0 <= ti[i][CAT_OCUP] && ti[i][CAT_OCUP] <= 4
                               && -1 <= ti[i][p47T]
                               && 0 <= ti[i][PP04G] && ti[i][PP04G] <= 10;
        if (!individuoValido) {
            res = false;
        }
    }
    return res;
}


// Auxiliares problema 3

bool hogarConHacinamientoCritico(eph_i &ti, hogar &h) {
    return cantidadDeHabitantes(ti, h) > 3 * cantidadDeDormitorios(h);
}


// Auxiliares problema 4

bool esCasaChica(eph_i &ti, hogar &h) {
    return cantidadDeHabitantes(ti, h) - 2 > cantidadDeDormitorios(h);
}

bool hogarValidoParaTeleworking(hogar &h) {
    return !esHogarDePueblo(h) && (esCasa(h) || esDepto(h));
}

float proporcionTeleworking(eph_h &th, eph_i &ti) {
    int cantidadTrabajando = 0;
    int cantidadTeleworking = 0;

    for (int i = 0; i < ti.size(); i++) {
        hogar h = hogarDelIndividuo(th, ti[i]);
        bool trabaja = ti[i][ESTADO] == 1;
        if (trabaja && hogarValidoParaTeleworking(h)) {
            cantidadTrabajando++;
            if (trabajaEnSuVivienda(ti[i], h)) {
                cantidadTeleworking++;
            }
        }
    }

    if (cantidadTrabajando == 0) {
        return 0;
    } else {
        return float(cantidadTeleworking) / float(cantidadTrabajando);
    }
}

bool trabajaEnSuVivienda(individuo &i, hogar &h) {
    return i[PP04G] == 6 && h[II3] == 1;
}


// Auxiliares problemas 5 y 8

int ingresosDelHogar(hogar &h, eph_i &ti) {
    int res = 0;
    for (int i = 0; i < ti.size(); i++) {
        int ingresosDelIndividuo = ti[i][p47T];
        bool viveEnElHogar = ti[i][INDCODUSU] == h[HOGCODUSU];
        if (viveEnElHogar && ingresosDelIndividuo > 0) {
            res += ingresosDelIndividuo;
        }
    }
    return res;
}


// Auxiliares problema 7

bool hogarVaAdelante(hogar &h1, hogar &h2) {
    return h1[REGION] < h2[REGION] || (h1[REGION] == h2[REGION] && h1[HOGCODUSU] < h2[HOGCODUSU]);
}

bool individuoVaAdelante(individuo &i1, individuo &i2) {
    return i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE] < i2[COMPONENTE];
}

int seleccionarIndiceProximoHogar(eph_h &th, int indiceInicio) {
    int res = indiceInicio;
    for (int i = indiceInicio + 1; i < th.size(); i++) {
        if (hogarVaAdelante(th[i], th[res])) {
            res = i;
        }
    }
    return res;
}

void ordenarIndividuosDelMismoHogar(eph_i &ti, int &tiOrdenadoHasta, dato codigoHogar) {
    for (int i = tiOrdenadoHasta; i < ti.size(); i++) {
        if (ti[i][INDCODUSU] == codigoHogar) {
            swap(ti[i], ti[tiOrdenadoHasta]);
            ordenarIndividuosPorComponente(ti, tiOrdenadoHasta);
            tiOrdenadoHasta++;
        }
    }
}

void ordenarIndividuosPorComponente(eph_i &ti, int indiceUltimoIndividuoDelMismoHogar) {
    int i = indiceUltimoIndividuoDelMismoHogar;
    while (i > 0 && individuoVaAdelante(ti[i], ti[i - 1])) {
        swap(ti[i], ti[i - 1]);
        i--;
    }
}


// Auxiliares problema 8

vector<int> buscarMuestra(vector<int> &ingresosPorHogar) {
    vector<int> res;
    for (int i = 0; i < ingresosPorHogar.size(); i++) {
        for (int j = i + 1; j < ingresosPorHogar.size(); j++) {
            int diferencia = ingresosPorHogar[j] - ingresosPorHogar[i];
            if (diferencia > 0) {
                vector<int> muestra = {i, j};
                llenarMuestra(muestra, diferencia, ingresosPorHogar);
                if (muestra.size() > res.size()) {
                    res = muestra;
                }
            }
        }
    }
    return res;
}

vector<int> calcularIngresosPorHogar(eph_h &th, eph_i &ti) {
    vector<int> res(th.size());
    for (int h = 0; h < th.size(); h++) {
        res[h] = ingresosDelHogar(th[h], ti);
    }
    return res;
}

void llenarMuestra(vector<int> &muestra, int diferencia, vector<int> &ingresosPorHogar) {
    int i = muestra[1];
    int j = muestra[1] + 1;
    while (j < ingresosPorHogar.size()) {
        if (ingresosPorHogar[j] - ingresosPorHogar[i] == diferencia) {
            i = j;
            muestra.push_back(j);
        }
        j++;
    }
}

void ordenarHogaresPorIngresos(eph_h &th, vector<int> &ingresos) {
    for (int i = 0; i < ingresos.size(); i++) {
        int indiceMin = i;
        for (int j = i; j < ingresos.size(); j++) {
            if (ingresos[j] < ingresos[indiceMin]) {
                indiceMin = j;
            }
        }
        swap(th[indiceMin], th[i]);
        swap(ingresos[indiceMin], ingresos[i]);
    }
}


// Auxiliares problema 10

bool individuoMatcheaBusqueda(individuo &individuo, vector<pair<int, dato>> &busqueda) {
    bool res = true;
    for (int i = 0; i < busqueda.size() && res; i++) {
        if (individuo[busqueda[i].first] != busqueda[i].second) {
            res = false;
        }
    }
    return res;
}


// Auxiliares problema 11

float distanciaEuclideana(pair<int, int> p1, pair<int, int> p2) {
    float a = p1.first - p2.first;
    float b = p1.second - p2.second;
    return sqrt(a * a + b * b);
}

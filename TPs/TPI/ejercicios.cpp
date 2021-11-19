#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;


// Implementación problema 1

bool esEncuestaValida(eph_h th, eph_i ti) {
    return !esVacia(ti)
           && !esVacia(th)
           && esMatriz(ti, COLUMNAS_INDIVIDUO)
           && esMatriz(th, COLUMNAS_HOGAR)
           && !hayIndividuosSinHogares(ti, th)
           && !hayHogaresSinIndividuos(ti, th)
           && !hayIndividuosRepetidos(ti)
           && !hayHogaresRepetidos(th)
           && mismoAnioYTrimestre(ti, th)
           && menosDe21MiembrosPorHogar(ti, th)
           && cantidadValidaDormitorios(th)
           && valoresIndividuoEnRango(ti)
           && valoresHogarEnRango(th);
}


// Implementación problema 2

vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    vector<int> res;
    for (int h = 0; h < th.size(); h++) {
        if (estaEnLaRegion(th[h], region)) {
            int habitaciones = th[h][IV2];
            while (res.size() < habitaciones) {
                res.push_back(0);
            }
            if (esCasa(th[h])) {
                res[habitaciones - 1]++;
            }
        }
    }
    return res;
}


// Implementación problema 3

vector<pair<int, float>> laCasaEstaQuedandoChica(eph_h th, eph_i ti) {
    vector<pair<int, float>> res = {
            make_pair(1, 0),
            make_pair(40, 0),
            make_pair(41, 0),
            make_pair(42, 0),
            make_pair(43, 0),
            make_pair(44, 0),
    };

    for (int i = 0; i < res.size(); i++) {
        dato region = res[i].first;
        int total = 0;
        int conHacinamientoCritico = 0;
        for (int h = 0; h < th.size(); h++) {
            if (estaEnLaRegion(th[h], region) && esCasa(th[h]) && esHogarDePueblo(th[h])) {
                total++;
                if (hogarConHacinamientoCritico(ti, th[h])) {
                    conHacinamientoCritico++;
                }
            }
        }
        res[i].second = total == 0 ? 0 : float(conHacinamientoCritico) / float(total);
    }

    return res;
}


// Implementación problema 4

bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    return proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i);
}


// Implementación problema 5

int costoSubsidioMejora(eph_h th, eph_i ti, int monto) {
    int res = 0;
    for (int h = 0; h < th.size(); h++) {
        if (esCasaPropia(th[h]) && esCasaChica(ti, th[h])) {
            res += monto;
        }
    }
    return res;
}


// Implementación problema 6

join_hi generarJoin(eph_h th, eph_i ti) {
    join_hi res;
    for (int h = 0; h < th.size(); h++) {
        for (int i = 0; i < ti.size(); i++) {
            bool viveEnElHogar = ti[i][INDCODUSU] == th[h][HOGCODUSU];
            if (viveEnElHogar) {
                res.push_back(make_pair(th[h], ti[i]));
            }
        }
    }
    return res;
}


// Implementación problema 7

void ordenarRegionYCODUSU(eph_h &th, eph_i &ti) {
    int tiOrdenadoHasta = 0;
    for (int i = 0; i < th.size(); i++) {
        int j = seleccionarIndiceProximoHogar(th, i);
        swap(th[i], th[j]);
        ordenarIndividuosDelMismoHogar(ti, tiOrdenadoHasta, th[i][HOGCODUSU]);
    }
}


// Implementación problema 8

vector<hogar> muestraHomogenea(eph_h &th, eph_i &ti) {
    vector<int> ingresosPorHogar = calcularIngresosPorHogar(th, ti);
    ordenarHogaresPorIngresos(th, ingresosPorHogar);

    vector<int> muestra = buscarMuestra(ingresosPorHogar);

    vector<hogar> res;
    for (int i = 0; i < muestra.size(); i++) {
        res.push_back(th[muestra[i]]);
    }

    return res.size() >= 3 ? res : vector<hogar>{};
}


// Implementación problema 9

void corregirRegion(eph_h &th, eph_i ti) {
    for (int h = 0; h < th.size(); h++) {
        if (th[h][REGION] == GBA) {
            th[h][REGION] = PAMPEANA;
        }
    }
}


// Implementación problema 10

pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda) {
    eph_h thMatcheados;
    eph_i tiMatcheados;
    eph_h thModificado;
    eph_i tiModificado;

    // En el peor caso ninguno matchea y no se modifican los th, ti de entrada.
    // https://www.cplusplus.com/reference/vector/vector/reserve/
    thModificado.reserve(th.size());
    tiModificado.reserve(ti.size());

    for (int i = 0; i < ti.size(); i++) {
        if (individuoMatcheaBusqueda(ti[i], busqueda)) {
            tiMatcheados.push_back(ti[i]);
        } else {
            tiModificado.push_back(ti[i]);
        }
    }

    int h = 0;
    while (h < th.size()) {
        int i = 0;
        while (i < tiMatcheados.size() && tiMatcheados[i][INDCODUSU] != th[h][HOGCODUSU]) {
            i++;
        }
        bool mantenerHogar = true;
        bool hayIndividuoMatcheadoDelHogar = i < tiMatcheados.size();
        if (hayIndividuoMatcheadoDelHogar) {
            thMatcheados.push_back(th[h]);
            int j = 0;
            while (j < tiModificado.size() && tiModificado[j][INDCODUSU] != th[h][HOGCODUSU]) {
                j++;
            }
            bool noQuedanIndividuosDelHogar = j == tiModificado.size();
            if (noQuedanIndividuosDelHogar) {
                mantenerHogar = false;
            }
        }
        if (mantenerHogar) {
            thModificado.push_back(th[h]);
        }
        h++;
    }

    th = thModificado;
    ti = tiModificado;

    return make_pair(thMatcheados, tiMatcheados);
}


// Implementación problema 11

vector<int> histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias) {
    vector<int> res(distancias.size());
    for (int h = 0; h < th.size(); h++) {
        pair<int, int> posicion = make_pair(th[h][HOGLATITUD], th[h][HOGLONGITUD]);
        float distanciaAlCentro = distanciaEuclideana(posicion, centro);
        int d = 0;
        while (d < distancias.size() && distanciaAlCentro > distancias[d]) {
            d++;
        }
        if (d < distancias.size()) {
            res[d]++;
        }
    }
    return res;
}
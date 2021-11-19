#include <iostream>
#include <vector>
#include <tuple>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <fstream>
#include <ctype.h>

#include "Funciones_TPI.h"

using namespace std;

bool flotante_valido(float valor_esperado, float valor_recibido, float umbral) {
  return abs(valor_esperado - valor_recibido) < umbral;\
}


vector < vector < int > > leerEncuestaIH(string nombreArchivo) {
  char sep = ','; // separador del csv
  ifstream miArchivo;
  vector < vector < int > > t;
  string line="";
  miArchivo.open(nombreArchivo.c_str(), ifstream::in);
  if ( miArchivo.is_open() ) {
    /*header:*/getline(miArchivo, line);
    while ( getline(miArchivo, line) ) {
      vector<int> item;
      std::stringstream linestream(line);
      std::string value;
      while ( getline(linestream, value, sep) ) {
        item.push_back(stoi(value));
      }
      t.push_back(item);
    }
    miArchivo.close();
  } else
    cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
  return t;
}

void leerEncuesta ( string filename , eph_h & th, eph_i & ti ){
  string path = "datos/";
  th = leerEncuestaIH(path+filename+".th");
  ti = leerEncuestaIH(path+filename+".ti");
}


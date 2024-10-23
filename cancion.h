//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#ifndef CANCION_H
#define CANCION_H

#include <iostream>
#include <string>
#include "artista.h"
#include "tiempo.h"
#include "valoracion.h"
#include <iomanip>
using namespace std;
#define DEFAULT "\033[1;0m"
#define ERROR "\033[1;31m"
#define GREEN "\033[1;32m"      /* Green */
#define YELLOW "\033[1;33m"      /* Yellow */
#define BLUE "\033[1;34m"      /* Blue */
#define MAGENTA "\033[1;35m"      /* Magenta */
#define CYAN "\033[1;36m"      /* Cyan */
#define WHITE "\033[1;37m"      /* White */
#define RED "\033[1;31m"	/* Red */
#define DEBUG "\033[1;34m"

class Artista;

class Cancion {
    protected:
        unsigned int id;
        string titulo;
        string ruta_archivo;
        Artista** v_artistas;
        int util_artistas;
        Tiempo duracion;
        int total_reproducciones;
        int total_inclusiones_en_playlist;
        Valoracion** valoracion;
        int util_valoracion;
        int contador;
        double total_valoracion;
        bool test;
        /*--------MÉTODO ADICIONAL--------*/
        void resize(int tamanio_nuevo);
        void resizeValoracion(int tamanio_nuevo);
    public:
        Cancion();
        Cancion(const Cancion &c);
        ~Cancion();
        /*--------GETS--------*/
        unsigned int getId() const;
        string getTitulo() const;
        string getRutaArchivo() const;
        Artista* getArtistas(int i) const;
        int getUtilArtistas() const;
        Tiempo getDuracion() const;
        int getTotalReproducciones() const;
        int getTotalInclusionesEnPlaylist() const;
        Valoracion* getValoracion(int i) const;
        int getUtilValoracion() const;
        int getContador() const;
        double getTotalValoracion() const;
        bool getTest() const;
        /*--------SETS--------*/
        void setId(const int id);
        void setTitulo(const string titulo);
        void setRutaArchivo(const string ruta);
        void setArtistas(const int i, Artista *a);
        void eliminarArtista(const int i);
        void setUtilArtistas(const int util);
        void setDuracion(const Tiempo duracion);
        void setTotalReproducciones(const int reproducciones);
        void setTotalInclusionesEnPlaylist(const int inclusiones);
        void setValoracion(const int i, Valoracion *val);
        void eliminarValoracion(const int i);
        void setUtilValoracion(const int util);
        void setContador(const int cont);
        void setTotalValoracion(const double totalVal);
        /*--------SOBRECARGA--------*/
        Cancion& operator=(const Cancion &c);
        /*--------MÉTODO ADICIONAL--------*/
        void virtual escucharCancion();
};

class Metal: public Cancion {
    void escucharCancion();
};

class Pop: public Cancion {
    void escucharCancion();
};

class Faraon_Love_Shady: public Cancion {
    void escucharCancion();
};

class Rap: public Cancion {
    void escucharCancion();
};

#endif
//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include "cancion.h"
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

class Playlist {
    private:
        unsigned int id;
        string nombre;
        Cancion** canciones_playlist;
        int util_canciones;
        Tiempo duracion_total;
        bool test;
        /*--------MÉTODO ADICIONAL--------*/
        void resize(int tamanio_nuevo);
    public:
        Playlist();
        Playlist(const Playlist &p);
        ~Playlist();
        /*--------GETS--------*/
        unsigned int getId() const;
        string getNombre() const;
        Cancion* getCanciones(int i) const;
        int getUtilCanciones() const;
        Tiempo getDuracion() const;
        bool getTest() const;
        /*--------SETS--------*/
        void setId(const int id);
        void setNombre(const string nombre);
        void setCanciones(const int i, Cancion *c);
        void eliminarCancion(const int i);
        void setUtilCanciones(const int util);
        void setDuracion(const Tiempo t);
        /*--------SOBRECARGA--------*/
        Playlist& operator=(const Playlist &p);
};

#endif
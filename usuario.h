//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include "cancion.h"
#include "playlist.h"
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

class Usuario {
    protected:
        unsigned int id;
        string login;
        string password;
        bool test;
    public:
        Usuario();
        Usuario(const Usuario &u);
        virtual ~Usuario();
        /*--------GETS--------*/
        int getId() const;
        string getLogin() const;
        string getPassword() const;
        bool getTest() const;
        /*--------SETS--------*/
        void setId(const unsigned int id);
        void setLogin(const string login);
        void setPassword(const string password);
};

class Administrador: public Usuario {

};

class Usuario_comun: public Usuario {
    private:
        Cancion** canciones_usuario;
        int util_canciones;
        Playlist** playlist_usuario;
        int util_playlist;
        /*--------MÉTODOS ADICIONALES--------*/
        void resizeCanciones(int tamanio_nuevo);
        void resizePlaylist(int tamanio_nuevo);
    public:
        Usuario_comun();
        Usuario_comun(const Usuario_comun &uc);
        ~Usuario_comun();
        /*--------GETS--------*/
        Cancion* getCanciones(int i) const;
        int getUtilCanciones() const;
        Playlist* getPlaylist(int i) const;
        int getUtilPlaylist() const;
        /*--------SETS--------*/
        void setCanciones(const int i, Cancion *c);
        void eliminarCancion(const int i);
        void setUtilCanciones(const int util);
        void setPlaylist(const int i, Playlist *p);
        void eliminarPlaylist(const int i);
        void setUtilPlaylist(const int util);
        /*--------SOBRECARGA--------*/
        Usuario_comun& operator=(const Usuario_comun &uc);
};

#endif
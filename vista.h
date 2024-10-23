//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include <string>
#include "cancion.h"
#include "usuario.h"
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

class Vista {
    private:
        Usuario** usuarios_sistema;
        int util_usuarios_sistema;
        Cancion** canciones_sistema;
        int util_canciones_sistema;
        Artista** artistas_sistema;
        int util_artistas_sistema;
        Usuario_comun* usuario_activo;
        Administrador* admin_activo;
        Artista** busqueda_artista;
        int util_busqueda_artista;
        Playlist** busqueda_playlist;
        int util_busqueda_playlist;
        Cancion** busqueda_cancion;
        int util_busqueda_cancion;
        bool test;

        void resizeArtistasSistema(int tamanio_nuevo);
        void resizeCancionesSistema(int tamanio_nuevo);
        void resizeUsuariosSistema(int tamanio_nuevo);
        void resizeBusquedaCanciones(int tamanio_nuevo);
    public:
        Vista();
        ~Vista();
        /*--------GETS--------*/
        Usuario* getUsuarioSistema(int i) const;
        int getUtilUsuariosSistema() const;
        Cancion* getCancionSistema(int i) const;
        int getUtilCancionesSistema() const;
        Artista* getArtistaSistema(int i) const;
        int getUtilArtistasSistema() const;
        Usuario_comun* getUsuarioActivo() const;
        Administrador* getAdminActivo() const;
        Artista* getBusquedaArtista(int i) const;
        int getUtilBusquedaArtista() const;
        Playlist* getBusquedaPlaylist(int i) const;
        int getUtilBusquedaPlaylist() const;
        Cancion* getBusquedaCancion(int i) const;
        int getUtilBusquedaCancion() const;
        bool getTest() const;
        /*--------SETS--------*/
        void setUsuarioSistema(const int i, Usuario *u);
        void eliminarUsuario(const int i);
        void setUtilUsuariosSistema(const int util);
        void setCancionSistema(const int i, Cancion *c);
        void eliminarCancion(const int i);
        void setUtilcancionesSistema(const int util);
        void setArtistaSistema(const int i, Artista *a);
        void eliminarArtista(const int i);
        void setUtilArtistasSistema(const int util);
        void setUsuarioActivo(Usuario_comun *u);
        void setAdminActivo(Administrador *u);
        void setBusquedaArtista(const int i, Artista *a);
        void setUtilBusquedaArtista(const int util);
        void setBusquedaPlaylist(const int i, Playlist *p);
        void setUtilBusquedaPlaylist(const int util);
        void setBusquedaCancion(const int i, Cancion *c);
        void eliminarBusquedaCancion(const int i);
        void setUtilBusquedaCancion(const int util);
        /*MÉTODOS*/
        /*Cargar datos básicos del Sistema*/
        /**
         * @brief Carga los datos básicos de los Artitas
         * @post Se abrán creado los Artistas con sus datos
         */
        void cargarArtistas();
        /**
         * @brief Carga los datos básicos de las Canciones
         * @post Se abrán creado las Canciones con sus datos
         */
        void cargarCanciones();
        /**
         * @brief Carga los datos básicos de los Usuarios
         * @post Se abrán creado los Usuarios con sus datos
         */
        void cargarUsuarios();

        /**
         * @brief Llama a las funciones necesarias para cargar los datos básicos
         * @post Se abrán creado todos los datos del Sistema
         */
        void cargarDatosPorDefecto();
        /*Menú y submenús del Sistema*/
        /**
         * @brief Le pide al Usuario Login y Password para inciar sesión
         * @post Se abrá iniciado sesión con un Usuario
         */
        void menuSistema();
        /**
         * @brief Muestra al Usuario el menú Administrador
         * @post Se mostrará el menú del Administrador
         */
        void menuAdministrador();
        /**
         * @brief Muestra al Usuario el menú del Usuario Común
         * @post Se mostrará el menú del Usuario común
         */
        void menuUsuarioComun();
        /*Funcionalidades del Usuario Común*/
        /**
         * @brief Permite consultar las Playlsits que tiene el Usuario activo
         * @post Muestra la Playlist elegida por el Usuario
         */
        void consultarPlaylists();
        /**
         * @brief Permite añadir una Canción a la Playlist que elija el Usuario del Usuario activo aumentando las inclusiones en Playlist de la Canción
         * @post Agrega una Canción en la Playlist elegida por el Usuario
         */
        void agregarCancionAplaylist();
        /**
         * @brief Permite eliminar una Canción a la Playlist que elija el Usuario del Usuario activo disminuyendo las inclusiones en Playlist de la Canción
         * @post Elimina una Canción de la Playlist elegida por el Usuario
         */
        void eliminarCancionDePlaylist();
        /**
         * @brief Permite que el Usuario activo valore una Canción del Catálogo del Sistema
         * 
         */
        void valorarCancion();
        /**
         * @brief Permite escuchar una Canción de las Playlists del Usuario activo aumentando sus reproducciones
         * 
         */
        void escucharCancion();
        /*Funcionalidades del Administrador*/
        void imprimirDatos();

        void rankings();
        Cancion** calcularRanking();
        void rankingGeneral();
        void rankingPorTipo();
        void rankingMetal();
        void rankingRap();
        void rankingPop();
        void rankingFaraon();
        void rankingArtistas();

        void opcionesCatalogo();
        void agregarCancionCatalogo();
        void eliminarCancionCatalogo();
        void modificarCancion();

        void opcionesUsuario();
        void agregarUsuarioAlSistema();
        void buscarUsuarios();
        void eliminarUsuariodelSistema();
        void modificarUsuario();

        void opcionesPlaylist();
        void eliminarPlaylist();
};

#endif

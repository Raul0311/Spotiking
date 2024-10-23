//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#include "usuario.h"

/*----------USUARIO----------*/
/*CONSTRUCTOR*/
Usuario::Usuario() {
    this->test = false;
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Usuario): Creando el Usuario..." << DEFAULT << endl;
    }

    this->setId(0);
    this->setLogin("NULL");
    this->setPassword("NULL");

    if(this->test == true) {
        cout << DEBUG << "DEBUG(Usuario): Usuario creado correctamente..." << DEFAULT << endl;
	}
}
/*CONSTRUCTOR POR COPIA*/
Usuario::Usuario(const Usuario &u) {
    this->test = u.test;
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Usuario): Creando el Usuario por Copia..." << DEFAULT << endl;
    }
    this->setId(u.getId());
    this->setLogin(u.getLogin());
    this->setPassword(u.getPassword());

    if(this->test == true) {
        cout << DEBUG << "DEBUG(Usuario): Usuario creado correctamente por Copia..." << DEFAULT << endl;
	}
}
/*DESTRUCTOR*/
Usuario::~Usuario() {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(~Usuario): Eliminando el Usuario..." << DEFAULT << endl;
    }

    this->setId(0);
    this->setLogin("NULL");
    this->setPassword("NULL");

    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(~Usuario): Usuario eliminado correctamente..." << DEFAULT << endl;
    }
}
/*GETS*/
int Usuario::getId() const {
    return this->id;
}

string Usuario::getLogin() const {
    return this->login;
}

string Usuario::getPassword() const {
    return this->password;
}

bool Usuario::getTest() const {
    return this->test;
}
/*SETS*/
void Usuario::setId(const unsigned int id) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setId): Estableciendo el id del usuario..." << DEFAULT << endl;
    }
    this->id = id;
}

void Usuario::setLogin(const string login) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setLogin): Estableciendo el login del usuario..." << DEFAULT << endl;
    }
    this->login = login;
}

void Usuario::setPassword(const string password) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setPassword): Estableciendo la password del usuario..." << DEFAULT << endl;
    }
    this->password = password;
}

/*----------USUARIO COMÚN----------*/
/*CONSTRUCTOR*/
Usuario_comun::Usuario_comun():Usuario() {
    this->test = true;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Usuario_comun): Creando el Usuario_comun..." << DEFAULT << endl;
    }
    
    this->setUtilCanciones(0);
    this->canciones_usuario = new Cancion*[this->util_canciones];
    if(this->canciones_usuario == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->canciones_usuario[0] = 0;

    this->setUtilPlaylist(0);
    this->playlist_usuario = new Playlist*[this->util_playlist];
    if(this->playlist_usuario == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->playlist_usuario[0] = 0;

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Usuario_comun): Usuario_comun creado correctamente..." << DEFAULT << endl;
    }
}
/*CONSTRUCTOR POR COPIA*/
Usuario_comun::Usuario_comun(const Usuario_comun &uc):Usuario() {
    this->test = uc.getTest();
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Usuario_comun): Creando el Usuario_comun por Copia..." << DEFAULT << endl;
    }
    this->setUtilCanciones(0);
    if(this->canciones_usuario != 0) {
        this->canciones_usuario = 0;
    }
    this->canciones_usuario = new Cancion*[uc.getUtilCanciones()];
    if(this->canciones_usuario == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    for(int i = 0; i < uc.getUtilCanciones(); i++) {
        this->setCanciones(i,uc.getCanciones(i));
    }

    this->setUtilPlaylist(0);
    if(this->playlist_usuario != 0) {
        this->playlist_usuario = 0;
    }
    this->playlist_usuario = new Playlist*[uc.getUtilPlaylist()];
    if(this->playlist_usuario == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    for(int i = 0; i < uc.getUtilPlaylist(); i++) {
        this->setPlaylist(i,uc.getPlaylist(i));
    }

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Usuario_comun): Usuario_comun creado correctamente por Copia..." << DEFAULT << endl;
    }
}
/*DESTRUCTOR*/
Usuario_comun::~Usuario_comun() {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(~Usuario_comun): Eliminando el Usuario_comun..." << DEFAULT << endl;
    }

    for(int i = 0; i < this->getUtilCanciones(); i++) {
        if(this->canciones_usuario[i] != 0) {
            this->canciones_usuario[i] = 0;
        }
        this->eliminarCancion(i);
    }
    if(this->canciones_usuario != 0) {
        delete [] this->canciones_usuario;
        this->canciones_usuario = 0;
    } else {
        cout << DEBUG <<  "Memoria ya liberada con anterioridad." << DEFAULT << endl;
    }
    this->setUtilCanciones(0);

    for(int i = 0; i < this->getUtilPlaylist(); i++) {
        if(this->playlist_usuario[i] = 0) {
            delete this->playlist_usuario[i];
            this->playlist_usuario[i] = 0;
        }
        this->eliminarPlaylist(i);
    }
    if(this->playlist_usuario != 0) {
        delete [] this->playlist_usuario;
        this->playlist_usuario = 0;
    } else {
        cout << DEBUG <<  "Memoria ya liberada con anterioridad." << DEFAULT << endl;
    }
    this->setUtilPlaylist(0);

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(~Usuario_comun): Usuario_comun eliminado correctamente..." << DEFAULT << endl;
    }
}
/*GETS*/
Cancion* Usuario_comun::getCanciones(int i) const {
    return this->canciones_usuario[i];
}

int Usuario_comun::getUtilCanciones() const {
    return this->util_canciones;
}

Playlist* Usuario_comun::getPlaylist(int i) const {
    return this->playlist_usuario[i];
}

int Usuario_comun::getUtilPlaylist() const {
    return this->util_playlist;
}
/*SETS*/
void Usuario_comun::setCanciones(const int i, Cancion *c) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setCanciones): Estableciendo una Canción al usuario_comun..." << DEFAULT << endl;
    }
    this->resizeCanciones(this->getUtilCanciones() + 1);
    this->canciones_usuario[i] = c;
}

void Usuario_comun::setUtilCanciones(const int util) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setUtilCanciones): Estableciendo la Util de las Canciones del usuario_comun..." << DEFAULT << endl;
    }
    this->util_canciones = util;
}
void Usuario_comun::eliminarCancion(const int i) {
    if(this->getUtilCanciones() == 1) {
        this->resizeCanciones(0);
    }
    if(this->canciones_usuario[i] != 0) {
        this->resizeCanciones(0);
        if(this->canciones_usuario[i] != 0) {
            this->canciones_usuario[i] = 0;
        }
    } else {
        if(this->canciones_usuario[i] != 0) {
            this->canciones_usuario[i] = 0;
        }
        this->canciones_usuario[i] = this->canciones_usuario[this->getUtilCanciones() - 1];
        this->resizeCanciones(this->getUtilCanciones() - 1);
    }
}

void Usuario_comun::setPlaylist(const int i, Playlist *p) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setPlaylist): Estableciendo una Playlist al usuario_comun..." << DEFAULT << endl;
    }
    this->resizePlaylist(this->getUtilPlaylist() + 1);
    this->playlist_usuario[i] = p;
}

void Usuario_comun::eliminarPlaylist(const int i) {
    if(this->getUtilPlaylist() == 1) {
        this->resizePlaylist(0);
        if(this->playlist_usuario[i] != 0) {
            //delete this->playlist_usuario[i];
        }
    } else {
        if(this->playlist_usuario[i] != 0) {
            //delete this->playlist_usuario[i];
        }
        this->playlist_usuario[i] = this->playlist_usuario[this->getUtilPlaylist() - 1];
        this->resizePlaylist(this->getUtilPlaylist() - 1);
    }
}

void Usuario_comun::setUtilPlaylist(const int util) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setUtilPlaylist): Estableciendo la Util de la Playlist del usuario_comun..." << DEFAULT << endl;
    }
    this->util_playlist = util;
}
/*SOBRECARGA*/
Usuario_comun& Usuario_comun::operator=(const Usuario_comun &uc) {
    this->test = uc.getTest();
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(operator=): Copiando Usuario_comun con Sobrecarga." << DEFAULT << endl;
    }

    if(this != &uc) {
        this->setUtilCanciones(0);
        if(this->canciones_usuario != 0) {
            delete [] this->canciones_usuario;
        }
        
        this->canciones_usuario = new Cancion*[uc.getUtilCanciones()];
        if(this->canciones_usuario == 0) {
            cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
            exit(-1);
        }

        for(int i = 0; i < uc.getUtilCanciones(); i++) {
            this->setCanciones(i,uc.getCanciones(i));
        }

        this->setUtilPlaylist(0);
        if(this->playlist_usuario != 0) {
            delete [] this->playlist_usuario;
        }
        
        this->playlist_usuario = new Playlist*[this->getUtilCanciones()];
        if(this->playlist_usuario == 0) {
            cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
            exit(-1);
        }

        for(int i = 0; i < uc.getUtilPlaylist(); i++) {
            this->setPlaylist(i,uc.getPlaylist(i));
        }
    }

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(operator=): Usuario_comun copiado correctamente con Sobrecarga." << DEFAULT << endl;
    }

    return *this;
}
/*MÉTODOS ADICIONALES*/
void Usuario_comun::resizeCanciones(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize de Canciones" << DEFAULT << endl;
    }
    
    Cancion** nuevo_v_cancion;
    //1º) Reservo Memoria
    if(tamanio_nuevo != this->getUtilCanciones() && tamanio_nuevo > this->getUtilCanciones()) {
        nuevo_v_cancion = new Cancion*[tamanio_nuevo];
        if(nuevo_v_cancion == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < tamanio_nuevo; i++) {
            nuevo_v_cancion[i] = 0;
        }
    }

    if(tamanio_nuevo != this->getUtilCanciones() && tamanio_nuevo < this->getUtilCanciones()) {
        nuevo_v_cancion = new Cancion*[this->getUtilCanciones()];
        if(nuevo_v_cancion == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < this->getUtilCanciones(); i++) {
            nuevo_v_cancion[i] = 0;
        }
    }

    //2º) Copio los valores del vector antiguo en el nuevo (independientemente del tamaño)
    if(tamanio_nuevo > this->getUtilCanciones()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize de Canciones para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilCanciones(); i++) {
            nuevo_v_cancion[i] = this->canciones_usuario[i];
        }
    } else if(tamanio_nuevo < this->getUtilCanciones()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize de Canciones para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
        }
        //copio los valores antiguos en el nuevo, que es más pequeño
        for(int i=0; i < tamanio_nuevo; i++) {
            nuevo_v_cancion[i] = this->getCanciones(i);
        }
    } else if(tamanio_nuevo == this->getUtilCanciones()) {
        if(this->getTest() == true) {
            cout << DEBUG << "El nuevo tamaño es igual que el anterior, no se realizará ningún cambio" << DEFAULT << endl;
        }
    }
    //3º) Eliminar la Memoria
    if(tamanio_nuevo != this->getUtilCanciones()) {
        delete [] this->canciones_usuario;
        this->canciones_usuario = nuevo_v_cancion;
        this->setUtilCanciones(tamanio_nuevo);
    }
}

void Usuario_comun::resizePlaylist(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize de Playlists" << DEFAULT << endl;
    }
    
    Playlist** nuevo_v_playlist;
    //1º) Reservo Memoria
    if(tamanio_nuevo != this->getUtilPlaylist() && tamanio_nuevo > this->getUtilPlaylist()) {
        nuevo_v_playlist = new Playlist*[tamanio_nuevo];
        if(nuevo_v_playlist == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        for(int i = 0; i < tamanio_nuevo; i++) {
            nuevo_v_playlist[i] = 0;
        }
    }

    if(tamanio_nuevo != this->getUtilPlaylist() && tamanio_nuevo < this->getUtilPlaylist()) {
        nuevo_v_playlist = new Playlist*[this->getUtilPlaylist()];
        if(nuevo_v_playlist == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        for(int i = 0; i < this->getUtilPlaylist(); i++) {
            nuevo_v_playlist[i] = 0;
        }
    }

    //2º) Copio los valores del vector antiguo en el nuevo (independientemente del tamaño)
    if(tamanio_nuevo > this->getUtilPlaylist()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize de Playlists para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilPlaylist(); i++) {
            nuevo_v_playlist[i] = this->playlist_usuario[i];
        }
    } else if(tamanio_nuevo < this->getUtilPlaylist()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize de Playlists para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
        }
        //copio los valores antiguos en el nuevo, que es más pequeño
        for(int i=0; i < tamanio_nuevo; i++) {
            nuevo_v_playlist[i] = this->getPlaylist(i);
        }
    } else if(tamanio_nuevo == this->getUtilPlaylist()) {
        if(this->getTest() == true) {
            cout << DEBUG << "El nuevo tamaño es igual que el anterior, no se realizará ningún cambio" << DEFAULT << endl;
        }
    }
    //3º) Eliminar la Memoria
    if(tamanio_nuevo != this->getUtilPlaylist()) {
        delete [] this->playlist_usuario;
        this->playlist_usuario = nuevo_v_playlist;
        this->setUtilPlaylist(tamanio_nuevo);
    }
}
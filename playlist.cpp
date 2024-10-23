//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#include "playlist.h"
/*CONSTRUCTOR*/
Playlist::Playlist() {
    this->test = true;
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Playlist): Creando la Playlist..." << DEFAULT << endl;
    }

    Tiempo t;

    this->setId(0);
    this->setNombre("NULL");
    this->setUtilCanciones(0);
    this->canciones_playlist = new Cancion*[this->util_canciones];
    if(this->canciones_playlist == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->canciones_playlist[0] = 0;
    t.setMinutos(0);
    t.setSegundos(0);
    this->setDuracion(t);

    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Playlist):Playlist creada correctamente..." << DEFAULT << endl;
    }
}
/*CONSTRUCTOR POR COPIA*/
Playlist::Playlist(const Playlist &p) {
    this->test = p.getTest();
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Playlist): Creando la Playlist por Copia..." << DEFAULT << endl;
    }

    this->setId(p.getId());
    this->setNombre(p.getNombre());
    this->setUtilCanciones(0);
    if(this->canciones_playlist != 0) {
        this->canciones_playlist = 0;
    }
    this->canciones_playlist = new Cancion*[this->util_canciones];
    if(this->canciones_playlist == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    for(int i = 0; i < p.getUtilCanciones(); i++) {
        this->setCanciones(i,p.getCanciones(i));
    }
    this->setDuracion(p.getDuracion());

    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Playlist): Playlist creada correctamente por Copia..." << DEFAULT << endl;
    }

}
/*DESTRUCTOR*/
Playlist::~Playlist() {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(~Playlist): Eliminando la Playlist..." << DEFAULT << endl;
    }

    Tiempo t;

    this->setId(0);
    this->setNombre("NULL");
    for(int i = 0; i < this->getUtilCanciones(); i++) {
        if(this->canciones_playlist[i] != 0) {
            this->canciones_playlist[i] = 0;
        }
        this->eliminarCancion(i);
    }
    if(this->canciones_playlist != 0) {
        delete [] this->canciones_playlist;
        this->canciones_playlist = 0;
    } else {
        cout << DEBUG <<  "Memoria ya liberada con anterioridad." << DEFAULT << endl;
    }
    this->setUtilCanciones(0);
    t.setMinutos(0);
    t.setSegundos(0);
    this->setDuracion(t);

    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(~Playlist): Playlist eliminada correctamente..." << DEFAULT << endl;
    }
}
/*GETS*/
unsigned int Playlist::getId() const {
    return this->id;
}

string Playlist::getNombre() const {
    return this->nombre;
}

Cancion* Playlist::getCanciones(int i) const {
    return this->canciones_playlist[i];
}

int Playlist::getUtilCanciones() const {
    return this->util_canciones;
}

Tiempo Playlist::getDuracion() const {
    return this->duracion_total;
}

bool Playlist::getTest() const {
    return this->test;
}
/*SETS*/
void Playlist::setId(const int id) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setId): Estableciendo el id la Playlist..." << DEFAULT << endl;
    }
    this->id = id;
}

void Playlist::setNombre(const string nombre) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setNombre): Estableciendo el nombre la Playlist..." << DEFAULT << endl;
    }
    this->nombre = nombre;
}

void Playlist::setCanciones(const int i, Cancion *c) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setCanciones): Estableciendo una Canción a la Playlist..." << DEFAULT << endl;
    }
    this->resize(this->getUtilCanciones() + 1);
    this->canciones_playlist[i] = c;
}

void Playlist::eliminarCancion(const int i) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(eliminarCancion): Eliminando una Canción a la Playlist..." << DEFAULT << endl;
    }
    if(this->getUtilCanciones() == 1) {
        this->canciones_playlist[i]->setTotalInclusionesEnPlaylist(this->canciones_playlist[i]->getTotalInclusionesEnPlaylist() - 1);
        this->resize(0);
    } else {
        this->canciones_playlist[i]->setTotalInclusionesEnPlaylist(this->canciones_playlist[i]->getTotalInclusionesEnPlaylist() - 1);
        this->canciones_playlist[i] = this->canciones_playlist[this->getUtilCanciones() - 1];
        this->resize(this->getUtilCanciones() - 1);
    }
}

void Playlist::setUtilCanciones(const int util) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setUtilCanciones): Estableciendo la Util de las Canciones de la Playlist..." << DEFAULT << endl;
    }
    this->util_canciones = util;
}

void Playlist::setDuracion(const Tiempo t) {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(setDuracion): Estableciendo la Duración de la Playlist..." << DEFAULT << endl;
    }
    this->duracion_total = t;
}
/*SOBRECARGA*/
Playlist& Playlist::operator=(const Playlist &p) {
    this->test = p.getTest();
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(operator=): Creando Playlist con Sobrecarga..." << DEFAULT << endl;
    }

    if(this != &p) {
        this->setId(p.getId());
        this->setNombre(p.getNombre());

        this->setUtilCanciones(0);
        if(this->canciones_playlist != 0) {
            delete [] this->canciones_playlist;
        }
        this->canciones_playlist = new Cancion*[this->util_canciones];
        if(this->canciones_playlist == 0) {
            cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
            exit(-1);
        }
        for(int i = 0; i < p.getUtilCanciones(); i++) {
            this->setCanciones(i,p.getCanciones(i));
        }
        this->setDuracion(p.getDuracion());
    }

    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(operator): Playlist creada correctamente con Sobrecarga..." << DEFAULT << endl;
    }
    
    return *this;
}
/*MÉTODO ADICIONAL*/
void Playlist::resize(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize" << DEFAULT << endl;
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
            cout << DEBUG << "Invocando al resize para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilCanciones(); i++) {
            nuevo_v_cancion[i] = this->canciones_playlist[i];
        }
    } else if(tamanio_nuevo < this->getUtilCanciones()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
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
        delete [] this->canciones_playlist;
        this->canciones_playlist = nuevo_v_cancion;
        this->setUtilCanciones(tamanio_nuevo);
    }
}
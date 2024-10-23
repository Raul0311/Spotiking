//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#include "cancion.h"

/*CONSTRUCTOR*/
Cancion::Cancion() {
    this->test = true;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Cancion): Creando la Canción..." << DEFAULT << endl;
    }
    Tiempo t;
    this->setId(0);
    this->setTitulo("NULL");
    this->setUtilArtistas(0);
    this->v_artistas = new Artista*[this->util_artistas];
    if(this->v_artistas == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->v_artistas[0] = 0;

    this->setUtilValoracion(0);
    this->valoracion = new Valoracion*[this->util_valoracion];
    if(this->valoracion == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->valoracion[0] = 0;
    this->setDuracion(t);
    this->setTotalReproducciones(0);
    this->setContador(0);

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Cancion): Canción creada correctamente..." << DEFAULT << endl;
    }
}
/*CONSTRUCTOR POR COPIA*/
Cancion::Cancion(const Cancion &a) {
    this->test = a.test;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Cancion): Creando la Canción por Copia..." << DEFAULT << endl;
    }
    this->setId(a.getId());
    this->setTitulo(a.getTitulo());
    this->setUtilArtistas(0);
    if(this->v_artistas != 0) {
        this->v_artistas = 0;
    }
    this->v_artistas = new Artista*[this->getUtilArtistas()];
    if(this->v_artistas == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    for(int i = 0; i < a.getUtilArtistas(); i++) {
        this->setArtistas(i,a.getArtistas(i));
    }

    if(this->valoracion != 0) {
        this->valoracion = 0;
    }
    this->valoracion = new Valoracion*[this->getUtilValoracion()];
    if(this->valoracion == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    for(int i = 0; i < this->getUtilValoracion(); i++) {
        this->setValoracion(i,a.getValoracion(i));
    }
    this->setDuracion(a.getDuracion());
    this->setTotalReproducciones(a.getTotalReproducciones());

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Cancion): Canción creada correctamente por Copia..." << DEFAULT << endl;
    }
}
/*DESTRUCTOR*/
Cancion::~Cancion() {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(~Cancion): Eliminando la Canción..." << DEFAULT << endl;
    }
    
    Tiempo t;
    this->setId(0);
    this->setTitulo("NULL");
    for(int i = 0; i < this->getUtilArtistas(); i++) {
        if(this->v_artistas[i] != 0) {
            this->v_artistas[i] = 0;
        }
        this->eliminarArtista(i);
    }
    if(this->v_artistas != 0) {
        this->v_artistas = 0;
    } else {
        cout << RED <<  "Memoria ya liberada con anterioridad." << DEFAULT << endl;
    }

    for(int i = 0; i < this->getUtilValoracion(); i++) {
        if(this->valoracion[i] != 0) {
            delete this->valoracion[i];
            this->valoracion[i] = 0;
        }
    }
    if(this->valoracion != 0) {
        delete [] this->valoracion;
        this->valoracion = 0;
    } else {
        cout << RED <<  "Memoria ya liberada con anterioridad." << DEFAULT << endl;
    }
    this->setDuracion(t);
    this->setTotalReproducciones(0);

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(~Cancion): Canción eliminada correctamente..." << DEFAULT << endl;
    }
}
/*GETS*/
unsigned int Cancion::getId() const {
    return this->id;
}

string Cancion::getTitulo() const {
    return this->titulo;
}

string Cancion::getRutaArchivo() const {
    return this->ruta_archivo;
}

Artista* Cancion::getArtistas(int i) const {
    return this->v_artistas[i];
}

int Cancion::getUtilArtistas() const {
    return this->util_artistas;
}

Tiempo Cancion::getDuracion() const {
    return this->duracion;
}

int Cancion::getTotalReproducciones() const {
    return this->total_reproducciones;
}

int Cancion::getTotalInclusionesEnPlaylist() const {
    return this->total_inclusiones_en_playlist;
}

Valoracion* Cancion::getValoracion(int i) const {
    return this->valoracion[i];
}

int Cancion::getUtilValoracion() const {
    return this->util_valoracion;
}

int Cancion::getContador() const {
    return this->contador;
}

double Cancion::getTotalValoracion() const {
    return this->total_valoracion;
}

bool Cancion::getTest() const {
    return this->test;
}
/*SETS*/
void Cancion::setId(const int id) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setId): Estableciendo el id de la Canción..." << DEFAULT << endl;
    }
    this->id = id;
}

void Cancion::setTitulo(const string titulo) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setTitulo): Estableciendo el título de la Canción..." << DEFAULT << endl;
    }
    this->titulo = titulo;
}

void Cancion::setRutaArchivo(const string ruta) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setTitulo): Estableciendo la ruta de la Canción..." << DEFAULT << endl;
    }
    this->ruta_archivo = ruta;
}

void Cancion::setArtistas(const int i, Artista *a) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setArtistas): Estableciendo el Artista de la Canción..." << DEFAULT << endl;
    }
    this->resize(this->getUtilArtistas() + 1);
    this->v_artistas[i] = a;
}

void Cancion::eliminarArtista(const int i) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(eliminarArtistas): Eliminando un Artista de la Canción..." << DEFAULT << endl;
    }
    if(this->getUtilArtistas() == 1) {
        this->resize(0);
        if(this->v_artistas[i] != 0) {
            this->v_artistas[i] = 0;
        }
    } else {
        if(this->v_artistas[i] != 0) {
            this->v_artistas[i] = 0;
        }
        this->v_artistas[i] = this->v_artistas[this->getUtilArtistas() - 1];
        this->resize(this->getUtilArtistas() - 1);
    }
}

void Cancion::setUtilArtistas(const int util) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setUtilArtistas): Estableciendo la util de los artistas de la Canción..." << DEFAULT << endl;
    }
    this->util_artistas = util;
}

void Cancion::setDuracion(const Tiempo duracion) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setDuracion): Estableciendo la duración de la Canción..." << DEFAULT << endl;
    }
    this->duracion = duracion;
}

void Cancion::setTotalReproducciones(const int reproducciones) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setTotalReproducciones): Estableciendo el total de reproducciones de la Canción..." << DEFAULT << endl;
    }
    this->total_reproducciones = reproducciones;
}

void Cancion::setTotalInclusionesEnPlaylist(const int inclusiones) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setTotalInclusionesEnPlaylist): Estableciendo el total de inclusiones en las playlist de la Canción..." << DEFAULT << endl;
    }
    this->total_inclusiones_en_playlist = inclusiones;
}

void Cancion::setValoracion(const int i, Valoracion *val) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setValoracion): Estableciendo la Valoración de la Canción..." << DEFAULT << endl;
    }
    this->resizeValoracion(this->getUtilValoracion() + 1);
    this->valoracion[i] = val;
}

void Cancion::eliminarValoracion(const int i) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(eliminarValoracion): Eliminando la Valoración de la Canción..." << DEFAULT << endl;
    }
    if(this->getUtilValoracion() == 1) {
        this->resizeValoracion(0);
        if(this->valoracion[i] != 0) {
            delete this->valoracion[i];
            this->valoracion[i] = 0;
        }
    } else {
        if(this->valoracion[i] != 0) {
            delete this->valoracion[i];
            this->valoracion[i] = 0;
        }
        this->valoracion[i] = this->valoracion[this->getUtilValoracion() - 1];
        this->resizeValoracion(this->getUtilValoracion() - 1);
    }
}

void Cancion::setUtilValoracion(const int util) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setUtilValoracion): Estableciendo util de la Valoración de la Canción..." << DEFAULT << endl;
    }
    this->util_valoracion = util;
}

void Cancion::setContador(const int cont) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setContador): Estableciendo el Contador de la Canción..." << DEFAULT << endl;
    }
    this->contador = cont;
}

void Cancion::setTotalValoracion(const double totalVal) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setContador): Estableciendo el total de la valoración de la Canción..." << DEFAULT << endl;
    }
    this->total_valoracion = totalVal;
}
/*SOBRECARGA*/
Cancion& Cancion::operator=(const Cancion &c) {
    this->test = c.getTest();
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(operator=): Copiando Canción con Sobrecarga." << DEFAULT << endl;
    }

    if(this != &c) {
        this->setId(c.getId());
        this->setTitulo(c.getTitulo());
        this->setUtilArtistas(0);
        if(this->v_artistas != 0) {
            delete [] this->v_artistas;
        }
        this->v_artistas = new Artista*[c.getUtilArtistas()];
        if(this->v_artistas == 0) {
            cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
            exit(-1);
        }
        for(int i = 0; i < this->getUtilArtistas(); i++) {
            this->setArtistas(i,c.getArtistas(i));
        }
        this->setDuracion(c.getDuracion());
        this->setTotalReproducciones(c.getTotalReproducciones());
    }

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(operator=): Canción copiada correctamente con Sobrecarga." << DEFAULT << endl;
    }

    return *this;
}

void Cancion::escucharCancion() {
    cout << GREEN << "Reproduciendo la canción...\n" << DEFAULT;
}

void Metal::escucharCancion() {
    cout << GREEN << "Reproduciendo la canción de Metal...\n" << DEFAULT;
}

void Pop::escucharCancion() {
    cout << GREEN << "Reproduciendo la canción de Pop...\n" << DEFAULT;
}

void Faraon_Love_Shady::escucharCancion() {
    cout << GREEN << "Reproduciendo la canción de Faraon_Love_shady...\n" << DEFAULT;
}

void Rap::escucharCancion() {
    cout << GREEN << "Reproduciendo la canción de Rap...\n" << DEFAULT;
}
/*MÉTODOS ADICIONALES*/
void Cancion::resize(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize" << DEFAULT << endl;
    }
    
    Artista** nuevo_v_artista;
    //1º) Reservo Memoria
    if(tamanio_nuevo != this->getUtilArtistas() && tamanio_nuevo > this->getUtilArtistas()) {
        nuevo_v_artista = new Artista*[tamanio_nuevo];
        if(nuevo_v_artista == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < tamanio_nuevo; i++) {
            nuevo_v_artista[i] = 0;
        }
    }

    if(tamanio_nuevo != this->getUtilArtistas() && tamanio_nuevo < this->getUtilArtistas()) {
        nuevo_v_artista = new Artista*[this->getUtilArtistas()];
        if(nuevo_v_artista == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < this->getUtilArtistas(); i++) {
            nuevo_v_artista[i] = 0;
        }
    }

    //2º) Copio los valores del vector antiguo en el nuevo (independientemente del tamaño)
    if(tamanio_nuevo > this->getUtilArtistas()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilArtistas(); i++) {
            nuevo_v_artista[i] = this->v_artistas[i];
        }
    } else if(tamanio_nuevo < this->getUtilArtistas()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
        }
        //copio los valores antiguos en el nuevo, que es más pequeño
        for(int i=0; i < tamanio_nuevo; i++) {
            nuevo_v_artista[i] = this->getArtistas(i);
        }
    } else if(tamanio_nuevo == this->getUtilArtistas()) {
        if(this->getTest() == true) {
            cout << DEBUG << "El nuevo tamaño es igual que el anterior, no se realizará ningún cambio" << DEFAULT << endl;
        }
    }
    //3º) Eliminar la Memoria
    if(tamanio_nuevo != this->getUtilArtistas()) {
        delete [] this->v_artistas; 
        this->v_artistas = nuevo_v_artista; 
        this->setUtilArtistas(tamanio_nuevo);
    }
}

void Cancion::resizeValoracion(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize" << DEFAULT << endl;
    }
    
    Valoracion** nuevo_v_valoracion;
    //1º) Reservo Memoria
    if(tamanio_nuevo != this->getUtilValoracion() && tamanio_nuevo > this->getUtilValoracion()) {
        nuevo_v_valoracion = new Valoracion*[tamanio_nuevo];
        if(nuevo_v_valoracion == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < tamanio_nuevo; i++) {
            nuevo_v_valoracion[i] = 0;
        }
    }

    if(tamanio_nuevo != this->getUtilValoracion() && tamanio_nuevo < this->getUtilValoracion()) {
        nuevo_v_valoracion = new Valoracion*[this->getUtilValoracion()];
        if(nuevo_v_valoracion == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < this->getUtilValoracion(); i++) {
            nuevo_v_valoracion[i] = 0;
        }
    }

    //2º) Copio los valores del vector antiguo en el nuevo (independientemente del tamaño)
    if(tamanio_nuevo > this->getUtilValoracion()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilValoracion(); i++) {
            nuevo_v_valoracion[i] = this->valoracion[i];
        }
    } else if(tamanio_nuevo < this->getUtilValoracion()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
        }
        //copio los valores antiguos en el nuevo, que es más pequeño
        for(int i=0; i < tamanio_nuevo; i++) {
            nuevo_v_valoracion[i] = this->getValoracion(i);
        }
    } else if(tamanio_nuevo == this->getUtilValoracion()) {
        if(this->getTest() == true) {
            cout << DEBUG << "El nuevo tamaño es igual que el anterior, no se realizará ningún cambio" << DEFAULT << endl;
        }
    }
    //3º) Eliminar la Memoria
    if(tamanio_nuevo != this->getUtilValoracion()) {
        delete [] this->valoracion; 
        this->valoracion = nuevo_v_valoracion; 
        this->setUtilValoracion(tamanio_nuevo);
    }
}
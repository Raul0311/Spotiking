//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//

#include "artista.h"

/*CONSTRUCTOR*/
Artista::Artista() {
    this->test = true;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Artista): creando el Artista..." << DEFAULT << endl;
    }

    this->setId(0);
    this->setNombre("NULL");
    this->setUtilCanciones(0);
    this->canciones = new Cancion*[this->util_canciones];
    if(this->canciones == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->canciones[0] = 0;

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Artista): Artista creado correctamente..." << DEFAULT << endl;
    }
}
/*CONSTRUCTOR POR COPIA*/
Artista::Artista(const Artista &a) {
    this->test = a.test;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Artista): creando el Artista por Copia..." << DEFAULT << endl;
    }

    this->setId(a.getId());
    this->setNombre(a.getNombre());
    this->setUtilCanciones(0);
    if(this->canciones != 0) {
        this->canciones = 0;
    }
    this->canciones = new Cancion*[this->getUtilCanciones()];
    if(this->canciones == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    for(int i = 0; i < a.getUtilCanciones(); i++) {
            this->setCanciones(i,a.getCanciones(i));
    }
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(Artista): Artista creado correctamente por Copia..." << DEFAULT << endl;
    }
}
/*DESTRUCTOR*/
Artista::~Artista() {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(~Artista): Eliminando el Artista..." << DEFAULT << endl;
    }

    this->setId(0);
    this->setNombre("NULL");
    for(int i = 0; i < this->getUtilCanciones(); i++) {
        if(this->canciones[i] != 0) {
            this->canciones[i] = 0;
        }
        this->eliminarCanciones(i);
    }
    if(this->canciones != 0) {
        delete [] this->canciones;
        this->canciones = 0;
    } else {
        cout << DEBUG <<  "Memoria ya liberada con anterioridad." << DEFAULT << endl;
    }

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(~Artista): Artista eliminado correctamente..." << DEFAULT << endl;
    }
}
/*GETS*/
unsigned int Artista::getId() const {
    return this->id;
}

string Artista::getNombre() const {
    return this->nombre;
}

Cancion* Artista::getCanciones(int i) const {
    return this->canciones[i];
}

int Artista::getUtilCanciones() const {
    return this->util_canciones;
}

int Artista::getTotalInclusiones() const {
    return this->total_inclusiones;
}

double Artista::getMediaValoracion() const {
    return this->media_valoracion;
}

bool Artista::getTest() const {
    return this->test;
}
/*SETS*/
void Artista::setId(const int id) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setId): Estableciendo el id del artista..." << DEFAULT << endl;
    }
    this->id = id;
}

void Artista::setNombre(const string nombre) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setNombre): Estableciendo el nombre del artista..." << DEFAULT << endl;
    }
    this->nombre = nombre;
}

void Artista::setCanciones(const int i, Cancion *c) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setCanciones): Estableciendo cancion en artista..." << DEFAULT << endl;
    }
    this->resize(this->getUtilCanciones() + 1);
    this->canciones[i] = c;
}

void Artista::eliminarCanciones(const int i) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(eliminarCanciones): Eliminando cancion en artista..." << DEFAULT << endl;
    }
    if(this->getUtilCanciones() == 1) {
        this->resize(0);
        if(this->canciones[i] != 0) {
            this->canciones[i] = 0;
        }
    } else {
        if(this->canciones[i] != 0) {
            this->canciones[i] = 0;
        }
        this->canciones[i] = this->canciones[this->getUtilCanciones() - 1];
        this->resize(this->getUtilCanciones() - 1);
    }
}

void Artista::setUtilCanciones(const int util) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setUtilCanciones): Estableciendo la util de las canciones del artista..." << DEFAULT << endl;
    }
    this->util_canciones = util;
}

void Artista::setTotalInclusiones(const int inclusiones) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setTotalInclusiones): Estableciendo las Inclusiones totales de todas las Canciones del artista..." << DEFAULT << endl;
    }
    this->total_inclusiones = inclusiones;
}

void Artista::setMediaValoracion(const double val) {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(setMediaValoracion): Estableciendo la Valoración media del artista..." << DEFAULT << endl;
    }
    this->media_valoracion = val;
}
/*SOBRECARGA DE OPERADORES*/
Artista& Artista::operator=(const Artista &a) {
    this->test = a.getTest();
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(operator=): Copiando artista con Sobrecarga." << DEFAULT << endl;
    }

    if(this != &a) {
        this->setId(a.getId());
        this->setNombre(a.getNombre());
        this->setUtilCanciones(0);
        if(this->canciones != 0) {
            delete [] this->canciones;
        }
        this->canciones = new Cancion*[a.getUtilCanciones()];
        if(this->canciones == 0) {
            cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
            exit(-1);
        }
        for(int i = 0; i < a.getUtilCanciones(); i++) {
            this->setCanciones(i,a.getCanciones(i));
        }
    }

    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(operator=): Artista copiado correctamente con Sobrecarga." << DEFAULT << endl;
    }

    return *this;
}

ostream& operator<<(ostream &flujo, const Artista &a) {
    if(a.getTest() == true) {
        cout << DEBUG <<  "Imprimiendo Artista con Sobrecarga" << DEFAULT << endl;
    }
    
    if(a.getUtilCanciones() == 0 && a.getCanciones(0) == 0) {
        flujo << DEBUG << "Este Artista tiene todos sus valores en 0" << DEFAULT << endl;        
    } else {
        flujo << BLUE << "El nombre del artista es: " << a.getNombre();
    }

    flujo << "\n";

    if(a.getTest() == true) {
        cout << DEBUG <<  "Artista imprimido correctamente con Sobrecarga" << DEFAULT << endl;
    }

    return flujo;
}

istream& operator>>(istream &flujo, Artista &a) {
    string nombre;
    unsigned int id;
    if(a.getTest() == true) {
        cout << DEBUG <<  "Introduciendo el Artista con Sobrecarga" << DEFAULT << endl;
    }

    cout << BLUE << "Introduzca el nombre del aritsa: " << DEFAULT;
    flujo >> nombre;
    a.setNombre(nombre);
    cout << BLUE << "Introduzca el ID del artista: " << DEFAULT;
    do {
        flujo >> id;
        if(id < 0) {
            cout << "El ID no puede ser negativo.\n";
        }
    } while(id < 0);
    a.setId(id);

    if(a.getTest() == true) {
        cout << DEBUG <<  "Artista introducido correctamente con Sobrecarga" << DEFAULT << endl;
    }

    return flujo;
}
/*MÉTODO ADICIONAL*/
void Artista::resize(int tamanio_nuevo) {
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
            nuevo_v_cancion[i] = this->canciones[i];
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
        delete [] this->canciones;
        this->canciones = nuevo_v_cancion;
        this->setUtilCanciones(tamanio_nuevo);
    }
}
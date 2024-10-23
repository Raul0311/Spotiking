//
// Created by Raúl Rodríguez Fernández on 14/05/2022
//
#include "cancion.h"
#include "vista.h"

/*CONSTRUCTOR*/
Vista::Vista() {
    this->test = true;
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Usuario): Creando la Vista..." << DEFAULT << endl;
    }

    this->setUtilArtistasSistema(0);
    this->artistas_sistema = new Artista*[this->util_artistas_sistema];
    if(this->canciones_sistema == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->artistas_sistema[0] = 0;

    this->setUtilcancionesSistema(0);
    this->canciones_sistema = new Cancion*[this->util_canciones_sistema];
    if(this->canciones_sistema == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->canciones_sistema[0] = 0;

    this->setUtilUsuariosSistema(0);
    this->usuarios_sistema = new Usuario*[this->util_usuarios_sistema];
    if(this->usuarios_sistema == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }
    this->usuarios_sistema[0] = 0;

    this->usuario_activo = 0;
    this->admin_activo = 0;
    
    this->setUtilBusquedaArtista(0);
    this->busqueda_artista = new Artista*[this->util_busqueda_artista];
    if(this->busqueda_artista == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }

    this->setUtilBusquedaCancion(0);
    this->busqueda_cancion = new Cancion*[this->util_busqueda_cancion];
    if(this->busqueda_cancion == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }

    this->setUtilBusquedaPlaylist(0);
    this->busqueda_playlist = new Playlist*[this->util_busqueda_playlist];
    if(this->busqueda_playlist == 0) {
        cerr << "No hay espacio suficiente. Se terminará la ejecución del programa." << endl;
        exit(-1);
    }

    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Usuario): Vista creada correctamente..." << DEFAULT << endl;
    }
}
/*DESTRUCTOR*/
Vista::~Vista() {
    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Usuario): Eliminando la Vista..." << DEFAULT << endl;
    }

    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
        if(this->artistas_sistema[i] != 0) {
            delete this->artistas_sistema[i];
            this->artistas_sistema[i] = 0;
        }
        this->eliminarArtista(i);
    }
    if(this->artistas_sistema != 0) {
        delete [] this->artistas_sistema;
        this->artistas_sistema = 0;
    } else {
        cout << RED << "Memoria ya liberada con anterioridad\n" << DEFAULT;
    }
    this->setUtilArtistasSistema(0);
    
    for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
        if(this->canciones_sistema[i] != 0) {
            delete this->canciones_sistema[i];
            this->canciones_sistema[i] = 0;
        }
        this->eliminarCancion(i);
    }
    if(this->canciones_sistema != 0) {
        delete [] this->canciones_sistema;
        this->canciones_sistema = 0;
    } else {
        cout << RED << "Memoria ya liberada con anterioridad\n" << DEFAULT;
    }
    this->setUtilcancionesSistema(0);
    
    
    for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
        if(this->usuarios_sistema[i] != 0) {
            delete this->usuarios_sistema[i];
            this->usuarios_sistema[i] = 0;
        }
        this->eliminarUsuario(i);
    }
    if(this->usuarios_sistema != 0) {
        delete [] this->usuarios_sistema;
        this->usuarios_sistema = 0;
    } else {
        cout << RED << "Memoria ya liberada con anterioridad\n" << DEFAULT;
    }
        this->setUtilUsuariosSistema(0);
    
    if(this->usuario_activo != 0) {
        this->usuario_activo = 0;
    } else {
        cout << RED << "Memoria ya liberada con anterioridad\n" << DEFAULT;
    }

    if(this->admin_activo != 0) {
        this->admin_activo = 0;
    } else {
        cout << RED << "Memoria ya liberada con anterioridad\n" << DEFAULT;
    }
    
    for(int i = 0; i < this->getUtilBusquedaArtista(); i++) {
        if(this->busqueda_artista[i] != 0) {
            this->busqueda_artista[i] = 0;
        }
        this->setBusquedaArtista(i,0);
    }
    if(this->busqueda_artista != 0) {
        this->busqueda_artista = 0;
    } else {
        cout << RED << "Memoria ya liberada con anterioridad\n" << DEFAULT;
    }
    this->setUtilBusquedaArtista(0);
    
    for(int i = 0; i < this->getUtilBusquedaCancion(); i++) {
        if(this->busqueda_cancion[i] != 0) {
            this->busqueda_cancion[i] = 0;
        }
        this->eliminarBusquedaCancion(i);
    }
    if(this->busqueda_cancion != 0) {
        this->busqueda_cancion = 0;
    } else {
        cout << RED << "Memoria ya liberada con anterioridad\n" << DEFAULT;
    }
    this->setUtilBusquedaCancion(0);
    
    for(int i = 0; i < this->getUtilBusquedaPlaylist(); i++) {
        if(this->busqueda_playlist[i] != 0) {
            this->busqueda_playlist[i] = 0;
        }
        this->setBusquedaPlaylist(i,0);
    }
    if(this->busqueda_playlist != 0) {
        this->busqueda_playlist = 0;
    } else {
        cout << RED << "Memoria ya liberada con anterioridad\n" << DEFAULT;
    }
    this->setUtilBusquedaPlaylist(0);

    if(this->test == true) {
        cout << DEBUG <<  "DEBUG(Usuario): Vista eliminada correctamente..." << DEFAULT << endl;
    }
}
/*GETS*/
Usuario* Vista::getUsuarioSistema(int i) const {
    return this->usuarios_sistema[i];
}

int Vista::getUtilUsuariosSistema() const {
    return this->util_usuarios_sistema;
}

Cancion* Vista::getCancionSistema(int i) const {
    return this->canciones_sistema[i];
}

int Vista::getUtilCancionesSistema() const {
    return this->util_canciones_sistema;
}

Artista* Vista::getArtistaSistema(int i) const {
    return this->artistas_sistema[i];
}

int Vista::getUtilArtistasSistema() const {
    return this->util_artistas_sistema;
}

Usuario_comun* Vista::getUsuarioActivo() const {
    return this->usuario_activo;
}

Administrador* Vista::getAdminActivo() const {
    return this->admin_activo;
}

Artista* Vista::getBusquedaArtista(int i) const {
    return this->busqueda_artista[i];
}

int Vista::getUtilBusquedaArtista() const {
    return this->util_busqueda_artista;
}

Cancion* Vista::getBusquedaCancion(int i) const {
    return this->busqueda_cancion[i];
}

int Vista::getUtilBusquedaCancion() const {
    return this->util_busqueda_cancion;
}

Playlist* Vista::getBusquedaPlaylist(int i) const {
    return this->busqueda_playlist[i];
}

int Vista::getUtilBusquedaPlaylist() const {
    return this->util_busqueda_playlist;
}

bool Vista::getTest() const {
    return this->test;
}
/*SETS*/
void Vista::setUsuarioSistema(const int i, Usuario *u) {
    this->resizeUsuariosSistema(this->getUtilUsuariosSistema() + 1);
    this->usuarios_sistema[i] = u;
}

void Vista::eliminarUsuario(const int i) {
    if(this->getUtilUsuariosSistema() == 1) {
        this->resizeUsuariosSistema(0);
    } else {
        this->usuarios_sistema[i] = this->usuarios_sistema[this->getUtilUsuariosSistema() - 1];
        this->resizeUsuariosSistema(this->getUtilUsuariosSistema() - 1);
    }
}

void Vista::setUtilUsuariosSistema(const int util) {
    this->util_usuarios_sistema = util;
}

void Vista::setCancionSistema(const int i, Cancion *c) {
    this->resizeCancionesSistema(this->getUtilCancionesSistema() + 1);
    this->canciones_sistema[i] = c;
}

void Vista::eliminarCancion(const int i) {
    if(this->getUtilCancionesSistema() == 1) {
        this->resizeCancionesSistema(0);
        //delete this->canciones_sistema[i];
    } else {
        //delete this->canciones_sistema[i];
        this->canciones_sistema[i] = this->canciones_sistema[this->getUtilCancionesSistema() - 1];
        this->resizeCancionesSistema(this->getUtilCancionesSistema() - 1);
    }
}

void Vista::setUtilcancionesSistema(const int util) {
    this->util_canciones_sistema = util;
}

void Vista::setArtistaSistema(const int i, Artista *a) {
    this->resizeArtistasSistema(this->getUtilArtistasSistema() + 1);
    this->artistas_sistema[i] = a;
}

void Vista::eliminarArtista(const int i) {
    if(this->getUtilArtistasSistema() == 1) {
        this->resizeArtistasSistema(0);
        delete [] this->artistas_sistema;
    } else {
        this->artistas_sistema[i] = this->artistas_sistema[this->getUtilArtistasSistema() - 1];
        this->resizeArtistasSistema(this->getUtilArtistasSistema() - 1);
    }
}

void Vista::setUtilArtistasSistema(const int util) {
    this->util_artistas_sistema = util;
}

void Vista::setUsuarioActivo(Usuario_comun *u) {
    this->usuario_activo = u;
}

void Vista::setAdminActivo(Administrador *a) {
    this->admin_activo = a;
}

void Vista::setBusquedaArtista(const int i, Artista *a) {
    this->busqueda_artista[i] = a;
}

void Vista::setUtilBusquedaArtista(const int util) {
    this->util_busqueda_artista = util;
}

void Vista::setBusquedaCancion(const int i, Cancion *c) {
    this->resizeBusquedaCanciones(this->getUtilBusquedaCancion() + 1);
    this->busqueda_cancion[i] = c;
}

void Vista::eliminarBusquedaCancion(const int i) {
    if(this->getUtilBusquedaCancion() == 1) {
        this->resizeBusquedaCanciones(0);
    } else {
        this->busqueda_cancion[i] = this->busqueda_cancion[this->getUtilBusquedaCancion() - 1];
        this->resizeBusquedaCanciones(this->getUtilBusquedaCancion() - 1);
    }
}

void Vista::setUtilBusquedaCancion( const int util) {
    this->util_busqueda_cancion = util;
}

void Vista::setBusquedaPlaylist(const int i, Playlist *p) {
    this->busqueda_playlist[i] = p;
}

void Vista::setUtilBusquedaPlaylist(const int util) {
    this->util_busqueda_playlist = util;
}
/*MÉTODOS*/
void Vista::cargarArtistas() {
    Artista *a = new Artista;
    a->setId(0);
    a->setNombre("Five Finger Death Funch");
    this->setArtistaSistema(0,a);
    a = new Artista;
    a->setId(1);
    a->setNombre("Faraon Love Shady");
    this->setArtistaSistema(1,a);
    a = new Artista;
    a->setId(2);
    a->setNombre("Eminem");
    this->setArtistaSistema(2,a);
    a = new Artista;
    a->setId(3);
    a->setNombre("Juice WRLD");
    this->setArtistaSistema(3,a);
    a = new Artista;
    a->setId(4);
    a->setNombre("Michael Jackson");
    this->setArtistaSistema(4,a);
    a = new Artista;
    a->setId(5);
    a->setNombre("Twenty One Pilots");
    this->setArtistaSistema(5,a);
    a = new Artista;
    a->setId(6);
    a->setNombre("Coolio");
    this->setArtistaSistema(6,a);
    a = new Artista;
    delete a;
    a = 0;
}

void Vista::cargarCanciones() {
    Tiempo t;
    Metal *m = new Metal;
    Rap *r = new Rap;
    Faraon_Love_Shady *f = new Faraon_Love_Shady;
    Pop *p = new Pop;
    
    m->setId(0);
    m->setTitulo("Inside Out");
    m->setRutaArchivo("->/canciones/metal/InsideOut->mp3");
    m->setArtistas(0,this->getArtistaSistema(0));
    t.setMinutos(3);
    t.setSegundos(46);
    m->setDuracion(t);
    m->setTotalReproducciones(3897);
    m->setTotalInclusionesEnPlaylist(1);
    this->setCancionSistema(0,m);
    m = 0;
    m = new Metal;

    m->setId(1);
    m->setTitulo("House of the Rising Sung");
    m->setRutaArchivo("->/canciones/metal/HouseOfTheRisingSung->mp3");
    m->setArtistas(0,this->getArtistaSistema(0));
    t.setMinutos(4);
    t.setSegundos(07);
    m->setDuracion(t);
    m->setTotalReproducciones(5213);
    m->setTotalInclusionesEnPlaylist(1);
    this->setCancionSistema(1,m);
    m = 0;
    delete m;
    
    r->setId(2);
    r->setTitulo("The Real Slim Shady");
    r->setRutaArchivo("->/canciones/rap/TheRealSlimShady->mp3");
    r->setArtistas(0,this->getArtistaSistema(2));
    t.setMinutos(4);
    t.setSegundos(44);
    r->setDuracion(t);
    r->setTotalReproducciones(9172);
    r->setTotalInclusionesEnPlaylist(1);
    this->setCancionSistema(2,r);
    r = 0;
    r = new Rap;

    f->setId(3);
    f->setTitulo("I am happy");
    f->setRutaArchivo("->/canciones/faraonShady/IamHappy->mp3");
    f->setArtistas(0,this->getArtistaSistema(1));
    t.setMinutos(2);
    t.setSegundos(15);
    f->setDuracion(t);
    f->setTotalReproducciones(9028);
    f->setTotalInclusionesEnPlaylist(0);
    this->setCancionSistema(3,f);
    f = 0;
    delete f;
    
    r->setId(4);
    r->setTitulo("Godzilla");
    r->setRutaArchivo("->/canciones/rap/Godzilla->mp3");
    r->setArtistas(0,this->getArtistaSistema(2));
    r->setArtistas(1,this->getArtistaSistema(3));
    t.setMinutos(3);
    t.setSegundos(31);
    r->setDuracion(t);
    r->setTotalReproducciones(6523);
    r->setTotalInclusionesEnPlaylist(0);
    this->setCancionSistema(4,r);
    r = 0;
    r = new Rap;

    p->setId(5);
    p->setTitulo("Billie Jean");
    p->setRutaArchivo("->/canciones/pop/BillieJean->mp3");
    p->setArtistas(0,this->getArtistaSistema(4));
    t.setMinutos(4);
    t.setSegundos(53);
    p->setDuracion(t);
    p->setTotalReproducciones(12559);
    p->setTotalInclusionesEnPlaylist(1);
    this->setCancionSistema(5,p);
    p = 0;
    p = new Pop;
    
    p->setId(6);
    p->setTitulo("Beat it");
    p->setRutaArchivo("->/canciones/pop/BeatIt->mp3");
    p->setArtistas(0,this->getArtistaSistema(4));
    t.setMinutos(4);
    t.setSegundos(16);
    p->setDuracion(t);
    p->setTotalReproducciones(12559);
    p->setTotalInclusionesEnPlaylist(1);
    this->setCancionSistema(6,p);
    p = 0;
    p = new Pop;

    p->setId(7);
    p->setTitulo("Stressed Out");
    p->setRutaArchivo("->/canciones/pop/StressedOut->mp3");
    p->setArtistas(0,this->getArtistaSistema(5));
    t.setMinutos(3);
    t.setSegundos(22);
    p->setDuracion(t);
    p->setTotalReproducciones(4982);
    p->setTotalInclusionesEnPlaylist(2);
    this->setCancionSistema(7,p);
    p = 0;
    delete p;
    
    r->setId(8);
    r->setTitulo("Gangstas Paradise");
    r->setRutaArchivo("->/canciones/rap/GangstasParadise->mp3");
    r->setArtistas(0,this->getArtistaSistema(6));
    t.setMinutos(4);
    t.setSegundos(00);
    r->setDuracion(t);
    r->setTotalReproducciones(6543);
    r->setTotalInclusionesEnPlaylist(4);
    this->setCancionSistema(8,r);
    r = 0;
    delete r;

    this->getArtistaSistema(0)->setCanciones(0,this->getCancionSistema(0));
    this->getArtistaSistema(0)->setCanciones(1,this->getCancionSistema(1));

    this->getArtistaSistema(2)->setCanciones(0,this->getCancionSistema(2));

    this->getArtistaSistema(1)->setCanciones(0,this->getCancionSistema(3));

    this->getArtistaSistema(2)->setCanciones(1,this->getCancionSistema(4));
    this->getArtistaSistema(3)->setCanciones(0,this->getCancionSistema(4));

    this->getArtistaSistema(4)->setCanciones(0,this->getCancionSistema(5));

    this->getArtistaSistema(4)->setCanciones(1,this->getCancionSistema(6));

    this->getArtistaSistema(5)->setCanciones(0,this->getCancionSistema(7));

    this->getArtistaSistema(6)->setCanciones(0,this->getCancionSistema(8));
}

void Vista::cargarUsuarios() {
    Usuario_comun *uc = new Usuario_comun;
    Administrador *a = new Administrador;
    Playlist *p = new Playlist;
    Tiempo t;
    Valoracion *v = new Valoracion;
    
    a->setId(2);
    a->setLogin("neozizou");
    a->setPassword("zizougod");
    this->setUsuarioSistema(0,a);
    a = new Administrador;

    uc->setId(0);
    uc->setLogin("delegado");
    uc->setPassword("quecaloh12");
    uc->setCanciones(0,this->getCancionSistema(0));
    v->setNombre("delegado");
    v->setValoracion(5);
    uc->getCanciones(0)->setValoracion(0,v);
    v = new Valoracion;
    uc->getCanciones(0)->setContador(1);

    uc->setCanciones(1,this->getCancionSistema(1));
    v->setNombre("delegado");
    v->setValoracion(3);
    uc->getCanciones(1)->setValoracion(0,v);
    v = new Valoracion;
    uc->getCanciones(1)->setContador(1);

    uc->setCanciones(2,this->getCancionSistema(2));
    v->setNombre("delegado");
    v->setValoracion(2);
    uc->getCanciones(2)->setValoracion(0,v);
     v = new Valoracion;
    uc->getCanciones(2)->setContador(1);

    uc->setCanciones(3,this->getCancionSistema(8));
    v->setNombre("delegado");
    v->setValoracion(5);
    uc->getCanciones(3)->setValoracion(0,v);
    v = new Valoracion;
    uc->getCanciones(3)->setContador(1);

    p->setId(0);
    p->setNombre("Metal-FFDP");
    p->setCanciones(0,this->getCancionSistema(0));
    p->setCanciones(1,this->getCancionSistema(1));
    p->setCanciones(2,this->getCancionSistema(8));
    t.setMinutos(11);
    t.setSegundos(53);
    p->setDuracion(t);
    uc->setPlaylist(0,p);
    p = new Playlist;

    p->setId(1);
    p->setNombre("Rap");
    p->setCanciones(0,this->getCancionSistema(2));
    p->setCanciones(1,this->getCancionSistema(8));
    t.setMinutos(8);
    t.setSegundos(44);
    p->setDuracion(t);
    uc->setPlaylist(1,p);
    p = new Playlist;

    p->setId(2);
    p->setNombre("Twenty One Pilots");
    p->setCanciones(0,this->getCancionSistema(7));
    p->setCanciones(1,this->getCancionSistema(8));
    t.setMinutos(7);
    t.setSegundos(22);
    p->setDuracion(t);
    uc->setPlaylist(2,p);
    p = new Playlist;

    this->setUsuarioSistema(1,uc);
    uc = new Usuario_comun;
    
    uc->setId(1);
    uc->setLogin("tifurz");
    uc->setPassword("elyayo");
    uc->setCanciones(0,this->getCancionSistema(3));
    v->setNombre("tifurz");
    v->setValoracion(2);
    uc->getCanciones(0)->setValoracion(0,v);
    v = new Valoracion;
    uc->getCanciones(0)->setContador(1);

    uc->setCanciones(1,this->getCancionSistema(5));
    v->setNombre("tifurz");
    v->setValoracion(5);
    uc->getCanciones(1)->setValoracion(0,v);
    v = new Valoracion;
    uc->getCanciones(1)->setContador(1);

    p->setId(0);
    p->setNombre("Pop");
    p->setCanciones(0,this->getCancionSistema(5));
    p->setCanciones(1,this->getCancionSistema(6));
    p->setCanciones(2,this->getCancionSistema(7));
    p->setCanciones(3,this->getCancionSistema(8));
    t.setMinutos(16);
    t.setSegundos(31);
    p->setDuracion(t);
    uc->setPlaylist(0,p);

    this->setUsuarioSistema(2,uc);
    uc = new Usuario_comun;
    p = new Playlist;

    delete a;
    a = 0;

    delete p;
    p = 0;

    delete uc;
    uc = 0;

    delete v;
    v = 0;
}

void Vista::cargarDatosPorDefecto() {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(cargarDatosPorDefecto): Cargando los datos básicos del sistema..." << DEFAULT << endl;
    }
    this->cargarArtistas();
    this->cargarCanciones();
    this->cargarUsuarios();
    
    /*cout << BLUE << "Artistas:\n" << DEFAULT;
    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
        cout << GREEN << this->getArtistaSistema(i)->getNombre() << DEFAULT << endl;
        for(int j = 0; j < this->getArtistaSistema(i)->getUtilCanciones(); j++) {
            cout << this->getArtistaSistema(i)->getCanciones(j)->getTitulo() << endl;
        }
    }
    cout << BLUE << "\nCanciones:\n" << DEFAULT;
    for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
        cout << GREEN << this->getCancionSistema(i)->getTitulo() << DEFAULT << endl;
    }
    cout << BLUE << "\nUsuarios:\n" << DEFAULT;
    for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
        cout << GREEN << this->getUsuarioSistema(i)->getLogin() << DEFAULT << endl;
    }*/
    
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(cargarDatosPorDefecto): Datos básicos del sistema cargados correctamente..." << DEFAULT << endl;
    }
}

void Vista::menuSistema() {
    int i = 0;
    string login, password;
    bool encontrado = false;
    do {
        cout << BLUE << "Introduzca el nombre del usuario: \n" << DEFAULT;
        cin >> login;
        cout << BLUE << "Introduzca la contraseña del usuario: \n" DEFAULT;
        cin >> password;

        for(i = 0; i < this->getUtilUsuariosSistema() && encontrado == false; i++) {
            if(login == this->getUsuarioSistema(i)->getLogin() && password == this->getUsuarioSistema(i)->getPassword()) {
                encontrado = true;
            } else {
                encontrado = false;
            }
        }
        i--;
        if(encontrado == true) {
            if(this->admin_activo = dynamic_cast<Administrador*>(this->usuarios_sistema[i])) {
                menuAdministrador();
            }
            if(this->usuario_activo = dynamic_cast<Usuario_comun*>(this->usuarios_sistema[i])) {
                menuUsuarioComun();
            }
        } else {
            cout << RED << "Usuario incorrecto \n" << DEFAULT;
        }
    } while(encontrado == false);
}

void Vista::menuAdministrador() {
    int option;
    do {
        cout << BLUE << "BIENVENIDO AL SISTEMA SPOTY-KING\n";
        cout << "USUARIO ACTIVO: " << this->admin_activo->getLogin() << DEFAULT << endl;

        cout << YELLOW << "Pulse el número de la acción que desee realizar: \n" << DEFAULT;
        cout << BLUE << "1. Cambiar de usuario.\n";
        cout << "2. Imprimir datos generales del sistema.\n";
        cout << "3. Rankings\n";
        cout << "4. Opciones del Catálogo de canciones del sistema\n";
        cout << "5. Opciones de los Usuarios\n";
        cout << "6. Opciones de las Playlsits\n";
        cout << "7. Destruir y salir\n" << DEFAULT;
        cin >> option;
        switch(option) {
            case 1:
                this->admin_activo = 0;
                this->menuSistema();
                this->~Vista();
                exit(-1);
                break;
            case 2:
                imprimirDatos();
                break;
            case 3:
                rankings();
                break;
            case 4:
                opcionesCatalogo();
                break;
            case 5:
                opcionesUsuario();
                break;
            case 6:
                opcionesPlaylist();
                break;
            case 7:
                cout << GREEN << "Gracias por usar SPOTY-KING\n" << DEFAULT;
                break;
        }
    } while(option != 7);
}

void Vista::imprimirDatos() {
    cout << BLUE << "Artistas del Sistema: " << DEFAULT << endl;
    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
        cout << GREEN << "Id del Artista: " << this->getArtistaSistema(i)->getId() << endl;
        cout << "Nombre del Artitsta: " << this->getArtistaSistema(i)->getNombre() << DEFAULT << endl << endl;
    }

    cout << BLUE << "\nCanciones del Sistema:\n" << DEFAULT;
    for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
        cout << GREEN << "Id de la Canción: " << this->getCancionSistema(i)->getId() << endl;
        cout << "Título de la Canción: " << this->getCancionSistema(i)->getTitulo() << endl;
        cout << "Duración de la Canción: " << this->getCancionSistema(i)->getDuracion().getMinutos() << ":" << this->getCancionSistema(i)->getDuracion().getSegundos() << endl;
        cout << "Ruta de la Canción: " << this->getCancionSistema(i)->getRutaArchivo() << endl;
        cout << "Aritistas de la Canción: " << DEFAULT << endl;
        for(int j = 0; j < this->getCancionSistema(i)->getUtilArtistas(); j++) {
            cout << CYAN << "\tId del Artista: " << this->getCancionSistema(i)->getArtistas(j)->getId() << endl;
            cout << "\tNombre del Artista: " << this->getCancionSistema(i)->getArtistas(j)->getNombre() << DEFAULT << endl;
        }
        cout << GREEN << "Total de reproducciones de la Canción: " << this->getCancionSistema(i)->getTotalReproducciones() << endl;
        cout << "Total inclusiones de la Canción en Playlists: " << this->getCancionSistema(i)->getTotalInclusionesEnPlaylist() << endl;
        cout << "Valoración media de los Artistas: " << this->getCancionSistema(i)->getTotalValoracion() << DEFAULT << endl << endl;
    }

    cout << BLUE << "\nUsuarios del Sistema:\n" << DEFAULT;
    for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
        cout << GREEN << "Id del Usuario: " << this->getUsuarioSistema(i)->getId() << endl;
        cout << "Login del Usuario: " << this->getUsuarioSistema(i)->getLogin() << DEFAULT << endl << endl;
        if(Usuario_comun *uc = dynamic_cast<Usuario_comun*>(this->getUsuarioSistema(i))) {
            for(int j = 0; j < uc->getUtilPlaylist(); j++) {
                cout << CYAN << "\tId de la Playlist: " << uc->getPlaylist(j)->getId() << endl;
                cout << "\tNombre de la Playlist: " << uc->getPlaylist(j)->getNombre() << endl;
                cout << "\tDuración total de la Playlist: " << uc->getPlaylist(j)->getDuracion().getMinutos() << ":" << uc->getPlaylist(j)->getDuracion().getSegundos() << endl;
                cout << "\tCanciones: \n" << DEFAULT;
                for(int k = 0; k < uc->getPlaylist(j)->getUtilCanciones(); k++) {
                    cout << MAGENTA << "\t\tTítulo de la canción: " << uc->getPlaylist(j)->getCanciones(k)->getTitulo() << DEFAULT << endl;
                }
                cout << endl;
            }
        }
    }
}

void Vista::rankings() {
    int option;
    cout << BLUE << "¿Qué ranking quiere consultar?\n";
    cout << "1. Ranking 1 - Top3 General Canciones\n";
    cout << "2. Ranking 2 - top3 por Tipo de Canción\n";
    cout << "3. Ranking 3 - Artistas\n" << DEFAULT;
    cin >> option;
    switch(option) {
        case 1:
            rankingGeneral();
            break;
        case 2:
            rankingPorTipo();
            break;
        case 3:
            rankingArtistas();
            break;
    }
}

Cancion** Vista::calcularRanking() {
    int util = this->getUtilCancionesSistema();
    Cancion* c = new Cancion;
    Cancion** v_cancion = new Cancion*[util];
    double valoracionMedia = 0.0, mediaRepro = 0.0, mediaInclu = 0.0, totalRepros = 0.0, totalInclu = 0.0;

    for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
        totalRepros += this->getCancionSistema(i)->getTotalReproducciones();
        totalInclu += this->getCancionSistema(i)->getTotalInclusionesEnPlaylist();
    }
    for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
        valoracionMedia = 0.0;
        mediaRepro = 0.0;
        mediaInclu = 0.0;
        for(int j = 0; j < this->getCancionSistema(i)->getUtilValoracion(); j++) {
            valoracionMedia += this->getCancionSistema(i)->getValoracion(j)->getValoracion();
        }
        if(valoracionMedia > 0 && this->getCancionSistema(i)->getContador() > 0) {
            valoracionMedia = (1.0 * valoracionMedia) / this->getCancionSistema(i)->getContador();
        } else {
            valoracionMedia = 0.0;
        }
        if(this->getCancionSistema(i)->getTotalReproducciones() > 0 && totalRepros > 0) {
            mediaRepro = (1.0 * this->getCancionSistema(i)->getTotalReproducciones()) / totalRepros;
        } else {
            mediaRepro = 0.0;
        }
        if(this->getCancionSistema(i)->getTotalInclusionesEnPlaylist() > 0 && totalInclu > 0) {
            mediaInclu = (1.0 * this->getCancionSistema(i)->getTotalInclusionesEnPlaylist()) / totalInclu;
        } else {
            mediaInclu = 0.0;
        }
        this->getCancionSistema(i)->setTotalValoracion(valoracionMedia + mediaRepro + mediaInclu);
    }

    for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
        v_cancion[i] = this->canciones_sistema[i];
    }

    int izq = 1,i;
    Cancion* aux = 0;
        
    for(izq = 1; izq < util; izq++){
            
        aux = v_cancion[izq];
            
        for(i = izq; i > 0 && aux->getTotalValoracion() > v_cancion[i-1]->getTotalValoracion(); i--) {
            v_cancion[i] = v_cancion[i-1];
        }
        v_cancion[i] = aux;
    }

    return v_cancion;
}

void Vista::rankingGeneral() {
    if(this->getUtilCancionesSistema() > 0) {
        Cancion** v_cancion = this->calcularRanking();
        for(int i = 0; i < 3; i++) {
            cout << GREEN << "Top " << i + 1 << ": " << v_cancion[i]->getTitulo() << endl;
            cout << "Total valoración: " << v_cancion[i]->getTotalValoracion() << DEFAULT << endl << endl;
        }
    } else {
        cout << RED << "No hay Canciones en el Sistema para realiar el ranking.\n" << DEFAULT;
    }
}

void Vista::rankingPorTipo() {
    int option;
    do {
        cout << BLUE << "¿De qué tipo de Canción quiere ver el ranking?\n";
        cout << "1. Metal\n";
        cout << "2. Rap\n";
        cout << "3. Pop\n";
        cout << "4. Faraon Love Shady\n" << DEFAULT;
        cin >> option;
    } while(option < 0 || option > 4);
    switch(option) {
        case 1:
            this->rankingMetal();
            break;
        case 2:
            this->rankingRap();
            break;
        case 3:
            this->rankingPop();
            break;
        case 4:
            this->rankingFaraon();
            break;
    }
}

void Vista::rankingMetal() {
    int contador = 1;
    if(this->getUtilCancionesSistema() > 0) {
        Cancion** v_cancion = this->calcularRanking();
        for(int i = 0; i < this->getUtilCancionesSistema() && contador <= 3; i++) {
            if(dynamic_cast<Metal*>(v_cancion[i])) {
                cout << GREEN << "Top " << contador << ": " << v_cancion[i]->getTitulo() << endl;
                cout << "Total valoración: " << v_cancion[i]->getTotalValoracion() << DEFAULT << endl << endl;
                contador++;
            }
        }
        if(contador == 1) {
            cout << RED << "No hay canciones de este tipo para hacer el ranking.\n" << DEFAULT;
        }
    } else {
        cout << RED << "No hay Canciones en el Sistema para realiar el ranking.\n" << DEFAULT;
    }
}

void Vista::rankingRap() {
    int contador = 1;
    if(this->getUtilCancionesSistema() > 0) {
        Cancion** v_cancion = this->calcularRanking();
        for(int i = 0; i < this->getUtilCancionesSistema() && contador <= 3; i++) {
            if(dynamic_cast<Rap*>(v_cancion[i])) {
                cout << GREEN << "Top " << contador << ": " << v_cancion[i]->getTitulo() << endl;
                cout << "Total valoración: " << v_cancion[i]->getTotalValoracion() << DEFAULT << endl << endl;
                contador++;
            }
        }
        if(contador == 1) {
            cout << RED << "No hay canciones de este tipo para hacer el ranking.\n" << DEFAULT;
        }
    } else {
        cout << RED << "No hay Canciones en el Sistema para realiar el ranking.\n" << DEFAULT;
    }
}

void Vista::rankingPop() {
    int contador = 1;
    if(this->getUtilCancionesSistema() > 0) {
        Cancion** v_cancion = this->calcularRanking();
        for(int i = 0; i < this->getUtilCancionesSistema() && contador <= 3; i++) {
            if(dynamic_cast<Pop*>(v_cancion[i])) {
                cout << GREEN << "Top " << contador << ": " << v_cancion[i]->getTitulo() << endl;
                cout << "Total valoración: " << v_cancion[i]->getTotalValoracion() << DEFAULT << endl << endl;
                contador++;
            }
        }
        if(contador == 1) {
            cout << RED << "No hay canciones de este tipo para hacer el ranking.\n" << DEFAULT;
        }
    } else {
        cout << RED << "No hay Canciones en el Sistema para realiar el ranking.\n" << DEFAULT;
    }
}

void Vista::rankingFaraon() {
    int contador = 1;
    if(this->getUtilCancionesSistema() > 0) {
        Cancion** v_cancion = this->calcularRanking();
        for(int i = 0; i < this->getUtilCancionesSistema() && contador <= 3; i++) {
            if(dynamic_cast<Faraon_Love_Shady*>(v_cancion[i])) {
                cout << GREEN << "Top " << contador << ": " << v_cancion[i]->getTitulo() << endl;
                cout << "Total valoración: " << v_cancion[i]->getTotalValoracion() << DEFAULT << endl << endl;
                contador++;
            }
        }
        if(contador == 1) {
            cout << RED << "No hay canciones de este tipo para hacer el ranking.\n" << DEFAULT;
        }
    } else {
        cout << RED << "No hay Canciones en el Sistema para realiar el ranking.\n" << DEFAULT;
    }
}

void Vista::rankingArtistas() {
    int util = this->getUtilArtistasSistema();
    int totalInclusiones = 0;
    double mediaValoracion = 0;
    Artista** a = new Artista*[util];
    this->calcularRanking();

    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
        mediaValoracion = 0;
        for(int j = 0; j < this->getArtistaSistema(i)->getUtilCanciones(); j++) {
            mediaValoracion += this->getArtistaSistema(i)->getCanciones(j)->getTotalValoracion();
        }
        if(mediaValoracion > 0 && this->getArtistaSistema(i)->getUtilCanciones() > 0) {
            mediaValoracion = mediaValoracion / this->getArtistaSistema(i)->getUtilCanciones();
            this->getArtistaSistema(i)->setMediaValoracion(mediaValoracion);
        } else {
            mediaValoracion = 0;
            this->getArtistaSistema(i)->setMediaValoracion(mediaValoracion);
        }
    }
    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
        a[i] = this->getArtistaSistema(i);
    }

    int izq = 1,i;
    Artista *aux = 0;
        
    for(izq = 1; izq < this->getUtilArtistasSistema(); izq++){
            
        aux = a[izq];
            
        for(i = izq; i > 0 && aux->getMediaValoracion() > a[i-1]->getMediaValoracion(); i--) {
            a[i] = a[i-1];
        }
        a[i] = aux;
    }

    cout << GREEN << "El Artista Hard-Worker es: " << a[0]->getNombre() << endl;
    cout << "Su valoración media es: " << a[0]->getMediaValoracion() << DEFAULT << endl << endl;
    a = 0;
    delete [] a;
    a = new Artista*[util];

    aux = 0;
    delete aux;
    aux = new Artista;

    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
        totalInclusiones = 0;
        for(int j = 0; j < this->getArtistaSistema(i)->getUtilCanciones(); j++) {
            totalInclusiones += this->getArtistaSistema(i)->getCanciones(j)->getTotalInclusionesEnPlaylist();
        }
        this->getArtistaSistema(i)->setTotalInclusiones(totalInclusiones);
    }
    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
        a[i] = this->getArtistaSistema(i);
    }

    for(izq = 1; izq < this->getUtilArtistasSistema(); izq++){
            
        aux = a[izq];
            
        for(i = izq; i > 0 && aux->getTotalInclusiones() > a[i-1]->getTotalInclusiones(); i--) {
            a[i] = a[i-1];
        }
        a[i] = aux;
    }

    cout << GREEN "El Artista Mr. Delegado es: " << a[0]->getNombre() << endl;
    cout << "Total inclusiones de las Canciones de su Catálogo: " << a[0]->getTotalInclusiones() << endl << endl;

    for(izq = 1; izq < this->getUtilArtistasSistema(); izq++){
            
        aux = a[izq];
            
        for(i = izq; i > 0 && aux->getTotalInclusiones() < a[i-1]->getTotalInclusiones(); i--) {
            a[i] = a[i-1];
        }
        a[i] = aux;
    }
    
    cout << GREEN "El Artista Faraón-Migue es: " << a[0]->getNombre() << endl;
    cout << "Total inclusiones de las Canciones de su Catálogo: " << a[0]->getTotalInclusiones() << DEFAULT << endl;
}

void Vista::opcionesCatalogo() {
    int option;
    do {
        cout << BLUE << "¿Qué desea realizar?\n";
        cout << "1. Agregar Nueva Canción al Catálogo del Sistema\n";
        cout << "2. Eliminar Canción del Catálogo del Sistema\n";
        cout << "3. Buscar Canciones en el Catálogo del Sistema\n";
        cout << "4. Modificar Datos de la Canción en el Catálogo del Sistema\n";
        cout << "5. Consultar Valoración Media de la Canción en el Catálogo del Sistema\n";
        cout << "6. Volver al menú principal\n" << DEFAULT;
        cin >> option;
        switch(option) {
            case 1:
                agregarCancionCatalogo();
                break;
            case 2:
                eliminarCancionCatalogo();
                break;
            case 3:

                break;
            case 4:
                modificarCancion();
                break;
            case 5:

                break;
            case 6:
                cout << BLUE << "Volviendo al menú principal...\n" << DEFAULT;
                break;
        }
    } while(option != 6);
}

void Vista::agregarCancionCatalogo() {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(agregarCancionCatalogo): Agregando una Canción al Catálogo del Sistema..." << DEFAULT << endl;
    }
    Tiempo t;
    Cancion *c = new Cancion;
    int id,option,option2,minutos,segundos;
    string titulo,ruta_archivo;
    bool encontrada = false;
    cout << BLUE << "Id de la Canción: " << DEFAULT;
    
    while(!(cin>>id) || (id < 0 || id > this->getUtilCancionesSistema())) {
        cout << RED << "Valor invalido\n" << DEFAULT;
        cin.clear();
        cin.ignore(10000,'\n');
    }

    cin.clear();
    cin.ignore(10000,'\n');

    c->setId(id);

    cout << BLUE << "Título de la Canción: " << DEFAULT;
    getline(cin,titulo);
    c->setTitulo(titulo);

    cout << BLUE << "Ruta de la canción: " << DEFAULT;
    getline(cin,ruta_archivo);
    c->setRutaArchivo(ruta_archivo);

    cout << BLUE << "Minutos: " << DEFAULT;
    cin >> minutos;
    cout << BLUE << "Segundos: " << DEFAULT;
    cin >> segundos;
    t.convertiraMinutosySegundos(minutos,segundos);
    c->setDuracion(t);

    cout << RED << "El total de reproducciones se pondrá a 0.\n" << DEFAULT;
    c->setTotalReproducciones(0);
    this->setCancionSistema(this->getUtilCancionesSistema(),c);

    do {
        cout << BLUE << "1. Introducir un artista\n";
        cout << "2. Seguir insertando los datos de la canción\n" << DEFAULT;
        cin >> option;
        switch(option) {
            case 1:
                do {
                    cout << BLUE << "¿Qué Artista quiere insertar?\n" << DEFAULT;
                    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
                        cout << BLUE << i + 1 << ". " << this->getArtistaSistema(i)->getNombre() << DEFAULT << endl;
                    }
                    cin >> option2;
                    option2--;
                    if(option2 < 0 || option2 > this->getUtilArtistasSistema() - 1) {
                        cout << RED << "Artista no válido.\n" << DEFAULT; 
                    }
                } while(option2 < 0 || option2 > this->getUtilArtistasSistema() - 1);
                encontrada = false;
                for(int i = 0; i < this->getArtistaSistema(option2)->getUtilCanciones() && encontrada == false; i++) {
                    if(c->getTitulo() == this->getArtistaSistema(option2)->getCanciones(i)->getTitulo()) {
                        encontrada = true;
                    }
                }
                if(encontrada == true) {
                    cout << RED << "Ya ha introducido este Artista en la Canción.\n" << DEFAULT;
                } else {
                    this->getArtistaSistema(option2)->setCanciones(this->getArtistaSistema(option2)->getUtilCanciones(),c);
                    c->setArtistas(c->getUtilArtistas(),this->getArtistaSistema(option2));
                }
                break;
            case 2:
                cout << BLUE << "Continuando con los datos de la canción..\n" << DEFAULT;
                break;
        }
    } while(option != 2);

    c = 0;
    delete c;
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(agregarCancionCatalogo): Canción agregada correctamente al Catálogo del Sistema..." << DEFAULT << endl;
    }
}

void Vista::eliminarCancionCatalogo() {
    Tiempo t;
    int option;
    bool encontrada = false, encontrada2 = false;
    cout << BLUE << "¿Qué canción desea eliminar?\n" << DEFAULT;
    if(this->getUtilCancionesSistema() > 0) {
        do {
            for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
                cout << BLUE << i + 1 << ". " << this->getCancionSistema(i)->getTitulo() << DEFAULT << endl;
            }
            cin >> option;
            option--;
            if(option < 0 || option > this->getUtilCancionesSistema() - 1) {
                cout << RED << "No existe una Canción en esa posición.\n" << DEFAULT;
            }
        } while(option < 0 || option > this->getUtilCancionesSistema() - 1);
        
        for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
            if(Usuario_comun *uc = dynamic_cast<Usuario_comun*>(this->usuarios_sistema[i])) {
                encontrada2 = false;
                for(int j = 0; j < uc->getUtilCanciones() && encontrada2 == false; j++) {
                    if(uc->getCanciones(j)->getTitulo() == this->canciones_sistema[option]->getTitulo()) {
                        encontrada2 = true; 
                        uc->eliminarCancion(j);
                    }
                }
                for(int j = 0; j < uc->getUtilPlaylist(); j++) {
                    t.setMinutos(0);
                    t.setSegundos(0);
                    encontrada = false;
                    for(int k = 0; k < uc->getPlaylist(j)->getUtilCanciones() && encontrada == false; k++) {
                        if(uc->getPlaylist(j)->getCanciones(k)->getTitulo() == this->canciones_sistema[option]->getTitulo()) {
                            encontrada = true;
                            uc->getPlaylist(j)->eliminarCancion(k);                  
                        }
                    }
                    uc->getPlaylist(j)->setDuracion(t);
                    for(int i = 0; i < uc->getPlaylist(j)->getUtilCanciones(); i++) {
                        t.setMinutos(t.getMinutos() + uc->getPlaylist(j)->getCanciones(i)->getDuracion().getMinutos());
                        t.setSegundos(t.getMinutos() + uc->getPlaylist(j)->getCanciones(i)->getDuracion().getSegundos());
                    }
                    t.convertiraMinutosySegundos(t.getMinutos(), t.getSegundos());
                    uc->getPlaylist(j)->setDuracion(t);
                }

            }
        }

        for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
            for(int j = 0; j < this->getArtistaSistema(i)->getUtilCanciones(); j++) {
                if(this->getArtistaSistema(i)->getCanciones(j)->getTitulo() == this->canciones_sistema[option]->getTitulo()) {
                    this->getArtistaSistema(i)->eliminarCanciones(j);
                }
            }
        }
        this->eliminarCancion(option);
    } else {
        cout << RED << "No hay ninguna canción para eliminar.\n" << DEFAULT;
    }
}

void Vista::modificarCancion() {
    int option,option2;
    cout << BLUE << "¿Qué Canción desea modificar?\n" << DEFAULT;
    do {
        for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
            cout << BLUE << i + 1 << ". " << this->getCancionSistema(i)->getTitulo() << DEFAULT << endl;
        }
        cin >> option;
        option--;
        if(option < 0 || option > this->getUtilCancionesSistema() - 1) {
            cout << RED << "No existe una Canción en esa posición.\n" << DEFAULT;
        }
    } while(option < 0 || option > this->getUtilCancionesSistema() - 1);
    do {
        cout << BLUE << "¿Qué quiere modificar de la canción?\n";
        cout << "1. Id\n";
        cout << "2. Título\n";
        cout << "3. Ruta del Archivo\n";
        cout << "4. Los Artistas de la canción\n";
        cout << "5. Duración de la Canción\n";
        cout << "6. Total de reproducciones de la Canción\n";
        cout << "7. Total inclusiones en Playlist\n";
        cout << "8. Salir\n" << DEFAULT;
        cin >> option2;
        switch(option2) {
            case 1: {
                int id;
                cout << BLUE << "Introduzca el Id de la Canción: " << DEFAULT;
                cin >> id;
                this->getCancionSistema(option)->setId(id);
                break;
            }
            case 2: {
                string titulo;
                cout << BLUE << "Introduzca el título de la Canción: " << DEFAULT;
                cin >> titulo;
                this->getCancionSistema(option)->setTitulo(titulo);
                break;
            }
            case 3: {
                string rutaArchivo;
                cout << BLUE << "Introduzca la nueva Ruta del Archivo: " << DEFAULT;
                cin >> rutaArchivo;
                this->getCancionSistema(option)->setRutaArchivo(rutaArchivo);
                break;
            }
            case 4: {
                int option3;
                cout << BLUE << "¿Eliminar o agregar un Artista?\n";
                cout << "1. Agregar\n";
                cout << "2. Eliminar\n" << DEFAULT;
                cin >> option3;
                switch (option3)
                {
                case 1:
                    int option4;
                    cout << BLUE << "¿Qué Artista quiere agregar?\n" << DEFAULT;
                    for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
                        cout << BLUE << i + 1 << ". " << this->getArtistaSistema(i)->getNombre() << DEFAULT << endl;
                    }
                    cin >> option4;
                    option4--;
                    this->getCancionSistema(option)->setArtistas(this->getCancionSistema(option)->getUtilArtistas(),this->getArtistaSistema(option4));
                    break;
                case 2:
                    if(this->getCancionSistema(option)->getUtilArtistas() > 0) {
                        int option5;
                        cout << BLUE << "¿Qué Artista quiere eliminar?\n" << DEFAULT;
                        for(int i = 0; i < this->getCancionSistema(option)->getUtilArtistas(); i++) {
                            cout << BLUE << i + 1 << ". " << this->getCancionSistema(option)->getArtistas(i)->getNombre() << DEFAULT << endl;
                        }
                        cin >> option5;
                        option5--;
                        this->getCancionSistema(option)->eliminarArtista(option5);
                    } else {
                        cout << RED << "No se pueden eliminar más artitas.\n" << DEFAULT; 
                    }
                    break;
                }
                break;
            }
            case 5: {
                Tiempo t;
                int minutos,segundos;
                cout << "Introduzca los minutos de la canción: ";
                cin >> minutos;
                cout << "Introduzca los segundos de la canción: ";
                cin >> segundos;
                t.convertiraMinutosySegundos(minutos,segundos);
                this->getCancionSistema(option)->setDuracion(t);
                break;
            }
            case 6: {
                int totalReproducciones;
                cout << BLUE << "Introduzca el número de reproducciones: \n" << DEFAULT;
                do {
                    cin >> totalReproducciones;
                    if(totalReproducciones < 0) {
                        cout << RED << "Las reproducciones no pueden ser negativas.\n" << DEFAULT;
                    }
                } while(totalReproducciones < 0);
                this->getCancionSistema(option)->setTotalReproducciones(totalReproducciones);
                break;
            }
            case 7: {
                int totalInclusiones;
                cout << BLUE << "Introduzca el número de inclusiones en las Playlists: \n" << DEFAULT;
                do {
                    cin >> totalInclusiones;
                    if(totalInclusiones < 0) {
                        cout << RED << "Las inclusiones no pueden ser negativas.\n" << DEFAULT;
                    }
                } while(totalInclusiones < 0);
                this->getCancionSistema(option)->setTotalInclusionesEnPlaylist(totalInclusiones);
                break;
            }
            case 8:
                cout << BLUE << "Volviendo al submenú del Catálogo...\n" << DEFAULT;
                break;
        }
    } while(option2 != 8);
}

void Vista::opcionesUsuario() {
    int option;
    do {
        cout << BLUE << "¿Qué desea realizar?\n";
        cout << "1. Agregar Nuevo Usuario al Sistema\n";
        cout << "2. Eliminar Usuario del Sistema\n";
        cout << "3. Buscar Usuario en el Sistema\n";
        cout << "4. Modificar Datos Usuario del Sistema\n";
        cout << "5. Volver al menú principal\n" << DEFAULT;
        cin >> option;
        switch(option) {
            case 1:
                agregarUsuarioAlSistema();
                break;
            case 2:
                eliminarUsuariodelSistema();
                break;
            case 3:
                buscarUsuarios();
                break;
            case 4:
                modificarUsuario();
                break;
            case 5:
                cout << GREEN << "Volviendo al menú principal...\n" << DEFAULT;
                break;
        }
    } while(option != 5);
}

void Vista::agregarUsuarioAlSistema() {
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(agregarUsuarioAlSistema): Agregando un Usuario al Sistema..." << DEFAULT << endl;
    }

    int option,id,option2;
    string login,password;
    cout << BLUE << "¿De qué tipo será el nuevo Usuario?\n";
    cout << "1. Administrador\n";
    cout << "2. Usuario Común\n" << DEFAULT;
    cin >> option;
    switch (option) {
        case 1: {
            Administrador *a = new Administrador;
            cout << BLUE << "Id del Usuario: " << DEFAULT;
            cin >> id;
            a->setId(id);

            cout << BLUE << "Login del Usuario: " << DEFAULT;
            cin >> login;
            a->setLogin(login);

            cout << BLUE << "Password del Usuario: " << DEFAULT;
            cin >> password;
            a->setPassword(password);
            this->setUsuarioSistema(this->getUtilUsuariosSistema(),a);
            a = 0;
            delete a;
        }
            break;
        case 2: {
            Usuario_comun *uc = new Usuario_comun;
            cout << BLUE << "Id del Usuario: " << DEFAULT;
            cin >> id;
            uc->setId(id);

            cout << BLUE << "Login del Usuario: " << DEFAULT;
            cin >> login;
            uc->setLogin(login);

            cout << BLUE << "Password del Usuario: " << DEFAULT;
            cin >> password;
            uc->setPassword(password);

            cout << BLUE << "¿Desea agregarle una Playlist?\n";
            cout << "1. Sí\n";
            cout << "2. No\n" << DEFAULT;
            cin >> option2;
            switch (option2) {
            case 1: {
                Playlist *p = new Playlist;
                int Nplaylist,Ncanciones,option,option2;
                string nombre;
                do {
                    cout << BLUE << "1. Agregar Playlist\n";
                    cout << "2. Continuar con los datos del Usuario\n" << DEFAULT;
                    cin >> option;
                    switch (option)
                    {
                    case 1: {
                        cout << BLUE << "Id de la Playlist: " << DEFAULT;
                        cin >> id;
                        p->setId(id);

                        cout << BLUE << "Nombre de la Playlist: " << DEFAULT;
                        cin >> nombre;
                        p->setNombre(nombre);

                        do {
                            int cancion;
                            cout << BLUE << "1. Agregar Canción\n";
                            cout << "2. Continuar\n" << DEFAULT;
                            cin >> option2;
                            switch (option2)
                            {
                            case 1:
                                for(int k = 0; k < this->getUtilCancionesSistema(); k++) {
                                    cout << BLUE << k + 1 << ". " << this->getCancionSistema(k)->getTitulo() << DEFAULT << endl;
                                }
                                cin >> cancion;
                                cancion--;
                                this->getCancionSistema(cancion)->setTotalInclusionesEnPlaylist(this->getCancionSistema(cancion)->getTotalInclusionesEnPlaylist() + 1);
                                p->setCanciones(p->getUtilCanciones(),this->getCancionSistema(cancion));
                                break;
                            
                            case 2:
                                cout << BLUE << "Continuando con los datos del Usuario...\n" << DEFAULT;
                                break;
                            }
                        } while(option2 != 2);
                        Tiempo t;
                        int minutos = 0,segundos = 0;
                        for(int i = 0; i < p->getUtilCanciones(); i++) {
                            minutos += p->getCanciones(i)->getDuracion().getMinutos();
                            segundos += p->getCanciones(i)->getDuracion().getSegundos();
                        }
                        t.convertiraMinutosySegundos(minutos, segundos);
                        p->setDuracion(t);
                        uc->setPlaylist(uc->getUtilPlaylist(),p);
                        cout << GREEN << "Duración total de la Playlist: " << uc->getPlaylist(uc->getUtilPlaylist() - 1)->getDuracion().getMinutos() << ":" << uc->getPlaylist(uc->getUtilPlaylist() - 1)->getDuracion().getSegundos() << endl;
                        p = 0;
                        delete p;
                        break;
                    }
                    case 2:
                        cout << BLUE << "Continuando con los datos del Usuario...\n" << DEFAULT;
                        break;
                    }
                } while(option != 2);
            }
                break;
            case 2:
                cout << BLUE << "Continuando con los datos del Usuario...\n" << DEFAULT;
                break;
            }
            this->setUsuarioSistema(this->getUtilUsuariosSistema(),uc);
            uc = 0;
            delete uc;
        }
            break;
    }
    
    if(this->getTest() == true) {
        cout << DEBUG <<  "DEBUG(agregarUsuarioAlSistema): Usuario agregado correctamente al Sistema..." << DEFAULT << endl;
    }
}

void Vista::eliminarUsuariodelSistema() {
    int option,p = 0;

    cout << BLUE << "¿Qué Usuario quiere eliminar?\n" << DEFAULT;
    for(p = 0; p < this->getUtilUsuariosSistema(); p++) {
        cout << BLUE << p + 1 << ". " << this->getUsuarioSistema(p)->getLogin() << DEFAULT << endl;
    }
    cin >> option;
    option--;

    if(dynamic_cast<Administrador*>(this->usuarios_sistema[option])) {
        cout << RED << "Solo se pueden eliminar Usuarios Comunes.\n" << DEFAULT;
    }
    if(Usuario_comun *uc = dynamic_cast<Usuario_comun*>(this->usuarios_sistema[option])) {
        for(int i = 0; i< uc->getUtilPlaylist(); i++) {
            for(int j = 0; j < uc->getPlaylist(i)->getUtilCanciones(); j++) {
                for(int k = 0; k < uc->getPlaylist(i)->getCanciones(j)->getUtilArtistas(); k++) {
                    uc->getPlaylist(i)->getCanciones(j)->eliminarArtista(k);
                }
                uc->getPlaylist(i)->eliminarCancion(j);
            }
            uc->eliminarPlaylist(i);
        }

        for(int i = 0; i < uc->getUtilCanciones(); i++) {
            for(int j = 0; j < uc->getCanciones(i)->getUtilValoracion(); j++) {
                if(uc->getLogin() == uc->getCanciones(i)->getValoracion(j)->getNombre()) {
                    uc->getCanciones(i)->eliminarValoracion(j);
                }
            }
        }
        this->eliminarUsuario(option);
    }
}

void Vista::buscarUsuarios() {
    int option;
    do {
        cout << BLUE << "¿Por qué criterio quiere buscar?\n";
        cout << "1. Por tipo de usuario\n";
        cout << "2. Volver\n" << DEFAULT;
        cin >> option;
        switch (option) {
        case 1:
            int option2;
            cout << BLUE << "1. Administradores\n";
            cout << "2. Usuarios comunes\n" << DEFAULT;
            cin >> option2;
            switch(option2) {
                case 1:
                    for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
                        if(Administrador *a = dynamic_cast<Administrador*>(this->getUsuarioSistema(i))) {
                            cout << GREEN << "Id del Administrador: " << a->getId() << endl;
                            cout << "Login del Administrador: " << a->getLogin() << DEFAULT << endl << endl;
                        }
                    }
                    break;
                case 2:
                    for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
                        if(Usuario_comun *uc = dynamic_cast<Usuario_comun*>(this->getUsuarioSistema(i))) {
                            cout << GREEN << "Id del Usuario: " << uc->getId() << endl;
                            cout << "Login del Usuario: " << uc->getLogin() << endl;
                            cout << "Playlists:" << DEFAULT << endl;
                            for(int j = 0; j < uc->getUtilPlaylist(); j++) {
                                cout << CYAN << "\tId de la Playlist: " << uc->getPlaylist(j)->getId() << endl;
                                cout << "\tNombre de la Playlist: " << uc->getPlaylist(j)->getNombre() << endl;
                                cout << "\tDuración total de la Playlist: " << uc->getPlaylist(j)->getDuracion().getMinutos() << ":" << uc->getPlaylist(j)->getDuracion().getSegundos() << endl;
                                cout << "\tCanciones: \n" << DEFAULT;
                                for(int k = 0; k < uc->getPlaylist(j)->getUtilCanciones(); k++) {
                                    cout << MAGENTA << "\t\tTítulo de la canción: " << uc->getPlaylist(j)->getCanciones(k)->getTitulo() << DEFAULT << endl;
                                }
                                cout << endl;
                            }
                        }
                    }
                    break;
            }
            break;
        case 2:
            cout << GREEN << "Volviendo al submenú...\n" << DEFAULT;
            break;
        }
    } while(option != 2);
}

void Vista::modificarUsuario() {
    int option;
    cout << BLUE << "¿Qué Usuario quiere modificar?\n" << DEFAULT;
    for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
        cout << BLUE << i + 1 << ". " << this->getUsuarioSistema(i)->getLogin() << DEFAULT << endl;
    }
    cin >> option;
    option--;

    if(dynamic_cast<Administrador*>(this->usuarios_sistema[option])) {
        int option2,id;
        string login,password;
        cout << BLUE << "1. Modificar Id\n";
        cout << "2. Modificar Login\n";
        cout << "3. Modificar Password\n" << DEFAULT;
        cin >> option2;
        switch (option2) {
            case 1:
                cout << BLUE << "Introduzca el nuevo Id: " << DEFAULT;
                cin >> id;
                this->getUsuarioSistema(option)->setId(id);
                break;
            case 2:
                cout << BLUE << "Introduzca el nuevo Login: " << DEFAULT;
                cin >> login;
                this->getUsuarioSistema(option)->setLogin(login);
                break;
            case 3:
                cout << BLUE << "Introduzca la nueva Password: " << DEFAULT;
                cin >> password;
                this->getUsuarioSistema(option)->setPassword(password);
                break;
        }
    }
    if(Usuario_comun *uc = dynamic_cast<Usuario_comun*>(this->usuarios_sistema[option])) {
        int option2,id;
        string login,password;
        cout << BLUE << "1. Modificar Id\n";
        cout << "2. Modificar Login\n";
        cout << "3. Modificar Password\n";
        cout << "4. Modificar Playlist\n" << DEFAULT;
        cin >> option2;
        switch (option2) {
            case 1:
                cout << BLUE << "Introduzca el nuevo Id: " << DEFAULT;
                cin >> id;
                uc->setId(id);
                break;
            case 2:
                cout << BLUE << "Introduzca el nuevo Login: " << DEFAULT;
                cin >> login;
                uc->setLogin(login);
                break;
            case 3:
                cout << BLUE << "Introduzca la nueva Password: " << DEFAULT;
                cin >> password;
                uc->setPassword(password);
                break;
            case 4:
                int option3;
                cout << BLUE << "1. Agregar Canción a la Playlist\n";
                cout << "2. Eliminar Canción de la Playlist\n" << DEFAULT;
                cin >> option3;
                switch(option3) {
                    case 1: {
                        Tiempo t;
                        int option,option2,i,j,minutos = 0,segundos = 0;
                        cout << BLUE << "¿A qué playlist desea añadirle una canción?\n" << DEFAULT;
                        for(i = 0; i < uc->getUtilPlaylist(); i++) {
                            cout << BLUE << i + 1 << ". " << uc->getPlaylist(i)->getNombre() << DEFAULT << endl;
                        }
                        cin >> option;
                        option--;

                        for(j = 0; j < this->getUtilCancionesSistema(); j++) {
                            cout << BLUE << j + 1 << ". " << this->getCancionSistema(j)->getTitulo() << DEFAULT << endl;
                        }
                        cin >> option2;
                        option2--;
                        uc->getPlaylist(option)->setCanciones(uc->getPlaylist(option)->getUtilCanciones(),this->getCancionSistema(option2));
                        for(int i = 0; i < uc->getPlaylist(option)->getUtilCanciones(); i++) {
                            minutos += uc->getPlaylist(option)->getCanciones(i)->getDuracion().getMinutos();
                            segundos += uc->getPlaylist(option)->getCanciones(i)->getDuracion().getSegundos();
                        }
                        t.convertiraMinutosySegundos(minutos,segundos);
                        uc->getPlaylist(option)->setDuracion(t);
                        cout << GREEN << "Duración total de la Playlist: " << uc->getPlaylist(option)->getDuracion().getMinutos() << ":" << uc->getPlaylist(option)->getDuracion().getSegundos() << DEFAULT << endl;
                        break;
                    }
                    case 2: {
                        Tiempo t;
                        int option,option2,i,j,minutos = 0,segundos = 0;
                        cout << BLUE << "¿De qué Playlist quiere eliminar la canción?\n" << DEFAULT;
                        for(i = 0; i < uc->getUtilPlaylist(); i++) {
                            cout << BLUE << i + 1 << ". " << uc->getPlaylist(i)->getNombre() << DEFAULT << endl;
                        }
                        cin >> option;
                        option--;

                        cout << BLUE << "¿Qué canción quiere eliminar?" << DEFAULT << endl;
                        for(int j = 0; j < uc->getPlaylist(option)->getUtilCanciones(); j++) {
                            cout << BLUE << j + 1 << ". " << uc->getPlaylist(option)->getCanciones(j)->getTitulo() << DEFAULT << endl;
                        }
                        cin >> option2;
                        option2--;

                        uc->getPlaylist(option)->getCanciones(option2)->setTotalInclusionesEnPlaylist(uc->getPlaylist(option)->getCanciones(option2)->getTotalInclusionesEnPlaylist() - 1);

                        uc->getPlaylist(option)->eliminarCancion(option2);

                        for(int i = 0; i < uc->getPlaylist(option)->getUtilCanciones(); i++) {
                            minutos += uc->getPlaylist(option)->getCanciones(i)->getDuracion().getMinutos();
                            segundos += uc->getPlaylist(option)->getCanciones(i)->getDuracion().getSegundos();
                        }
                        t.convertiraMinutosySegundos(minutos,segundos);
                        uc->getPlaylist(option)->setDuracion(t);
                        cout << GREEN << "Duración total de la Playlist: " << uc->getPlaylist(option)->getDuracion().getMinutos() << ":" << uc->getPlaylist(option)->getDuracion().getSegundos() << DEFAULT << endl;
                        break;
                    }
                }
        }
    }
}

void Vista::opcionesPlaylist() {
    int option;
    cout << BLUE << "1. Consultar Playlist\n";
    cout << "2. Eliminar Playlist\n"  << DEFAULT;
    cin >> option;
    switch (option) {
        case 1: {
            int option2,option3;
            cout << BLUE << "¿De qué usuario quiere consultar la Playlist?\n" << DEFAULT;
            for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
                cout << BLUE << i + 1 << ". " << this->getUsuarioSistema(i)->getLogin() << DEFAULT << endl;
            }
            cin >> option2;
            option2--;
            if(Usuario_comun *uc = dynamic_cast<Usuario_comun*>(this->usuarios_sistema[option2])) {
                cout << BLUE << "¿Qué Playlist quiere consultar?\n" << DEFAULT;
                for(int j = 0; j < uc->getUtilPlaylist(); j++) {
                    cout << BLUE << j + 1 << ". " << uc->getPlaylist(j)->getNombre() << DEFAULT << endl;
                }
                cin >> option3;
                option3--;
                cout << GREEN << "Id de la Playlist: " << uc->getPlaylist(option3)->getId() << endl;
                cout << "Nombre de la Playlist: " << uc->getPlaylist(option3)->getNombre() << endl;
                cout << "Duración total de la Playlist: " << uc->getPlaylist(option3)->getDuracion().getMinutos() << ":" << uc->getPlaylist(option3)->getDuracion().getSegundos() << endl;
                cout << "Canciones: \n" << DEFAULT;
                for(int i = 0; i < uc->getPlaylist(option3)->getUtilCanciones(); i++) {
                    cout << MAGENTA << "\tId de la canción: " << uc->getPlaylist(option3)->getCanciones(i)->getId() << endl;
                    cout << "\tTítulo de la canción: " << uc->getPlaylist(option3)->getCanciones(i)->getTitulo() << endl;
                    cout << "\tDuración de la canción: " << uc->getPlaylist(option3)->getCanciones(i)->getDuracion().getMinutos() << ":" << uc->getPlaylist(option3)->getCanciones(i)->getDuracion().getSegundos() << endl;
                    cout << "\tRuta de la canción: " << uc->getPlaylist(option3)->getCanciones(i)->getRutaArchivo() << endl;
                    cout << "\tArtistas de la canción: "  << DEFAULT << endl;
                    for(int j = 0; j < uc->getPlaylist(option3)->getCanciones(i)->getUtilArtistas(); j++) {
                        cout << CYAN << "\t\tId del Artista: " << uc->getPlaylist(option3)->getCanciones(i)->getArtistas(j)->getId() << endl;
                        cout << "\t\tNombre del Artista: " << uc->getPlaylist(option3)->getCanciones(i)->getArtistas(j)->getNombre() <<  DEFAULT << endl;
                    }
                    cout << MAGENTA << "\tTotal de reprducciones de la canción: " << uc->getPlaylist(option3)->getCanciones(i)->getTotalReproducciones() << endl;
                    cout << "\tInclusioines de la canción en Playlists: " << uc->getPlaylist(option3)->getCanciones(i)->getTotalInclusionesEnPlaylist() << DEFAULT << endl << endl;
                }
            } else {
                cout << RED << "Solo los usuarios comunes tienen PLaylists.\n" << DEFAULT;
            }
            break;
        }
        case 2: 
            this->eliminarPlaylist();
            break;
    }
}

void Vista::eliminarPlaylist() {
    int option2,option3;
    cout << BLUE << "¿De qué usuario quiere eliminar la Playlist?\n" << DEFAULT;
    for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
        cout << BLUE << i + 1 << ". " << this->getUsuarioSistema(i)->getLogin() << DEFAULT << endl;
    }
    cin >> option2;
    option2--;
    if(Usuario_comun *uc = dynamic_cast<Usuario_comun*>(this->usuarios_sistema[option2])) {
        if(uc->getUtilPlaylist() > 0) {
            cout << BLUE << "¿Qué Playlist quiere eliminar?\n" << DEFAULT;
            for(int j = 0; j < uc->getUtilPlaylist(); j++) {
                cout << BLUE << j + 1 << ". " << uc->getPlaylist(j)->getNombre() << DEFAULT << endl;
            }
            cin >> option3;
            option3--;
            cout << BLUE << "Eliminando Playlist...\n" << DEFAULT;

            for(int i = 0; i < uc->getPlaylist(option3)->getUtilCanciones(); i++) {
                for(int k = 0; k < uc->getPlaylist(option3)->getCanciones(i)->getUtilArtistas(); k++) {
                    uc->getPlaylist(option3)->getCanciones(i)->eliminarArtista(k);
                }
                uc->getPlaylist(option3)->getCanciones(i)->setTotalInclusionesEnPlaylist(uc->getPlaylist(option3)->getCanciones(i)->getTotalInclusionesEnPlaylist() - 1);
                uc->getPlaylist(option3)->eliminarCancion(i);
            }
            uc->eliminarPlaylist(option3);
            cout << BLUE << "Playlist eliminada correctamente...\n" << DEFAULT;
        } else {    
            cout << RED << "Este Usuario no tiene Playlists." << DEFAULT << endl;
        }
    } else {
        cout << RED << "Solo los usuarios comunes tienen PLaylists.\n" << DEFAULT;
    }
}

void Vista::menuUsuarioComun() {
    int option;
    do {
        cout << BLUE << "BIENVENIDO AL SISTEMA SPOTY-KING\n";
        cout << "USUARIO ACTIVO: " << this->usuario_activo->getLogin() << DEFAULT << endl;

        cout << YELLOW << "Pulse el número de la acción que desee realizar: \n" << DEFAULT;
        cout << BLUE << "1. Cambiar de Usuario\n";
        cout << "2. Consultar Playlist del Usuario y Ver Canciones de Playlist.\n";
        cout << "3. Agregar Canción del Sistema a Playlist.\n";
        cout << "4. Eliminar Canción de una Playlist.\n";
        cout << "5. Valorar una Canción\n";
        cout << "6. Reproducir Canción\n";
        cout << "7. Destruir y salir\n" << DEFAULT;
        cin >> option;
        switch(option) {
            case 1:
                this->usuario_activo = 0;
                this->menuSistema();
                this->~Vista();
                exit(-1);
                break;
            case 2:
                this->consultarPlaylists();
                break;
            case 3:
                this->agregarCancionAplaylist();
                break;
            case 4:
                this->eliminarCancionDePlaylist();
                break;
            case 5:
                this->valorarCancion();
                break;
            case 6:
                this->escucharCancion();
                break;
            case 7:
                cout << GREEN << "Gracias por usar SPOTY-KING\n" << DEFAULT;
                break;
        }
    } while(option != 7);
}

void Vista::consultarPlaylists() {
    int option,option2, i;
    do {
        cout << BLUE << "¿Qué Playlist desea ver?\n" << DEFAULT;
        for(i = 0; i < this->usuario_activo->getUtilPlaylist(); i++) {
            cout << BLUE << i + 1 << ". " << this->usuario_activo->getPlaylist(i)->getNombre() << DEFAULT << endl;
        }
        cin >> option;
        option--;
        if(option < 0 || option > this->usuario_activo->getUtilPlaylist() - 1) {
            cout << RED << "No hay una Playlist en esa posición\n" << DEFAULT;
        } else {
            if(this->usuario_activo->getPlaylist(option)->getUtilCanciones() > 0) {
                cout << BLUE << "¿Qué canción quiere consultar?\n" << DEFAULT;
                for(int j = 0; j < this->usuario_activo->getPlaylist(option)->getUtilCanciones(); j++) {
                    cout << BLUE << j + 1 << ". " << this->usuario_activo->getPlaylist(option)->getCanciones(j)->getTitulo() << DEFAULT << endl;
                }
                cin >> option2;
                option2--;

                cout << GREEN << "Título: " << this->usuario_activo->getPlaylist(option)->getCanciones(option2)->getTitulo() << endl;
                cout << "Artistas: \n";
                for(int i = 0; i < this->usuario_activo->getPlaylist(option)->getCanciones(option2)->getUtilArtistas(); i++) {
                    cout << this->usuario_activo->getPlaylist(option)->getCanciones(option2)->getArtistas(i)->getNombre() << endl;
                }
                cout << "Duración: " << this->usuario_activo->getPlaylist(option)->getCanciones(option2)->getDuracion().getMinutos() << ":" 
                    << this->usuario_activo->getPlaylist(option)->getCanciones(option2)->getDuracion().getSegundos() << DEFAULT << endl << endl;
            } else {
                cout << RED << "No hay ninguna canción que mostrar.\n" << DEFAULT;
            }
        }
    } while(option < 0 || option > this->usuario_activo->getUtilPlaylist() - 1);
 }

void Vista::agregarCancionAplaylist() {
    Tiempo t;
    int option,option2,i,j,minutos = 0,segundos = 0;
    cout << BLUE << "¿A qué playlist desea añadirle una canción?\n" << DEFAULT;
    for(i = 0; i < this->usuario_activo->getUtilPlaylist(); i++) {
        cout << BLUE << i + 1 << ". " << this->usuario_activo->getPlaylist(i)->getNombre() << DEFAULT << endl;
    }
    cin >> option;
    option--;

    cout << BLUE << "¿Qué canción desea añadir a la Playlist?\n" << DEFAULT;
    for(j = 0; j < this->getUtilCancionesSistema(); j++) {
        cout << BLUE << j + 1 << ". " << this->getCancionSistema(j)->getTitulo() << DEFAULT << endl;
    }
    cin >> option2;
    option2--;

    this->getCancionSistema(option2)->setTotalInclusionesEnPlaylist(this->getCancionSistema(option2)->getTotalInclusionesEnPlaylist() + 1);
    
    this->usuario_activo->getPlaylist(option)->setCanciones(this->usuario_activo->getPlaylist(option)->getUtilCanciones(),this->getCancionSistema(option2));
    for(int i = 0; i < this->usuario_activo->getPlaylist(option)->getUtilCanciones(); i++) {
        minutos += this->usuario_activo->getPlaylist(option)->getCanciones(i)->getDuracion().getMinutos();
        segundos += this->usuario_activo->getPlaylist(option)->getCanciones(i)->getDuracion().getSegundos();
    }
    t.convertiraMinutosySegundos(minutos,segundos);
    this->usuario_activo->getPlaylist(option)->setDuracion(t);
    cout << GREEN << "Duración total de la Playlist: " << this->usuario_activo->getPlaylist(option)->getDuracion().getMinutos() << ":" << this->usuario_activo->getPlaylist(option)->getDuracion().getSegundos() << DEFAULT << endl;
}

void Vista::eliminarCancionDePlaylist() {
    Tiempo t;
    int option,option2,i,j,minutos = 0,segundos = 0;
    cout << BLUE << "¿De qué Playlist quiere eliminar la canción?\n" << DEFAULT;
    for(i = 0; i < this->usuario_activo->getUtilPlaylist(); i++) {
        cout << BLUE << i + 1 << ". " << this->usuario_activo->getPlaylist(i)->getNombre() << DEFAULT << endl;
    }
    cin >> option;
    option--;

    if(this->usuario_activo->getPlaylist(option)->getUtilCanciones() > 0) {
        cout << BLUE << "¿Qué canción quiere eliminar?" << DEFAULT << endl;
        for(int j = 0; j < this->usuario_activo->getPlaylist(option)->getUtilCanciones(); j++) {
            cout << BLUE << j + 1 << ". " << this->usuario_activo->getPlaylist(option)->getCanciones(j)->getTitulo() << DEFAULT << endl;
        }
        cin >> option2;
        option2--;

        this->usuario_activo->getPlaylist(option)->getCanciones(option2)->setTotalInclusionesEnPlaylist(this->usuario_activo->getPlaylist(option)->getCanciones(option2)->getTotalInclusionesEnPlaylist() - 1);

        this->usuario_activo->getPlaylist(option)->eliminarCancion(option2);

        for(int i = 0; i < this->usuario_activo->getPlaylist(option)->getUtilCanciones(); i++) {
            minutos += this->usuario_activo->getPlaylist(option)->getCanciones(i)->getDuracion().getMinutos();
            segundos += this->usuario_activo->getPlaylist(option)->getCanciones(i)->getDuracion().getSegundos();
        }
        t.convertiraMinutosySegundos(minutos,segundos);
        this->usuario_activo->getPlaylist(option)->setDuracion(t);
        cout << GREEN << "Duración total de la Playlist: " << this->usuario_activo->getPlaylist(option)->getDuracion().getMinutos() << ":" << this->usuario_activo->getPlaylist(option)->getDuracion().getSegundos() << DEFAULT << endl;
    } else {
        cout << RED << "Esta Playlist no tiene más Canciones.\n" << DEFAULT;
    }
}

void Vista::valorarCancion() {
    int option,valoracion;
    bool encontrada;
    Valoracion *v = new Valoracion;
    cout << BLUE << "¿Qué canción quiere valorar?\n" << DEFAULT;
    for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
        cout << BLUE << i + 1 << ". " << this->getCancionSistema(i)->getTitulo() << DEFAULT << endl;
    }
    cin >> option;
    option--;

    for(int i = 0; i < this->usuario_activo->getUtilCanciones() && encontrada == false; i++) {
        if(this->usuario_activo->getCanciones(i)->getTitulo() == this->getCancionSistema(option)->getTitulo()) {
            encontrada = true;
        }
    }

    if(encontrada == true) {
        cout << RED << "Ya ha valorado esta canción.\n" << DEFAULT;
    } else {
        cout << BLUE << "Introduzca la valoración de 0 a 5 estrellas: " << DEFAULT;
        do {
            cin >> valoracion;
            if(valoracion < 0 || valoracion > 5) {
                cout << RED << "La valoración solo puede ser de 0 a 5 estrellas\n" << DEFAULT;
            }
        } while(valoracion < 0 || valoracion > 5);
        v->setNombre(this->usuario_activo->getLogin());
        v->setValoracion(valoracion);
        this->getCancionSistema(option)->setContador(this->getCancionSistema(option)->getContador() + 1);
        this->getCancionSistema(option)->setValoracion(this->getCancionSistema(option)->getUtilValoracion(),v);
        this->usuario_activo->setCanciones(this->usuario_activo->getUtilCanciones(),this->getCancionSistema(option));
    }
}

void Vista::escucharCancion() {
    int option,option2,i,j;

    cout << BLUE << "¿De qué Playlist quiere escuchar la canción?\n" << DEFAULT;
    for(i = 0; i < this->usuario_activo->getUtilPlaylist(); i++) {
        cout << BLUE << i + 1 << ". " << this->usuario_activo->getPlaylist(i)->getNombre() << DEFAULT << endl;
    }
    cin >> option;
    option--;

    cout << BLUE << "¿Qué canción quiere escuchar?\n" << DEFAULT;
    for(j = 0; j < this->usuario_activo->getPlaylist(option)->getUtilCanciones(); j++) {
        cout << BLUE << j + 1 << ". " << this->usuario_activo->getPlaylist(option)->getCanciones(j)->getTitulo() << DEFAULT << endl;
    }
    cin >> option2;
    option2--;

    this->usuario_activo->getPlaylist(option)->getCanciones(option2)->setTotalReproducciones(this->usuario_activo->getPlaylist(option)->getCanciones(option2)->getTotalReproducciones() + 1);

    cout << GREEN << "Total reproducciones: " << this->usuario_activo->getPlaylist(option)->getCanciones(option2)->getTotalReproducciones() << DEFAULT << endl;

    this->usuario_activo->getPlaylist(option)->getCanciones(option2)->escucharCancion();
}

void Vista::resizeArtistasSistema(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize" << DEFAULT << endl;
    }
    
    Artista** nuevo_v_artista;
    //1º) Reservo Memoria
    if(tamanio_nuevo != this->getUtilArtistasSistema() && tamanio_nuevo > this->getUtilArtistasSistema()) {
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

    if(tamanio_nuevo != this->getUtilArtistasSistema() && tamanio_nuevo < this->getUtilArtistasSistema()) {
        nuevo_v_artista = new Artista*[this->getUtilArtistasSistema()];
        if(nuevo_v_artista == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
            nuevo_v_artista[i] = 0;
        }
    }

    //2º) Copio los valores del vector antiguo en el nuevo (independientemente del tamaño)
    if(tamanio_nuevo > this->getUtilArtistasSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilArtistasSistema(); i++) {
            nuevo_v_artista[i] = this->artistas_sistema[i];
        }
    } else if(tamanio_nuevo < this->getUtilArtistasSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
        }
        //copio los valores antiguos en el nuevo, que es más pequeño
        for(int i=0; i < tamanio_nuevo; i++) {
            nuevo_v_artista[i] = this->getArtistaSistema(i);
        }
    } else if(tamanio_nuevo == this->getUtilArtistasSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "El nuevo tamaño es igual que el anterior, no se realizará ningún cambio" << DEFAULT << endl;
        }
    }
    //3º) Eliminar la Memoria
    if(tamanio_nuevo != this->getUtilArtistasSistema()) {
        delete [] this->artistas_sistema; 
        this->artistas_sistema = nuevo_v_artista; 
        this->setUtilArtistasSistema(tamanio_nuevo);
    }
}

void Vista::resizeCancionesSistema(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize" << DEFAULT << endl;
    }
    
    Cancion** nuevo_v_cancion;
    //1º) Reservo Memoria
    if(tamanio_nuevo != this->getUtilCancionesSistema() && tamanio_nuevo > this->getUtilCancionesSistema()) {
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

    if(tamanio_nuevo != this->getUtilCancionesSistema() && tamanio_nuevo < this->getUtilCancionesSistema()) {
        nuevo_v_cancion = new Cancion*[this->getUtilCancionesSistema()];
        if(nuevo_v_cancion == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
            nuevo_v_cancion[i] = 0;
        }
    }

    //2º) Copio los valores del vector antiguo en el nuevo (independientemente del tamaño)
    if(tamanio_nuevo > this->getUtilCancionesSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilCancionesSistema(); i++) {
            nuevo_v_cancion[i] = this->canciones_sistema[i];
        }
    } else if(tamanio_nuevo < this->getUtilCancionesSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
        }
        //copio los valores antiguos en el nuevo, que es más pequeño
        for(int i=0; i < tamanio_nuevo; i++) {
            nuevo_v_cancion[i] = this->getCancionSistema(i);
        }
    } else if(tamanio_nuevo == this->getUtilCancionesSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "El nuevo tamaño es igual que el anterior, no se realizará ningún cambio" << DEFAULT << endl;
        }
    }
    //3º) Eliminar la Memoria
    if(tamanio_nuevo != this->getUtilCancionesSistema()) {
        delete [] this->canciones_sistema;
        this->canciones_sistema = nuevo_v_cancion;
        this->setUtilcancionesSistema(tamanio_nuevo);
    }
}

void Vista::resizeUsuariosSistema(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize" << DEFAULT << endl;
    }
    
    Usuario** nuevo_v_usuarios;
    //1º) Reservo Memoria
    if(tamanio_nuevo != this->getUtilUsuariosSistema() && tamanio_nuevo > this->getUtilUsuariosSistema()) {
        nuevo_v_usuarios = new Usuario*[tamanio_nuevo];
        if(nuevo_v_usuarios == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < tamanio_nuevo; i++) {
            nuevo_v_usuarios[i] = 0;
        }
    }

    if(tamanio_nuevo != this->getUtilUsuariosSistema() && tamanio_nuevo < this->getUtilUsuariosSistema()) {
        nuevo_v_usuarios = new Usuario*[this->getUtilUsuariosSistema()];
        if(nuevo_v_usuarios == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }

        //Inicializo
        for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
            nuevo_v_usuarios[i] = 0;
        }
    }

    //2º) Copio los valores del vector antiguo en el nuevo (independientemente del tamaño)
    if(tamanio_nuevo > this->getUtilUsuariosSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilUsuariosSistema(); i++) {
            nuevo_v_usuarios[i] = this->usuarios_sistema[i];
        }
    } else if(tamanio_nuevo < this->getUtilUsuariosSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
        }
        //copio los valores antiguos en el nuevo, que es más pequeño
        for(int i=0; i < tamanio_nuevo; i++) {
            nuevo_v_usuarios[i] = this->getUsuarioSistema(i);
        }
    } else if(tamanio_nuevo == this->getUtilUsuariosSistema()) {
        if(this->getTest() == true) {
            cout << DEBUG << "El nuevo tamaño es igual que el anterior, no se realizará ningún cambio" << DEFAULT << endl;
        }
    }
    //3º) Eliminar la Memoria
    if(tamanio_nuevo != this->getUtilUsuariosSistema()) {
        delete [] this->usuarios_sistema;
        this->usuarios_sistema = nuevo_v_usuarios;
        this->setUtilUsuariosSistema(tamanio_nuevo);
    }
}

void Vista::resizeBusquedaCanciones(int tamanio_nuevo) {
    if(this->getTest() == true) {
        cout << DEBUG << "Invocando al resize" << DEFAULT << endl;
    }
    
    Cancion** nuevo_v_cancion;
    //1º) Reservo Memoria
    if(tamanio_nuevo != this->getUtilBusquedaCancion() && tamanio_nuevo > this->getUtilBusquedaCancion()) {
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

    if(tamanio_nuevo != this->getUtilBusquedaCancion() && tamanio_nuevo < this->getUtilBusquedaCancion()) {
        nuevo_v_cancion = new Cancion*[this->getUtilBusquedaCancion()];
        if(nuevo_v_cancion == 0){
            cerr<< "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
            exit(-1);
        }
        
        //Inicializo
        for(int i = 0; i < this->getUtilBusquedaCancion(); i++) {
            nuevo_v_cancion[i] = 0;
        }
    }

    //2º) Copio los valores del vector antiguo en el nuevo (independientemente del tamaño)
    if(tamanio_nuevo > this->getUtilBusquedaCancion()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para crecer..." << DEFAULT << endl;
        }
        //copio los valores antiguos en el nuevo, que es más grande
        for(int i = 0; i < this->getUtilBusquedaCancion(); i++) {
            nuevo_v_cancion[i] = this->busqueda_cancion[i];
        }
    } else if(tamanio_nuevo < this->getUtilBusquedaCancion()) {
        if(this->getTest() == true) {
            cout << DEBUG << "Invocando al resize para decrecer (pérdida de info!!)..." << DEFAULT << endl;  
        }
        //copio los valores antiguos en el nuevo, que es más pequeño
        for(int i=0; i < tamanio_nuevo; i++) {
            nuevo_v_cancion[i] = this->getBusquedaCancion(i);
        }
    } else if(tamanio_nuevo == this->getUtilBusquedaCancion()) {
        if(this->getTest() == true) {
            cout << DEBUG << "El nuevo tamaño es igual que el anterior, no se realizará ningún cambio" << DEFAULT << endl;
        }
    }
    //3º) Eliminar la Memoria
    if(tamanio_nuevo != this->getUtilBusquedaCancion()) {
        delete [] this->busqueda_cancion;
        this->busqueda_cancion = nuevo_v_cancion;
        this->setUtilBusquedaCancion(tamanio_nuevo);
    }
}
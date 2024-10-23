#include "cancion.h"
#include "artista.h"
#include "playlist.h"
#include "vista.h"
#include "usuario.h"
int main() {
    Vista v;
    v.cargarDatosPorDefecto();
    v.menuSistema();
}
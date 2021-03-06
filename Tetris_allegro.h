#ifndef TETRIS_ALLEGRO_H_INCLUDED
#define TETRIS_ALLEGRO_H_INCLUDED

#include <allegro.h>

#define anchura 800
#define altura  820
#define Tbloque 25

#define color1    0
#define color2    1
#define color3    2
#define color4    3
#define color5    4
#define color6    5
#define color7    6

#define Ladrillo  0


void mostrar_bloque(BITMAP * buffer, BITMAP * img_b, int XC, int YC, int color, int tipo);

struct Bloque{
    int x, y, tipo;
};

class pieza{
    private:
        Bloque b_prin;
        Bloque bls[3];
        int color_p;
    public:
        pieza(Bloque _b_prin, Bloque _bls[3], int _color_p);
        void mostrar_pieza(BITMAP * buffer, BITMAP * img_b);
        void incrX(int incr){ b_prin.x += incr; }
        void incrY(int incr){ b_prin.y += incr; }
        bool colision_abajo();
        bool colision_derec();
        bool colision_izqui();
        bool fila_llena(int fila);
        void insertar_mapa();
        int getY(){ return b_prin.y; }
        int getX(){ return b_prin.x; }
        void setBPrin(Bloque newB_prin){ b_prin = newB_prin; }
        void setBls(Bloque newBls[3]){ for(int i=0; i<3; i++) bls[i] = newBls[i]; }
        void setColor(int newColor){ color_p = newColor; }
        void rotar();
};

void mostrar_muros(BITMAP * buffer, BITMAP * marco);
//void mostrar_marco(BITMAP * buffer, BITMAP * marco);
void mostrar_numero(BITMAP * buffer, BITMAP * img_num, int numero, int xnum, int ynum);
void mostrar_datos (BITMAP * buffer, BITMAP * img_texto, BITMAP * img_num, int puntos, int nivel);

void mostrar_dat   (BITMAP * buffer, BITMAP * img_num, int ese, int zeta);
void mostrar_dat1  (BITMAP * buffer, BITMAP * img_num, int ele, int cuadrado);
void mostrar_dat2  (BITMAP * buffer, BITMAP * img_num, int palo, int ele2);
void mostrar_dat3  (BITMAP * buffer, BITMAP * img_num, int te);



void mostrar_restD(BITMAP * buffer, BITMAP * img_texto, BITMAP * img_num, int lineas, int stats);
void limpiar_mapa();
void mostrar_mapa(BITMAP * buffer, BITMAP * img_b);
void eliminar_fila(int fila);
void portada(BITMAP * p);

#endif // TETRIS_ALLEGRO_H_INCLUDED

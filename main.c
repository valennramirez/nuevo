#include <stdio.h>
#include <stdlib.h>

int main()
{

    srand(time(NULL)); ///Declara el seed para el rand
    Heroe jugador;
    cargaUsuario(&jugador);
    nodoArbol*mapa=inicArbol();
    mapa=cargaMapa(mapa);
    celda ada[20];

    int fin=0, aux=0;



    while(fin==0)
    {
        printf("1-avanzar\n");
        printf("2-retroceso\n");
        printf("3-ver inventario\n");
        printf("4-guardar y salir\n");
        scanf("%d", &aux);

        switch(aux)
        {
        case 1:
            {
                int op;

                printf("desea avanzar por la izquierda o la derecha?\n");
                printf("1-derecha 2-izquierda");
                scanf("%d", &op);

                if(op==1)
                {
                    printf("nuestro heroe avanza por la derecha\n");
                    Sleep(2300);
                    system("cls");
                    avanzarDerecha(mapa,jugador.habitacionActual,&jugador);
                }
                else if(op==2)
                {
                    printf("nuestro heroe avanza por la izquierda\n");
                    Sleep(2300);
                    system("cls");
                    avanzarIzquierda(mapa,jugador.habitacionActual,&jugador);
                    ///dibujito??
                }
                else
                {
                    printf("el heroe solo puede avanzar por derecha o izquierda\n");
                }
            }break;
        case 2:
            {
                if(jugador.habitacionActual==4)
                {
                    printf("cuando nuestro heroe intenta salir del castillo, se percata de que las puertas estan cerradas\n");
                    Sleep(2300);
                    system("cls");
                }
                else
                {
                    retroceso(&jugador,mapa);
                }
            }break;
        case 3:
            {
                verinventario(&inventario);

                ///usar objetos
            } break;

        case 4:
            {
                printf ("Desea guardar la partida y salir?\n");
                printf ("1- si \n 0- no");
                scanf("%d", &fin);

                int validos=guardarJugador(ada, 20, &jugador); ///guarda los jugadores en una celda con el mapa correspondiente
                guardarPartida("partidas.bin", ada, validos); ///guarda la partida en un archivo para despues poder acceder

            }break;
        }

    }
    return 0;
}

///retroceso nueva

int buscarNodoHabitacion (nodoarbol *mapa, int habitacion)
{
    int nro;
    if(habitacion==mapa->nroHabitacion)
    {
        nro=mapa->nroHabitacion;
    }
    else if (habiacion>4)
    {
        nro=buscarNodoHabitacion (mapa->izq, habitacion);
    }
    else
    {
        nro=buscarNodoHabitacion(mapa->der, habitacion);
    }
    return nro;
}
heroe *retroceso (heroe jugador, nodoarbol *mapa)
{
    if (jugador.habitacionActual>4)
    {
        jugador.habitacionActual=buscarNodoHabitacion(mapa->derecha, habitacionActual);
    }
    else if (4>jugador.habitacionActual)
    {
        jugador.habitacionActual=buscarNodoHabitacion(mapa->izquierda, habitacionActual);
    }

    return jugador;
}
///arreglo de arboles
int buscarPosHeroe (celda ada[], int validos, char nombre)
{
    int i=0, rta=-1;
    while(validos>i && rta==-1)
    {
        if (strcmpi (ada[i].jugador.nombre, nombre)==0)
        {
            rta=i;
        }
        i++;
    }
    return rta;
}
int alta(celda ada[], int validos, heroe jugador)
{
    int validos;

    int pos=buscarPosHeroe(ada, validos, jugador.nombre);

    if(pos==-1)
    {
        validos=agregarHeroe(ada, validos, jugador);
        pos=validos-1;
    }
    ada[pos].mapaArbol=cargaMapa(ada[pos].mapaArbol);

    ///actualizar mapa??

    return validos;
}
int guardarJugador (celda ada[], int dimension, heroe jugador);
{
    int validos;
    while(dimension>validos)
    {
        validos=alta(ada, validos, jugador);
    }
    return validos;
}

void guardarPartida (char nombreArchivo[], celda ada[], int dimension)
{
    FILE *archivo=fopen(nombreArchivo, "w+b");

    if (archivo!=NULL)
    {
        while(i<validos)
        {
            fwrite(&ada[i], sizeof(celda), 1, archivo);
        }
        fclose(archivo);
    }
}

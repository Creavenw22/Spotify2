#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define NUMCAN 15
#define NUMIN 6

typedef struct
{
    int idInterprete;
    char nombre[100];
    char nacionalidad[100];
    int estadoI;

}eInterprete;

typedef struct
{
    int idCancion;
    int interprete;
    char titulo[100];
    float duracion;
    int estadoC;
}eCancion;

void inicializarCanciones(eCancion[], int);
void inicializarInterprete(eInterprete[], int);
void mostrarCancion(eCancion[], int);
void mostrarInterpretes(eInterprete[], int);
void cancionesxInterprete(eInterprete[],eCancion[],int ,int);
void bajaInterprete(eInterprete[], int);
void bajaCancion(eCancion canciones[], int tam);
void mostrarCancionxNac(eCancion cancion[],eInterprete interprete[], int tamC, int tamI);

int main()
{
    char seguir = 's';
    int opcion;

    eCancion cancion[NUMCAN];
    eInterprete interprete[NUMIN];

    while(seguir == 's')
    {
        printf("1-.Alta cancion\n");
        printf("2-.Alta interprete\n");
        printf("3-.Mostrar canciones (Todas)\n");
        printf("4-.Mostrar interpretes(Todos)\n");
        printf("5-.Lista de canciones por interprete\n");
        printf("6-.Borrar interprete\n");
        printf("7-.Borrar canciones\n");
        printf("8-.Modificar interprete\n");
        printf("9-.Modificar canciones\n");
        printf("10-.Mostrar canciones artitas por pais\n");
        printf("11-.Mostrar artista con mas canciones \n");
        printf("12-.Mostrar la duracion de todos los temas de un artista\n");


        printf("13-.Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
                case 1:
                    system("cls");
                    inicializarCanciones(cancion, NUMCAN);
                    system("cls");
                    break;

                case 2:
                    system("cls");
                    inicializarInterprete(interprete, NUMIN);
                    system("cls");
                    break;

                case 3:
                    system("cls");
                    mostrarCancion(cancion, NUMCAN);
                    printf("\n");
                    system("pause");
                    system("cls");
                    break;

                case 4:
                    system("cls");
                    mostrarInterpretes(interprete, NUMIN);
                    system("pause");
                    system("cls");
                    break;

                case 5:
                    system("cls");
                    cancionesxInterprete(interprete,cancion, NUMIN, NUMCAN);
                    system("pause");
                    system("cls");
                    break;
                case 6:
                    system("cls");
                    bajaInterprete(interprete,NUMIN);
                    system("pause");
                    system("cls");

                    break;
                case 7:
                    system("cls");
                    bajaCancion(cancion,NUMCAN);
                    system("pause");
                    system("cls");
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 10:
                    system("cls");
                    mostrarCancionxNac(cancion,interprete, NUMCAN,NUMIN);
                    system("pause");
                    system("cls");
                    break;
                case 11:
                    break;
                case 12:
                    break;
                case 13:
                    seguir = 'n';
                    break;
        }

    }

    system("cls");

    return 0;
}


void inicializarCanciones(eCancion cancion[], int tam)
{
    int i;

    int idCancion[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int interprete[]={100,100,101,101,102,102,103,103,104,104,101,105,105,101,105};
    char titulo[][100]={"Clocks","Green Eyes","Roses","Young","You belong with me","Trouble","When I was your man","Grenade","Crimen","Cactus","Honest","Animals","Sunday Morning","Closer","Payphone"};
    float duracion[]={3.04,2.38,4.12,2.41,3.41,5.01,2.21,4.07,5.03,3.02,4.06,3.21,3.50,5.01,2,35};
    int estadoC[]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    for(i=0;i<tam;i++)
    {
        cancion[i].idCancion = idCancion[i];
        cancion[i].interprete = interprete[i];
        strcpy(cancion[i].titulo,titulo[i]);
        cancion[i].duracion=duracion[i];
        cancion[i].estadoC =estadoC[i];
    }
}

void inicializarInterprete(eInterprete interprete[], int tam)
{
    int i;
    int idInterprete[]={100,101,102,103,104,105};
    char nombre[][100]={"Coldplay", "Chainsmokers","Taylor Swift","Bruno Mars","Ceratti","Maroon 5"};
    char nacionalidad[][100]={"Britanico","EEUU","EEUU","EEUU","Argentino","EEUU"};
    int estadoI[]={1,1,1,1,1,1};

    for(i=0;i<tam;i++)
    {
        interprete[i].idInterprete=idInterprete[i];
        strcpy(interprete[i].nombre,nombre[i]);
        strcpy(interprete[i].nacionalidad, nacionalidad[i]);
        interprete[i].estadoI=estadoI[i];
    }
}


void mostrarCancion(eCancion cancion[], int tam)
{
    int i;
    printf("ID ------------------ TITULO -------------- INTERPRETE ---------- DURACION\n");

    for(i=0;i<tam;i++)
    {
        printf("\n%d\t%20s\t%20d\t%15.2f\t",cancion[i].idCancion,cancion[i].titulo,cancion[i].interprete,cancion[i].duracion);
    }

}

void mostrarInterpretes(eInterprete interprete[], int tam)
{
    int i;
    printf("\n\nID INTERPRETE ----------- NOMBRE ----------- NACIONALIDAD\n");

    for(i=0; i<tam;i++)
    {
        printf("%d\t%25s\t%15s\n",interprete[i].idInterprete, interprete[i].nombre, interprete[i].nacionalidad);
    }

}


void cancionesxInterprete(eInterprete interprete[],eCancion cancion[],int tamI, int tamC)
{
    int k,j;

    for(j=0; j<tamI; j++)
    {
        printf("%s:\n", interprete[j].nombre);

        for(k=0;k<tamC;k++)
        {
            if(cancion[k].interprete == interprete[j].idInterprete)
            {
                printf("%s\n",cancion[k].titulo);

            }
        }
                printf("\n");//Printf Cabeza 100% negro villero

    }

}

void bajaInterprete(eInterprete interprete[], int tam)
{
    int i;
    char opcion;
    int auxId;

    mostrarInterpretes(interprete, NUMIN);

    printf("Ingrese ID del artista a dar de baja:\n");
    scanf("%d",&auxId);

    for(i=0;i<tam;i++)
    {
        if(auxId == interprete[i].idInterprete)
        {
            printf("Dar de baja %s...? S/N\n",interprete[i].nombre);
            opcion=getche();
            if(opcion == 's'|| opcion == 'S')
            {
                interprete[i].estadoI = 0;
                printf("Se ha dado de baja %s con exito!",interprete[i].nombre);
                break;
            }
                else if(interprete[i].idInterprete != auxId);
                {
                printf("No se encontro la wea con la misma ID\n");
                }
        }

    }


}

void bajaCancion(eCancion canciones[], int tam)
{
    int i;
    char opcion;
    int auxId;

    mostrarCancion(canciones, NUMCAN);

    printf("Ingrese ID de la cancion a dar de baja:\n");
    scanf("%d",&auxId);

    for(i=0;i<tam;i++)
    {
        if(auxId == canciones[i].idCancion)
        {
            printf("Dar de baja %s...? S/N\n",canciones[i].titulo);
            opcion=getche();
            if(opcion == 's'|| opcion == 'S')
            {
                canciones[i].estadoC = 0;
                printf("Se ha dado de baja %s con exito!",canciones[i].titulo);
                break;
            }
                else if(canciones[i].idCancion != auxId);
                {
                printf("No se encontro la wea con la misma ID\n");
                }

        }
    }
}


void mostrarCancionxNac(eCancion cancion[],eInterprete interprete[], int tamC, int tamI)
{
    int i,j;
    int menu;

    printf("Ingrese la nacionalidad de las canciones que desea mostrar:\n1: Britanicas\n2: Estadounidenses\n3: Argentinas");
    scanf("%d",&menu);
    switch(menu)
        {
        case 1:
            for(i=0;i<tamI;i++)
            {
                if (strcmp(interprete[i].nacionalidad,"Britanico"))
                {
                    for(j=0;j<tamC;j++)
                        {
                            if(cancion[j].interprete==interprete[i].idInterprete)
                                {
                                printf("%s\n",cancion[j].titulo);
                                }

                        }
                }
            }
        break;

        }
}

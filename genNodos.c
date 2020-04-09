#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#include "motor.h"

typedef struct p2
{
    int id;
    int cost;
    struct p2 *sig;
    struct p2 *ant;
    struct p2 *aba;
    struct p2 *arr;
    //uint 8;
}nodos;

int x=0;
nodos *raiz=NULL, *nuNodo=NULL, *motor=NULL;
void insertar();
void acomodamelo();
void imprimemelo();
void liberamelo();
void imprimemelocost();
int RandomNumberGenerator(const int nMin, const int nMax);

int main()
{
    int matriz[15][3];
    for (int i = 0; i < 15; i++) {
      matriz[i][0]=i+1;
    }
    matriz[0][1]=0;
    matriz[0][2]=0;
    system("clear");
    int op;

    while(op!=4)
    {
        printf("\n\n\t\t\t\t**Menú**\n");
        printf("\t\t\t1. Insertar datos.\n");
        printf("\t\t\t2. Mostrar mapa de datos.\n");
        printf("\t\t\t3. Imprime costos.\n");
        printf("\t\t\t4. Salir.\n");
        printf("\nIngresa la opción que deseas: ");
        scanf("%i", &op);


        switch(op)
        {
        case 1:
            printf("Estoy en insertar\n");
            insertar();
            acomodamelo();
            system("clear");
            break;
        case 2:
            printf("Estoy en imprimir\n");
            imprimemelo();
            getchar();
            getchar();
            system("clear");
            break;
        case 3:
            imprimemelocost();
            getchar();
            getchar();
            system("clear");
            break;
        case 4:
            printf("Estoy saliendo\n");
            liberamelo();
            break;

        default:
            system("clear");
            printf("\n\n\n\t\t\t\tIngresa una opción válida.");
            sleep(5);
            break;
        }
    }

}

void insertar()
{
    nodos *nuevo;
    nuevo = (nodos*)malloc(sizeof(nodos));
    x++;//ID requerido.
    nuevo->id=x;
    nuevo->sig=NULL;
    nuevo->aba=NULL;
    nuevo->arr=NULL;
    nuevo->ant=NULL;
    nuevo->cost=RandomNumberGenerator(1,10);
    nuNodo=nuevo;

}
void acomodamelo(){
  //aux3 = renglon actual
  //aux2 = rengol anterior
  //aux = lugar actual
  nodos *aux,*aux2,*aux3;
  aux=raiz;
  aux2=raiz;
  aux3=raiz;
  if (raiz==NULL ) {
    raiz=nuNodo;
    nuNodo=NULL;
  }
  else{
    //While para recorrer filas
    while (aux->aba!=NULL) {
      aux=aux->aba;
      aux3=aux3->aba;
      if (aux->aba!=NULL) {
        aux2=aux;
      }
    }
    //recorrer columa
    while (aux->sig!=NULL) {
      aux=aux->sig;
      aux2=aux2->sig;
    }

    if (aux->id%5!=0) {
      aux->sig=nuNodo;
      nuNodo->ant=aux;
      if (aux->id >= 5) {
        aux2=aux2->sig;
        nuNodo->arr=aux2;
        aux2->aba=nuNodo;
      }

    }

    else{
      aux=aux3;
      aux->aba=nuNodo;
      nuNodo->arr=aux;
    }

  }
}

void imprimemelo(){
  nodos *aux,*aux2;
  aux=raiz;
  aux2=raiz;
  printf("Estoy adentro de la funcion\n");
  if (aux->aba==NULL) {
    printf("Estoy adentro de if\n");
    while (aux2->sig!=NULL) {
      printf("%d,",aux2->id );
      aux2=aux2->sig;
    }
    printf("%d\n",aux2->id );
  }
  else{
    printf("Estoy adentro de else\n");
    while (aux->aba!=NULL) {
      while (aux2->sig!=NULL) {
        printf("%d,",aux2->id );
        aux2=aux2->sig;
      }
      printf("%d\n",aux2->id );
      aux=aux->aba;
      aux2=aux;
    }
    while (aux2->sig!=NULL) {
      printf("%d,",aux2->id );
      aux2=aux2->sig;
    }
    printf("%d\n",aux2->id );
  }

}
void liberamelo(){
  nodos *aux,*aux2,*aux3;
  aux=raiz;
  aux2=raiz;
  aux3=raiz;
  if (aux->aba==NULL) {
    while (aux2->sig!=NULL) {
      aux2=aux2->sig;
      free(aux3);
      aux3=aux2;
    }
    free(aux2);
  }
  else{
    while (aux->aba!=NULL) {
      aux3=aux3->aba;
      while (aux2->sig!=NULL) {
        aux2=aux2->sig;
        free(aux);
        aux=aux2;
      }
      free(aux2);
      aux=aux3;
      aux2=aux3;
    }
    while (aux2->sig!=NULL) {
      aux2=aux2->sig;
      free(aux);
      aux=aux2;
    }
    free(aux2);
  }
}
int RandomNumberGenerator(const int nMin, const int nMax)
{
    int nRandonNumber = 0;

    nRandonNumber = rand()%(nMax-nMin) + nMin;
    return nRandonNumber;
}
void imprimemelocost(){
  nodos *aux,*aux2;
  aux=raiz;
  aux2=raiz;
  printf("Estoy adentro de la funcion\n");
  if (aux->aba==NULL) {
    printf("Estoy adentro de if\n");
    while (aux2->sig!=NULL) {
      printf("%d,",aux2->cost );
      aux2=aux2->sig;
    }
    printf("%d\n",aux2->cost );
  }
  else{
    printf("Estoy adentro de else\n");
    while (aux->aba!=NULL) {
      while (aux2->sig!=NULL) {
        printf("%d,",aux2->cost );
        aux2=aux2->sig;
      }
      printf("%d\n",aux2->cost );
      aux=aux->aba;
      aux2=aux;
    }
    while (aux2->sig!=NULL) {
      printf("%d,",aux2->cost );
      aux2=aux2->sig;
    }
    printf("%d\n",aux2->cost );
  }

}

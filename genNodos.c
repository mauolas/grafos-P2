#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//#include "motor.h"

typedef struct p2
{
    int id;
    int cost;
    int costposicion[2][4];
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
void costpos();
void imprimearr();
int adonde();
void imptabres(int resultados[][3],int listaLibres[],int listaNoLibres[]);
void actlistas(int listaLibres[],int listaNoLibres[]);

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
    int listaLibres[10];
    int listaNoLibres[10];
    int resultados[10][3];
    for (int i = 0; i < 10; i++) {
      listaLibres[i]=i+1;
      listaNoLibres[i]=0;
      resultados[i][0]=i+1;
      resultados[i][1]=999;
      resultados[i][2]=0;
    }
    resultados[0][1]=0;


    while(op!=7)
    {
        printf("\n\n\t\t\t\t**Menú**\n");
        printf("\t\t\t1. Insertar datos.\n");
        printf("\t\t\t2. Mostrar mapa de datos.\n");
        printf("\t\t\t3. Imprime costos.\n");
        printf("\t\t\t4. Planea costo.\n");
        printf("\t\t\t5. Imprime tabla resultados.\n");
        printf("\t\t\t6. Moverse.\n");
        printf("\t\t\t7. Salir.\n");
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
            costpos();
            imprimearr();
            for (int i = 0; i < 4; i++) {
              int x=1;
              if (motor->costposicion[0][i] != -1) {
                while (x != motor->costposicion[1][i]) {
                  x++;
                }
                if (resultados[x-1][1]>motor->costposicion[0][i]) {
                  resultados[x-1][1]=motor->costposicion[0][i];
                  resultados[x-1][2]=motor->id;
                }
              }
            }
            actlistas(listaLibres,listaNoLibres);
            //adonde();
            getchar();
            getchar();
            system("clear");
            break;
        case 5:
            imptabres(resultados,listaLibres,listaNoLibres);
            getchar();
            getchar();
            system("clear");
            break;

        case 6:
            printf("Nos movemos para:\n");
            adonde(listaNoLibres);
            break;

        case 7:
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
    nuevo->cost=RandomNumberGenerator(1,9);
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
    motor=raiz;
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

void costpos() {
  //Posicion 0=arriba 1=derecha 2=abajo 3=izquierda
  //Sacar costo arribq
  if (motor->arr !=NULL) {
    int temp=(motor->arr)->cost - motor->cost;
    if (temp<0) {
      temp=temp*(-1);
    }
    motor->costposicion[0][0]=temp;
    motor->costposicion[1][0]=(motor->arr)->id;
  }
  else{
    motor->costposicion[0][0]=-1;
    motor->costposicion[1][0]=0;
  }
  //sacar costo derecha
  if (motor->sig !=NULL) {
    int temp=(motor->sig)->cost - motor->cost;
    if (temp<0) {
      temp=temp*(-1);
    }
    motor->costposicion[0][1]=temp;
    motor->costposicion[1][1]=(motor->sig)->id;
  }
  else{
    motor->costposicion[0][1]=-1;
    motor->costposicion[1][1]=0;
  }
  //sacar costo abajo
  if (motor->aba !=NULL) {
    int temp=(motor->aba)->cost - motor->cost;
    if (temp<0) {
      temp=temp*(-1);
    }
    motor->costposicion[0][2]=temp;
    motor->costposicion[1][2]=(motor->aba)->id;
  }
  else{
    motor->costposicion[0][2]=-1;
    motor->costposicion[1][2]=0;
  }
  //sacar costo izquierda
  if (motor->ant !=NULL) {
    int temp=(motor->ant)->cost - motor->cost;
    if (temp<0) {
      temp=temp*(-1);
    }
    motor->costposicion[0][3]=temp;
    motor->costposicion[1][3]=(motor->ant)->id;
  }
  else{
    motor->costposicion[0][3]=-1;
    motor->costposicion[1][3]=0;
  }
}

void imprimearr(){
  for (int i = 0; i < 4; i++) {
    printf("Costo: %d,",motor->costposicion[0][i]);
    printf("ID: %d\n",motor->costposicion[1][i]);
  }
}

void imptabres(int resultados[][3],int listaLibres[],int listaNoLibres[]){
  for (int i = 0; i < 10; i++) {
    printf("%d\t%d\t%d\n",resultados[i][0],resultados[i][1],resultados[i][2] );
  }
  printf("Tabla libres:");
  for (int x = 0; x < 10; x++) {
    printf("%d,",listaLibres[x] );
  }
  printf("\nTabla no libres:");
  for (int x = 0; x < 10; x++) {
    printf("%d,",listaNoLibres[x] );
  }
}

int adonde(int listaNoLibres[]) {
  int temp = 10;
  int pos=-1;
  for (int i = 0; i < 4; i++) {
    if (motor->costposicion[0][i] != -1) {
      int x=0;
      int bandera=0;
      while (motor->costposicion[1][i] != listaNoLibres[x] && x<10) {
        x++;
      }
      if (motor->costposicion[1][i] == listaNoLibres[x]) {
        bandera = 1;
      }
      if (motor->costposicion[0][i]<temp && bandera == 0) {
        temp=motor->costposicion[0][i];
        pos = i;
      }
    }
  }
  if (pos==0) {
    printf("Arriba\n");
    motor=motor->arr;
  }
  else if(pos==1){
    printf("derecha\n");
    motor=motor->sig;
  }
  else if(pos==2){
    printf("abajo\n");
    motor=motor->aba;
  }
  else if(pos==3){
    printf("izquierda\n");
    motor=motor->ant;
  }
  else{
    printf("No me puedo mover hermano\n");
  }
  return temp;
}

void actlistas(int listaLibres[],int listaNoLibres[]){
  int i=0;
  while (listaLibres[i]!=motor->id) {
    i++;
  }
  listaLibres[i]=0;
  listaNoLibres[i]=motor->id;
}

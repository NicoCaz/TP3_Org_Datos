#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo *izq,*der;
} nodo;

typedef nodo * TArbol;

void agregando(TArbol *A,int dato);
void recorreInorden(TArbol A);
void meteDatos(TArbol *A);
void creaArch();
void meteDatos(TArbol *A);
void buscaRec(TArbol A,int dato,int *esta);
void buscaIterativa(TArbol A,int dato, int *pos);

int main() {
    TArbol A=NULL;
    int esta=0;
    creaArch();
    meteDatos(&A);
    recorreInorden(A);
    buscaRec(A,14,&esta);
    printf("\n \n");
    if(esta)
        printf("esta es dato");
    else
        printf("no esta el dato");
    printf("Hello world!\n");
    return 0;
}



void agregando(TArbol *A,int x) {
    if (*A == NULL) {
        *A = (TArbol)malloc(sizeof(nodo));
        (*A)->dato = x;
        (*A)->der = NULL;
        (*A)->izq = NULL;
    } else if (x>(*A)->dato)
        agregando(&((*A)->der), x);
    else
        agregando(&((*A)->izq), x);
}
void recorreInorden(TArbol A) {
    if(A!=NULL) {
        recorreInorden(A->izq);
        printf("  %d",A->dato);
        recorreInorden(A->der);
    }
}
void buscaRec(TArbol A,int dato,int *esta) {
    if(A!=NULL && !(*esta)) {
        if(A->dato > dato)
            buscaRec(A->izq,dato,esta);
        else if(A->dato <dato)
            buscaRec(A->der,dato,esta);
        else
            *esta=1;
    }
}
void creaArch(){
    FILE * arch = fopen("datos.dat","wb");
    fseek(arch,0,0);
    int dato;
    for(int i = 0;i<100000;i++){
     dato=rand();
     fwrite(&dato,sizeof(nodo),1,arch);
    }
    fclose(arch);
}
void meteDatos(TArbol *A){
    FILE * arch = fopen("datos.dat","rb");
    fseek(arch,0,0);
    int dato;
    fread(&dato,sizeof(nodo),1,arch);
    agregando(A,dato);
    while(fread(&dato,sizeof(nodo),1,arch )&& !feof(arch))
        agregando(A,dato);
    fclose(arch);

}


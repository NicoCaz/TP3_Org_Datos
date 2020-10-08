//--------------RECURSIVOS-------------------
void InsertaREC (int A[], int X,unsigned int i) {
    int aux;
    A[i]=X;
    if ((i>0)&&(A[(i-1)/2]<A[i])) {
        aux=A[(i-1)/2];
        A[(i-1)/2]=A[i];
        A[i]=aux;
        InsertaREC(A,X,(i-1)/2)
    }
}

void OrdenREC(int  A[],unsigned int act, unsigned int max) {
    if (act<max) {
        OrdenREC(A,2*act+1);
        printf("  %d ", A[act]);
        OrdenREC(A,2*act+2);
    }
}

int BuscaREC(int A, int X,unsigned int act,unsigned int max) {
    if (act<max) {
        if (A[act]==X)
            return 1;
        else
            return BuscaREC(A,X,2*act+2,max)||BuscaREC(A,X,2*act+1,max);
    } else
        return 0;
}
//---------------ITERATIVOS-------------------
void InsertaIT (int  A[], int  X,unsigned int i) {
    Tdato aux;
    A[i]=X;
    while ((i>0)&&(A[(i-1)/2]<A[i])) {
        aux=A[(i-1)/2];
        A[(i-1)/2]=A[i];
        A[i]=aux;
        i=(i-1)/2;
    }
}

void OrdenIT(Tdato A[],unsigned int max) {
    TPila pila;
    IniciaP(pila);
    unsigned int i=0;
    if (max>=0) {
        do {
            while (i<max) {
                PoneP(pila,i);
                i=2*i+1;
            }
            SacaP(pila,i);
            printf("\t%d",A[i]);
            i=2*i+2;
        } while (!VaciaP(pila) && i<max)
        }
}


int BuscaIT(Tdato A[],Tdato X,unsigned int max) {
    int i=0;
    if (max>=0) {
        while(A[i]!=X && i<max)
            i++;
        return (A[i]==X);
    } else
        return 0;
}


//-------------------PERSISTENCIA--------
void ArbolARigido(Tdato A[], unsigned int max) {
    FILE *arch;
    unsigned int i=0;
    arch=fopen("ArbolMEM.dat","wb");
    for (i=0; i<max; i++) {
        fwrite(&A[i],sizeof(Tdato),1,arch);
    }
    fclose(arch);
}



void InsertaIT (TArbol *A, int X)
{
    int noinserta=0;
    arbol aux,rec;
    rec=*A;
    aux = (arbol) malloc (sizeof (struct nodo));
    aux->dato = X;
    aux->der = NULL;
    aux->izq = NULL;
    if (rec!=NULL)
        while (!noinserta)
        {
            if (X>rec->dato)
                if (rec->der==NULL)
                {
                    noinserta=!;
                    rec->der=aux;
                }
                else
                    rec=rec->der;
            else if (rec->izq==NULL)
            {
                noinserta=!;
                rec->izq=aux;
            }
            else
                rec=rec->izq;
        }
    else
        *A=aux;
}

void OrdenIT(TArbol A)
{
    TPila pila;
    IniciaP(pila);
    if (A!=NULL)
    {
        do
        {
            while (A != NULL)
            {
                PoneP(pila,A);
                A=A->der;
            }
            SacaP(pila,A);
            printf("\t%d",A->dato);
            A=A->der;
        }
        while (!VaciaP(pila) && A!=NULL)
        }
}
int BuscaIT(TArbol A,int X)
{
    if (A!=NULL)
    {
        while(A->dato!=X)
        {
            if (X>A->dato)
                A=A->der;
            else
                A=A->izq;
        }
        return A->dato;
    }
    else
        return 0;
}

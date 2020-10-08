

void InsertaREC (int A[], int X,unsigned int i)
{
    Tdato aux;
    A[i]=X;
    if ((i>0)&&(A[(i-1)/2]<A[i]))
    {
        aux=A[(i-1)/2];
        A[(i-1)/2]=A[i];
        A[i]=aux;
        InsertaREC(A,X,(i-1)/2)
    }
}

void OrdenREC(Tdato A[],unsigned int act, unsigned int max)
{
    if (act<max)
    {
        OrdenREC(A,2*act+1);
        printf("  %d ", A[act]);
        OrdenREC(A,2*act+2);
    }
}

int BuscaREC(Tdato A,Tdato X,unsigned int act,unsigned int max)
{
    if (act<max)
    {
        if (A[act]==X)
            return 1;
        else
            return BuscaREC(A,X,2*act+2,max)||BuscaREC(A,X,2*act+1,max);
    }
    else
        return 0;
}

#include <stdio.h>

int numeroAppel = 1;


int fibo(int n)
{

printf("\nAppel %d : valeur de n reçue=%d",numeroAppel++,n) ;

//conditions d'arret
if (n==0) return 1;
else if (n==1) return 1;
else    
        {
            return fibo(n-1) + fibo(n-2) ; 
        }
 

}



int main()
{

int v=4;
printf("\n\tfibo(%d)= %d \n\n",v,fibo(v));
return 0;
}

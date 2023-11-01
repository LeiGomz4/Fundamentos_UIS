#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <climits>
#include <iostream>

int factorial(int );
float media(int [], int );

int main()
{
    int n, i;
    printf("Introduzca el número de elementos, por favor: ");
    scanf("%d", &n);
    srand(time(0));
    int elementos[n];
    // generación de los n elementos, con valores enteros entre 1 y 100
    for ( i = 0; i < n; i++ )
    {
        elementos[i] = 1 + rand() % 100;
    }

    // impresión en pantalla de los elementos generados.
    for ( i = 0; i < n; i++ )
    {
        printf("%d ", elementos[i]);
    }
    printf("\n");
    int mayor = elementos[0];
    int menor = elementos[0];
    int posmayor = 0; 
    int posmenor = 0;
    // mayor y menor.
    for (i = 0; i < n; i++)
    {
        if (elementos[i] > mayor)
        {
            printf("El elemento %d es %d, el mayor es %d\n", i+1, elementos[i], mayor);
            mayor = elementos[i];
            posmayor = i;
        }

        if (elementos[i] < menor)
        {
            menor = elementos[i];
            posmenor = i;
        }
    }
    printf("El mayor es %d, pos %d. El menor es %d, pos %d\n", mayor, posmayor, menor, posmenor);
    // factorial
    for (i = 0; i < n; i++)
    {
        long long int fact = 1;
        if (elementos[i] < 20)
        {
            fact = factorial(elementos[i]);
            std::cout << elementos[i] << "! = " << fact << std::endl;
            printf("El factorial de %d es %lld\n", elementos[i], fact);
        }
        
    }

    int conteos[n];
    int j;
    for (i = 0; i < n; i++)
    {
        int temp = 0;
        for (j = 0; j < n; j++)
        {
            if (elementos[i] == elementos[j])
            {
                temp++;
            }
        }
        conteos[i] = temp;
    }

    for ( i = 0; i < n; i++ )
    {
        printf("%d: %d ", elementos[i], conteos[i]);
    }
    printf("\n");
    // calculo de la media
    float prom = media(elementos, n);
    printf("La media es %f\n", prom);
    


}

float media(int V[], int n)
{
    float suma = 0;
    int i;
    for (i=0; i<n; i++)
    {
        suma = suma + V[i];
    }
    return suma / n;
}

int factorial(int m)
{
    long long int fact = 1;
    while (m > 1)
    {
        fact = fact * m;
        m = m - 1;
    }
    return fact;
}


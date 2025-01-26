// ProgramacionParalela.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <omp.h>

#define N 1500
#define chunk 20
#define mostrar 25

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando arreglos en paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    for (i = 0;i < N;i++)
    {
        a[i] = i * 10;
        b[i] = (i * 3) * 6;
    }
    int pedazos = chunk;

    #pragma omp parallel for \
    shared(a,b,c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0;i < N;i++)
        c[i] = a[i] * b[i];

    std::cout << "" << mostrar << "valores arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "" << mostrar << "valores arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "" << mostrar << "valores arreglo c: " << std::endl;
    imprimeArreglo(c);
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar;x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}
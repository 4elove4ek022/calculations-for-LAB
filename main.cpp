#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define N 100

int putin(const void *i, const void *j);

double error(double *cmass, double ave);

double average(double *cmass);

int main()
{
    double mass[N] = {55, 47, 58, 60, 38, 37, 62, 41, 38, 47, 44, 51, 36, 61, 46, 55, 53, 49, 59, 65, 47, 55, 49, 54, 45, 54, 59, 62, 54, 44, 50, 52, 41, 30, 48, 47, 49, 52, 108, 43, 48, 34, 54, 47, 63, 60, 51, 56, 52, 47, 55, 59, 44, 57, 50, 49, 45, 47, 52, 48, 56, 43, 49, 49, 46, 53, 42, 35, 39, 56, 49, 39, 60, 55, 35, 45, 49, 42, 51, 35, 41, 50, 37, 42, 64, 48, 49, 38, 51, 45, 54, 62, 54, 46, 42, 59, 39, 45, 45, 63};
    double cmass[N];
    for(size_t i = 0; i < N; i++)
    {
        cmass[i] = mass[i];
    }

    setlocale(LC_ALL,"russian");

    /*printf("Библиотечкая функция qsort() имеет 4 аргумента.\n"
    /      "Первые два параметра это параметрты,позволяющие получать доступ -> qsort(указатель, размер массива)\n"
    /       "потом размер элемента( sizeof(type)) и 4 - это как сортировать: > 0 if n1 > n2; = 0 if n1 = n2; < 0 if n1 < n2\n"
    /       "Итог : qsort(указатель, размер, sizeof(type), имя_функции_сравнения);\n"
    /       "Пример сортировки в коде программы...\n\n\n\n\n\n"); */

    qsort(mass, N, sizeof(double), putin);

    int i = 0;
    int counter = 1;

    for(i; i < N; i++)
    {
        if(!mass[i]) break;// все не инициализированные эл-ты массива или нули не печатать.
        if(mass[i] == mass[i-1]) counter++;
        else if(mass[i] != mass[i-1])
            {
                printf("    ||    sum = %d\n", counter);
                counter = 1;
            }
        printf("%10.2lf |",mass[i]);
    }

    printf("\n i = %d", i);

    double ave = average(cmass);
    double sigma = error(cmass, ave);
    printf("\n\n\n average = %lf", ave);
    printf("\n sigma = %lf", sigma);

    return 0;
}

int putin(const void *i, const void *j)
{

    return *(double *)j - *(double *)i;
}

double error(double *cmass, double ave)
{
    double sum = 0;
    for(int i = 0; i < N; i++)
        sum+= pow(cmass[i] - ave,2);
    return sqrt(sum / (N * (N-1) ));
}

double average(double *cmass)
{
    double sum = 0;
    for(int i = 0; i < N; i++)
        sum+=cmass[i];
    return (sum/N);
}

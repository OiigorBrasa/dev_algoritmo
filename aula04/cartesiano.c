#include <stdio.h>

void cartesianos(float x, float y)
{
    if (x == 0 && y == 0)
    {
        printf("Origem");
    }
    else if (x == 0)
    {
        printf("Sobre o eixo y");
    }
    else if (y == 0)
    {
        printf("Sobre o eixo x");
    }
    else
    {
        if (x > 0 && y > 0)
        {
            printf("Q1");
        }
        else if (x < 0 && y > 0)
        {
            printf("Q2");
        }
        else if (x < 0 && y < 0)
        {
            printf("Q3");
        }
        else
        {
            printf("Q4");
        }
    }
}

int main()
{
    float x, y;
    printf("Digite x e y:\n");
    scanf(" %f", &x);
    scanf(" %f", &y);
    cartesianos(x, y);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a = 0,b = 0,c = 0,media = 0;

     do {
        printf("entre com a primeira nota de 0 a 10-->");
    scanf("%f", &a);
     }while (a<0 || a>10);

     do {
        printf("entre com a segunda nota de 0 a 10-->");
    scanf("%f", &b);
     }while (b<0 || b>10);

     do {
        printf("entre com a terceira nota de 0 a 10-->");
    scanf("%f", &c);
     }while (c<0 || c>10);

    media=(a+b+c)/3;
    system("cls");
    printf("Nota 1 -> %.1f", a);
    printf("\nNota 2 -> %.1f", b);
    printf("\nNota 3 -> %1.f", c);

    printf("\n\nMedia = (%.1f + %.1f + %.1f)/3 = %.2f\n", a, b, c, media);
    if(media<6)
        {
        printf("\nSua media e insuficiente\nmedia -> %.2f\n", media);
        }
    else if(media>=6 && media<8)
        {
        printf("\nSua media e mediocre\nmedia -> %.2f\n", media);
        }
    else if (media>=8)
    {
        printf("\nSua media e excelente\nmedia -> %.2f\n", media);
    }
    return 0;
}
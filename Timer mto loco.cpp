#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "bugiganga.cpp"
#define primeira_vez 2 //defina 1 se for a primeira vez ou 2 se o programa já foi compilado neste computador

int mtrx[10][10]={0};
int matriz_inicio[30][13]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,7,7,7,7,7,7,7,7,0,0,0},
        {0,7,0,0,0,0,0,0,0,0,7,0,0},
        {0,7,0,0,0,0,0,7,0,0,7,0,0},
        {0,7,0,0,0,0,0,7,0,0,7,0,0},
        {0,7,0,0,0,0,0,7,7,7,7,7,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,7,7,7,7,7,7,7,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,7,0,0},
        {0,7,0,0,0,0,0,0,0,0,7,0,0},
        {0,7,0,0,0,0,0,0,0,0,7,0,0},
        {0,7,0,7,7,7,7,7,7,7,0,0,0},
        {0,7,0,0,0,0,0,0,0,0,0,0,0},
        {0,7,7,7,7,7,7,7,7,7,7,0,0},
        {0,7,0,0,0,0,0,0,0,0,0,0,0},
        {0,7,0,0,7,7,7,7,7,7,7,0,0},
        {0,7,0,7,0,0,0,7,0,0,0,0,0},
        {0,7,0,7,0,0,0,7,0,0,0,0,0},
        {0,7,0,7,0,0,0,7,0,0,0,0,0},
        {0,7,0,7,0,0,0,7,0,0,0,0,0},
        {0,7,0,0,7,7,7,7,7,7,7,0,0},
        {0,7,0,0,0,0,0,0,0,0,0,0,0},
        {0,7,7,7,7,7,7,7,7,7,0,0,0},
        {0,7,0,0,0,0,0,0,0,0,7,0,0},
        {0,7,0,0,0,0,0,0,0,0,7,0,0},
        {0,7,0,0,0,0,0,0,0,0,7,0,0},
        {0,7,0,0,0,0,0,0,0,0,7,0,0},
        {0,0,7,7,7,7,7,7,7,7,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0},
     };
     void Abertura(void){
    //função abertura
for(int x=0;x<30;x++){
        for(int y=0;y<13;y++)
         {
           gotoxy(x,y);
           if(matriz_inicio[x][y]==0){textcolor(WHITE);}
           if(matriz_inicio[x][y]==7){textcolor(VERDE);}
           printf("%c",219);
         }
     }
}
    int direita [32][34]={
       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,1,1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,1,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0,0},
       {0,0,0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0},
       {0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0},
       {0,0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,3,3,3,3,3,1,1,1,1,0},
       {0,1,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,3,3,1,1,2,2,1,0},
       {0,1,2,2,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,4,4,2,2,2,1,0},
       {0,1,2,2,1,2,2,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,2,4,4,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,4,4,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,4,4,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,4,4,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,4,4},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,4},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,7,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,7,7,7,7,2,1,2,2,2,1,0},
       {0,0,1,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,7,7,2,2,2,1,2,2,1,0,0},
       {0,0,0,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,1,0,0,0},
       {0,0,0,0,1,1,1,1,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,1,1,1,1,1,0,0,0,0},
       {0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    int esquerda [32][34]={
       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,1,1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,1,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0,0},
       {0,0,0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0},
       {0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0},
       {0,0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,1,3,3,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,0},
       {0,1,2,2,1,3,3,3,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,2,2,1,0},
       {0,1,2,2,1,1,4,4,4,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,2,2,2,1,0},
       {0,1,2,2,1,4,4,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,2,2,2,1,0},
       {0,1,2,2,4,4,2,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,2,1,2,2,2,1,0},
       {0,1,2,4,4,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,2,2,2,1,0},
       {0,1,4,4,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,4,4,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {4,4,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {4,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,7,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,7,7,7,7,2,1,2,2,2,1,0},
       {0,0,1,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,7,7,2,2,2,1,2,2,1,0,0},
       {0,0,0,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,1,0,0,0},
       {0,0,0,0,1,1,1,1,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,1,1,1,1,1,0,0,0,0},
       {0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    int sem_baqueta[32][34]={
       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,1,1,1,1,1,3,3,3,3,3,3,3,3,1,1,1,1,1,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0,0},
       {0,0,0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0,0,0},
       {0,0,0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,0,0,0},
       {0,0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,0},
       {0,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,0},
       {0,1,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,2,2,1,0},
       {0,1,2,2,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,2,2,2,1,0},
       {0,1,2,2,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,7,2,1,2,2,2,1,0},
       {0,1,2,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,7,7,7,7,2,1,2,2,2,1,0},
       {0,0,1,2,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,7,7,2,2,2,1,2,2,1,0,0},
       {0,0,0,1,1,2,2,2,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,1,2,1,0,0,0},
       {0,0,0,0,1,1,1,1,2,1,1,2,2,2,2,2,2,2,2,2,1,1,2,2,2,1,1,1,1,1,0,0,0,0},
       {0,0,0,0,0,0,1,1,1,1,1,1,1,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
       {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
    int prato_2[20][26]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
        {0,1,1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {0,1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,3,3,1,1,1,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,3,3,1,1,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,3,3,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,3,3,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,3,3,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
    };
    int prato_1[20][26]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,3,3,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1,1,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,3,3,1,1,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,3,3,1,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,1,1,1,1,1,1,1,3,3,1,1,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,3,3,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,3,3,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,3,3,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};
    int prato_inicial[20][26]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0},
        {0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0},
    };
    int prato_inicial_2[20][26]={
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
        {0,1,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,1,1,1,1,1,1,1,1,2,2,1,1,1,1,1,1,1,1,1,1,0,0,0,0},
        {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    };
void animacao(void){
    //função animação
   int aux=0;
   while(1){
        for(int x=0;x<20;x++){
            for(int y=0;y<26;y++)
        {
            gotoxy(y+80,x);
           if(prato_inicial[x][y]==0){textcolor(PRETO);}
           if(prato_inicial[x][y]==1){textcolor(YELLOW);}
           if(prato_inicial[x][y]==2){textcolor(DARK_GRAY);}
           printf("%c",219);
        }
     }
        for(int x=0;x<20;x++){
            for(int y=0;y<26;y++)
        {
            gotoxy(y+10,x);
           if(prato_inicial_2[x][y]==0){textcolor(PRETO);}
           if(prato_inicial_2[x][y]==1){textcolor(YELLOW);}
           if(prato_inicial_2[x][y]==2){textcolor(DARK_GRAY);}
           printf("%c",219);
        }
     }
    for(int x=0;x<32;x++){

        for(int y=0;y<34;y++)
         {
           gotoxy(y+40,x);
           if(direita[x][y]==0){textcolor(PRETO);}
           if(direita[x][y]==1){textcolor(DARK_GRAY);}
           if(direita[x][y]==2){textcolor(VERMELHO);}
           if(direita[x][y]==3){textcolor(LIGHT_GRAY);}
           if(direita[x][y]==4){textcolor(MARRON);}
           printf("%c",219);
         }
     }
     Sleep(10);
   //  system("cls");
     for(int x=0;x<32;x++){
        for(int y=0;y<34;y++)
        {
            gotoxy(y+40,x);
           if(esquerda[x][y]==0){textcolor(PRETO);}
           if(esquerda[x][y]==1){textcolor(DARK_GRAY);}
           if(esquerda[x][y]==2){textcolor(VERMELHO);}
           if(esquerda[x][y]==3){textcolor(LIGHT_GRAY);}
           if(esquerda[x][y]==4){textcolor(MARRON);}
           printf("%c",219);
        }
     }
     Sleep(10);
   //  system("cls");
     aux++;
     if(aux%5==0){
      //  system("cls");
         for(int x=0;x<32;x++){
            for(int y=0;y<34;y++)
        {
            gotoxy(y+40,x);
           if(sem_baqueta[x][y]==0){textcolor(PRETO);}
           if(sem_baqueta[x][y]==1){textcolor(DARK_GRAY);}
           if(sem_baqueta[x][y]==2){textcolor(VERMELHO);}
           if(sem_baqueta[x][y]==3){textcolor(LIGHT_GRAY);}
           if(sem_baqueta[x][y]==4){textcolor(MARRON);}
           printf("%c",219);
        }
     }
        for(int x=0;x<20;x++){
            for(int y=0;y<26;y++)
        {
            gotoxy(y+80,x);
           if(prato_2[x][y]==0){textcolor(PRETO);}
           if(prato_2[x][y]==1){textcolor(YELLOW);}
           if(prato_2[x][y]==2){textcolor(DARK_GRAY);}
           if(prato_2[x][y]==3){textcolor(MARRON);}
           printf("%c",219);
        }
     }
        for(int x=0;x<20;x++){
            for(int y=0;y<26;y++)
        {
            gotoxy(y+10,x);
           if(prato_1[x][y]==0){textcolor(PRETO);}
           if(prato_1[x][y]==1){textcolor(YELLOW);}
           if(prato_1[x][y]==2){textcolor(DARK_GRAY);}
           if(prato_1[x][y]==3){textcolor(MARRON);}
           printf("%c",219);
        }
     }

     Sleep(200);
  //   system("cls");
     }
     if(aux==20){
        break;
     }
   }
}

void escreve_arquivo(int display, int cor_fundo, int cor_digito, int cor_painel)       
{
    //função pra escrever os dados no arquivo
    FILE *fp;
    fp = fopen("teste_eba", "w");           
        if(!fp){
            printf("Erro");
            exit(0);
        }
        fprintf(fp, "%i\n", display); //número salvo
        fprintf(fp, "100\n"); //número inicial
        fprintf(fp, "%i\n", cor_fundo); //cor do fundo salvo
        fprintf(fp, "%i\n", cor_digito); //cor dos digitos salvo
        fprintf(fp, "%i\n", cor_painel); //cor do painel salvo
    fclose(fp);
}

 int mostra_cent(int numero, int numero2)
{
    //funcao para mostrar as centenas
    int p_escrita=0;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
         {
           gotoxy(j+22,i);
           if(numero==1){
               if(mtrx[j][i]==0){textcolor(PRETO);}
               p_escrita=1;
           }
           else if(numero==2){
               if(mtrx[j][i]==0){textcolor(AZUL);}
               p_escrita=2;
           }
           else if(numero==3){
               if(mtrx[j][i]==0){textcolor(LIGHT_GRAY);}
               p_escrita=3;
           }
           else if(numero==4){
               if(mtrx[j][i]==0){textcolor(CIANO);}
               p_escrita=4;
           }
           if(numero2==1){
               if(mtrx[j][i]==1){textcolor(VERDE);}
           }
           else if(numero2==2){
               if(mtrx[j][i]==1){textcolor(WHITE);}
           }
           else if(numero2==3){
               if(mtrx[j][i]==1){textcolor(MARRON);}
           }
           else if(numero2==4){
               if(mtrx[j][i]==1){textcolor(VERMELHO);}
           }
           printf("%c",219);
         }
    return(p_escrita);
}
 int mostra_dez(int numero, int numero2)
{
   //funcao para mostrar as dezenas
    int p_escrita;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
          gotoxy(j+33,i);
          if(numero==1){
               if(mtrx[j][i]==0){textcolor(PRETO);}
           }
           else if(numero==2){
               if(mtrx[j][i]==0){textcolor(AZUL);}
           }
           else if(numero==3){
               if(mtrx[j][i]==0){textcolor(LIGHT_GRAY);}
           }
           else if(numero==4){
               if(mtrx[j][i]==0){textcolor(CIANO);}
           }
           if(numero2==1){
               if(mtrx[j][i]==1){textcolor(VERDE);}
               p_escrita=1;
           }
           else if(numero2==2){
               if(mtrx[j][i]==1){textcolor(WHITE);}
               p_escrita=2;
           }
           else if(numero2==3){
               if(mtrx[j][i]==1){textcolor(MARRON);}
               p_escrita=3;
           }
           else if(numero2==4){
               if(mtrx[j][i]==1){textcolor(VERMELHO);}
               p_escrita=4;
           }
          printf("%c",219);
        }
    return(p_escrita);
}
 int mostra_uni(int numero, int numero2)
{
   //funcao para mostrar as unidades
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
          gotoxy(j+44,i);
          if(numero==1){
               if(mtrx[j][i]==0){textcolor(PRETO);}
           }
           else if(numero==2){
               if(mtrx[j][i]==0){textcolor(AZUL);}
           }
           else if(numero==3){
               if(mtrx[j][i]==0){textcolor(LIGHT_GRAY);}
           }
           else if(numero==4){
               if(mtrx[j][i]==0){textcolor(CIANO);}
           }
           if(numero2==1){
               if(mtrx[j][i]==1){textcolor(VERDE);}
           }
           else if(numero2==2){
               if(mtrx[j][i]==1){textcolor(WHITE);}
           }
           else if(numero2==3){
               if(mtrx[j][i]==1){textcolor(MARRON);}
           }
           else if(numero2==4){
               if(mtrx[j][i]==1){textcolor(VERMELHO);}
           }
          printf("%c",219);
        }
}

 int muda_cor_fundo()
 {
     //função para mudar a cor do fundo e retornar um valor para salvar
     int cor, p_escrita=0;
     gotoxy(30,19);
     printf(" Escolha a nova cor-->");
     gotoxy(30,20);
     printf("\n\n1- Azul\n2- Vermelho\n3- Verde\n4- Amarelo\n5- Roxo");
     gotoxy(54,19);
     scanf("%i", &cor);
     switch(cor)
     {
        case 1:
        system("color 1F");
        p_escrita=1;
        break;

        case 2:
        system("color 4F");
        p_escrita=2;
        break;

        case 3:
        system("color 2F");
        p_escrita=3;
        break;

        case 4:
        system("color 6F");
        p_escrita=4;
        break;

        case 5:
        system("color 5F");
        p_escrita=5;
        break;
     }
     gotoxy(25,12);
        printf("                                 ");    
     gotoxy(30,19);
        printf("                                 ");
     gotoxy(0,22);
        printf("                                 ");
     gotoxy(0,23);
         printf("                               ");
     gotoxy(0,24);
         printf("                               ");
     gotoxy(0,25);
         printf("                               ");
     gotoxy(0,26);
         printf("                               ");
    return(p_escrita);
 }

 int muda_cor_digitos(){
 }

 void zera_mtrx(void)
 {
   //função p zerar a matriz
   for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        mtrx[i][j]=0;
 }
 void desenho_numero(int D)
{
    //função que desenha o numero recebido
    //i = linha j = coluna
  if(D==0){
    for(int j=3;j<8;j++)
       mtrx[1][j]=1;
    for(int j=2;j<9;j++)
       mtrx[2][j]=1;
    for(int j=3;j<8;j++)
       mtrx[8][j]=1;
    for(int j=2;j<9;j++)      //MOSTRAR 0
       mtrx[7][j]=1;

    for(int i=2;i<8;i++)
    {
     mtrx[i][2]=1;
     mtrx[i][3]=1;
     mtrx[i][7]=1;
     mtrx[i][8]=1;
    }
  }
  else if(D==1)
  {
    for(int i=2;i<8;i++)
     mtrx[i][8]=1;
      for(int j=2;j<9;j++){     //MOSTRAR 1
        mtrx[4][j]=1;
        mtrx[5][j]=1;
    }
    for(int j=3;j<5;j++)
        mtrx[3][j]=1;
    for(int i=2;i<3;i++)
        mtrx[i][4]=1;
  }
  else if(D==2)
  {
    for(int i=2;i<8;i++)
     mtrx[i][8]=1;
    for(int i=2;i<5;i++)
        mtrx[i][7]=1;
    for(int i=3;i<6;i++)
        mtrx[i][6]=1;
    for(int i=1;i<3;i++){       //MOSTRAR 2
        mtrx[i][4]=1;
        mtrx[i][3]=1;
    }
    for(int i=4;i<7;i++)
        mtrx[i][5]=1;

  for(int i=5;i<8;i++)
        mtrx[i][4]=1;
  for(int i=3;i<8;i++)
        mtrx[i][3]=1;
  for(int i=2;i<7;i++)
        mtrx[i][2]=1;
  }
    else if(D==3){
        for(int i=1;i<8;i++){
            mtrx[i][2]=1;
            mtrx[i][8]=1;
        }
        for(int j=3;j<8;j++){
            mtrx[7][j]=1;       //MOSTRAR 3
            mtrx[8][j]=1;
        }
        for(int i=2;i<9;i++)
           mtrx[i][5]=1;
   }
    else if(D==4){
       for(int j=2;j<9;j++){
           mtrx[6][j]=1;
           mtrx[7][j]=1;
          // mtrx[8][j]=1;
        }
       for(int j=2;j<5;j++){
           mtrx[1][j]=1;        //MOSTRAR 4
           mtrx[2][j]=1;
          // mtrx[3][j]=1;
       }
       for(int i=1;i<7;i++){
        mtrx[i][5]=1;
       }
    }
    else if(D==5){
        for(int i=1;i<8;i++){
            mtrx[i][2]=1;
            mtrx[i][8]=1;
            mtrx[i][5]=1;
        }
        for(int i=6;i<8;i++){   //MOSTRAR 5
            mtrx[i][6]=1;
            mtrx[i][7]=1;
        }
        for(int j=3;j<6;j++){
            mtrx[1][j]=1;
            mtrx[2][j]=1;
        }
    }
   else if(D==6){
        for(int i=2;i<7;i++){
            mtrx[i][2]=1;
            mtrx[i][8]=1;
        }
        for(int j=3;j<8;j++){
            mtrx[1][j]=1;
            mtrx[2][j]=1;       //MOSTRAR 6
        }
        for(int i=6;i<8;i++){
            mtrx[i][6]=1;
            mtrx[i][7]=1;
        }
        for(int i=4;i<7;i++)
            mtrx[i][5]=1;
    }
    else if(D==7){
        for(int i=1;i<8;i++)
            mtrx[i][2]=1;
        for(int i=1;i<3;i++)
            mtrx[i][8]=1;
        for(int i=2;i<4;i++)
            mtrx[i][7]=1;
        for(int i=3;i<5;i++)    //MOSTRAR 7
            mtrx[i][6]=1;
        for(int i=4;i<6;i++)
            mtrx[i][5]=1;
        for(int i=5;i<7;i++)
            mtrx[i][4]=1;
        for(int i=6;i<7;i++)
            mtrx[i][4]=1;
        for(int i=6;i<8;i++)
            mtrx[i][3]=1;

    }
    else if(D==8){
        for(int i=2;i<8;i++){
            mtrx[i][2]=1;
            mtrx[i][5]=1;
            mtrx[i][8]=1;
        }
        for(int j=3;j<5;j++){
            mtrx[1][j]=1;
            mtrx[2][j]=1;       //MOSTRAR 8
            mtrx[7][j]=1;
            mtrx[8][j]=1;
        }
        for(int j=6;j<8;j++){
            mtrx[1][j]=1;
            mtrx[2][j]=1;
            mtrx[7][j]=1;
            mtrx[8][j]=1;
        }
    }
      else if(D==9){
        for(int i=2;i<8;i++){
            mtrx[i][2]=1;
            mtrx[i][5]=1;
            mtrx[i][8]=1;
        }
        for(int j=3;j<8;j++){   //MOSTRAR 9
            mtrx[8][j]=1;
            mtrx[7][j]=1;
        }
        for(int j=3;j<5;j++){
            mtrx[1][j]=1;
            mtrx[2][j]=1;
        }
      }

}
 int main(){ 
     Abertura();
     printf("\nTURMA 4312 - dia:0x/05");
     Sleep(5000);                                   //Abertura
     system("cls");
      int aux, total, cor_fundo, cor_digito, cor_painel;
      int p=0,c=0, display, n_inicio, y;

        if(primeira_vez==1){
            FILE *fp;
            fp = fopen ("teste_eba","r");   //cria o arquivo caso ainda não exista
            escreve_arquivo(0,2,3,5);
        }
        
        FILE *fp;
        fp = fopen ("teste_eba","r");
         fscanf(fp, "%i" "%i" "%i" "%i" "%i", &total, &n_inicio, &cor_fundo, &cor_digito, &cor_painel); //le o arquivo
              
        if(cor_fundo==1){system("color 1F");}       //azul
        else if(cor_fundo==2){system("color 4F");}  //vermelho
        else if(cor_fundo==3){system("color 2F");}  //verde
        else if(cor_fundo==4){system("color 6F");}  //amarelo
        else if(cor_fundo==5){system("color 5F");}  //roxo
        
        if(total==0){
            total=100;
        }
   int cent=total/100, dez=(total%100)/10, uni=(total%100)%10;

        desenho_numero(uni);
           mostra_uni(cor_painel, cor_digito);
                zera_mtrx();
                
        desenho_numero(dez);                       
         cor_digito = mostra_dez(cor_painel, cor_digito);
                zera_mtrx();
                
         desenho_numero(cent);
         cor_painel = mostra_cent(cor_painel, cor_digito);
                zera_mtrx();

         gotoxy(20,11);
            printf(" Digite # para iniciar a contagem:  ");
        p=getchar();
            if(p==35){                                     //começar pausado
         gotoxy(20,11);
            printf("                                    ");
        gotoxy(20,11);
            printf(" Pressione # para pausar/mudar o valor  ");
        gotoxy(20,14);                                                     //opções de entrada
            printf(" Pressione & para mudar a cor do fundo  ");
        gotoxy(20,15);
            printf( "Pressione ! para mudar a cor do painel ");
        gotoxy(20,16);
            printf( "Pressione - para mudar a cor dos digitos");
        }


    for(aux=uni;aux>=0;aux--){                      //Laço do timer
       if(kbhit()){
            c=getchar();
            if(c==35){
                scanf("%i", &p);
                total=p;                            //Função para pausar e mudar o valor do timer
                cent=total/100;
                dez=(total%100)/10;
                uni=(total%100)%10;
                aux=uni;
                gotoxy(25,12);
                printf("                               ");
         }
            else if(c==38){
                cor_fundo = muda_cor_fundo();
            }
            else if(c==33){
                gotoxy(30,20);
                printf("\n\n1- Preto\n2- Azul\n3- Cinza\n4- Ciano");
                scanf("%i", &cor_painel);
                gotoxy(25,12);
                     printf("                                 ");
                gotoxy(0,22);
                     printf("                                 ");
                gotoxy(0,23);
                     printf("                               ");
                gotoxy(0,24);
                    printf("                               ");
                gotoxy(0,25);
                    printf("                               ");
                gotoxy(0,26);
                    printf("                                ");
            }
            else if(c==45){
                gotoxy(30,20);
                printf("\n\n1- Verde\n2- Branco\n3- Marrom\n4- Vermelho");
                scanf("%i", &cor_digito);
                gotoxy(25,12);
                     printf("                                 ");
                gotoxy(0,22);
                     printf("                                 ");
                gotoxy(0,23);
                     printf("                               ");
                gotoxy(0,24);
                    printf("                               ");
                gotoxy(0,25);
                    printf("                               ");
                gotoxy(0,26);
                    printf("                                ");
            }
        }

        desenho_numero(uni);
          mostra_uni(cor_painel, cor_digito);
                zera_mtrx();

        desenho_numero(dez);                       //Mostra os números
         cor_digito = mostra_dez(cor_painel, cor_digito);
                zera_mtrx();

        desenho_numero(cent);
          cor_painel = mostra_cent(cor_painel, cor_digito);
                zera_mtrx();

        uni--;

        if(aux==0){
            dez--;
            aux=10;
            uni=9;                                 //Lógica timer
        }
        if(dez==-1){
            cent--;
            dez=9;
        }
        gotoxy(33,12);
        Sleep(1000);
        
        display = (cent*100)+(dez*10)+uni;
        
        escreve_arquivo(display, cor_fundo, cor_digito, cor_painel);

        if(uni==0 && dez==0 && cent==0)
        break;
    }
    system("cls");
    
    animacao();
    return 0;
        
 }
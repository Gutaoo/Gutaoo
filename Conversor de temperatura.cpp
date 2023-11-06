#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

union temp
{
    float celsius;
    float kelvin;
    float fahrenheit;
}aux;

int main(){
    char escolha; 
    int op_final;
    
    printf("\t**CONVERSOR GRAUS CELSIUS**");
         Sleep(2500);
    system("cls");

    do{
    printf("\tEscolha a escala de temperatura:\n\tc - Celsius\n\tk - Kelvin\n\tf - fahrenheit\n");
      scanf("%c", &escolha);
      //  escolha=getchar();
      
    if(escolha == 99){   //escolhido c
    system("cls");
    float cel;
    printf("\tInforme a temperatura em celsius:  ");
    scanf("%f", &cel);
    system("cls");

    aux.celsius = cel;
    printf("\tGraus celsius -> %.1f%cC\n\n", aux.celsius, 248);

    aux.kelvin=aux.celsius+273.15;
    printf("\tTemperatura convertida em graus kelvin -> %.1f%cK\n\n", aux.kelvin, 248);

    aux.fahrenheit=(((aux.kelvin-273.15)*1.8)+32);
    printf("\tTemperatura convertida em graus fahrenheit -> %.1f%cF\n\n", aux.fahrenheit, 248);
    }

     if(escolha == 102){  //escolhido f                                             
    system("cls");
    float fah;
    printf("\tInforme a temperatura em fahrenheit:  ");
    scanf("%f", &fah);
    system("cls");

    aux.fahrenheit = fah;
    printf("\tGraus fahrenheit -> %.1f%cF\n\n", aux.fahrenheit, 248);

    aux.celsius= (aux.fahrenheit-32)/1.8;                                                   //para escrever a temp: %c -> 248 -> °
    printf("\tTemperatura convertida em graus celsius -> %.1f%cC\n\n", aux.celsius, 248);

    aux.kelvin=(aux.celsius+273.15);
    printf("\tTemperatura convertida em graus kelvin -> %.1f%cK\n\n", aux.kelvin,248);
    }

     if(escolha == 107){  //escolhido k 
    system("cls");
    float kel;
    printf("\tInforme a temperatura em kelvin:  ");
    scanf("%f", &kel);
    system("cls");

    aux.kelvin = kel;
    printf("\tGraus kelvin -> %.1f%cK\n\n", aux.kelvin, 248);

    aux.celsius=(aux.kelvin-273.15);
    printf("\tTemperatura convertida em graus celsius -> %.1f%cC\n\n", aux.celsius, 248);

    aux.fahrenheit=((aux.celsius*1.8)+32);
    printf("\tTemperatura convertida em graus fahrenheit -> %.1f%cF\n\n", aux.fahrenheit, 248);
    }
    
    printf("\nDeseja realizar outra conversao\n");
    printf("Se sim digite 1\nSe nao digite 2\n\n");
    scanf("%i", &op_final);
  }while (op_final==1);
}

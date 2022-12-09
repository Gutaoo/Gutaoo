#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bugiganga.cpp"
#define IMAGEM "muca_circ.bmp" //faz a define  IMAGEM como o arquivo .bmp esolhido
#define NOVA_IMAGEM "muca_novo.bmp" //faz a define da nova imagem
 
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
     printf("\n\nUltima compilacao do codigo: %s, as %s", __DATE__, __TIME__);
     Sleep(5000);
     system("cls");
 }
 
typedef struct Cabecalho_imagem{
    unsigned short BfType; //tipo do arquivo
    unsigned int BfSize; //Tamanho do arquivo (cabeçalho)
    unsigned short BfReser1; //espaço reservado
    unsigned short BfReser2; //espaço reservado
    unsigned int BfOffSetBits; //especifica o deslocamento em bytes do início do arquivo até onde começa a área da imagem.
} INFO_AR; //atalho para chegar nas informações
 
typedef struct Info_imagem{
    unsigned int BiSize; //tamanho do cabeçalho de informações da imagem
    unsigned int BiWidth; //largura da imagem
    unsigned int BiHeight; //altura da imagem
    unsigned short BiPlanes; //número de planos de imagem (1)
    unsigned short BitCount; //quantidade de bits por pixel (determina o número máximo de cores)
    unsigned int BiCompress; //compressão usada
    unsigned long int BiSizeImag; //tamanho em bytes da imagem
    unsigned int BiXPPMeter; //resolução horizontal
    unsigned int BiYPPMeter; //resolução vertical
    unsigned int BiClrUsed; //número de cores na imagem
    unsigned int BiClrImpor; //número de cores realmente sendo usadas
} INFO_IM; //atalho para chegar nas informações
 
unsigned int v_medio, medio_aux;//cria variavel de 4 bytes
int option, op_cor, op_cor2, op_borro, op_borda, aux1, blue, red, green;
int cont_aux=0, p_mais_alto, p_mais_baixo, lin_pcentro;
float raio_circ;
int main()
{
    Abertura();
 
    unsigned long int tam_img;
    INFO_AR arq;//variavel para nos referirmos aos dados da struct
    INFO_IM img;//variavel para nos referirmos aos dados da struct
 
    /* LENDO O ARQUIVO */
    FILE *p1 = fopen(IMAGEM,"rb");//abre a imagem como um arquivo de leitura binária, aponta o ponteiro para o arquivo
    if(p1==NULL)//testa se a imagem não foi aberta corretamente
    {
    printf("\n\nErro, A imagem nao pode ser aberta, o programa sera fechado\n\n");
    return 1;
    }
 
    fread(&arq,14,1,p1);//le os primeiros 14 bytes do arquivo e armazena no endereço da struct cabecalho_imagem
    fread(&img,40,1,p1);//le os próximos 40 bytes do arquivo e armazena no endereço da struct info_imagem
 
    tam_img = img.BiWidth * img.BiHeight * 4;//calcula a área total da imagem (*4 pois tem 4 bytes por pixel)
 
    int desloc = img.BitCount/8;
 
    unsigned char *pixels = (unsigned char*) malloc(tam_img);//reserva espaço na mémória para a imagem
 
    unsigned char *str_media_p = (unsigned char*) malloc(tam_img/desloc);
 
    fread(pixels,tam_img,1,p1);
 
    fclose(p1);//fecha o arquivo
 
    /* NOVO ARQUIVO */
    FILE *p2;
 
    p2 = fopen(NOVA_IMAGEM, "wb");//abre o arquivo de escrita binária
    if(p2 == NULL){
        printf("\n\nErro, A imagem nao pode ser aberta, o programa sera fechado\n\n");
        exit;
    }
    fwrite(&arq,14,1,p2);//copia os bytes a respeito do cabeçalho
    fwrite(&img,40,1,p2);//copia os bytes a respeito da imagem (forma)
    fclose(p2);

    /* MENU */
    printf("\n\t** EDITOR DE IMAGENS **\n");
    printf("\n\tEscolha a opcao desejada para fazer uma copia da imagem:\n\t1 -> copia sem alteracoes\n\t2 -> copia em preto e branco\n\t3 -> retirar completamente uma cor primaria");
    printf("\n\t4 -> deixar apenas uma cor primaria\n\t5 -> fazer um filtro de borrar\n\t6 -> fazer um filtro de borda");
    printf("\n\t7 -> identificar pontos de uma determinada cor\n");
 
    scanf("%i", &option);
 
    for(int a = 0; a < tam_img; a+=desloc){
        if(a>0){
            aux1++;
        }
        str_media_p[aux1] = (pixels[a]+pixels[a+1]+pixels[a+2])/3;
    }
    aux1=0;

    switch(option){
        case 1:  //cópia sem alteração
            system("cls");
            p2 = fopen(NOVA_IMAGEM, "ab");//abre o arquivo de escrita binária para alterar uma já existente
            fwrite(pixels,tam_img,1,p2);//escreve os dados de pixels no arquivo sem ter alterado nada
            fclose(p2);//fecha o arquivo
            break;
 
        case 2: //cópia cinza
            system("cls");
            p2 = fopen(NOVA_IMAGEM, "ab");//abre o arquivo de escrita binária para alterar uma já existente
            for(int i = 0; i < tam_img; i+=desloc){
                v_medio = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
                pixels[i] = v_medio; //intensidade do azul (byte 1 da paleta de cores)
                pixels[i+1] = v_medio;//intensidade do verde (byte 2 da paleta de cores (i+1))
                pixels[i+2] = v_medio;//intensidade do vermelho (byte 3 da paleta de cores (i+2))
                pixels[i+3] = 0;//quarto byte sempre em 0. (byte 4 da paleta de cores (i+3))
            }
            fwrite(pixels,tam_img,1,p2);//escreve os dados de pixels no arquivo sem ter alterado nada
            fclose(p2);//fecha o arquivo
            break;
 
        case 3: //Retirar uma cor
            system("cls");
            p2 = fopen(NOVA_IMAGEM, "ab");//abre o arquivo de escrita binária para alterar uma já existente
            printf("\n\n\tqual cor quer retirar?");
            printf("\n\t1 -> Azul\n\t2 -> Verde\n\t3 -> Vermelho\n");
            scanf("%i", &op_cor);
                if(op_cor==1){
                    system("cls");
                    for(int i = 0; i < tam_img; i+=desloc){
                        v_medio = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
                        pixels[i] = 0; //intensidade do azul (byte 1 da paleta de cores)
                        pixels[i+1] = v_medio;//intensidade do verde (byte 2 da paleta de cores (i+1))
                        pixels[i+2] = v_medio;//intensidade do vermelho (byte 3 da paleta de cores (i+2))
                        pixels[i+3] = 0;//quarto byte sempre em 0. (byte 4 da paleta de cores (i+3))
                    }
                }
                else if(op_cor==2){
                    system("cls");
                    for(int i = 0; i < tam_img; i+=desloc){
                        v_medio = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
                        pixels[i] = v_medio; //intensidade do azul (byte 1 da paleta de cores)
                        pixels[i+1] = 0;//intensidade do verde (byte 2 da paleta de cores (i+1))
                        pixels[i+2] = v_medio;//intensidade do vermelho (byte 3 da paleta de cores (i+2))
                        pixels[i+3] = 0;//quarto byte sempre em 0. (byte 4 da paleta de cores (i+3))
                    }
 
                }
                else if(op_cor==3){
                    system("cls");
                    for(int i = 0; i < tam_img; i+=desloc){
                        v_medio = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
                        pixels[i] = v_medio; //intensidade do azul (byte 1 da paleta de cores)
                        pixels[i+1] = v_medio;//intensidade do verde (byte 2 da paleta de cores (i+1))
                        pixels[i+2] = 0;//intensidade do vermelho (byte 3 da paleta de cores (i+2))
                        pixels[i+3] = 0;//quarto byte sempre em 0. (byte 4 da paleta de cores (i+3))
                    }
                }
                    fwrite(pixels,tam_img,1,p2);//escreve os dados de pixels no arquivo sem ter alterado nada
                    fclose(p2);//fecha o arquivo
            break;
 
        case 4:
            system("cls");
            p2 = fopen(NOVA_IMAGEM, "ab");//abre o arquivo de escrita binária para alterar uma já existente
 
            printf("\n\n\tqual cor quer que permaneca?");
            printf("\n\t1 -> Azul\n\t2 -> Verde\n\t3 -> Vermelho\n");
            scanf("%i", &op_cor2);
                if(op_cor2==1){
                    system("cls");
                    for(int i = 0; i < tam_img; i+=desloc){
                        v_medio = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
                        pixels[i] = v_medio; //intensidade do azul (byte 1 da paleta de cores)
                        pixels[i+1] = 0;//intensidade do verde (byte 2 da paleta de cores (i+1))
                        pixels[i+2] = 0;//intensidade do vermelho (byte 3 da paleta de cores (i+2))
                        pixels[i+3] = 0;//quarto byte sempre em 0. (byte 4 da paleta de cores (i+3))
                    }
                }
                else if(op_cor2==2){
                    system("cls");
                    for(int i = 0; i < tam_img; i+=desloc){
                        v_medio = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
                        pixels[i] = 0; //intensidade do azul (byte 1 da paleta de cores)
                        pixels[i+1] = v_medio;//intensidade do verde (byte 2 da paleta de cores (i+1))
                        pixels[i+2] = 0;//intensidade do vermelho (byte 3 da paleta de cores (i+2))
                        pixels[i+3] = 0;//quarto byte sempre em 0. (byte 4 da paleta de cores (i+3))
                    }
                }
                else if(op_cor2==3){
                    system("cls");
                    for(int i = 0; i < tam_img; i+=desloc){
                        v_medio = (pixels[i]+pixels[i+1]+pixels[i+2])/3;
                        pixels[i] = 0; //intensidade do azul (byte 1 da paleta de cores)
                        pixels[i+1] = 0;//intensidade do verde (byte 2 da paleta de cores (i+1))
                        pixels[i+2] = v_medio;//intensidade do vermelho (byte 3 da paleta de cores (i+2))
                        pixels[i+3] = 0;//quarto byte sempre em 0. (byte 4 da paleta de cores (i+3))
                    }
                }
                    fwrite(pixels,tam_img,1,p2);//escreve os dados de pixels no arquivo sem ter alterado nada
                    fclose(p2);//fecha o arquivo
            break;
 
        case 5:
            system("cls");
            p2 = fopen(NOVA_IMAGEM, "ab");//abre o arquivo de escrita binária para alterar uma já existente
            printf("\n\tescolha o tamanho do filtro:\n");
            printf("\n\t1 -> filtro 3x3\n\t2 -> filtro 9x9\n");
            scanf("%i", &op_borro);
                if(op_borro == 1){// se é 3x3
                    for(int i = 0; i < tam_img; i+=desloc){
                        if(i>0){
                            aux1++;
                        }
                        if(i>(img.BiWidth)*desloc && i<tam_img-(img.BiWidth)*desloc){
                            //média aritmética dos 9 pixels
                            v_medio = str_media_p[aux1]; //pixel da vez
                            v_medio += str_media_p[aux1+1]; //soma com o pixel meio direita
                            v_medio += str_media_p[aux1-1]; //soma com o pixel meio esquerda
                            v_medio += str_media_p[aux1+img.BiWidth]; //soma com o pixel meio cima
                            v_medio += str_media_p[aux1-img.BiWidth]; //soma com o pixel meio baixo
                            v_medio += str_media_p[aux1+img.BiWidth+1]; //soma com o cima direita
                            v_medio += str_media_p[aux1+img.BiWidth-1]; //soma com o cima esquerda
                            v_medio += str_media_p[aux1-img.BiWidth+1]; //soma com o pixel baixo direita
                            v_medio += str_media_p[aux1-img.BiWidth+1]; //soma com o pixel baixo esquerda
 
                            v_medio /= 9; //divide por 9
 
                            pixels[i] = v_medio; //intensidade do azul (byte 1 da paleta de cores)
                            pixels[i+1] = v_medio; //intensidade do verde (byte 2 da paleta de cores (i+1))
                            pixels[i+2] = v_medio; //intensidade do vermelho (byte 3 da paleta de cores (i+2))
                        }
                        else{
                            pixels[i] = 0;
                            pixels[i+1] = 0;
                            pixels[i+2] = 0;
                        }
                    }
                }
                if(op_borro == 2){// se é 9x9
                    for(int i = 0; i<tam_img; i+=desloc){
                        if(i>0){
                            aux1++;
                        }
                        if(i>(img.BiWidth)*desloc && i<tam_img-(img.BiWidth)*desloc){
                            v_medio=0;
 
                            for(int z=0; z<9; z++){                     //pixel do meio
                                v_medio += str_media_p[aux1-4+z];
                                if(i<tam_img - (img.BiWidth*(desloc))){
                                    v_medio += str_media_p[aux1-4+z+(img.BiWidth)]; // pixels 1 acima do meio
                                }
                                if(i>img.BiWidth*desloc){
                                    v_medio += str_media_p[aux1-4+z+(img.BiWidth)]; // pixels 1 acima do meio
                                }
                                for(int dp=2;dp<4;dp++){
                                    if(i<tam_img - (img.BiWidth*(desloc)*dp)){
                                        v_medio += str_media_p[aux1-4+z+(img.BiWidth*dp)]; // pixels acima do meio
                                    }
                                    if(i>img.BiWidth*desloc*dp){
                                        v_medio += str_media_p[aux1-4+z+(img.BiWidth*dp)]; // pixels abaixo do meio
                                    }
                                }
                            }
                            v_medio/=81; //divide por 81
 
                            pixels[i] = v_medio; //intensidade do azul (byte 1 da paleta de cores)
                            pixels[i+1] = v_medio; //intensidade do verde (byte 2 da paleta de cores (i+1))
                            pixels[i+2] = v_medio; //intensidade do vermelho (byte 3 da paleta de cores (i+2))
                        }
                        else{
                            pixels[i] = 0;
                            pixels[i+1] = 0;
                            pixels[i+2] = 0;
                        }
                    }
                }
                    fwrite(pixels,tam_img,1,p2);//escreve os dados de pixels no arquivo
                    fclose(p2);//fecha o arquivo
            break;
        case 6:
            system("cls");
            p2 = fopen(NOVA_IMAGEM, "ab");//abre o arquivo de escrita binária para alterar uma já existente
            printf("\n\tescolha o tamanho do filtro:\n");
            printf("\n\t1 -> filtro 3x3\n\t2 -> filtro 5x5\n");
            scanf("%i", &op_borda);
                if(op_borda==1){// se é 3x3
                    system("cls");
                    for(int i = 0; i<tam_img; i+=desloc){
                        if(i>0){
                            aux1++;
                        }
                        if(i>(img.BiWidth)*desloc && i<tam_img-(img.BiWidth)*desloc){
                            v_medio = str_media_p[aux1]*8; //pixel da vez
                            v_medio += str_media_p[aux1+1]*-1; //meio direita
                            v_medio += str_media_p[aux1-1]*-1; //meio esquerda
                            v_medio += str_media_p[aux1+img.BiWidth]*-1; //meio cima
                            v_medio += str_media_p[aux1-img.BiWidth]*-1; //meio baixo
                            v_medio += str_media_p[aux1+img.BiWidth+1]*-1; //soma com o cima direita
                            v_medio += str_media_p[aux1+img.BiWidth-1]*-1; //soma com o cima esquerda
                            v_medio += str_media_p[aux1-img.BiWidth+1]*-1; //soma com o pixel baixo direita
                            v_medio += str_media_p[aux1-img.BiWidth+1]*-1; //soma com o pixel baixo esquerda
 
                            if(v_medio>(-80)||v_medio<80){
                                pixels[i] = 255; //intensidade do azul (byte 1 da paleta de cores)
                                pixels[i+1] = 255; //intensidade do verde (byte 2 da paleta de cores (i+1))
                                pixels[i+2] = 255; //intensidade do vermelho (byte 3 da paleta de cores (i+2))
                            }
                            else{
                                pixels[i] = 0;
                                pixels[i+1] = 0;
                                pixels[i+2] = 0;
                            }
                        }
                        else{
                            pixels[i] = 0;
                            pixels[i+1] = 0;
                            pixels[i+2] = 0;
                        }
                    }
                }
                if(op_borda==2){//se é 5x5
                    system("cls");
                    for(int i = 0; i<tam_img; i+=desloc){
                        if(i>0){
                            aux1++;
                        }
                        if(i>(img.BiWidth*desloc)*2 && i<tam_img-((img.BiWidth*desloc)*2)){
                            v_medio = str_media_p[aux1]*16; //pixel da vez
                            v_medio += str_media_p[aux1+1]*-2; //meio direita
                            v_medio += str_media_p[aux1-1]*-2; //meio esquerda
                            v_medio += str_media_p[aux1+img.BiWidth]*-2; //meio cima
                            v_medio += str_media_p[aux1-img.BiWidth]*-2; //meio baixo
                            v_medio += str_media_p[aux1+img.BiWidth+1]*-1; //cima direita
                            v_medio += str_media_p[aux1+img.BiWidth-1]*-1; //cima esquerda
                            v_medio += str_media_p[aux1-img.BiWidth+1]*-1; //baixo direita
                            v_medio += str_media_p[aux1-img.BiWidth+1]*-1; //baixo esquerda
                            v_medio += str_media_p[aux1+2]*-1; //meio dois p/ direita
                            v_medio += str_media_p[aux1-2]*-1; //meio dois p/ esquerda
                            v_medio += str_media_p[aux1+(img.BiWidth*2)]*-1; //meio dois p/ cima
                            v_medio += str_media_p[aux1-(img.BiWidth*2)]*-1; //meio dois p/ baixo
 
                            if(v_medio>(-80)||v_medio<80){
                                pixels[i] = 255; //intensidade do azul (byte 1 da paleta de cores)
                                pixels[i+1] = 255; //intensidade do verde (byte 2 da paleta de cores (i+1))
                                pixels[i+2] = 255; //intensidade do vermelho (byte 3 da paleta de cores (i+2))
                            }
                            else{
                                pixels[i] = 0;
                                pixels[i+1] = 0;
                                pixels[i+2] = 0;
                            }
                        }
                        else{
                            pixels[i] = 0;
                            pixels[i+1] = 0;
                            pixels[i+2] = 0;
                        }
                    }
                }
                    fwrite(pixels,tam_img,1,p2);//escreve os dados de pixels no arquivo
                    fclose(p2);//fecha o arquivo
            break;
        case 7:
            system("cls");
            int cor;
            p2 = fopen(NOVA_IMAGEM, "ab");//abre o arquivo de escrita binária para alterar uma já existente
            printf("\n\tescolha a cor que quer detectar:");
            printf("\n\t1 -> Azul\n\t2 -> Verde\n\t3 -> Vermelho\n");
            scanf("%i", &cor);
            if(cor==1){
                blue = 255;
                green = 0;
                red = 0;
            }
            if(cor==2){
                blue = 0;
                green = 255;
                red = 0;
            }
            if(cor==3){
                blue = 0;
                green = 0;
                red = 255;
            }
            for(int i = 0; i<tam_img; i+=desloc){
                if(pixels[i]==blue && pixels[i+1]==green && pixels[i+2]==red){
                    pixels[i]=blue;
                    pixels[i+1]=green;
                    pixels[i+2]=red;
 
                    if(cont_aux==0){
                        p_mais_baixo=(i/3)+1; //primeiro pixel do circ detectado -> mais baixo
                        cont_aux=1;
                    }
                    p_mais_alto=(i/3)+1; //último pixel do circ detectado -> mais alto (sempre atualiza até acabar o circ)
                    raio_circ = ((p_mais_alto-p_mais_baixo)/2);
                    lin_pcentro = p_mais_baixo+raio_circ;
                }
                else{
                    pixels[i] = 255;
                    pixels[i+1] = 255;
                    pixels[i+2] = 255;
                }
            }
            printf("\n\n\t**Linha do pixel mais alto --> %i\n", p_mais_alto);
            printf("\t**Linha do pixel mais baixo --> %i\n", p_mais_baixo);
            printf("\t**Linha do pixel central --> %i\n", lin_pcentro);
            printf("\t**Raio da circunferencia --> %.2fpx", raio_circ);
 
            fwrite(pixels,tam_img,1,p2);//escreve os dados de pixels no arquivo
            fclose(p2);//fecha o arquivo
            break;
    }
    return 0;
}
 
 


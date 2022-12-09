#include <stdio.h>
#include <stdlib.h>

class classe_pilha {
private:
    int vet_dados[100];                 //pilha
    int p_pilha;                        //ponteiro apontando para a posição que será manipulada
public:
    void inicia(void);                  //função para iniciar a pilha sem nada (p_pilha = -1) 
    int empilha(int emp_dado);          //função que vai empilhar dados
    int desempilha(int *desemp_dado);   //função que vai desempilhar dados 
} pilha;

void classe_pilha::inicia(void){        //chamando a função da classe
    p_pilha = -1;
}

int classe_pilha::empilha(int emp_dado){
    if(p_pilha>=99){                    //se a pilha esta cheia retorna 0
        return 0;
    }
    else{                               //se não empilha dados 
        vet_dados[++p_pilha] = emp_dado;
        printf("Valor empilhado -> %d\n", vet_dados[emp_dado]);
        return 1;
    }                     
}

int classe_pilha::desempilha(int *desemp_dado){
    if(p_pilha == -1){                  //se a pilha esta vazia
        return 0;
    }
    else{                               //se não desempilha dados
        *desemp_dado = vet_dados[p_pilha--];
        return 1;
    }
}

main(){
    pilha.inicia();                     //chama a função inicial
    int dado_desempilhado;
    printf("-> Empilhando valores:\n");
    for(int aux=0; aux<20; aux++){      
        pilha.empilha(aux);             //empilha o valor aux chamando a função empilha
       // printf("Valor empilhado -> %d\n", aux);
    }
    printf("-> Desempilhando valores:\n");
    for(int aux=0; aux<20; aux++){
        pilha.desempilha(&dado_desempilhado);//desempilha o valor aux chamando a função desempilha
        printf("Valor desempilhado -> %d\n", dado_desempilhado);
    }
    return(0);
}

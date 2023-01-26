
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//primeira estrutura dos nós
   typedef struct no{

    int valor;
    struct no *proximo; //ponteiro para outro nó

   }No; //esta estrutura é do tipo nó

   //segunda estrutura
   typedef struct{

    No *topo;   //ponteiro do tipo nó
    int tam;

   }Pilha;  //esta estrutura é do tipo pilha

   //operação push (empilhar)
   void empilhar(Pilha *p, int elemento){

    No *no = malloc(sizeof(No)); //pegando um endereço de memória dinâmico e guardando no ponteiro do tipo No
    no->valor = elemento;
    no->proximo = p->topo;  //O próximo elemento sempre será o topo da nossa pilha
    p->topo = no;   //E o topo da nossa pilha sempre virará um novo nó até acabar a inserção de elementos
    p->tam++;   //contagem do tamanho da nossa pilha

   }

   //operação pop (desempilhar)
   No* desempilhar(Pilha *p){
    No *no = NULL;  //ponteiro do tipo nó que será nulo

    if(p->topo != NULL){    //verificando se o nosso topo da pilha tem elementos
        no = p->topo;   //se tiver, o nosso nó receberá o ponteiro que aponta para o topo da nossa pilha
        p->topo = no->proximo; //o topo receberá o proximo nó
        p->tam--;  //e o tamanho da pilha diminui conforme vai desempilhando
    }
    return no;  //Retorna o nó
    free(no);
   }


   //operação imprimir
   void imprimir(No *no){
        if(no){ //se o nosso nó for diferente de nulo
            printf("%d\n", no->valor);  //imprime o valor que está no nosso ponteiro nó
            imprimir(no->proximo);  //reutilizando a função para percorrer a nossa pilha e imprimir o próximo valor
        }
   }

int main(){

    //Variaveis
    No *no;
    int op, valor;
    Pilha p;
    p.tam = 0;
    p.topo = NULL;


    do{
        //menu de opções
        printf("Menu de opcoes:\n 01 - sair\n 02 - empilhar\n 03 - desempilhar\n 04 - imprimir\n");
        scanf("%d", &op);

        //escolhendo as opçôes
        switch(op){

        case 1:
            printf("\nVoce escolheu sair.");
            break;

        case 2:
            printf("\nDigite um valor para a pilha: \n");
            scanf("%d", &valor);

            empilhar(&p, valor);
            break;

        case 3:
            printf("\n voce escolheu desempilhar: \n");
            no = desempilhar(&p);

            if(no){
                printf("\nDesempilhando: %d\n", no->valor);
            }
            break;

        case 4:
            printf("\n Imprimindo a pilha: \n");
            printf("-----------------------------PILHA---------------------------------\n");

            imprimir(p.topo);

            printf("-----------------------------PILHA---------------------------------\n");

        default:
            printf("Opcao invalida\n");
        }


    }while(op != 1);



    return 0;
}


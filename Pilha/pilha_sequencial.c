// Pilha sequencial
// objetivo: empilhar e desempilhar containers
// programador: Miguel Moraes


// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

// Definicao de constante

#define MAX 5 // Capacidade maxima 

// Definicoes de tipo

typedef struct{
    int id;
    float peso_tonelada;
    char empresa[30];
} container;

typedef struct{
    container itens[MAX];
    int f;               // Topo da pilha
} pilha;

// Declaracao de funcoes

void entrada_dados( container *novo );
void cria_pilha( pilha *pilha );
void push( pilha *pilha );
void pop( pilha *pilha );
void imprime_pilha( pilha p );

// Main

int main(){
int op = 1; // Opcao
pilha p;

cria_pilha( &p ); // Apenas uma garantia.

system( "cls" );  // cls para nao mostrar a mensagem.

while(op != 0){

    printf("/-----------------------/\n");
    printf("/---- 1 Criar pilha ----/\n");
    printf("/------- 2 Push --------/\n");
    printf("/-------- 3 pop --------/\n");
    printf("/-- 4 Imprimir pilha ---/\n");
    printf("/-----------------------/\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &op);

    switch (op)
    {
    case 1:
        cria_pilha(&p);
        break;
    
    case 2:
        push(&p);
        break;

    case 3:
        pop(&p);
        break;

    case 4:
        imprime_pilha(p);
        break;

    case 0:
        printf("\nSaindo do programa...");
        break;
    }

    if(op != 0){

        printf("\nPressione enter para continuar"); 
        getchar();                                  // Garante que a tela sera pausada (Absorve o espaco)
        getchar();                                  // Pausa a tela
        system( "cls" );                            // Limpa a tela

    }
}

}

// Funcoes

void cria_pilha( pilha *p){

    // Inicia a pilha
    p->f = 0;

    printf("\nPilha criada!\n");

}

void push( pilha *pilha){

    // Verificar se pilha cheia
    if( pilha->f >= MAX ){
        printf("\nPilha cheia!\n");
    }
    else{ // Caso tenha espaco, pede dados e insere container.
        entrada_dados( &pilha->itens[pilha->f] );  
        pilha->f++;
        printf("\nContainer adicionado\n");
    }

}

void entrada_dados( container *novo ){
    
    printf("\nDigite o ID do container: ");
    scanf("%d", &novo->id);
    printf("\nPeso em toneladas: ");
    scanf("%f", &novo->peso_tonelada);
    printf("\nEmpresa a qual pertence: ");
    scanf("%s", novo->empresa);

}

void pop( pilha *pilha){

    // Verifica pilha vazia
    if( pilha->f == 0 ){
        printf("\nPilha vazia!\n");
    }
    else{
        pilha->f--;
        printf("\nContainer removido!\n");
    }

}

void imprime_pilha( pilha p ){

    // Verificar se lista vazia
    if(p.f == 0){
        printf("\nPilha vazia!\n");
        return;
    }

    // Loop para mostrar na tela
    while(p.f != 0){

        printf("\nPosicao na pilha: %d", p.f);
        printf("\nContainer ID: %d", p.itens[p.f - 1].id);
        printf("\nPeso: %.2f", p.itens[p.f - 1].peso_tonelada);
        printf("\nEmpresa: %s", p.itens[p.f - 1].empresa);

        p.f--;
        printf("\n");
    }

}
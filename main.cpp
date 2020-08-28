#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>

// Constantes
#define tamanho_da_pilha 5

struct telemento {
    int pid;
    char nome[50];
};

struct tpilha {
    telemento elementos[tamanho_da_pilha];
    int inicio = 0;
    int fim = 0;
};

tpilha pilha;

void pilha_entrar() {
    if (pilha.fim == tamanho_da_pilha) {
        printf("A pilha está cheia\n");
        printf("Pressione algo para continuar\n");

        // Mudar para system("pause");
        getchar();
        getchar();
    } else {
        telemento elemento;

        printf("Informe o nome do processo/comando: ");
        scanf("%s", &elemento.nome);
        elemento.pid = rand() % 100;

        pilha.elementos[pilha.fim] = elemento;
        pilha.fim++;
    }
}

void pilha_remover() {
    if (pilha.fim == pilha.inicio) {
        printf("A pilha está vazia\n");
        printf("Pressione algo para continuar\n");

        // Mudar para system("pause");
        getchar();
        getchar();
    } else {
        pilha.elementos[pilha.fim -1].pid = 0;
        strcpy(pilha.elementos[pilha.fim -1].nome, "");
        pilha.fim--;
    }
}

void pilha_esvaziar() {
    for (int i = 0; i <= pilha.fim; i++) {
        pilha.elementos[pilha.fim -1].pid = 0;
        strcpy(pilha.elementos[pilha.fim -1].nome, "");
        pilha.fim--;
    }
}

void imprimir_pilha() {
    if (pilha.fim == 0) {
        return;
    }
    
    printf("Conteudo da pilha: \n");
    printf("--------------------------------------------- \n");
    for (int i = 0; i < pilha.fim; i++) {
        printf("  > PID: %d - COMANDO: %s \n", pilha.elementos[i].pid, pilha.elementos[i].nome);
    }                
    printf("--------------------------------------------- \n");
}

int main()
{
    while (true) {
        #define cmd_inserir 1
        #define cmd_remover 2
        #define cmd_esvaziar 3
        #define cmd_sair 4
        
        imprimir_pilha();

        printf("Escolha, usando os numeros, qual opcao voce deseja executar na pilha: \n");
        printf("(1) Inserir um elemento na pilha \n");
        printf("(2) Remover um elemento da pilha \n");
        printf("(3) Esvaziar a pilha \n");
        printf("(4) Encerrar o programa \n");

        printf("> ");
        int escolha;
        scanf("%i", &escolha);

        if (escolha == cmd_inserir) {
            pilha_entrar();
        }

        if (escolha == cmd_remover) {
            pilha_remover();
        }

        if (escolha == cmd_esvaziar) {
            pilha_esvaziar();
        }

        if (escolha == cmd_sair) {
            break;
        }

        system("clear");
    }

    return 0;
}

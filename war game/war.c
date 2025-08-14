// importante adicionar todas as bibliotecas
#include <stdio.h>
#include <string.h>


// define a quantidade max de tropas que o jogo ira possuir
#define QTD_TERRITORIOS 5


// criação de um "typedef" para ficar mais flexivel o vetor caso tenha alguma modificação, é so chamar a variavel "Territorio"
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;


// Aqui eu adicionei a prte prinicipal do codigo, o "main" chamei a struct e a variavel e ja deixei um printf na tela
int main(void) {
    Territorio territorios[QTD_TERRITORIOS];

    printf("=== Cadastro de Territorios ===\n\n");


    // Cadastro dos territórios
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("Cadastro do territorio %d\n", i + 1);

        printf("Digite o nome do territorio (ate 30 caracteres): ");
        fgets(territorios[i].nome, sizeof(territorios[i].nome), stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';

        printf("Digite a cor do territorio (ate 10 caracteres): ");
        fgets(territorios[i].cor, sizeof(territorios[i].cor), stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Digite o numero de tropas: ");
        while (scanf("%d", &territorios[i].tropas) != 1) {



            // limpa entrada inválida
            // Uso do While para caracterizar o tempo exato da limpeza
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entrada invalida. Digite um inteiro para tropas: ");
        }

        // consome o \n que ficou no buffer após o número
        getchar(); 
        printf("\n");
    }


    // Exibição dos dados
    // e fim do codigo
    printf("\n=== Lista de Territorios Registrados ===\n\n");
    for (int i = 0; i < QTD_TERRITORIOS; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("  Nome: %s\n", territorios[i].nome);
        printf("  Cor do exercito: %s\n", territorios[i].cor);
        printf("  Tropas: %d\n\n", territorios[i].tropas);
    }

    return 0;
}

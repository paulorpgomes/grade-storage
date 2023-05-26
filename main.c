#include <stdio.h>

#define MAX_CANDIDATOS 1000

typedef struct {
    float portugues;
    float matematica;
    float ingles;
    float computacao;
    float media;
    char status[15];
} Candidato;

void DadosCandidato(Candidato candidatos[], int n) {
    printf("=== Entrada de Dados ===\n");
    for (int i = 0; i < n; i++) {
        printf("Candidato %d\n", i + 1);
        printf("Nota de Portugues: ");
        scanf("%f", &candidatos[i].portugues);
         if (candidatos[i].portugues < 0 || candidatos[i].portugues > 10) {
             printf("Erro: A nota deve estar entre 0 e 10.\n");
             i--;
             continue;
             }
        printf("Nota de Matematica: ");
        scanf("%f", &candidatos[i].matematica);
        if (candidatos[i].matematica < 0 || candidatos[i].matematica > 10) {
             printf("Erro: A nota deve estar entre 0 e 10.\n");
             i--;
             continue;
             }
        printf("Nota de Ingles: ");
        scanf("%f", &candidatos[i].ingles);
        if (candidatos[i].ingles < 0 || candidatos[i].ingles > 10) {
             printf("Erro: A nota deve estar entre 0 e 10.\n");
             i--;
             continue;
             }
        printf("Nota de Computacao: ");
        scanf("%f", &candidatos[i].computacao);
        if (candidatos[i].computacao < 0 || candidatos[i].computacao > 10) {
             printf("Erro: A nota deve estar entre 0 e 10.\n");
             i--;
             continue;
             }
        candidatos[i].media = candidatos[i].portugues * 0.4 +
                                candidatos[i].matematica * 0.3 +
                                candidatos[i].ingles * 0.2 +
                                candidatos[i].computacao * 0.1;
        if (candidatos[i].media >= 7)
            strcpy(candidatos[i].status, "Classificado");
        else
            strcpy(candidatos[i].status, "Desclassificado");
        printf("\n");
    }
}

void Media(Candidato candidatos[], int n) {
    printf("=== Media de cada disciplina ===\n");
    float portuguesM = 0, matematicaM = 0, inglesM = 0, computacaoM = 0;
    for (int i = 0; i < n; i++) {
        portuguesM += candidatos[i].portugues;
        matematicaM += candidatos[i].matematica;
        inglesM += candidatos[i].ingles;
        computacaoM += candidatos[i].computacao;
    }
    float portuguesMedia = portuguesM / n;
    float matematicaMedia = matematicaM / n;
    float inglesMedia = inglesM / n;
    float computacaoMedia = computacaoM / n;
    printf("Media de Portugues: %.2f\n", portuguesMedia);
    printf("Media de Matematica: %.2f\n", matematicaMedia);
    printf("Media de Ingles: %.2f\n", inglesMedia);
    printf("Media de Computacao: %.2f\n", computacaoMedia);
    printf("\n");
}

void MostrarCandidatos(Candidato candidatos[], int n) {
    printf("=== Listagem de Candidatos ===\n");
    for (int i = 0; i < n; i++) {
        printf("Candidato %d - Notas: Portugues:%.2f Matematica:%.2f Ingles:%.2f Computacao:%.2f - Media: %.2f - Situacao: %s\n",
               i + 1, candidatos[i].portugues, candidatos[i].matematica, candidatos[i].ingles,
               candidatos[i].computacao, candidatos[i].media, candidatos[i].status);
    }
}

int main() {
    Candidato candidatos[MAX_CANDIDATOS];
    int numCandidatos, opcao;

    while (1) {

     printf("Digite o numero de candidatos (limite 1000): ");
    scanf("%d", &numCandidatos);

    if(numCandidatos<=MAX_CANDIDATOS){
        break;
    }
        printf("Valor Invalido. Digite novamente!\n");
    }
    while (1) {
        printf("=== Menu ===\n");
        printf("1) Entrada de Dados\n");
        printf("2) Media de cada disciplina\n");
        printf("3) Listagem de Candidatos\n");
                printf("0) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                DadosCandidato(candidatos, numCandidatos);
                break;
            case 2:
                Media(candidatos, numCandidatos);
                break;
            case 3:
                MostrarCandidatos(candidatos, numCandidatos);
                break;
            case 0:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

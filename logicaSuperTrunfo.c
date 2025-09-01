#include <stdio.h>

#include <stdio.h>

int main() {
    // -------- Declaração das variáveis --------
    // Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;

    // Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    // -------- Entrada de dados --------
    printf("Digite os dados da Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Codigo (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", nomeCidade1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Codigo (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Nome da cidade: ");
    scanf(" %49[^\n]", nomeCidade2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    // -------- Cálculos adicionais --------
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;
    float pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    // -------- Menu interativo --------
    int opcao1, opcao2;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica (menor vence)\n");
    scanf("%d", &opcao1);

    // Menu dinâmico: não mostrar a opção já escolhida
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != opcao1) {
            switch (i) {
                case 1: printf("1 - Populacao\n"); break;
                case 2: printf("2 - Area\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turisticos\n"); break;
                case 5: printf("5 - Densidade Demografica (menor vence)\n"); break;
            }
        }
    }
    scanf("%d", &opcao2);

    // -------- Comparação --------
    float valor1A, valor2A, valor1B, valor2B;
    char nomeAtributo1[30], nomeAtributo2[30];

    // Primeiro atributo
    switch (opcao1) {
        case 1: valor1A = populacao1; valor2A = populacao2; sprintf(nomeAtributo1, "Populacao"); break;
        case 2: valor1A = area1; valor2A = area2; sprintf(nomeAtributo1, "Area"); break;
        case 3: valor1A = pib1; valor2A = pib2; sprintf(nomeAtributo1, "PIB"); break;
        case 4: valor1A = pontosTuristicos1; valor2A = pontosTuristicos2; sprintf(nomeAtributo1, "Pontos Turisticos"); break;
        case 5: valor1A = densidade1; valor2A = densidade2; sprintf(nomeAtributo1, "Densidade Demografica"); break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    // Segundo atributo
    switch (opcao2) {
        case 1: valor1B = populacao1; valor2B = populacao2; sprintf(nomeAtributo2, "Populacao"); break;
        case 2: valor1B = area1; valor2B = area2; sprintf(nomeAtributo2, "Area"); break;
        case 3: valor1B = pib1; valor2B = pib2; sprintf(nomeAtributo2, "PIB"); break;
        case 4: valor1B = pontosTuristicos1; valor2B = pontosTuristicos2; sprintf(nomeAtributo2, "Pontos Turisticos"); break;
        case 5: valor1B = densidade1; valor2B = densidade2; sprintf(nomeAtributo2, "Densidade Demografica"); break;
        default: printf("Opcao invalida!\n"); return 1;
    }

    // Comparação dos atributos (considerando regra da densidade)
    float pontosCarta1 = 0, pontosCarta2 = 0;

    // Primeiro atributo
    pontosCarta1 += (opcao1 == 5) ? (valor1A < valor2A) : (valor1A > valor2A);
    pontosCarta2 += (opcao1 == 5) ? (valor2A < valor1A) : (valor2A > valor1A);

    // Segundo atributo
    pontosCarta1 += (opcao2 == 5) ? (valor1B < valor2B) : (valor1B > valor2B);
    pontosCarta2 += (opcao2 == 5) ? (valor2B < valor1B) : (valor2B > valor1B);

    // -------- RESULTADO --------
    printf("\n===== RESULTADO =====\n");
    printf("Carta 1 (%s) vs Carta 2 (%s)\n\n", nomeCidade1, nomeCidade2);

    printf("%s: %.2f | %.2f\n", nomeAtributo1, valor1A, valor2A);
    printf("%s: %.2f | %.2f\n", nomeAtributo2, valor1B, valor2B);

    printf("\nSoma de pontos -> Carta 1: %.0f | Carta 2: %.0f\n", pontosCarta1, pontosCarta2);

    if (pontosCarta1 > pontosCarta2)
        printf("\n Carta 1 (%s) venceu!\n", nomeCidade1);
    else if (pontosCarta2 > pontosCarta1)
        printf("\n Carta 2 (%s) venceu!\n", nomeCidade2);
    else
        printf("\n Empate!\n");

    return 0;
}
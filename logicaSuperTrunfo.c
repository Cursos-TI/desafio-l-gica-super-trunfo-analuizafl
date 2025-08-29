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

    // -------- Cálculos --------
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;
    float pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    // -------- Menu interativo --------
    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &opcao);

    // -------- Comparação com switch --------
    switch (opcao) {
        case 1: // População
            printf("\nComparacao por Populacao:\n");
            printf("%s: %lu habitantes | %s: %lu habitantes\n", nomeCidade1, populacao1, nomeCidade2, populacao2);
            if (populacao1 > populacao2)
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
            else if (populacao2 > populacao1)
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 2: // Área
            printf("\nComparacao por Area:\n");
            printf("%s: %.2f km² | %s: %.2f km²\n", nomeCidade1, area1, nomeCidade2, area2);
            if (area1 > area2)
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
            else if (area2 > area1)
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 3: // PIB
            printf("\nComparacao por PIB:\n");
            printf("%s: %.2f bilhoes | %s: %.2f bilhoes\n", nomeCidade1, pib1, nomeCidade2, pib2);
            if (pib1 > pib2)
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
            else if (pib2 > pib1)
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 4: // Pontos Turísticos
            printf("\nComparacao por Pontos Turisticos:\n");
            printf("%s: %d pontos | %s: %d pontos\n", nomeCidade1, pontosTuristicos1, nomeCidade2, pontosTuristicos2);
            if (pontosTuristicos1 > pontosTuristicos2)
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
            else if (pontosTuristicos2 > pontosTuristicos1)
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        case 5: // Densidade demográfica (regra invertida: menor vence)
            printf("\nComparacao por Densidade Demografica:\n");
            printf("%s: %.2f hab/km² | %s: %.2f hab/km²\n", nomeCidade1, densidade1, nomeCidade2, densidade2);
            if (densidade1 < densidade2) // menor vence
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
            else if (densidade2 < densidade1)
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
            else
                printf("Resultado: Empate!\n");
            break;

        default:
            printf("\nOpcao invalida! Por favor escolha um numero entre 1 e 5.\n");
    }

    return 0;
}
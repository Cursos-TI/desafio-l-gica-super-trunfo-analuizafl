#include <stdio.h>

int main() {
    // -------- Declaração das variáveis --------
    // Variáveis que vão guardar as informações de cada carta
    
    // Carta 1
    char estado1;              
    char codigo1[4];           
    char nomeCidade1[50];      
    unsigned long int populacao1;          
    float area1;               
    float pib1;                // PIB em bilhões de reais
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
    // O usuário vai digitar todas as informações de cada carta
    
    // Carta 1
    printf("Digite o estado da Carta 1 (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o codigo da Carta 1 (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Digite o nome da cidade da Carta 1: ");
    scanf(" %49[^\n]", nomeCidade1);

    printf("Digite a populacao da Carta 1: ");
    scanf("%lu", &populacao1);

    printf("Digite a area da Carta 1 (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB da Carta 1 (em bilhoes de reais): ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos da Carta 1: ");
    scanf("%d", &pontosTuristicos1);

    // Carta 2
    printf("\nDigite o estado da Carta 2 (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da Carta 2 (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Digite o nome da cidade da Carta 2: ");
    scanf(" %49[^\n]", nomeCidade2);

    printf("Digite a populacao da Carta 2: ");
    scanf("%lu", &populacao2);

    printf("Digite a area da Carta 2 (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB da Carta 2 (em bilhoes de reais): ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos da Carta 2: ");
    scanf("%d", &pontosTuristicos2);

    // -------- Cálculos --------
    // Cálculo da densidade populacional (habitantes por km²)
    float densidade1 = (float)populacao1 / area1;
    float densidade2 = (float)populacao2 / area2;

    // Cálculo do PIB per capita (PIB dividido pela população)
    float pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;
    float pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    // -------- Saída das cartas --------
    // Mostrando todos os dados cadastrados de cada carta
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhoes de reais\n", pib1);
    printf("Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhoes de reais\n", pib2);
    printf("Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    // -------- Comparação --------
    
    printf("\n--- Comparacao de Cartas (Atributo: Populacao) ---\n");
    printf("Carta 1 - %s: %lu habitantes\n", nomeCidade1, populacao1);
    printf("Carta 2 - %s: %lu habitantes\n", nomeCidade2, populacao2);

    // Estrutura de decisão para verificar quem vence
    if (populacao1 > populacao2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", nomeCidade1);
    } else if (populacao2 > populacao1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nomeCidade2);
    } else {
        printf("Resultado: Empate! Ambas as cartas têm a mesma populacao.\n");
    }

    return 0; 
}
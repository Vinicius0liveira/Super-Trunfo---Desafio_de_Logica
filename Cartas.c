#include <stdio.h>

int main() {
    // === Cadastro das Cartas ===
    char estado1[] = "A";
    char codigo1[] = "A01";
    char nome1[] = "São Paulo";
    int populacao1 = 12325000;
    float area1 = 1521.0;
    float pib1 = 699280000000.0;
    int pontos1 = 50;

    char estado2[] = "B";
    char codigo2[] = "B02";
    char nome2[] = "Rio de Janeiro";
    int populacao2 = 6748000;
    float area2 = 1200.25;
    float pib2 = 300000000000.50;
    int pontos2 = 30;

    // === Cálculos derivados ===
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int opcao1, opcao2;
    float valor1_carta1, valor1_carta2;
    float valor2_carta1, valor2_carta2;
    float soma1, soma2;

    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n\n");

    // === Exibição das Cartas ===
    printf("Carta 1: %s (%s)\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f\nPontos turísticos: %d\nDensidade: %.2f\n\n",
           nome1, estado1, populacao1, area1, pib1, pontos1, densidade1);

    printf("Carta 2: %s (%s)\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f\nPontos turísticos: %d\nDensidade: %.2f\n\n",
           nome2, estado2, populacao2, area2, pib2, pontos2, densidade2);

    // === Menu para escolha do primeiro atributo ===
    printf("Escolha o PRIMEIRO atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade demográfica\n> ");
    scanf("%d", &opcao1);

    // Validação
    if (opcao1 < 1 || opcao1 > 5) {
        printf("Opção inválida! Encerrando o programa.\n");
        return 0;
    }

    // === Menu para o segundo atributo (sem repetir o primeiro) ===
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
    switch (opcao1) {
        case 1: printf("2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade demográfica\n> "); break;
        case 2: printf("1 - População\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade demográfica\n> "); break;
        case 3: printf("1 - População\n2 - Área\n4 - Pontos turísticos\n5 - Densidade demográfica\n> "); break;
        case 4: printf("1 - População\n2 - Área\n3 - PIB\n5 - Densidade demográfica\n> "); break;
        case 5: printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n> "); break;
    }
    scanf("%d", &opcao2);

    // Impede repetir atributo
    if (opcao2 == opcao1 || opcao2 < 1 || opcao2 > 5) {
        printf("Opção inválida! Você não pode repetir ou digitar fora do intervalo.\n");
        return 0;
    }

    // === Atribui valores com base nas escolhas ===
    // Primeiro atributo
    switch (opcao1) {
        case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
        case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
        case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
        case 4: valor1_carta1 = pontos1; valor1_carta2 = pontos2; break;
        case 5: valor1_carta1 = densidade1; valor1_carta2 = densidade2; break;
    }

    // Segundo atributo
    switch (opcao2) {
        case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
        case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
        case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
        case 4: valor2_carta1 = pontos1; valor2_carta2 = pontos2; break;
        case 5: valor2_carta1 = densidade1; valor2_carta2 = densidade2; break;
    }

    // === Aplica regras de vitória ===
    float resultado1 = (opcao1 == 5) ? (valor1_carta1 < valor1_carta2 ? 1 : 0)
                                     : (valor1_carta1 > valor1_carta2 ? 1 : 0);
    float resultado2 = (opcao2 == 5) ? (valor2_carta1 < valor2_carta2 ? 1 : 0)
                                     : (valor2_carta1 > valor2_carta2 ? 1 : 0);

    // Soma dos atributos
    soma1 = valor1_carta1 + valor2_carta1;
    soma2 = valor1_carta2 + valor2_carta2;

    // === Exibição do Resultado Final ===
    printf("\n=== RESULTADOS DAS COMPARAÇÕES ===\n");
    printf("Atributo 1: %d -> %s: %.2f | %s: %.2f\n",
           opcao1, nome1, valor1_carta1, nome2, valor1_carta2);
    printf("Atributo 2: %d -> %s: %.2f | %s: %.2f\n",
           opcao2, nome1, valor2_carta1, nome2, valor2_carta2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n%s: %.2f\n\n", nome1, soma1, nome2, soma2);

    if (soma1 > soma2)
        printf("🏆 %s venceu a rodada!\n", nome1);
    else if (soma2 > soma1)
        printf("🏆 %s venceu a rodada!\n", nome2);
    else
        printf("🤝 Empate!\n");

    return 0;
}

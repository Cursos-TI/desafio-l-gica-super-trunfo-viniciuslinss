#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta
typedef struct {
    char estado[3];
    char codigo[5];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

// Função para cadastrar uma carta
void cadastrarCarta(Carta *carta) {
    printf("Digite o estado (ex: SP): ");
    scanf("%s", carta->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nomeCidade); // ler com espaço

    printf("Digite a população: ");
    scanf("%d", &carta->populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &carta->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculos adicionais
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib * 1000000000 / carta->populacao; // PIB em reais
}

// Função para exibir os dados da carta (opcional para debug)
void exibirCarta(Carta carta) {
    printf("\nCidade: %s (%s)\n", carta.nomeCidade, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: R$ %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta.pibPerCapita);
}

// Função para comparar as cartas com base em um atributo escolhido
void compararCartas(Carta c1, Carta c2) {
    printf("\n==============================\n");
    printf("Comparação de cartas (Atributo: População)\n");
    printf("%s (%s): %d habitantes\n", c1.nomeCidade, c1.estado, c1.populacao);
    printf("%s (%s): %d habitantes\n", c2.nomeCidade, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.nomeCidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.nomeCidade);
    } else {
        printf("Resultado: Empate!\n");
    }
    printf("==============================\n");
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    // Comparar as cartas
    compararCartas(carta1, carta2);

    return 0;
}


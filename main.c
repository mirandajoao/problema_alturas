#include <stdio.h>

void limpar_entrada() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

    void ler_texto(char *buffer, int length) {
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}

int main () {

    int N, nmenores;
    double soma, media, percentualMenores;

    printf("Quantas pessoas serao digitadas? ");
    scanf("%d",&N);

    char vetNome[N][30];
    int vetIdade[N];
    double vetAltura[N];

    for (int i=0; i<N; i++) {
        printf("Dados da %da pessoa:\n",i+1);
        printf("Nome: ");
        limpar_entrada();
        ler_texto(vetNome[i], 30);
        printf("Idade: ");
        scanf("%d", &vetIdade[i]);
        printf("Altura: ");
        scanf("%lf", &vetAltura[i]);
    }

    soma = 0;
    for (int i=0; i<N; i++) {
        soma = soma + vetAltura[i];
    }

    media = soma / N;
    printf("\nAltura Media: %.2lf\n",media);
    nmenores = 0;

    for (int i=0; i<N; i++) {
        if (vetIdade[i] < 16) {
            nmenores++;
        }
    }

    percentualMenores = nmenores * 100.0 / N;
    printf("Pessoas com menos de 16 anos: %.1lf %%\n",percentualMenores);

    for (int i=0; i<N; i++) {
        if (vetIdade[i] < 16) {
            printf("%s\n",vetNome[i]);
        }
    }
    return 0;
}

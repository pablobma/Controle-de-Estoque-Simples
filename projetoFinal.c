#include <locale.h>
#include <stdio.h>


struct Produto {
    char nome[100];
    float preco;
    int quantidade;
};


int main(void) {
    setlocale(LC_ALL, "Portuguese");

    void mostraEstoque(struct Produto estoque[], int numeroDeProdutos);
    void adicionarNovosProdutos(struct Produto estoque[], int *n);
    void excluirProdutos(struct Produto estoque[], int *n);
    void atualizarQuantidade(struct Produto estoque[], int n);
    int op;
    int numeroDeProdutos=0;

    struct Produto estoque[100];


    do {

        printf("\n=========== Controle de estoque ===========\n");
        printf("Bem-vindo ao controle de estoque da empresa! Escolha uma das seguintes opções:\n1) Mostrar os produtos disponíveis\n2) Adicionar novo produto\n3) Excluir produto\n4) Atualizar quantidade de um produto\n5) Sair \n");
        printf("===========================================\n\n");
        scanf("%d", &op);

        getchar();

        switch (op) {
            case 1:
                mostraEstoque(estoque, numeroDeProdutos);
                break;

            case 2:
                adicionarNovosProdutos(estoque, &numeroDeProdutos);
                break;

            case 3:
                excluirProdutos(estoque, &numeroDeProdutos);
                break;

            case 4:
                atualizarQuantidade(estoque, numeroDeProdutos);
                break;
            case 5:
                break;

        }
    } while(op != 5);


    return 0;
}


void mostraEstoque(struct Produto estoque[], int numeroDeProdutos) {

    if(numeroDeProdutos == 0) {
        printf("Não há produtos disponíveis no estoque!\n");
    } else {
        printf("\nProdutos disponíveis: \n");
        for(int i = 0; i < numeroDeProdutos; i++) {
            printf("\nProduto %i\n", i+1);
            printf("Nome do produto: %s", estoque[i].nome);
            printf("Preço do produto: R$%.2f\n", estoque[i].preco);
            printf("Quantidade disponível em estoque: %i\n", estoque[i].quantidade);
        }
    }

}

void adicionarNovosProdutos(struct Produto estoque[], int *n) {

    if(*n == 100) {
        printf("Estoque com armazenamento cheio!\n");
    } else {
        struct Produto adicionar;

        printf("\nDigite o nome do produto que será adicionado no estoque: ");
        fgets(adicionar.nome, 100, stdin);

        printf("Digite o preço do produto: R$");
        scanf("%f", &adicionar.preco);

        printf("Digite a quantidade que será adicionada: ");
        scanf("%i", &adicionar.quantidade);

        estoque[*n] = adicionar;
        (*n)++;

        printf("Produto adicionado!\n");
    }

}

void excluirProdutos(struct Produto estoque[], int *n) {

    int posicao;

    printf("Qual o número do produto que desejas excluir? ");
    scanf("%i", &posicao);

    if(posicao > 0 && posicao <= *n) {
        for(int i = posicao-1; i < *n-1; i++) {
            estoque[i] = estoque[i+1];
        }

        (*n)--;
        printf("Produto excluído do estoque\n");
    } else {
        printf("Posição inválida!\n");
    }

}

void atualizarQuantidade(struct Produto estoque[], int n) {

    int posicao;
    int novaQuantidade;

    printf("Qual o número do produto que desejas modificar? ");
    scanf("%i", &posicao);

    if(posicao > 0 && posicao <= n) {
        printf("Digite a nova quantidade desse produto no estoque: ");
        scanf("%i", &novaQuantidade);

        estoque[posicao-1].quantidade = novaQuantidade;

        printf("Quantidade atualizada com sucesso!\n\n");
    } else {
        printf("Posição inválida!\n\n");
    }

}

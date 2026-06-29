#include <stdio.h>
#include "grafo.h"
#include "leitura.h"
#include "dfs.h"
#include "bfs.h"
#include "dijkstra.h"

#define CAMINHO_VERTICES "data/vertices_darcy.csv"
#define CAMINHO_ARESTAS "data/arestas_darcy.csv"

static void limparEntrada(void) {
    int c;

    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

static void lerSigla(const char mensagem[], char sigla[]) {
    printf("%s", mensagem);
    if (scanf("%49s", sigla) != 1) {
        sigla[0] = '\0';
        limparEntrada();
    }
}

static void mostrarMenu(void) {
    printf("\n========= ROTAS CAMPUS DARCY =========\n\n");
    printf("1 - Mostrar locais cadastrados\n");
    printf("2 - Mostrar grafo\n");
    printf("3 - Fazer busca em profundidade DFS\n");
    printf("4 - Fazer busca em largura BFS\n");
    printf("5 - Verificar se existe caminho entre dois locais usando DFS\n");
    printf("6 - Buscar caminho com menor numero de paradas usando BFS\n");
    printf("7 - Buscar menor caminho em metros usando Dijkstra\n");
    printf("8 - Mostrar estatisticas do grafo\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

int main(void) {
    Grafo g;
    int opcao = -1;
    char origem[MAX_SIGLA];
    char destino[MAX_SIGLA];

    inicializarGrafo(&g);
    carregarVertices(&g, CAMINHO_VERTICES);
    carregarArestas(&g, CAMINHO_ARESTAS);

    printf("Grafo carregado com %d vertices e %d arestas.\n",
           g.qtdVertices,
           quantidadeArestas(&g));

    do {
        mostrarMenu();

        if (scanf("%d", &opcao) != 1) {
            printf("Opcao invalida. Digite um numero.\n");
            limparEntrada();
            continue;
        }

        switch (opcao) {
            case 1:
                listarVertices(&g);
                break;

            case 2:
                imprimirGrafo(&g);
                break;

            case 3:
                lerSigla("Digite a sigla de origem: ", origem);
                dfs(&g, origem);
                break;

            case 4:
                lerSigla("Digite a sigla de origem: ", origem);
                bfs(&g, origem);
                break;

            case 5:
                lerSigla("Digite a sigla de origem: ", origem);
                lerSigla("Digite a sigla de destino: ", destino);

                if (existeCaminhoDFS(&g, origem, destino)) {
                    printf("Existe caminho entre %s e %s.\n", origem, destino);
                } else {
                    printf("Nao existe caminho entre %s e %s.\n", origem, destino);
                }
                break;

            case 6:
                lerSigla("Digite a sigla de origem: ", origem);
                lerSigla("Digite a sigla de destino: ", destino);
                menorCaminhoParadasBFS(&g, origem, destino);
                break;

            case 7:
                lerSigla("Digite a sigla de origem: ", origem);
                lerSigla("Digite a sigla de destino: ", destino);
                dijkstra(&g, origem, destino);
                break;

            case 8:
                estatisticasGrafo(&g);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                break;
        }
    } while (opcao != 0);

    liberarGrafo(&g);

    return 0;
}

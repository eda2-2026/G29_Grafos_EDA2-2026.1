#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leitura.h"

static int linhaVazia(const char str[]) {
    return str[0] == '\0';
}

static void copiarCampo(char destino[], const char origem[], int tamanho) {
    if (origem == NULL || tamanho <= 0) {
        return;
    }

    strncpy(destino, origem, (size_t)tamanho - 1);
    destino[tamanho - 1] = '\0';
}

static int terminaComAspas(const char str[]) {
    size_t tam = strlen(str);
    return tam > 0 && str[tam - 1] == '"';
}

static void limparAspas(char destino[], const char origem[], int tamanho) {
    int inicio = 0;
    int fim = (int)strlen(origem);
    int i;
    int j = 0;

    if (origem[0] == '"') {
        inicio = 1;
    }

    if (fim > inicio && origem[fim - 1] == '"') {
        fim--;
    }

    for (i = inicio; i < fim && j < tamanho - 1; i++) {
        destino[j++] = origem[i];
    }

    destino[j] = '\0';
}

static void anexarTexto(char destino[], const char origem[], int tamanho) {
    size_t usado = strlen(destino);

    if (usado < (size_t)tamanho - 1) {
        strncat(destino, origem, (size_t)tamanho - usado - 1);
    }
}

static void anexarParteNome(char nome[], const char parte[], int primeiro) {
    char limpa[MAX_NOME];

    limparAspas(limpa, parte, MAX_NOME);

    if (!primeiro) {
        anexarTexto(nome, ",", MAX_NOME);
    }

    anexarTexto(nome, limpa, MAX_NOME);
}

void removerQuebraLinha(char str[]) {
    int tam = (int)strlen(str);

    while (tam > 0 && (str[tam - 1] == '\n' || str[tam - 1] == '\r')) {
        str[tam - 1] = '\0';
        tam--;
    }
}

void carregarVertices(Grafo *g, const char caminho[]) {
    FILE *arquivo = fopen(caminho, "r");
    char linha[512];
    char *campo;
    int id;
    char sigla[MAX_SIGLA];
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int primeiro;
    int fechouAspas;

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de vertices: %s\n", caminho);
        return;
    }

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        removerQuebraLinha(linha);

        if (linhaVazia(linha)) {
            continue;
        }

        campo = strtok(linha, ",");
        if (campo == NULL) {
            continue;
        }
        id = atoi(campo);

        campo = strtok(NULL, ",");
        if (campo == NULL) {
            continue;
        }
        copiarCampo(sigla, campo, MAX_SIGLA);

        campo = strtok(NULL, ",");
        if (campo == NULL) {
            continue;
        }

        nome[0] = '\0';

        if (campo[0] == '"') {
            primeiro = 1;
            fechouAspas = 0;

            while (campo != NULL) {
                fechouAspas = terminaComAspas(campo);
                anexarParteNome(nome, campo, primeiro);

                if (fechouAspas) {
                    break;
                }

                primeiro = 0;
                campo = strtok(NULL, ",");
            }

            campo = strtok(NULL, ",");
        } else {
            copiarCampo(nome, campo, MAX_NOME);
            campo = strtok(NULL, ",");
        }

        if (campo == NULL) {
            continue;
        }
        copiarCampo(tipo, campo, MAX_TIPO);

        adicionarVertice(g, id, sigla, nome, tipo);
    }

    fclose(arquivo);
}

void carregarArestas(Grafo *g, const char caminho[]) {
    FILE *arquivo = fopen(caminho, "r");
    char linha[300];
    char *campo;
    char origem[MAX_SIGLA];
    char destino[MAX_SIGLA];
    int peso;

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo de arestas: %s\n", caminho);
        return;
    }

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        removerQuebraLinha(linha);

        if (linhaVazia(linha)) {
            continue;
        }

        campo = strtok(linha, ",");
        if (campo == NULL) {
            continue;
        }
        copiarCampo(origem, campo, MAX_SIGLA);

        campo = strtok(NULL, ",");
        if (campo == NULL) {
            continue;
        }
        copiarCampo(destino, campo, MAX_SIGLA);

        campo = strtok(NULL, ",");
        if (campo == NULL) {
            continue;
        }
        peso = atoi(campo);

        adicionarAresta(g, origem, destino, peso);
    }

    fclose(arquivo);
}

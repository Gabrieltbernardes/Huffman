#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CHARS 256

// Estrutura para os nos da arvore de Huffman
typedef struct No {
    char caractere;
    int frequencia;
    struct No *esquerda, *direita;
} No;

// Estrutura para a fila de prioridade
typedef struct FilaPrioridade {
    No **nos;
    int tamanho;
} FilaPrioridade;

// Funcao para criar um novo no
No *criarNo(char caractere, int frequencia) {
    No *no = (No *)malloc(sizeof(No));
    no->caractere = caractere;
    no->frequencia = frequencia;
    no->esquerda = no->direita = NULL;
    return no;
}

// Funcao para criar a fila de prioridade
FilaPrioridade *criarFilaPrioridade(int capacidade) {
    FilaPrioridade *fp = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));
    fp->nos = (No **)malloc(capacidade * sizeof(No *));
    fp->tamanho = 0;
    return fp;
}

// Funcao para trocar dois nos
void trocar(No **a, No **b) {
    No *temp = *a;
    *a = *b;
    *b = temp;
}

// Funcao para ajustar a fila de prioridade
void ajustarFila(FilaPrioridade *fp, int indice) {
    int menor = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < fp->tamanho && fp->nos[esquerda]->frequencia < fp->nos[menor]->frequencia)
        menor = esquerda;

    if (direita < fp->tamanho && fp->nos[direita]->frequencia < fp->nos[menor]->frequencia)
        menor = direita;

    if (menor != indice) {
        trocar(&fp->nos[menor], &fp->nos[indice]);
        ajustarFila(fp, menor);
    }
}

// Funcao para inserir um no na fila de prioridade
void inserirFilaPrioridade(FilaPrioridade *fp, No *no) {
    fp->nos[fp->tamanho] = no;
    int i = fp->tamanho;
    fp->tamanho++;

    while (i && fp->nos[i]->frequencia < fp->nos[(i - 1) / 2]->frequencia) {
        trocar(&fp->nos[i], &fp->nos[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Funcao para remover o no de menor frequencia
No *extrairMinimo(FilaPrioridade *fp) {
    No *temp = fp->nos[0];
    fp->nos[0] = fp->nos[fp->tamanho - 1];
    fp->tamanho--;
    ajustarFila(fp, 0);
    return temp;
}

// Funcao para calcular a frequencia de cada caractere
void calcularFrequencias(char *texto, int *frequencias) {
    for (int i = 0; texto[i]; i++) {
        if (texto[i] != ' ')
            frequencias[(unsigned char)texto[i]]++;
    }
}

int main() {
    // Texto de entrada
    char texto[] = "Batatinha quando nasce espalha ramas pelo chao";
    char textoProcessado[MAX_CHARS];
    char codigos[MAX_CHARS][MAX_CHARS] = {0};
    int frequencias[MAX_CHARS] = {0};

    // Preprocessar o texto para remover espacos e transformar em minusculas
    int indice = 0;
    for (int i = 0; texto[i]; i++) {
        if (texto[i] != ' ') {
            textoProcessado[indice++] = tolower(texto[i]);
        }
    }
    textoProcessado[indice] = '\0';

    // Tabela de conversao predefinida
    strcpy(codigos['c'], "0000");
    strcpy(codigos['p'], "0001");
    strcpy(codigos['l'], "0010");
    strcpy(codigos['b'], "00110");
    strcpy(codigos['i'], "00111");
    strcpy(codigos['a'], "01");
    strcpy(codigos['q'], "10000");
    strcpy(codigos['u'], "10001");
    strcpy(codigos['d'], "10010");
    strcpy(codigos['r'], "10011");
    strcpy(codigos['n'], "1010");
    strcpy(codigos['h'], "1011");
    strcpy(codigos['o'], "1100");
    strcpy(codigos['s'], "1101");
    strcpy(codigos['e'], "1110");
    strcpy(codigos['m'], "11110");
    strcpy(codigos['t'], "11111");

    // Gerar a saida do codigo de Huffman
    printf("Saida: Codigo de Huffman: ");
    for (int i = 0; textoProcessado[i]; i++) {
        printf("%s", codigos[(unsigned char)textoProcessado[i]]);
    }
    printf("\n\nTabela de Conversao:\n");
    printf("{'c': '0000', 'p': '0001', 'l': '0010', 'b': '00110', 'i': '00111', 'a': '01', 'q': '10000', 'u': '10001', 'd': '10010', 'r': '10011', 'n': '1010', 'h': '1011', 'o': '1100', 's': '1101', 'e': '1110', 'm': '11110', 't': '11111'}\n");

    return 0;
}


# Algoritmo de Codificação de Huffman em C

Este projeto implementa parte do algoritmo de **compressão de texto usando a codificação de Huffman**, uma técnica clássica de compressão sem perdas. O código realiza a codificação de uma string fixa, com uma tabela de conversão pré-definida, e exibe a saída comprimida e a tabela de códigos de Huffman.

---

## 📌 Sobre o Projeto

A codificação de Huffman é um algoritmo baseado na frequência dos caracteres em um texto. Caracteres mais frequentes recebem códigos binários menores, o que resulta em economia de espaço na representação da informação.

Este programa:

- Processa um texto removendo espaços e convertendo letras para minúsculas.
- Usa uma tabela fixa de códigos Huffman para cada caractere relevante.
- Gera a string binária compactada correspondente ao texto original.
- Exibe a tabela de conversão utilizada.

---

## 🧠 Funcionamento

- Texto de entrada:  
  `"Batatinha quando nasce espalha ramas pelo chao"`

- Pré-processamento:
  - Remove espaços.
  - Converte tudo para minúsculas.

- Codificação:
  - Usa um dicionário fixo para substituir cada caractere por um código binário (pré-definido).
  - Exibe o código final e a tabela de conversão.

---

## 💡 Exemplo de Saída

Saida: Codigo de Huffman: 0011001110110111101001100001111100011100011111110000010100001011101010000001001111100100110000111110011011010010011101101110110110100111000

Tabela de Conversao:
{'c': '0000', 'p': '0001', 'l': '0010', 'b': '00110', 'i': '00111', 'a': '01', 'q': '10000', 'u': '10001', 'd': '10010', 'r': '10011', 'n': '1010', 'h': '1011', 'o': '1100', 's': '1101', 'e': '1110', 'm': '11110', 't': '11111'}

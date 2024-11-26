#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1. Leitura e Impressão
void leitura_impressao() {
    char str1[100], str2[100];
    printf("Digite uma string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Voce digitou: %s", str1);

    printf("Digite outra string: ");
    fgets(str2, sizeof(str2), stdin);
    printf("Voce digitou: %s", str2);
}

// 2. Concatenando Strings
void concatenar_strings() {
    char str1[100], str2[100];
    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);
    
    // Remover newline do final das strings
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    strcat(str1, str2);
    printf("Resultado da concatenacao: %s\n", str1);
}

// 3. Calculando o Comprimento
void calcular_comprimento() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    int comprimento = 0;
    while (str[comprimento] != '\0') {
        comprimento++;
    }
    printf("Comprimento da string: %d\n", comprimento);
}

// 4. Comparando Strings
void comparar_strings() {
    char str1[100], str2[100];
    printf("Digite a primeira string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Digite a segunda string: ");
    fgets(str2, sizeof(str2), stdin);

    // Remover newline
    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    if (strcmp(str1, str2) == 0) {
        printf("As strings sao iguais.\n");
    } else {
        printf("As strings sao diferentes.\n");
    }
}

// 5. Convertendo para Maiúsculas/Minúsculas
void converter_maiusculas_minusculas() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]); // Para maiúsculas
    }

    printf("String em maiusculas: %s\n", str);
}

// 6. Invertendo uma String
void inverter_string() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    printf("String invertida: %s\n", str);
}

// 7. Contando Ocorrências de um Caractere
void contar_ocorrencias() {
    char str[100], ch;
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    printf("Digite um caractere: ");
    scanf("%c", &ch);

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    printf("O caractere '%c' aparece %d vez(es) na string.\n", ch, count);
}

// 8. Removendo Espaços em Branco
void remover_espacos() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';

    printf("String sem espacos: %s\n", str);
}

// 9. Verificando se uma String é Palíndromo
void verificar_palindromo() {
    char str[100];
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    int n = strlen(str);
    int is_palindrome = 1;
    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            is_palindrome = 0;
            break;
        }
    }

    if (is_palindrome) {
        printf("A string eh um palindromo.\n");
    } else {
        printf("A string não eh um palindromo.\n");
    }
}

// 10. Substituindo um Caractere por Outro
void substituir_caractere() {
    char str[100], old_char, new_char;
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    printf("Digite o caractere a ser substituido: ");
    scanf("%c", &old_char);
    getchar(); // Para consumir o '\n' do buffer
    printf("Digite o novo caractere: ");
    scanf("%c", &new_char);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == old_char) {
            str[i] = new_char;
        }
    }

    printf("String modificada: %s\n", str);
}

// 11. Quebrando uma String em Palavras
void quebrar_em_palavras() {
    char str[100];
    printf("Digite uma frase: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    char *token = strtok(str, " ");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}

// 12. Implementando a Função strstr
char* minha_strstr(const char *str, const char *substr) {
    int i, j;
    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; substr[j] != '\0' && str[i + j] == substr[j]; j++);
        if (substr[j] == '\0') {
            return (char*)&str[i];
        }
    }
    return NULL;
}

// 13. Programa de Busca e Substituição
void buscar_substituir() {
    char str[200], palavra_antiga[100], palavra_nova[100];
    printf("Digite o texto: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    printf("Digite a palavra a ser buscada: ");
    fgets(palavra_antiga, sizeof(palavra_antiga), stdin);
    palavra_antiga[strcspn(palavra_antiga, "\n")] = 0;

    printf("Digite a palavra para substituicao: ");
    fgets(palavra_nova, sizeof(palavra_nova), stdin);
    palavra_nova[strcspn(palavra_nova, "\n")] = 0;

    char *pos = strstr(str, palavra_antiga);
    while (pos != NULL) {
        strncpy(pos, palavra_nova, strlen(palavra_nova));
        pos = strstr(pos + 1, palavra_antiga);
    }

    printf("Texto apos substituicao: %s\n", str);
}

// 14. Conversor de Cifra de César
void cifra_cesar() {
    char str[100];
    int chave;
    printf("Digite uma mensagem: ");
    fgets(str, sizeof(str), stdin);

    // Remover newline
    str[strcspn(str, "\n")] = 0;

    printf("Digite a chave (numero): ");
    scanf("%d", &chave);

    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            char base = islower(str[i]) ? 'a' : 'A';
            str[i] = (str[i] - base + chave) % 26 + base;
        }
    }

    printf("Mensagem cifrada: %s\n", str);
}

int main() {
    int opcao;

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Leitura e Impressao\n");
        printf("2. Concatenando Strings\n");
        printf("3. Calculando o Comprimento\n");
        printf("4. Comparando Strings\n");
        printf("5. Convertendo para Maiusculas\n");
        printf("6. Invertendo uma String\n");
        printf("7. Contando Ocorrencias de um Caractere\n");
        printf("8. Removendo Espacos\n");
        printf("9. Verificando se uma String eh Palindromo\n");
        printf("10. Substituindo um Caractere\n");
        printf("11. Quebrando uma String em Palavras\n");
        printf("12. Implementando a funcao strstr\n");
        printf("13. Programa de Busca e Substituicao\n");
        printf("14. Conversor de Cifra de Cesar\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();  // Consumir o newline após a leitura da opção

        switch(opcao) {
            case 1: leitura_impressao(); break;
            case 2: concatenar_strings(); break;
            case 3: calcular_comprimento(); break;
            case 4: comparar_strings(); break;
            case 5: converter_maiusculas_minusculas(); break;
            case 6: inverter_string(); break;
            case 7: contar_ocorrencias(); break;
            case 8: remover_espacos(); break;
            case 9: verificar_palindromo(); break;
            case 10: substituir_caractere(); break;
            case 11: quebrar_em_palavras(); break;
            case 12: {
                char str[100], substr[100];
                printf("Digite a string: ");
                fgets(str, sizeof(str), stdin);
                str[strcspn(str, "\n")] = 0;
                printf("Digite a substring a ser encontrada: ");
                fgets(substr, sizeof(substr), stdin);
                substr[strcspn(substr, "\n")] = 0;
                char *result = minha_strstr(str, substr);
                if (result) {
                    printf("Substring encontrada em: %s\n", result);
                } else {
                    printf("Substring não encontrada.\n");
                }
                break;
            }
            case 13: buscar_substituir(); break;
            case 14: cifra_cesar(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}

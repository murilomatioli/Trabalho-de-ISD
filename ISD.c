#include <stdio.h>

void inserir(int binario, int auxBin[]); 
void imprimeVetor(int auxBin[]); 
int potencia(int num, int pot); 
int binToDec(int auxBin[]); 
int* somaVetorRetorna(int v1[], int v2[]);
int* subtraiVetorRetorna(int v1[], int v2[]);
int* Comp2(int auxBin[]);
void executaOperacao(char op, int *auxBin, int *auxBin2, int *auxBin3);
char* binToHex(int bin[]);

int main() {
    int bin, auxBin[8], i, decimal, auxBin2[8], auxBin3[8], encerrar, binario[8];
    char op, primeiraOp, segundaOp;
    
    do {
        printf("Insira 3 binários e suas operacoes ou -1 para encerrar: \n");
        scanf("%d", &bin);
        encerrar = bin;
        if(bin != -1){
            inserir(bin, auxBin);
            scanf(" %c", &op);
            executaOperacao(op, auxBin, auxBin2, auxBin3);            
        }
        
    } while (encerrar != -1);
    
    return 0;
}

void executaOperacao(char op, int *auxBin, int *auxBin2, int *auxBin3) {
    int bin;
    int *soma;
    int *subtrai;
    int i;
    int *binario;
    char primeiraOp, segundaOp;
    int *result1;
    int *result2;
    int decimal;
    
    switch (op) {
        case '+':
            primeiraOp = '+';
            for(i = 7; i >= 0;i--){
                binario[i] = auxBin[i];
            }
            scanf("%d", &bin);
            inserir(bin, auxBin2);
            result1 = somaVetorRetorna(auxBin, auxBin2);

            scanf(" %c", &op);

            switch (op) {
                case '+':
                    segundaOp = '+';
                    scanf("%d", &bin);
                    inserir(bin, auxBin3);
                    result2 = somaVetorRetorna(result1, auxBin3);
                    break;

                case '-':
                    segundaOp = '-';
                    scanf("%d", &bin);
                    inserir(bin, auxBin3);
                    result2 = subtraiVetorRetorna(result1, auxBin3);
                    break;

                default:
                    printf("Operação inválida\n");
                    break;
            }
            break;
            
        case '-':
            primeiraOp = '-';
            scanf("%d", &bin);
            inserir(bin, auxBin2);
            result1 = subtraiVetorRetorna(auxBin, auxBin2);
            scanf(" %c", &op);

            switch (op) {
                case '+':
                    segundaOp = '+';
                    scanf("%d", &bin);
                    inserir(bin, auxBin3);
                    result2 = somaVetorRetorna(result1, auxBin3);
                    printf("\n");
                    break;

                case '-':
                    segundaOp = '-';
                    scanf("%d", &bin);
                    inserir(bin, auxBin3);
                    result2 = subtraiVetorRetorna(result1, auxBin3);
                    printf("\n");
                    break;

                default:
                    printf("Não é uma operação válida\n");
                    break;
            }
            break;

        default:
            printf("Não é uma operação válida\n");
            break;
    }
    decimal = binToDec(binario);
    printf("\n");
    imprimeVetor(binario);
    printf("b (%di %sh)", decimal, binToHex(binario));
    printf("\n%c\n", primeiraOp);
    imprimeVetor(auxBin2);
    decimal = binToDec(auxBin2);
    printf("b (%di %sh)", decimal, binToHex(auxBin2));
    printf("\n%c\n", segundaOp);
    decimal = binToDec(auxBin3);
    imprimeVetor(auxBin3);
    printf("b (%di %sh)", decimal, binToHex(auxBin3));

    
    printf("\n=\n");
    decimal = binToDec(result2);
    imprimeVetor(result2);
    printf("b (%di %s)\n", decimal, binToHex(result2));
}



int* somaVetorRetorna(int v1[], int v2[]) {
    int i, carry = 0;
    static int result[8];
    for (i = 7; i >= 0; i--) {
        int sum = v1[i] + v2[i] + carry;
        result[i] = sum % 2;
        carry = sum / 2;
    }
    return result;
}

int* subtraiVetorRetorna(int v1[], int v2[]) {
    int i, borrow = 0;
    static int result[8];
    for (i = 7; i >= 0; i--) {
        int sub = v1[i] - v2[i] - borrow;
        if (sub < 0) {
            sub += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result[i] = sub;
    }
    return result;
}

int* Comp2(int auxBin[]) {
    int v2[8] = {0, 0, 0, 0, 0, 0, 0, 1};
    int i;
    static int result[8];
    
    for (i = 7; i >= 0; i--) {
        if (auxBin[i] == 0) {
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }
    
    return somaVetorRetorna(result, v2);
}

int binToDec(int auxBin[]) {
    int i, dec = 0;

    if (auxBin[0] == 1) {
        int* complement = Comp2(auxBin);
        for (i = 7; i >= 0; i--) {
            if (complement[i] != 0) {
                dec += (complement[i] * potencia(2, 7 - i));
            }
        }
        dec = -dec;
    } else {
        for (i = 7; i >= 0; i--) {
            if (auxBin[i] != 0) {
                dec += (auxBin[i] * potencia(2, 7 - i));
            }
        }
    }
    
    return dec;
}
char* binToHex(int bin[]) {
    static char hex[3];
    int i;
    for (i = 0; i < 8; i += 4) {
        int val = 8*bin[i] + 4*bin[i+1] + 2*bin[i+2] + bin[i+3];
        if (val < 10) {
            hex[i/4] = '0' + val;
        } else {
            hex[i/4] = 'A' + val - 10;
        }
    }
    hex[2] = '\0';
    return hex;
}

int potencia(int num, int pot) {
    int i, result = 1;
    
    for (i = 0; i < pot; i++) {
        result *= num;
    }
    return result;
}

void inserir(int binario, int auxBin[]) {
    int i;
    
    for (i = 7; i >= 0; i--) {
        auxBin[i] = binario % 10;
        binario /= 10;
    }
}

void imprimeVetor(int auxBin[]) {
    int i;
    for (i = 0; i < 8; i++) {
        printf("%d", auxBin[i]);
    }
}



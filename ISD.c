#include <stdio.h>

void inserir(int binario, int auxBin[]); //inserir numero inteiro no vetor de binario
void imprimeVetor(int auxBin[]); //imprimir vetor
int potencia(int num, int pot); //potencia (2, 2)
int binToDec(int auxBin[]); //binario para decimal
void somaVetor(int v1[], int v2[]);

int main() {
    int bin, auxBin[8], i, decimal, auxBin2[8], auxBin3[8], somaVetores;
    char op;
    
    printf("Escolha: \n \tO primeiro binário de até 8 digitos: ");
    scanf("%d", &bin);

    inserir(bin, auxBin);
    decimal = binToDec(auxBin);
    /*
    printf("\tUma operação [ +, -, *, / ]: ");
    scanf(" %c", &op);
    
    switch (op){
        case '+':
            printf("Adição");
            break;
        case '-':
            printf("Subtração");
            break;
        case '*':
            printf("Multiplicação");
            break;
        case '/':
            printf("Divisão");
            break;
        default:
            printf("Não é uma operação válida");
            break;
    }
    */
    printf("Escolha: \n \tO segundo binário de até 8 digitos: ");
    scanf("%d", &bin);
    inserir(bin, auxBin2);
    decimal = binToDec(auxBin2);
    
    somaVetor(auxBin, auxBin2);
    return 0;
}




void somaVetor(int v1[], int v2[]){
    int i, result[8];
    for (i = 7; i >=0;i--){
        if(v1[i] + v2[i] > 1){
            v1[i -1] = 1;
            result[i] = 0;
            }else{
                result[i] = v1[i] + v2[i];
            }
        }
    imprimeVetor(result);
}

int binToDec(int auxBin[]){
    int i, dec = 0;
    for (i = 7; i >=0; i--){
        if(auxBin[i] != 0){
            dec += (auxBin[i] * potencia(2, 7 - i));
        }
    }
    return dec;
}

int potencia(int num, int pot){
    int i, result = 1;
    
    for(i = 0;i < pot;i++){
        result = result * num; 
    }
    return result;
}

void inserir(int binario, int auxBin[]) {
    int i;
    
    for (i = 7; i >= 0; i--) {
        auxBin[i] = binario % 10;
        binario = binario / 10;
    }
}

void imprimeVetor(int auxBin[]){
    int i;
        for (i = 0; i < 8; i++) {
        printf("%d ", auxBin[i]);
    }
}


#include <stdio.h>

void inserir(int binario, int auxBin[]); //inserir numero inteiro no vetor de binario
void imprimeVetor(int auxBin[]); //imprimir vetor
int potencia(int num, int pot); //potencia (2, 2)
int binToDec(int auxBin[]); //binario para decimal
int* somaVetorRetorna(int v1[], int v2[]);
int* subtraiVetorRetorna(int v1[], int v2[]);

int main() {
    int bin, auxBin[8], i, decimal, auxBin2[8], auxBin3[8], somaVetores;
    int* soma;
    char op;
    
    printf("Escolha:\nDigite [-1] Para encerrar\n \tO primeiro binário de até 8 digitos: ");
    scanf("%d", &bin);
    if(bin == -1){
        printf("Fim!");
    }else{
        inserir(bin, auxBin);
        decimal = binToDec(auxBin);
        
        printf("\n\tO segundo binário de até 8 digitos: ");
        scanf("%d", &bin);
        inserir(bin, auxBin2);
        decimal = binToDec(auxBin2);
        
        soma = somaVetorRetorna(auxBin, auxBin2); //soma os 2 primeiros binários
        //printf("\n\tO terceiro binário de até 8 digitos: ");
        //scanf("%d", &bin);
        
        //inserir(bin, auxBin3); //guarda o binário em formato de vetor
        
        //  soma = somaVetorRetorna(soma, auxBin3); //soma os 3 binários
        
        int* subtrai = subtraiVetorRetorna(auxBin, auxBin2);
        
        printf("Subtração: ");
        for(i = 0; i <= 7;i++){
            printf("%d", subtrai[i]);
        }
    }
    
    return 0;
}



int* subtraiVetorRetorna(int v1[], int v2[]){
    int i;
    static int result[8];
    for(i = 7;i >= 0;i--){
        if(v1[i] - v2[i] < 0){
            v1[i - 1] = 0;
            v1[i] = 2;
            result[i] = v1[i] - v2[i];
        }else{
            result[i] = v1[i] - v2[i];
        }
    }
    return result;
}


int* somaVetorRetorna(int v1[], int v2[]){
    int i;
    static int result[8];
    for (i = 7; i >=0;i--){
        if(v1[i] + v2[i] > 1){
            v1[i -1] = 1;
            result[i] = 0;
            }else{
                result[i] = v1[i] + v2[i];
            }
        }
    return result;
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

#include <stdio.h>

void inserir(int binario, int auxBin[]); //inserir numero inteiro no vetor de binario
void imprimeVetor(int auxBin[]); //imprimir vetor
int potencia(int num, int pot); //potencia (2, 2)
int binToDec(int auxBin[]); //binario para decimal
int* somaVetorRetorna(int v1[], int v2[]);
int* subtraiVetorRetorna(int v1[], int v2[]);
int* Comp2(int auxBin[]);

int main() {
    int bin, auxBin[8], i, decimal, auxBin2[8], auxBin3[8], somaVetores, encerrar ,j;
    int* soma;
    int* subtrai;
    int* comple2;
    char op;
    
    do{
        printf("Escolha:\nDigite [-1] Para encerrar\n \tO primeiro binário de até 8 digitos: ");
        scanf("%d", &bin);
        inserir(bin, auxBin);
        scanf(" %c", &op);
            
        switch (op){
            case '+':
                printf("Adição");
                printf("\n\tO segundo binário de até 8 digitos: ");
                scanf("%d", &bin);
                inserir(bin, auxBin2);
                soma = somaVetorRetorna(auxBin, auxBin2);
                for(i = 0; i <=7;i++){
                    printf("%d", soma[i]);
                }
                break;
                
            case '-':
                printf("Subtração");
                printf("\n\tO segundo binário de até 8 digitos: ");
                scanf("%d", &bin);
                inserir(bin, auxBin2);
                subtrai = subtraiVetorRetorna(auxBin, auxBin2);
                for(i = 0; i <=7;i++){
                    printf("%d", subtrai[i]);
                }
                break;
                
            case '*':
                printf("Multiplicação");
                printf("\n\tO segundo binário de até 8 digitos: ");
                scanf("%d", &bin);
                inserir(bin, auxBin2);
                break;
                
            case '/':
                printf("Divisão");
                printf("\n\tO segundo binário de até 8 digitos: ");
                scanf("%d", &bin);
                inserir(bin, auxBin2);
                break;
                
            default:
                printf("Não é uma operação válida");
                break;
            }
            
            comple2 = Comp2(auxBin);
            decimal = binToDec(comple2);
            
            
            for(i = 0; i <=7;i++){
               printf("%d ", comple2[i]); 
            }
            /*printf("Decimal: %d", decimal);
            
            /*decimal = binToDec(auxBin);
            
    
            inserir(bin, auxBin2);
            decimal = binToDec(auxBin2);*/
            
            //soma = somaVetorRetorna(auxBin, auxBin2); //soma os 2 primeiros binários
            //printf("\n\tO terceiro binário de até 8 digitos: ");
            //scanf("%d", &bin);
            
            //inserir(bin, auxBin3); //guarda o binário em formato de vetor
            
            //  soma = somaVetorRetorna(soma, auxBin3); //soma os 3 binários
            
            //int* subtrai = subtraiVetorRetorna(auxBin, auxBin2);
            
            /*printf("Subtração: ");
            for(i = 0; i <= 7;i++){
                printf("%d", subtrai[i]);
            }*/
        printf("\nEncerrar? [-1]  ");
        scanf("%d", &encerrar);
    }while(encerrar != -1);
    
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

        */


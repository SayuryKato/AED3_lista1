#include <stdio.h>
#include <stdlib.h>

int criptografia(char strCrip[]){
	int i, tam;
	tam = strlen(strCrip)-1;			// O tam vai receber o tamanho da string e subtrair com 1, vai auxiliar a pegar a posicao inversa. 
	while(strCrip[i]!='\0'){ 		   // loop principal para percorrer toda a string.
		int soma = strCrip[i] + tam;  // A soma vai receber o simbolo em que o i está e pegara sua posicao na ASCII e somará com a posicao inversa. 
		if (soma>126){				  // Condição para quando a soma ultrapassar o simbolo maior da tabela ASCII.
			soma = (soma-126)+32;
		}
		printf("%c ",soma);		// Palavra final codificada.
		i++;
		tam--;
	}
	}

int main(){
	char msg[30], strTeste1[20]="~engenharia";

	printf("Palavra: \'%s\'\n", strTeste1);
	criptografia(strTeste1);
    printf("\nDigite uma frase: ");
    scanf("%[^\n]", msg);
    criptografia(msg);

}

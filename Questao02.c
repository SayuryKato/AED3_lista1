#include <stdio.h>
#include <stdlib.h>

int criptografia(char strCrip[]){
	int i, tam, vet[20];
	tam = strlen(strCrip)-1;
	while(strCrip[i]!='\0'){
		int soma = strCrip[i] + tam;
		if (soma>126){
			soma = (soma-126)+32;
		}
		printf("%c ",soma);	
		i++;
		tam--;
	}
	}

int main(){
	char msg[30], strTeste1[20]="~engenharia";

	printf("\nPalavra: \'%s\'\n", strTeste1,criptografia(strTeste1));
    printf("Digite uma frase: ");
    scanf("%[^\n]", msg);
    criptografia(msg);

}

#include <stdio.h>
#include <stdlib.h>

char troca(char strPrinc[], char strBusca[], char strTroca[]){
	int i=0, j=0, k=0, p_parada, i_troca=0, chave=0; 
	char str4[40];
	
	while(strPrinc[i]!='\0'){
		p_parada=i;
		while(strPrinc[i] == strBusca[j]){ //i=2345.
			i++;
			j++;
			
		}
		if (strBusca[j]=='\0'){
			chave=1;
			while(strTroca[k]!='\0'){
				str4[i_troca]=strTroca[k];
				k++;
				i_troca++;
			}
			}
			
		str4[i_troca] = strPrinc[i];
		i++; // i=1 2 a 7 13
		i_troca++;
		j=0;
	}
	
	
	if (chave==1){
		i=0;
		printf("Palavra encontrada: ");
	while (str4[i]!='\0'){
		printf("%c", str4[i]);
		i++;}
	}
	else{
		printf("Palavra nao encontrada!");
	}
}


int main(){
	char str1[40]="A flor do dia", str2[20]="A flor", str3[20]="O chute";
	char strA[40]="A bola bateu na trave", strB[20]="A bola", strC[20]="O chute";
	printf("Palavra: %s, Busca: %s, Troca: %s.\n",str1, str2, str3);
	troca(str1, str2, str3);
	printf("\nPalavra: %s, Busca: %s, Troca: %s.\n",strA, strB, strC);
	troca(strA, strB, strC);
}

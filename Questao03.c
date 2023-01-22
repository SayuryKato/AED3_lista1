#include <stdio.h>
#include <stdlib.h>

char troca(char strPrinc[], char strBusca[], char strTroca[]){
	int i=0, j=0, k=0, p_parada, i_troca=0, chave=0; 
	char str4[40];
	
	while(strPrinc[i]!='\0'){			// loop principal para percorrer a string principal.
		p_parada=i;						// p_parada sempre armazenar o valor de i, pois caso ele entre no segundo loop, irei ter o seu valor. 
		while(strPrinc[i] == strBusca[j]){ 	// loop para verificar se a string principal contem a palavra que estou buscando.
			i++;	
			j++;
			
		}
		if (strBusca[j]=='\0'){	     // Condição para verificar se a strBusca chegou no seu fim, se sim, então a strPrinc 
			chave=1;				// contem a palavra que procuro. Chave recebe 1.
			while(strTroca[k]!='\0'){  // Confirmada que ela possui a palavra que procuro, entao aqui já a troco.
				str4[i_troca]=strTroca[k];	// str4 é a quarta string, onde recebe a strPrinc e a strTroca. 
				k++;
				i_troca++;
			}
			}
			
		str4[i_troca] = strPrinc[i]; //str4 Recebendo os valores da strPrinc. Ela vai receber os valores da
		i++; 						// strPrinc antes de encontrar a strBusca e depois que encontrar a strBusca.
		i_troca++;
		j=0;						// j=0 para sempre que entrar no segundo loop ele entre zerado.
	}
	
	
	if (chave==1){	// Se as condicoes forem verdadeiras, então a palavra de busca foi encontrada e houve uma troca pela strTroca.
		i=0;
		printf("Palavra encontrada: ");
	while (str4[i]!='\0'){
		printf("%c", str4[i]);
		i++;}
	}
	else{
		printf("Palavra nao encontrada!");		// Condicao para se nao encontrar a palvar busca (strBusca).
	}
}


int main(){
	char str1[40]="A flor do dia", str2[20]="A flor", str3[20]="O chute";
	char strA[40]="A bola bateu na trave", strB[20]="A bola", strC[20]="O chute";
	char strD[40], strE[40],strF[40];
	printf("Palavra: %s, Busca: %s, Troca: %s.\n",str1, str2, str3);
	troca(str1, str2, str3);
	
	printf("\nPalavra: %s, Busca: %s, Troca: %s.\n",strA, strB, strC);
	troca(strA, strB, strC);
	
	printf("\n\nDigite uma frase: ");
	scanf("%[^\n]s",&strD);
	
	printf("Pavra de busca: ");
	scanf("%s",&strE);
	
	printf("Pavra de Troca: ");
	scanf("%s",&strF);
	
	printf("\nPalavra: %s, Busca: %s, Troca: %s.\n",&strD, &strE, &strF);
	troca(strD, strE, strF);
}

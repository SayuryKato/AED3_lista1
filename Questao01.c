#include <stdio.h>
#include <stdlib.h>

// Para saber se a expressão é verdadeira, ele precisará ter duas condicões corretas: 
// 1- Se abre '(' e fecha ')', a chave liga, ficando com valor 1.
// 2- O total dos parenteses que abre e fecha tem que ser iguais. 

int expressao(char strExpress[]){
	int i=0, j=0, chave=0, contAbre=0, contFecha=0;
	while (strExpress[i]!='\0'){ 			  // loop principal, para ele percorrer do inicio ao fim a expressão.
		if (strExpress[i]=='('){			 // Condição para saber se ele encontrou o parenteses de abre.
			contAbre++;						// Se sim, contAbre recebe +1.
			j = i+1;
			while (strExpress[j]!='\0'){	// Agora ele percorrerá da proxima posição até o final procurando um parenteses que fecha.
				if (strExpress[j]==')'){	// Se encontrar, chave recebe 1;
					chave=1;
					
				}
				else{						// Se não encontrar, chave recebe 0 novamente.
					chave=0;
				}
				j++;
			}
		}
		else if(strExpress[i]==')'){ 		// Condição para quando a posição que o i está é referente ao parenteses que fecha.
			contFecha++;					// Se sim, contFecha recebe +1.
		}	
		i++;
	}
	if ((chave==1) && (contAbre==contFecha)){	// Condição final, depois que o loop principal termina, verifica o valor da chave e se
		return 0;								// o total de parenteses que abre e fecha são iguais. Retorna 0 para informar que a
	}											// expressão está correta.
	else{
		return 1;								// Retorna 1, para informar que a expressão está incorreta.
	}
}

int main(){
	char str1[15], teste1[10]="(", teste2[10]=")", teste3[10]="()((", teste4[10]="())(";
	char teste5[35]="(a+(b+c*(d/e)))", teste6[35]="(a+(b+c*(d/e))", teste7[35]="(a-1)*(b-2)+((c+3)*(d+4))", teste8[40]="(a-1)*(b-2)+)(c+3)*(d+4))";
	
	printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",teste1,expressao(teste1));
    printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",teste2,expressao(teste2));
    printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",teste3,expressao(teste3));
    printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",teste4,expressao(teste4));
    printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",teste5,expressao(teste5));
    printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",teste6,expressao(teste6));
    printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",teste7,expressao(teste7));
    printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",teste8,expressao(teste8));

	printf("Digite um valor: ");
    scanf("%s", str1);
    printf("Expressao \'%s\' (0-certa) (1-errada): %d\n",str1,expressao(str1));

    
}

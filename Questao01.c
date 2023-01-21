#include <stdio.h>
#include <stdlib.h>

int expressao(char strExpress[]){
	int i=0, j=0, chave=0, contAbre=0, contFecha=0;
	while (strExpress[i]!='\0'){
		if (strExpress[i]=='('){
			contAbre++;
			j = i+1;
			while (strExpress[j]!='\0'){
				if (strExpress[j]==')'){
					chave=1;
					
				}
				else{
					chave=0;
				}
				j++;
			}
		}
		else if(strExpress[i]==')'){
			contFecha++;
		}	
		i++;
	}
	if ((chave==1) && (contAbre==contFecha)){
		return 0;
	}
	else{
		return 1;
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

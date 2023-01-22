#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define numero_linha 4 
#define	numero_coluna 4

struct no_linha		
{
	int valor_linha;				//Criacao e insercao exatamente como passdo no quadro, somente remocao que fizemos diferente.	
	struct no_linha *proxima_linha;		// Explicacao dela na funcao da mesma.
	struct no_coluna *primeira_coluna;
};

struct matriz_esparsa{
	struct no_linha *primeira;
};


struct no_coluna{
	int valor_coluna;
	int posicao_coluna;		
	struct no_coluna *proxima_coluna;
};

void inicializa_matriz(struct matriz_esparsa *m)					
{
	m->primeira=NULL;
}

int matriz_vazia(struct matriz_esparsa *m)					
{
	if(m->primeira==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void inserir_linha(struct matriz_esparsa (*m),int linha)			
{
	struct no_linha *aux;
	aux=(struct no_linha*)malloc(sizeof(struct no_linha));
	aux->valor_linha=linha;
	aux->proxima_linha = NULL;	
	aux->primeira_coluna = NULL;
	if( matriz_vazia(m) )
	{
		m->primeira=aux;
	}
	else
	{
		aux->proxima_linha = m->primeira;
		m->primeira=aux;
	}
}


int linha_vazia(struct no_linha *pc)						
{
	if(pc->primeira_coluna==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int inserir_em_ordem(struct no_linha (*pc), int valor, int coluna)		
{
	struct no_coluna *aux, *antes;
	struct no_coluna *novo;

	novo=(struct no_coluna*)malloc(sizeof(struct no_coluna));
	novo->valor_coluna=valor;
	novo->posicao_coluna=coluna;
	novo->proxima_coluna=NULL;	

	if( linha_vazia(pc) )		
	{
		pc->primeira_coluna=novo;
		return 0;
	}
	else	
	{
		antes=NULL;
		aux=pc->primeira_coluna;
		while(aux!=NULL)	
		{
			if(aux->posicao_coluna >= coluna)		
			{
				if(antes == NULL && pc->primeira_coluna == aux)	
				{
					novo->proxima_coluna = aux;
					pc->primeira_coluna = novo;	
					return 0;
				}
				else	
				{
					antes->proxima_coluna = novo;
					novo->proxima_coluna = aux;
					return 0;
				}
			}
			antes=aux;
			aux=aux->proxima_coluna;
		}
		if( aux == NULL && antes->posicao_coluna < coluna )
		{
			antes->proxima_coluna = novo;
			return 0;
		}

	}

}

void inserir_elemento(struct matriz_esparsa *m, int val, int lin, int col)
{
	struct no_linha *aux;
	aux=m->primeira;
	while(aux!=NULL)
	{
		if(aux->valor_linha==lin)
		{
			inserir_em_ordem(aux, val, col);
		}
		aux=aux->proxima_linha;
	}
}


void mostra_matriz_esparsa(struct matriz_esparsa *m)
{
	struct no_linha *aux_lin;
	struct no_coluna *aux_col;	
	
	aux_lin = m->primeira;
	while(aux_lin!=NULL)
	{

		printf("linha %d ",aux_lin->valor_linha);

		aux_col = aux_lin->primeira_coluna;


		while(aux_col!=NULL)
		{
			printf("coluna (%d,%d) ",aux_col->valor_coluna, aux_col->posicao_coluna);
			aux_col=aux_col->proxima_coluna;

		}
		

		printf("\n");
		aux_lin=aux_lin->proxima_linha;
	}
}


void rastreio_remove(struct matriz_esparsa *m, int linha, int coluna)		// chamada rastreio_remove vai procurar a linha e coluna e depois remover.
{
	struct no_linha *aux;					// auxiliar para procurar a linha.
	struct no_coluna *pc, *hold, *ant;		// auxiliar para procurar a coluna, armazenar a coluna anterior e coluna da proxima. 
	int chave = 0, chave_linha=0;
	aux=m->primeira;		
	while(aux!=NULL)			// loop principal, para  continuar enquanto o campo da linha que o aux estiver apontando for diferente de nulo.
	{
		if(aux->valor_linha==linha)		// Condicao para quando ele encontrar a linha informada pelo usuario.
		{
			//printf("achei a linha!");
			chave_linha=1;
			pc=aux->primeira_coluna;	
			while (pc!=NULL){		// loop principal da coluna.
				if (pc->posicao_coluna==coluna){		// Condição para quando encontrar a coluna informada pelo usuario.
					chave = 1;						//printf("Achei a coluna! %d\n", pc->valor_coluna);
					hold=pc->proxima_coluna;		//printf("HOLD: %d\n", hold->valor_coluna); / hold vai segurar a proxima coluna.
					pc->proxima_coluna=NULL;			// pc vai fazer a coluna que eu quero remover apontar para nulo.
					ant->proxima_coluna=hold;			// ant vai apontar para a coluna que hold estava segurando.
					
					
				}
				ant=pc;	  //printf("%d\n", ant->posicao_coluna); / ant vai sempre recer a coluna que o pc está apontando, para quando pc encontrar a coluna do 
				pc=pc->proxima_coluna; // ...usuario, ele vai esta guardando a anterior. / Aqui é o pc andando mais uma coluna enquanto ele nao acha a informada.
			}
			if (pc==NULL && chave==0){
				printf("valor ja vazio!");	// Se achar a linha, mas não a coluna, significa que ele esta vazia (igual a 0). 
			}
		}
		aux=aux->proxima_linha; // aux apontando para a proxima linha enqaunto ele nao acha a informda.
	}
	if (chave_linha==0){
		printf("Linha nao encontrada! Usuario informou valor alem do limite da linha"); // Condicao para quando ele nao encontra a linha. 
	}
}


int main()
{
	struct matriz_esparsa m;
	inicializa_matriz(&m);	
	int linha_proc = 3, coluna_proc=2;
int i, j;
	int sparse_matrix[numero_linha][numero_coluna] =
	{
		{50, 0, 0, 0},
		{10, 0, 20, 0},
		{0, 0, 0, 0},
		{-30, 0, -60, 5}
	};
	printf("      Matriz de entrada\n");
	for(i=0; i<numero_linha; i++)
	{
		for(j=0; j<numero_coluna; j++)
		{
			printf("%d ", sparse_matrix[i][j]);
		}
		printf("\n");
	}

	for(i=numero_linha-1; i>=0; i--)
	{
		inserir_linha(&m,i);		
	}

	for(i=0; i<numero_linha; i++)
	{
		for(j=0; j<numero_coluna; j++)
		{
			if( sparse_matrix[i][j] != 0 )
			{
				inserir_elemento(&m, sparse_matrix[i][j], i, j);			
			}

		}
	}

	printf("\n      Matriz esparsa\n");
	mostra_matriz_esparsa(&m);
	
	printf("\n      Remove Matriz Esparsa\n");
	printf("Remove linha: %d, coluna: %d",linha_proc, coluna_proc);
	rastreio_remove(&m,linha_proc, coluna_proc);
	printf("\n      Matriz esparsa\n");
	mostra_matriz_esparsa(&m);


}


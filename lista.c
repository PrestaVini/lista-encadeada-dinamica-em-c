#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

Lista l;

void inicializar() {
    Noh *nohAux;
    
    while(l.nohInicial != NULL) {
        nohAux = l.nohInicial;
        l.nohInicial = l.nohInicial->proximoNoh;
        free(nohAux);
    }
}

int verificarVazia() {
    if(l.nohInicial == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int tamanhoLista() {
    if(!verificarVazia()) {
        Noh *nohAux;
        nohAux = l.nohInicial;
        int contador = 1;
        while(nohAux->proximoNoh != NULL) {
            contador++;
            nohAux = nohAux->proximoNoh;
        }
        
        return contador;
    } else {
        return 0;
    }
}

void inserir(int numero, int posicao) {
    
    Noh *novoNoh = malloc(sizeof(Noh));
    if(novoNoh != NULL) {
        novoNoh->dado = numero;
        novoNoh->proximoNoh = NULL;
        
        if(verificarVazia()) {
            l.nohInicial = novoNoh;
        } else if(posicao == 1) {
            novoNoh->proximoNoh = l.nohInicial;
            l.nohInicial = novoNoh;
        } else if(posicao > tamanhoLista()) {
            Noh *nohAux;
            nohAux = l.nohInicial;
            
            while(nohAux->proximoNoh != NULL) {
                nohAux = nohAux->proximoNoh;
            }
            
            nohAux->proximoNoh = novoNoh;
        } else {
            Noh *nohAux = l.nohInicial;
            int contador = 1;
            
            while(contador < posicao - 1) {
                nohAux = nohAux->proximoNoh;
                contador++;
            }
            
            novoNoh->proximoNoh = nohAux->proximoNoh;
            nohAux->proximoNoh = novoNoh;
        }
        
    } else {
        printf("\nNao foi possivel alocar memoria!");
    }
    
}

void imprimir() {
    if(!verificarVazia()) {
        Noh *nohAux;
        nohAux = l.nohInicial;
        int contador = 1;
        
        do {
            printf("\nPosicao: %d", contador);
            printf("\nDado: %d\n", nohAux->dado);
            contador++;
            nohAux = nohAux->proximoNoh;
        } while(nohAux != NULL);
    } else {
        printf("\nA lista estah vazia!");
    }
}

int remover(int posicao) {
    if(!verificarVazia()) {
        Noh *nohAux;
        nohAux = NULL;
        int dadoRemovido;
        
        if(posicao == 1) {
            nohAux = l.nohInicial;
            l.nohInicial = nohAux->proximoNoh;
        } else {
            if(posicao <= tamanhoLista()) {
                Noh *nohAnterior;
                nohAnterior = l.nohInicial;
                int contador = 1;
                
                while(contador < posicao - 1 && nohAnterior->proximoNoh != NULL) {
                    contador++;
                    nohAnterior = nohAnterior->proximoNoh;
                }
                
                nohAux = nohAnterior->proximoNoh;
                nohAnterior->proximoNoh = nohAux->proximoNoh;
            } else {
                return 0;
            }
        }
        dadoRemovido = nohAux->dado;
        free(nohAux);
        return dadoRemovido;
    } else {
        return 0;
    }
}


//Funcoes para testes automatizados
void emitirResultado(int resultado) {
	if(resultado) 
		printf("\nGREEN: Passou!");
	else printf("\nRED: Nao passou!");
}

void testar1_VaziaLista(){
	printf("\nTeste 1: Este teste irah verificar a lista vazia");
	inicializar();
	if(verificarVazia()) {
		emitirResultado(1);
	} else emitirResultado(0);
}


void testar3_RemoverLista(){
	int removido = 0;
	printf("\nTeste 3: Este teste irah tentar remover de uma lista vazia");
	inicializar();
	removido = remover(0);
	if(verificarVazia())
		emitirResultado(1);
	else emitirResultado(0);
}

void testar4_RemoverLista(int quant){
	if(quant > 10) {
		printf("\nSo eh possivel testar com lista com ateh 10 elementos");
	} else {
		int i, respostaEsperada, removido,
		    numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
			posicao[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 
			posicaoRemover[10][10] = {
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{2, 2, 1, 0, 0, 0, 0, 0, 0, 0},
								{4, 2, 0, 1, 0, 0, 0, 0, 0, 0},
								{3, 4, 0, 2, 0, 0, 0, 0, 0, 0},
								{6, 1, 4, 0, 2, 1, 0, 0, 0, 0},
								{5, 2, 5, 2, 0, 2, 1, 0, 0, 0},
								{7, 7, 3, 5, 0, 2, 2, 1, 0, 0},
								{5, 5, 5, 0, 4, 4, 2, 1, 1, 0}
								},
				saida[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {2, 1, 0, 0, 0, 0, 0, 0, 0, 0},
								 {3, 1, 2, 0, 0, 0, 0, 0, 0, 0},
								 {3, 4, 2, 1, 0, 0, 0, 0, 0, 0},
								 {5, 3, 1, 4, 2, 0, 0, 0, 0, 0},
								 {4, 6, 1, 5, 2, 3, 0, 0, 0, 0},
								 {7, 2, 6, 1, 5, 4, 3, 0, 0, 0},
								 {6, 3, 8, 4, 1, 7, 5, 2, 0, 0},
								 {8, 9, 4, 7, 1, 5, 6, 3, 2, 0},
								 {6, 7, 8, 1, 9, 10, 4, 3, 5, 2}
								};
		printf("\nTeste 4: Este teste irah inserir %d elemento na lista e remove-lo, deixando a lista vazia", quant);

		inicializar();
		for(i = 0; i < quant; i++)
			inserir(numeros[i], posicao[i]+1);

		if(quant > TAM_MAX)
			respostaEsperada = TAM_MAX-1;
		else respostaEsperada = quant-1;
		
		for(i = 0; i < quant && i < TAM_MAX; i++) {
			removido = remover(posicaoRemover[respostaEsperada][i]+1);
			
			if(removido != saida[respostaEsperada][i]) {
				emitirResultado(0);
				return;
			}
		}
		//verifica se a lista ficou vazia
		if(verificarVazia())
			emitirResultado(1);
		else emitirResultado(0);
		}
}


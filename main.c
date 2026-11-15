#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(int argc, char *argv[]) {
	int temp, posicao;
	int opcao;
	inicializar();

	do {
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Realizar testes de inicializar a lista");
		printf("\n6. Realizar testes de inserir e remover na lista");
		printf("\n8. Sair");
		printf("\nDigite a opcao desejada: ");
		
		scanf("%d", &opcao);
		
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				printf("Digite o numero: ");
				scanf("%d", &temp);
				printf("Digite a posicao: ");
				scanf("%d", &posicao);
				if(posicao >= 1) {
				    inserir(temp, posicao);
				} else {
				    printf("\nA posicao deve ser maior ou igual a 1");
				}
				break;
			case 3:
				printf("Digite a posicao: ");
				scanf("%d", &posicao);
				if(posicao >= 1 && !verificarVazia() && posicao <= tamanhoLista()) {
    				temp = remover(posicao);
    				printf("\nNumero removido: %d", temp);
				} else {
				    printf("\nErro, ou a lista estah vazia ou a posicao eh invalida");
				}
				break;
			case 4:
				imprimir();
				break;
			case 5:
				testar1_VaziaLista();
				break;
			case 6:
				testar3_RemoverLista();
				testar4_RemoverLista(1);
				testar4_RemoverLista(2);
				testar4_RemoverLista(3);
				testar4_RemoverLista(4);
				testar4_RemoverLista(5);
				break;
			case 8:
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 8);
}

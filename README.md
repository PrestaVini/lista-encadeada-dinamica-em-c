# Lista Encadeada Dinâmica em C

Implementação de uma lista simplesmente encadeada utilizando alocação dinâmica de memória na linguagem C.

## Enunciado da atividade

Desenvolver uma lista encadeada dinâmica capaz de armazenar números inteiros. O programa deve permitir inicializar a lista, inserir elementos em posições determinadas, remover elementos, imprimir o conteúdo e verificar se a lista está vazia. Também devem ser realizados testes automatizados para validar as operações implementadas.

## Funcionalidades

- Inicialização e limpeza da lista;
- Liberação da memória alocada anteriormente;
- Verificação de lista vazia;
- Cálculo do tamanho da lista;
- Inserção de números em posições determinadas;
- Remoção de elementos por posição;
- Impressão dos dados armazenados;
- Menu interativo no terminal;
- Testes automatizados com resultados `GREEN` ou `RED`.

## Estrutura do projeto

| Arquivo | Descrição |
| --- | --- |
| `main.c` | Contém o menu e controla a interação com o usuário. |
| `lista.c` | Contém a implementação das funções da lista e dos testes. |
| `lista.h` | Contém as estruturas, constantes e assinaturas das funções. |

## Estruturas utilizadas

O projeto utiliza duas estruturas principais:

- `Noh`: guarda um número inteiro e um ponteiro para o próximo nó;
- `Lista`: guarda o ponteiro para o primeiro nó da lista.

A memória dos nós é reservada com `malloc()` e liberada com `free()`.

## Tecnologias utilizadas

- Linguagem C;
- Ponteiros;
- Estruturas (`struct`);
- Alocação dinâmica de memória;
- OnlineGDB.

## Como executar no OnlineGDB

1. Acesse [OnlineGDB](https://www.onlinegdb.com/online_c_compiler);
2. Selecione a linguagem **C**;
3. Crie os arquivos `main.c`, `lista.c` e `lista.h`;
4. Copie o conteúdo dos arquivos deste repositório;
5. Clique em **Run**;
6. Escolha uma opção do menu exibido no terminal.

## Compilação local

Com o GCC instalado, execute:

```bash
gcc main.c lista.c -o lista
./lista
```

No Windows, execute o programa compilado com:

```bash
lista.exe
```

## Testes

O menu permite executar testes automatizados para:

- Verificar se a lista foi inicializada vazia;
- Tentar remover um elemento de uma lista vazia;
- Inserir e remover diferentes quantidades de elementos;
- Confirmar que a lista fica vazia ao final das remoções.

Quando o resultado esperado é alcançado, o programa exibe `GREEN: Passou!`. Caso contrário, exibe `RED: Nao passou!`.

## Autor

Desenvolvido por [PrestaVini](https://github.com/PrestaVini).

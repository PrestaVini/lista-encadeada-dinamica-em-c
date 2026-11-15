#define TAM_MAX 5

typedef struct _noh {
    int dado;
    struct _noh *proximoNoh;
} Noh;

typedef struct _lista {
    Noh *nohInicial;
} Lista;

void inserir(int numero, int posicao);
int remover(int posicao);
void imprimir();
void inicializar();
int verificarVazia();
int tamanhoLista();

//Funcoes para testes automatizados
void testar1_VaziaLista();
void testar3_RemoverLista();
void testar4_RemoverLista(int quant);

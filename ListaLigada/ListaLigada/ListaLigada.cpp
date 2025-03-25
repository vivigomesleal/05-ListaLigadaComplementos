#include <iostream>
#include <cstdlib> // Adicionado para usar malloc e free

using namespace std;

// definicao de tipo
struct NO {
    int valor;
    NO* prox;
};

NO* primeiro = NULL;
NO* ultimo = NULL;    // Ponteiro para o ultimo elemento

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------

int main()
{
    menu();
    return 0; // Adicionado retorno para main
}

void menu()
{
    int op = 0;
    while (op != 7) {
        system("cls"); // somente no windows
        cout << "Menu Lista Ligada";
        cout << endl << endl;
        cout << "1 - Inicializar Lista \n";
        cout << "2 - Exibir quantidade de elementos \n";
        cout << "3 - Exibir elementos \n";
        cout << "4 - Buscar elemento \n";
        cout << "5 - Inserir elemento \n";
        cout << "6 - Excluir elemento \n";
        cout << "7 - Sair \n\n";

        cout << "Opcao: ";
        cin >> op;

        switch (op)
        {
        case 1: inicializar();
            break;
        case 2: exibirQuantidadeElementos();
            break;
        case 3: exibirElementos();
            break;
        case 4: buscarElemento();
            break;
        case 5: inserirElemento();
            break;
        case 6: excluirElemento();
            break;
        case 7:
            return;
        default:
            break;
        }

        system("pause"); // somente no windows
    }
}

void inicializar()
{
    // se a lista já possuir elementos
    // libera a memoria ocupada
    NO* aux = primeiro;
    while (aux != NULL) {
        NO* paraExcluir = aux;
        aux = aux->prox;
        free(paraExcluir);
    }

    primeiro = NULL;
    ultimo = NULL; // Adicionado para resetar o ultimo
    cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

    int nElementos = 0;
    NO* aux = primeiro;
    while (aux != NULL) {
        nElementos++;
        aux = aux->prox;
    }
    cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
    if (primeiro == NULL) {
        cout << "Lista vazia \n";
        return;
    }
    else {
        cout << "Elementos: \n";
        NO* aux = primeiro;
        while (aux != NULL) {
            cout << aux->valor << endl;
            aux = aux->prox;
        }
    }
}


void inserirElemento() {
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        cout << "Erro ao alocar memoria." << endl; // adicionado mensagem de erro
        return;
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    if (primeiro == NULL) {
        primeiro = novo;
        ultimo = novo; // Atualiza o ponteiro para o último elemento
    }
    else {
        ultimo->prox = novo; // Insere o novo nó após o último
        ultimo = novo; // Atualiza o ponteiro para o último elemento
    }
}

void excluirElemento() {
    if (primeiro == NULL) { // adicionado verificação de lista vazia
        cout << "Lista vazia" << endl;
        return;
    }

    int numero;
    cout << "Digite o elemento a ser excluido: ";
    cin >> numero;

    NO* atual = primeiro;
    NO* anterior = NULL;

    while (atual != NULL && atual->valor != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "Elemento nao encontrado." << endl;
        return;
    }

    if (anterior == NULL) {
        primeiro = atual->prox;
        if (primeiro == NULL) {
            ultimo = NULL;
        }
    }
    else {
        anterior->prox = atual->prox;
        if (anterior->prox == NULL) {
            ultimo = anterior;
        }
    }

    free(atual);
    cout << "Elemento excluido." << endl;
}
     
NO* posicaoElemento(int numero) { // implementação da função
    NO* atual = primeiro;
    while (atual != NULL) {
        if (atual->valor == numero) {
            return atual;
        }
        atual = atual->prox;
    }   
    return NULL;
}

void buscarElemento() {
    int numero;
    cout << "Digite o elemento a ser buscado: ";
    cin >> numero;

    NO* encontrado = posicaoElemento(numero);
    if (encontrado != NULL) {
        cout << "Elemento encontrado: " << encontrado->valor << endl;
    }
    else {
        cout << "Elemento nao encontrado." << endl;
    }
}
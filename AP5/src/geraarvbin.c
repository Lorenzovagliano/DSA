#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <getopt.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

// Syntax tree structure
typedef long TipoChave;
typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;
typedef struct TipoNo * TipoApontador;
typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef struct prm{
  char nomesaida[200];
  int semente;
  int numno;
  FILE * saida;
  int treesize;
  int numlevel;
} prm_t;

void uso()
// Descricao: imprime as instrucoes de uso do programa
// Entrada:  N/A
// Saida: instrucoes
{
  fprintf(stderr,"geraexp\n");
  fprintf(stderr,"\t-o <arq>\t(arquivo de saida) \n");
  fprintf(stderr,"\t-s <num>\t(semente)\n");
  fprintf(stderr,"\t-n <num>\t(numero de nos)\n");
  fprintf(stderr,"\t-h\t(opcoes de uso)\n");
}

void parse_args(int argc, char ** argv, prm_t * prm)
// Descricao: analisa a linha de comando a inicializa variaveis
// Entrada: argc e argv
// Saida: prm
{
     extern char * optarg;
     extern int optind;
     int c ;
     //>Reges padrao
     prm->nomesaida[0] = 0;
     prm->semente = 0;
     prm->numno = 3;
     prm->numlevel = 2;
     // percorre a linha de comando buscando identificadores
     while ((c = getopt(argc, argv, "o:s:n:iph")) != EOF){
       switch(c) {
         case 'o':
	          // arquivo de saida
	          strcpy(prm->nomesaida,optarg);
                  break;
         case 's':
	          // semente aleatoria
	          prm->semente = atoi(optarg);
		  srand48((long) prm->semente);
		  break;
         case 'n':
	          // numero de nos
	          prm->numno = atoi(optarg);
		  prm->numlevel = ((int) log2((double) prm->numno))+2;
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
     }
     // verifica apenas o nome do arquivo de saida
     if (!prm->nomesaida[0]) {
       printf("Arquivo de saida nao definido.");
       exit(1);
     }
}

void dumpTree(TipoApontador * T, int level, prm_t * prm) {
  if ((*T) != NULL) {
    for(int i=0; i<level; i++) fprintf(prm->saida,"    ");
    fprintf(prm->saida," %3ld (%d)\n", (*T)->Reg.Chave,level);
    dumpTree(&(*T)->Esq,level+1,prm);
    dumpTree(&(*T)->Dir,level+1,prm);
  }
}

int createTree(TipoNo ** curr, int level, prm_t * prm){
  // create node
  (*curr) = (TipoNo*) malloc(sizeof(TipoNo));
  (*curr)->Esq = (*curr)->Dir = NULL;
  // set type
  if (drand48()>((8.0*(1<<level)*prm->treesize))/(((1<<prm->numlevel)*prm->numno))){
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
    if (prm->treesize<prm->numno) createTree(&((*curr)->Esq),level+1,prm);
    if (prm->treesize<prm->numno) createTree(&((*curr)->Dir),level+1,prm);
  } else {
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
  }
  return prm->treesize;
}

void preOrderAux(TipoNo *root, TipoNo **pre, int *indice) {
  if (root == NULL) {
    return;
  }
  pre[*indice] = root;
  (*indice)++;
  preOrderAux(root->Esq, pre, indice);
  preOrderAux(root->Dir, pre, indice);
}

void preOrder(TipoNo *root, TipoNo **pre, int indice) {
  preOrderAux(root, pre, &indice);
}

// função para realizar o caminhamento in-order
void inOrderAux(TipoNo *root, TipoNo **in, int *indice) {
  if (root == NULL) {
    return;
  }
  inOrderAux(root->Esq, in, indice);
  in[*indice] = root;
  (*indice)++;
  inOrderAux(root->Dir, in, indice);
}

void inOrder(TipoNo *root, TipoNo **in, int indice) {
  inOrderAux(root, in, &indice);
}

// função para realizar o caminhamento pos-order
void posOrderAux(TipoNo *root, TipoNo **pos, int *indice) {
  if (root == NULL) {
    return;
  }
  posOrderAux(root->Esq, pos, indice);
  posOrderAux(root->Dir, pos, indice);
  pos[*indice] = root;
  (*indice)++;
}

void posOrder(TipoNo *root, TipoNo **pos, int indice) {
  posOrderAux(root, pos, &indice);
}

bool ancestral(int i, int j, TipoNo** pre, TipoNo** pos, int tam_pre, int tam_pos) {

  int pos_i = -1, pos_j = -1;
  for (int k = 0; k < tam_pos; k++) {
    if (pos[k] == pre[i]) {
      pos_i = k;
    }
    if (pos[k] == pre[j]) {
      pos_j = k;
    }
    if (pos_i != -1 && pos_j != -1) {
      break; // encontramos as posições de i e j nos vetores de pós-ordem
    }
  }

  // procura o ancestral comum recursivamente
  for (int k = 0; k < tam_pre; k++) {
    if (pre[k] == NULL) {
      continue;
    }
    if (k == i || k == j) {
      continue;
    }
    int pos_k = -1;
    for (int l = 0; l < tam_pos; l++) {
      if (pos[l] == pre[k]) {
        pos_k = l;
        break;
      }
    }
    if (pos_k == -1) {
      continue; // k não foi encontrado no vetor pos
    }
    if ((pos_k < pos_i && pos_k > pos_j) || (pos_k > pos_i && pos_k < pos_j)) {
      return true; // k é o ancestral comum de i e j
    }
    if (pos_k < pos_i && pos_k < pos_j) {
      break; // k está à esquerda de i e j, portanto não é o ancestral comum
    }
    // k está à direita de i e j, continuamos a busca
  }

  return false; // não foi encontrado um ancestral comum
}

int main(int argc, char *argv[])
{
  TipoNo *root;
  prm_t prm;
  int i,j;

  parse_args(argc,argv,&prm);
  prm.saida = fopen(prm.nomesaida,"wt");
  prm.treesize = 0;

  createTree(&root,0,&prm);
  dumpTree(&root,0,&prm);
  TipoNo** pre = NULL;
  TipoNo** in = NULL;
  TipoNo** pos = NULL;
  pre = malloc(prm.treesize * sizeof(TipoNo*));
  in = malloc(prm.treesize * sizeof(TipoNo*));
  pos = malloc(prm.treesize * sizeof(TipoNo*));
  int indice = 0;
  void preOrder(root, pre, indice);
  indice = 0;
  void inOrder(root, pre, indice);
  indice = 0;
  void posOrder(root, pre, indice);

  int preSize = sizeof(pre)/sizeof(TipoNo);
  int posSize = sizeof(pos)/sizeof(TipoNo);

  for (int k=0; k<prm.treesize; k++){
    i = j = 0;
    while (i==j){
      i = (int) (drand48()*prm.treesize);
      j = (int) (drand48()*prm.treesize);
    }
    fprintf(prm.saida,"%d testando ancestral(%d,%d)\n",k,i,j);
    ancestral(i,j, pre, pos, preSize, posSize); 
  }

  fclose(prm.saida);
  return 0;
} 

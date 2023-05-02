//---------------------------------------------------------------------
// Arquivo      : vetop.c
// Conteudo     : programa de avaliacao do TAD VET 
// Autor        : Wagner Meira Jr. (meira@dcc.ufmg.br)
// Historico    : 2022-04-01 - arquivo criado
//---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>
#include <string.h>
#include "vet.h"
#include "msgassert.h" 

// definicoes de operacoes a serem testadas
#define OPSOMA 1
#define OPPRODUTOINTERNO 2
#define OPNORMA 3

typedef struct opt{
  int opescolhida;
  int tam;
} opt_tipo;

void uso()
// Descricao: imprime as opcoes de uso
// Entrada: nao tem
// Saida: impressao das opcoes de linha de comando
{
  fprintf(stderr,"vetop\n");
  fprintf(stderr,"\t-d <int>\t(dimensao)\n");
  fprintf(stderr,"\t-s \t\t(somar vetores) \n");
  fprintf(stderr,"\t-i \t\t(produto interno de dois vetores) \n");
  fprintf(stderr,"\t-n \t\t(norma vetor)\n");
}


void parse_args(int argc,char ** argv, opt_tipo * opt)
// Descricao: le as opcoes da linha de comando e inicializa variaveis
// Entrada: argc, argv, opt
// Saida: opt
{
     // variaveis externas do getopt
     extern char * optarg;
     extern int optind;

     // variavel auxiliar
     int c;

     // inicializacao variaveis globais para opcoes
     opt->opescolhida = -1;
     opt->tam = -1;

     // getopt - letra indica a opcao, : junto a letra indica parametro
     // no caso de escolher mais de uma operacao, vale a ultima
     while ((c = getopt(argc, argv, "isnd:h")) != EOF)
       switch(c) {
         case 'i':
		  avisoAssert(opt->opescolhida==-1,
		              "Mais de uma operacao escolhida");
	          opt->opescolhida = OPPRODUTOINTERNO;
                  break;
         case 's':
		  avisoAssert(opt->opescolhida==-1,
		              "Mais de uma operacao escolhida");
	          opt->opescolhida = OPSOMA;
                  break;
         case 'n':
		  avisoAssert(opt->opescolhida==-1,
		              "Mais de uma operacao escolhida");
	          opt->opescolhida = OPNORMA;
                  break;
         case 'd': 
	          opt->tam = atoi(optarg);
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
       // verificacao da consistencia das opcoes
       erroAssert(opt->opescolhida>0,"vetop - necessario escolher operacao");
       erroAssert(opt->tam>0, "matop - tamanho do vetor tem que ser positivo");
}


int main(int argc, char ** argv)
// Descricao: programa principal para execucao de operacoes de matrizes 
// Entrada: argc e argv
// Saida: depende da operacao escolhida
{
  // ate 3 matrizes sao utilizadas, dependendo da operacao
  vetor_tipo a, b, c;
  double norma, prodinterno;
  opt_tipo opt;
  // avaliar linha de comando
  parse_args(argc,argv,&opt);

  // execucao dependente da operacao escolhida
  switch (opt.opescolhida){
    case OPSOMA:
         // cria vetores a e b aleatorios, que sao somados para o vetor c
	 // vetor c é impresso e todos os vetores sao destruidos
         criaVetor(&a,opt.tam,0);
         inicializaVetorAleatorio(&a);
	 printf("Vetor a:\n");
	 imprimeVetor(&a);
         criaVetor(&b,opt.tam,1);
         inicializaVetorAleatorio(&b);
	 printf("Vetor b:\n");
	 imprimeVetor(&b);
         criaVetor(&c,opt.tam,2);
         inicializaVetorNulo(&c);
         somaVetores(&a,&b,&c);
	 printf("Vetor c:\n");
	 imprimeVetor(&c);
         destroiVetor(&a);
         destroiVetor(&b);
         destroiVetor(&c);
	 break;
    case OPPRODUTOINTERNO:
         // cria vetores a e b aleatorios, e calcula o seu produto interno
         criaVetor(&a,opt.tam,0);
         inicializaVetorAleatorio(&a);
	 printf("Vetor a:\n");
	 imprimeVetor(&a);
         criaVetor(&b,opt.tam,1);
         inicializaVetorAleatorio(&b);
	 printf("Vetor b:\n");
	 imprimeVetor(&b);
         prodinterno = produtoInternoVetores(&a,&b);
	 printf("Produto interno %f\n",prodinterno);
         destroiVetor(&a);
         destroiVetor(&b);
	 break;
    case OPNORMA:
         // cria vetor aleatorio e calcula sua norma
         criaVetor(&a,opt.tam,0);
         inicializaVetorAleatorio(&a);
	 printf("Vetor a:\n");
	 imprimeVetor(&a);
	 norma = normaVetor(&a);
	 printf("Norma %f\n",norma);
         destroiVetor(&a);
	 break;
   default:
         // nao deve ser executado, pois ha um erroAssert em parse_args
         uso();
	 exit(1);
  }

  return 0;
}


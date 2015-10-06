#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Rotulo{
	char nome[101];
	int memoria;
	struct Rotulo *prox;
}Rotulo;

void ObtemRotulos(FILE *entrada,Rotulo **p);
Rotulo* AddLista(Rotulo *ini, char info[]);
void imprime(Rotulo *ini);
int RemoveSufixo(char info[]);
int vazia(Rotulo *LISTA);
void Writer(FILE *entrada);
int main (int argc, char *argv[]){
  Rotulo *p = NULL;
  char *pch;
  char info[1001];   
  FILE *entrada;
  FILE *saida;
  entrada = fopen(argv[1], "r");
  saida = fopen(argv[2], "w");
  if(entrada == NULL && saida == NULL)
	printf("Erro, nao foi possivel abrir o arquivo\n");
  else
    while( (fgets(info, sizeof(info), entrada))!=NULL ){
	    pch = strtok (info," ,-;\n)(");
	    while (pch != NULL && *pch != '#'){
             fprintf(saida,"%s\n",pch);
             pch = strtok (NULL, " ,-;\n)(");
        }
	}
	fclose(entrada);
	fclose(saida);	
	entrada = fopen(argv[2],"r");	
	ObtemRotulos(entrada,&p);	
	rewind(entrada);	
	Writer(entrada);
	close(entrada);	
	imprime(p);
    
	
  
	return 0;
}

void ObtemRotulos(FILE *entrada,Rotulo **p){
	char info[101];	
	int Rotulo;	
	while(fgets(info,sizeof(info),entrada)!=NULL){
		Rotulo = RemoveSufixo(info);
		if(Rotulo)
			*p = AddLista(*p,info);
	}
}
	

Rotulo* AddLista(Rotulo *LISTA, char info[]) {
	Rotulo *novo=(Rotulo *) malloc(sizeof(Rotulo));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	novo->prox = NULL;
	
	if(vazia(LISTA)){
		LISTA =novo;
		strcpy(novo->nome,info);		
	}
	else{
		Rotulo *tmp = LISTA;
		strcpy(novo->nome,info);
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		
		tmp->prox = novo;
	}
	return LISTA;
}


void imprime(Rotulo *ini) {
	Rotulo *p;
	p = ini;
	while (p) {
		printf("%s \n", p->nome);
		p = p->prox;
	}
}

int RemoveSufixo(char info[]){
	int tam;
	tam = sizeof(info);
	if(info[tam-2] == ':'){
		info[tam-2] = '\0';	
		return 1;
	}
	else 
		return 0;
}	

int vazia(Rotulo *LISTA)
{
	if(LISTA == NULL)
		return 1;
	else
		return 0;
}

void Writer(FILE *entrada){
	char info[101];	
	char org[] = ".org";
	char align[] = ".align";
	char wfill[] = ".wfill";
	char word[] = ".word";
	char set[] = ".set";	
		
	while(fgets(info,sizeof(info),entrada)!=NULL){
		if(info[0] == '.'){
			if(!strcmp(strlwr(info),org)){
				fgets(info,sizeof(info),entrada);				
				org(info);
			}
			else if(!strcmp(strlwr(info),align)){
				fgets(info,sizeof(info),entrada);
				align(info);
			}
			else if(!strcmp(strlwr(info),wfill)){
				fgets(info,sizeof(info),entrada);
				wfill(info);
			}
			else if(!strcmp(strlwr(info),word)){
				fgets(info,sizeof(info),entrada);
				word(info);
			}
			else if(!strcmp(strlwr(info),set)){
				fgets(info,sizeof(info),entrada);
				set(info);
			}
		}

	}
}


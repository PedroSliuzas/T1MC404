#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
  char * pch;
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
  return 0;
}

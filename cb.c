#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

void Conversor(char palavra[]);
char *TiraRotulo(char palavra[]);
void Decimal(char palavra[]);
void Bin(char palavra[]);
void Octal(char palavra[]);
char *strrev(char *str);
int main(){
    char palavra[100];
    scanf("%s",palavra);
    Conversor(palavra);
    
    return 0;
}
 
void Conversor(char palavra[]){
 
    if(palavra[1] == 'x' || palavra[1] == 'X' ){
       palavra = TiraRotulo(palavra);
       printf("%s \n",palavra); 
    }
    else if(palavra[1] == 'b' || palavra[1] == 'B')
       Bin(TiraRotulo(palavra));
    else if(palavra[1] == 'o' || palavra[1] == 'O')
       Octal(TiraRotulo(palavra));
    else 
       Decimal(palavra);
   
 
                  
}


char *TiraRotulo(char palavra[]){
    int i = 2,tamanho;
    tamanho = strlen(palavra);
    while(i<(tamanho)){
        palavra[i-2] = palavra[i];
        i++;
    }
    palavra[i-2] = '\0';
    return palavra;    
}

void Decimal(char palavra[]){
    int valor,i=0,tamanho;
    char resultado[100];
    valor =  atoi(palavra);
    tamanho = strlen(palavra);
	while(valor!= 0){
      if((valor % 16)< 10)
        resultado[i] = 48+(valor % 16);
      else if((valor % 16) == 10)
        resultado[i] = 'A';
      else if((valor % 16) == 11)
        resultado[i] = 'B';
      else if((valor % 16) == 12)
        resultado[i] = 'C';
      else if((valor % 16) == 13)
        resultado[i] = 'D';       
      else if((valor % 16) == 14)
        resultado[i] = 'E';
      else if((valor % 16) == 15)
        resultado[i] = 'F'; 
      valor = valor/16;
      i++;
    }
	resultado[i] = '\0';
	palavra = strrev(resultado);
    printf("%s \n",palavra);	
    
}    

void Bin(char palavra[]){
    int tamanho,i,resultado = 0;
    tamanho = strlen(palavra);
    for(i = 0;i<tamanho;i++)
        resultado += (palavra[i]-48)*pow(2,tamanho-1-i); 
    sprintf(palavra, "%i", resultado);
    Decimal(palavra);
    
}

void Octal(char palavra[]) {
    int tamanho,i,resultado = 0;
    tamanho = strlen(palavra);
    for(i = 0;i<tamanho;i++)
        resultado += (palavra[i]-48)*pow(8,tamanho-1-i);    
    sprintf(palavra, "%i", resultado);
   Decimal(palavra);
    
}   

char *strrev(char *str){
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

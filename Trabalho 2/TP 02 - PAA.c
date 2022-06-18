#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// TRABALHO 2 - PROJETO E ANALISE DE ALGORTIMOS
//Informacoes do estudante
// Nome: Joao Pedro Pereira
// Curso: BCC
// RA: 769714

void Merge_Vetor (int inicio_vet, int meio_vetor, int final_vet, int *vetor) {

   int *aux, inicio, meio, temp = 0;

   aux = malloc ((final_vet - inicio_vet) * sizeof (int));      
   inicio = inicio_vet;
   meio = meio_vetor;                       
                                 
   while (inicio < meio_vetor && meio < final_vet) {  
      if (vetor[inicio] >= vetor[meio]) {
         aux[temp++] = vetor[inicio++]; 
      }      
      else {
        aux[temp++] = vetor[meio++]; 

      }             
   }   
   while (inicio < meio_vetor) {
      aux[temp++] = vetor[inicio++]; 
   } 
   while (meio < final_vet) {
      aux[temp++] = vetor[meio++];  
   } 
   for (inicio = inicio_vet; inicio < final_vet; inicio++) {
      vetor[inicio] = aux[inicio - inicio_vet]; 
   } 
   free (aux);                           
}

void Merge_Sort (int inicio_vetor, int final_vetor, int *vetor) {

   int meio_vetor;

   if (inicio_vetor < final_vetor - 1) {          
      meio_vetor = (inicio_vetor + final_vetor) / 2;          
      Merge_Sort (inicio_vetor, meio_vetor, vetor);        
      Merge_Sort (meio_vetor, final_vetor, vetor);        
      Merge_Vetor (inicio_vetor, meio_vetor, final_vetor, vetor);     
   }
 
}

int main()
{
   FILE *pont_arquivo;
   long long int count = 0;
   char name_archive[MAX];

   scanf ("%s", name_archive);
   pont_arquivo = fopen (name_archive, "r");

   if (pont_arquivo == NULL){
      printf("O arquivo %s, nao foi encontrado\n", name_archive);
      exit(EXIT_FAILURE);
    }

   int i, tam, *vetor;
   
      fscanf(pont_arquivo, "%d", &tam);
      vetor = (int*) malloc(tam * sizeof(int));

   for (i = 0; i < tam; i++){
      fscanf(pont_arquivo, "%d", &vetor[i]);
   }

   Merge_Sort(0, tam, vetor);

   for(i = 2; i < tam; i = i + 3){
      count += vetor[i];
   }

   printf("%lld", count);
   
   free(vetor);
   
   fclose(pont_arquivo);

    return 0;

}




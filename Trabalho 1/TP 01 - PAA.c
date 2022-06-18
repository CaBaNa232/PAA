#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// TRABALHO 1 - PROJETO E ANALISE DE ALGORTIMOS
//Informacoes do estudante
// Nome: Joao Pedro Pereira
// Curso: BCC
// RA: 769714

int Merge_Vetor (int inicio_vet, int meio_vetor, int final_vet, int *vetor) 
{
   int *aux, inicio, meio, temp, count; 

   count = 0 ;
   temp = 0;

   aux = malloc ((final_vet - inicio_vet) * sizeof (int));      
   inicio = inicio_vet;
   meio = meio_vetor;                       
                                 
   while (inicio < meio_vetor && meio < final_vet) {  
      if (vetor[inicio] <= vetor[meio]) {
         aux[temp++] = vetor[inicio++]; 
      }      
      else {
        aux[temp++] = vetor[meio++]; 
        count += (meio_vetor + 1) - inicio + 1;
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
   return count;   
   free (aux);   
                           
}

int Merge_Sort (int inicio_vetor, int final_vetor, int *vetor)
{
   int meio_vetor, count;
   count = 0;

   if (inicio_vetor < final_vetor - 1) {          
      meio_vetor = (inicio_vetor + final_vetor) / 2;          
      count += Merge_Sort (inicio_vetor, meio_vetor, vetor);        
      count += Merge_Sort (meio_vetor, final_vetor, vetor);        
      count += Merge_Vetor (inicio_vetor, meio_vetor, final_vetor, vetor);     
   }
   return count;
}

int main()
{

   FILE *pont_arquivo;
   int count_swap = 0;
   char name_archive[MAX];
   scanf ("%s", name_archive);
   pont_arquivo = fopen (name_archive, "r");

   if (pont_arquivo == NULL){
      printf("O arquivo %s, nao foi encontrado\n", name_archive);
      exit(EXIT_FAILURE);
    }

   int i, tam = 1, *vetor;
   
    while (tam != 0){

      fscanf(pont_arquivo, "%d", &tam);
      vetor = (int*) malloc(tam * sizeof(int));

   for (i = 0; i < tam; i++){
         fscanf(pont_arquivo, "%d", &vetor[i]);
      }

   count_swap = Merge_Sort(0, tam, vetor);
   //printf("Trocas - %d\n", count_swap);
      
   if (tam != 0){
      if (count_swap % 2 == 0){ 
            printf("Finn\n");
         }
      else{
         printf("Jake\n"); 
         }
      }
    }    

   free(vetor);
   
   fclose(pont_arquivo);


    return 0;

}


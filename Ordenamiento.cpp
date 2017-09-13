#include<stdio.h> 
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 
#define tam 1000

struct nodo{
       int dato; 
       struct nodo *sig; 
       struct nodo *ant;
       };
typedef struct nodo* lista;

lista li;
int i,j,n;
int menu();
int menu_portada();
void portada();
void vecAleatorio();
void quicksort(lista, int primero, int ultimo);
void vec_quicksort(int a[], int primero, int ultimo);


int main(int argc, char*argv[]){
    li = (nodo*) malloc(sizeof(nodo));
	li->sig = NULL;
	li->ant = NULL;
	li->dato = 0;
	menu();//ABRIR MENU PRINCIPAL
    
}//FIN DEL MAIN 
 
int menu(){
    system ("CLS");    
    int sw=1, i, j, auxiliarP, aux;
    int arreglo[tam], vec[tam];;
    long opcion;
    clock_t inicio,fin;
	nodo* auxiliar, *p;
    double tiempo;
    //bool vecvacio= true;
    
    do{
    switch (menu_portada()){       
                    case 1:
                        system ("CLS");
            
                        p = li;                         
                        aux = 0; 
                        srand(time(0));
                     
                        for(int i = 0; i < tam; i++){
                            aux = (1 + rand() % 1000);                 
                        
						 
                        //arreglo[i] = aux;
						auxiliar = (nodo*) malloc(sizeof(nodo));
						auxiliar->sig = NULL;
						auxiliar->ant = NULL;
						auxiliar->dato = aux;
						while (p->sig!=NULL) {
						 p = p->sig;

						}
						p ->sig = auxiliar;
						auxiliar->ant = p;
						
						printf("[%d]\t",auxiliar->dato);
                        }
                         getchar();
					
					                 
                        break;

                     case 2:
							
                         inicio = clock();
                         system("cls");
						 p = li;
						 auxiliarP = 0;
						 while (p->sig!= NULL){
							 p = p->sig;
							 auxiliarP++;
						 }

						 quicksort(li, 0, auxiliarP);
						 p = li;
						 while(p!=NULL){
							 printf("[%d]\t",p->dato);
							 p = p->sig;
						 }
                         fin = clock();
                         tiempo=((double)(fin-inicio))/CLOCKS_PER_SEC;
                         printf("\n\nEl tiempo es %f sec",tiempo);
                         getch();
                       break;
                       
                     case 3:
                        system ("CLS");
                        void vecAleatorio();{
                                                 
                        int aux = 0; 
                        srand(time(0));
                     
                        for(int i = 0; i < tam; i++){
                            aux = (1 + rand() % 1000);                 
                            int aux2 = 0;
                     
                             while(aux2 < i){
                     
                              if(aux != arreglo[aux2])
                                   aux2++;
                     
                              else{
                                   aux = (1 + rand() % 1000);
                                   aux2 = 0; 
                                    }
                             } 
                        arreglo[i] = aux; 
                        printf("[%d]\t",arreglo[i]);
                        }
                         getchar();    
                        }                   
                        break;
                       
                     case 4:                       
                       system("cls");
                         inicio = clock();
                         for(int x=0;x<tam;x++){
                                 vec[x]=arreglo[x]; 
                         }
                         vec_quicksort(vec, 0, 999);
                         for(int x=0; x<tam; x++) printf("[%d]\t",vec[x]);
                         
                         fin = clock();
                         tiempo=((double)(fin-inicio))/CLOCKS_PER_SEC;
                         printf("\n\nEl tiempo es %f sec",tiempo);
                         getch();
                       break;                   
                         
                     case 5:
                         system ("CLS");
                         printf ("Press any key to exit...");
                         getch();                     
                         exit(0); //FUNCION PARA SALIR DEL PROGRAMA                           
                         break;
                     default:
                         system ("CLS");
                         printf("opcion no valida...por favor intente nuevamente\n");
                         getch();
                         break;    
                    }
    }while(sw!=0);
    
  system("pause");
  return 0;  
     
}//FIN MENU

int menu_portada(){

    portada();//IMAGEN DEL MENU PRINCIPAL
    int opc;
    printf("\t");
	  scanf("%d",&opc);//CAPTURAR OPCIONES DEL MENU
	  fflush(stdin);

	   while(opc < 1 || opc > 5){//VALIDAR OPCIONES
	   system("cls");
	   portada();
	   printf("\n\t\t\tIngrese Una Opcion Valida: ");
	   fflush(stdin);
       scanf("%d",&opc);
       }
       
       return opc;
	            
}//FIN MENU PORTADA
//********************************************************************************************//
//****************************** F O N D O  D E L   M E N U **********************************//
//********************************************************************************************//

void portada(){
     
         system("cls");
         system ("color 3f");
         printf("\n");
         printf("         -------------------------------------------------------------\n");
         printf("        |                                                             |\n");         
         printf("        |      :: O R D E N A M I E N T O  Q U I C K  S O R T ::      |\n");
         printf("        |                                                             |\n");
         printf("        |     ::U N I V E R S I D A D  D E L  M A G D A L E N A::     |\n");
         printf("        |                                                             |\n");   
         printf("         -------------------------------------------------------------'\n");
         printf("                               |            |                           \n");
         printf("  ---------------------------------------------------------------------------\n");
         printf(" |                                                                           |\n");
         printf(" |   1. GENERAR ALEATORIO LISTA.                                             |\n");
         printf(" |   2. METODO QUICK SORT LISTA.                                             |\n");
         printf(" |   3. GENERAR VECTOR ALEATORIO.                                            |\n");
         printf(" |   4. METODO QUICK SORT VECTOR.                                            |\n");
         printf(" |   5. SALIR.                                                               |\n");
         printf(" |                                                                           |\n");
         printf("  ---------------------------------------------------------------------------'\n");
         printf("                               |            |\n");
         printf("                               |  ESCOJA:   |\n");
         printf("                               |            |\n");
         printf("                                ------------ "); 
         
}//FIN PORTADA 


//***********************************************************************************//
//************************* Q U I C K  S O R T  L I S T A ***************************//
//**********************************************************************************//

void quicksort(lista a, int primero, int ultimo)
{
int i, j, central, k, aux = 0;
int pivote;
nodo* ip = a;
nodo* p = ip;
nodo* jp = ip;
central = (primero + ultimo)/2;
for (k = 0; k< central; k++){
	p = p->sig;
}
pivote = p->dato;
while(aux!=primero){
	ip = ip->sig;
	aux++;
}
aux = 0;
while(aux!=ultimo){
	jp = jp->sig;
	aux++;
}

i = primero;
j = ultimo;

do{
	while (ip->dato < pivote) {
		ip = ip->sig;
		i++;
	}
	while (jp->dato > pivote) {
		jp = jp->ant;
		j--;
	
	}
  if (i <= j)
  {
     int tmp;
	 tmp = ip->dato;
	 ip->dato = jp->dato;
	 jp->dato = tmp;
     i++;
	 ip = ip->sig;
     j--;
	 jp = jp->ant;
  }
}while (i <= j);

/* intercambia a[i] con a[j] */

    if (primero < j)
      quicksort(a, primero, j);
    if (i < ultimo)
      quicksort(a, i, ultimo);      
}

//************************************************************************//
//************************* Q U I C K  S O R T ***************************//
//************************************************************************//

void vec_quicksort(int a[], int primero, int ultimo)
{
int i, j, central;
int pivote;
central = (primero + ultimo)/2;
pivote = a[central];
i = primero;
j = ultimo;

do{
   while (a[i] < pivote) i++;
   while (a[j] > pivote) j--;
  if (i <= j)
  {
     int tmp;
     tmp = a[i];
     a[i] = a[j];
     a[j] = tmp;
     i++;
     j--;
  }
}while (i <= j);

/* intercambia a[i] con a[j] */

    if (primero < j)
      vec_quicksort(a, primero, j);
    if (i < ultimo)
      vec_quicksort(a, i, ultimo);      
}




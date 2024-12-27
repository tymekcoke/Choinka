#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //deklaracje zmiennych i stałych wartości
    int i, j, k, len, l, gestosc;
    
    char spacja = ' ';
    char gwiazdka = '*';
    char ozdoba = 'o';
     
    //inicjalizacja generatora losowych liczb
    srand(time(NULL));
    
    //zapytanie o długość choinki oraz gęstość ozdób (i sprawdzanie ich poprawnosci)
    printf("Dlugosc choinki: ");
    scanf("%d", &len);
    
      if (len < 1){
        printf("Wprowadzono nieprawidlowa wysokosc choinki (wysokosc zostala ustawiona na standardowa, czyli 8)\n");
        len = 8;
    }
    
    printf("Gestosc ozdob (od 0 do 100): ");
    scanf("%d", &gestosc);
    
    
    if (gestosc > 100 | gestosc < 0){
        printf("Wprowadzono nieprawidlowa gestosc ozdob (gestosc zostala ustawiona na standardowa, czyli 20)\n");
        gestosc = 20;
    }
    

    //głowna pętla
    for (i = 1; i < len + 1; i++){
        
        //spacje
        for (k = 0; k < len - i; k++){
            printf("%c", spacja);
        }
        
        //gwiazdki
        int ilosc_gwiazdek = (2*i) - 1;
        
        for (j = 0; j < ilosc_gwiazdek; j++){
            
            //ozdoby
            if (rand() % 100 < gestosc){
                int kolor = rand () % 5 + 1;
                switch (kolor) {
                    case 1: printf("\033[1;31m%c\033[0m", ozdoba); break; 
                    case 2: printf("\033[1;32m%c\033[0m", ozdoba); break; 
                    case 3: printf("\033[1;33m%c\033[0m", ozdoba); break; 
                    case 4: printf("\033[1;34m%c\033[0m", ozdoba); break; 
                    case 5: printf("\033[1;35m%c\033[0m", ozdoba); break; 
                }  
            } else {printf("\033[0;32m%c\033[0m", gwiazdka);}
                
            
        }
        
        printf("\n");
        
    }

    //pień
    for (i = 1; i < 3; i++){
        
        for (l = 1; l < len - 1; l++){
            printf("%c", spacja);
        }
        
        printf("\033[0;33mMvM\033[0m\n");
        

    }
    
    //napis
    printf("\n\033[1;31mW\033[1;32me\033[1;33ms\033[1;34mo\033[1;35mł\033[1;36my\033[1;31mch \033[1;32mŚ\033[1;33mw\033[1;34mi\033[1;35ma\033[1;36mt!\033[0m\n");

    return 0;
}
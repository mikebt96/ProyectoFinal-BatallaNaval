// Proyecto Final - BatallaNaval.c
// Implementación de un juego simple de Batalla Naval en C
// Autor: Miguel Ángel Butrón López
// Materia: Fundamentos de Programación UNAM (2018)
// Descripción: Juego de Batalla Naval en C donde el jugador coloca barcos
// y ataca la flota enemiga en un tablero de 5x5.





#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

#define BoardSize 5
#define Water '~'
#define Ship 'S'
#define ShipNum 5
#define Hit 'X'
#define Miss 'O'

void ClearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void BoardInitializer(char tab[BoardSize][BoardSize]){

    for(int i = 0; i<BoardSize; i++){
        for(int j=0; j<BoardSize; j++){
            tab[i][j] =  Water;
        }
    }
}

void BoardPrint(char tab[BoardSize][BoardSize]){
    printf(" \n\n");
    for(int i = 0; i<BoardSize; i++){
        for(int j=0; j<BoardSize; j++){
            printf("%c ", tab[i][j]);
        }

        printf("\n");
    }
}

void ShipPlacer(char tab[BoardSize][BoardSize]){
    int ShipsPlaced = 0;
    while (ShipsPlaced < ShipNum){

        printf("\nColoca tu barco %d de %d\n\n ", ShipsPlaced+1, ShipNum);
        
        int fila, columna;

        printf("Introduce una fila (elige del 0 - 4): ");
        scanf(" %d", &fila);

        printf("Introduce una columna (elige del 0 - 4): ");
        scanf(" %d", &columna);

        if (fila< 0 || fila >= BoardSize || columna < 0 || columna >= BoardSize || tab[fila][columna] == Ship){

            printf("\n¡ERROR! Las Coordenadas (%d, %d) están fuera del tablero o ya están ocupadas.\n", fila, columna);
            printf("Por favor, introduce valores entre 0 y 4.\n\n");

        }

        else{
            tab[fila][columna] = Ship;
            ClearScreen();
            BoardPrint(tab);
            ShipsPlaced++;
        }



    }

    printf("¡Todos los barcos se encuentran en posición! \n");
}


void EnemyPlacerShips(char tab[BoardSize][BoardSize]){
    int ShipsPlaced = 0;

    while (ShipsPlaced < ShipNum){

        int fila = rand() % BoardSize;
        int columna =  rand() % BoardSize;

        if (tab[fila][columna] == Water){

            tab[fila][columna] = Ship;
            ShipsPlaced++;
        }
    }
}

void StartBattle(char PlayerBoard[BoardSize][BoardSize], char EnemyBoard[BoardSize][BoardSize], char AttackBoard[BoardSize][BoardSize]){

    int PlayerHits = 0;
    int EnemyHits = 0;

    while(true){

        
        printf("Enemigo");
        BoardPrint(AttackBoard);
        printf(" --------------------------------------------------------\n");
        printf("Tu Flota:");
        BoardPrint(PlayerBoard);


        int fila, columna;
        printf("\n--- Tu turno ---");
        printf("\n¡Introduce las coordenadas para atacar, mi capitán!\n");
        printf("Introduce la fila (0-4): ");
        scanf(" %d", &fila);
        printf("Introduce la columna (0-4): ");
        scanf(" %d", &columna);


        if (fila < 0 || fila >= BoardSize || columna < 0 || columna >= BoardSize){
            ClearScreen();
            printf("\n¡ERROR! Las Coordenadas (%d, %d) están fuera del tablero.\n", fila, columna);
            printf("Por favor, introduce valores entre 0 y 4.\n\n");
            sleep(2);
            ClearScreen();
            continue;

       } else if (AttackBoard[fila][columna] != Water){
            ClearScreen();
            printf("\n¡ERROR! Ya disparaste en (%d, %d) antes.\n", fila, columna);
            sleep(2);
            ClearScreen();
            continue;
       } else{
            if (EnemyBoard[fila][columna] == Ship){
                printf("\n¡Golpe en (%d, %d)!\n", fila, columna);
                AttackBoard [fila][columna] = Hit;
                PlayerHits++;
                sleep(2);
            } else{
                printf("\n¡Le has dado al agua en (%d,%d)!\n", fila, columna );
                AttackBoard[fila][columna] = Miss;
                sleep(2);
            }
       }

       if (PlayerHits == ShipNum){
        printf("\n¡Felicidades! ¡Eres un gran soldado, has hundido toda la flota enemiga!");
        printf("\nTablero de Ataque Final:\n");
        BoardPrint(AttackBoard);
        sleep(2);
        break;
       }

       printf("\n--- Turno del enemigo ---\n");

        int fila_enemigo, columna_enemigo;

        do {
            fila_enemigo = rand() % BoardSize;
            columna_enemigo = rand() % BoardSize;
        } while (PlayerBoard[fila_enemigo][columna_enemigo] == Hit || PlayerBoard[fila_enemigo][columna_enemigo] == Miss);

        if (PlayerBoard[fila_enemigo][columna_enemigo] == Ship) {
            printf("¡El enemigo te ha dado un GOLPE en (%d, %d)!\n", fila_enemigo, columna_enemigo);
            PlayerBoard[fila_enemigo][columna_enemigo] = Hit; 
            EnemyHits++;
            sleep(2);
        } else {
            printf("¡El enemigo disparó en (%d, %d) pero no te ha dado!\n", fila_enemigo, columna_enemigo);
            PlayerBoard[fila_enemigo][columna_enemigo] = Miss;
            sleep(2);
        }

        if (EnemyHits == ShipNum) {
            printf("\n¡OH NO! El enemigo ha hundido todos tus barcos.\n");
            printf("--- Fin del Juego ---\n");
            printf("Este era tu tablero final:\n");
            BoardPrint(PlayerBoard);
            sleep(2);
            break;
        }
            
        ClearScreen();
    } 
}

int main(){
    ClearScreen();
    char PlayerBoard[BoardSize][BoardSize];
    char EnemyBoard[BoardSize][BoardSize];
    char AttackBoard[BoardSize][BoardSize];



    srand(time(NULL));
    BoardInitializer(PlayerBoard);
    BoardInitializer(EnemyBoard);
    BoardInitializer(AttackBoard);

    printf("-------------- ¡Bienvenido a Batalla Naval! ---------------\n");
    sleep(2);
    ClearScreen();
    printf("Este es tu tablero. Prepárate para colocar tus barcos.\n");
    BoardPrint(PlayerBoard);
    ShipPlacer(PlayerBoard);

    printf("\n-------------- ¡Tu flota está lista! ------------\n");
    sleep(2);
    ClearScreen();


    printf("\n\n\nEl enemigo está colocando sus barcos...\n\n\n");
    sleep(2);
    ClearScreen();
    EnemyPlacerShips(EnemyBoard);


    StartBattle(PlayerBoard, EnemyBoard, AttackBoard);

    return 0;
}
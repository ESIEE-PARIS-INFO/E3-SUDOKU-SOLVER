#include <stdio.h>

#include "sudoku.h"
#include "graphic.h"
#include <MLV/MLV_all.h>

/*
 * Initialise la grille de sudoku en mettant toutes les cases à 0
 * (0 représente une case vide)
 */
void initialize_empty_board(Board grid){
    int i;
    for(i=0; i<9; i++){
        int j;
        for(j=0; j<9; j++){
            grid[i][j] = 0;
        }
    }
}

/*
 * Affiche la grille de sudoku dans le terminal
 * (principalement utile pour le débogage)
 */
void print_board(Board grid){
    int i;
    for(i=0; i<9; i++){
        int j;
        for(j=0; j<9; j++){
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

/*
 * Vérifie si un nombre peut être placé à la position (row, col)
 * sans violer les règles du sudoku
 * Retourne 1 si le placement est valide, 0 sinon
 */
int is_valid(Board grid, int row, int col, int num){
    /* Vérification de la ligne */
    int i;
    for(i = 0; i < 9; i++)
        if(grid[row][i] == num)
            return 0;

    /* Vérification de la colonne */
    for(i = 0; i < 9; i++)
        if(grid[i][col] == num)
            return 0;

    /* Calcul de la position du bloc 3x3 */
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    /* Vérification du bloc 3x3 */
    for(i = 0; i < 3; i++){
        int j;
        for(j = 0; j < 3; j++){
            if(grid[startRow + i][startCol + j] == num)
                return 0;
        }
    }

    return 1;
}

/*
 * Vérifie si la partie est terminée
 * La partie est finie s'il n'y a plus aucune case vide
 */
int game_finished(Board b){
    int i;
    for(i=0; i<9; i++){
        int j;
        for(j=0; j<9; j++){
            if(b[i][j] == 0)
                return 0;
        }
    }
    return 1;
}

/*
 * Fonction principale du jeu
 * Gère l'affichage, les clics souris et les interactions du joueur
 */
/*
 * Fonction principale du jeu
 * Gère l'affichage, les clics souris et les interactions du joueur
 */
void play(Board b){
    int x, y, col, row;
    int running = 1;

    /* Affichage initial */
    load_board(b);
    draw_erase_button();
    MLV_update_window();

    while(running){

        MLV_wait_mouse(&x, &y);
        printf("Clic en x=%d y=%d\n", x, y);

        /* Vérifie que le clic est dans la grille */
        if(x >= 0 && x < 9*80 && y >= 0 && y < 9*80){
            col = x / 80;
            row = y / 80;

            printf("Case cliquée : row=%d col=%d\n", row, col);

            /* Le joueur ne peut jouer que sur une case vide */
            if(b[row][col] == 0){
                load_clavier();

                /* Affiche un "?" temporaire sur la case sélectionnée */
                MLV_draw_text(col*80 + 30, row*80 + 30, "?", MLV_COLOR_BLACK);
                MLV_update_window();

                int valid_click = 0;
                while(!valid_click){
                    MLV_wait_mouse(&x, &y);

                    /* Clic sur le clavier numérique */
                    if(x >= 10*80 && x < 13*80 && y >= 4*80 && y < 7*80){
                        int k_col = (x - 10*80) / 80;
                        int k_row = (y - 4*80) / 80;
                        int num = k_row * 3 + k_col + 1;

                        if(is_valid(b, row, col, num)){
                            b[row][col] = num;
                            printf("Placement valide : %d\n", num);
                        } else {
                            /* Feedback visuel en cas d'erreur */
                            MLV_draw_filled_rectangle(col*80, row*80, 80, 80, MLV_COLOR_RED);
                            MLV_update_window();
                            MLV_wait_milliseconds(500);
                        }

                        valid_click = 1;
                    }

                    /* Clic sur le bouton effacer */
                    if(x >= 10*80 && x < 13*80 && y >= 7*80 && y < 8*80 + 240){
                        b[row][col] = 0;
                        valid_click = 1;
                    }
                }

                /* Rafraîchissement après modification */
                MLV_draw_filled_rectangle(10*80, 4*80, 240, 240, MLV_COLOR_BLACK);
                load_board(b);
                draw_erase_button();
                MLV_update_window();
            }
        }

        /* Fin de la partie */
        if(game_finished(b)){
            running = 0;
        }
    }
}


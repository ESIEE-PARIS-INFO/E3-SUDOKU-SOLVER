#include <MLV/MLV_all.h>

#include "graphic.h"
#include "sudoku.h"

/*
 * Dessine la grille du sudoku et affiche les chiffres déjà placés
 */
void load_board(Board b){
    int row, col;
    char cell_value[2];
    
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            int x = col * 80;
            int y = row * 80;

            /* Dessin du fond de la case */
            MLV_draw_filled_rectangle(x, y, 80, 80, MLV_COLOR_WHITE);

            /* Dessin du contour de la case */
            MLV_draw_rectangle(x, y, 80, 80, MLV_COLOR_GRAY);
            
            /* Affichage du chiffre uniquement si la case n'est pas vide */
            if (b[row][col] != 0) {
                sprintf(cell_value, "%d", b[row][col]);
                MLV_draw_text(x + 30, y + 30, cell_value, MLV_COLOR_BLACK);
            }
        }
    }
}

/*
 * Affiche le clavier numérique permettant au joueur
 * de choisir un chiffre entre 1 et 9
 */
void load_clavier(){
    int row, col;
    char cell_value[2];
    int i = 1;

    /* Parcours des cases du clavier (3x3) */
    for (row = 4; row < 7; row++){
        for(col = 10; col < 13; col++){
            int x = col * 80;
            int y = row * 80;

            MLV_draw_filled_rectangle(x, y, 80, 80, MLV_COLOR_WHITE);
            MLV_draw_rectangle(x, y, 80, 80, MLV_COLOR_GRAY);

            /* Affichage du chiffre correspondant */
            sprintf(cell_value, "%d", i++);
            MLV_draw_text(x + 30, y + 30, cell_value, MLV_COLOR_BLACK);
        }
    }
}

/*
 * Dessine le bouton permettant d'effacer
 * la valeur d'une case sélectionnée
 */
void draw_erase_button() {
    MLV_draw_filled_rectangle(10*80, 7*80, 240, 80, MLV_COLOR_GRAY);
    MLV_draw_rectangle(10*80, 7*80, 240, 80, MLV_COLOR_BLACK);

    /* Texte centré dans le bouton */
    MLV_draw_text_box(
        10*80, 7*80,
        240, 80,
        "ANNULER",
        20,
        MLV_COLOR_BLACK,
        MLV_COLOR_WHITE,
        MLV_COLOR_GRAY,
        MLV_TEXT_CENTER,
        MLV_HORIZONTAL_CENTER,
        MLV_VERTICAL_CENTER
    );
}

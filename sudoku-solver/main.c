#include <stdio.h>

#include "sudoku.h"
#include "in_out.h"
#include "graphic.h"
#include <stdlib.h>
#include <time.h>
#include <MLV/MLV_all.h>

/*
 * Fonction principale du programme
 * Initialise le jeu, charge la grille et lance la partie
 */
int main(int argc, char* argv[]){
    /* Vérification de la présence du fichier en argument */
    if(argc < 2){
        printf("Usage : %s fichier_grille\n", argv[0]);
        return 1;
    }

    /* Initialisation du générateur de nombres aléatoires */
    srand(time(NULL));

    Board B;

    /* Lecture de la grille depuis le fichier passé en argument */
    fread_board(argv[1], B);

    /* Création de la fenêtre graphique */
    MLV_create_window("Sudoku", "sudoku.png", 1200, 800);

    /* Affichage initial de la grille */
    load_board(B);

    /* Zone noire réservée à l'affichage du clavier numérique */
    MLV_draw_filled_rectangle(10*80, 4*80, 240, 240, MLV_COLOR_BLACK);

    MLV_update_window();

    /* Lancement de la boucle principale du jeu */
    play(B);

    /* Libération des ressources graphiques */
    MLV_free_window();

    return 0;
}

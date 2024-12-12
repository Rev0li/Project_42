/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okientzl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:41:45 by okientzl          #+#    #+#             */
/*   Updated: 2024/12/12 14:44:45 by okientzl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars {
    void    *mlx;       // Pointeur vers l'instance MLX
    void    *win;       // Pointeur vers la fenêtre
    int     drawing;    // Booléen pour savoir si on dessine ou pas
}               t_vars;

// Fonction pour gérer les événements de souris (clic enfoncé)
int mouse_press(int button, int x, int y, t_vars *vars)
{
    printf("Mouse_press exe (%d, %d)\n", x, y);
    if (button == 1)  // Clic gauche enfoncé
    {
        vars->drawing = 1;
        printf("Mouse pressed at (%d, %d)\n", x, y);
    }
    return (0);
}

// Fonction pour gérer les événements de souris (clic relâché)
int mouse_release(int button, int x, int y, t_vars *vars)
{
    printf("Mouse_release exe (%d, %d)\n", x, y);
    if (button == 1)  // Clic gauche relâché
    {
        vars->drawing = 0;
        printf("Mouse released at (%d, %d)\n", x, y);
    }
    return (0);
}

// Fonction pour dessiner en continu lorsque le clic est maintenu
int mouse_move(int x, int y, t_vars *vars)
{
    printf("mouse_move exe (%d, %d)\n", x, y);
    if (vars->drawing)
    {
        mlx_pixel_put(vars->mlx, vars->win, x, y, 0xFFFFFF);  // Dessine un pixel blanc
        printf("Drawing at (%d, %d)\n", x, y);
    }
    return (0);
}

// Fonction pour gérer la fermeture de la fenêtre
int close_window(t_vars *vars)
{
    printf("Window closed. Goodbye!\n");
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

int main(void)
{
    t_vars vars;

    // Initialisation de MLX et création de la fenêtre
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 800, 600, "Draw like Paint");
    vars.drawing = 0;  // Initialisation de l'état de dessin à faux

    // Hooks pour les événements de souris avec les masques appropriés
    mlx_hook(vars.win, 4, ButtonPressMask, mouse_press, &vars);         // ButtonPress
    mlx_hook(vars.win, 5, ButtonReleaseMask, mouse_release, &vars);     // ButtonRelease
    mlx_hook(vars.win, 6, PointerMotionMask, mouse_move, &vars);        // MotionNotify

    // Hook pour fermer la fenêtre proprement avec le bouton X
    mlx_hook(vars.win, 17, StructureNotifyMask, close_window, &vars);   // DestroyNotify

    // Boucle principale de MLX
    mlx_loop(vars.mlx);
}


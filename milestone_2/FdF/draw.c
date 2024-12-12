#include "mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 1200
#define HEIGHT 1000
#define PALETTE_WIDTH 50
#define PALETTE_HEIGHT 300

typedef struct s_vars {
    void    *mlx;
    void    *win;
    int     drawing;
    int     color;
    int     eraser_mode;
    int     prev_x;
    int     prev_y;
}               t_vars;

// Couleurs de la palette
int colors[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFFF00, 0xFF00FF, 0x00FFFF, 0xFFFFFF, 0x000000};
int num_colors = sizeof(colors) / sizeof(colors[0]);

// Fonction pour dessiner une ligne avec l'algorithme de Bresenham
void draw_line(t_vars *vars, int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1)
    {
        mlx_pixel_put(vars->mlx, vars->win, x0, y0, vars->eraser_mode ? 0x000000 : vars->color);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }
}

// Fonction pour dessiner la palette de couleurs à gauche
void draw_palette(t_vars *vars)
{
    int rect_height = PALETTE_HEIGHT / num_colors;

    for (int i = 0; i < num_colors; i++)
    {
        for (int y = i * rect_height; y < (i + 1) * rect_height; y++)
        {
            for (int x = 0; x < PALETTE_WIDTH; x++)
            {
                mlx_pixel_put(vars->mlx, vars->win, x, y, colors[i]);
            }
        }
    }
}

// Fonction pour gérer les événements de souris (clic enfoncé)
int mouse_press(int button, int x, int y, t_vars *vars)
{
    if (button == 1) // Clic gauche enfoncé
    {
        if (x < PALETTE_WIDTH && y < PALETTE_HEIGHT) // Sélection de la couleur dans la palette
        {
            int rect_height = PALETTE_HEIGHT / num_colors;
            int index = y / rect_height;
            vars->color = colors[index];
            vars->eraser_mode = (index == num_colors - 1);
        }
        else // Zone de dessin
        {
            vars->drawing = 1;
            vars->prev_x = x;
            vars->prev_y = y;
            mlx_pixel_put(vars->mlx, vars->win, x, y, vars->eraser_mode ? 0x000000 : vars->color);
        }
    }
    return (0);
}

// Fonction pour gérer les événements de souris (clic relâché)
int mouse_release(int button, int x, int y, t_vars *vars)
{
    if (button == 1) // Clic gauche relâché
    {
        vars->drawing = 0;
    }
    return (0);
}

// Fonction pour dessiner en continu lorsque le clic est maintenu
int mouse_move(int x, int y, t_vars *vars)
{
    if (vars->drawing && x >= PALETTE_WIDTH)
    {
        draw_line(vars, vars->prev_x, vars->prev_y, x, y);
        vars->prev_x = x;
        vars->prev_y = y;
    }
    return (0);
}

// Fonction pour gérer la fermeture de la fenêtre
int close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
}

int main(void)
{
    t_vars vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Draw with Continuous Lines");
    vars.drawing = 0;
    vars.color = 0xFFFFFF; // Blanc par défaut
    vars.eraser_mode = 0;

    draw_palette(&vars); // Dessine la palette au lancement

    // Hooks pour les événements de souris
    mlx_hook(vars.win, 4, ButtonPressMask, mouse_press, &vars);
    mlx_hook(vars.win, 5, ButtonReleaseMask, mouse_release, &vars);
    mlx_hook(vars.win, 6, PointerMotionMask, mouse_move, &vars);

    // Hook pour fermer la fenêtre proprement avec le bouton X
    mlx_hook(vars.win, 17, StructureNotifyMask, close_window, &vars);

    mlx_loop(vars.mlx);
}


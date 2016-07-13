
/*
** clang ./libftprintf/libftprintf.a ncurses_vm.c -I ./libftprintf/ -lncurses -lm
*/


#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <curses.h>
#include <math.h>
#include <signal.h>
#include "vm.h"
#include "vm_struct.h"

//#include "ft_printf.h"

#ifndef MEM_SIZE
# define MEM_SIZE (4*1024)
#endif

typedef struct	s_n
{
	WINDOW *win;
	int **map;
	int size;
	int hauteur;
	int largeur;
	int xmax;
	int ymax;
}				t_n;

//void ncurses_map_draw(WINDOW *win, int **map, int hauteur, int largeur);
void ncurses_map_draw(WINDOW *win, t_vm_data *arena, int hauteur, int largeur);
void ncurses_border_draw(int xmax, int ymax);
void ncurses_menu_draw(t_vm_data *arena);


void ft_error(char *str)
{
	// replacer par ft_printf
	printf("ERROR: %s\n", str);
	//
	exit(0);
}

void resize_handler(int sig)
{
	int hauteur;
	int largeur;
	int tmp;

	(void)sig;
	getmaxyx(stdscr, hauteur, largeur);
	if (hauteur < 60 && largeur < 400)
	{
		while (hauteur >= 0)
		{
			tmp = largeur;
			while (largeur >= 0)
			{
				mvprintw(hauteur, largeur, " ");
				largeur--;
			}
			largeur = tmp;
			hauteur--;
		}
	}
}

int **ncurses_map_init(void)
{
	// init map
	int i;
	int **map;

	map = (int **)malloc(sizeof(int *) * MEM_SIZE + 1);
	i = 0;
	if (!map)
		ft_error("Erreur en initialisant la map.");
	while (i < MEM_SIZE)
	{
		map[i] = (int *)malloc(sizeof(int) * MEM_SIZE);
		if (!map[i])
			ft_error("Erreur en initialisant la map.");

		// rempli la map avec des zeros
		*map[i] = 0x00;
		i++;
	}
	// DEBUG
	*map[MEM_SIZE / 2] = 0x01;
	//
	map[i] = NULL;
	return (map);
}

void ncurses_border_draw(int xmax, int ymax)
{
	int i;
	getmaxyx(stdscr, ymax, xmax);


	// couleur grise
	attron(COLOR_PAIR(42));

	// bordure de gauche
	i = -1;
	while (++i < ymax)
		mvprintw(i, 0, "|");
	// bordure de droite
	i = -1;
	while (++i < ymax)
		mvprintw(i, xmax - 1, "|");
	// bordure du milieu
	i = -1;
	while (++i < ymax)
		mvprintw(i, (64 * 3) + 4, "|");
	// bordure du haut
	i = -1;
	while (++i < xmax)
		mvprintw(0, i, "-");
	// bordure du bas
	i = -1;
	while (++i < xmax)
		mvprintw(ymax - 1, i, "-");
	// bordure du bas de l'arene
	i = -1;
	while (++i < (64 * 3) + 4)
		mvprintw(64 + 3, i, "-");


	// retour couleur normale
	attron(COLOR_PAIR(21));

}

void ncurses_livebreakdown_progressbar_current(void)
{
	int i;

	// variables pourcentages de test
	int p1 = 25;
	int p2 = 50;
	int p3 = 5;
	int p4 = 10;
	int p5 = 5;
	int p6 = 5;

	(void)p1;
	(void)p2;
	(void)p3;
	(void)p4;
	(void)p5;
	(void)p6;
	//

	i = 0;
	while (i < 50)
	{
		if (i < p1 / 2)
			attron(COLOR_PAIR(2));
		else if (i < (p1 + p2) / 2)
			attron(COLOR_PAIR(4));
		else if (i < (p1 + p2 + p3) / 2)
			attron(COLOR_PAIR(6));
		else if (i < (p1 + p2 + p3 + p4) / 2)
			attron(COLOR_PAIR(8));
		else if (i < (p1 + p2 + p3 + p4 + p5) / 2)
			attron(COLOR_PAIR(10));
		else
			attron(COLOR_PAIR(77));
		mvprintw(64 + 10, 129 + i, "-");
		attron(COLOR_PAIR(21));
		i++;
	}

}
void ncurses_livebreakdown_progressbar_last(void)
{

	int i;

	// variables pourcentages de test
	int p1 = 25;
	int p2 = 75;
	int p3 = 0;
	int p4 = 25;
	int p5 = 0;
	int p6 = 0;

	(void)p1;
	(void)p2;
	(void)p3;
	(void)p4;
	(void)p5;
	(void)p6;
	//




	i = 0;
	while (i < 50)
	{
		if (i < p1 / 2)
			attron(COLOR_PAIR(2));
		else if (i < (p1 + p2) / 2)
			attron(COLOR_PAIR(4));
		else if (i < (p1 + p2 + p3) / 2)
			attron(COLOR_PAIR(6));
		else if (i < (p1 + p2 + p3 + p4) / 2)
			attron(COLOR_PAIR(8));
		else if (i < (p1 + p2 + p3 + p4 + p5) / 2)
			attron(COLOR_PAIR(10));
		else
			attron(COLOR_PAIR(77));
		mvprintw(64 + 13, 129 + i, "-");
		attron(COLOR_PAIR(21));
		i++;
	}

}

void ncurses_menu_livebreakdown(void)
{
	attron(COLOR_PAIR(77));
	mvprintw(64 + 9, 128, "%s", "Live breakdown for current period :                 ");
	attron(COLOR_PAIR(21));
	mvprintw(64 + 10, 128, "%s", "[--------------------------------------------------]");
	ncurses_livebreakdown_progressbar_current();
	attron(COLOR_PAIR(77));
	mvprintw(64 + 12, 128, "%s", "Live breakdown for last period :                    ");
	attron(COLOR_PAIR(21));
	mvprintw(64 + 13, 128, "%s", "[--------------------------------------------------]");
	ncurses_livebreakdown_progressbar_last();
	attron(COLOR_PAIR(21));
}

int		nb_of_processes_all_players(t_vm_data *arena)
{
	int			nb_processes;
	int			i;
	t_player	*tmp_playershead;

	i = 0;
	nb_processes = 0;
	tmp_playershead = arena->players;
	while (i < arena->number_of_players)
	{
		if (arena->players != NULL && arena->players->still_in_game != 0)
			nb_processes += arena->players->number_of_process;
		arena->players = arena->players->next;
		i++;
	}
	arena->players = tmp_playershead;
	return (nb_processes);
}

void ncurses_menu_draw(t_vm_data *arena)
{
	// couleur blanc flashy
	attron(COLOR_PAIR(77));

	mvprintw(64 + 5, 90, "%s", "                          ");
	if (arena->pause)
		mvprintw(64 + 5, 90, "%s", "**  PAUSE  **");
	else
		mvprintw(64 + 5, 90, "%s", "** RUNNING **");

	mvprintw(64 + 9, 77, "%s", "                          ");
	mvprintw(64 + 9, 77, "Cycles par seconde : %i", 77);

	mvprintw(64 + 11, 77, "%s", "                          ");
	mvprintw(64 + 11, 77, "Cycle actuel : %i", arena->cycles);

	mvprintw(64 + 13, 77, "%s", "                          ");
	mvprintw(64 + 13, 77, "Processus : %i", nb_of_processes_all_players(arena));

	mvprintw(64 + 9, 7, "%s", "                          ");
	mvprintw(64 + 9, 7, "CYCLE_TO_DIE : %i", arena->cycles_to_die);

	mvprintw(64 + 11, 7, "%s", "                          ");
	mvprintw(64 + 11, 7, "CYCLE_DELTA : %i", arena->cycle_delta);

	mvprintw(64 + 13, 7, "%s", "                          ");
	mvprintw(64 + 13, 7, "NBR_LIVE : %i", arena->nbr_live);

	mvprintw(64 + 15, 7, "%s", "                          ");
	mvprintw(64 + 15, 7, "MAX_CHECK : %i", arena->max_checks);

	mvprintw(64 + 15, 128, "%s", "                          ");
	mvprintw(64 + 15, 7, "MAX_CHECK : %i", arena->max_checks);

	ncurses_menu_livebreakdown();

	attron(COLOR_PAIR(21));
}

void ncurses_map_draw_case_color(t_vm_data *arena, char *valeur, int joueur, int current_block)
{
	int case_owner;

	case_owner = arena->process_field[current_block];
	// active la couleur du joueur si la case est possedee
	// LE POINTEUR COLOR_FIELD NEST PAS MISE A JOUR POUR LES 'LIVE'
	// (ET LE RESTE SUREMENT...)
	if (joueur != 0)
	{
		// UN LIVE EST PRESENT ET VIENT D'ETRE EXECUTE
		// SURBRILLANCE
		// PROCESS FIELD NEST PAS BIEN REMPLI
		if (valeur[0] == '0' && valeur[1] == '1' && case_owner == joueur)
			attron(COLOR_PAIR((joueur * 2) - 1));
		// PAS LIVE
		// COULEUR NORMALE DU JOUEUR
		else
			attron(COLOR_PAIR((joueur * 2) + 0));
	}
	// si la case n'appartient a personne
	// ecrit en gris
	else
		attron(COLOR_PAIR(21));
}

void ncurses_map_draw(WINDOW *win, t_vm_data *arena, int hauteur, int largeur)
{
	static char *hexa = "0123456789abcdef";
	int current_block;
	int x;
	int y;

	(void)win;
	current_block = 0;
	y = 2;
	while (y <= hauteur)
	{
		x = 3;
		while (x <= largeur * 3)
		{

			// parcours la map
			int	 joueur;
			char valeur[2];
			int nb_processes;

			joueur = 0;
			nb_processes = 0;

			// recupere la valeur de la case
			if (current_block < MEM_SIZE)
			{
//				valeur[0] = 'T';
//				valeur[1] = 'T';
				valeur[0] = hexa[arena->field[current_block] / 16];
				valeur[1] = hexa[arena->field[current_block] % 16];
				joueur = arena->color_field[current_block];
			}
			else
			{
				valeur[0] = ' ';
				valeur[1] = ' ';
			}

			// selection de la couleur de la case
			ncurses_map_draw_case_color(arena, valeur, joueur, current_block);

			// imprime la valeur
			mvprintw(y, x, "%c%c", valeur[0], valeur[1]);
			x += 2;

			// desactive la couleur du joueur
			attron(COLOR_PAIR(21));

			// separateur (whitespace)
			mvprintw(y, x, " ");
			x++;

			current_block++;
		}
		y++;
	}
}

void ncurses_color_init(void)
{
	start_color();
	init_color(COLOR_RED, 777, 0, 0);
	init_color(COLOR_GREEN, 0, 777, 0);
	init_color(COLOR_BLUE, 0, 0, 777);
	init_color(COLOR_BLACK, 0, 0, 0);
	init_color(COLOR_WHITE, 999, 999, 999);
	init_color(COLOR_CYAN, 420, 420, 420); // GREY

	init_pair(1,  COLOR_WHITE, COLOR_RED);
	init_pair(2,  COLOR_RED, COLOR_BLACK);

	init_pair(3,  COLOR_WHITE, COLOR_GREEN);
	init_pair(4,  COLOR_GREEN, COLOR_BLACK);

	init_pair(5,  COLOR_WHITE, COLOR_YELLOW);
	init_pair(6,  COLOR_YELLOW, COLOR_BLACK);

	init_pair(7,  COLOR_WHITE, COLOR_BLUE);
	init_pair(8,  COLOR_BLUE, COLOR_BLACK);

	init_pair(9,  COLOR_WHITE, COLOR_MAGENTA);
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);

	init_pair(21, COLOR_CYAN, COLOR_BLACK);
	init_pair(42, COLOR_CYAN, COLOR_CYAN);
	init_pair(77, COLOR_WHITE, COLOR_BLACK);
}

void ncurses_init(WINDOW **win, int ***map)
{
	// init rand var
	srand(time(NULL));

	// init NCURSES
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	// init colors
	ncurses_color_init();

	// init NCURSES
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	// init map
	*map = ncurses_map_init();

	// window init
	*win = newwin(70 + 2, ((64 * 3) * 2) + 2, 1, 1);

}

void ncurses_loop(WINDOW *win, t_vm_data *arena, int **map)
{
	int largeur = 64;
	int hauteur = 70;

	int ch;

	arena->pause = 1;
	(void)map;
	nodelay(stdscr, TRUE);
	while (1337)
	{
		// KEYBOARD INPUT
		ch = getch();
		if (ch == KEY_BACKSPACE)
			break;
		else if (ch == ' ')
			arena->pause ^= 1;



		if (arena->graph && !arena->pause)
		{
			//refresh_fresh_field(arena);
			arena->cycles++;
			increment_waiting_time(arena);
			check_instruction_from_proc(arena);
			execute_instruction(arena);
			//if (arena->dump && arena->cycles % arena->cycles_to_dump == 0)
			//	dump(arena);
			//if (arena->loop_dump && arena->cycles % arena->cycles_to_loop_dump
			//	== 0)
			//	dump_and_wait(arena);
//          if (arena->graph)
//              display_graphic(arena); // add un sleep dedans + faire un clear du screen;
			if (arena->cycles == arena->next_cycle_check)
				if (!is_someone_alive(arena))
					break ;
		}

//		printf("%d\n", arena->cycles);

//		ncurses_map_draw(win, map, hauteur, largeur);
		ncurses_map_draw(win, arena, hauteur, largeur);
		ncurses_menu_draw(arena);
		ncurses_border_draw(hauteur, largeur);
		wrefresh(win);
	}
}

void ncurses_free(int **map)
{
	// close NCURSE
	endwin();
	free(map);
}


void ncurses_play(t_vm_data *arena)
{
	WINDOW *win;
	int **map;

	set_players_in_game(arena);
	// se declenche lors du resize de la window
	signal(SIGWINCH, resize_handler);




	// ncurses behavior
	ncurses_init(&win, &map);
	ncurses_loop(win, arena, map);
	ncurses_free(map);
}

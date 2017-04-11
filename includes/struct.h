/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmoreaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:58:13 by qmoreaux          #+#    #+#             */
/*   Updated: 2016/12/15 14:44:04 by rfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "op.h"
# define POS players[0]->instance[inu[1]]->program_control
# define POS2 players[0]->instance[n]->program_control
# define ARGCODE unsigned int op_arg[4], unsigned char codage
# define SAVEOP players[0]->instance[inu[1]]->save_op
# define CUBE 256*256*256
# define CARRE 256*256
# define ALIVE players[0]->instance[inu[1]]->is_alive

typedef struct	s_proce
{
	char			**reg;
	int				carry;
	int				program_control;
	int				cycle;
	int				is_alive;
	int				last_op_live;
	unsigned char	*save_op;
}				t_proce;

typedef struct	s_joueur
{
	char	*name;
	char	*comment;
	int		num_joueur;
	int		nb_live_total;
	int		nb_live_current_cycle;
	int		last_live;
	int		nb_instance;
	int		cycle;
	int		weight;
	int		last_alive;
	t_proce **instance;
}				t_joueur;

typedef struct	s_state
{
	int	nbr_live;
	int	cycle_to_check;
	int	nb_check;
}				t_state;

typedef struct	s_env
{
	int				cycle;
	int				nb_player;
	unsigned char	*memory;
	t_joueur		**champion;
	int				num_instance;
}				t_env;

unsigned char	*parsing(t_joueur **players, unsigned char *memory, \
	int nbp, int dumb);
int				nb_arg(unsigned char *str);
void			live(unsigned char *memory);
char			*get_comment(int fd);
char			*get_name(int fd);
unsigned char	*resize(unsigned char *instruct, unsigned char *str, \
	int nb, int i);
unsigned char	*save_instruct(t_joueur **players, unsigned char *instruct,
				int i, int num);
unsigned char	*skip_zero(int fd, unsigned char *str);
unsigned char	*print_memory(unsigned char *memory);
int				init_player(t_joueur **players, int n, int fd);
int				flag_n(t_joueur **players, int *in, char **argv, int argc);
void			check_num_available(t_joueur **players, int n);
unsigned char	*get_players(t_joueur **players, char **argv, int *in, \
				int argc);
int				count_param(char **argv, int argc);
unsigned char	*get_instruct(t_joueur **players, int fd, int num);
unsigned int	*get_op_arg_2(unsigned char *str, unsigned int *params);
unsigned int	*get_op_arg(unsigned char *str);
void			split_moove(t_joueur **players, int *inu, unsigned char *memory,
		int (**execute_op)(t_env *env, int num_player, unsigned int op_args[4],
			unsigned char codage));
int				get_nb_cycle(char c);
void			moove_parseur(t_joueur **players, unsigned char *memory,
		int nbp, int (**execute_op)(t_env *env, int num_player,
			unsigned int op_args[4], unsigned char codage));
int				check_live(t_joueur **players, t_state *state, int nbp);
int				check_alive(t_joueur **players, int nbp);
void			init_program_control(t_joueur **players, int nbp);
int				get_codage(unsigned char *str);
t_env			*create_env(t_joueur **players, unsigned char *memory, \
	int nbp, int n);
int				error(unsigned char *str);
void			who_won(t_joueur **players, int nbp);
void			introduce_players(t_joueur **players, int nbp);
void			ft_cpymem(unsigned char *dst, unsigned char *src, int pos);
int				nb_skip(unsigned char op, unsigned char c);
void			check_instruct(t_joueur **players, unsigned char *memory, \
	int nbp, int n);
int				start_init(t_joueur **players, int n, int fd);
unsigned char	*start_recup_players(int *fd);
int				*reset_recup(int *in, int *fd, unsigned char *str);

void			recup_111(unsigned char *str, unsigned int *params);
void			recup_122(unsigned char *str, unsigned int *params);
void			recup_112(unsigned char *str, unsigned int *params);
void			recup_41(unsigned char *str, unsigned int *params);
void			recup_21(unsigned char *str, unsigned int *params);
void			recup_11(unsigned char *str, unsigned int *params);
void			recup_12(unsigned char *str, unsigned int *params);
void			recup_221(unsigned char *str, unsigned int *params);
void			recup_241(unsigned char *str, unsigned int *params);
void			recup_211(unsigned char *str, unsigned int *params);
void			recup_421(unsigned char *str, unsigned int *params);
void			recup_441(unsigned char *str, unsigned int *params);
void			recup_141(unsigned char *str, unsigned int *params);
void			recup_411(unsigned char *str, unsigned int *params);
void			recup_121(unsigned char *str, unsigned int *params);

#endif

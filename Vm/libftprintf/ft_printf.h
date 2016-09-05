/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamouda <ahamouda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 03:19:22 by ahamouda          #+#    #+#             */
/*   Updated: 2016/09/05 07:15:14 by ahamouda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>
# include <pwd.h>
# include <errno.h>
# include <sys/acl.h>
# include <termios.h>
# include <curses.h>
# define BUFF_SIZE 4096

# define ANSI_RESET			"\x1b[0m"
# define ANSI_BOLD			"\x1b[1m"
# define ANSI_UNDERLIGNED	"\x1b[4m"
# define ANSI_REVERSE_COLOR	"\x1b[7m"

# define ANSI_FG_RED		"\x1b[31m"
# define ANSI_FG_GREEN		"\x1b[32m"
# define ANSI_FG_YELLOW		"\x1b[33m"
# define ANSI_FG_BLUE		"\x1b[34m"
# define ANSI_FG_MAGENTA	"\x1b[35m"
# define ANSI_FG_CYAN		"\x1b[36m"
# define ANSI_FG_WHITE		"\x1b[37m"

# define ANSI_FG_STANDART	"\x1b[39m"

# define ANSI_BG_RED		"\x1b[41m"
# define ANSI_BG_GREEN		"\x1b[42m"
# define ANSI_BG_YELLOW		"\x1b[43m"
# define ANSI_BG_BLUE		"\x1b[44m"
# define ANSI_BG_MAGENTA	"\x1b[45m"
# define ANSI_BG_CYAN		"\x1b[46m"
# define ANSI_BG_WHITE		"\x1b[47m"

# define ANSI_BG_STANDART	"\x1b[40m"

typedef	enum		e_fg_color
{
	FG_RED,
	FG_GREEN,
	FG_YELLOW,
	FG_BLUE,
	FG_MAGENTA,
	FG_CYAN,
	FG_WHITE,
	FG_NO
}					t_fg_color;

typedef	enum		e_bg_color
{
	BG_RED,
	BG_GREEN,
	BG_YELLOW,
	BG_BLUE,
	BG_MAGENTA,
	BG_CYAN,
	BG_WHITE,
	BG_NO
}					t_bg_color;

typedef	enum		e_special
{
	RESET,
	BOLD,
	UNDERLIGNED,
	REVERSE_COLOR,
	FG_STANDART,
	BG_STANDART,
	SCREEN_CLEAR,
	SPE_NO
}					t_special;

typedef struct		s_flags
{
	char			type;
	char			sign;
	int				nb_max_char;
	int				i;
	int				nb_c_written;
	int				nb_min_char;
	int				plus;
	int				minus;
	int				space;
	int				zero;
	char			precision[10];
	char			min_area_size[10];
	char			is_min_area_size_here;
	char			is_precision_here;
	char			sub_specifier[2];
	t_fg_color		fg_color;
	t_bg_color		bg_color;
	t_special		special;
	char			reset_fg;
	char			reset_ansi;
	char			reset_bg;
	int				hash;
	char			star;
	char			dot_star;
	char			*converted_number;
	char			*tmp_conv_nb;
}					t_flags;

typedef struct		s_info
{
	int				nb_c_written;
	int				nb_c_needed;
	char			*tmp;
	char			*tmp_second;
	char			*tmp_third;
	char			*converted_string;
}					t_info;

int					ft_printf(char *format, ...);
int					ft_printf_fd(int fd, char *format, ...);
char				*ft_printf_str(int *len, char *format, va_list vb);
int					ft_printf_buffed(int flush, char *format, ...);

int					display(char *str, va_list *va, t_info *list);
char				*display_var(char *str, va_list *va, t_info *list);
void				display_final(t_flags *flag, va_list *va, t_info *list);

void				display_spe_var(t_flags *flag, va_list *va, t_info *list);
void				display_alpha_var(t_flags *flag, va_list *va, t_info*list);
void				display_numeric_var(t_flags *flag, va_list *va,
		t_info *list);

int					is_alphabetic_type(char c);
int					is_special_type(char c);
int					is_a_sub_specifier(char c);
int					is_a_valid_type(char c);
int					is_a_good_flag_or_type(char *s);

void				set_to_zero(t_flags *current_flag);
t_flags				*init_flags(void);

char				*ft_printf_check_flags(t_flags *flag, char *s, va_list *va,
		t_info *lst);

char				*apply_fg(char *s, t_info *list);

char				*apply_bg(char *s, t_info *list);

char				*apply_special(char *s, t_flags *flag, t_info *list);
void				apply_spe_after(t_flags *flag, t_info *list);

char				*itoa_base(void *x, int base, t_flags *flag);

void				bufferjoin(t_info *list, char *str, int len);

void				bufferujoin(t_info *list, int c);

int					uc_to_str(t_info *list, int c);

void				*cast_normal_integer(t_flags *flag, void *x);

void				get_nb_min_char(t_flags *flag, char *str);

void				print_char(t_flags *flag, t_info *list);

void				print_normal_char(va_list *va, t_flags *flag, t_info *list);

void				print_unicode_char(va_list *va, t_flags *flag,
		t_info *list);

void				print_normal_integer(va_list *va, t_flags *flag,
		t_info *list);

void				print_pointer(t_flags *flag, va_list *va, t_info *list);

void				print_binary(t_flags *flag, va_list *va, t_info *list);

void				print_int_tab(va_list *va, t_info *list);

void				print_str_tab(va_list *va, t_info *list);

void				print_normal_string(va_list *va, t_flags *flag,
		t_info *list);

void				print_unicode_string(va_list *va, t_flags *flag,
		t_info *list);

void				stock_n(va_list *va, t_flags *flag, t_info *list);

int					get_unicode_len(int c);

void				*get_sign(void *x, t_flags *flag);

char				*get_zero_or_space_or_hash(t_flags *flag, char *str);
char				*get_operator(t_flags *flag, char *str);
char				*get_precision(t_flags *flag, char *str);
char				*get_min_area_size(t_flags *flag, char *str);

char				*get_sub_specifier(t_flags *flag, char *str);

char				*get_type(t_flags *flag, char *str);

char				*get_dot_star(t_flags *flag, char *str, va_list *va);
char				*get_star(t_flags *flag, char *str, va_list *va);

char				*get_ansi_code(t_flags *flag, char *str, t_info *list);

void				reset_min_area_size(t_flags *flag);
void				reset_precision(t_flags *flag);

int					ft_strnocasencmp(const char *s1, const char *s2, int n);
int					ft_strnocasecmp(const char *s1, const char *s2);
int					ft_strxcmp(const char *s1, const char *s2, int n);
void				*ft_memset(void *s, int c, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strcat(char *dest, const char *src);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
void				ft_putstr(char *s);
int					ft_isspace(int c);
int					ft_atoi(const char *nptr);
char				*ft_strdup(const char *s);
int					ft_isdigit(int c);
void				ft_putendl(char const *s);
void				ft_malloc_error(void);
size_t				ft_strxlen(const char *s, char c);
size_t				ft_stmrxlen(const char *s, char *c);
size_t				ft_strslen(const char *s, char *to_find);

int					get_nb_c(char *s, char c);

char				*ftprintf_strjoin(t_info *list, char *s, int s2_len);
char				*ftprintf_strndup(const char *s, int n);
char				*ftprintf_strncpy_cat(char *ns, t_info *list, char *s,
		int len);

void				*byte_swap(void *toswap, size_t size);

int					ft_strmchr(char *s, char *to_find);

int					ft_strnmchr(char *s, char *to_find, int l);

char				*ft_strnjoin(char const *s1, char const *s2, int n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
int					get_next_line(int const fd, char **line);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s, const char *s_to_find);
char				*ft_strnstr(const char *s, const char *s_to_find, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_and_free(char *s1, const char *s2);
char				*ft_strjoinsep(const char *s1, const char *s2, char sep);
char				*ft_strjoinsep_and_free(char *s1, const char *s2, char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strclr(char *s);
char				*ft_itoa(int n);
void				ft_strmrepl(char *src, char *to_find, char c);
char				*ft_strrepl(char *src, char to_find, char c);
char				*ft_strrev(char *s);
int					ft_sqrt(int nb);
char				*ft_strndup(const char *s, int n);
char				*ft_strxdup(const char *s, char c);
int					ft_fctrl(int nb);
void				ft_screenclr(void);

void				ft_error(char *str);

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_rec_putnbr(int n);

int					ft_is_str_digit(char *s);
int					ft_is_str_space(char *s);
int					ft_is_str_blank(char *s);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isblank(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_ispunct(int c);
int					ft_isupper(int c);
int					ft_isxdigit(int c);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *to_add);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstpush(t_list **alst, t_list *to_push);
void				ft_lstcswap(t_list *lst1, t_list *lst2);

typedef struct		s_gnl
{
	int				fd;
	char			*buffer;
	int				start;
	int				end;
	struct s_gnl	*next;
}					t_gnl;

typedef int			t_bool;

#endif

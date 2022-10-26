#ifndef FILLER_H
# define FILLER_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "struct.h"

int             main(void);
int             get_player(t_data **data);
void	        get_size(char **line, int *height, int *widht);
int	            read_map(t_data **data);
int	            read_piece(t_data **data);
int		        trim_piece(t_data **data);
void            free_piece(t_data **data, int height);
void	        free_map(t_data **data);
int             free_data(t_data **data, int result);
void	        point_map(t_data **data);
int		        solve(t_data **data);

# define LOG    "filler.log"

void            print_map(t_data **data);

#endif
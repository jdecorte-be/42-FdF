/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:36:49 by decortejohn       #+#    #+#             */
/*   Updated: 2022/02/11 16:28:46 by decortejohn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_img_data
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*img;
}	t_img_data;

typedef struct s_fdf
{
	t_img_data	data;
	float		x1;
	float		y1;
	void		*img;
	void		*p_mlx;
	void		*p_win;
	char		**ag;
	int			height;
	int			width;
	int			**map;
	float		zoom;
	int			h_move;
	int			v_move;
	float		h_view;
}		t_fdf;

int		find_mod(int num);
int		find_max(int num1, int num2);
void	ft_free_tab(char **tab);
void	put_pxl(t_fdf *tab, int x, int y, int color);
char	*get_next_line(int fd);
int		ft_isdigit(int character);
void	readfile(t_fdf *tab);
void	tracing(t_fdf *tab);
void	ft_free_tab_of_int(int **tab);

#endif

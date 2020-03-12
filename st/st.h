#ifndef ST_H
# define ST_H

//# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>


//del
#include <stdio.h>
//
typedef struct	s_m
{
	int	k;
	int	z;
}				t_m;

typedef struct	s_b
{

	int			x;
	int			y;
	int			i;
	t_m	m;

}				t_b;

#endif

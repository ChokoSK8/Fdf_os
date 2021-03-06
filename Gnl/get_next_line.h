/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:06:29 by abrun             #+#    #+#             */
/*   Updated: 2021/09/21 19:38:31 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../Libft/libft.h"
# define BUFFER_SIZE 10

int				get_next_line(int fd, char **line);

char			*get_buf(int fd, int *ret, char *buf);

int				fill_line(char *buf, char **line);

size_t			get_len_buf(char *buf);

char			*ft_strdup(const char *s);

char			*get_new_buf(char *buf);

int				checker_and_init(int fd, char **line, char *buf);

#endif

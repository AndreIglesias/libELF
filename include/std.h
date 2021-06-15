/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 15:11:58 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/16 01:19:40 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_H
# define STD_H

# include <sys/types.h>

ssize_t		ft_read(int fd, void *buf, size_t count);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_printf_fd(const int fd, const char *format, ...);

#endif

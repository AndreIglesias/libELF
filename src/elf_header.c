/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 19:51:47 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/16 00:47:53 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libelf.h"
#include "std.h"

int	elf_header(t_elf *elf, char *obj)
{
	if ((elf->fd = open(obj, O_RDONLY)) < 0)
	{
		ft_printf_fd(2, "libelf: '%s': No such file\n", obj);
		return (-1);
	}
	if (elf->class == ELFCLASS32)
	{
		if (ft_read(elf->fd, &elf->elf_32, sizeof(elf->elf_32))
							< (ssize_t)sizeof(elf->elf_32))
		{
			close(elf->fd);
			return (0);
		}
	}
	else
	{
		if (ft_read(elf->fd, &elf->elf_64, sizeof(elf->elf_64))
							< (ssize_t)sizeof(elf->elf_64))
		{
			close(elf->fd);
			return (0);
		}
	}
	close(elf->fd);
	return (1);
}

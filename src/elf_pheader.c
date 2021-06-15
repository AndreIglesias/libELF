/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_pheader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:59:40 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/16 01:18:45 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libelf.h"
#include "std.h"

int	elf_pheader(t_elf *elf, char *obj)
{
	if ((elf->fd = open(obj, O_RDONLY)) < 0)
	{
		ft_printf_fd(2, "libelf: '%s': No such file\n", obj);
		return (-1);
	}
	if (elf->class == ELFCLASS32)
	{
		if (lseek(elf->fd, elf->elf_32.e_phoff, SEEK_SET) < 0
			&& ft_read(elf->fd, &elf->phdr_32, sizeof(elf->phdr_32))
							< (ssize_t)sizeof(elf->phdr_32))
		{
			close(elf->fd);
			return (0);
		}
	}
	else
	{
		if (lseek(elf->fd, elf->elf_64.e_phoff, SEEK_SET) < 0
			&& ft_read(elf->fd, &elf->phdr_64, sizeof(elf->phdr_64))
			< (ssize_t)sizeof(elf->phdr_64))
		{
			close(elf->fd);
			return (0);
		}
	}
	close(elf->fd);
	return (1);
}

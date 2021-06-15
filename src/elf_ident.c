/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf_ident.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:37:49 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 18:15:41 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libelf.h"
#include "std.h"

/*
**	ret:
**		 0	: Invalid identification
**		 1	: Valid identification
		-1	: No such file
*/

int		elf_ident(t_elf *elf, char *obj)
{
	if ((elf->fd = open(obj, O_RDONLY)) < 0)
		return (-1);
	if (ft_read(elf->fd, elf->identifier, EI_NIDENT) < EI_NIDENT)
	{
		close(elf->fd);
		return (0);
	}
	close(elf->fd);
	if (ft_strncmp((char *)elf->identifier, ELFMAG, SELFMAG))
		return (0);
	if (elf->identifier[EI_CLASS] != ELFCLASS32 &&
		elf->identifier[EI_CLASS] != ELFCLASS64)
		return (0);
	if (elf->identifier[EI_DATA] != ELFDATA2LSB &&
		elf->identifier[EI_DATA] != ELFDATA2MSB)
		return (0);
	if (elf->identifier[EI_VERSION] != EV_CURRENT)
		return (0);
	if (elf->identifier[EI_OSABI] > 0x12)
		return (0);
	return (1);
}

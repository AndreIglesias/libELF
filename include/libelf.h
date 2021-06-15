/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libelf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:06:58 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/15 16:08:54 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBELF_H
# define LIBELF_H

# include <linux/elf.h>

# include <unistd.h>
# include <fcntl.h>

/*
**	unistd:
**		close
**	fcntl:
**		open / O_RDONLY
*/


typedef struct s_elf
{
	Elf32_Ehdr		elf_32;
	Elf64_Ehdr		elf_64;
	unsigned char	identifier[EI_NIDENT];
	unsigned char	class;
	char			*obj;
	int				fd;
}	t_elf;

int		elf_ident(t_elf *elf, char *obj);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libelf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ciglesia <ciglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 01:06:58 by ciglesia          #+#    #+#             */
/*   Updated: 2021/06/16 01:19:18 by ciglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBELF_H
# define LIBELF_H

# include "elf.h"

# include <unistd.h>
# include <fcntl.h>

# define EI_ABIVERSION 8

/*
**	unistd:
**		close
**	fcntl:
**		open / O_RDONLY
*/


typedef struct s_elf
{
	/*
	**	elf_header
	*/
	Elf32_Ehdr		elf_32;
	Elf64_Ehdr		elf_64;
	/*
	**	program_header
	*/
	Elf32_Phdr		phdr_32;
	Elf64_Phdr		phdr_64;
	/*
	**	general
	*/
	unsigned char	identifier[EI_NIDENT];
	unsigned char	class;
	char			*obj;
	int				fd;
}	t_elf;

int		elf_ident(t_elf *elf, char *obj);
int		elf_header(t_elf *elf, char *obj);
int		elf_pheader(t_elf *elf, char *obj);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:14:49 by niragne           #+#    #+#             */
/*   Updated: 2020/02/04 16:47:56 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"

/*
** LD = 0x40 => 0x7F (excluding 0x76)
*/

void	ld_reg_8(uint8_t* dst, uint8_t src)
{
	*dst = src;
}

void	ld_reg_16(uint16_t* dst, uint16_t src)
{
	*dst = src;
}

int		ld_dc(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.d), gb->reg.c);
}

int		ld_c_a8(struct gb_cpu_s* gb)
{
	ld_reg_8(&(gb->reg.c), (uint8_t)gb->current_instruction->args);
}

int		ld_hl_a16(struct gb_cpu_s* gb)
{
	ld_reg_16(&(gb->reg.hl), gb->current_instruction->args);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:27:30 by niragne           #+#    #+#             */
/*   Updated: 2020/02/12 13:44:50 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "gb.h"

int		add(struct gb_cpu_s* gb, uint8_t value)
{
	uint16_t ret;
	ret = gb->reg.a + value;
	cpu_toggle_flag(gb, ZERO_FLAG, !ret);
	cpu_toggle_flag(gb, CARRY_FLAG, ret > 255);
	cpu_unset_flag(gb, SUBSTRACTION_FLAG);
	gb->reg.a = (uint8_t)ret;
}

int		add_a(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.a);
}

int		add_b(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.b);
}

int		add_c(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.c);
}

int		add_d(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.d);
}

int		add_e(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.e);
}

int		add_h(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.h);
}

int		add_l(struct gb_cpu_s* gb)
{
	add(gb, gb->reg.l);
}

int		add_a8(struct gb_cpu_s* gb)
{
	add(gb, gb->current_instruction->args);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:05:57 by niragne           #+#    #+#             */
/*   Updated: 2020/04/09 18:03:35 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gb.h"
#include <stdio.h>
#include <string.h>

static struct command_s command_invalid =
{
	NULL, command_not_found, NULL
};

static struct command_s commands[] =
{
	{"n", command_next, "Execute next instruction"},
	{"r", command_run, "Run to next breakpoint"},
	{"p", command_print, "Print value at index"},
	{"b", command_add_breakpoint, "Add breakpoint"},
	{"v", command_set_verbose, "Change verbose level"},
	{"i", command_info, "Print general info"},
	{"del", command_del, "Delete all breakpoints"},
	{"help", command_help, "Display all available commands"},
	{"q", command_quit, "Quit"}
};

int		command_next(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	/*
	** Ugly... This should probably be refactored.
	*/
	(void)s;
	(void)arg;
	uint8_t ret = handle_instruction(gb);
	gpu_tick(gb);

	if (gb->debugger->verbose_level == 0)
			debug_print_gb(gb);

	return (ret);
}

int		command_add_breakpoint(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	(void)s;
	printf("Adding breakpoint %x\n", arg);
	add_breakpoint(&(gb->debugger->breakpoints), arg);
	print_breakpoints(gb->debugger->breakpoints);
	return (0);
}

int		command_set_verbose(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	(void)s;
	printf("Changing verbose level to %x\n", arg);
	gb->debugger->verbose_level = arg;
	return (0);
}

int		command_info(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	(void)s;
	(void)arg;
	update_current_instruction(gb);
	debug_print_gb(gb);
	return (0);
}

int		command_not_found(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	(void)gb;
	(void)arg;	
	
	printf("undefined command: \"%s\"\n", s);
	return (0);
}

int		command_quit(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	(void)s;
	(void)arg;
	gb->running = 0;
	return (0);
}

int		command_run(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	(void)s;
	(void)arg;	
	gb->paused = 0;
	return (0);
}

int		command_print(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	(void)s;
	printf("%x: %x\n", arg, read_8(gb, arg));	
	printf("%x: %x\n", arg, read_16(gb, arg));	
	return (0);
}

int		command_del(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	(void)s;
	(void)arg;
	clear_breakpoints(&(gb->debugger->breakpoints));
	return (0);
}

int		command_help(struct gb_cpu_s* gb, char* s, uint16_t arg)
{
	struct command_s* ret;
	int i = 0;
	(void)s;
	(void)gb;
	(void)arg;

	while (i * sizeof(struct command_s) < sizeof(commands))
	{
		ret = commands + i;
		printf("%s: %s\n", ret->name, ret->desc);
		i++;
	}
	return (0);
}

struct command_s* find_command(char* s)
{
	struct command_s* ret;
	int i = 0;

	while (i * sizeof(struct command_s) < sizeof(commands))
	{
		ret = commands + i;
		if (!strcmp(s, ret->name))
		{
			return (ret);
		}
		i++;
	}
	return (&command_invalid);
}

void	parse_command(struct gb_cpu_s* gb)
{
	char buffer[255];
	char command[255];
	int ret;
	uint16_t arg;
	static struct command_s* cmd = commands + 0;

	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		gb->running = 0;
		return ;
	}
	int rd = sscanf(buffer, "%s %hx", command, &arg);
	if (rd > 0)
	{
		cmd = find_command(command);
	}
	ret = cmd->f(gb, command, arg);
	if (ret)
		gb->running = 0;
}
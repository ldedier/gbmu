/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalEqual.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalEqual.hpp"

SymbolTerminalEqual::SymbolTerminalEqual(void) : AbstractTerminal("==")
{
	
}

SymbolTerminalEqual::~SymbolTerminalEqual(void)
{
	
}

int	SymbolTerminalEqual::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

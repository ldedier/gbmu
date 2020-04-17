/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalMultiply.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolTerminalMultiply.hpp"

SymbolTerminalMultiply::SymbolTerminalMultiply(void) : AbstractTerminal("*")
{
	
}

SymbolTerminalMultiply::~SymbolTerminalMultiply(void)
{
	
}

int	SymbolTerminalMultiply::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}


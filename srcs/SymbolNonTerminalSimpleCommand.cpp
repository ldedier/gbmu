/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalSimpleCommand.cpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

# include "SymbolNonTerminalSimpleCommand.hpp"

SymbolNonTerminalSimpleCommand::SymbolNonTerminalSimpleCommand(void) : AbstractNonTerminal("simplecommand")
{
	
}

SymbolNonTerminalSimpleCommand::~SymbolNonTerminalSimpleCommand(void)
{
	
}

int	SymbolNonTerminalSimpleCommand::traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const
{
	static_cast<void>(ast);
	static_cast<void>(context);
	return (0);
}

void	SymbolNonTerminalSimpleCommand::computeProductions(AbstractGrammar<int, CustomStack &> & cfg)
{
	addProduction(cfg, 1, (std::string[]){"commandname"});
	addProduction(cfg, 3, (std::string[]){"commandname", "separatorpipeline", "commandsuffix"});
}
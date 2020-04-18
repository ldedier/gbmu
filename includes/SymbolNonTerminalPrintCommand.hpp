/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolNonTerminalPrintCommand.hpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:47:46 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 12:47:46 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLNONTERMINALPRINTCOMMAND_HPP
# define SYMBOLNONTERMINALPRINTCOMMAND_HPP

# include "DebuggerGrammar.hpp"

class SymbolNonTerminalPrintCommand : public AbstractNonTerminal<int, CustomStack &>
{
	public:
		SymbolNonTerminalPrintCommand(void);
		~SymbolNonTerminalPrintCommand(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;
		virtual void computeProductions(AbstractGrammar<int, CustomStack &> & cfg);

	private:

};

#endif

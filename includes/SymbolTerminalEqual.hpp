/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalEqual.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALEQUAL_HPP
# define SYMBOLTERMINALEQUAL_HPP

# include "AbstractTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalEqual : public AbstractTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalEqual(void);
		~SymbolTerminalEqual(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif

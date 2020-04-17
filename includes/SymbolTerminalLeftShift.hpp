/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SymbolTerminalLeftShift.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 03:08:44 by ldedier            #+#    #+#            */
/*   Updated: 2020/04/17 03:08:44 by ldedier           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SYMBOLTERMINALLEFTSHIFT_HPP
# define SYMBOLTERMINALLEFTSHIFT_HPP

# include "AbstractTerminal.hpp"
# include "CustomStack.hpp"

class SymbolTerminalLeftShift : public AbstractTerminal<int, CustomStack &>
{
	public:
		SymbolTerminalLeftShift(void);
		~SymbolTerminalLeftShift(void);
		virtual int traverse(ASTNode<int, CustomStack &> & ast, CustomStack & context) const;

	private:

};

#endif
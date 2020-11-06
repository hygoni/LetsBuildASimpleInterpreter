/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:02:37 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/11/06 22:51:55 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Token.hpp"

class Interpreter {
 private:
   std::string  _text;
   int          _pos;
   Token        _current_token;
 public:
                Interpreter(std::string const& text);
   Token        get_next_token();
   void         advance();
   char         current() const;
   void         eat(Type type);
   int          eval();
};

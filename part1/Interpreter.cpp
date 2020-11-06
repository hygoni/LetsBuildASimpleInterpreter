/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:06:10 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/11/06 21:33:07 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cctype>
#include <string>
#include "Interpreter.hpp"

Interpreter::Interpreter(std::string const& text) {
  this->_text = text;
  this->_pos = 0;
  this->_current_token = get_next_token();
}

Token Interpreter::get_next_token() {
  /* if all characters are read, it returns END_OF_FILE */
  if (this->_pos == this->_text.size()) {
    return Token(END_OF_FILE);
  }

  char c = this->_text.at(this->_pos);
  this->_pos++;

  /* check type of a token */
  if (isdigit(c)) {
    return Token(INTEGER, std::string(1, c));
  } else if (c == '+') {
    return Token(PLUS, std::string(1, c)); 
  } else {
    /* invalid token */
    throw std::exception();
  }
}

void Interpreter::eat(Type type) {
  if (this->_current_token.getType() == type) {
    this->_current_token = this->get_next_token();
  } else {
    throw std::exception();
  }
}

int Interpreter::eval() {
  int x, y;

  x = atoi(this->_current_token.getValue().c_str());
  this->eat(INTEGER);
  this->eat(PLUS);
  y = atoi(this->_current_token.getValue().c_str());
  this->eat(INTEGER);
  this->eat(END_OF_FILE);
  return x + y;
}

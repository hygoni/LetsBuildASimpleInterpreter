/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interpreter.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:06:10 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/11/06 23:33:23 by hyeyoo           ###   ########.fr       */
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
  char c;

  /* if all characters are read, it returns END_OF_FILE */
  if (this->_pos == this->_text.size()) {
    return Token(END_OF_FILE);
  }

  /* skip whitespace */
  c = this->current();
  while (isspace(c)) {
    this->advance();
    if (this->_pos == this->_text.size())
      break;
    c = this->current();
  }

  /* check type of a token */
  if (isdigit(c)) {
    int number = 0;
    while (isdigit(c)) {
      number = number * 10 + (c - '0');
      this->advance();
      if (this->_pos == this->_text.size())
        break;
      c = this->current();
    }
    return Token(INTEGER, std::to_string(number));
  } else if (c == '+') {
    this->advance();
    return Token(PLUS, std::string(1, c)); 
  } else if (c == '-') {
    this->advance();
    return Token(MINUS, std::string(1, c));
  } else {
    /* invalid token */
    throw std::exception();
    return Token(NONE);
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
  char op;

  x = atoi(this->_current_token.getValue().c_str());
  this->eat(INTEGER);

  op = this->_current_token.getValue().at(0);
  if (op == '+')
    this->eat(PLUS);
  else if (op == '-')
    this->eat(MINUS);
  else
    throw std::exception();

  y = atoi(this->_current_token.getValue().c_str());
  this->eat(INTEGER);
  this->eat(END_OF_FILE);

  if (op == '+') {
    return x + y;
  } else if (op == '-') {
    return x - y;
  } else {
    throw std::exception();
    return 0;
  }
}

void  Interpreter::advance() {
  this->_pos++;
}

char  Interpreter::current() const {
  return this->_text.at(this->_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:04:37 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/11/06 21:25:19 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Token.hpp"

Token::Token() {
  this->_type = NONE;
  this->_value = "";
}

Token::Token(Type type) {
  this->_type = type;
  this->_value = "";
}

Token::Token(Type type, std::string const& value) {
  this->_type = type;
  this->_value = value;
}

Type Token::getType() const {
  return this->_type;
}

std::string const& Token::getValue() const {
  return this->_value;
}

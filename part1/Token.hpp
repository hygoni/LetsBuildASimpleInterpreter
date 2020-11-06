/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Token.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:58:54 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/11/06 21:24:35 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Type.hpp"

class Token {
  private:
    Type                _type;
    std::string         _value;
  public:
                        Token();
                        Token(Type _type);
                        Token(Type _type, std::string const& _value);
    Type                getType() const;
    std::string const&  getValue() const;
};

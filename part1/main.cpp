/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:28:18 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/11/06 21:28:44 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Interpreter.hpp"

int   main(void)
{
  std::string input;
  std::cin >> input;

  std::cout << "the input text is : " << input << std::endl;
  try {
    Interpreter inter(input);
    int result = inter.eval();
    std::cout << "result is " << result << std::endl;
  } catch (std::exception const& e) {
    std::cout << "parse error!" << std::endl;
  }
  return 0;
}

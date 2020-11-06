/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <hyeyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 21:28:18 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/11/06 23:31:16 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Interpreter.hpp"

int   main(void)
{
  std::string input;
  std::string line;
  getline(std::cin, line);
  std::cout << "the input text is : " << line << std::endl;
  try {
    Interpreter inter(line);
    int result = inter.eval();
    std::cout << "result is " << result << std::endl;
  } catch (std::exception const& e) {
    std::cout << "parse error!" << std::endl;
  }
  return 0;
}

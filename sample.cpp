/**
 * @file useStackToJudgeBalancedParen.cpp
 * @author Zhou Jing (254644528@qq.com)
 * @brief
 * @version 0.1
 * @date 2022-11-15
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <stack>
#include <string>

extern bool isValidParen(std::string Paren);

int main() {
  std::string Ref = "((())){(})";
  if (isValidParen(Ref))
    std::cout << "Valid" << std::endl;
  else
    std::cout << "Not Valid" << std::endl;
  return 0;
}

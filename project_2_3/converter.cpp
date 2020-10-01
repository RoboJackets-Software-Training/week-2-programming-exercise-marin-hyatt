#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include "converter.h"

 /**
   * returns a number 0-15 based off of a hex char
   * This uses ascii to figure out number it corresponds to
   * @param input
   * @return
   */
  int converter::hexCharToNumber(char input) {
    // this means it is [A,B,C,D,E,F]
    if(input > 57) {
      return input - (65 - 10);
    } else {
      // this is a digit in ascii
      return input - 48;
    }
  }

  /**
   * returns the character that is the given hex number
   * only valid on 0-15
   * @param input
   * @return
   */
  char converter::numberToHexChar(int input) {
    if(input < 10) {
      // it is a digit
      return input + 48;
    } else {
      return (input - 10) + 65;
    }
  }

  int converter::binaryToDecimal(std::string binaryString) {
    int powerCounter = 0;
    int decimal = 0;
    for (int i = binaryString.size(); i >= 0; i--) {
      int num = hexCharToNumber(binaryString[i]);
      decimal += num * std::pow(2, powerCounter);
      powerCounter++;
    }
    return decimal;
  }

  int converter::hexToDecimal(std::string hexString) {
    int powerCounter = 0;
    int decimal = 0;
    for (int i = hexString.size(); i >= 0; i--) {
      int num = hexCharToNumber(hexString[i]);
      decimal += num * std::pow(16, powerCounter);
      powerCounter++;
    }
    return decimal;
  }
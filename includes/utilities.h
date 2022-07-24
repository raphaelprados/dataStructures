//
// Created by alex1 on 13/07/2022.
//

#include "algorithm"
#include "iostream"
#include "string"

#ifndef ALGORITMOS_II_UTILITIES_H
#define ALGORITMOS_II_UTILITIES_H

std::string intToBinary(int num) {

    std::string binary;

    if(num == 0 )
        return "0";
    while(num != 0) {
        binary.push_back((char)(48 + num % 2));
        num /= 2;
    }
    std::reverse(binary.begin(), binary.end());

    return binary;
}

bool is_even(int num) {
    return (num & 1);
}

bool is_multiple_2(int num) {
    return (num & !(num - 1));
}

#endif //ALGORITMOS_II_UTILITIES_H

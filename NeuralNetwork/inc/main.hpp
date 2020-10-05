#pragma once

#include <iostream>
#include <random>
#include <istream>
#include <string>
#include <vector>

#include "NeuralNetwork.hpp"

#define nl std::cout << std::endl;

double relu(double x) {
    return x > 0 ? x : 0;
}

double dtanh(double value) {
    return -0.5 * ((tanh(value) - 1) * (tanh(value) + 1));
}

const char* message = "CPP-PROJECT TEMPLATE";
#pragma once

#include <cmath>
#include <vector>

#include "Matrix.hpp"

class NeuralNetwork {
   private:
    int input_nodes;
    int hidden_nodes;
    int output_nodes;
    Matrix weights_ih;
    Matrix weights_ho;
    Matrix bias_h;
    Matrix bias_o;

    double learningRate = 0.1;

   public:
    NeuralNetwork(const NeuralNetwork &);
    NeuralNetwork(unsigned, unsigned, unsigned);
    NeuralNetwork();

    unsigned getInputNodes();
    unsigned getHiddenNodes();
    unsigned getOutputNodes();

    Matrix getWeightsIh();
    Matrix getWeightsHo();

    Matrix getHiddenBias();
    Matrix getOutputBias();

    void setLearningRate(double);

    void train(vector<double>, vector<double>);
    vector<double> predict(vector<double>);
    void mutate(functioncall);

    NeuralNetwork& copy();

    //Tests
    void print();
};
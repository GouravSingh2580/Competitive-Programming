#include "NeuralNetwork.hpp"

#define dd std::cout << "#####" << std::endl;

#define aa std::cout << "$$$$$" << std::endl;

#define p(x) std::cout << #x << " " << x.getRows() << " " << x.getCols() << std::endl;

// Constructor for Any NeuralNetwork
NeuralNetwork::NeuralNetwork(unsigned input, unsigned hidden, unsigned output) {
    this->input_nodes = input;
    this->hidden_nodes = hidden;
    this->output_nodes = output;

    this->weights_ih = Matrix(hidden, input, 0);
    this->weights_ho = Matrix(output, hidden, 0);

    this->bias_h = Matrix(hidden, 1, 0);
    this->bias_o = Matrix(output, 1, 0);

    this->weights_ih.randomize();
    this->weights_ho.randomize();

    this->bias_h.randomize();
    this->bias_o.randomize();

    this->learningRate = 0.1;
}

// Copy Constructor
NeuralNetwork::NeuralNetwork(const NeuralNetwork &n) {
    this->input_nodes = n.input_nodes;
    this->hidden_nodes = n.hidden_nodes;
    this->output_nodes = n.output_nodes;

    this->weights_ih = Matrix(n.weights_ih);
    this->weights_ho = Matrix(n.weights_ho);

    this->bias_h = Matrix(n.bias_h);
    this->bias_o = Matrix(n.bias_o);

    this->learningRate = n.learningRate;
}

// Default Constructor
NeuralNetwork::NeuralNetwork() {
}

// Set the learning rate
void NeuralNetwork::setLearningRate(double rate) {
    this->learningRate = rate;  // default 0.1
}

// Train the neural network
// args: Array with inputs, Array with the results
void NeuralNetwork::train(vector<double> input_array, vector<double> target_array) {
    Matrix inputs = Matrix(input_array);
    Matrix hidden = this->weights_ih * inputs;
    hidden += this->bias_h;
    // activation function!
    hidden.sigmod();

    // Generating the output's output!
    Matrix outputs = this->weights_ho * hidden;
    outputs += this->bias_o;
    outputs.sigmod();

    // Convert array to matrix object
    Matrix targets = Matrix(target_array);

    // Calculate the error
    // ERROR = TARGETS - OUTPUTS
    Matrix output_errors = targets - outputs;

    // Calculate gradient
    Matrix gradients = outputs.dSigmod();
    gradients = gradients.hadamard(output_errors);
    gradients *= this->learningRate;

    // Calculate Deltas
    Matrix hidden_transpose = hidden.transpose();
    Matrix weights_ho_deltas = gradients * hidden_transpose;

    // Adjust the weights by deltas
    this->weights_ho += weights_ho_deltas;
    // Adujust bias by its deltas (which is just the gradient)
    this->bias_o += gradients;

    // Calculate the hidden layer errors
    Matrix weights_ho_transpose = this->weights_ho.transpose();
    Matrix hidden_errors = weights_ho_transpose * output_errors;

    // Calculate hidden gradient
    Matrix hidden_gradient = hidden.dSigmod();
    hidden_gradient = hidden_gradient.hadamard(hidden_errors);
    hidden_gradient *= this->learningRate;

    // Calculate input->hidden deltas
    Matrix inputs_transpose = inputs.transpose();
    Matrix weights_ih_deltas = hidden_gradient * inputs_transpose;
    // Adjust the weights by deltas
    this->weights_ih += weights_ih_deltas;

    // Adjust the bias by its deltas (which is just the gradients)
    this->bias_h = this->bias_h + hidden_gradient;
}

// Predict a output
// args: Array of inputs
// return: Array of outputs to given inputs
vector<double> NeuralNetwork::predict(vector<double> input_array) {
    // Generating the hidden outputs
    Matrix inputs = Matrix(input_array);
    Matrix hidden = this->weights_ih * inputs;
    hidden = hidden + this->bias_h;

    // Activation function
    hidden = hidden.sigmod();

    // Generating the ouput's output!
    Matrix output = this->weights_ho * hidden;
    Matrix out = output + this->bias_o;
    output = output.sigmod();

    return output.toArray();
}

// Make a copy of this NeuralNetwork
NeuralNetwork &NeuralNetwork::copy() {
    return *this;
}

// Apply a mutate function in weights and bias
void NeuralNetwork::mutate(functioncall func) {
    this->weights_ih.map(func);
    this->weights_ho.map(func);
    this->bias_h.map(func);
    this->bias_o.map(func);
}

// Fancy print all weights and bias
void NeuralNetwork::print() {
    std::cout << "Weights_HO\n";
    this->weights_ho.print();
    std::cout << "Weights_IH\n";
    this->weights_ih.print();
    std::cout << "Bias_H\n";
    this->bias_h.print();
    std::cout << "Bias_O\n";
    this->bias_o.print();
}

// Get inputs #
unsigned NeuralNetwork::getInputNodes() {
    return this->input_nodes;
}

// Get hidden #
unsigned NeuralNetwork::getHiddenNodes() {
    return this->hidden_nodes;
}

// Get ouputs #
unsigned NeuralNetwork::getOutputNodes() {
    return this->output_nodes;
}

// Get input-hidden weights Matrix
Matrix NeuralNetwork::getWeightsIh() {
    return this->weights_ih;
}

// Get hiden-outputs weights Matrix
Matrix NeuralNetwork::getWeightsHo() {
    return this->weights_ho;
}

// Get hidden bias Matrix
Matrix NeuralNetwork::getHiddenBias() {
    return this->bias_h;
}

// Get output bias Matrix
Matrix NeuralNetwork::getOutputBias() {
    return this->bias_o;
}
#include "main.hpp"

std::vector<double> toPos(double index) {
    return {index == 1 ? 1.0 : 0.0, index == 2 ? 1.0 : 0.0, index == 3 ? 1.0 : 0.0};
}

double fromPos(std::vector<double> v) {
    if (v[0] == 1.0) {
        return 1;
    } else if (v[1] == 1.0) {
        return 2;
    } else {
        return 3;
    }
}

double fromOut(std::vector<double> v) {
    return std::distance(v.begin(), std::max_element(v.begin(), v.end())) + 1;
}

int main(int argc, char** argv) {
    NeuralNetwork nn = NeuralNetwork(4, 5, 3);

    std::ifstream file("bin/iris_data_files/iris.data");
    std::string line;

    std::vector<std::vector<double>> train;
    std::vector<std::vector<double>> label;

    double in1, in2, in3, in4, out;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> in1 >> in2 >> in3 >> in4 >> out;
        train.push_back({in1, in2, in3, in4});
        label.push_back(toPos(out));
    }

    double totalAcc;

    for (int k = 0; k < 10; k++) {
        for (int i = 0; i < 100000; i++) {
            int index = i % (train.size());
            nn.train(train[index], label[index]);
        }

        double rate = 0;
        double acc = 0;

        for (int i = 0; i < train.size(); i++) {
            std::vector<double> output = nn.predict(train[i]);
            double o = fromPos(label[i]);
            double a = fromOut(output);
            //std::cout << "output: " << a << " label: " << o << std::endl;
            if (a == o) rate++;
        }

        acc = rate / train.size();

        std::cout << "rate: " << rate << "/" << train.size() << " acc: " << acc << std::endl;

        totalAcc += acc;
    }

    std::cout << "Average acc: " << totalAcc / 10 << std::endl;

    return 0;
}
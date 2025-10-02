#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

int main(int argc, char* argv[]) {
    std::vector<double> operands;
    std::string operation = "both"; // По умолчанию вычисляем и то, и другое

    po::options_description desc("Калькулятор среднего и медианы\n\nДопустимые опции");
    desc.add_options()
        ("help,h", "Показать справку по использованию")
        ("operation,o", po::value<std::string>(&operation), 
         "Операция: mean (среднее), median (медиана) или both (оба, по умолчанию)")
        ("operands", po::value<std::vector<double>>(&operands)->multitoken()->required(),
         "Операнды (8-10 чисел)")
    ;

    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        
        if (vm.count("help")) {
            std::cout << desc << std::endl;
            std::cout << "\nПримеры использования:\n";
            std::cout << "  calculator --operands 1 2 3 4 5 6 7 8\n";
            std::cout << "  calculator --operation mean --operands 10 20 30 40 50 60 70 80 90\n";
            std::cout << "  calculator -o median --operands 5.5 6.6 7.7 8.8 9.9 10.1 11.2 12.3\n";
            std::cout << "  calculator --operation both --operands 1 2 3 4 5 6 7 8 9 10\n";
            return 0;
        }
        
        po::notify(vm);
    } catch (po::error& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        std::cerr << desc << std::endl;
        return 1;
    }

    // Проверка допустимости операции
    if (operation != "mean" && operation != "median" && operation != "both") {
        std::cerr << "Ошибка: неизвестная операция '" << operation << "'" << std::endl;
        std::cerr << "Допустимые операции: mean, median, both" << std::endl;
        return 1;
    }

    // Проверка количества операндов
    if (operands.size() < 8 || operands.size() > 10) {
        std::cerr << "Ошибка: количество операндов должно быть от 8 до 10. Получено: " 
                  << operands.size() << std::endl;
        return 1;
    }

    // Вывод введенных операндов
    std::cout << "Введенные операнды: ";
    for (size_t i = 0; i < operands.size(); ++i) {
        std::cout << operands[i];
        if (i != operands.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    // Вычисление в зависимости от выбранной операции
    if (operation == "mean" || operation == "both") {
        double sum = std::accumulate(operands.begin(), operands.end(), 0.0);
        double average = sum / operands.size();
        std::cout << "Среднее значение: " << average << std::endl;
    }

    if (operation == "median" || operation == "both") {
        std::vector<double> sorted_operands = operands;
        std::sort(sorted_operands.begin(), sorted_operands.end());
        
        double median;
        size_t size = sorted_operands.size();
        if (size % 2 == 0) {
            median = (sorted_operands[size/2 - 1] + sorted_operands[size/2]) / 2.0;
        } else {
            median = sorted_operands[size/2];
        }
        std::cout << "Медиана: " << median << std::endl;
    }

    return 0;
}

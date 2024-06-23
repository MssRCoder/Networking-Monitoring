#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream arquivo("csv_data.csv"); // Abrir o arquivo para leitura
    std::string linha;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) { // Ler cada linha do arquivo
            std::vector<std::string> tokens;
            std::stringstream ss(linha);
            std::string token;

            while (std::getline(ss, token, ',')) { // Separar por vírgula
                tokens.push_back(token); // Armazenar cada token em um vetor
            }

            // Exemplo de processamento dos tokens (imprimir cada variável separadamente)
            for (const auto& t : tokens) {
                std::cout << t << " ";
            }
            std::cout << "\n";
        }
        arquivo.close(); // Fechar o arquivo após a leitura
    } else {
        std::cerr << "Não foi possível abrir o arquivo.\n";
    }

    return 0;
}

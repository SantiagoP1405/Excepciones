/*
Santiago Patricio Gómez Ochoa
A01735171
11/06/2024
Programación Orientada a Objetos
*/
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

void validateGameParameters(int sizeTablero, int players, int snakes, int ladders, int reward, int penalty) {
    std::vector<std::string> errors;

    if (sizeTablero <= 0) {
        errors.push_back("Invalid sizeTablero value " + std::to_string(sizeTablero));
    }

    if (players <= 1) {
        errors.push_back("Invalid players value " + std::to_string(players));
    }

    if (snakes >= sizeTablero) {
        errors.push_back("Invalid snakes value " + std::to_string(snakes));
    }

    if (ladders >= sizeTablero) {
        errors.push_back("Invalid ladders value " + std::to_string(ladders));
    }

    if (reward >= sizeTablero || reward >= ladders) {
        errors.push_back("Invalid reward value " + std::to_string(reward));
    }

    if (penalty >= sizeTablero || penalty >= snakes) {
        errors.push_back("Invalid penalty value " + std::to_string(penalty));
    }

    if((snakes + ladders) >= sizeTablero){
        errors.push_back("Invalid snakes + ladders values " + std::to_string(snakes + ladders));
    }

    if (!errors.empty()) {
        std::ostringstream oss;
        for (const auto& error : errors) {
            oss << error << std::endl;
        }
        throw std::runtime_error(oss.str());
    }
}

bool getUserOption(int& errorCount) {
    while (errorCount < 5) {
        char option;
        std::cout << std::endl;
        std::cout << "Ingresa alguna de las siguientes opciones:  " << std::endl;
        std::cout << "< C > Continuar: " << std::endl;
        std::cout << "< E > Salir" << std::endl;
        std::cin >> option;
        option = toupper(option);

        if (option == 'C') {
            std::cout << "Continuando juego..." << std::endl;
            return true; // Continuar el juego.
        } else if (option == 'E') {
            std::cout << "-- GAME OVER --" << std::endl;
            return false; // Terminar el juego.
        } else {
            errorCount++;
            std::cerr << "Opción inválida" << std::endl;
            std::cerr << "Por favor presiona < C > para continuar o < E > para terminar el juego" << std::endl;
            if (errorCount == 5) {
                std::cerr << "Cantidad de opciones inválidas excedidas" << std::endl;
                std::cerr << "-- GAME OVER --" << std::endl;
                return false; // Terminar el juego por errores.
            }
        }
    }
    return false; // Por si el while se rompe de alguna manera.
}

int main() {
    try {
        int sizeTablero, numSerpientes, penalty, numEscaleras, reward, players;

        std::cout << "Ingrese el tamaño del tablero: ";
        std::cin >> sizeTablero;
        std::cout << "Ingrese el número de casillas de serpiente que habrán: ";
        std::cin >> numSerpientes;
        std::cout << "Ingrese cuántas casillas retrocederá si cae en una serpiente: ";
        std::cin >> penalty;
        std::cout << "Ingrese el número de casillas de escalera que habrá: ";
        std::cin >> numEscaleras;
        std::cout << "Ingrese cuántas casillas avanzará si cae en una escalera: ";
        std::cin >> reward;
        std::cout << "Ingrese cuántos jugadores habrán: ";
        std::cin >> players;
        std::cout << std::endl;

        // Validar parámetros del juego
        validateGameParameters(sizeTablero, players, numSerpientes, numEscaleras, reward, penalty);

        // Interacción con el usuario
        int errorC = 0;
        bool continueGame = true;
        while (continueGame) {
            continueGame = getUserOption(errorC);
        }
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;  // Terminar el juego con error
    }

    return 0;
}
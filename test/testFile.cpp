#include <iostream>
#include <thread>
#include <chrono>


#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // Affiche du texte initial
    std::cout << "Initial Text\n";
    std::cout << "Initial Text\n";
    std::cout << "Initial Text\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Efface tout l'écran et replace le curseur en haut à gauche
    std::cout << "\033[2J\033[H";  // Effacer tout l'écran
    std::cout.flush();

    // Affiche "bonjour"
    std::cout << "bonjour\n";
    std::cout << "bonjour\n";
    std::cout << "bonjour\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Efface à nouveau l'écran
    std::cout << "\033[2J\033[H";  // Effacer tout l'écran
    std::cout.flush();

    // Affiche autre chose
    std::cout << "Nouvelle ligne d'affichage\n";
    std::cout << "Nouvelle ligne d'affichage\n";
    std::cout << "Nouvelle ligne d'affichage\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Efface l'écran une dernière fois
    std::cout << "\033[2J\033[H";
    std::cout.flush();

    std::cout << "Fin de l'affichage\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    return 0;
}


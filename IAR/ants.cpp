#include <iostream>
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

// Compilar: g++ ants.cpp -o ants -lsfml-graphics -lsfml-window -lsfml-system


int main(){



    sf::Window window(sf::VideoMode(600, 600), "Ants");
    
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
    }

    return 0;
}
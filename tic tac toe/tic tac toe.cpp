#include<iostream>
#include"SFML\Graphics.hpp"
#include"SFML\Window.hpp"
#include"SFML\System.hpp"

#ifdef _WIN32
#include <windows.h>

void sleep(unsigned milliseconds)
{
    Sleep(milliseconds);
}
#else
#include <unistd.h>

void sleep(unsigned milliseconds)
{
    usleep(milliseconds * 1000); // takes microseconds
}
#endif




void Draw(sf::RenderWindow& window, sf::Sprite& figure, int x, int y) {
    figure.setPosition(x, y);
    window.draw(figure);
    //window.display();
}



int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "SFML works!");
    int current = 1;
    char circle_field = 'O';
    char cross_field = 'O';
    char field;

    //board
     sf::Texture board;
    board.loadFromFile("C:/Users/Habel/source/repos/tic tac toe/board.png");
    sf::Sprite board_sprite(board);  

    //circle
    sf::Texture circle;
    circle.loadFromFile("C:/Users/Habel/source/repos/tic tac toe/circle.png");
     sf::Sprite circle_sprite(circle);
    ///circle_sprite.setPosition(0.0f, 0.0f);


    //cross
    sf::Texture cross;
    cross.loadFromFile("C:/Users/Habel/source/repos/tic tac toe/cross.png");
    sf::Sprite cross_sprite(cross);

    	
    
    char board_arr[3][3];
    bool isFirstIteration = true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board_arr[i][j]= ' ';
        }
    }
    
        
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
        }
        if (current % 2 == 0) {
            field = circle_field;
        }
        else {
            field = cross_field;
        }
        // Clear the window
        window.clear();

        // Draw the board sprite
        window.draw(board_sprite);

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            // Pobierz współrzędne kliknięcia myszy
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;
            current++;
            // Wyświetl współrzędne w konsoli
           // std::cout << "Kliknięcie myszy - X: " << x << ", Y: " << y << std::endl;
            
            if (x > 0 && x <= 300 && y > 0 && y <= 300) {
                board_arr[0][0] = field;
            }
            if (x > 300 && x <= 600 && y > 0 && y <= 300) {
                board_arr[0][1] = field;
            }
            if (x > 600 && x <= 900 && y > 0 && y <= 300) {
                board_arr[0][2] = field;
            }
            if (x > 0 && x <= 300 && y > 300 && y <= 600) {
                board_arr[1][0] = field;
            }
            if (x > 300 && x <= 600 && y > 300 && y <= 600) {
                board_arr[1][1] = field;
            }
            if (x > 600 && x <= 900 && y > 300 && y <= 600) {
                board_arr[1][2] = field;
            }
            if (x > 0 && x <= 300 && y > 600 && y <= 900) {
                board_arr[2][0] = field;
            }
            if (x > 300 && x <= 600 && y > 600 && y <= 900) {
                board_arr[2][1] = field;
            }
            if (x > 600 && x <= 900 && y > 600 && y <= 900) {
                board_arr[2][2] = field;
            }
            

        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board_arr[i][j] == 'X') {
                    Draw(window, cross_sprite, 300 * j, 300 * i);
                }
                if (board_arr[i][j] == 'O') {
                    Draw(window, circle_sprite, 300 * j, 300 * i);
                }
            }
        }
        
        // isFirstIteration = false;
       // window.display();
        window.display();
           
       //Sleep(1000);
        
        std::cout << current;
    }
    
   
    return 0;
}



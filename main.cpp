#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>
#include "Game.h"
#pragma warning(suppress : 4996).


using namespace sf;
void displayHomeScreen(RenderWindow& fenetre, bool colorGame, bool colorSettings);

Font menufont;
int playermode[4] = { 0,1,1,1 };

int main()
{
    menufont.loadFromFile("./Media/Font/font.ttf");

    RenderWindow fenetre(VideoMode(UI_WIDTH, UI_HEIGHT), "Bomberman", Style::Close);
    Game game;

    displayHomeScreen(fenetre, false, false);

    while (fenetre.isOpen())
    {
        Event evenement;
        while (fenetre.pollEvent(evenement))
        {

            switch (evenement.type)
            {
            case Event::Closed:
                fenetre.close();
                break;
            case Event::MouseMoved:
                    if (evenement.mouseMove.x >= 50 && evenement.mouseMove.x <= 300 && evenement.mouseMove.y >= 350 && evenement.mouseMove.y < 430)
                        displayHomeScreen(fenetre, true, false);
                    else if (evenement.mouseMove.x >= (UI_WIDTH - 300) && evenement.mouseMove.x <= (UI_WIDTH - 50) && evenement.mouseMove.y >= 350 && evenement.mouseMove.y < 430)
                        displayHomeScreen(fenetre, false, true);
                    else
                        displayHomeScreen(fenetre, false, false);
                
                break;
            case Event::MouseButtonPressed:
                    if (evenement.mouseButton.x >= (UI_WIDTH - 300) && evenement.mouseButton.x <= (UI_WIDTH - 50) && evenement.mouseButton.y >= 350 && evenement.mouseButton.y < 430)
                        fenetre.close();
                    else if (evenement.mouseButton.x >= 50 && evenement.mouseButton.x <= 300 && evenement.mouseButton.y >= 350 && evenement.mouseButton.y < 430)
                        game.reloadGame(fenetre, 1);
                        game.run(fenetre);
                                   
                break;
            }
        }
    }
}


void displayHomeScreen(RenderWindow& fenetre, bool colorGame, bool colorSettings)
{
   

    sf::Texture background;
    !background.loadFromFile("Media/Image/Menu6.png");

    Sprite fondo;
    fondo.setTexture(background);
    fondo.setPosition(0, 0);

    Text playText;
    playText.setString("JUGAR");
    playText.setFont(menufont);
    playText.setPosition(120, 380);
    playText.setCharacterSize(22);
    if (colorGame)
        playText.setFillColor(Color(0, 0, 0));

    Text exitText;
    exitText.setString("SALIR");
    exitText.setFont(menufont);
    exitText.setPosition(475, 380);
    exitText.setCharacterSize(22);
    if (colorSettings)
        exitText.setFillColor(Color(241, 196, 15));


    fenetre.setSize(Vector2u(UI_WIDTH, UI_HEIGHT));
    fenetre.clear(Color::Black);
    fenetre.draw(fondo);
    fenetre.draw(playText);
    fenetre.draw(exitText);
    fenetre.display();
}


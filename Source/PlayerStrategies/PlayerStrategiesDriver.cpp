#include "../../Header/PlayerStrategies/PlayerStrategiesDriver.h"
#include "../../Header/PlayerStrategies/PlayerStrategies.h"
#include "../../Header/Map/Map.h"
#include "../../Header/GameEngine/GameEngine.h"
#include "../../Header/Player/Player.h"
#include "../../Header/Cards/Cards.h"
#include "../../Header/Orders/Orders.h"

#include <iostream>
using std::cout;
using std::endl;

void testPlayerStrategies()
{
    cout << "-----------------------------------------------------------\n"
         << "\t** PART 1: PLAYER STRATEGY PATTERN **\n\n";

    // setup game engine (just to test access to the deck), territories, and players to test
    GameEngine *game = new GameEngine();
    GameEngine::getDeck()->createDeck();

    Territory *territories[7] = {new Territory(0, "Villeray", 4), new Territory(1, "Little Italy", 4),
                                 new Territory(2, "Mile End", 3), new Territory(3, "Plateau", 3),
                                 new Territory(4, "Mount Royal", 2), new Territory(5, "Downtown", 1),
                                 new Territory(6, "The Village", 1)};

    territories[0]->addAdjacentTerritory(territories[1]);
    territories[1]->addAdjacentTerritory(territories[0]);
    territories[1]->addAdjacentTerritory(territories[2]);
    territories[2]->addAdjacentTerritory(territories[1]);
    territories[2]->addAdjacentTerritory(territories[3]);
    territories[3]->addAdjacentTerritory(territories[2]);
    territories[3]->addAdjacentTerritory(territories[4]);
    territories[4]->addAdjacentTerritory(territories[3]);
    territories[3]->addAdjacentTerritory(territories[6]);
    territories[6]->addAdjacentTerritory(territories[3]);
    territories[4]->addAdjacentTerritory(territories[5]);
    territories[5]->addAdjacentTerritory(territories[4]);
    territories[5]->addAdjacentTerritory(territories[6]);
    territories[6]->addAdjacentTerritory(territories[5]);
    territories[2]->addAdjacentTerritory(territories[4]);
    territories[4]->addAdjacentTerritory(territories[2]);

    cout << "-----------------------------------------------------------\n"
         << "*CREATED TEST TERRITORIES*\n\n";
    for (Territory *territory : territories)
        cout << *territory;
    cout << "-----------------------------------------------------------\n";

    Player *tina = new Player("Tina", new AggressivePlayerStrategy);
    Player *eugene = new Player("Eugene", new AggressivePlayerStrategy);
    Player *louise = new Player("Louise", new AggressivePlayerStrategy);

    game->addPlayer(tina);
    game->addPlayer(eugene);
    game->addPlayer(louise);

    // assign territories for testing
    tina->addTerritory(territories[4]);
    tina->addTerritory(territories[5]);
    tina->addTerritory(territories[6]);
    eugene->addTerritory(territories[0]);
    eugene->addTerritory(territories[3]);
    louise->addTerritory(territories[1]);
    louise->addTerritory(territories[2]);

    tina->addReinforcements(50);
    eugene->addReinforcements(50);
    louise->addReinforcements(50);

    territories[4]->setArmyUnits(5);
    territories[0]->setArmyUnits(5);
    territories[5]->setArmyUnits(10);
    territories[1]->setArmyUnits(20);
    territories[3]->setArmyUnits(20);
    territories[2]->setArmyUnits(5);
    territories[6]->setArmyUnits(8);

    eugene->getHand()->addToHand(GameEngine::getDeck()->draw());
    tina->getHand()->addToHand(GameEngine::getDeck()->draw());
    louise->getHand()->addToHand(GameEngine::getDeck()->draw());
    eugene->getHand()->addToHand(GameEngine::getDeck()->draw());
    tina->getHand()->addToHand(GameEngine::getDeck()->draw());
    louise->getHand()->addToHand(GameEngine::getDeck()->draw());
    eugene->getHand()->addToHand(GameEngine::getDeck()->draw());
    tina->getHand()->addToHand(GameEngine::getDeck()->draw());
    louise->getHand()->addToHand(GameEngine::getDeck()->draw());
    eugene->getHand()->addToHand(GameEngine::getDeck()->draw());
    tina->getHand()->addToHand(GameEngine::getDeck()->draw());
    louise->getHand()->addToHand(GameEngine::getDeck()->draw());

    cout << "-----------------------------------------------------------\n"
         << "\t\t~~~~~~ORDERS ISSUING~~~~~~~\n"
         << "-----------------------------------------------------------\n";

    for (int i = 0; i < 8; i++)
    {
        cout << "-----------------------------------------------------------\n";
        tina->issueOrder();
        cout << "-----------------------------------------------------------\n";
        louise->issueOrder();
        cout << "-----------------------------------------------------------\n";
        eugene->issueOrder();
    }

    cout << "-----------------------------------------------------------\n"
         << "\t\t~~~~~~ORDERS EXECUTION~~~~~~~"
         << "-----------------------------------------------------------\n";

    Order *next;
    for (int i = 0; i < 8; i++)
    {
        cout << "-----------------------------------------------------------\n";
        if ((next = tina->nextOrder()))
            next->execute();
        cout << "-----------------------------------------------------------\n";
        if ((next = eugene->nextOrder()))
            next->execute();
        cout << "-----------------------------------------------------------\n";
        if ((next = louise->nextOrder()))
            next->execute();
    }
}

#include "../../Header/PlayerStrategies/PlayerStrategiesDriver.h"
#include "../../Header/PlayerStrategies/PlayerStrategies.h"
#include "../../Header/Map/Map.h"
#include "../../Header/GameEngine/GameEngine.h"
#include "../../Header/Player/Player.h"
#include "../../Header/Cards/Cards.h"

#include <iostream>
using std::cout;
using std::endl;

void testPlayerStrategies()
{
    cout << "-----------------------------------------------------------\n"
         << "\t** PART 1: PLAYER STRATEGY PATTERN **\n\n";

    // setup game engine (just to test access to the deck), territories, and players to test
    GameEngine *game = new GameEngine();

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

    Player *tina = new Player("Tina", new HumanPlayerStrategy);
    Player *eugene = new Player("Eugene", new HumanPlayerStrategy);
    Player *louise = new Player("Louise", new HumanPlayerStrategy);

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

    territories[4]->setArmyUnits(20);
    territories[1]->setArmyUnits(20);
    territories[3]->setArmyUnits(20);

    eugene->getHand()->addToHand(new BombCard());
    tina->getHand()->addToHand(new BombCard());
    louise->getHand()->addToHand(new ReinforcementCard());
    eugene->getHand()->addToHand(new DiplomacyCard());
    tina->getHand()->addToHand(new AirliftCard());
    louise->getHand()->addToHand(new DiplomacyCard());
    eugene->getHand()->addToHand(new AirliftCard());
    tina->getHand()->addToHand(new BlockadeCard());
    louise->getHand()->addToHand(new BlockadeCard());

    cout << "-----------------------------------------------------------\n";
    // issue test deploy orders
    tina->issueOrder();
    cout << "-----------------------------------------------------------\n";
    louise->issueOrder();
    cout << "-----------------------------------------------------------\n";
    eugene->issueOrder();
    cout << "-----------------------------------------------------------\n";
    tina->issueOrder();
    cout << "-----------------------------------------------------------\n";
    louise->issueOrder();
    cout << "-----------------------------------------------------------\n";
    eugene->issueOrder();
    cout << "-----------------------------------------------------------\n";
    tina->issueOrder();
    cout << "-----------------------------------------------------------\n";
    louise->issueOrder();
    cout << "-----------------------------------------------------------\n";
    eugene->issueOrder();
    cout << "-----------------------------------------------------------\n";
    tina->issueOrder();
    cout << "-----------------------------------------------------------\n";
    louise->issueOrder();
    cout << "-----------------------------------------------------------\n";
    eugene->issueOrder();
    cout << "-----------------------------------------------------------\n";
    tina->issueOrder();
    cout << "-----------------------------------------------------------\n";
    louise->issueOrder();
    cout << "-----------------------------------------------------------\n";
    eugene->issueOrder();
    cout << "-----------------------------------------------------------\n";
    tina->issueOrder();
    cout << "-----------------------------------------------------------\n";
    louise->issueOrder();
    cout << "-----------------------------------------------------------\n";
    eugene->issueOrder();
    cout << "-----------------------------------------------------------\n";
    tina->issueOrder();
    cout << "-----------------------------------------------------------\n";
    louise->issueOrder();
    cout << "-----------------------------------------------------------\n";
    eugene->issueOrder();
    cout << "-----------------------------------------------------------\n";
    tina->issueOrder();
    cout << "-----------------------------------------------------------\n";
    louise->issueOrder();
    cout << "-----------------------------------------------------------\n";
    eugene->issueOrder();
    cout << "-----------------------------------------------------------\n";
}

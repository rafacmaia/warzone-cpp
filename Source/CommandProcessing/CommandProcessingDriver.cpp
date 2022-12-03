#include "../../Header/CommandProcessing/CommandProcessingDriver.h"
#include "../../Header/CommandProcessing/CommandProcessing.h"
#include "../../Header/GameEngine/GameEngine.h"
#include "../../Header/GameEngine/GameEngineDriver.h"

void testCommandProcessor()
{
    CommandProcessor* commandProcessor = nullptr;
    GameEngine::State currentState = GameEngine::State::End;

    while (commandProcessor == nullptr || currentState == GameEngine::State::End) {
        GameEngine* gameEngine = new GameEngine();
        currentState = GameEngine::State::Start;
        commandProcessor = gameEngine->initializeCommandProcessor();
        
        // if(commandProcessor != NULL){
        while (currentState != GameEngine::State::End)
        {
            currentState = gameEngine->startupPhase(gameEngine->getState(), commandProcessor);
        }
        
        if (commandProcessor != nullptr)
        {
            delete commandProcessor;
            commandProcessor = nullptr;
            delete gameEngine;
            gameEngine = nullptr;
            break;
        }
    }
}
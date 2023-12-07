#include "ObjectiveManager.h"
#include <random>
#include <functional>

ObjectiveManager::ObjectiveManager()
{   
    _objectivesAmount = Data::ObjectivesPositions.size();

    srand(time(NULL));

    for (int i = 0; i < _objectivesAmount; ++i) {
        
        _objectives.push_back(make_unique<Objective>(i));
    }

    _visibleTime = Data::ObjectiveVisibleTime;
    _clock.restart();

    ActivateRandomObjective();
}
    
int ObjectiveManager::GetCurrentVisibleIndex() {
    return _currentVisibleIndex;
}

void ObjectiveManager::ActivateRandomObjective()
{
    int randomNum;
    int max = _objectivesAmount - 1;

    do {
        //TODO: try to set randomly an array between 1 and 2 with random elements to activate
        randomNum = rand() % (max - 0 + 1);
        _objectives[randomNum]->SetActive();
        _previousVisibleIndex = _currentVisibleIndex;
        _currentVisibleIndex = randomNum;

    } while (randomNum == _currentVisibleIndex && _previousVisibleIndex ==_currentVisibleIndex);
}

void ObjectiveManager::SetCurrentObjectiveInactive() {
    if(_currentVisibleIndex>=0)
        _objectives[_currentVisibleIndex]->SetInactive();
}

void ObjectiveManager::UpdateAll()
{
    if (_clock.getElapsedTime().asSeconds()>_visibleTime) {
        SetCurrentObjectiveInactive();
        ActivateRandomObjective();
        SetInnocentOrEnemy();
        _clock.restart();
    }

    for(auto& objective: _objectives)
    {
        if (objective->IsActive()) {
            objective->Update();
        }
    }
}
void ObjectiveManager::SetInnocentOrEnemy() {
    //Generate random boolean to determine if its innocent or enemy
    //solution from: https://stackoverflow.com/a/43329456
    static auto randomNum = bind(uniform_int_distribution<>(0, 1), default_random_engine());
    
    if(randomNum())
        _objectives[_currentVisibleIndex]->SetAsNoInnocent();
    else
        _objectives[_currentVisibleIndex]->SetAsInnocent();
}

void ObjectiveManager::DrawAll(RenderWindow& window)
{
    for (auto& objective : _objectives) {
        if (objective->IsActive()) {
            objective->Draw(&window);
        }
    }
}

Enum ObjectiveManager::ObjectiveCollided(Vector2i position)
{
    bool check = _objectives[_currentVisibleIndex]->CheckCollision(position);

    if (check) {        
        _objectives[_currentVisibleIndex]->SetInactive();
        _clock.restart();
        int indexObjectiveKilled = _currentVisibleIndex;
        ActivateRandomObjective();

        return _objectives[indexObjectiveKilled]->IsInnocent()? Innocent : Enemy;
    
    }
    return None;
}



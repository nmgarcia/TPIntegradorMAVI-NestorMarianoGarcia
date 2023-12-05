#include "ObjectiveManager.h"

ObjectiveManager::ObjectiveManager()
{   
    _objectivesAmount = Data::ObjectivesPositions.size();

    srand(time(NULL));

    for (int i = 0; i < _objectivesAmount; ++i) {
        
        _objectives.push_back(make_unique<Objective>(i));
    }
    _visibleTime = 2.0f;
    _clock.restart();
}
    
int ObjectiveManager::GetCurrentVisibleIndex() {
    return _currentVisibleIndex;
}

void ObjectiveManager::ActivateRandomObjective()
{
    int randomNum;
    int max = _objectivesAmount - 1;

    do {
        randomNum = rand() % (max - 0 + 1);
        _objectives[randomNum]->SetActive();
        _currentVisibleIndex = randomNum;
    } while (randomNum != _currentVisibleIndex);
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
        _clock.restart();
    }

    for(auto& objective: _objectives)
    {
        if (objective->IsActive()) {
            objective->Update();
        }
    }
}

void ObjectiveManager::DrawAll(RenderWindow& window)
{
    for (auto& objective : _objectives) {
        if (objective->IsActive()) {
            objective->Draw(&window);
        }
    }
}



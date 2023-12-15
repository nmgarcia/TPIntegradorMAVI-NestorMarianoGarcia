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
    
    ActivateRandomObjective();
}
   
void ObjectiveManager::RestartObjectiveManager() {
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
        randomNum = rand() % (max - 0 + 1);
        _objectives[randomNum]->SetActive();
        _previousVisibleIndex = _currentVisibleIndex;
        _currentVisibleIndex = randomNum;

    } while (randomNum == _currentVisibleIndex && _previousVisibleIndex ==_currentVisibleIndex);

    SetInnocentOrEnemy();
    
    _clock.restart();
}

void ObjectiveManager::UpdateAll()
{
    if (_clock.getElapsedTime().asSeconds()>_visibleTime) {
        EnemyAttack();        
        SetAllAsInactive();
        ActivateRandomObjective();
    }
}

void ObjectiveManager::SetAllAsInactive() {
    int counter = 0;
    for (auto& objective : _objectives)
    {
        if (objective->IsActive())counter++;

        objective->SetInactive();
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

Enum ObjectiveManager::GetObjectCollided(Vector2i position)
{
    bool check = _objectives[_currentVisibleIndex]->CheckCollision(position);

    if (check) {

        SetAllAsInactive();
        int indexObjectiveKilled = _currentVisibleIndex;
        ActivateRandomObjective();

        return _objectives[indexObjectiveKilled]->IsInnocent()? Innocent : Enemy;
    
    }
    return None;
}

void ObjectiveManager::EnemyAttack() {

    if (!_objectives[_currentVisibleIndex]->IsInnocent() && !_isAttacking) {
        _isAttacking = true;
    }
}

bool ObjectiveManager::IsAttacking()
{
    return _isAttacking;
}

void ObjectiveManager::SetIsAttackingFalse()
{
    _isAttacking = false;
}


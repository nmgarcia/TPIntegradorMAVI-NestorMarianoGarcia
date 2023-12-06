#include "Objective.h"

Objective::Objective()
{
	Initilize();
}

Objective::Objective(int position) {
	Initilize();
	_position = Data::ObjectivesPositions[position]._position;
	_positionNumber = position;
}

void Objective::Initilize() {
	_isActive = false;	
	_objectiveTexture.loadFromFile(Data::assetsPath[Enemy1]);
	SetSprite();
}

void Objective::Update()
{

}

void Objective::Draw(RenderWindow* window)
{	
	if(_isActive) {
		_objectiveSprite.setPosition(_position.x, _position.y+15);
		window->draw(_objectiveSprite);
	}
}

void Objective::SetSprite() {
	_objectiveSprite.setTexture(_objectiveTexture);
	_objectiveSprite.setScale(0.5f, 0.5f);
	_objectiveSprite.setOrigin(_objectiveTexture.getSize().x / 2.0f, _objectiveTexture.getSize().y / 2.0f);
}

bool Objective::IsInnocent(){
	return _isInnocent;
}

void Objective::SetAsInnocent() {
	_objectiveTexture.loadFromFile(Data::assetsPath[Innocent]);
	SetSprite();
	_isInnocent = true;
}

void Objective::SetAsNoInnocent() {
	_objectiveTexture.loadFromFile(Data::assetsPath[Enemy1]);
	SetSprite();
	_isInnocent = false;
}

bool Objective::IsActive() {
	return _isActive;
}

void Objective::SetActive() {
	_isActive = true;
}

void Objective::SetInactive() {
	_isActive = false;
}
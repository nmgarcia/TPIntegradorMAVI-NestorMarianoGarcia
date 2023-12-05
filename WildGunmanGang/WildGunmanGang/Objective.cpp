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
	SetSprite(_objectiveTexture);
}

void Objective::Update()
{

}

void Objective::Draw(RenderWindow* window)
{	
	if(_isActive) {
		_objectiveSprite.setPosition(_position.x, _position.y);
		window->draw(_objectiveSprite);
	}
}

void Objective::SetSprite(Texture& texture) {
	_objectiveSprite.setTexture(texture);
	_objectiveSprite.setScale(0.6f, 0.6f);
	_objectiveSprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
}
bool Objective::IsInnocent(){
	return _isInnocent;
}

void Objective::SetAsInnocent() {
	_isInnocent = true;
}

void Objective::SetAsNoInnocent() {
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
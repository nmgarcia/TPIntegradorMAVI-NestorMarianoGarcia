#include "ObjectivePool.h"


ObjectivePool::ObjectivePool(int poolSize)
{   
    for (int i = 0; i < poolSize; ++i) {
        Objective objective;

        objectives.push_back(objective);
    }
}

    
Objective ObjectivePool::GetEnemy(float x, float y)
{
    // Buscar un enemigo inactivo en el pool y devolverlo
    for (auto& objective : objectives) {
        // Verificar si el enemigo está inactivo (puedes tener una bandera para esto)
        if (!objective.IsActive()) {
            // Reactivar el enemigo y establecer su posición
            objective.Activate();
            return objective;
        }
    }

    // Si todos los enemigos están activos, simplemente devolver el primero
    return objectives.front();
}

// Función para actualizar todos los enemigos en el pool
void ObjectivePool::UpdateAll()
{
    for(Objective objective: objectives)
    {
        if (objective.IsActive()) {
            objective.Update();
        }
    }
}

// Función para dibujar todos los enemigos en la ventana
void ObjectivePool::DrawAll(RenderWindow* window)
{
    for (auto& objective : objectives) {
        if (objective.IsActive()) {
            objective.Draw(window);
        }
    }
}



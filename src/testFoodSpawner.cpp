#include "foodSpawner.h"
#include <iostream>

using namespace std;
int main()
{
    FoodSpawner fs(10, 10);
    vector<SDL_Point> body;
    SDL_Point p1;
    p1.x = 0;
    p1.y = 1;
    body.push_back(p1);
    Food f1 = fs.SpawnFood(body);
    cout << f1.position.x << " " << f1.position.y << endl;
}
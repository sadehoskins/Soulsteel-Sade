//
// Created by lrfri on 14.05.2024.
//

#ifndef RAYLIBSTARTER_GAMEPLAY_H
#define RAYLIBSTARTER_GAMEPLAY_H

#include <vector>
#include "raylib.h"
#include "assestmanagergraphics.h"
#include "scene.h"

class maincharacter;
class enemies;

    class gameplay:public scene {
    public:

        void update() override;

        scene *evaluateSceneChange() override;

        void draw() override;

        void drawDebug() override;

        //loads the necessary textures
        Texture2D heart = assestmanagergraphics::getTexture("userinterface/heart_smaller");
        //Texture2D modeRobo = LoadTexture("assets/graphics/robot_anuki_3.png");
        //Texture2D modeSoul = LoadTexture("assets/graphics/soul_destiny_3.png");

        //loads the textures on the map (Kachelsatz)
        Texture2D tilesetgrass = assestmanagergraphics::getTexture("tilesets/grassesfour");


        //attributes necessary for using the map
        std::vector<int> tiles;
        //int rows;
        //int cols;
        gameplay();
        bool touchesWall(Vector2 pos, float size);
        bool touchesWall(Vector2 pos);
        //bool touchesNextDoor(Vector2 pos, float size);
        //int getTouchedNextDoor(Vector2 position, float radius);

        Vector2 touchWallPosition(Vector2 pos, Vector2 size);
        Rectangle getWallAt(Vector2 pos);
        int getTileAt(float x, float y);
        Rectangle getTouchedWall(Vector2 position, float radius);

        //std::vector<int> tileMap;
        int mapWidth = 25;
        int mapHeight = 15;

        maincharacter *themaincharacter;
        enemies *enemies;

        int room=1;
        bool hasbeeninroom1before =false;

        void reloadRoom();
    };




#endif //RAYLIBSTARTER_GAMEPLAY_H

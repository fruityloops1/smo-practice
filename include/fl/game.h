#pragma once

class StageScene;
class PlayerActorHakoniwa;

namespace fl {

class Game {
public:
    static inline Game& instance() {static Game ui; return ui;}
    void setStageScene(StageScene* stage_scene);
    PlayerActorHakoniwa* getPlayer() const;

    void killMario();
    void damageMario(int amount);
    void lifeUpHeart();
    void healMario();
    void removeCappy();
    void invincibilityStar();

private:
    StageScene* mStageScene;

};

}

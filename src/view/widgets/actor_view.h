#include "widget.h"
#include "ui_manager.h"

class Label;

namespace Core::AI {
class Actor;
}

class ActorView: public Widget {
public:
    ActorView(int x, int y, const UIManager& uiManager, View& view);
    virtual ~ActorView();

    void updateLabels();
    void nextActor();
    void prevActor();


    virtual void draw(SDL_Renderer *renderer);
private:
    Core::AI::Actor* actor = nullptr;

    Label* nameLabel;
    Label* foodLabel;
    Label* waterLabel;
    Label* placeLabel;

    const UIManager& _uiManager;
    View& _view;
};
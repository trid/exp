#include "widget.h"
#include "ui_manager.h"

namespace Core::AI::Actors {
class Agent;
} // namespace Core::AI::Actors

namespace View::Widgets {

class Label;

class ActorView : public Widget {
public:
    ActorView(int x, int y, const UIManager& uiManager, ViewFacade& view);
    virtual ~ActorView();

    void updateLabels();
    void nextActor();
    void prevActor();


    virtual void draw(SDL_Renderer* renderer);
private:
    Core::AI::Actors::Agent* actor = nullptr;

    Label* nameLabel;
    Label* foodLabel;
    Label* waterLabel;
    Label* placeLabel;

    const UIManager& _uiManager;
    ViewFacade& _view;
};

} // namespace View::Widgets
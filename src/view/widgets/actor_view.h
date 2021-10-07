#include "widget.h"
#include "ui_manager.h"

namespace Core::AI {
class Actor;
}

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
    Core::AI::Actor* actor = nullptr;

    Label* nameLabel;
    Label* foodLabel;
    Label* waterLabel;
    Label* placeLabel;

    const UIManager& _uiManager;
    ViewFacade& _view;
};

} // namespace View::Widgets
#include "widget.h"
#include "ui_manager.h"

class Actor;
class Label;

class ActorView: public Widget {
public:
    ActorView(int x, int y, UIManager& uiManager, View& view);
    virtual ~ActorView();

    void updateLabels();
    void nextActor();
    void prevActor();


    virtual void draw(SDL_Renderer *renderer);
private:
    Actor* actor = nullptr;

    Label* nameLabel;
    Label* foodLabel;
    Label* waterLabel;
    Label* placeLabel;

    UIManager& _uiManager;
    View& _view;
};
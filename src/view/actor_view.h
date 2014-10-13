#include "widget.h"

class Actor;
class Label;

class ActorView: public Widget {
private:
    Actor* actor;

    Label* nameLabel;
    Label* foodLabel;
    Label* waterLabel;
    Label* placeLabel;
public:
    ActorView(int x, int y);
    virtual ~ActorView();

    void updateLabels();
    void nextActor();
    void prevActor();


    virtual void draw(SDL_Renderer *renderer);
};
#ifndef ACTOR_VIEW_H
#define ACTOR_VIEW_H

#include "private/render_target.h"
#include "widget.h"
#include "ui_manager.h"

namespace Core::AI::Actors {
class Agent;
} // namespace Core::AI::Actors

namespace View::Widgets {

class Label;

class ActorView : public Widget {
public:
    ActorView(int x, int y, UIManager& uiManager, ViewFacade& view);
    virtual ~ActorView();

    void updateLabels();
    void nextActor();
    void prevActor();


    virtual void draw(Window& window);
private:
    Core::AI::Actors::Agent* actor = nullptr;

    Font _font;

    Label* nameLabel;
    Label* foodLabel;
    Label* waterLabel;
    Label* placeLabel;

    ViewFacade& _view;

    RenderTarget _renderTarget;
};

} // namespace View::Widgets

#endif // ACTOR_VIEW_H
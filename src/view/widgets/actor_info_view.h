#ifndef ACTOR_VIEW_H
#define ACTOR_VIEW_H

#include <boost/optional.hpp>

#include "widget.h"
#include "ui_manager.h"

#include "private/render_target.h"

namespace Core {
class World;
} // namespace Core

namespace Core::AI::Agents {
class Agent;
class AgentsRegistry;
} // namespace Core::AI::Agents

namespace View::Widgets {

class Label;

class ActorInfoView : public Widget {
public:
    ActorInfoView(int x, int y, const Core::World& world, UIManager& uiManager, ViewFacade& view);

    void updateLabels();
    void nextActor();
    void prevActor();

    void draw(Window& window) override;
private:
    boost::optional<const Core::AI::Agents::Agent&> _actor = boost::none;

    Font _font;

    std::unique_ptr<Label> _nameLabel;
    std::unique_ptr<Label> _foodLabel;
    std::unique_ptr<Label> _waterLabel;
    std::unique_ptr<Label> _placeLabel;

    RenderTarget _renderTarget;

    const Core::World& _world;
};

} // namespace View::Widgets

#endif // ACTOR_VIEW_H
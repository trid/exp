//
// Created by TriD on 30.09.2021.
//

#ifndef EXP_VIEW_CONSTANTS_H
#define EXP_VIEW_CONSTANTS_H

namespace View {

// Locations view
constexpr char kLocationsImagesDataPath[] = "res/locations/location_images.xml";
constexpr char kLocationKey[] = "locations";
constexpr char kLocationTypeKey[] = "name";
constexpr char kSpriteNameKey[] = "sprite";
constexpr char kImageResourcesPath[] = "res/img/";

// ViewFacade
constexpr char kSDLInitErrorMessage[] = "SDL_Init error";
constexpr char kSDLCreateWindowError[] = "SDL_CreateWindow error";
constexpr char kSDLCreateRendererError[] = "SDL_CreateRenderer error";
constexpr char kGrassSpritePath[] = "res/img/grass.jpg";
constexpr char kActorGreenSpritePath[] = "res/img/actor_green.png";
constexpr char kActorBlueSpritePath[] = "res/img/actor_blue.png";
constexpr char kActorGreenType[] = "green";
constexpr char kActorBlueType[] = "blue";

} // namespace View

#endif //EXP_VIEW_CONSTANTS_H

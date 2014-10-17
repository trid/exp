#include <string>
#include <unordered_map>
#include <list>
#include "map_object.h"

using std::unordered_map;
using std::list;
using std::string;

class SceneObjectManager {
private:
    SceneObjectManager(){};
    unordered_map<string, MapObjectPtr> mapObjects;
public:
    static SceneObjectManager& getInstance() {
        static SceneObjectManager som;
        return som;
    }

    MapObject* createMapObject(int x, int y, const string &path, const string& name);
    void removeSceneObject(const string& name);
    MapObjectPtr getMapObject(const string& name);
    void draw(SDL_Renderer* renderer);
};
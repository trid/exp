//
// Created by TriD on 25.10.2021.
//

#ifndef EXP_FONTS_CACHE_H
#define EXP_FONTS_CACHE_H

#include <string>
#include <unordered_map>
#include <utility>

#include <boost/functional/hash.hpp>

#include <SDL2/SDL_ttf.h>

#include "font.h"

namespace View {

using FontsCacheKey = std::pair<std::string, int>;

struct PairHash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        std::size_t seed = 0;
        boost::hash_combine(seed, h1);
        boost::hash_combine(seed, h2);
        return seed;
    }
};

class FontsCache {
public:
    FontsCache();
    ~FontsCache();

    Font getFont(const std::string& path, int size);
private:
    std::unordered_map<FontsCacheKey, TTF_Font*, PairHash> _cachedFonts;
};

}

#endif //EXP_FONTS_CACHE_H

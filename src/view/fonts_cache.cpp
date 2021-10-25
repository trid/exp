//
// Created by TriD on 25.10.2021.
//

#include "fonts_cache.h"

View::FontsCache::FontsCache() {
    if (!TTF_WasInit()) {
        TTF_Init();
    }
}

View::FontsCache::~FontsCache() {
    for (const auto& item: _cachedFonts) {
        TTF_CloseFont(item.second);
    }
    _cachedFonts.clear();

    TTF_Quit();
}

Font View::FontsCache::getFont(const std::string& path, int size) {
    auto it = _cachedFonts.find(std::make_pair(path, size));

    if (it != _cachedFonts.end()) {
        return Font(it->second);
    }

    auto inserted = _cachedFonts.emplace(std::make_pair(path, size), TTF_OpenFont(path.c_str(), size));

    return Font(inserted.first->second);
}


#include <SDL_render.h>
#include <SDL_ttf.h>
#include "log_view.h"
#include "view.h"
#include "ui_manager.h"

void LogView::draw(SDL_Renderer *renderer) {
    View &view = View::getView();
    UIManager &uiManager = UIManager::getInstance();
    if (dirty) {
        if (surface) {
            SDL_DestroyTexture(surface);
        }
        int height = TTF_FontHeight(uiManager.getConsoleFont());
        int startHeight = 0;
        int surfaceHeight = height * 10;
        surface = SDL_CreateTexture(renderer, view.getScreenPixelFormat(), SDL_TEXTUREACCESS_TARGET, view.getWindowWidth(), surfaceHeight);
        SDL_SetTextureBlendMode(surface, SDL_BLENDMODE_BLEND);
        SDL_SetRenderTarget(renderer, surface);

        SDL_SetRenderDrawColor(renderer, 10, 10, 50, 100);
        SDL_RenderClear(renderer);

        for (string& str: messages) {
            SDL_Surface* renderedSurface = TTF_RenderText_Solid(uiManager.getConsoleFont(), str.c_str(), textColor);
            SDL_Texture* renderedText = SDL_CreateTextureFromSurface(renderer, renderedSurface);
            SDL_FreeSurface(renderedSurface);
            SDL_Rect rect;
            rect.x = 0;
            rect.y = startHeight;
            SDL_QueryTexture(renderedText, nullptr, nullptr, &rect.w, &rect.h);
            SDL_RenderCopy(renderer, renderedText, nullptr, &rect);
            SDL_DestroyTexture(renderedText);
            startHeight += height;
        }

        SDL_SetRenderTarget(renderer, nullptr);
    }
    SDL_Rect rect;
    rect.x = getX();
    rect.y = getY();
    SDL_QueryTexture(surface, nullptr, nullptr, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, surface, nullptr, &rect);
}

void LogView::addMessage(const string &message) {
    messages.push_back(message);
    while (messages.size() > 10) {
        messages.pop_front();
    }

    dirty = true;
}

LogView::LogView(int x, int y): Widget(x, y) {
    textColor.r = 255;
    textColor.g = 255;
    textColor.b = 255;
}

#pragma once

#include "sead/devenv/seadDebugFontMgrNvn.h"
#include "sead/textwriter.h"
#include "sead/basis/seadNew.hpp"
#include "sead/gfx/seadViewport.h"

#include "agl/DrawContext.h"
#include "agl/utl.h"
#include "game/HakoniwaSequence/HakoniwaSequence.h"

#include "game/System/GameSystem.h"

#include "al/util.hpp"

extern sead::TextWriter *gTextWriter;

extern bool showMenu;
extern bool isInGame;

bool setupDebugMenu(agl::DrawContext *context, sead::Viewport *viewport);
void drawBackground(agl::DrawContext *context);
void drawMainHook(HakoniwaSequence *curSequence, sead::Viewport *viewport, sead::DrawContext *drawContext);
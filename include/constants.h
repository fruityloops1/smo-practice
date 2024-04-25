#pragma once

namespace constants {

// Fadeoff distances for the rendering
// It's done in drawer.cpp like this:
// (maxDist-al::calcDistance(player, pos))/maxDist * maxAlpha
constexpr float minDist = 15000;
constexpr float maxDist = 20000;
constexpr float maxAlpha = .2;

} // namespace constants

#include "graphics/style.h"

namespace cvg
{

void style::set_fill(color c)
{
  fill_ = c;
}

void style::set_stroke(color c)
{
  stroke_ = c;
}

void style::set_stroke_width(float w)
{
  stroke_width_ = w;
}

color style::fill(color def)
{
  return fill_.value_or(def);
}

color style::stroke(color def)
{
  return stroke_.value_or(def);
}

float style::stroke_width(float def)
{
  return stroke_width_.value_or(def);
}

} //namespace


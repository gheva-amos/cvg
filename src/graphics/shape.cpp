#include "graphics/shape.h"

namespace cvg
{

void shape::fill(color c)
{
  style_.set_fill(c);
}

void shape::stroke(color c)
{
  style_.set_stroke(c);
}

void shape::stroke_width(float w)
{
  style_.set_stroke_width(w);
}


} //namespace


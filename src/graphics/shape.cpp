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

const style& shape::get_style() const
{
  return style_;
}

void shape::move_to(float x, float y)
{
  transform_.x() = x;
  transform_.y() = y;
}

void shape::rotate(float degrees)
{
  transform_.deg() = degrees;
}

const transform& shape::get_transform() const
{
  return transform_;
}

} //namespace


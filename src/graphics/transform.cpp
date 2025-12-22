#include "graphics/transform.h"

namespace cvg
{

transform::transform(float x, float y, float deg) :
  x_{x}, y_{y}, deg_{deg}, todo_{true}
{
}

transform::transform() :
  todo_{false}
{
}

float& transform::x()
{
  todo_ = true;
  return x_;
}

float& transform::y()
{
  todo_ = true;
  return y_;
}

float& transform::deg()
{
  todo_ = true;
  return deg_;
}


float transform::x() const
{
  return x_;
}

float transform::y() const
{
  return y_;
}

float transform::deg() const
{
  return deg_;
}

bool transform::todo() const
{
  return todo_;
}

} // namespace


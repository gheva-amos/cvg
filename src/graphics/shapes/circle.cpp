#include "graphics/shapes/circle.h"
#include "graphics/visitor.h"

namespace cvg
{

circle::circle(float x, float y, float r) :
  x_{x}, y_{y}, r_{r}
{
}

float circle::x() const
{
  return x_;
}

float circle::y() const
{
  return y_;
}

float circle::r() const
{
  return r_;
}

void circle::accept(visitor& v) const
{
  v.visit(*this);
  v.done(*this);
}

} // namespace


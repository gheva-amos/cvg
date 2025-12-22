#include "graphics/shapes/circle.h"
#include "graphics/visitor.h"

namespace cvg
{

circle::circle(size_t x, size_t y, size_t r) :
  x_{x}, y_{y}, r_{r}
{
}

size_t circle::x() const
{
  return x_;
}

size_t circle::y() const
{
  return y_;
}

size_t circle::r() const
{
  return r_;
}

void circle::accept(visitor& v) const
{
  v.visit(*this);
  v.done(*this);
}

} // namespace


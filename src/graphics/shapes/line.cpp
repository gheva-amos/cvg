#include "graphics/shapes/line.h"
#include "graphics/visitor.h"

namespace cvg
{

line::line(float x0, float y0, float x1, float y1) :
  x0_{x0}, y0_{y0}, x1_{x1}, y1_{y1}
{
}

float line::x0() const
{
  return x0_;
}

float line::y0() const
{
  return y0_;
}

float line::x1() const
{
  return x1_;
}

float line::y1() const
{
  return y1_;
}


float& line::x0()
{
  return x0_;
}

float& line::y0()
{
  return y0_;
}

float& line::x1()
{
  return x1_;
}

float& line::y1()
{
  return y1_;
}

void line::accept(visitor& v) const
{
  v.visit(*this);
}

} // namespace

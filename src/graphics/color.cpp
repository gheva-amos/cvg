#include "graphics/color.h"

namespace cvg
{

color::color(int r, int g, int b, int a) :
  red_{r}, green_{g}, blue_{b}, alpha_{a}, none_{false}
{
}

color::color() :
  none_{true}
{
}

bool color::none() const
{
  return none_;
}

int color::red() const
{
  return red_;
}

int color::green() const
{
  return green_;
}

int color::blue() const
{
  return blue_;
}

int color::alpha() const
{
  return alpha_;
}

double color::alpha_frac() const
{
  return alpha_ / 255.0;
}

} // namespace


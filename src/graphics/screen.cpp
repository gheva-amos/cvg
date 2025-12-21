#include "graphics/screen.h"

namespace cvg
{

screen::screen(size_t h, size_t w) :
  height_{h}, width_{w}
{
}

size_t& screen::height()
{
  return height_;
}

size_t screen::height() const
{
  return height_;
}

size_t& screen::width()
{
  return width_;
}

size_t screen::width() const
{
  return width_;
}

void screen::fill(color c)
{
  style_.set_fill(c);
}

void screen::stroke(color c)
{
  style_.set_stroke(c);
}

void screen::stroke_width(float w)
{
  style_.set_stroke_width(w);
}

void screen::accept(visitor& visitor)
{
  visitor.visit(*this);

  for (const auto& s : shapes_)
  {
    s->accept(visitor);
  }
}

}


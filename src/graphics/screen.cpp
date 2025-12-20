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

}


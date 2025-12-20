#ifndef CVG_GRAPHICS_SCREEN_H__
#define CVG_GRAPHICS_SCREEN_H__
#include <cstddef>

namespace cvg
{

class screen
{
public:
  screen(size_t h, size_t w);
  virtual ~screen() = default;
  size_t& height();
  size_t height() const;
  size_t& width();
  size_t width() const;
protected:
  size_t height_;
  size_t width_;
};

} // namespace

#endif // CVG_GRAPHICS_SCREEN_H__

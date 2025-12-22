#ifndef CVG_GRAPHICS_STYLE_H__
#define CVG_GRAPHICS_STYLE_H__
#include <optional>
#include "graphics/color.h"

namespace cvg
{

class style
{
public:

  color fill(color def=color{}) const;
  color stroke(color def=color{0, 0, 0, 255}) const;
  float stroke_width(float def=1.0) const;

  void set_fill(color c);
  void set_stroke(color c);
  void set_stroke_width(float w);
private:
  std::optional<color> fill_;
  std::optional<color> stroke_;
  std::optional<float> stroke_width_;
};

} //namespace

#endif // CVG_GRAPHICS_STYLE_H__

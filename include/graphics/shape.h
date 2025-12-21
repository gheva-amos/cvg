#ifndef CVG_GRAPHICS_SHAPE_H__
#define CVG_GRAPHICS_SHAPE_H__

#include "graphics/style.h"

namespace cvg
{

class visitor;

class shape
{
public:
  virtual ~shape() = default;
  virtual void accept(visitor& v) const = 0;
  void fill(color c);
  void stroke(color c);
  void stroke_width(float w);
protected:
  style style_;
};

} // namespace

#endif // CVG_GRAPHICS_SHAPE_H__

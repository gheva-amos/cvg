#ifndef CVG_GRAPHICS_SHAPE_H__
#define CVG_GRAPHICS_SHAPE_H__

#include "graphics/style.h"
#include "graphics/transform.h"

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
  
  const style& get_style() const;

  void move_to(float x, float y);
  void rotate(float degrees);
  const transform& get_transform() const;
protected:
  style style_;
  transform transform_;
};

} // namespace

#endif // CVG_GRAPHICS_SHAPE_H__

#ifndef CVG_SHAPES_CIRCLE_H__
#define CVG_SHAPES_CIRCLE_H__
#include "graphics/shape.h"

namespace cvg
{

class circle final : public shape
{
public:
  circle(size_t x, size_t y, size_t r);

  virtual void accept(visitor& v) const override;

  size_t x() const;
  size_t y() const;
  size_t r() const;
private:
  size_t x_;
  size_t y_;
  size_t r_;
};

}

#endif // CVG_SHAPES_CIRCLE_H__

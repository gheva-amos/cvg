#ifndef CVG_SHAPES_CIRCLE_H__
#define CVG_SHAPES_CIRCLE_H__
#include "graphics/shape.h"

namespace cvg
{

class circle final : public shape
{
public:
  circle(float x, float y, float r);

  virtual void accept(visitor& v) const override;

  float x() const;
  float y() const;
  float r() const;
private:
  float x_;
  float y_;
  float r_;
};

}

#endif // CVG_SHAPES_CIRCLE_H__

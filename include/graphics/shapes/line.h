#ifndef CVG_SHAPES_LINE_H__
#define CVG_SHAPES_LINE_H__

#include "graphics/shape.h"

namespace cvg
{

class line final : public shape
{
public:

  line(float x0, float y0, float x1, float y1);
  float x0() const;
  float y0() const;
  float x1() const;
  float y1() const;

  float& x0();
  float& y0();
  float& x1();
  float& y1();

  virtual void accept(visitor& v) const override;
private:
  float x0_;
  float y0_;
  float x1_;
  float y1_;
};

} // namespace

#endif // CVG_SHAPES_LINE_H__

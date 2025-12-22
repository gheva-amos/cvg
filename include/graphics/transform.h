#ifndef CVG_GRAPHICS_TRANSFORM_H__
#define CVG_GRAPHICS_TRANSFORM_H__

namespace cvg
{

class transform
{
public:
  transform(float x, float y, float deg=0.0);
  transform();

  float& x();
  float& y();
  float& deg();

  float x() const;
  float y() const;
  float deg() const;

  bool todo() const;
private:
  float x_;
  float y_;
  float deg_;
  bool todo_;
};

} // namespace

#endif // CVG_GRAPHICS_TRANSFORM_H__

#ifndef CVG_GRAPHICS_COLOR_H__
#define CVG_GRAPHICS_COLOR_H__

namespace cvg
{

class color
{
public:
  color(int r, int g, int b, int a=255);
  color();

  bool none() const;

  int red() const;
  int green() const;
  int blue() const;
  int alpha() const;
  double alpha_frac() const;
private:
  int red_;
  int green_;
  int blue_;
  int alpha_;
  bool none_;
};

} //namespace

#endif // CVG_GRAPHICS_COLOR_H__

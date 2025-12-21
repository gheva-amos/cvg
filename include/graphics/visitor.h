#ifndef CVG_GRAPHICS_VISITOR_H__
#define CVG_GRAPHICS_VISITOR_H__

namespace cvg
{

class screen;

class visitor
{
public:
  virtual ~visitor() = default;

  virtual void visit(const screen& screen) = 0;
};

} //namespace

#endif // CVG_GRAPHICS_VISITOR_H__

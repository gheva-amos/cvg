#ifndef CVG_GRAPHICS_VISITOR_H__
#define CVG_GRAPHICS_VISITOR_H__
#include <ostream>

namespace cvg
{

class screen;
class circle;
class group;

class visitor
{
public:
  virtual ~visitor() = default;

  virtual void visit(const screen& screen) = 0;
  virtual void visit(const circle& c) = 0;
  virtual void visit(const group& g) = 0;

  virtual void done(const screen& s) = 0;
  virtual void done(const circle& c) = 0;
  virtual void done(const group& g) = 0;

  virtual void write(std::ostream& s) const = 0;
};

} //namespace

#endif // CVG_GRAPHICS_VISITOR_H__

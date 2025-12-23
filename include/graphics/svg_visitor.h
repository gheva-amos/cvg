#ifndef CVG_GRAPHICS_SVG_VISITOR_H__
#define CVG_GRAPHICS_SVG_VISITOR_H__
#include "graphics/visitor.h"
#include "graphics/style.h"
#include "graphics/color.h"
#include "graphics/transform.h"
#include <sstream>

namespace cvg
{

class svg_visitor final : public visitor
{
public:
  virtual void visit(const screen& screen) override;
  virtual void visit(const circle& c) override;
  virtual void visit(const group& g) override;
  virtual void visit(const line& l) override;

  virtual void done(const screen& s) override;
  virtual void done(const circle& c) override;
  virtual void done(const group& g) override;
  virtual void done(const line& l) override;

  virtual void write(std::ostream& s) const override;

private:
  void add_style(const style& s);
  void add_color(const color& c);
  void add_transform(const transform& t);
  std::stringstream data_;
};

} // namespace

#endif // CVG_GRAPHICS_SVG_VISITOR_H__

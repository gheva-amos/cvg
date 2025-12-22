#include "graphics/svg_visitor.h"
#include <iomanip>
#include "graphics/screen.h"
#include "graphics/shapes/circle.h"
#include "graphics/shapes/group.h"

namespace cvg
{

template <typename T>
std::ostream& in_quotes(std::ostream& stream, T val)
{
  stream << '"' << val << '"';
  return stream;
}

void svg_visitor::visit(const screen& screen)
{
  data_ << "<svg xmlns=" << '"' << "http://www.w3.org/2000/svg" << '"' << std::endl;
  data_ << "width=";
  in_quotes(data_, screen.width()) << std::endl;
  data_ << "height=";
  in_quotes(data_, screen.height()) << std::endl;
  data_ << "viewBox=" << '"' << "0 0 " << screen.width() << ' ' << screen.height() << '"' << '>' << std::endl;
}

void svg_visitor::visit(const circle& c)
{
  data_ << "<circle cx=";
  in_quotes(data_, c.x()) <<  " cy=";
  in_quotes(data_, c.y()) << " r=";
  in_quotes(data_, c.r()) << std::endl;

  add_style(c.get_style());
  data_ << std::endl;
  add_transform(c.get_transform());
  data_ << std::endl;
  data_ << "/>" << std::endl;
}

void svg_visitor::visit(const group& g)
{
  data_ << "<g ";
  add_style(g.get_style());
  data_ << std::endl;
  add_transform(g.get_transform());
  data_ << std::endl;
  data_ << " >";
}

void svg_visitor::done(const screen& s)
{
  data_ << " </svg>" << std::endl;
}

void svg_visitor::done(const circle& c)
{
}

void svg_visitor::done(const group& g)
{
  data_ << " </g>" << std::endl;
}

void svg_visitor::write(std::ostream& s) const
{
  s << data_.str();
}

void svg_visitor::add_style(const style& s)
{
  const auto& fill = s.fill();
  if (!fill.none())
  {
    data_ << " fill=";
    add_color(fill);
  }
  else
  {
    data_ << " fill=\"none\" ";
  }
  const auto& stroke = s.stroke();
  if (!stroke.none())
  {
    data_ << " stroke=";
    add_color(stroke);
  }
  else
  {
    data_ << " stroke=\"none\" ";
  }
  data_ << " stroke-width=";
  in_quotes(data_, s.stroke_width());
}

void svg_visitor::add_color(const color& c)
{
  data_ << "\"rgba(";

  data_ << c.red() << ",";
  data_ << c.green() << ",";
  data_ << c.blue() << ",";
  data_ << std::fixed << std::setprecision(1);
  data_ << c.alpha_frac();
  data_ << ")\"";
}

void svg_visitor::add_transform(const transform& t)
{
  if (!t.todo())
  {
    return;
  }
  data_ << "transform=\"";
  data_ << "translate(" << t.x() << ' ' << t.y() << ") ";

  if (t.deg() != 0.0)
  {
    data_ << "rotate(" << t.deg() << ") ";
  }
  data_ << '"';
}

} // namespace


#include "graphics/shapes/group.h"
#include "graphics/visitor.h"

namespace cvg
{

void group::accept(visitor& v) const
{
  v.visit(*this);

  for (const auto& s : shapes_)
  {
    s->accept(v);
  }
  v.done(*this);
}

} // namespace


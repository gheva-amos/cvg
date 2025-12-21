#ifndef CVG_GRAPHICS_SCREEN_H__
#define CVG_GRAPHICS_SCREEN_H__
#include <cstddef>
#include <vector>
#include <memory>
#include "graphics/shape.h"
#include "graphics/style.h"
#include "graphics/color.h"
#include "graphics/visitor.h"

namespace cvg
{

class screen
{
public:
  screen(size_t h, size_t w);
  virtual ~screen() = default;
  size_t& height();
  size_t height() const;
  size_t& width();
  size_t width() const;

  void fill(color c);
  void stroke(color c);
  void stroke_width(float w);

  template <typename shape_t, typename... args_t>
  shape_t& add(args_t&&... args)
  {
    static_assert(std::is_base_of_v<shape, shape_t>, "shape_t must derive from shape");

    auto ptr = std::make_unique<shape_t>(
      std::forward<args_t>(args)...
    );

    shape_t& ref = *ptr;
    ref.stroke(style_.stroke());
    ref.fill(style_.fill());
    ref.stroke_width(style_.stroke_width());
    shapes_.push_back(std::move(ptr));
    return ref;
  }

  void accept(visitor& visitor);

protected:
  size_t height_;
  size_t width_;
  std::vector<std::unique_ptr<shape>> shapes_;
  style style_;
};

} // namespace

#endif // CVG_GRAPHICS_SCREEN_H__

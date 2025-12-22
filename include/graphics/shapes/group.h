#ifndef CVG_SHAPES_GROUP_H__
#define CVG_SHAPES_GROUP_H__
#include "graphics/shape.h"
#include <memory>
#include <vector>

namespace cvg
{

class group final : public shape
{
public:
  template <typename shape_t, typename... args_t>
  shape_t& add(args_t&&... args)
  {
    static_assert(std::is_base_of_v<shape, shape_t>, "shape_t must derive from shape");

    auto ptr = std::make_unique<shape_t>(
      std::forward<args_t>(args)...
    );

    shape_t& ref = *ptr;
    shapes_.push_back(std::move(ptr));
    return ref;
  }

  virtual void accept(visitor& v) const override;

private:
  std::vector<std::unique_ptr<shape>> shapes_;

};

} // namespace

#endif // CVG_SHAPES_GROUP_H__

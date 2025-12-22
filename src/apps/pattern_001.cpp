#include <fstream>
#include <cstdlib>

#include <graphics/screen.h>
#include <graphics/svg_visitor.h>
#include <graphics/color.h>
#include <graphics/shapes/circle.h>
#include <graphics/shapes/group.h>

void show_pattern(size_t height, size_t width, const std::string& path);

int main(int argc, char** argv)
{
  size_t height{1000}, width{1000};
  std::string path{"./pattern_001.svg"};
  if (argc < 3)
  {
    // TODO usage
    return 1;
  }
  else if (argc == 3)
  {
    path = argv[1];
    height = width = std::atoi(argv[2]);
  }
  else if (argc == 4)
  {
    path = argv[1];
    height = std::atoi(argv[2]);
    width = std::atoi(argv[3]);
  }
  else
  {
    // TODO usage
    return 1;
  }
  show_pattern(height, width, path);
  return 0;
}

void show_pattern(size_t height, size_t width, const std::string& path)
{
  cvg::screen screen{height, width};

  cvg::group& grp{screen.add<cvg::group>()};
  grp.move_to(screen.height() / 2, screen.width() / 2);

  for (size_t i{0}; i < 12; ++i)
  {
    cvg::group& g{grp.add<cvg::group>()};
    g.rotate(30 * i);
    cvg::circle& circ{g.add<cvg::circle>(0, 0, screen.height() / 20)};
    circ.move_to(50, 0);
  }
  cvg::svg_visitor visitor;

  screen.accept(visitor);

  std::ofstream out{path};

  visitor.write(out);
  out.close();
}


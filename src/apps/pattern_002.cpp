#include <fstream>
#include <cstdlib>
#include <cmath>

#include <graphics/screen.h>
#include <graphics/svg_visitor.h>
#include <graphics/color.h>
#include <graphics/shapes/circle.h>
#include <graphics/shapes/group.h>
#include <graphics/shapes/line.h>

constexpr float sin30{0.5};
constexpr float cos30{std::sqrt(3) / 2};

void add_lines(size_t a, cvg::group& grp)
{
  float x0, y0, x1, y1, x2, y2, x3, y3;
  x0 = a * cos30;
  y0 = a * sin30;
  x1 = -x0;
  y1 = -y0;
  x2 = x0;
  y2 = y1;
  x3 = x1;
  y3 = y0;

  grp.add<cvg::line>(x0, y0, x1, y1);
  grp.add<cvg::line>(x2, y2, x3, y3);
}

void tile(size_t a, cvg::group& root)
{
  for (int i{0}; i < 6; ++i)
  {
    cvg::group& grp1{root.add<cvg::group>()};
    cvg::group& grp2{grp1.add<cvg::group>()};

    add_lines(a, grp2);
    grp1.rotate(i * 60);
    grp2.move_to(cos30 * a * 2, 0);
  }
}

void show_pattern(size_t height, size_t width, size_t a, const std::string& path)
{
  cvg::screen screen{height, width};

  cvg::group& grp{screen.add<cvg::group>()};

  for (int i{-2}; i < 20; ++i)
  {
    cvg::group& grp1{grp.add<cvg::group>()};
    for (int j{-2}; j < 20; ++j)
    {
      cvg::group& grp2{grp1.add<cvg::group>()};
      cvg::group& grp3{grp2.add<cvg::group>()};
      
      tile(a, grp3);
      if (j % 2 == 0)
      {
        grp2.move_to(3 * a * cos30, 0);
      }
      grp3.move_to(6 * a * cos30 * i, 4.5 * a * j);
    }
  }

  cvg::svg_visitor visitor;

  screen.accept(visitor);

  std::ofstream out{path};

  visitor.write(out);
  out.close();
}

int main(int argc, char** argv)
{
  constexpr size_t a{10};
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

  show_pattern(height, width, a, path);
  return 0;
}


#include <gtest/gtest.h>
#include <iostream>

#include <graphics/screen.h>
#include <graphics/svg_visitor.h>
#include <graphics/color.h>
#include <graphics/shapes/circle.h>
#include <graphics/shapes/group.h>

TEST(LinkageWorks, UserGuide)
{
  cvg::screen screen{480, 640};

  cvg::circle& circ{screen.add<cvg::circle>(0, 0, 100)};

  circ.stroke_width(1);
  circ.stroke(cvg::color{0, 0, 0, 255});
  circ.fill(cvg::color{});
  circ.move_to(screen.height() / 2, screen.width() / 2);

  cvg::svg_visitor visitor;

  screen.accept(visitor);

  //visitor.write(std::cout);
}

TEST(FirstPattern, UserGuide)
{
  cvg::screen screen{1000, 1000};

  cvg::group& grp{screen.add<cvg::group>()};
  grp.move_to(500, 500);

  for (size_t i{0}; i < 12; ++i)
  {
    cvg::group& g{grp.add<cvg::group>()};
    g.rotate(30 * i);
    cvg::circle& circ{g.add<cvg::circle>(0, 0, 50)};
    circ.move_to(50, 0);
  }
  cvg::svg_visitor visitor;

  screen.accept(visitor);

  visitor.write(std::cout);
}


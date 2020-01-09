#ifndef METROIDVANIART_METROIDVANIASTAGEBACKGROUND_H
#define METROIDVANIART_METROIDVANIASTAGEBACKGROUND_H

#include <vector>

#include "../../../../dependencies/NovelRT/src/NovelRT.h"

namespace MetroidvaniaRT {
  class MetroidvaniaStageBackground {
  public:
    std::vector<NovelRT::NovelRenderObject> elements;



    MetroidvaniaStageBackground();
    ~MetroidvaniaStageBackground();
  };
}

#endif // METROIDVANIART_METROIDVANIASTAGE_H

#ifndef METROIDVANIART_METROIDVANIASTAGESERVICE_H
#define METROIDVANIART_METROIDVANIASTAGESERVICE_H

#include <vector>

#include "./structures/stage/MetroidvaniaStage.h"
#include "../../dependencies/NovelRT/src/NovelRenderingService.h"

namespace MetroidvaniaRT {
  class MetroidvaniaStageService {
  private:
    std::unique_ptr<NovelRT::NovelRenderingService> _renderer;
  public:
    std::vector<MetroidvaniaStage*> stages;

    MetroidvaniaStageService* addStage(MetroidvaniaStage* stage);
    MetroidvaniaStage* renderStage(const int& stage);

    MetroidvaniaStageService(std::unique_ptr<NovelRT::NovelRenderingService> renderer);
  };
}

#endif // METROIDVANIART_METROIDVANIASTAGESERVICE_H

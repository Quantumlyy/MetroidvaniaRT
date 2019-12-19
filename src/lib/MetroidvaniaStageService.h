#ifndef METROIDVANIART_METROIDVANIASTAGESERVICE_H
#define METROIDVANIART_METROIDVANIASTAGESERVICE_H

#include <vector>

#include "./structures/stage/MetroidvaniaStage.h"
#include "./structures/platform/MetroidvaniaPlatform.h"
#include "../../dependencies/NovelRT/src/NovelRenderingService.h"

namespace MetroidvaniaRT {
  class MetroidvaniaStageService {
  private:
    NovelRT::NovelRenderingService* _renderer;
  public:
    std::vector<MetroidvaniaStage*> stages;

    MetroidvaniaStageService* addStage(MetroidvaniaStage* stage);
    MetroidvaniaStageService* addStagePlatform(int stageEntry, MetroidvaniaPlatform* platform);
    MetroidvaniaStage* renderStage(int stageEntry);

    MetroidvaniaStageService(NovelRT::NovelRenderingService* renderer);
  };
}

#endif // METROIDVANIART_METROIDVANIASTAGESERVICE_H

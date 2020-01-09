#ifndef METROIDVANIART_METROIDVANIASTAGESERVICE_H
#define METROIDVANIART_METROIDVANIASTAGESERVICE_H

#include <map>
#include <string>

#include "./structures/MetroidvaniaIdentificationInformation.h"
#include "./structures/stage/MetroidvaniaStage.h"
#include "./structures/platform/MetroidvaniaPlatform.h"
#include "../../dependencies/NovelRT/src/NovelRT.h"

namespace MetroidvaniaRT {
  struct findingComparator {
    bool operator()(const MetroidvaniaIdentificationInformation& x, const MetroidvaniaIdentificationInformation& y) const {
      return (x.id > y.id);
    }
  };

  class MetroidvaniaStageService {
  public:
    std::map<MetroidvaniaIdentificationInformation, std::unique_ptr<MetroidvaniaStage>, findingComparator> stages;

    MetroidvaniaStageService* addStage(std::unique_ptr<MetroidvaniaStage> stage);
    MetroidvaniaStage* getStage(int _id);
    MetroidvaniaStage* getStage(const std::string& _name);
    MetroidvaniaStageService* addStagePlatform(const std::string& stageName, std::unique_ptr<MetroidvaniaPlatform> platform);
    MetroidvaniaStageService* addStagePlatform(int stageId, std::unique_ptr<MetroidvaniaPlatform> platform);
    MetroidvaniaStage* renderStage(NovelRT::NovelRenderingService* renderer, int stageId);
    MetroidvaniaStage* renderStage(NovelRT::NovelRenderingService* renderer, const std::string& stageName);

    MetroidvaniaStageService();
  };
}

#endif // METROIDVANIART_METROIDVANIASTAGESERVICE_H

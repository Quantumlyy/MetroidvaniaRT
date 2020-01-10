#ifndef METROIDVANIART_STAGESERVICE_H
#define METROIDVANIART_STAGESERVICE_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT::Graphics {
  struct findingComparator {
    bool operator()(const IdentificationInformation& x, const IdentificationInformation& y) const {
      return (x.id > y.id);
    }
  };

  class StageService {

  public:
    std::map<IdentificationInformation, std::unique_ptr<Stage>, findingComparator> stages;

    StageService* addStage(std::unique_ptr<Stage> stage);
    Stage* getStage(int _id);
    Stage* getStage(const std::string& _name);
    StageService* addStagePlatform(const std::string& stageName, std::unique_ptr<Platform> platform);
    StageService* addStagePlatform(int stageId, std::unique_ptr<Platform> platform);
    Stage* renderStage(NovelRT::NovelRenderingService* renderer, int stageId);
    Stage* renderStage(NovelRT::NovelRenderingService* renderer, const std::string& stageName);

    StageService();
  };
}

#endif // METROIDVANIART_STAGESERVICE_H

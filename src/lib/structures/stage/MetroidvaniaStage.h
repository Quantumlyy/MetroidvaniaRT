#ifndef METROIDVANIART_METROIDVANIASTAGE_H
#define METROIDVANIART_METROIDVANIASTAGE_H

#include <vector>

#include "../platform/MetroidvaniaPlatform.h"
#include "../../../../dependencies/NovelRT/src/NovelUtilities.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"

namespace MetroidvaniaRT {
  /**
   * The base class for a Stage.
   */
  class MetroidvaniaStage {
    NOVELRT_PARAMETERLESS_EVENT(FinishedRender)
  protected:
    int _id;
  public:
    std::vector<MetroidvaniaPlatform*> platforms;

    virtual int getId() const;
    virtual void setId(int value);

    MetroidvaniaStage* addPlatform(MetroidvaniaPlatform* platform);
    void renderPlatforms(NovelRT::NovelRenderingService* renderer);
    void renderStage(NovelRT::NovelRenderingService* renderer);

    MetroidvaniaStage(int id = 0);
    ~MetroidvaniaStage();
  };
}

#endif // METROIDVANIART_METROIDVANIASTAGE_H

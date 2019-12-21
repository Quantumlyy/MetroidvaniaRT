#ifndef METROIDVANIART_METROIDVANIASTAGE_H
#define METROIDVANIART_METROIDVANIASTAGE_H

#include <vector>

#include "../platform/MetroidvaniaPlatform.h"
#include "../../../../dependencies/NovelRT/src/NovelRT.h"
#include "../../../../dependencies/NovelRT/src/NovelUtilities.h"

namespace MetroidvaniaRT {
  /**
   * The base class for a Stage.
   */
  class MetroidvaniaStage {
    NOVELRT_PARAMETERLESS_EVENT(StageRendered)
  protected:
    int _id;
    int _computedHighestLayer;
    int _computedLowestLayer;
    int _computedHighestLayerOrder;
    int _computedLowestLayerOrder;
  public:
    std::vector<MetroidvaniaPlatform*> platforms;

    virtual int getId() const;
    virtual void setId(int value);

    virtual int getComputedHighestLayer() const;
    virtual int getComputedLowestLayer() const;
    virtual int getComputedHighestLayerOrder() const;
    virtual int getComputedLowestLayerOrder() const;

    MetroidvaniaStage* addPlatform(MetroidvaniaPlatform* platform);
    void renderPlatforms(NovelRT::NovelRenderingService* renderer);
    void computePlatforms();
    void renderStage(NovelRT::NovelRenderingService* renderer);

    MetroidvaniaStage(int id = 0);
    ~MetroidvaniaStage();
  };
}

#endif // METROIDVANIART_METROIDVANIASTAGE_H

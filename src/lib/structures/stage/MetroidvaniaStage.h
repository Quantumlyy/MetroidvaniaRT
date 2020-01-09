#ifndef METROIDVANIART_METROIDVANIASTAGE_H
#define METROIDVANIART_METROIDVANIASTAGE_H

#include <vector>

#include "../MetroidvaniaIdentificationInformation.h"
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
    MetroidvaniaIdentificationInformation& _II;
    int _computedHighestLayer;
    int _computedLowestLayer;
  public:
    std::vector<std::unique_ptr<MetroidvaniaPlatform>> platforms;

    virtual MetroidvaniaIdentificationInformation& getII() const;

    virtual int getComputedHighestLayer() const;
    virtual int getComputedLowestLayer() const;

    virtual void checkIIConfliction(std::unique_ptr<MetroidvaniaPlatform> insertedPlatform);

    MetroidvaniaStage* addPlatform(std::unique_ptr<MetroidvaniaPlatform> platform);
    void renderPlatforms(NovelRT::NovelRenderingService* renderer);
    void computePlatformLayers();
    void renderStage(NovelRT::NovelRenderingService* renderer);

    MetroidvaniaStage(MetroidvaniaIdentificationInformation& identificationInformation);
  };
}

#endif // METROIDVANIART_METROIDVANIASTAGE_H

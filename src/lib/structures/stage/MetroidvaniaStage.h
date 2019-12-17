#ifndef METROIDVANIART_METROIDVANIASTAGE_H
#define METROIDVANIART_METROIDVANIASTAGE_H

#include <vector>

#include "../platform/MetroidvaniaPlatform.h"
#include "../../../../dependencies/NovelRT/src/NovelRenderingService.h"

namespace MetroidvaniaRT {
  /**
   * The base class for a Stage.
   */
  class MetroidvaniaStage {
  protected:
    int _id;
  public:
    std::vector<MetroidvaniaPlatform*> platforms;

    virtual int getId() const;
    virtual void setId(int value);

    MetroidvaniaStage* addPlatform(MetroidvaniaPlatform*);
    void renderPlatforms(NovelRT::NovelRenderingService*);
    void renderStage(NovelRT::NovelRenderingService*);

    MetroidvaniaStage();
  };
}

#endif // METROIDVANIART_METROIDVANIASTAGE_H

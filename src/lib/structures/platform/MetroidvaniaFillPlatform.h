#ifndef METROIDVANIART_METROIDVANIAFILLPLATFORM_H
#define METROIDVANIART_METROIDVANIAFILLPLATFORM_H

#include "MetroidvaniaPlatform.h"
#include "../../../../dependencies/NovelRT/src/NovelCommonArgs.h"
#include "../../../../dependencies/NovelRT/src/NovelBasicFillRect.h"
#include "../../../../dependencies/NovelRT/src/GeoVector.h"
#include "../../../../dependencies/NovelRT/src/RGBAConfig.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a fill platform in a stage.
   */
  class MetroidvaniaFillPlatform : public MetroidvaniaPlatform {
  public:
    NovelRT::NovelBasicFillRect* renderObj;
    NovelRT::NovelBasicFillRect* formRender(NovelRT::NovelRenderingService* renderer);

    MetroidvaniaFillPlatform(NovelRT::GeoVector<float>&, NovelRT::RGBAConfig&, NovelRT::NovelCommonArgs&);
  };
}

#endif // METROIDVANIART_METROIDVANIAFILLPLATFORM_H

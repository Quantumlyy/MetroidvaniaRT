#ifndef METROIDVANIART_METROIDVANIAFILLPLATFORM_H
#define METROIDVANIART_METROIDVANIAFILLPLATFORM_H

#include "MetroidvaniaPlatform.h"
#include "../MetroidvaniaIdentificationInformation.h"
#include "../../../../dependencies/NovelRT/src/NovelRT.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a fill platform in a stage.
   */
  class MetroidvaniaFillPlatform : public MetroidvaniaPlatform {
  public:
    NovelRT::NovelBasicFillRect* renderObj;
    NovelRT::NovelBasicFillRect* formRender(NovelRT::NovelRenderingService* renderer) final;

    MetroidvaniaFillPlatform(MetroidvaniaIdentificationInformation& identificationInformation, NovelRT::RGBAConfig& colourFill, NovelRT::NovelCommonArgs& args);
  };
}

#endif // METROIDVANIART_METROIDVANIAFILLPLATFORM_H

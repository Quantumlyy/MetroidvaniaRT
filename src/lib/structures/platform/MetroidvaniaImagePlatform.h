#ifndef METROIDVANIART_METROIDVANIAIMAGEPLATFORM_H
#define METROIDVANIART_METROIDVANIAIMAGEPLATFORM_H

#include <string>

#include "MetroidvaniaPlatform.h"
#include "../MetroidvaniaIdentificationInformation.h"
#include "../../../../dependencies/NovelRT/src/NovelRT.h"

namespace MetroidvaniaRT {
  /**
   * The base class for creating a image platform in a stage.
   */
  class MetroidvaniaImagePlatform : public MetroidvaniaPlatform {
  protected:
    const std::string& _filePath;
  public:
    NovelRT::NovelImageRect* renderObj;
    NovelRT::NovelImageRect* formRender(NovelRT::NovelRenderingService* renderer) final;

    MetroidvaniaImagePlatform(MetroidvaniaIdentificationInformation& identificationInformation, const std::string& filePath, NovelRT::NovelCommonArgs& args, NovelRT::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_METROIDVANIAIMAGEPLATFORM_H

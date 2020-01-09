#ifndef METROIDVANIART_FILLPLATFORM_H
#define METROIDVANIART_FILLPLATFORM_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT::Graphics {
  /**
   * The base class for creating a fill platform in a stage.
   */
  class FillPlatform : public Platform {
  public:
    NovelRT::NovelBasicFillRect* renderObj;
    NovelRT::NovelBasicFillRect* formRender(NovelRT::NovelRenderingService* renderer) final;

    FillPlatform(IdentificationInformation& identificationInformation, NovelRT::RGBAConfig& colourFill, NovelRT::NovelCommonArgs& args);
  };
}

#endif // METROIDVANIART_FILLPLATFORM_H

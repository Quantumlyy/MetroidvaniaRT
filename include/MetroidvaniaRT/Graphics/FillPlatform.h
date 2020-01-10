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
    NovelRT::Graphics::BasicFillRect* renderObj;
    NovelRT::Graphics::BasicFillRect* formRender(NovelRT::Graphics::RenderingService* renderer) final;

    FillPlatform(IdentificationInformation& identificationInformation, NovelRT::Graphics::RGBAConfig& colourFill, NovelRT::Transform& args);
  };
}

#endif // METROIDVANIART_FILLPLATFORM_H

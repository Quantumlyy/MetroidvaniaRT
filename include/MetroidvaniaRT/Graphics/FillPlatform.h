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

    NovelRT::Graphics::BasicFillRect* create(NovelRT::Graphics::RenderingService* renderer) override;

    FillPlatform(IdentificationInformation& identificationInformation, NovelRT::Transform& transform, int layer, NovelRT::Graphics::RGBAConfig& colourConfig);
  };
}

#endif // METROIDVANIART_FILLPLATFORM_H

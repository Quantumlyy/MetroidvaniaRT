#ifndef METROIDVANIART_FILLPLATFORM_H
#define METROIDVANIART_FILLPLATFORM_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT::Graphics {
  /**
   * The base class for creating a fill platform in a stage.
   */
  class FillPlatform : public Platform<NovelRT::Graphics::BasicFillRect> {
  public:
    std::shared_ptr<NovelRT::Graphics::BasicFillRect> renderObj;

    std::shared_ptr<NovelRT::Graphics::BasicFillRect> create(std::weak_ptr<NovelRT::Graphics::RenderingService> renderer) override;

    FillPlatform(IdentificationInformation& identificationInformation, NovelRT::Transform& transform, int layer, NovelRT::Graphics::RGBAConfig& colourConfig);
  };
}

#endif // METROIDVANIART_FILLPLATFORM_H

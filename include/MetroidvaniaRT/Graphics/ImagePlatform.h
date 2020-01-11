#ifndef METROIDVANIART_IMAGEPLATFORM_H
#define METROIDVANIART_IMAGEPLATFORM_H

#ifndef METROIDVANIART_H
#error Please do not include this directly. Use the centralised header (MetroidvaniaRT.h) instead!
#endif

namespace MetroidvaniaRT::Graphics {
  /**
   * The base class for creating a image platform in a stage.
   */
  class ImagePlatform : public Platform {
  protected:
    const std::string& _filePath;

  public:
    NovelRT::Graphics::ImageRect* renderObj;

    NovelRT::Graphics::ImageRect* create(NovelRT::Graphics::RenderingService* renderer) override;

    ImagePlatform(IdentificationInformation& identificationInformation, int layer, const std::string& filePath, NovelRT::Transform& transform, NovelRT::Graphics::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_IMAGEPLATFORM_H

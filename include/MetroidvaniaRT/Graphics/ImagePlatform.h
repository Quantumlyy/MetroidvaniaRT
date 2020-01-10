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
    NovelRT::Graphics::ImageRect* formRender(NovelRT::Graphics::RenderingService* renderer) final;

    ImagePlatform(IdentificationInformation& identificationInformation, const std::string& filePath, NovelRT::Transform& args, NovelRT::Graphics::RGBAConfig& colourTint);
  };
}

#endif // METROIDVANIART_IMAGEPLATFORM_H

#include <MetroidvaniaRT.h>

namespace MetroidvaniaRT::Graphics {
  ImagePlatform::ImagePlatform(IdentificationInformation& identificationInformation,
    const std::string& filePath,
    NovelRT::NovelCommonArgs& args,
    NovelRT::RGBAConfig& colourTint) : Platform(identificationInformation, args, colourTint), _filePath(filePath) { }

  NovelRT::NovelImageRect* ImagePlatform::formRender(NovelRT::NovelRenderingService* renderer) {
    renderObj = renderer->getImageRect(_filePath, _args, _colourTint);
    raisePlatformRendered();
    return renderObj;
  }
}

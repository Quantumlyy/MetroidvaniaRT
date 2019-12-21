#include "MetroidvaniaImagePlatform.h"

namespace MetroidvaniaRT {
  MetroidvaniaImagePlatform::MetroidvaniaImagePlatform(const std::string& filePath,
    NovelRT::NovelCommonArgs& args,
    NovelRT::RGBAConfig& colourTint) : MetroidvaniaPlatform(args, colourTint), _filePath(filePath) { }

  NovelRT::NovelImageRect* MetroidvaniaImagePlatform::formRender(NovelRT::NovelRenderingService* renderer) {
    renderObj = renderer->getImageRect(_filePath, _args, _colourTint);
    raisePlatformRendered();
    return renderObj;
  }
}

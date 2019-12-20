#include "MetroidvaniaPlatform.h"

namespace MetroidvaniaRT {
  MetroidvaniaPlatform::MetroidvaniaPlatform(NovelRT::NovelCommonArgs& args,
    NovelRT::RGBAConfig& colourTint) :
      _args(args),
      _colourTint(colourTint),
      _id(0) { }

  int MetroidvaniaPlatform::getId() const {
    return _id;
  }
  void MetroidvaniaPlatform::setId(int value) {
    _id = value;
  }

  int MetroidvaniaPlatform::getLayer() const {
    return _args.layer;
  }
  void MetroidvaniaPlatform::setLayer(int value) {
    _args.layer = value;
  }

  int MetroidvaniaPlatform::getLayerOrder() const {
    return _args.orderInLayer;
  }
  void MetroidvaniaPlatform::setLayerOrder(int value) {
    _args.orderInLayer = value;
  }

}

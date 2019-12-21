#include "../dependencies/NovelRT/src/NovelRT.h"
#include "../include/MetroidvaniaRT.h"

int main(int argc, char* argv[]) {
  auto runner = new MetroidvaniaRT::MetroidvaniaRunner(0);

  auto fillArgs = NovelRT::NovelCommonArgs();
  fillArgs.layer = 0;
  fillArgs.orderInLayer = 0;
  fillArgs.startingPosition.setX(1920 / 2);
  fillArgs.startingPosition.setY(1080 / 2);
  fillArgs.startingScale = NovelRT::GeoVector<float>(456, 618);

  runner->getStageService()->addStage(new MetroidvaniaRT::MetroidvaniaStage());
  runner->getStageService()->addStagePlatform(0, new MetroidvaniaRT::MetroidvaniaFillPlatform(NovelRT::RGBAConfig(255, 0, 255, 255), fillArgs));
  runner->getStageService()->renderStage(0);

  runner->runNovel();
  return EXIT_SUCCESS;
}

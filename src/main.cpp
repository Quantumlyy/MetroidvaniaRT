#include "./lib/MetroidvaniaRunner.h"
#include "./lib/structures/stage/MetroidvaniaStage.h"
#include "./lib/structures/platform/MetroidvaniaFillPlatform.h"
#include "../dependencies/NovelRT/src/NovelCommonArgs.h"
#include "../dependencies/NovelRT/src/RGBAConfig.h"
#include "../dependencies/NovelRT/src/GeoVector.h"
#include "../dependencies/NovelRT/src/NovelLayeringService.h"

int main(int argc, char* argv[]) {
  auto runner = new MetroidvaniaRT::MetroidvaniaRunner(0, 10);

  auto fillArgs = NovelRT::NovelCommonArgs();
  fillArgs.layer = 0;
  fillArgs.orderInLayer = 0;
  fillArgs.startingPosition.setX(1920 / 2);
  fillArgs.startingPosition.setY(1080 / 2);
  fillArgs.startingScale = NovelRT::GeoVector<float>(456, 618);
  auto stage = new MetroidvaniaRT::MetroidvaniaStage();
  auto platform = new MetroidvaniaRT::MetroidvaniaFillPlatform(NovelRT::RGBAConfig(255, 0, 255, 255), fillArgs);

  stage->addPlatform(platform);
  runner->addStage(stage);
  runner->stages[0]->renderStage(runner->getRenderer());

  runner->runNovel();
  return EXIT_SUCCESS;
}

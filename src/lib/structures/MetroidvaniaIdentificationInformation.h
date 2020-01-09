#ifndef METROIDVANIART_METROIDVANIAIDENTIFICATIONINFORMATION_H
#define METROIDVANIART_METROIDVANIAIDENTIFICATIONINFORMATION_H

#include <string>

namespace MetroidvaniaRT {
  struct MetroidvaniaIdentificationInformation {
  public:
    std::string name = "";
    int32_t id;

    MetroidvaniaIdentificationInformation() {};
  };
}

#endif // METROIDVANIART_METROIDVANIAIDENTIFICATIONINFORMATION_H

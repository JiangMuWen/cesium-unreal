#include "CesiumWebMapTileServiceRasterOverlay.h"
#include "Cesium3DTilesSelection/WebMapTileServiceRasterOverlay.h"
#include "CesiumRuntime.h"

std::unique_ptr<Cesium3DTilesSelection::RasterOverlay>
UCesiumWebMapTileServiceRasterOverlay::CreateOverlay() {
  Cesium3DTilesSelection::WebMapTileServiceRasterOverlayOptions Options;
  if (MaximumLevel > MinimumLevel && bSpecifyZoomLevels) {
    Options.minimumLevel = MinimumLevel;
    Options.maximumLevel = MaximumLevel;
  }
  if (bUseUrlTemplate) {
    Options.urlTemplate = TCHAR_TO_UTF8(*this->UrlTemplate);
  }
  if (bNeedKey) {
    std::string key = TCHAR_TO_UTF8(*this->KeyName);
    std::string value = TCHAR_TO_UTF8(*this->KeyValue);
    if (!key.empty() && !value.empty()) {
      Options.token = std::pair<std::string, std::string>(key, value);
    } 
  }

  std::vector<std::string> subdomain;
  TArray<FString> subdomainArray;
  SubDomain.ParseIntoArray(subdomainArray, TEXT(","), false);
  for (auto& Str : subdomainArray) {
    subdomain.push_back(TCHAR_TO_UTF8(*Str));
  }
  if (!subdomain.empty())
    Options.subdomains = subdomain;

  std::vector<std::string> tilelabel;
  TArray<FString> tilelabelArray;
  TileMatrixLabels.ParseIntoArray(tilelabelArray, TEXT(","), false);
  for (auto& Str : tilelabelArray) {
    tilelabel.push_back(TCHAR_TO_UTF8(*Str));
  }
  if (!tilelabel.empty())
    Options.tileMatrixLabels = tilelabel;


  return std::make_unique<Cesium3DTilesSelection::WebMapTileServiceRasterOverlay>(
      TCHAR_TO_UTF8(*this->MaterialLayerKey),
      TCHAR_TO_UTF8(*this->Url),
      TCHAR_TO_UTF8(*this->Layer),
      TCHAR_TO_UTF8(*this->Style),
      TCHAR_TO_UTF8(*this->TileMatrixSetID),
      Options);
}

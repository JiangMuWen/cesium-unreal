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
  return std::make_unique<Cesium3DTilesSelection::WebMapTileServiceRasterOverlay>(
      TCHAR_TO_UTF8(*this->MaterialLayerKey),
      TCHAR_TO_UTF8(*this->Url),
      TCHAR_TO_UTF8(*this->Layer),
      TCHAR_TO_UTF8(*this->Style),
      TCHAR_TO_UTF8(*this->TileMatrixSetID),
      // std::vector<CesiumAsync::IAssetAccessor::THeader>(),
      Options);
}

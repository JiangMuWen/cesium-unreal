// Copyright 2020-2021 CesiumGS, Inc. and Contributors

#pragma once

#include "CesiumRasterOverlay.h"
#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "CesiumWebMapTileServiceRasterOverlay.generated.h"


/**
 * A raster overlay that directly accesses a Web Map Tile Service (WMTS) server.
 */
UCLASS(ClassGroup = (Cesium), meta = (BlueprintSpawnableComponent))
class CESIUMRUNTIME_API UCesiumWebMapTileServiceRasterOverlay
    : public UCesiumRasterOverlay {
  GENERATED_BODY()

public:
  /**
   * The base URL of the Web Map Tile Service (WMTS).
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  FString Url;

  /**
   * True to use a URL template.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  bool bUseUrlTemplate = false;

  /**
   * The URL template of the Web Map Tile Service (WMTS).
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (EditCondition = "bUseUrlTemplate"))
  FString UrlTemplate = "";

  /**
   * True to use a key-value token for the WMTS request.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  bool bNeedKey = false;

  /**
   * The keyname of the token.
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (EditCondition = "bNeedKey"))
  FString KeyName = "";

  /**
   * The value of the token.
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (EditCondition = "bNeedKey"))
  FString KeyValue = "";

  /**
   * The layer name for WMTS requests.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  FString Layer;

  /**
   * The identifier of the TileMatrixSet to use for WMTS requests.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  FString TileMatrixSetID;

  /**
   * The style name for WMTS requests.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  FString Style = "default";

  /**
   * True to directly specify minum and maximum zoom levels available from the
   * server, or false to automatically determine the minimum and maximum zoom
   * levels from the server's tilemapresource.xml file.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  bool bSpecifyZoomLevels = false;

  /**
   * Minimum zoom level.
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (EditCondition = "bSpecifyZoomLevels"))
  int32 MinimumLevel = 0;

  /**
   * Maximum zoom level.
   */
  UPROPERTY(
      EditAnywhere,
      Category = "Cesium",
      meta = (EditCondition = "bSpecifyZoomLevels"))
  int32 MaximumLevel = 10;

  /**
   * The subdomains to use for the {s} or {subdomain} placeholder in the URL
   * template.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  FString SubDomain;

  /**
   * A list of identifiers in the TileMatrix to use for WMTS requests, one per
   * TileMatrix level.
   */
  UPROPERTY(EditAnywhere, Category = "Cesium")
  FString TileMatrixLabels;

protected:
  virtual std::unique_ptr<Cesium3DTilesSelection::RasterOverlay>
  CreateOverlay() override;
};

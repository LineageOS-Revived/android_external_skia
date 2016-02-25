/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef Request_DEFINED
#define Request_DEFINED

#include "GrContextFactory.h"

#include "SkDebugCanvas.h"
#include "SkPicture.h"
#include "SkStream.h"
#include "SkSurface.h"

#include "UrlDataManager.h"

struct MHD_Connection;
struct MHD_PostProcessor;

struct UploadContext {
    SkDynamicMemoryWStream fStream;
    MHD_PostProcessor* fPostProcessor;
    MHD_Connection* connection;
};

struct Request {
    Request(SkString rootUrl) 
    : fUploadContext(nullptr)
    , fUrlDataManager(rootUrl)
    , fGPUEnabled(false) {}

    UploadContext* fUploadContext;
    SkAutoTUnref<SkPicture> fPicture;
    SkAutoTUnref<SkDebugCanvas> fDebugCanvas;
    SkAutoTDelete<GrContextFactory> fContextFactory;
    SkAutoTUnref<SkSurface> fSurface;
    UrlDataManager fUrlDataManager;
    bool fGPUEnabled;
};

#endif


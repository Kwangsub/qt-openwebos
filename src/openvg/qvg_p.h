/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtOpenVG module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the either Technology Preview License Agreement or the
** Beta Release License Agreement.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain
** additional rights. These rights are described in the Nokia Qt LGPL
** Exception version 1.0, included in the file LGPL_EXCEPTION.txt in this
** package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you are unsure which license is appropriate for your use, please
** contact the sales department at http://www.qtsoftware.com/contact.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QVG_P_H
#define QVG_P_H

#include "qvg.h"

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of other Qt classes.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtGui/qimage.h>

#if !defined(QT_NO_EGL)
#include <QtGui/private/qegl_p.h>
#endif

QT_BEGIN_NAMESPACE

class QVGPaintEngine;

#if !defined(QT_NO_EGL)

class QEglContext;

// Create an EGL context, but don't bind it to a surface.  If single-context
// mode is enabled, this will return the previously-created context.
Q_OPENVG_EXPORT QEglContext *qt_vg_create_context(QPaintDevice *device);

// Destroy an EGL context that was created by qt_vg_create_context().
// If single-context mode is enabled, this will decrease the reference count.
Q_OPENVG_EXPORT void qt_vg_destroy_context(QEglContext *context);

// Return the shared pbuffer surface that can be made current to
// destroy VGImage objects when there is no other surface available.
Q_OPENVG_EXPORT EGLSurface qt_vg_shared_surface(void);

// Make a context current with a specific surface.
Q_OPENVG_EXPORT void qt_vg_make_current(QEglContext *context, EGLSurface surface);

// Make a context uncurrent.
Q_OPENVG_EXPORT void qt_vg_done_current(QEglContext *context, bool force = false);

// Destroy a surface that was previously associated with a context.
Q_OPENVG_EXPORT void qt_vg_destroy_surface(QEglContext *context, EGLSurface surface);

// Convert the configuration format in a context to a VG or QImage format.
Q_OPENVG_EXPORT VGImageFormat qt_vg_config_to_vg_format(QEglContext *context);
Q_OPENVG_EXPORT QImage::Format qt_vg_config_to_image_format(QEglContext *context);

#endif

// Create a paint engine.  Returns the common engine in single-context mode.
Q_OPENVG_EXPORT QVGPaintEngine *qt_vg_create_paint_engine(void);

// Destroy a paint engine.  Does nothing in single-context mode.
Q_OPENVG_EXPORT void qt_vg_destroy_paint_engine(QVGPaintEngine *engine);

// Convert between QImage and VGImage format values.
Q_OPENVG_EXPORT VGImageFormat qt_vg_image_to_vg_format(QImage::Format format);

QT_END_NAMESPACE

#endif
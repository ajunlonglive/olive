/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2019 Olive Team

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

***/

#ifndef WAVEFORMSCOPE_H
#define WAVEFORMSCOPE_H

#include <QOpenGLWidget>

#include "codec/frame.h"
#include "render/backend/opengl/openglcolorprocessor.h"
#include "render/backend/opengl/openglshader.h"
#include "render/backend/opengl/opengltexture.h"

OLIVE_NAMESPACE_ENTER

class WaveformScope : public QOpenGLWidget
{
  Q_OBJECT
public:
  WaveformScope(QWidget* parent = nullptr);

public slots:
  void SetTexture(OpenGLTexture* texture);

protected:
  virtual void initializeGL() override;

  virtual void paintGL() override;

private:
  OpenGLShaderPtr pipeline_;

  OpenGLTexture* texture_;

private slots:
  void CleanUp();

};

OLIVE_NAMESPACE_EXIT

#endif // WAVEFORMSCOPE_H

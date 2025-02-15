/***

  Olive - Non-Linear Video Editor
  Copyright (C) 2022 Olive Team

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

#ifndef PARAM_H
#define PARAM_H

#include "panel/curve/curve.h"
#include "panel/timebased/timebased.h"
#include "widget/nodeparamview/nodeparamview.h"

namespace olive {

class ParamPanel : public TimeBasedPanel
{
  Q_OBJECT
public:
  ParamPanel(QWidget* parent);

  NodeParamView *GetParamView() const
  {
    return static_cast<NodeParamView *>(GetTimeBasedWidget());
  }

  const QVector<Node*> &GetContexts() const
  {
    return GetParamView()->GetContexts();
  }

  void CloseContextsBelongingToProject(Project *p)
  {
    GetParamView()->CloseContextsBelongingToProject(p);
  }

public slots:
  void SetSelectedNodes(const QVector<Node::ContextPair> &nodes)
  {
    GetParamView()->SetSelectedNodes(nodes, false);
  }

  virtual void DeleteSelected() override;

  virtual void SelectAll() override;

  virtual void DeselectAll() override;

  void SetContexts(const QVector<Node*> &contexts);

signals:
  void FocusedNodeChanged(Node* n);

  void SelectedNodesChanged(const QVector<Node::ContextPair> &nodes);

  void RequestViewerToStartEditingText();

protected:
  virtual void Retranslate() override;

};

}

#endif // PARAM_H

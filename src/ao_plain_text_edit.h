#pragma once

#include "widgets/input_history.h"

#include <QKeyEvent>
#include <QMimeData>
#include <QPlainTextEdit>
#include <QWidget>

namespace spritechat
{
class AOPlainTextEdit : public QPlainTextEdit
{
  Q_OBJECT

public:
  explicit AOPlainTextEdit(QWidget *parent = nullptr);

  int capacity() const;
  void setCapacity(int capacity);

  void record();

Q_SIGNALS:
  void returnPressed();

protected:
  void keyPressEvent(QKeyEvent *event) override;
  void insertFromMimeData(const QMimeData *source) override;

private:
  theory::InputHistory _history;
};
} // namespace spritechat

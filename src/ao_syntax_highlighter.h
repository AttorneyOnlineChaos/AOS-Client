#pragma once

#include "game/chat_markup.h"

#include <QList>
#include <QString>
#include <QSyntaxHighlighter>
#include <QTextDocument>

namespace spritechat
{
class AOSyntaxHighlighter : public QSyntaxHighlighter
{
  Q_OBJECT

public:
  explicit AOSyntaxHighlighter(QTextDocument *document);

  void setMarkup(const QList<theory::ChatMarkup> &markup);
  void setDefaultColor(int color);

protected:
  void highlightBlock(const QString &text) override;

private:
  QList<theory::ChatMarkup> _markup;
  int _defaultColor = 0;
};
} // namespace spritechat

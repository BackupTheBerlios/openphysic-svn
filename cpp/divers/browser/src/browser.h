/*
Browser
Copyright (C) 2008  Sebastien CELLES
 
This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.
 
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
 
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef BROWSER_H
#define BROWSER_H
//
#include "ui_browser.h"
//

#include <QKeyEvent>


class Browser : public QDialog, public Ui::Browser
  {
    Q_OBJECT
    //Q_PROPERTY(QUrl url READ url WRITE setUrl)

  public:
    Browser( QWidget * parent = 0, Qt::WFlags f = 0 );
    ~Browser();

    //void setUrl(const QUrl &url);
    //QUrl url() const;

    void keyPressEvent(QKeyEvent *event);

  public slots:
    void save(void);
    void load(void);

  private slots:
    void update(void);
    void update_view(void);

  private:
    QTimer * timer;
    int default_interval;

    int page;
    //WebView[3] wv;
    //int current_webview;

    QVector <QUrl> url_list;

    void next();
    void previous();

    void reset_timer();
  };

#define CFG_FILE QLatin1String("browser.xml")
#define CFG_DIR QDir::homePath()

#endif

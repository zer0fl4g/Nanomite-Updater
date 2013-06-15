#ifndef UUPDATEWIDGET1_H
#define UUPDATEWIDGET1_H

#include <QMainWindow>
#include <QUrl>

class QStackedWidget;
class QProgressBar;

class UCheckUpdatesWidget;
class UUpdatesModel;
class UUpdatesTableView;
class UFileDownloader;

namespace Ui {
class UUpdateWidget1;
}

class UUpdateWidget1 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit UUpdateWidget1(QWidget *parent = 0);
    ~UUpdateWidget1();
    
signals:
    void signal_downloadUpdatesFinished();

public slots:
    void slot_installUpdates();
    void slot_checkUpdates();
    void slot_checkUpdatesFailed(const QString &error);
    void slot_closeWidget();
    void slot_showUpdatesTable(UUpdatesModel *model);

protected slots:
    void slot_downloadFileFinished();
    void slot_error(const QString &error);

private:
    enum EToolBarActions {
        eINSTALL_UPDATES_ACTION = 0,
        eQUIT_ACTION,
        eSEPERATOR_ACTION,
        eCHECK_UPDATES_ACTION,
        eMAX_ACTION
    };

    Ui::UUpdateWidget1 *ui;

    QList<QAction *>    m_toolBarActions;

    QStackedWidget      *m_stackedWidget;
    UCheckUpdatesWidget *m_checkUpdatesWidget;
    UUpdatesTableView   *m_updatesTableView;
    QList<QProgressBar *>   m_progressBarList;

    UFileDownloader     *m_downloader;

    unsigned int        m_currentDownloadFile;
};

#endif // UUPDATEWIDGET1_H

#ifndef WIDGET_H
#define WIDGET_H
#include <QDialog>
#include <QWidget>
#include <QProcess>
#include <QListWidgetItem>

#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QListWidget>
#include <QPushButton>
#include <QSpacerItem>
#include <QTextEdit>
#include <QToolButton>
#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void beginReadInfo();
    void ReadStandardOutput();
    void ReadStandardError();
    void startDownload(QString id);
    void statuFinished(int f, QProcess::ExitStatus statu);

    void ReadStandardOutputDown();
    void ReadStandardErrorDown();
    void statuFinishedDown(int f, QProcess::ExitStatus statu);

    void on_toolButtonRefrech_clicked();

    void on_pushButtonErr_clicked(bool checked);

    void on_listWidgetResult_itemChanged(QListWidgetItem *item);

    void on_lineEditPath_returnPressed();

    void on_toolButtonDownload_clicked();

    void on_toolButtonStop_clicked();

    void on_toolButtonFolder_clicked();

   void setupMe();

private:



    QLineEdit *lineEditPath;
    QToolButton *toolButtonRefrech;

    QLineEdit *lineEditFolder;
    QToolButton *toolButtonFolder;
    QLabel *labelInfo;

    QPushButton *pushButtonErr;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEditReadErr;
    QListWidget *listWidgetResult;

    QToolButton *toolButtonDownload;
    QToolButton *toolButtonStop;

    QTextEdit *textEditDownload;

    QProcess *m_process;
QProcess *m_processDownLoad;
QString m_path;
};

#endif // WIDGET_H
